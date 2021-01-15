#include <iostream>
#include <vector>
#include <string>
#include <memory>

/*
    | THE COPY-ASSIGNMENT OPERATOR |
        A class also controls how objects of its class are assigned,
        
        Sales_data trans, accum;
        trans = accum;              // uses the Sales_data copy-assignment operator.

        As with the copy constructor, the compiler synthesizes a copy-assignment operator if the class does not define its own.


        | OVERLOADED ASSIGNMENT |
            Overloaded operators are functions that have the name operator followed by the symbol for the operator being defined.
            Hence, the assignment operator is a function named operator= This function has a return type and parameter list.

            The parameters in an overloaded operator represent the operands of the operator. Some operators, assignment among them,
            must be defined as member functions. When an operator is a member, the left-hand operand is bound to the implicit this parameter.
            The right-hand operand is a binary operator, passed as an explicit parameter

            class Foo {
            public:
                Foo& operator=(const Foo&);     // assignment operator
            };

        **NOTE** Assignment operators should return a reference to their left-hand operand.

        | SYNTHESIZED COPY-ASSIGNMENT OPERATOR |
            If there is none defined, the compiler generates a synthesized copy-assignment operator for a class. For some classes, 
             the synthesized copy-assignment operator disallows assignment.
            
            Otherwise, it assigns each nonstatic member of the right-hand object to the corresponding member of the left-hand object
             using the copy-assignment operator for the type of that member. Array members are assigned by assigning each element of the array.
             The synthesized copy-assignment operator returns a reference to its left-hand object.

             Sales_data& Sales_data::operator=(const Sales_data &rhs) {
                 bookNo = rhs.bookNo;               // calls the string::operator=
                 units_sold = rhs.units_sold;       // uses built-in int assignment
                 revenue = rhs.revenue;             // uses the built-in double assignment
                 return *this;                      // returns a reference to this object
             }

*/

int main()
{


    return 0;
}