#include <iostream>

int main()
{
    int i = 42;
    int *p1 = &i;       // create pointer p1 and initialize to the address of i;
    *p1 = *p1 * *p1;    // calls the object of p1, and initializes it to object of pi times object of pi (pi^2)

    std::cout << *p1 <<std::endl;

    return 0;
}
