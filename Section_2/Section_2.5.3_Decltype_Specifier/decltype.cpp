#include <iostream>

int main()
{
    decltype(f()) sum = x;      // sum has whatever type f returns

    const int ci = 0, &cj = ci;

    decltype(ci) x = 0;         // x has type const int
    decltype(cj) y = x;         // y has type const int& and is bound to x
    // decltype(cj) z;          // error: z is a reference and must be initialized


    // decltype of an expression can be a reference type
    int i = 42, *p = &i, &r = i;
    decltype(r + 0) b;              // int type
    decltype(*p) c;                 // error: c is int& and must be initialized
                                    // the type deduced by *p is int& and not int

    decltype((i)) d;                // decltype(()) is always reference type | error: d is int& and must be initialized
    decltype(i) d;                  // ok: e is an int

    // remember, decltype(()) is always a reference type, while decltype() is only reference type is variable is

    return 0;
}
