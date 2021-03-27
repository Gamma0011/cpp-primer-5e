#ifndef __BLOB_H__
#define __BLOB_H__

#include <iostream>
#include <string>
#include <vector>
#include <memory>

template<typename T> class Blob {
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    // constructors
    Blob();
    Blob(std::initializer_list<T> il);

    // number of elements in Blob
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    // add/remove elements from data
    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();

    // element access
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
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) { };

/************* public member functions *************/

template<typename T>
void Blob<T>::pop_back() {
    check(0, "pop_back called on empty Blob");
    data->pop_back();
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