#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "strClass.h"
#include "strVecClass.h"
#include "folderMessageClasses.h"
#include "hasPtrClass.h"

/*
    e13.45  - Distinguish between an rvalue reference and an lvalue reference.
                rvalue reference - && - refers to an object's value
                lvalue reference - &  - refers to an object's identity

    e13.46  - Which kind of reference can be bound to the following initializers?
                int f();                lvalue reference
                vector<int> vi(100);    lvalue reference

                int? r1 = f();          rvalue reference | int &&r1 = f(); f() is a function returning an int
                int? r2 = vi[0];        lvalue reference | int &r2 = vi[0];   
                int? r3 = r1;           lvalue reference | int &r3 = r1;    even though r1 is rvalue reference, binds as lvalue
                int? r4 = vi[0] * f();  rvalue reference | int &&r4 = vi[0] * f(); arithmetic returns an rvalue

    e13.47  - Give the copy constructor and copy-assignment operator in your String class a 
                statement that prints a message each time the function is execute

                see. strClass.h

    e13.48  - Define a vector<string> and call push_back several times on that vector. Run your program 
                and see how often Strings are copied

    e13.49  - Add a move constructor and move-assignment operator to your StrVec, String and Message classes
                see. folderMessageClasses.h , strVecClass.h, && strClass.h

    e13.50  - Put print statements in the move operations in your String class and rerun the program from exercise 13.48 
                that used a vector<String> to see when copies are avoided

                OUTPUT:
                    *** S1 ***
                        Copy Constructor Function Executed.                    
                    *** S2 ***
                        Copy Constructor Function Executed.
                        Move Constructor
                    *** S3 ***
                        Copy Constructor Function Executed.
                        Move Constructor
                        Move Constructor
                    *** S4 ***
                        Copy Constructor Function Executed.

                Copy Constructor called on the initial pushback operation for new element, move constructor called on already-existing elements. 

    e13.51  - Although unique_ptrs cannot be copied, in 12.1.5 (pg 471), we wrote a clone function that returned a unique_ptr by value
                Explain why this function is legal and how it works.

            unique_ptr<int> clone(int p) { return unique_ptr<int>(new int(p)); }

            int p is copied into the function. Therefore, since p is about to be destroyed once the function ends, we have the unique
             ability to tranfer ownership of p from the function. This only works when elements are about to be destroyed -- similar to the 
             parameters for using std::move
    
    e13.52  - Explain in detail what happens in the assignments of the HasPtr object on pg 541. In particular, what happens to the values of hp,
                hp2, and rhs paramter in HasPtr assignment operator

                class HasPtr {
                    public:
                        HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) { p.ps = 0; }
                        HasPtr& operator=(HasPtr rhs) { swap(*this, rhs); return *this; }
                }

                hp = hp2; 
                hp = std::move(hp2);    

                - Data members of hp2 are copied into hp using the HasPtr copy constructor and copy assignment operator.
                    During this process, string* ps receives a new memory address unique to itself, but retains the same string literal as the copied-from object
                        HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i) { }; 
                    Both the copied-from and copied-to objects exist
                - Data members of hp2 are returns as rvalue references, and ownership is moved from hp2 to hp. Calls to move constructor and move-assignment operator
                        swap function is called, swapping the lhs (to) and rhs (from) members. After the swap completes, rhs (original) is put into a state where
                        it is safe to delete. 
                    Ownership of memory address of string literal ps and int i has now be transferred to hp and hp2 is safe to destroy
    
    e13.53  - As a matter of low-level efficiency, the HasPtr assignment operator is not ideal. Explain why. Implement a copy-assignment and move-assignment operator
                for HasPtr and compare the operations executed in your new assignments vs the copy-and-swap method.

                see. hasPtrClass.h      
                        HasPtr& HasPtr::operator=(const HasPtr&);
                        HasPtr& HasPtr::operator=(HasPtr &&) noexcept;
    
    e13.54  - What would happen if we defined a HasPtr move-assignment operator, but did not change the copy-and-swap operator? Write code to test answer.
                The compiler notes a problem:
                "more than one operator "=" matches these operands: 
                    -- function "HasPtr::operator=(const HasPtr &rhs)" 
                    -- function "HasPtr::operator=(HasPtr rhs)"

                From this, it seems like leaving the copy-and-swap operator or the copy-assignment operator will cause the function matching to match both functions.
                 In this case, the compiler is unsure of which to use and returns an error. It is best in this case to only have one.

    e13.55  - Add an rvalue reference version of push_back to your StrBlob
                see. strBlobClass.h
                        void push_back(std::string &&t) { data->push_back(std::move(t)); }

    e13.56  - What would happen if we defined sorted as:
                Foo Foo::sorted() const & {
                    Foo ret(*this);
                    return ret.sorted();
                }

                This would not work. ret is an lvalue, which means that the ret.sorted() would just call the same sorted const &

    e13.57  - What if we defined sorted as:
                Foo Foo::sorted() const & {
                    return Foo(*this).sorted();
                }

                Foo(*this) returns an rvalue, therefore, the rvalue version of sorted() is called from the lvalue function.

    e13.58  - Write versions of class Foo with print statements in the sorted functions to test your answers
                see. Class Foo; below

*/

class Foo {
public:
    friend void print(const Foo&);

    Foo() =  default;               // default constructor

    /*
    Foo sorted() const & {
        Foo ret(*this);
        std::cout << "Should loop until stack exhausted." <<std::endl;      // works as expected
        return ret.sorted();
    }
    */
    Foo sorted() const & {
        std::cout << "This will work and call rvalue sorted() to perform the sort" <<std::endl;
        return Foo(*this).sorted();
    }
    /*
    Foo sorted() const & {
        Foo ret(*this);
        std::sort(ret.vec.begin(), ret.vec.end());
        return ret;
    }
    */
    Foo sorted() && {
        std::cout << "Rvalue sorted() called." <<std::endl;
        std::sort(vec.begin(), vec.end());
        return *this;
    }
    void push_back() {
        int i;
        while (std::cin >> i && i != 0) { vec.push_back(i); }
    }
private:
    std::vector<int> vec;
};

void print(const Foo &f) {
    for (auto i : f.vec) {
        std::cout << i <<std::endl;
    }
}

int f() { return 1; }

void e1346() {
    std::vector<int> vi(100);

    int &&r1 = f();
    int &r2 = vi[0];
    int &r3 = r1;
    int &&r4 = vi[0] * f();
}

void e1348() {
    std::vector<String> svec;

    String s1, s2, s3, s4, s5;

    std::cout << "*** S1 ***" << std::endl;
    svec.push_back(s1);
    std::cout << "*** S2 ***" << std::endl;
    svec.push_back(s2);
    std::cout << "*** S3 ***" << std::endl;
    svec.push_back(s3);
    std::cout << "*** S4 ***" << std::endl;
    svec.push_back(s4);
    std::cout << "*** S5 ***" << std::endl;
    svec.push_back(s5);
}

void e1354() {
    HasPtr hp1("hp1"), hp2("hp2"), hp3("hp3");

    // hp2 = hp1;
}

void e1356() {
    Foo f1;
    f1.push_back();
    print(f1.sorted());

}

int main()
{
    //e1348();
    e1356();

    return 0;
}