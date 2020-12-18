#include <iostream>

int main()
{
    const int ci = 1024;

    const int &r1 = ci;     // ok: both reference and underlying object are constant
    r1 = 42;                //error: r1 is a reference to const
    int &r2 = c1;           //error: nonconst reference to a const object
    

    return 0;
}
