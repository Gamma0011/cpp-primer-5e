#include <iostream>

int main()
{
    const int a = 3;
    int b = 4;

    // Auto & Decltype deduce same type

    decltype(b) e;                  // e has type int

    auto f = b;                     // f has type int

    // Auto & Decltype deduce different type

    // Example 1

    decltype(a) c = a;              // c has type const int
    std::cout << c <<std::endl;

    auto d = a;                     // auto drops top-level const, d has type int
    std::cout << d <<std::endl;

    // Example 2

    int i, &j = i;

    auto i2 = j;                    // i2 has type int
    decltype(j) a2;                 // a2 has type int&

    return 0;
}
