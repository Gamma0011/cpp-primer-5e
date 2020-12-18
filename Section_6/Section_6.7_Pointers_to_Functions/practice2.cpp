#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
// the easiest way to declare a function that returns a pointer to a function is by using a tupe alias
using F = int(int*, int);           // F is a function type, not a pointer
using PF = int(*)(int*, int);       // PF is a pointer type

PF f1(int);     // ok: PF is a pointer to function; f1 returns a pointer to a function
//F f2(int);      // error: F is a declared function type. f2 can't return function, only pointer to function
F *f3(int);     // ok: explicitly specifies that the return type is a pointer to a function

// we can also declare f3 directly:
int (*f3(int))(int*, int);           
// we can simplify declarations of functions that return pointers to function by using a trailing return
auto f1(int) -> int (*)(int*, int); 

// as we've seen in the declaration of useBigger, writing function pointer types gets tedious
//  Type aliases along with decltype let us simplify code that uses function pointers:

bool lengthCompare(const string&, const string&);
// Func and Func2 have function type
typedef bool Func(const string&, const string&);
typedef decltype(lengthCompare) Func2;              // equivalent type

// FuncP and FuncP2 have pointer to function type
typedef bool (*FuncP)(const string&, const string &);
// NOTE!! decltype always returns function type. In order to use decltype and return *, we must declare it -- hence *FuncP2
//typedef decltype(const string&, const string&) *FuncP2;     // same type


// third parameter is a function type and is automatically treated as a pointer to a function
void useBigger(const string &s1, const string &s2, bool pf(const string &, const string &));
// same declaration: explicitly define the parameter as a pointer to a function
void useBigger(const string &s1, const string &s2, bool(*pf)(const string &, const string &));

/* USING auto OR decltype FOR FUNCTION POINTER TYPES

    string::size_type sumLength(const string &, const string &);
    string::size_type largerLength(const string &, const string&);

    // depending on the value of its string parameter
    // get Fcn returns a pointer to sumLength or to largerLength
    decltype(sumLength) *getFcn(const string&);


*/



int main()
{
    // automatically converts the function length compare to a pointer to function
    //  useBigger(s1, s2, lengthCompare);



    return 0;
}
