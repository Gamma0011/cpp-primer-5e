#include <iostream>
#include <vector>
#include <string>
#include "strVecClass.h"

/*
    || ASSIGNMENT OPERATORS ||
        In addition to the copy- and move-assignment operators that assign one object of the class type to another object of the same type,
         a class can define additional operators that allow other types as the right-hand operand. 
        
        As one example, in addition to the copy- and move-assignment operators, the library vector class defines a 3rd assignment operator that
         takes a braced list of elements. 

            std::vector<std::string> v; 
            v = {"a", "an", "the"};

        We can add this to our StrVec class as well. In order to be consistent with assignment for built-in type, and with copy- and move- assignment 
         operators, our new assignment will return a reference to left-hand operand.
            
            *see. StrVec &operator=(std::initializer_list<std::string>) in strVecClass.h

            StrVec& StrVec::operator=(std::initializer_list<std::string> il) {
                // alloc_n_copy allocates space and copies elements from given range.
                auto data = alloc_n_copy(il.begin(), il.end());
                free();     // destroy elements in this object and free space
                beg = data.first;   // update data members to point to the new space;
                lelem = cap = data.second;
                return *this;
            }

        As with the copy- and move-assignment operators, other overloaded assignment operators have to free existing elements to create new ones. Unlike the copy-
         and move-assignment operators, this operator does not need to check for self-assignment because parameters is an initializer_list and cannot be *this

            *NOTE* Assignment operators can be overloaded. Regardless of parameter type, assignment operators MUST be defined as member functions.

        
        || COMPOUND-ASSIGNMENT OPERATORS ||
            Compound assignment operators are not required to be members. However, we prefer to define all assignments, including compound assignments
             class. For consistency, with built-in type, these operators should return a & to their left-hand operator.

            *see. Sales_data& Sales_data::operator+=(const Sales_data &rhs);

                Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
                    units_sold += rhs.units_sold;
                    revenue += rhs.revenue;
                    return *this;
                }

            *NOTE* Assignment operators must, and ordinarily compound-assignment operators should, be defined as member. These members return a & to the left-hand operand.
*/

int main()
{


    return 0;
}
