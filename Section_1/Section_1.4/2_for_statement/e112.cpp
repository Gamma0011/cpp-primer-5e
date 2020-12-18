#include <iostream>

int main()
{
    int value =0;

    for(int i = -100; i <= 100; ++i){
        value+=i;
    }

    std::cout <<  "Sum of -100 to 100 inclusive is " << value <<std::endl;

    return 0;
}
