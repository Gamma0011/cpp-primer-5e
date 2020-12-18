#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::istream;
using std::ostream;

// define your own versions of the add, read and print functions
// e78 - why does read define its Sales_data parameter as & and print defines its as const &
//   read is input stream and has to be able to write
//   print is output stream and doesn't need to write, nor do we want it to. const makes object read-only
struct Sales_data 
{
    string isbn() const { return bookNo; };
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    // data members are unchanged
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

double Sales_data::avg_price() const {
    if (units_sold) {
        return revenue / units_sold;
    } else {
        return 0;
    }
}

Sales_data& Sales_data::combine(const Sales_data &item) {
    units_sold += item.units_sold;
    revenue += item.revenue;
    return *this;
}

Sales_data add(const Sales_data &a, const Sales_data &b) {
    Sales_data sum = a;
    sum.combine(b);
    return sum;
}

istream &read(istream &is, Sales_data &item) {
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item) {
    os << "Book Number: " << item.bookNo << '\n'
       << "Units Sold: " << item.units_sold << '\n'
       << "Total Revenue: $" << item.revenue <<endl;
    return os;
}

int main()
{


    return 0;
}