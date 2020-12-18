#include <iostream>

int main()
{
    int i = 0, &r1 = i;
    double d = 0, &r2 = d;

    r2 = 3.14159;       // valid, r2 reference, therefore r2=d=3.14159
    std::cout << d <<std::endl;

    r2 = r1;            // valid, &r2 = &r1 = i, therefore r2=0
    std::cout << r2 <<std::endl;

    i = r2;             // valid, i = &r2 = d, therefore i = 0
    std::cout << i <<std::endl;

    r1 = d;             // invalid, cannot change reference object once bound, &r1 = i
    std::cout << r1 <<std::endl;

    return 0;
}
