#include <iostream>

int i = 42;

int main()
{
    int i = 100;
    int j = i;

    std::cout << j <<std::endl;     // j = 100 because local i hid global i. no explicit declaration of use of global variable ::i

    return 0;
}