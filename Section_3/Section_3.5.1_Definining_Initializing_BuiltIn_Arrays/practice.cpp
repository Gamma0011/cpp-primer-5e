#include <iostream>
#include <array>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::array;

// IMPORTANT: we cannot initialize an array as a copy of another array
//  it is also illegal to assign one array to another
//      int a[] = {1,2,3};          // array of 3 ints
//      int a2[] = a;               // error: cannot initialize one array with another
//      a2 = a;                     // error: cannot assign one array to another

void practice1()
{
    unsigned cnt = 42;                  // not a constant expression
    constexpr unsigned sz = 42;         // constant expression

    int arr[10];                        // array of 10 ints
    int *parr[sz];                      // array of 42 pointers to int
    //string bad[cnt];                    // error: count is not a constant expression
    //string strs[get_size()];            // ok if get_size is constexpress, otherwise error
}

void practice2()
{
    const unsigned sz = 3;                 
    int ia1[sz] = {0,1,2};              // array of three ints with values 0, 1 , 2;
    int a2[] = {0,1,2};                 // an array of dimension 3;
    int a3[5] = {0,1,2};                // equal to a3[] = {0,1,2,0,0};
    string a4[3] = {"hi", "bye"};       // same as a4[] = {"hi", "bye", ""};
    //int a5[2] = {0,1,2};                // error: too many initalizers


    // character arrays have an additional form of initialization. We can initialize arrays from a string literal
    //  it's important to remember that string literals end with a null character, which is copied into the array with the characters in the literal

    char c1[] = {'C', '+', '+'};            // list initialization, no null
    //char c2[] = ('C', '+', '+', '\0');      // list initialization, explicit null
    char c3[] = "C++";                      // null terminator added automatically
    //char c4[6] = "Daniel";                // error: no space for null!
}

void arrayswithpointers()
{
    int *ptrs[10];                      // ptrs is an array of 10 pointers to int
    //int &refs[10] = /* ? */             // error: no arrays of references
    int (*Parray)[10] = &arr;           // Parray points to an array of 10 ints
    int (&arrRef)[10] = arr;            // arrRef refers to an array of 10 ints

}


int main()
{


    return 0;
}
