#include <iostream>

int main()
{
    int i = 1024, i2 = 2048;        // i and i2 are both ints
    int &r = i, r2 = i2;            // r is reference bound to i; r2 is an int
    int i3 = 1024, &ri = i3;        // i3 is an int, ri is a reference bound to i3
    int &r3 = i3, &r4 = i2;         // both references r3 bound to i3, r4 bound to i2

    // references can only be bound to an object, not a literal or to a result of a general expression

    int &refVal4 = 10;              // not legal, error: initalizer must be an object
    double dval = 3.14;             
    int &refVal5 = dval;            // error: initalizer must be an int object

    return 0;
}
