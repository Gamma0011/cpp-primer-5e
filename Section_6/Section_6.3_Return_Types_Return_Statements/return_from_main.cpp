#include <iostream>
#include <vector>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
    There is one exception to the rule that a function with a return type other than void must return a value;
        The MAIN function is allowed to reminate without a return.
         If controls reaches the end of main and there is no return, then the compiler implicitly inserts a return of 0;

    A 0 indicates success while most other values indicate failure. A nonzero value has a machine-dependent meaning;
    To make return values machine independent, the cstlib header defines two preprocessor variables that we can use to indicate success or failure;

    ** NOTE ** because these are preprocessor variables, we cannot proceed with with std:: nor define them in using std:: declaration ***

    return EXIT_FAILURE;        // defined in cstdlib
    return EXIT_SUCCESS;        // defined in cstdlib

*/

// Recursion
//  A function that calls itself, either directly or indirectly is a recursive function
// **NOTE** the main() function may not call itself

// calculate val!, which 1*2*3 ... *val
int factorial(int val) 
{
    if (val > 1) {
        return factorial(val - 1) * val;
    }
    return 1;
}

int main()
{
    
    if (some_failure) {
        return EXIT_FAILURE;        // defined in cstdlib
    } else {
        return EXIT_SUCCESS;        // defined in cstdlib
    }
    
   cout << factorial(5) <<endl;
}