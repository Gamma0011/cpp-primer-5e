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
    e12.32  - Rewrite TextQuery and QueryResult classes to use a StrBlob instead of a vector<string> to hold the input file.
*/

class QueryResult;

class TextQuery {
public:
    TextQuery(std::ifstream &ifs) {
        StrBlob sb;
        for (std::string line, word ; ifs >> line ; sb.data->push_back(line)) {
            std::vector<std::string>::size_type count;
            for (std::istringstream read(line); read >> word ; ) {
                auto &w = smap[word];
                if (!w) {
                    w.reset(new std::shared_ptr<std::set<std::vector<std::string>::size_type>>);
                }
                w->insert(count);
            }
        }
    }
private:
    StrBlob sb;
    std::map<std::string, std::shared_ptr<std::set<std::vector<std::string>::size_type>>> smap;
};

class QueryResults {};

class StrBlob {
    friend class TextQuery;
    friend class QueryResult;
public:
    StrBlob();
    StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) { };

    std::size_t size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();

    std::string& front();
    std::string& back();
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(std::size_t i, const std::string &msg) const;
};

int main()
{


    return 0;
}