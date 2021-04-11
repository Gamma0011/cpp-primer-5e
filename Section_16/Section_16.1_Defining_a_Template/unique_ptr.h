#ifndef __UNIQUE_PTR_H__
#define __UNIQUE_PTR_H__

#include <iostream>
#include <functional>
#include <memory>


template<typename T, typename D = std::default_delete<T>>
class unique_ptr{
public:
    unique_ptr() = default;
    unique_ptr(T *ptr, D d) :
        ptr(p), del(d) { };
    
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    unique_ptr(unique_ptr&&) noexcept;
    unique_ptr& operator=(unique_ptr&&) noexcept;

    ~unique_ptr();

    void swap(unique_ptr&);
    void reset(T *t = nullptr) noexcept;

private:
    T *p = nullptr;
    D del;
};

template<typename T, typename D>
inline unique_ptr<T, D>::unique_ptr(unique_ptr &&rhs) noexcept :
    p(rhs.p), del(rhs.del) { rhs.p = nullptr; }

template<typename T, typename D>
inline unique_ptr<T, D>& unique_ptr<T, D>::operator=(unique_ptr &&rhs) noexcept {
    if (this != &rhs) {
        unique_ptr<T, D>(std::move(rhs).swap(*this))
    }
    return *this;
}

template<typename T, typename D>
inline unique_ptr<T, D>::~unique_ptr() { del(p); }

template<typename T, typename D>
void unique_ptr<T, D>::swap(unique_ptr &ptr) {
    using std::swap;
    swap(p, ptr.p);
}

template<typename T, typename D>
void unique_ptr<T, D>::reset(T *t = nullptr) noexcept {
    unique_ptr<T, D>(t).swap(*this);
}

#endif