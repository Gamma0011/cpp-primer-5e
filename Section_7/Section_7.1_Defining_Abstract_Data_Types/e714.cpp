#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istream;
using std::ostream;

// e714 - write a version of the default constructor that explicitly initializes the members to the values we have provided as in-class constructors;

struct Sales_data 
{
    string bookNo;
    unsigned units_sold;
    double revenue;

    Sales_data()                // default constructor with explicit initialization
    {
        bookNo = "";            // initialize as empty string
        units_sold = 0;         // no units sold
        revenue = 0.0;          // no revenue
    }
};


int main()
{



    return 0;
}
