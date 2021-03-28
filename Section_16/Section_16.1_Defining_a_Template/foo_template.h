#ifndef __FOO_H__
#define __FOO_H__

#include <iostream>

template<typename T> class Foo {
public:
    static std::size_t count();
private:
    static std::size_t ctr;
};

template<typename T>
std::size_t Foo<T>::count() {
    return ctr;
}

template<typename T>
std::size_t Foo<T>::ctr = 0;


#endif