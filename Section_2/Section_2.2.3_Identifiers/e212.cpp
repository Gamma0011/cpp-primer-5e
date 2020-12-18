#include <iostream>

int main()
{
    // int double = 3.14        // illegal, cannot use double
    int _ = 10;                 // legal
    std::cout << _ <<std::endl; 

    // int 1_or_2 = 1;             // illegal, cannot contain more than one _
    double Double = 3.14;          // legal, Double is different than double, therefore Double is the variable name

    return 0;
}