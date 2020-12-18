#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

using F = int(int, int);            // standard function type
using FP = int(*)(int,int);         // function pointer type

// e654 - write a declaration for a function that takes 2 int parameters and returns int.
// then declare a vector whose elements have this function pointer type
int f1(int, int);

vector<decltype(f1) *> storage = {};               // vector elements of function pointer type
vector<FP> storage2 = {};                          // this is also a valid declaration

// e655 - write four functions that add, subtract, multiply and divide two int values. Store pointers to these functions in your vector

int add(int a, int b) {return a + b;}

int subtract(int a, int b) {return a - b;}

int multiply(int a, int b) {return a * b;}

int divide(int a, int b) {return b =! 0 ? a / b : 0;}


int main()
{
    // e656 - call each element in the vector and print their results
    vector<decltype(add) *> vecOfPointers{add, subtract, multiply, divide};

    for (auto f : vecOfPointers) {
        cout << f(1,2) <<endl;
    }


    return 0;
}
