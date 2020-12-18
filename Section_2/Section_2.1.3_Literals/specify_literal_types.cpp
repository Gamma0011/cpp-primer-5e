#include <iostream>

/*
 * Prefix           Meaning                         Type
 * u                Unicode 16 character            char16_t
 * U                Unicode 32 character            char32_t
 * L                Wide Character                  wchar_t
 * u8               utf-8 (string literals only)    char
 * 
 *          Integer Literals                Floating-Point Literals
 * Suffix           Minimum Type        Suffix          Type
 * u or U           unsigned            f or F          Float
 * l or L           long                l or L          long double
 * ll or LL         long long
 */

int main()
{
    std::cout << L'a' <<std::endl;          // wide character literal, type is wchar_t
    std::cout << u8"hi!" <<std::endl;       // utf-8 string literal (utf-8 uses a Unicode character in 8 bits)
    std::cout << 42ULL <<std::endl;         // unsigned integer literal, type is unsigned long long
    std::cout << 1E-3F <<std::endl;         // single-prevision floating-point literal, type is float
    std::cout << 3.14159L <<std::endl;      // extended precision floating-point literal, type is long double

    return 0;
}