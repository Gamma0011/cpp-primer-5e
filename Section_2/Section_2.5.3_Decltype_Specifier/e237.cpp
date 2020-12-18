#include <iostream>

int main()
{
    int a = 3, b = 4;
    
    decltype(a) c = a;      // c has type int, c = 3 | reads as int c = int& a;
    std::cout << c <<std::endl;

    decltype(a = b) d = a;  // int a = int& b | int d = int& a, d = 3
    std::cout << d <<std::endl;

    return 0;
}
