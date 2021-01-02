#ifndef conststrblob_h
#define conststrblob_h

#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>

#include "strblobs.h"

class ConstStrBlobPtr {
public:
    ConstStrBlobPtr() : curr(0) { };
    ConstStrBlobPtr(const StrBlob &csb, std::size_t sz = 0) : wptr(csb.data), curr(sz) { }; 
    bool operator!=(ConstStrBlobPtr &s) { return s.curr != curr; }
    std::string &deref() const {
        auto p = check(curr, "Dereference past end.");
        return (*p)[curr];
    }
    ConstStrBlobPtr &incr() {
        check(curr, "Increment past end of ConstStrBlobPtr");
        ++curr;
        return *this;
    }
private:
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
    std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string& msg) {
        auto ret = wptr.lock();
        if(!ret) { throw std::runtime_error("Unbound Const StrBlob"); }
        if(i >= ret->size()) { throw std::out_of_range(msg); }
        return ret;
    }
};

ConstStrBlobPtr StrBlob::begin() { return ConstStrBlobPtr(*this); }
ConstStrBlobPtr StrBlob::end() { return ConstStrBlobPtr(*this, data->size()); }

#endif