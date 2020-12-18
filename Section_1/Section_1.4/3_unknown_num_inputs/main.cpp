#include <iostream>

int main()
{

    // read until end-of-file (non-int input), calculating a running total of all values read
    // control+d denoted end-of-file input on MacOS
    int sum = 0, value = 0;
    

    std::cout << "Please enter the numbers you'd like to add, followed by ENTER." <<std::endl;
    std::cout << "Type any letter or press CONTROL + d to end." <<std::endl;

    while(std::cin >> value){
        sum+=value;
    }

    std::cout << "Sum is: " << sum <<std::endl;

    return 0;
}
