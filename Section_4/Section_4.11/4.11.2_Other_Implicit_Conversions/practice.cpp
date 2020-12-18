#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void arr_to_ptr()
{
// array to pointer conversion: 
//  in most expressions, when we use an array, the array is automatically converted to a pointer to the first element of the array

// this conversion is NOT performed when an array is used with decltype or as the operand of the address-of (&), sizeof, or typeid operators
    
    int ia[10];     // array of ten ints;
    int* ip = ia;   // convert ia to a pointer to the first element;
}


void ptrconv()
{
    // a const integral value of 0 and the literal nullptr can be converted to any pointer type; 
    //   a pointer to any nonCONST type can be converted to void*, and a pointer to any type can be converted to a const void*
}

void convtoconst()
{
    // we can convert a pointer to a nonconst type to a pointer to the corresponding const type, and similarly for references.
    // if T is a type,we can convert a pointer or a reference to T intoa  ppointer or reference to const T

    int i;          
    const int &j = i;           // convert a nonconst to a reference to a const int;
    const int *p = &i;          // convert address of noncost to the address of a const;
    // int &r = j, *q = p;      // error: conversion from const to nonconst not allowed;
}

void convdefclasstype()
{
    // class types can define conversions that the compiler will apply automatically, but will only apply one class-type conversion at a time

    // we use a class-type converion when we use a C-style char string where a library string is expected
    //  and when we read from an istream in a condition
    string s, t = "a value";            // character string literal converted to type string;
    while (cin >> s);                   // while consition converts cin to bool;

    // (cin >> s) reads cin and yields cin as its results. conditions expect a value of type bool.
    // but this condition tests a value of type istream. the IO Library defines a conversion from istream to bool.
    // that conversion is used to automatically convert cin to bool, the resulting bool value depends on the state of the stream.

    // if the last read succeeded, then the conversion yields true, else bool yields false.


}

int main()
{

    return 0;
}
