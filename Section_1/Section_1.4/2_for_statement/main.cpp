#include <iostream>

int main()
{

    int value = 0;

    // add 1 to 10 inclusively using a for loop
    for(int counter = 1; counter <=10; ++counter){
        value+=counter;
    }

    std::cout << "1 to 10 added inclusively equals " << value <<std::endl;

    return 0;
}