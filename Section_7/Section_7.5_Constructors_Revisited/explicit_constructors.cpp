#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;

// https://stackoverflow.com/questions/7099957/implicit-vs-explicit-conversion


class Sales_data {
public:
    friend const ostream &print(ostream &os, Sales_data &item);
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(n*p) { }
    explicit Sales_data(const std::string &s): bookNo(s) { }
    // explicit keyword only meaningful inside class body - kind of like friend. Don't use for members outside the class body
    explicit Sales_data(istream &is);
    istream &read(istream &is, Sales_data &item) { return is; }
private:
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};

// no need for explicit declaration here
Sales_data::Sales_data(istream &is) { read(is, *this); }

const ostream &print(ostream &os, Sales_data &item) { os << item.bookNo << '\n' << item.units_sold << '\n' << item.revenue <<endl; return os;}

/*  Implicit conversions happens when using the copy form of initialization =
    Explicit constructors CANNOT be used with this form of initialization, instead we must use direct initialization

    Sales_data item1(null_book);            // okay: direct initilization
    Sales_data item2 = null_book;           // ERROR: COPY FORM INITILIZATION

    // ok: the argument is an explicitly constructed Sales_data object
    item.combine(Sales_data(null_book));
    // ok: static_cast can use an explicit constructor
    item.combine(static_cast<Sales_data>(cin));

*/

int main()
{

    Sales_data test;
    print(cout, test);

    return 0;
}