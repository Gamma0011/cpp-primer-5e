#ifndef __SHARED_PTR_H__
#define __SHARED_PTR_H__

#include <iostream>
#include <functional>

template<typename T>
class shared_ptr {
public:
    shared_ptr() = default;
    shared_ptr(T *ptr, std::function<void(T*)> func = nullptr) :
        p(ptr), del(func), usage(new std::size_t(1)) { };
    
    shared_ptr(const shared_ptr&);
    shared_ptr& operator=(const shared_ptr&);
    ~shared_ptr();

    void reset() noexcept;
    void reset(T *ptr, std::function<void(T*)> func = nullptr);

    T* get() const noexcept { return p; }
    bool operator!=() const noexcept { return this->get() != nullptr; }
    std::size_t usage_count() const noexcept { return (!*this) ? 0 : *usage; }
    bool unique() const noexcept { return this->usage_count() == 1; }

private:
    T *p = nullptr;
    std::size_t *usage = nullptr;
    std::function<void(T*)> del = nullptr;
    void decrement_free();
};

template<typename T>
inline shared_ptr<T>::shared_ptr(const shared_ptr &ptr) :
    p(ptr.p), del(ptr.del), usage(p.usage) {
        if (*this) {
            ++*usage;
        }
    };

template<typename T>
inline shared_ptr<T>& shared_ptr<T>::operator=(const shared_ptr &rhs) {
    if (this != &rhs) {
        if (*this) {
            decrement_free();
        }
    }
    return *this;
}

template<typename T>
inline shared_ptr<T>::~shared_ptr() {
    if (*this) {
        decrement_free();
    }
}

template<typename T>
inline void shared_ptr<T>::decrement_free() {
    if (--*usage == 0) {
        (del) ? del(p) : delete p;
    }
    p = nullptr;
    usage = nullptr;
}

#endif