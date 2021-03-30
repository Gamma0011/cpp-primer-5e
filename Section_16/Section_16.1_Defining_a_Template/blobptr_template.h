#ifndef __BLOBPTR_H__
#define __BLOBPTR_H__

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "blob_template.h"

template<typename T>
class BlobPtr {
public:
    BlobPtr() : curr(0) { };
    BlobPtr(Blob<T> &a, std::size_t sz = 0) : wptr(a.data), curr(sz) { };

    T& operator*() const;
    BlobPtr& operator++();
    BlobPtr& operator--();
    bool operator!=(const BlobPtr &);
private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

// overloaded operators

template<typename T>
T& BlobPtr<T>::operator*() const {
    auto e = check(curr, "Dereference past end.");
    return (*e)[curr];
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
    BlobPtr ret = *this;
    --*this;
    return ret;
}

template<typename T>
bool BlobPtr<T>::operator!=(const BlobPtr<T> &bp) {
    return curr != bp.curr;
}

// functions
template<typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t sz, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret) { throw std::runtime_error("Unbound BlobPtr."); }
    if (sz >= ret->size()) { throw std::out_of_range(msg); }
    return ret;
}


#endif