#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// because we cannot copy an array, a function cannot return an array
// However, a function can return a pointer or a ref to an array, although the syntax to define functions that return pointers or refs to arrays is daunting

// Most straightforward way is to use a type alias

typedef int arrT[10];       // arrT is a synonym for the type array of 10 ints;
using arrT = int[10];       // equivalent declaration of arrT;
arrT* func(int i);          // func returns a pointer to an array of 10 ints;

// to declare a function without a type alias, we ,ust remember the array's dimension

int arr[10];                // arr is an array of 10 ints;
int *p1[10];                // p1 is an array of 10 pointers;
int (*p2)[10] = &arr;       // p2 pointers tp an array of 10 ints;


int (*func(int i))[10];     // this declares func without using a type alias;

// in C++11, we can use a trailing return type, and is useful for complicated returns such as pointers or & to arrays
//func takes an int arg and returns a pointer to an array of 10 ints;
auto func1(int i) -> int(*)[10];


// using decltype
int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};

// returns a pointer to an array of 5 ints elements;
decltype(odd) *arrPtr(int i)
{

    return (i % 2) ? &odd : &even;      // returns a pointer to the array;
}

int main()
{
    // int ia[10] = {0,1,2,3,4,5,6,7,8,9};
    // func1(ia);

    return 0;
}
