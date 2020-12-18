#include <iostream>

/* Program is for illustration purposes only: it is bad style for a function 
 * to use a global variable and also define a local variable with the same name
 */

int reused = 42; // global scope

int main()
{
    int unique = 0; // block scope within function main
                    // output #1 uses global reused and prints 42 0
    std::cout << reused << " " << unique <<std::endl;

    int reused = 0; // new, local object named reused, which hides global reused
                    // output #2 uses reused, prints 0 0 
    std::cout << reused << " " << unique <<std::endl;

                    //output #3 explicitly requests the global reused, printing 42 0
    std::cout << ::reused << " " << unique <<std::endl;
    

    return 0;
}