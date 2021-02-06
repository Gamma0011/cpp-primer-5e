#include <iostream>
#include <vector>
#include <string>
#include "sales_data.h"

/*
    || ARITHMETIC AND RELATIONAL OPERATORS ||
        Normally, we define arithmetic and relational operators as nonmember functions in order to allow conversaions for either the left- or right-hand operand.
         These operators shouldn't need to change the state or either operand, so the parameters are usually const &.
        
        An arithmetic operator usually generates a new value that is the result of a computation on its two operands. The value returned is distinct and is calculated
         in a local variable. The operation returns a copy of this local and its result. When arithmetic operators are defined, so too are their compound assignment operator.
         When a class has both operators, it is usually more efficient to define the arithmetic operator to use compound assignment
         
        | EQUALITY OPERATORS |
            Normally, classes in C++ define equality operators to test if 2 objects are equivalent to eachother. They normally compare every data member and are only equal
            if all objects of class are equal.

                see.    bool operator==(const Sales_data&, const Sales_data&);
                        bool operator!=(const Sales_data&, const Sales_data&);

            - If a class has an operator to determine equality, it should define that function as operator== rahter than a named function.
                Users will expect to be able to compare objects using ==; providing == means they won't need to learn
                and remember a new name for the operator and it is easier to use the library containers and algorithms with classes that
                define == operator
            - If a class defines operator==, that operator should determine whether the given objects contain equivalent data.
            - Ordinarily, the equality operator should be transmissive, meaning that if a==b, and b==c, then a==c is true too.
            - If a class defines operator==, it should also define operator!=
            - One of the equality of inequality operators should delegate the work to the other. That is, one of these operators should
                do the real work to compare objects. 
                ex. Operator!= calls operator== in return !(lhs == rhs);

            *NOTE* Classes for which there is a logical meaning for equality normally should define operator==.

*/

bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.bookNo == rhs.bookNo &&
           lhs.units_Sold == rhs.units_Sold &&
           lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
    return !(lhs == rhs);
}

Sales_data
operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;       // copy data members from lhs into sum
    sum += rhs;                 // add rhs into sum
    return sum;
}

Sales_data&
Sales_data::operator+=(const Sales_data &rhs) {
    units_Sold = units_Sold + rhs.units_Sold;
    revenue = revenue + rhs.revenue;
    return *this;
}

int main()
{


    return 0;
}