#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <istream>

class Sales_data{
    friend std::istream& operator>>(std::istream&, Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
    friend Sales_data operator-(const Sales_data&, const Sales_data&);
public:
    Sales_data& operator=(const std::string&);
    Sales_data& operator+=(const Sales_data&);
    Sales_data& operator-=(const Sales_data&);

    Sales_data() = default;
    Sales_data(std::string bn) : bookNo(bn) { };
    Sales_data(std::string bn, unsigned us, double r) : bookNo(bn), units_Sold(us), revenue(r) { };

    double avg_price() const;

    std::string bookNo;
    unsigned units_Sold = 0;
    double revenue = 0;
};

Sales_data&
Sales_data::operator=(const std::string &s) {
    *this = Sales_data(s);
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    auto temp = lhs;
    temp.units_Sold += rhs.units_Sold;
    temp.revenue += rhs.revenue;
    return temp;
}

Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs) {
    auto temp = lhs;
    temp.units_Sold -= rhs.units_Sold;
    temp.revenue -= rhs.revenue;
    return temp;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
    units_Sold = rhs.units_Sold;
    revenue = rhs.revenue;
    return *this;
}

double Sales_data::avg_price() const {
    if (units_Sold) { 
        return revenue/units_Sold; 
    } else { 
        return 0; 
    }
}

#endif