#include <iostream>

int main()
{
    // when a pointer points to an object, we can use the dereference operator (*) to access the object;

    int ival = 42;
    int *p = &ival;                 // p holds the address of ival; p is a pointer to ival
    std::cout << *p <<std::endl;    // * yields the object to which p points, in this case 42



    // Dereferencing a pointer yields the object to which the pointer points.
    // We can assign to that object by assigning to the result of the dereference.

    *p = 0;
    std::cout << *p <<std::endl;
    std::cout << p <<std::endl;

    return 0;
}