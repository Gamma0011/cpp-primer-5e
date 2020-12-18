#include <iostream>

/*
newline             \n
vertical tab        \v
backslash           \\
carriage return     \r
horizontal tab      \h
backspace           \b
question mark       \?
formfeed            \f
alert(bell)         \a
double quote        \"
single quote        \'
*/

int main()
{
    std::cout << '\n' <<std::endl;      // prints a newline
    std::cout << "\tHi!\n" <<std::endl; // prints a tab followed by "Hi!" and a newline

    /* 
    we can also write generalize escape sequences, 
    which is \x followed by one or more hexidecimal digits
    or a \ followed by one, two, or three octal digits
    */
    std::cout << '\7' <<std::endl;      // bell
    std::cout << '\12' <<std::endl;     // newline
    std::cout << '\40' <<std::endl;     // blank
    std::cout << '\0' <<std::endl;      // null
    std::cout << '\115' <<std::endl;    // 'M'
    std::cout << '\x4d' <<std::endl;    // 'M'
    std::cout << "Hi! \x4dO\115!" <<std::endl; // print "Hi MOM!"
    std::cout << "\1234" <<std::endl;  //prints \123 ' and 4, only 3 digits in an octal value

    return 0;
}
