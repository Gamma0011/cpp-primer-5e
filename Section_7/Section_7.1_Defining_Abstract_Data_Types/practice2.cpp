#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;

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

double Sales_data::avg_price() const 
{
    if (units_sold) {
        return revenue/units_sold;
    } else {
        return 0;
    }
}

// combine acts as += (compound assignment op)
Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;   // add the members of rhs into
    revenue += rhs.revenue;         // the members of "this" object
    return *this;                   // return the object on which the function was called
}

// input transactions contain ISBN, number of copies sold, and sales price
// IO classes (istream, ostream) are types that cannot be copied, so we may only pass them by reference &
//  Additionally, reading/writing to a stream changes it, so both functions take normal references and no const &
istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

// the add function takes two Sales_data objects and returns a new Sales_data representing their sum

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;           // copy data members from lhs into sum
    sum.combine(rhs);               // add data members from rhs into sum
    return sum;
}


int main()
{



    return 0;
}
