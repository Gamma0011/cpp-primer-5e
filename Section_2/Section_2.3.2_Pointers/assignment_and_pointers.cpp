#include <iostream>

int main()
{
    int i = 42;
    int *pi = 0;        // pi initialized but addresses no object
    int *pi2 = &i;      // pi2 initalized to hold address of i
    int *pi3;           // if pi3 defined inside of block, p3 left uninitialized -- BAD PRACTICE

    pi3 = pi2;          // pi3 and pi2 address the same object, i
    pi2 = 0;            // pi2 now addresses no object

    int ival = 80;
    pi = &ival;         // value in pi is changed; pi now points to ival
    std::cout << *pi <<std::endl;

    *pi = 0;            // value in ival is changed, pi is unchanged
                        // *pi access the object of the pointer, in this case, the pointer is bound to ival
    std::cout << ival <<std::endl;


    return 0;
}
