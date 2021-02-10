#ifndef STRBLOB_CLASS
#define STRBLOB_CLASS

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <memory>

class StrBlob {
public:
    friend class StrBlobPtr;
    friend bool operator==(const StrBlob&, const StrBlob&);
    friend bool operator!=(const StrBlob&, const StrBlob&);
    friend bool operator<(const StrBlob&, const StrBlob&);
    friend bool operator>(const StrBlob&, const StrBlob&);

    StrBlob(const StrBlob &sb) : data(std::make_shared<std::vector<std::string>>(*sb.data)) { }; 
    StrBlob& operator=(const StrBlob &sb) {
        data = std::make_shared<std::vector<std::string>>(*sb.data);
        return *this; 
    }

    std::string& operator[](std::size_t);
    const std::string& operator[](std::size_t) const;

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

// subscript operators
std::string& StrBlob::operator[](std::size_t n) {
    return data->at(n);
}

const std::string& StrBlob::operator[](std::size_t n) const {
    return data->at(n);
}

#endif