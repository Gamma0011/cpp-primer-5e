#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istream;
using std::ostream;

// redefining class Sales_data as a class and not a struct
class Sales_data {
    // friend declaration for non-member Sales_data operations
friend Sales_data add(const Sales_data&, const Sales_data&);
friend istream &read(istream&, Sales_data&);
friend ostream &print(ostream&, const Sales_data&);
    // other members and access specifiers
public:
    Sales_data() = default;
    Sales_data(const string &s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue (p*n) { }
    Sales_data(const string &s) : bookNo(s) { }
    Sales_data(istream &);
    string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data&);

private:
    double avg_price() const { return units_sold ? revenue/units_sold : 0; }
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data &Sales_data::combine(const Sales_data &item) {
    revenue += item.revenue;
    units_sold += item.units_sold;
    return *this;
}

Sales_data add(const Sales_data &a, const Sales_data &b) {
    Sales_data add = a;
    add.combine(a);
    return add;
}

istream &read(istream &is, Sales_data &item) {
    double price;
    cout << "Please enter the ISBN, Units Sold, and Price: ";
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item) {
    os << "Book Number: " << item.bookNo << '\n'
       << "Books Sold: " << item.units_sold << '\n'
       << "Total Revenue: $" << item.revenue <<endl;
    return os;
}


int main()
{



    return 0;
}
