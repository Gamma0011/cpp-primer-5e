#include <iostream>

int main()
{
    const int i = 42;       // i is of type const int
    auto j = i;             // j is of type int (top-level const dropped)
    const auto &k = i;      // k is reference to i of type const int (top-level const dropped, but const auto declared)
    auto *p = &i;           // p is a pointer of type const int

    const auto j2 = i, &k2 = i;     // j2 is of type const int, k2 is a reference of type const int

    return 0;
}