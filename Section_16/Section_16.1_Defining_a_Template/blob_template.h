#ifndef __BLOB_H__
#define __BLOB_H__

#include <iostream>
#include <string>
#include <vector>
#include <memory>

//#include "blobptr_template.h"

// forward declarations needed for friend declarations in Blob
template<typename> class BlobPtr;
template<typename> class Blob;
template<typename T> bool operator==(const Blob<T>&, const Blob<T>&);


// defining of class Blob
template<typename T> class Blob {
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    // constructors
    Blob();
    Blob(std::initializer_list<T> il);
    template<typename It> Blob(It b, It e);
    
    // copy control
    Blob(const Blob<T> &);
    Blob<T>& operator=(const Blob<T> &);

    // number of elements in Blob
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    // add/remove elements from data
    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();

    // element access
    T& front();
    T& back();
    T& operator[](size_type i);

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

/************* constructors *************/
template<typename T>
Blob<T>::Blob() : data(std::shared_ptr<std::vector<T>>()) { };

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(std::shared_ptr<std::vector<T>>(il)) { };

template<typename T> 
template<typename It>
Blob<T>::Blob(It b, It e) : data(std::make_shared<std::vector<T>>(b,e)) { };

// copy constructor
template<typename T>
Blob<T>::Blob(const Blob<T> &b) {
    data = b.data;
}

// copy assignment operator
template<typename T>
Blob<T>& Blob<T>::operator=(const Blob<T> &b) {
    if (*this != b) { data = b.data; }
    return *this;
}

/************* public member functions *************/

template<typename T>
void Blob<T>::pop_back() {
    check(0, "pop_back called on empty Blob");
    data->pop_back();
}

template<typename T>
T& Blob<T>::front() {
    check(0, "Front called on empty Blob");
    return data->front();
}

template<typename T>
T& Blob<T>::back() {
    check(0, "Back on empty Blob");
    return data->back();
}

template<typename T>
T& Blob<T>::operator[](size_type i) {
    // if i too big, check will throw, preventing access to nonexistent element
    check(i, "Subscript out of range.");
    return (*data)[i];
}

/************* private member functions *************/
template<typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size()) {
        std::out_of_range(msg);
    }
}

#endif