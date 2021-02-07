#include <iostream>
#include <vector>
#include <string>
#include "sales_data.h"

/*
    e14.20  - Define the addition and compound-assignment operators for your Sales_data class.
                    see. sales_data.h
                            friend Sales_data& operator+(const Sales_data&, const Sales_data&);
                            Sales_data& operator+=(const Sales_data&);

    e14.21  - Write the Sales_data operator so that + does the actual addition and += calls +. Discuss the disadvantages of this approach.
                We need to dereference this to add to rhs, which calls the + function. From there, temp is returned and becomes *this, which is then returned.
                 It's a bunch of unnecessary work and is confusing to read.

                Sales_data& operator+(const Sales_data &lhs, const Sales_data &rhs) {
                    auto temp = lhs;
                    temp = temp.units_Sold + rhs.units_sold;
                    temp = temp.revenue + rhs.revenue;
                    return temp;
                }
                Sales_data& operator+=(const Sales_data &rhs) {
                    *this + rhs;
                    return *this;
                }
    
    e14.22  - Define a version of the assignment operator that we can assign a string representing an ISBN to a Sales_data.
                    see. sales_data.h


                *need to keep working*
*/

int main()
{
    Sales_data test;
    std::string s("test");
    test = s;


    return 0;
}
