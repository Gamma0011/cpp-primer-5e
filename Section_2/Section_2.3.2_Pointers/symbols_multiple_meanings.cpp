#include <iostream>

int main()
{
    int i = 42;
    int &r = i;     // r& follows a type and is part of a declaration; r is a reference
    int *p;         // * follows a type and is part of a declaration; p is a pointer
    p = &r;         // & is used in an expression as the address-of operator because p is a pointer
    *p = i;         // * is used in an expression as the dereference operator
    int &r2 = *p    // & is part of a declaration; * is the dereference operator. r2 is a reference of the object pointer

    return 0;
}