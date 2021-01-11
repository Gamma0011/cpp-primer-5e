#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <new>
#include <map>
#include <set>

/*
    e1230   - Defines your own version of the TextQuery and QueryResult class and execute the run queries function from pg. 486
*/

// function prototyping
std::string make_plural(std::size_t, const std::string &, const std::string &);

class QueryResult;

class TextQuery {
public:
    TextQuery(std::ifstream &ifs) : svec(new std::vector<std::string>) {
        for (std::string line ; std::getline(ifs, line) ; svec->push_back(line)) {
            std::string word;
            std::vector<std::string>::size_type n = svec->size() - 1;
            for(std::istringstream read(line) ; read >> word ; ) { 
                auto &lines = smap[word];
                if (!lines) {
                    lines.reset(new std::set<std::vector<std::string>::size_type>);
                } 
                lines->insert(n);
            }
        }
    }
    QueryResult query(const std::string &) const;
private:
    std::shared_ptr<std::vector<std::string>> svec;
    std::map<std::string, std::shared_ptr<std::set<std::vector<std::string>::size_type>>> smap;
};

class QueryResult {
    friend std::ostream &print(std::ostream &, const QueryResult &);
public:
    QueryResult(const std::string &w,
                std::shared_ptr<std::vector<std::string>> v,
                std::shared_ptr<std::set<std::vector<std::string>::size_type>> s) :
                word(w), qrvec(v), qrs(s) { };
private:
    std::string word;
    std::shared_ptr<std::vector<std::string>> qrvec;
    std::shared_ptr<std::set<std::vector<std::string>::size_type>> qrs;
};

QueryResult TextQuery::query(const std::string &s) const {
    std::shared_ptr<std::set<std::vector<std::string>::size_type>> defaultSet(new std::set<std::vector<std::string>::size_type>);
    auto lookup = smap.find(s);
    if (lookup == smap.end()) { 
        return QueryResult(s, svec, defaultSet);
    } else {
        return QueryResult(s, svec, lookup->second);
    }
}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
    os << qr.word << " occurs " << qr.qrs->size() << make_plural(qr.qrs->size(), " time", "s");
    for (auto &line : *qr.qrs) {
        os << "line " << line + 1 << " : "
           << *(qr.qrvec->begin() + line) << std::endl;
    }

    return os;
};

std::string make_plural(std::size_t sz, const std::string &w, const std::string &p) {
    return (sz > 1 ? (w + p) : w);
}

void runQueries(std::ifstream &inFile) {
    TextQuery tq(inFile);
    while(true) {
        std::cout << "Enter a word to look for, or q to quit: ";
        std::string s;
        if(!(std::cin >> s) || s == "q") {
            break;
        } else {
            print(std::cout, tq.query(s)) <<std::endl;
        }
    }
}

int main(/*int argi, char **argc*/)
{
    //std::ifstream open(argc[1]);
    std::ifstream open("test.txt");

    if (open) {
        runQueries(open);
    } else {
        std::cerr << "ERROR: No file." <<std::endl;
        return -1;
    }

    return 0;
}