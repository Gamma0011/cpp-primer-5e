#include <iostream>

int main()
{
    extern int ix = 1024;       // definition
    int iy;                     // declaration and definition
    extern int iz;              // declaration only

    return 0;
}