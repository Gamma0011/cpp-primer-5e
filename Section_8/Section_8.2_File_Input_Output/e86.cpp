#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;
using std::ofstream;

/*
    e86 - rewrite the bookstore program from pg 256 to read its transactions from a file. pass the name of the file as an arg to main (pg 281)
*/

struct Sales_data
{
    string isbn() const { return bookNo; };             // member function isbn()
    Sales_data& combine(const Sales_data&);             // member function combine

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;   // add the members of rhs into
    revenue += rhs.revenue;         // the members of "this" object
    return *this;                   // return the object on which the function was called
}

istream &read(istream &is, Sales_data &item) {
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

ostream &print(ostream &os, Sales_data &item) {
    os << "ISBN: " << item.bookNo << '\n'
       << "Units sold: " << item.units_sold << '\n'
       << "Total Revenue: $" << item.revenue <<endl;
    return os;
}

int main(int argv, char **argc) 
{
    std::ifstream in(argc[1]);              // open file
    Sales_data total;

    if(read(in, total)) {
        Sales_data temp;
        while(read(in, temp)) {
            if(total.isbn() == temp.isbn()) {
                total.combine(temp);
            } else {
                print(cout, total) <<endl;
                total = temp;
            }
        }
    print(cout, total) <<endl;
    } else {
        std::cerr << "ERROR: Cannot open file." <<endl;
    }


    return 0;
}