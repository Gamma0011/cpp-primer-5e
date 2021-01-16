#include <iostream>
#include <vector>
#include <string>

/*
    e13.13  - A good way to understand copy-control members and constructors is to define a simpile class with these members
                in which each member prints its name. Add the copy-assignment operator and destructor, and write a program using X
                objects in various ways.
                    - Pass them as nonreference and reference parameters
                    - Dynamically allocate them
                    - Put them in containers
        
                **Remember, compiler can omit calls to the copy constructor.

                struct X {
                    X() { std::cout << "X()" <<std:::endl; }
                    X(const X&) { std::cout << "X(const X&)" <<std::endl; }

                }


            1) Direct Initialization - test2(test1)         - Constructor, Copy Constructor, Destructor (test2), Destructor (test1)
            2) Direct Initialization - *test2(&test1)       - Constructor, Destructor
            
*/

struct X {
    X() { std::cout << "X()" <<std::endl; }                                         // default
    X(const X&) { std::cout << "X(const X&)" <<std::endl; }                         // copy constructor
    X& operator=(const X&) { std::cout << "X& operator=(const X&)" <<std::endl; return *this; }   // copy-assignment operator
    ~X() { std::cout << "~X()" <<std::endl; }
};

int main()
{
    X test1;
    X *test2(&test1);

    return 0;
}