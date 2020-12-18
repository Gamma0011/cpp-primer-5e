#include <iostream>

int main()
{
    std::cout << "Who goes with F\145rgus?\012" <<std::endl;        // \145 = e, \012 = newline | both are octals
    std::cout << 3.14e1L <<std::endl;                               // long double floating point literal, single point precision, = 31.4
    std::cout << 1024.f <<std::endl;                                // originally int, but declared as float
    std::cout << 3.14L <<std::endl;                                 // long doyble float literal

    return 0;
}