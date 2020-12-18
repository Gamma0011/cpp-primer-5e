#include <iostream>

int main()
{
    int sum=50, counter=51;

    while(counter<=100){
        sum+=counter;
        ++counter;
    }

    std::cout << "The sum of 50 to 100 inclusive is " << sum <<std::endl;

    return 0;
}
