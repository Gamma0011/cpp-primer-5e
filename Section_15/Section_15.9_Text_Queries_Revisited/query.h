#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <memory>

class QueryResult;

class StrBlob {
    friend class TextQuery;
    friend class QueryResult; 
public:
    StrBlob() : data(new std::vector<std::string>) { };
    StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) { };

    std::size_t size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();

    std::string& front();
    std::string& back();
    std::shared_ptr<std::vector<std::string>> data;
private:
    void check(std::size_t i, const std::string &msg) const;
};

class TextQuery {
    friend class QueryResult;
public:
    TextQuery(std::ifstream &ifs) {
        for (std::string line, word ; std::getline(ifs, line) ; tqsb.data->push_back(line)) {
            std::vector<std::string>::size_type count = tqsb.data->size();
            for (std::istringstream read(line); read >> word ; ) {
                auto &w = smap[word];
                if (!w) {
                    w.reset(new std::set<std::vector<std::string>::size_type>);
                }
                w->insert(count);
            }
        }
    }
    void printResults();
    QueryResult query(const std::string &) const;
private:
    StrBlob tqsb;
    std::map<std::string, std::shared_ptr<std::set<std::vector<std::string>::size_type>>> smap;
};

class QueryResult {
    friend std::ostream &print(std::ostream &, const QueryResult &);
public:
    QueryResult(const std::string &s,
                const StrBlob &tsb,
                std::shared_ptr<std::set<std::vector<std::string>::size_type>> tqrs) :
                word(s), qrsb(tsb), qrs(tqrs) { };

    // begin and end that return iterators into the set of line numbers returned by a given query
    std::set<std::vector<std::string>::size_type>::iterator begin() { return qrs->begin(); }
    std::set<std::vector<std::string>::size_type>::iterator end() { return qrs->end(); }

    // A member named get_file that returns a shared_ptr to the file in the QueryResult object
    std::shared_ptr<StrBlob> get_file() { return std::make_shared<StrBlob>(qrsb); }

private:
    std::string word;
    StrBlob qrsb;
    std::shared_ptr<std::set<std::vector<std::string>::size_type>> qrs;
};

QueryResult TextQuery::query(const std::string &s) const {
    std::shared_ptr<std::set<std::vector<std::string>::size_type>> defSet(new std::set<std::vector<std::string>::size_type>);

    auto lookup = smap.find(s);
    if (lookup == smap.end()) {
        return QueryResult(s, tqsb, defSet);
    } else {
        return QueryResult(s, tqsb, lookup->second);
    }
}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
    os << qr.word << " occurs " << qr.qrs->size() << (qr.qrs->size() > 1 ? " times." : " time.");
    for (auto &l : *qr.qrs) {
        os << "\n(line " << l + 1 << ") : " << *(qr.qrsb.data->begin() + l) << std::endl;
    }
    return os;
}

void TextQuery::printResults() {
    for (auto beg = tqsb.data->begin(); beg != tqsb.data->end(); ++beg) {
        std::cout <<  *beg <<std::endl;
    }
    for (auto &f : smap) {
        std::cout << f.first << " : ";
        for (auto &s : *f.second) {
            std::cout << s <<std::endl;
        }
    }
}

void runQueries(std::ifstream &ifs) {
    TextQuery tq(ifs);
    while (true) {
        std::string s;
        std::cout << "Enter a word to search for, or type q to quit: ";
        if (!(std::cin >> s) || (s == "q")) {
            break;
        } else {
            print(std::cout, tq.query(s)) <<std::endl;
        }
    }
}

#endif