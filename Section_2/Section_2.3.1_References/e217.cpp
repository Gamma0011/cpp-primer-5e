#include <iostream>

int main()
{

    int i, &ri = i;

    i = 5;
    ri = 10;

    std::cout << i << " " << ri <<std::endl;            // will print out 10 for both i and ri

    return 0;
}
