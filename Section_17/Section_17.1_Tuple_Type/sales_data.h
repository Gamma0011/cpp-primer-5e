#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data{
    friend std::istream& operator>>(std::istream&, Sales_data&);
    friend std::ostream& operator<<(std::ostream&, Sales_data&);
    friend bool operator==(const Sales_data&, const Sales_data&);
    friend bool operator!=(const Sales_data&, const Sales_data&);
    friend class std::hash<Sales_data>;
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

namespace std{  
    template<>                  // defining a specialization with
    struct hash<Sales_data>{    // the template parameter of Sales_data
        // type used to hash an unordered container must define these types
        typedef std::size_t result_type;
        typedef Sales_data argument_type;      // by default, this needs ==
        
        std::size_t operator()(const Sales_data& s) const;
    };

    std::size_t
    hash<Sales_data>::operator()(const Sales_data& s) const {
        return  hash<std::string>()(s.bookNo) ^
                hash<unsigned>()(s.units_Sold) ^
                hash<double>()(s.revenue);
    }

}   // close std namespace; note no semicolon


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


/*************** NON-MEMBER FUNCTIONS ***************/
std::ostream&
operator<<(std::ostream &os, const Sales_data &s) {
    os << s.bookNo << " " << s.revenue << " " << s.units_Sold;
    return os;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
    return  lhs.bookNo == rhs.bookNo &&
            lhs.units_Sold == rhs.units_Sold &&
            lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
    return !(lhs == rhs);
}



#endif