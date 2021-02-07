#include <iostream>
#include <vector>
#include <string>
#include "sales_data.h"
#include "strClass.h"
#include "strBlobClass.h"
#include "strVecClass.h"
#include "strBlobPtrClass.h"
#include "vehicleClass.h"


/*
    e14.13  - Which other arithmetic operators, if any, do you think Sales_data should support? Define.
                I think adding a subtraction constructor and subtraction-assignment operator would be important for modifying total inventory and bookkeeping
                - Sales_data operator-(const Sales_data&, const Sales_data&);
                - Sales_data& Sales_data::operator-=(const Sales_data&);

    e14.14  - Why do you think it is more efficient to define operator+ to call += rather than the other way around?
                Because when + is defined, so too should +=
                Additionally, + is dealing with objects of class type, where as += os dealing with objects of built-in type,
                therefore arithmetic operators are already built into the objects.
    
    e14.15  - Should the class you chose for 7.40 define any arithmetic operators?
                In its current form, there is no need to define arithmetic operators. However, if we expand the program to track inventory,
                 then there would be a need to define operators
    e14.16  - Define equality and inequality operators for your StrBlob and StrBlobPtr, StrVec, and String classes

    e14.17  - Should the class you chose for 7.30 define the equality operators? Define

    e14.18  - Define relational operators for your StrBlob, StrBlobPtr, StrVec and String classes

    e14.19  - Should the class you chose for exercise 7 implement relational operators? Why or why not?
                Relational operators could be used, but based upon the parameters of the class, there's no clear logic for how best to compare.
                As a result, it would be best to leave the class without relational operators. 

*/

Sales_data
operator-(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum -= rhs;
    return sum;
}

Sales_data&
Sales_data::operator-=(const Sales_data &rhs) {
    units_Sold = units_Sold - rhs.units_Sold;
    revenue = revenue - rhs.revenue;
    return *this;
}

// StrBlob equality/inequality
bool operator==(const StrBlob &lhs, const StrBlob &rhs) { return lhs.data == rhs.data; }
bool operator!=(const StrBlob &lhs, const StrBlob &rhs) { return !(lhs==rhs); }
// StrBlob relational operators
bool operator<(const StrBlob &lhs, const StrBlob &rhs) { return lhs.data->size() < rhs.data->size(); }
bool operator>(const StrBlob &lhs, const StrBlob &rhs) { return lhs.data->size() > rhs.data->size(); }

// StrBlobPtr equality/inequality
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) { return lhs.deref() == rhs.deref(); }
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) { return !(lhs == rhs); }
// StrBlobPtr relational operators
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) { return lhs.deref().size() < rhs.deref().size(); }
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) { return lhs.deref().size() > rhs.deref().size(); }

// StrVec equality/inequality
bool operator==(const StrVec &lhs, const StrVec &rhs) {
    for (auto l = lhs.begin() ; l != lhs.end() ; ) {
        for (auto r = rhs.begin() ; r != rhs.end() ; ) {
            if ( l == r) {
                ++l; ++r;
            } else {
                return false;
            }
        }
    }
    return true;
}
bool operator!=(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs == rhs);
}
// StrVec relational operators
bool operator<(const StrVec &lhs, const StrVec &rhs) { return (lhs.cap - lhs.beg) < (rhs.cap - rhs.beg); }
bool operator>(const StrVec &lhs, const StrVec &rhs) { return (lhs.cap - lhs.beg) > (rhs.cap - rhs.beg); }


// String equality/inequality
bool operator==(const String &lhs, const String &rhs) {
    for (auto &l : lhs) {
        for (auto &r : rhs) {
            if (l != r) {
                return false;
            }
        }
    }
    return true;
}
bool operator!=(const String &lhs, const String &rhs) { return !(lhs == rhs); }
// String relational operators
bool operator<(const String &lhs, const String &rhs) { return lhs.size() < rhs.size(); }
bool operator>(const String &lhs, const String &rhs) { return lhs.size() > rhs.size(); }


// Vehicle class Equality Operators
bool operator==(const Vehicle &lhs, const Vehicle &rhs) {
    return lhs.make == rhs.make &&
           lhs.manufacturer == rhs.manufacturer &&
           lhs.year == rhs.year &&
           lhs.mileage == lhs.mileage;
}

bool operator!=(const Vehicle &lhs, const Vehicle &rhs) {
    return !(lhs == rhs);
}

int main()
{


    return 0;
}
