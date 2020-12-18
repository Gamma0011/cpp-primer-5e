#include <iostream>

int main()
{
    int counter= 10;

    // print counter number and stop when counter == 0
    while(counter!=0){
        std::cout << counter <<std::endl;
        --counter;
    }
    return 0;
}
