#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct Sales_data {
    // new members: operations on Sales_data objects
    // const member functions can be called by const and non-const objects
    // non-const member functions can only be called by a non-const object

    // The Compiler processes classes in two steps. This explains why bookNo can be defined after it's use in member function isbn()
    //      1) member declarations compiled
    //      2) member functions compiled
    std::string isbn() const { return bookNo; };
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    // data members are unchanged
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
// nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, const Sales_data&);
// when we define a member function outside the class body, the member's definition must match the declaration in the class body
        // since avg_price() was defined as a const member function, we must define const here too
double Sales_data::avg_price() const {
    if (units_sold) {
        return revenue/units_sold;
    } else {
        return 0;
    }
}

// combine acts as += (compound assignmnet op)
Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;   // add the members of rhs into
    revenue += rhs.revenue;         // the members of "this" object
    return *this;                   // return the object on which the function was called
}

int main()
{
    // pseudo-code illustration of how a call to a member function is translated: total.isbn()
    //   Sales_data::isbn(&total);

    // pseudo-code illustraction of how implicit this pointer is used
    //  this code is illegal: we may not explicitly define the this pointer ourselves
    //   note that this is a pointer to const because isbn is a const member
    // std::string Sales_data::isbn(const Sales_data *const this) { return this->bookNo; }
    
    Sales_data total;                               // variable to hold the running sum
    if (read(cin, total))   {                       // read the first transaction
        Sales_data trans;                           // variable to hold data for next transaction
        while (read(cin, trans))    {               // read the remaining transactions
            if (total.isbn() == trans.isbn())   {   // check isbns
                // below, the address of total is bound to the implicit this parameter and rhs is bound to trans
                // combine executes : units_sold += rhs.units_sold;     add the members of rhs into
                total.combine(trans);               // update running total
            } else  {
                print(cout, total) <<endl;      // print results
                total = trans;                  // process next book
            }
        }
        print(cout, total) <<endl;
        total = trans;                          // print last transaction
    } else  {                                   // no input detected
        std::cerr << "No data!" <<endl;              // notify user
    }
    return 0;
}

