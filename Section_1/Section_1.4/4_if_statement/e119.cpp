#include <iostream>

int main()
{
    int higher=10, lower=0;

    while(higher >= lower){
        std::cout << higher <<std::endl;
        --higher;
    }
    return 0;
}
