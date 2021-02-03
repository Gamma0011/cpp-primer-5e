#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

class Sales_data{
public:
    Sales_data() = default;

    std::string bookNo;
    unsigned units_Sold = 0;
    double revenue = 0;
};

#endif