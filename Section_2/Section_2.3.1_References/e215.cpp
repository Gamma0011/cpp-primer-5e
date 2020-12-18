#include <iostream>

int main()
{
    int ival = 1.01;            // float, trunicated to 1, valid
    //int &rval1 = 1.01;          // invalid, reference not object

    int &rval2 = ival;          // valid
    //int &rval3;                 // invalid, reference must be initalized


    return 0;
}