#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::istream;
using std::ostream;

struct Sales_data;
istream &read(istream &, Sales_data &);                             // explicit declaration of &variables not needed

// define your own versions of the add, read and print functions
struct Sales_data 
{
    // constructors added
    Sales_data() = default;                                         // default constructor
    Sales_data(const std::string &s) : bookNo(s) { }                // constructor uses default parameters for everything except for bookNo
    /*
    Sales_data(const std::string &s) :                                  // same as Sales_data(const std::string &s) : bookNo(s) { }
        bookNo(s), units_sold(0), revenue(0) { }                            // BEST PRACTICE: use in-class initializers such as in the Sales_data(const std::string &s) : bookNo(s) { }
    */
    Sales_data(const std::string &s, unsigned n, double p) :        // constructor takes all arguments
        bookNo(s), units_sold(n), revenue(p*n) { }                      // uses the arguments to initialize                
    Sales_data(std::istream &is) { read(is, *this); }               // originally outside constructor moved within class body
    string isbn() const { return bookNo; };
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    // data members are unchanged
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// member functions
Sales_data& Sales_data::combine(const Sales_data &item) {
    revenue += item.revenue;
    units_sold += item.units_sold;
    return *this;
}

double Sales_data::avg_price() const {
    return revenue/units_sold;
}

// nonmember functions
Sales_data add(Sales_data &a, Sales_data &b) {
    Sales_data newData = a;
    newData.combine(b);
    return newData;
}

istream &read(istream &is, Sales_data &item) {
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

ostream &print(ostream &os, Sales_data &item) {
    os << "Book Number: " << item.bookNo << '\n'
       << "Units Sold: " << item.units_sold << '\n'
       << "Total Revenue: $" << item.revenue <<endl;
    return os;
}

/*
Sales_data::Sales_data(std::istream &is) {                  // defining a constructor outside of the class
    read(is, *this);                                        // read will read a transaction from is into this object
}
*/

int main()
{
    Sales_data noConstructors();
    Sales_data bookNoOnly("9089");
    Sales_data allItems("3290", 10, 89);

    return 0;
}