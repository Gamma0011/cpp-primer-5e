#include <iostream>

int main()
{
    int a = 3, b = 4;
    decltype(a) c = a;      // c has type int
    std::cout << c <<std::endl;

    decltype((b)) d = a;    // d is int& of a
    std::cout << d <<std::endl;

    ++c;                    // c = 4
    std::cout << c <<std::endl;
    ++d;                    // d = 4
    std::cout << d <<std::endl;

    return 0;
}