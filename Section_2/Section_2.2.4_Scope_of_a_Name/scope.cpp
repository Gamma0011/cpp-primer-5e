#include <iostream>

// int main has global scope, meaning it can be used throughout the program

// curly braces establish scope | 2 types - global and block scope

int main()
{
    // int sum has block scope within main function
    int sum = 0;
        for(int value = 10; value >= 0; value--){
            // int value has block scope within for loop
            sum+=value;
        }
        std::cout << "Sum of 10 to 1 Inclusive is " << sum <<std::endl;

    return 0;
}
