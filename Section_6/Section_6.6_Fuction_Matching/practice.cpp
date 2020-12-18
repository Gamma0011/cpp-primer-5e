#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// in most cases, it's easy to figure out which overloaded function matches a given call
//  however, it is not simple when the overloaded functions have the same number of paramters and when one or more
//   of the parameters have tupes that are related by conversion.

void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);

int main()
{
    // f(5.6);         // this calls void f(double, double);

    return 0;
}
