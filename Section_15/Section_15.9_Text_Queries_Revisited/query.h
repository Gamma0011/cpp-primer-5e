#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <string>

/*
    NOTES:
        QUERY_BASE: eval and rep are pure virtual functions, making this an abstract base class. We don't intend
         users or derived classes use Query_base directly -- therefore no public members. Friendship is given to
         Query because members of Query will call virtuals. Protected member line_no, will be used in eval.
         Additionally, ~Query_base() is in protected because it's implicitly used by destructors in derived classes.

        

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
    // rep is a string representation off query
    virtual std::string rep() const = 0;                    // pure virtual function
};

#endif