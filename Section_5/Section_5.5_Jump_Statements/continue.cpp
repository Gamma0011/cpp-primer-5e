#include <iostream>
#include <string>
#include <vector>

using std::cin; 
using std::cout; 
using std::endl; 
using std::string;
using std::vector;

// continue terminates the current iteration of the nearest enclosing loop and immediately begins the next iteratio
// can only appear inside a for, while, or do while loop
// continue may appear inside a switch only if that switch is embedded inside of an iterative statement

// continue iterrupts the current iteration, but execution remains inside of the loop
// in the case of while && do while, execution continues by evaluating the condition

int main()
{

    string buf;
    while (cin >> buf && !buf.empty()) {
        if (buf[0] != '_') {
            continue;       // get another input
        }
    }

    return 0;
}
