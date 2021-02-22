#include <iostream>
#include <vector>
#include <string>

/*
    We saw that a nonexplicit constructor that can be called with one argument define an implicit conversion. Such
     constructors convert an object from one arg type to the class type. We can also define conversion FROM 
     class type. 
    
    We can define a conversion from a class type by defining a conversion operator. Converting constructors
    and conversion operators define CLASS-TYPE CONVERSIONS. These are also called USER-DEFINED CONVERSIONS

    | CONVERSION OPERATORS |
        A conversion operator is a special kind of member function that converts a value of a class type to a value of some other type.

        SYNTAX: operator type() const;

        Type represents a type. Conversion operators can be defined for any type, other than void. Additionally, conversions to
        an array or a function type are not allowed.

        Conversions to pointer types and reference types are allowed.

        Since CONVERSION OPERATORS have no explicitly stated return type and no parameters, they must be member functions. Additionally,
        there should be no change to the objects they convert, therefore declare as CONST

    | DEFINING A CLASS WITH A CONVERSION OPERATOR |
        see. class SmallInt;

        Our SmallInt class defines conversions TO and FROM its type. The constructor converts values of arithmetic type to a SmallInt.
        The conversion operator converts SmallInt objects to int.
*/

class SmallInt {
public:
    SmallInt(int i = 0): val(i) {
        if (i < 0 || i > 255) {
            throw std::out_of_range("Bad SmallInt Value");
        }
    }
    operator int() const { return val; }
private:
    std::size_t val;
};

void smallint() {
    SmallInt si;
    si = 4;         // implicitly converts 4 to SmallInt then calls SmallInt::operator=
    si + 3;         // implicitly converts si to int, followed by int addition
}

int main()
{


    return 0;
}