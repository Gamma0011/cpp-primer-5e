#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <istream>

class Sales_data{
public:
    friend std::istream& operator>>(std::istream&, Sales_data&);

    Sales_data() = default;
    Sales_data(std::string bn, unsigned us, double r) : bookNo(bn), units_Sold(us), revenue(r) { };

    double avg_price() const;

    std::string bookNo;
    unsigned units_Sold = 0;
    double revenue = 0;
};

double Sales_data::avg_price() const {
    if (units_Sold) { 
        return revenue/units_Sold; 
    } else { 
        return 0; 
    }
}

#endif