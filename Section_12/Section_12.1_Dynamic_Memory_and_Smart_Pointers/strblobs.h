#ifndef strblob_h
#define strblob_h

#include <iostream>
#include <vector>
#include <initializer_list>
#include <string>
#include <memory>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
public:
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
    typedef std::vector<std::string>::size_type size_type;
    StrBlob() : data(std::make_shared<std::vector<std::string>>()) { };      // default constructor
    StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) { };
    size_type size() { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &s) { 
        //check(0, "Called push_back on empty vector.");
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
    ConstStrBlobPtr cbegin() const;
    ConstStrBlobPtr cend() const;
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) {
        if (i >= data->size()) {
            throw std::out_of_range(msg);
        }
    }
};

class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) { };
    StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) { };
    bool operator!=(StrBlobPtr &p) { return p.curr != curr; }
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

class ConstStrBlobPtr {
public:
    ConstStrBlobPtr() : curr(0) { };
    ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) { };
    bool operator!=(ConstStrBlobPtr &csb) { return csb.curr != curr; }
    std::string &deref() {
        auto p = check(curr, "Cannot dereference past end");
        return (*p)[curr];
    }
    ConstStrBlobPtr& incr() {
        check(curr, "Cannot increment past end");
        ++curr;
        return *this;
    }

private:
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
    std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string &msg) {
        auto ret = wptr.lock();
        if(!ret) { throw std::runtime_error("Unbound ConstStrBlobPtr."); }
        if(i >= ret->size()) { throw std::out_of_range(msg); }
        return ret;
    }
};

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }
ConstStrBlobPtr StrBlob::cbegin() const { return ConstStrBlobPtr(*this); }
ConstStrBlobPtr StrBlob::cend() const { return ConstStrBlobPtr(*this, data->size()); }

#endif
