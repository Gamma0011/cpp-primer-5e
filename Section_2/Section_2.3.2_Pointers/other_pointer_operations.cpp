#include <iostream>

int main()
{
    int ival = 1024;

    int *p1 = 0;        // declaration of pointer, initialized to 0 or nullptr
    int *p2 = &ival;    // p2 is a valid pointer that holds the address of ival

    if (pi)         // pi has value of 0, so condition evaluates as false
        // ...

    if (pi2)        // pi2 points to ival, which != 0, therefore, the condition evaluates as true
        // ...

    /* Any nonzero pointer evaluates as true
     *
     * When comparing two pointers with != or ==, they are only equal if they share the same address!
     * 
     */


    return 0;
}
