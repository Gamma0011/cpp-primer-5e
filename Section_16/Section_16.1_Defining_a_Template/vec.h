#ifndef __VEC_H__
#define __VEC_H__

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <utility>
#include <memory>
#include <new>

template<typename T>
class Vec {
public:
    Vec();
    Vec(std::initializer_list<T>);

    Vec(const Vec&);
    Vec& operator=(const Vec&);
    Vec(Vec &&) noexcept;
    Vec& operator=(Vec&&) noexcept;
    ~Vec();

    std::size_t size();
    std::size_t capacity();
    std::size_t reserve(std::size_t);
    auto resize(std::size_t);
    void push_back(const T&);
    void push_back(T&&);
    T *begin() const;
    T *end() const;

private:
    static std::allocator<T> alloc;
    T *beg;
    T *lelem;
    T *cap;

    void check_n_allocate();
    void reallocate();
    std::pair<T*, T*> alloc_n_copy(const T*, const T*);
    void free();
};

// alloc implementation
template<typename T> std::allocator<T> Vec<T>::alloc;

// constructors //
template<typename T>
Vec<T>::Vec() : beg(nullptr), lelem(nullptr), cap(nullptr) { };

template<typename T>
Vec<T>::Vec(std::initializer_list<T>(il)) {
    reallocate();
    for (auto e : il) { alloc.construct(beg++, e); }
}

// copy operations //
template<typename T>
Vec<T>::Vec(const Vec<T> &v) {
    auto newdata = alloc_n_copy(v.begin(), v.end());
    beg = newdata.first;
    lelem = cap = newdata.second;
}

template<typename T>
Vec<T>& Vec<T>::operator=(const Vec<T> &v) {
    auto newdata = alloc_n_copy(v.begin(), v.end());
    free();
    beg = newdata.first;
    lelem = cap = newdata.second;
    return *this;
}

// move operations //
template<typename T>
Vec<T>::Vec(Vec<T> &&v) noexcept : beg(std::move(v.beg)),
                                   lelem(std::move(v.lelem)),
                                   cap(std::move(v.cap)) {
    v.beg = v.lelem = v.cap = nullptr;
}

template<typename T>
Vec<T>& Vec<T>::operator=(Vec<T> &&v) noexcept {
    if (*this != &v) {
        free();
        beg = std::move(v.beg);
        lelem = std::move(v.lelem);
        cap = std::move(v.cap);
        beg = lelem = cap = nullptr;
    }
    return *this;
}

// destructor //
template<typename T>
Vec<T>::~Vec() {
    free();
}

// public member functions //
template<typename T>
std::size_t Vec<T>::size() {
    return cap - beg;
}

template<typename T>
std::size_t Vec<T>::capacity() {
    return cap - lelem;
}

template<typename T>
std::size_t Vec<T>::reserve(std::size_t sz) {
    return (sz ? size() * 2 : 1);
}

template<typename T>
auto Vec<T>::resize(std::size_t sz) {
    return alloc.allocate(sz);
}

template<typename T>
T* Vec<T>::begin() const {
    return beg;
}

template<typename T>
T* Vec<T>::end() const {
    return lelem;
}

template<typename T>
void Vec<T>::push_back(const T &t) {
    check_n_allocate();
    alloc.allocate(lelem++, t);
}

template<typename T>
void Vec<T>::push_back(T &&t) {
    check_n_allocate();
    alloc.allocate(lelem++, std::move(t));
}

// private member functions //
template<typename T>
void Vec<T>::check_n_allocate() {
    if (size() == capacity()) {
        reallocate();
    }
}

template<typename T>
void Vec<T>::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto first = alloc.allocate(newcapacity);
    auto last = std::uninitialized_copy(std::make_move_iterator(begin()),
                                        std::make_move_iterator(end()),
                                        first);
    free();
    beg = first;
    lelem = last;
    cap = beg + newcapacity;
}

template<typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T *b, const T *e) {
    auto dest = alloc.allocate(e - b);
    return {dest, std::uninitialized_copy(b, e, dest)};
}

template<typename T>
void Vec<T>::free() {
    if (beg) {
        for (auto e = lelem ; e != beg ; ) {
            alloc.destroy(--e);
        }
    alloc.deallocate(beg, cap-beg);
    }
}

#endif