#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "strClass.h"

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
*/
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

    String s1, s2, s3, s4;

    std::cout << "*** S1 ***" << std::endl;
    svec.push_back(s1);
    std::cout << "*** S2 ***" << std::endl;
    svec.push_back(s2);
    std::cout << "*** S3 ***" << std::endl;
    svec.push_back(s3);
    std::cout << "*** S4 ***" << std::endl;
    svec.push_back(s4);
}

int main()
{
    e1348();

    return 0;
}