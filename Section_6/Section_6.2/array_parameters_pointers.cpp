#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

//void print1(const int*);


// there are three common techniques to manage pointer parameters

// #1 : using a marker to specify the extent of an array
// this works well for data where there are obvious end-marker values such as null characters (C-style string literals '\0')
/*void print(const char *cp)
{
    if (cp)                         // if cp is not a null pointer
        while (*cp)                 // so long as the character it points to is not a null character
            cout << *cp++ <<endl;   // print the character postfix and advance the pointer
}
*/

// #2 : using the standard library conventions
/*
void print(const int *beg, const int *end)
{   
    // print every element starting at beg up to but not including end
    while (beg != end) {
        cout << *beg++ <<endl;          // print the current element
                                        // advance the pointer
    }
}
*/

// #3 : explicitly passing a sizing parameter
//  const int ia[] equivalent to const int* ia
// size is passed explicitly and used to control access to elements of ia
void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i) {
        cout << ia[i] <<endl;
    }

}

int main()
{
    /*      these three declarations of print are == 
            each function has a single parameter of type const int *

            void print(const int*);
            void print(const int[]);            // shows intent that the function takes an array
            void print(const int[10]);          // dimensions for documentation purposes (at best)
    */

   // when a compiler checks a call to print, it only checks that the argument has type const int*
   int i = 0, j[2] = {0, 1};
   //print(&i);           // okay, &i is a reference to int *i[0];
   //print(j);            // j is converted to int * that, by default points to j[0];

    // begin() and end() will safely calculate the pointer arguments to pass to the print(const int*, const int*) 
    //print(std::begin(j), std::end(j));

    // explicitly passing a size parameter
    int a[] = {0,1,2,3};        // int array of size 4
    print(a, std::end(a) - std::begin(a));

    return 0;
}