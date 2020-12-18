#include <iostream>

int main()
{
    int month1 = 9, day1 = 7;               // valid format
    int month2 = 09, day2 = 07;             // prefixing digits with 0 tells compiler to treat as an octal | invalid because expecting octal value

    std::cout << month1 << "/" << day1 <<std::endl;         
    std::cout << month2 << "/" << day2 <<std::endl;         

    return 0;
}