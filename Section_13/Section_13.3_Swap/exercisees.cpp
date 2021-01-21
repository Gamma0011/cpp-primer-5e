#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
    e13.29  - Explain why the calls to swap inside swap do not cause a recursive loop
                swap(HasPtr&, HasPtr& );

                Each of the two objects within swap are unique and execute to swap the data members within the objects.
                 Once the data members are swapped, the function has completed.
    
    e13.30  - Write and test a swap function for your valuelike version of HasPtr. Give your swap a print statement that notes when it is executed.

    e13.31  - Give your class a < operator and define a vector of HasPtrs. Give that vector some elements then sort the vector. Note when swap is called.
*/

class HasPtr {
public:
    friend void swap(HasPtr &, HasPtr &);
    friend bool operator<(HasPtr &, HasPtr &);

    HasPtr(const HasPtr &h) : ps(new std::string(*h.ps)), i(h.i) { };
    HasPtr& operator=(const HasPtr &orig) {
        std::string *temp = new std::string(*orig.ps);
        delete ps;                                      // free ps memory
        ps = temp;
        i = orig.i;
        return *this;
    }

    HasPtr& swap(HasPtr &rhs) {
        using std::swap;
        swap(ps, rhs.ps);
        swap(i, rhs.i);
        std::cout << "Swap Called." <<std::endl;
        return *this;
    }

    ~HasPtr() { delete ps; };

    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { };
    void print() { std::cout << *ps <<std::endl; }
private:
    std::string *ps;
    int i;
};

void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "Swap Called." <<std::endl;
}

bool operator<(HasPtr &lhs, HasPtr &rhs) {
    return *lhs.ps < *rhs.ps;
}

void e1330() {
    HasPtr hw("Hello World");
    HasPtr gw("Goodbye World");

    swap(hw, gw);

    hw.print();
    gw.print();
}

void e1331() {
    HasPtr a("a"), d("d"), c("c"), b("b");
    std::vector<HasPtr> vec = {d,a,c,b};

    std::sort(vec.begin(), vec.end());

    for (auto &e : vec) {
        e.print();
    }
}

int main()
{
    //e1330();
    e1331();

    return 0;
}