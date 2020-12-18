#include <iostream>

void e19_redo();
void e110_redo();
void e111_redo();

int main()
{
    std::cout << "\nExercise 1.9\n";
    e19_redo();

    std::cout << "\nExercise 1.10\n";
    e110_redo();

    std::cout << "\nExercise 1.11\n";
    e111_redo();

    return 0;
}

void e19_redo(){
    // sum 50 to 100 inclusive. Print sum.

    int num = 50;

    for(int counter = 51; counter <= 100; ++counter){
        num+=counter;
    }
    
    std::cout << "Sum of 51 to 100 inclusive is " << num <<std::endl;
}

void e110_redo(){

    // count from 10 to 0 and print number
    for(int counter = 10; counter >= 0; --counter){
        std::cout << counter <<std::endl;
    }
}

void e111_redo(){
    
    // prompt user for a higher and lower number. Count from higher to lower. Print current number.

    int lower = 0, higher = 0;

    std::cout << "Let's count! Please enter a lower number: ";
    std::cin >> lower;

    std::cout << "And, let's enter that higher one: ";
    std::cin >> higher;

    for(int counter = lower; counter <= higher; ++counter){
        std::cout << counter <<std::endl;
    }
}