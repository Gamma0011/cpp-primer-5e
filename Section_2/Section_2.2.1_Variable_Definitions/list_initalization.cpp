#include <iostream>

int main()
{
    int units_sold1 = 0;         // general initalization of int = 0
    int units_sold2 = {0};       // list initalization of int
    int units_sold3{0};          // another version of list initalization of int
    int units_sold4(0);          // another general initalization of int = 0;


    // the compiler will not allow us to list initalized variables of built-in type
    // if the initilizer might lead to loss of information

    long double ld = 3.1415926536;

    int a{ld}, b = {ld};            // error: narrowing conversion required
    int c(ld), d = ld;              // will work, but value trunicated to fit within int (only prints 3)

    std::cout << c << "\n" << d <<std::endl;

    return 0;
}