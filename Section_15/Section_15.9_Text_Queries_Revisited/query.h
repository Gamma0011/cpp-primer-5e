#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include "text_query.h"

/*
    *Abstract Base   Derived 
    Query_Base  -> WordQuery 
                -> NotQuery
                * Abstract Base     Derived
                -> BinaryQuery  -> OrQuery
                                -> AndQuery

    NOTES:
        QUERY_BASE: eval and rep are pure virtual functions, making this an abstract base class. We don't intend
         users or derived classes use Query_base directly -- therefore no public members. Friendship is given to
         Query because members of Query will call virtuals. Protected member line_no, will be used in eval.
         Additionally, ~Query_base() is in protected because it's implicitly used by destructors in derived classes.

        QUERY: Provides the interface to (and hides) the Query)base inheritance hierarchy. Each Query object will
         hold a shared_ptr to a corresponding Query_base object. Because Query is only an interface, it must
         define its own versions of eval and rep. Constructor takes a string and builds WordQuery. & | ~ operators
         will build AndQuery, OrQuery, and NotQuery, returning a Query object bound to its newly generated object.
         We will need Query to have a constructor that takes a shared_ptr to a Query_base, storing its pointer.
         This constructor will be private and operators (operator&, etc) will need to be friends.
        
        WORDQUERY: Purpose is to hold the search word. Looks for a given string. Only operation that performs
         a query on the provided TextQuery object.

        EVAL FUNCTIONS: calls on the operands and applies unique logic: OrQuery eval operation returns union of lhs and rhs. 
            AndQuery returns intersection. NotQuery returns line numbers that are not in operand's set
*/

// abstract class acts as a base class for concrete query types; all members are private
class Query_base {
    friend class Query;
protected:
    using line_no = TextQuery::line_no;     // used in the eval functions
    virtual ~Query_base() = default;
private:
    // eval returns the QueryResult that matches this Query
    virtual QueryResult eval(const TextQuery&) const = 0;   // pure virtual function
    // rep is a string representation of query
    virtual std::string rep() const = 0;                    // pure virtual function
};

class Query {
    friend Query operator&(const Query&, const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator~(const Query&);
public:
    Query(const std::string&);              // build a new WordQuery
    // Interface functions: call corresponding Query_base operation
    // Query_base pointer used to call respective virtual base operation - determined at run time by object type
    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    std::string rep() const { return q->rep(); }
private:
    Query(std::shared_ptr<Query_base> query) : q(query) { };
    std::shared_ptr<Query_base> q;
};

class WordQuery : public Query_base {
private:
    friend class Query;         // Query uses WordQuery constructor
    WordQuery(const std::string &s) : query_word(s) { }

    // concrete class: WordQuery defines all inherited pure virtuals
    QueryResult eval(const TextQuery &t) const { return t.query(query_word); }   // does search for word
    std::string rep() const { return query_word; }                              // returns word being represented
    std::string query_word;
};

class NotQuery : public Query_base {
private:
    friend Query operator~(const Query&);
    NotQuery(const Query &q): query(q) {
        std::cout << "NotQuery Constructor" <<std::endl;
    };

    // concrete class: definition of pure virtuals
    std::string rep() const { return "~(" + query.rep() + ")"; }
    QueryResult eval(const TextQuery&) const;
    Query query;
};

// Abstract Class: we cannot created objects of BinaryQuery type
class BinaryQuery : public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s) :
        lhs(l), rhs(r), opSym(s) { }

    // abstract class: Binary doesn't define eval. Left to AndQuery and OrQuery
    std::string rep() const override { return "(" + lhs.rep() + " "
                                         + opSym + " "
                                         + rhs.rep() + ")"; }
    Query lhs, rhs;         // right- and left-hand operators
    std::string opSym;      // name of operator
};

class AndQuery : public BinaryQuery {
private:
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") { 
        std::cout << "AndQuery Constructor" <<std::endl;
    };
    
    // Concrete Class: inherits rep, defines virtual eval
    QueryResult eval(const TextQuery&) const override;
};

class OrQuery : public BinaryQuery {
private:
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|") { 
        std::cout << "OrQuery Constructor" <<std::endl;
    };

    // Concrete Class: inherits rep, defines virtual eval
    QueryResult eval(const TextQuery&) const override;
};

/********* COMPARISON OPERATORS *********/

inline
Query operator~(const Query &operand) {
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

inline
Query operator&(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

inline
Query operator|(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

/********* QUERY CONSTRUCTOR *********/

// allocates WordQuery and initializes its pointer member to point to new object
inline
Query::Query(const std::string &s) : q(new WordQuery(s)) {
    std::cout << "Query Constructor" <<std::endl;
}

/********* OVERLOADED OPERATORS *********/
std::ostream &operator<<(std::ostream &os, const Query &query) {
    // Query::rep makes virtual vall through Query_base pointer to rep;
    return os << query.rep();
}

/********* ORQUERY EVAL *********/
QueryResult
OrQuery::eval(const TextQuery &text) const {
    // virtual calls through Query members, lhs and rhs
    // the calls to eval return the Query Result for each operand
    auto right = rhs.eval(text), left = lhs.eval(text);
    // copy the line numbers from left-hand operand into result set
    auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
    // insert lines from right-hand operand
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}

/********* ANDQUERY EVAL *********/
QueryResult
AndQuery::eval(const TextQuery &text) const {
    // virtual calls through the Query operands to get result sets for operands
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>();
    // writes the intersection of the two ranges to a destination iterator
    // destination iterator in this call adds elements to ret
    std::set_intersection(left.begin(), left.end(),
                          right.begin(), right.end(),
                          std::inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

/********* NOTQUERY EVAL *********/
QueryResult
NotQuery::eval(const TextQuery &text) const {
    auto result = query.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>();
    auto beg = result.begin(), end = result.end();

    auto sz = result.get_file()->size();
    for (std::size_t n = 0 ; n != sz ; ++n) {
        if (beg == end || *beg != n) {
            ret_lines->insert(n);           // if not in result, add this line
        } else if (beg != end) {
            ++beg;                          // otherwise get the next line number in result if there is one
        }
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}

#endif



