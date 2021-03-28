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
    
    T& operator*() const {
        auto p = check(curr, "Dereference past end.");
        return (*p)[curr];
    }

    BlobPtr& operator++();
    BlobPtr& operator--();
private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};


template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
    BlobPtr ret = *this;
    ++*this;
    return ret;
}


#endif