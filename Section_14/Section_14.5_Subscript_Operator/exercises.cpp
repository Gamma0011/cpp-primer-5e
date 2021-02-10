#include <iostream>
#include <vector>
#include <string>
#include "sales_data.h"
#include "vehicleClass.h"

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
    
    e14.23  - Define an initializer_list assignment operator for your version of the StrVec class.
                    see. strVecClass.h

    e14.24  - Decide whether the class you used in exercise 7.40 needs a copy- or move-assignment operator.
                    see. vehicleClass.h

    e14.25  - Implement any other assignment operators your class should define. Explain.

    e14.26  - Define subscript operators for StrVec, String, StrBlob, and StrBlobPtr classes.
                see. strVecClass.h
                     strClass.h - char& operator[](size_t); const char& operator[](size_t) const;
                     strBlobClass.h - std::string& operator[](size_t); const std::string& operator[](size_t) const;
                     strBlobPtrClass.h - 
*/

void e1422() {
    Sales_data test;
    std::string s("test");
    test = s;
}

void e1425() {
    Vehicle t1(1998, "Plymouth", "Neon", 192000);
    Vehicle t2;
    std::cout << t1 <<std::endl;
    std::cout << t2 <<std::endl;
    t2 = t1;
    std::cout << t2 <<std::endl;
}

int main()
{
    e1425();

    return 0;
}
