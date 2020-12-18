#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::exception;

// throw expressions    - indicates that it has encountered something it cannot handle;
// try block            - handling part used to deal with exception (exception handlers);
// exception classes are used to pass info abbout what happened between an associated throw and catch

class Sales_item{};


void practicethrow()
{
    /* using example from pg 23
    Sales_item item1, item2;

    cin >> item1 >> item2;

    if (item1.isbn() != item2.isbn()) {
        throw runtime_error("Data must refer to the same ISBN");
    }
    cout << item1 + item2 <<endl;

    */
}

void tryblocks()
{
    /* syntax:
        try {
            program-statements
        } catch (exception declaration) {
            handler-statement
        } catch (exception declaration) {
            handler-statement
        }

    */
}

void writingahandler()
{
    while (cin >> item1 >> item2) {
        try {
            // execute code that will add the two Sales_items
            // if the additional failes, the code throws a runtime_error exception
        } catch (std::runtime_error err) {
            // remind the user that the ISBNs must match and prompt for another pair;
            cout << err.what()
                 << "\nTry again? Enter (y/n): " <<endl;
            char c;
            if (!cin || c == 'n') {
                break;      // break out of while loop
            }
        }
    }


}


int main()
{
    


    return 0;
}
