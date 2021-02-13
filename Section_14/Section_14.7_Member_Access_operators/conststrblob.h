#ifndef conststrblob_h
#define conststrblob_h

#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>

#include "strBlobClass.h"
#include "strBlobPtrClass.h"

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

    const std::string& operator*() const;             // dereference operator
    const std::string* operator->() const;            // arrow operator
private:
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
    std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string& msg) const {
        auto ret = wptr.lock();
        if(!ret) { throw std::runtime_error("Unbound Const StrBlob"); }
        if(i >= ret->size()) { throw std::out_of_range(msg); }
        return ret;
    }
};


// dereference operator
const std::string& ConstStrBlobPtr::operator*() const {
    auto e = check(curr, "Dereferenced element out of range");
    return (*e)[curr];
}

// arrow operator
const std::string* ConstStrBlobPtr::operator->() const {
    auto e = check(curr, "Element out of range");
    return & this->operator*();
}


// ConstStrBlobPtr StrBlob::begin() { return ConstStrBlobPtr(*this); }
// ConstStrBlobPtr StrBlob::end() { return ConstStrBlobPtr(*this, data->size()); }

#endif