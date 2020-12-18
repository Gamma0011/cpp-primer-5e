#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// e625 - write a main function that takes two arguments, concatenate the supplied arguments and print resulting string

// e626 - write a program that accepts the options presented in thsi section. print the values of the args passed to main

int main(int argc, char *argv[])
{
    string s;
    for (int i = 1; i != argc; ++i) {
        s += string(argv[i]) + " ";
    }
    cout << s <<endl;

    return 0;
}
