#include <iostream>
#include <vector>
#include <string>
#include <memory>

/*
    e13.27  - Define your own reference-counted version of HasPtr
*/

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), usage(new std::size_t(1)), i(0) {};      // constructor
    HasPtr(const HasPtr &hp) : ps(hp.ps), usage(hp.usage), i(hp.i) { ++*hp.usage; };
    HasPtr& operator=(const HasPtr &rhs) {
        ++*rhs.usage;
        if (--*usage == 0) {
            delete ps;
            delete usage;
        }
        usage = rhs.usage;
        ps = rhs.ps;
        i = rhs.i;

        return *this;

    }
    ~HasPtr() {
        if (--*usage == 0) {
            delete ps;
            delete usage;
        }
    }


private:
    std::size_t *usage;
    std::string *ps;
    int i;
};

int main()
{

    return 0;
}