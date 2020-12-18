#include <iostream>

int main()
{

    extern int i;       // declares but does not define i
    int j;              // declares and defines j


    // any declaration that includes an explicit initalizer is a definition

    extern double pi = 3.1416; // definition


    /* variables must be defined exactly once but can be declared many times
     *
     * To use a variables in more than one files requires declarations that are separate from the variable's definition.
     * To use the same variable in multiple files, we must define that variable in one and only one file.
     * Other files that use that variable must declare but not define that variable.
     * 
     */

    return 0;
}