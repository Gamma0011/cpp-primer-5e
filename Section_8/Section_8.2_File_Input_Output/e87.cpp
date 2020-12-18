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
    e87 - modify bookstore program to write output to a file
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
    std::ifstream in(argc[1]);
    std::ofstream out(argc[2], std::ofstream::app | std::ofstream::out);

    Sales_data total;
    
    if(read(in, total)) {
        Sales_data temp;
        while(read(in, temp)) {
            if(total.isbn() == temp.isbn()) {
                total.combine(temp);
            } else {
                print(out, total) <<endl;
                total = temp;
            }
        }
        print(out, total) <<endl;
    } else {
        std::cerr << "ERROR: No Files Provided." <<endl;
    }

    return 0;
}