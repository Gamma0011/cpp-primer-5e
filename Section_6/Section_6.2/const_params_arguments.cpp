#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// **NOTE** use reference to const whenever possible 

void fcn(const int i);
// in C++, we can define several functions that have the same name, however, we can only do so if their parameter lists are sufficiently different
// void fcn(int i);         // error: redefines fnc(int). Because top-level consts are ignored, int i is same parameter as const int i

int main()
{
    const int ci = 42;      // const is top level
    int i = ci;             // okay, when we copy ci, it's top-level const is ignored
    int *const p = &i;      // const is top-level, we can't assign to p now;
    *p = 0;                 // okay, changes through p are allowed, i is now 0;

    return 0;
}

void fcn(const int i) 
{
    // fcn can read by not write to i;
}