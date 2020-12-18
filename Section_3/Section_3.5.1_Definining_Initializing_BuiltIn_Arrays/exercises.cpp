#include <iostream>
#include <array>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::array;

void e327()
{
    unsigned buf_size = 1024;

    int i1[buf_size];                   // legal, buf_size is of type int
    //int i2[4+7-14];                     // illegal, array can not be negative
    //int i3[txt_size()];                 // legal, assuming unsigned int returned
    //char c1[11] = "fundamental";        // illegal, no room for null character '/0'
}

    string sa[10];                      // array of 10 strings default initialized to ""
    int ia[10];                         // array of 10 ints default initialized to 0

void e329()
{
        // drawbacks of arrays over vectors
        // arrays have a fixed size, which offers better run-time performance, but gives less flexibility


}


int main()
{
        // what are the values in the following arrays?

    cout << *sa <<endl;
    cout << *ia <<endl;

    string sa2[10];         //  array of 10 strings default initialized to ""
    int ia2[10];            //  array of 10 ints default initialized to 0

    cout << *sa2 <<endl;
    cout << *ia2 <<endl;

    return 0;
}