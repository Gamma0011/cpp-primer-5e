#include <iostream>

int main()
{
    std::cout << 'a' <<std::endl;           // character literal
    std::cout << L'a' <<std::endl;          // char literal of widechar_t type
    std::cout << "a" <<std::endl;           // string literal
    std::cout << L"a" <<std::endl;          // wide string literal - characters in string stored as widechar_t

    std::cout << 10 <<std::endl;            // int literal
    std::cout << 10u <<std::endl;           // unsigned int literal
    std::cout << 10L <<std::endl;           // Long int literal
    std::cout << 10uL <<std::endl;          // unsigned long int literal
    std::cout << 012 <<std::endl;           // int literal octal type
    std::cout << 0xc <<std::endl;           // int literal hexadecimal form

    std::cout << 3.14 <<std::endl;          // float literal
    std::cout << 3.14f <<std::endl;         // float literal, float type
    std::cout << 3.14L <<std::endl;         // float literal, double long

    std::cout << 10 <<std::endl;            // int literal
    std::cout << 10u <<std::endl;           // unsigned int literal
    std::cout << 10. <<std::endl;           // float literal
    std::cout << 10e-2 <<std::endl;         // 1 point precision float literal

    return 0;
}