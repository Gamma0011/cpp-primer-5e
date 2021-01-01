#ifndef strblob_h
#define strblob_h

#include <iostream>
#include <vector>
#include <initializer_list>
#include <string>
#include <memory>

class StrBlobPtr;

class StrBlob {
public:
    friend class StrBlobPtr;
    typedef std::vector<std::string>::size_type size_type;
    StrBlob() : data(std::make_shared<std::vector<std::string>>()) { };      // default constructor
    StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) { };
    size_type size() { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &s) { 
        check(0, "Called push_back on empty vector.");
        data->push_back(s);
    }
    void pop_back() {
        check(0, "Called pop_back on empty vector.");
        data->pop_back();
    }
    std::string& front() {
        check(0, "Called front on empty vector");
        return data->front();
    }
    std::string& back() {
        check(0, "Called back on empty vector.");
        return data->back();
    }
    StrBlobPtr begin();
    StrBlobPtr end();
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) {
        if (i >= data->size()) {
            throw std::out_of_range("msg");
        }
    }
};

class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) { };
    StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(), curr(sz) { };
    std::string& deref() const {
        auto p = check(curr, "Dereference past end");
        return (*p)[curr];
    }
    StrBlobPtr& incr() {
        check(curr, "Increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
private:
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
    std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string &msg) const {
        auto ret = wptr.lock();
        if(!ret) { throw std::runtime_error("Unbound StrBlob."); }
        if(i >= ret->size()) { throw std::out_of_range(msg); }
        return ret;
    }
};

#endif