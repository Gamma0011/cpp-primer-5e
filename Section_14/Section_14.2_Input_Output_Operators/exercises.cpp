#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include "sales_data.h"
#include "strClass.h"
#include "vehicleClass.h"

/*
    e14.6   - Define an output operator for your Sales_data class
                see. std::ostream& operator<<(std::ostream &os, const Sales_data &s);
    
    e14.7   - Define an output operator for your String class you wrote in Section 13
                see. std::ostream& operator<<(std::ostream &os, const String &s);

    e14.8   - Define an output operator for the class you chose in exercise 7.40.
                see. std::ostream& operator<<(std::ostream &s, const )

    e14.9   - Define an input operator for your Sales_data class
                see. std::istream& operator>>(std::istream &is, Sales_data &s);

    e14.10  - Describe the behavior of Sales_data input operator if given the following input:
                a) This input would succeed as it matches the expected input types.
                b) This input would fail as the third input type is a string when a numeric type was expected. Default-Initialized object.

    e14.11  - What, if anything, is wrong with the following Sales_data input operator? What would happen if we
                gave this operator the data in the previous exercise?
                
                std::istream& operator>>(std::istream &in, Sales_data& s) {
                    double price;
                    in >> s.bookNo >> s.units_sold >> price;
                    s.revenue = s.units_sold * price;
                    return in;
                }

                a) This input would succeed as it matches the expected input types.
                b) This input would fail because of incorrect type input. Because there are no checks to check validity of the stream,
                    subsequent use of the stream will also fail.
    
    e14.12 - Define an input operator for the class you used in exercise 7.40. Be sure to handle input errors.
                see. std::istream& operator>>(std::istream &is, Vehicle &v);

*/

// output operator for Sales_data
std::ostream& operator<<(std::ostream &os, const Sales_data &s) {
    os << s.bookNo << " " << s.units_Sold << " "
       << s.revenue << " " << s.avg_price();
    return os;
}
// input operator for Sales_data
std::istream& operator>>(std::istream &is, Sales_data &s) {
    double price;
    is >> s.bookNo >> s.units_Sold >> price;
    if (is) {
        s.revenue = price/s.units_Sold;
    } else {
        s = Sales_data();
    }
    return is;
}

// output operator for String
std::ostream& operator<<(std::ostream &os, const String &s) {
    for (const auto &ch : s) { 
		os << ch;
	}
	return os;
}

// output operator for Vehicle
std::ostream& operator<<(std::ostream &os, const Vehicle &v) {
    os << v.year << " " << v.manufacturer << " " << v.make << " " << v.mileage;
    return os;
}

// input operator for Vehicle
std::istream& operator>>(std::istream &is, Vehicle &v) {
    is >> v.year >> v.manufacturer >> v.make >> v.mileage;
    if (!is) {          // if input stream invalid
        v = Vehicle();  // return default-initialized object of class type
    }
    return is;
}

int main()
{


    return 0;
}