#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


/* do while syntax

    do
            statement
    while (condition);


*/

void practice()
{
    // repeatedly ask for a pair of numbers to sum

    string rsp;         // used in the condition; can't be defined inside of do
    do {
        cout << "Please enter two values: ";
        int val1 = 0, val2 = 0;
        cin >> val1 >> val2;
        cout << "The sume of " << val1 << " and " << val2 
             << " = " << val1 + val2 << "\n\n"
             << "More? Enter yes or no: ";
        cin >> rsp;
    } while (!rsp.empty() && rsp[0] != 'n');
}

int main()
{
    practice();


    return 0;
}
