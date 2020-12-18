#include <iostream>

int main()
{
    int *ip1, *ip2;     // both are points to type int
    double dp, *dp2;    // dp2 is a pointer to type double, while dp is a double

    int ival = 42;
    int *p = &ival;     // pointer p or type integer holds the address (&) of ival 

    std::cout << p <<std::endl;


    // aside from two exceptions, the types of pointers must match because the type of pointer is used
    // to infer the type of object to which the pointer points.


    /* The value (address) stored in a pointer can be in one of four states
     *  1. It can point to an object
     *  2. It can point to the location just immediately past the end of an object 
     *  3. It can be a null pointer, indicating that it is not bound to any object
     *  4. It can be invalid; values other than the preceding three are invalid
     */

    return 0;
}