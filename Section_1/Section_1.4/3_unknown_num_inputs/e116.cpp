#include <iostream>

int main()
{
    // ask user to input 5 numbers, add all together and print the sum

    int num = 0, input = 0;

    std::cout << "Please enter 5 numbers to add: " <<std::endl;

    for (int counter = 1; counter <= 5; ++counter){
        std::cin >> input;
        num+=input;
    }

    std::cout << "The sum of the 5 numbers you entered is: " << num <<std::endl;

    return 0;
}
