#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;

// #1 : Array Reference Parameters
// okay: parameter is a reference to an array; the dimension is part of the type
// parentheses around the &arr are necessary:
        // f(int &arr[10])      - Declares arr as an array of reference;
        // f(int (&arr)[10])    - Declares arr as a reference to an array of 10 ints;
void print(int (&arr)[10])          // because the size of the array is a part of the type, only arrays with 10 ints will work;
{
    for(auto elem : arr) {
        cout << elem <<endl;
    }
}


// #2 : Passing a Multidimensional Array
// Remember, there are no multidimensional arrays in C++, only arrays of arrays
// A multidimensional array is passed as a pointer to its first element
        // int *matrix[10]      - array of 10 pointers
        // int (*matrix[10])    - pointer to an array of 10 ints
// in this example, matrix points to the first element of an array whose elements are an array of 10 ints
void print(int (*matrix)[10], int rowSize)  // same as: void print(int matrix[][10], int rowSize) {}
{ /* */
}

int main()
{


    return 0;
}
