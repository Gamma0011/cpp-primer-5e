#include <iostream>

int main()
{
    int one = 1, *ptr = &one;

    std::cout << *ptr << " : " << ptr <<std::endl;

    *ptr = 10;      // change the value of the pointer
    std::cout << *ptr << " : " << ptr <<std::endl;


    int two = 2;
    ptr = &two;    // change the object to which the pointer points
    std::cout << *ptr << " : " << ptr <<std::endl;

    

    return 0;
}
