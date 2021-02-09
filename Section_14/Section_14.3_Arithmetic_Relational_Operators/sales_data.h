#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <istream>

class Sales_data{
    friend std::istream& operator>>(std::istream&, Sales_data&);
    friend std::ostream& operator<<(std::ostream&, Sales_data&);
public:
    Sales_data& operator=(const std::string &s);             // assign string to bookNo;
    Sales_data& operator+=(const Sales_data&);
    Sales_data& operator-=(const Sales_data&);

    Sales_data() = default;
    Sales_data(std::string bn): bookNo(bn) { };
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

double Sales_data::avg_price() const {
    if (units_Sold) { 
        return revenue/units_Sold; 
    } else { 
        return 0; 
    }
}


/*************** NON MEMBER FUNCTIONS ***************/
std::ostream&
operator<<(std::ostream &os, const Sales_data &s) {
    os << s.bookNo << " " << s.revenue << " " << s.units_Sold;
    return os;
}


#endif