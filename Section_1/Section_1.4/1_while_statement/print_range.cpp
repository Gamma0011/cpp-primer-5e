#include <iostream>

int main()
{
    // prompt user for a higher and lower int value, print numbers between them
    int lower=0, higher=0;

    std::cout << "Let's count! Please enter the lower number: ";
    std::cin >> lower;

    std::cout << "Please enter the higher number: ";
    std::cin >> higher;

    while (lower<=higher){
        std::cout << lower <<std::endl;
        lower++;
    }

    return 0;
}