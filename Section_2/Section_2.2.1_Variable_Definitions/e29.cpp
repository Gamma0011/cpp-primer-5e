#include <iostream>

int main()
{

    // std::cin >> int input_value;         // this failes because int input_value must be declared before std::cin
    // int i = {3.14};                      // this fails because 3.14 is float, not int -- error: narrowing conversion
    // double salary = wage = 9999.99       // wage was not declared
    double salary = 9999.99, wage = salary; // this works. salary declared and initalized, then wage declared and set = to salary
    int i = 3.14;                           // value is of type float, declared as int -- trunicated to 3
    std::cout << i <<std::endl;

    return 0;
}
