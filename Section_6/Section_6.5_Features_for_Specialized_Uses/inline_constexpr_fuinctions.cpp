#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// inline is only a request to the compiler, which may ignore the inline declaration
// inline is mainly used to optimize small, straight-like functions that are called quickly.
// don't use for complex, 75 line functions
inline const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

// constexpr is a function that can be used in a constant expression.
// it must meet certain restrictions: 
//   1. return type and type of eah parameter must be a literal type
//   2. the function body must contain exactly one return statement

// NOTE: constexpr are implicitly inline functions
constexpr int new_sz() {return 42;}     //
constexpr int foo = new_sz();           // okay: foo is a constant expression


// ** PUT inline and constexpr Functions in Header Files
// The compiler needs the definition and not just the declaration
// all definitions of a given inline or constexpr must match exactly

int main()
{



    return 0;
}
