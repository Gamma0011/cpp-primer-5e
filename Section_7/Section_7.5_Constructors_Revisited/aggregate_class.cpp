#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;

/* Aggregate Class
    An aggregate class gives its users direct access to its members and has special initialization syntax. A class is aggregate if:
    - All of its data members are public
    - It does not define any constructors
    - It has no in-class initializers
    - It has no base classes or virtual functions, which are class-related features
*/

// Aggregate Class
struct Data {
    int ival;
    string s;
};

// we can initialize data members of an aggregate class by providing a braced list of member initalizers
// initializers MUST appear in declaration order
// val1.ival = 0; val1.s = string("Anna");
Data val1 = {0, "Anna"};
// Iniitalizers out of order ERROR:     Data val2 = {"Anna", 23};

// If the list of initializers has less than the elements of the class, values are default-initialized
Data val3 = {0};        // string s = ""
// The list of initializers cannot exceed that of the elements of the class.
// Data val4 = {23, "anna", "nyc"};    // error


int main()
{


    return 0;
}
