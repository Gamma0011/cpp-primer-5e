#ifndef STRBLOB_CLASS
#define STRBLOB_CLASS

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <memory>

class StrBlob {
public:
    StrBlob(const StrBlob &sb) : data(std::make_shared<std::vector<std::string>>(*sb.data)) { }; 
    StrBlob& operator=(const StrBlob &sb) {
        data = std::make_shared<std::vector<std::string>>(*sb.data);
        return *this; 
    }


    StrBlob() : data(new std::vector<std::string>) { };
    StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) { };

    std::size_t size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &t) { data->push_back(t); }                // lvalue version
    void push_back(std::string &&t) { data->push_back(std::move(t)); }          // rvalue version
    void pop_back();

    std::string& front();
    std::string& back();

    int usage() { return data.use_count(); }
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(std::size_t i, const std::string &msg) const;
};



#endif