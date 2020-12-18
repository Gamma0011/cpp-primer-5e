#include <iostream>
#include <vector>
#include "Chapter6.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// function prototyping, also known as function declaration
void print(vector<int>::const_iterator beg, vector<int>::const_iterator end);



// factorial of val is val * (val - 1) * (val - 2), etc)

int fact(int val)
{
    int ret = 1;    // local variable to hold the result as we calculate it
    while (val > 1) {
        ret *= val--;   // assign ret * val to ret then decremenet val postfix
    }

    return ret;         // return the result;
}

// a function's parameter list can be empty, but cannot be omitted.
//  leaving () is implicit, while (void) denotes explicit
void test(void) {};

// when setting multiple parameters in a function, even those parameters of same type must be explicitly stated
// int f1(int a, b)             -- WRONG, error
// int f2(int a, int b)         -- This will work


// local statics are not destroyed when a function ends, only when a program terminates.
// therefore a local static's lifetime exists across calls
size_t count_calls()
{
    static size_t ctr = 0;      // value will persist across calls
    return ++ctr;
}


int main()
{
    /*
    int j = fact(5);        // j equals 120, i.e., the result of fact(5)
    cout << "5! is " << j <<endl;
    */

   /*
   for (size_t i = 0; i < 10; ++i){
       cout << count_calls() << '\t';
   }
   */


    cout << absolute(-910) <<endl;
    cout << factorial(50) <<endl;

    return 0;
}
