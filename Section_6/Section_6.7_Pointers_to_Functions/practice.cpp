#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// Pointers to Functions

// compares the length of two strings
bool lengthCompare(const string &, const string &);
// to declare a pointer that can point at this function, we declare a pointer in place of the function's name
//   pf points to a function that takes two const string & arguments and returns bool
bool (*pf)(const string &, const string &);             // uninitialized

// NOTE: omitting the paratheses around *pf will create a function that returns a pointer to bool (bool*)

// when we use the name of a function as a value, the function is automatically converted to a pointer. for example, we can assign the address of lengthCompare to pf:
pf = lengthCompare;     // pf now points to the function named lengthCompare
pf = &lengthCompare;    // equivalent assignment: address-of operator is optional

// additionally, we can use a pointer to a function to call the pointer to which the pointer pointers - no need to dereference the pointer
bool b1 = pf("hello", "goodbye");               // calls lengthCompare
bool b2 = (*pf)("hello", "goodbye");            // same call 
bool b3 = lengthCompare("hello", "goodbye");    // same call


// there is no conversion between pointers to one function type and pointers to another function type
// however, we can assign a nullptr or 0 to a function pointer to indicate that the pointer does not point to any function

string::size_type sumLength(const string &, const string &);
bool cstringCompare(const char *, const char *);

pf = 0;                     // ok: pf points to no function
pf = sumLength;             // error: return type differs
pf = cstringCompare;        // error paramter types differ
pf = lengthCompare;         // ok: function and pointer types match exactly

// Pointers to Overloaded Functions
// as usual, when using overloaded functions, the context must name clear which version is being used
void ff(int*);
void ff(unsigned int);
void (*pf1)(unsigned int) = ff;     // pf1 pointers to ff(unsigned); - Works because pf1 matches ff exactly

void (*pf2)(int) = ff;       // this will fail no overloaded function accepting parameters of type int
double(*pf3)(int*) = ff;     // this will also fail. wrong return type. All overloaded functions of return type void



int main()
{


    return 0;
}
