#ifndef HASPTR_CLASS
#define HASPTR_CLASS

#include <iostream>
#include <string>
#include <vector>
#include <utility>

class HasPtr {
private:
    friend void swap(HasPtr &, HasPtr &);
    friend bool operator<(HasPtr &, HasPtr &);

    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { };
    HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i) { };                   // each HasPtr has its own copy of the string to which ps points
    HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) { p.ps = 0; }                        
    HasPtr& operator=(HasPtr);
    ~HasPtr() { delete ps; }

    HasPtr& swap(HasPtr &);

public:
    std::string *ps;
    int i;
};

HasPtr& HasPtr::operator=(HasPtr rhs) {
    using std::swap;
    swap(*this, rhs);
    return *this;                        // return the object
}

HasPtr& HasPtr::swap(HasPtr &rhs) {
    using std::swap;
    swap(ps, rhs.ps);
    swap(i, rhs.i);
    std::cout << "Swap (&rhs)." <<std::endl;
    return *this;
}    

bool operator<(HasPtr &lhs, HasPtr &rhs) {
    std::cout << "operator<" <<std::endl;
    return *lhs.ps < *rhs.ps;
}

void swap(HasPtr &lhs, HasPtr &rhs) {
    std::cout << "Swap (&lhs, &rhs)" <<std::endl;
    lhs.swap(rhs);
}


#endif