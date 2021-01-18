#include <iostream>
#include <vector>
#include <string>
#include <memory>

/*
    e13.22  - Assume we want HasPtr to behave like a value. That is, each object should have its own copy
                of the string to which the object points. You already know everything you need to know about how to implement this.
                Write HasPtr copy constructor and copy-assignment operator.
*/

class HasPtr {
public:
    HasPtr(const HasPtr &h) : ps(new std::string(*h.ps)), i(h.i) { };
    HasPtr& operator=(const HasPtr &orig) {
        std::string *temp = new std::string(*orig.ps);
        delete ps;                                      // free ps memory
        ps = temp;
        i = orig.i;
        return *this;
    }
    ~HasPtr() { delete ps; };

    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { };
private:
    std::string *ps;
    int i;
};


int main()
{

    return 0;
}