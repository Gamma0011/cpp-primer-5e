#include <iostream>

int main()
{
    int i = 0;

    // double* dp = &i;     //illegal pointer dp of different type to i
    // int *ip = i;         // illegal. trying to initialize to object of i rather than address of
    int *p = &i;            // legal!

    return 0;
}
