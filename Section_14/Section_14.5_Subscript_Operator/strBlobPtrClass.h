#ifndef STRBLOBPTR_CLASS
#define STRBLOBPTR_CLASS

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "strBlobClass.h"

class StrBlobPtr {
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator>(const StrBlobPtr &, const StrBlobPtr &); 
public:
    StrBlobPtr() : curr(0) { };                 // default constructor generates a null StrBlobPtr
    StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) { };
    std::string& deref() const;
    StrBlobPtr& incr();         // prefix version

    std::string& operator[](std::size_t);
    const std::string& operator[](std::size_t) const;
private:
    // check returns a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
    // store weak_ptr, which means underlying vector might be destroyed
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

// subscript operators
std::string& StrBlobPtr::operator[](std::size_t n) {
    auto p = check(n, "Subscript out of Range!");
    return (*p)[n];
}

const std::string& StrBlobPtr::operator[](std::size_t n) const {
    auto p = check(n, "Subscript out of Range!");
    return (*p)[n];
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();                                             // is the vector still around?
    if(!ret) { throw std::runtime_error("Unbound StrBlobPtr"); }        // if null
    if(i >= ret->size()) { throw std::out_of_range(msg); }              
    return ret;                                             // return shared_ptr to vector
}

std::string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];      //  (*p) is the vector to which the object points
}

StrBlobPtr& StrBlobPtr::incr() {        // prefix: return a reference to the incremented object
    // if curr already points past the end of the container, cannot increment
    check(curr, "Increment past end of StrBlobPtr.");
    ++curr;         // advance current state
    return *this;
}
/*

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

*/

#endif