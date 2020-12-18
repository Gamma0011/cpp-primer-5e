#include <iostream>
#include <cstring>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    // we can initialize a string from a string literal
    string s = ("Hello world");     // s holds Hello World

    // there is no base functionality provided to use a library string when a c-style string is required
    //  however, there is a string member function called c_str that can do that
    
    // char *str = s;               // error: cant' initalize a char* from a string
    const char *str = s.c_str();    // this works
    //cout << *str <<endl;



    // ** Using an array to initialize a vector **
    // remember!! arrays cannot initialize arrays, and vectors cannot initialize arrays

    int int_arr[] = {0,1,2,3,4,5};

    // ivec has 6 elements; each is a copy of the corresponding element in int_arr
    vector<int> ivec(std::begin(int_arr), std::end(int_arr));
    // the specified range can also be a subset of the array
    vector<int> subVec(int_arr + 1, int_arr + 4);               // subVec = int_arr[1] - int_arr[3];

                
                
                // FINAL THOUGHTS!!
    /*
     * C++ Programs should use VECTORS and ITERATORS instead of built-in arrays
     *   and pointers.
     * Use STRINGS rather than C-Style array-bbased character strings.
     */

    return 0;
}
