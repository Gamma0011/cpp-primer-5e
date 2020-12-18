#include <iostream>

int main()
{
    // this is a char literal and only contains 1 character
    std::cout << 'a' <<std::endl;

    // this is a string literal, technically containing 2 characters because it's a string; 'a' and a null character \0
    std::cout << "a" <<std::endl;


    // we can span multiple lines with string literals, making it easier to read.
    // the compiler can work with this
    std::cout << "This is a string literal " 
                 "with concatenation." <<std::endl;

    return 0;
}