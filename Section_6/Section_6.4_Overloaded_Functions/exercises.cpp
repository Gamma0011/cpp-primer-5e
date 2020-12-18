#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/* 

e639 - explain the effect of the second declaration in each of the following declarations. Which if any are illegal?

(a) int calc(int, int);
    int calc(const int, const int);

    ** Legal, but redeclares calc. Top-level const has no effect on the arguments passed.

(b) int get();
    double get();

    redefines the return type of function get() to double. This is not exactly illegal, but it is confusing and ambigious 

(c) int *reset(int *);
    double *reset(double *);    

    double *reset() defines a second function of return type double. Since parameters differ, there is no conflict and the compiler
    can deduce which function to call when passed arguments

*/

int main()
{



    return 0;
}
