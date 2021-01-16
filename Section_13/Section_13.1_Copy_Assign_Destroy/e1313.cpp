#include <iostream>
#include <vector>
#include <string>
#include <memory>

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
            3) X *test3 = new(X);                           - Constructor
            4) X *test4(test3);                             - Nothing.
            5) shared_ptr<X> test5; X test6(*test5);        - Copy-assignment operator, destructor
            6) make_shared<X>();                            - Copy constructor, destructor
            7) X test8(*test7);                             - Copy-assignent operator, destructor
            8) std::vector<X> xvec = {t1};                  - Copy-assignment operator, Copy-assignment operator, destructor. Destructor to vector during memberwise destruction phase.
            9) std::vector<X> xvec;                         - Nothing
*/

struct X {
    X() { std::cout << "X()" <<std::endl; }                                         // default
    X(const X&) { std::cout << "X(const X&)" <<std::endl; }                         // copy constructor
    X& operator=(const X&) { std::cout << "X& operator=(const X&)" <<std::endl; return *this; }   // copy-assignment operator
    ~X() { std::cout << "~X()" <<std::endl; }
};

int main()
{
    //X test1;
    //X *test2(&test1);
    //X *test3 = new(X);
    //X *test4(test3);
    //delete test3;
    //delete test4;

    //std::shared_ptr<X> test5;
    //X test6(*test5);

    //auto test7 = std::make_shared<X>();
    //X test8(*test7);

    X t1, t2, t3;
    std::cout <<std::endl;
    std::vector<X> xvec = {t1};
    //std::vector<X> xvec;
    std::cout <<std::endl;

    return 0;
}