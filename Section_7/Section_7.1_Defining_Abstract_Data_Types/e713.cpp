#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istream;
using std::ostream;

// e713 - rewrite the program on pg 255 to use the istream constructor

struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    string isbn() {return bookNo;}          // function to return bookNo of class object
    Sales_data &combine(const Sales_data &);
};

Sales_data& Sales_data::combine(const Sales_data &item) {
    revenue += item.revenue;
    units_sold += item.units_sold;
    return *this;
}

// non-member function of class Sales_data
istream &read(istream &is, Sales_data &item) {
    double price = 0.0;
    cout << "Enter Book Number, Units Sold, and Price: ";
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}
ostream &print(ostream &os, Sales_data &item) {
    os << "Book Number: " << item.bookNo << '\n'
       << "Total Units: " << item.units_sold << '\n'
       << "Revenue: $" << item.revenue <<endl;
    return os;
}

int main()
{
    Sales_data total;
    if (read(cin, total)) {
        Sales_data trans;
        while (read(cin, trans)) {
            if (total.bookNo == trans.bookNo) {
                total.combine(trans);
            } else {
                print(cout, total) <<endl;
                total = trans;
            }
        }
        print(cout, total) <<endl;
    } else {
        std::cerr << "ERROR: No input" <<endl;
        return -1;
    }
    return 0;
}
