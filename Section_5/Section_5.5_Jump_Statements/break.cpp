#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// break statement terminates the nearest enclosing while, do while, for or switch statement. 
//   execution resumes immediately following the terminated statement

int main()
{

    string buf;
    while (cin >> buff && !buff.empty()) {
        switch(buf[0]) {
            case '-':
                // process up to the first blank
                for (auto it = buf.begin()+1; it != buf.end(); ++it) {
                    if (*it == ' ')
                        break;      // #1 leaves the for loop
                }
            // break #1 transfers control here,
            // remaining '-' processing:
            break;  // break #2 leaves the switch statement   
            case '+':
                // ...
        }   // end of switch statement
        // break #2 transfers control here
    }   // end while


    return 0;
}
