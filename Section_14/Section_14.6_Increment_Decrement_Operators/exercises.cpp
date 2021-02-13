#include <iostream>
#include <vector>
#include <string>
#include "strBlobPtrClass.h"

/*
    e14.27  - Add increment and decrement operators to your StrBlobPtr class.

    e14.28  - Define addition and subtraction for StrBlobPtr so that these operators implement pointer arithmetic.
                see. strBlobPtrClass.h ; functions below
                
                // addition pointer arithmetic
                std::string& StrBlobPtr::operator+(std::size_t n) {
                    auto e = check(curr+n, "No Element at Position within Vector");
                    return (*e)[curr+n];
                }

                // subtraction pointer arithmetic
                std::string& StrBlobPtr::operator-(std::size_t n) {
                    auto e = check(curr-n, "No Element at Position within Vector");
                    return (*e)[curr-n];
                }
    
    e14.29  - We did not define a const version of increment or decrement operators. Why not?
                Defining const& would not allow us to properly increment or decrement through the elements
                since the element at position would be read-only. We need the ability to read and write,
                therefore, we should use & for prefix, and a copy for postfix (following the same rules
                as the postfix built-in type).

*/

int main()
{


    return 0;
}