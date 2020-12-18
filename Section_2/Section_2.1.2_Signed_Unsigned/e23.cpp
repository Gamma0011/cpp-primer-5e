#include <iostream>

int main()
{

    unsigned u = 10, u2 = 42;
    std::cout << u2 - u <<std::endl;

    // this will fail. Unsigned cannot be less than 0;
    std::cout << u - u2 <<std::endl;


    // by default, values will be signed, allowing them to be positive, negative and 0
    int i = 10, i2 = 42;
    std::cout << i2 -i <<std::endl;
    std::cout << i - i2 <<std::endl;

    // both these will pass
    // if one operand is unsigned, the signed type will convert to unsigned to allow the computation to happen
    std::cout << i - u <<std::endl;
    std::cout << u - i <<std::endl;

    // this will fail; reason: signed (i) - (unsigned) u2
    // signed (i) converts to unsigned type, therefore, unsigned (i = 10) - unsigned (u2 = 42) = -32. 
    // Negative unsigned type cannot exist, therefore the compiler prints the number of bits in an int type (this case, 32 bits)
    std::cout << i - u2 <<std::endl;



    return 0;
}