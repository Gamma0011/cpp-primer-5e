#include <iostream>

// program is legal, in for loop, i = 0 and exists in local scope of for loop
// i in std::cout calls the i in local scope of function main

int main()
{
    int i = 100, sum = 0;

    for (int i = 0; i != 10; ++i){
        sum += i;
    }
    std::cout << i << " " << sum <<std::endl;

    return 0;
}
