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
                Key components: 
                                    operator< checks if lhs < rhs - returns bool
                                    operator= (copy-assignment) called and will swap if false
                                            Within operator= (*this).swap(orig) called, and *this returned - reference to HasPtr &swap();
                                            Within HasPtr &swap(), there is swap(&lhs, &rhs) that swaps the data members of objects
                                    Once all operator< == true, std::sort terminates.
    
    e13.32  - Would the pointerlike version of HasPtr benefit from defining a swap function. Why or why not?
                Swap is useful for when we work with classes that act like values because it helps with memory allocation. Pointerlike classes
                 already manage memory, so therefore, no need to define swap, unless we want more control or plan to reorder elements (where swap is almost always needed).
*/

class HasPtr {
public:
    friend void swap(HasPtr &, HasPtr &);
    friend bool operator<(HasPtr &, HasPtr &);

    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { };

    HasPtr(const HasPtr &h) : ps(new std::string(*h.ps)), i(h.i) { };

    HasPtr& operator=(HasPtr orig) {
        std::cout << "operator=" <<std::endl;
        this->swap(orig);
        return *this;
    }

    ~HasPtr() { delete ps; };

    HasPtr& swap(HasPtr &rhs) {
        using std::swap;
        swap(ps, rhs.ps);
        swap(i, rhs.i);
        std::cout << "Swap (&rhs)." <<std::endl;
        return *this;
    }

    void print() { std::cout << *ps <<std::endl; }

private:
    std::string *ps;
    int i;
};

void swap(HasPtr &lhs, HasPtr &rhs) {
    std::cout << "Swap (&lhs, &rhs)" <<std::endl;
    lhs.swap(rhs);
}

bool operator<(HasPtr &lhs, HasPtr &rhs) {
    std::cout << "operator<" <<std::endl;
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