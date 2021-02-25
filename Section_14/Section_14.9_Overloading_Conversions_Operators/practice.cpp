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

        Although the compiler will apply only one user-defined conversion at a time, an implicit user-defined conversion can be preceded,
         or followed by a standard (built-in) conversion. As a result, we can pass any arithmetic type to the SmallInt constructor

            SmallInt si = 3.14;     // calls SmallInt(int) constructor
            si + 3.14;              // int is converted to double via implicit conversion

        Because conversion operators are implicitly applied, there is no way to pass args to these functions. Conversion operators
         may not be defined to take parameters. Each conversion function does not have a specified return type, but must return
         a value of its corresponding type

            operator int(SmallInt&);            // error: nonmember

            int operator int() const;           // error: return type
            operator int(int = 0) const;        // error: parameter int
            operator int*() const { return 42; }// error 42 not a pointer

        *NOTE* Avoid overuse of conversion functions.

        In practice, classes rarely provide conversion operators because users can be surprised by a conversion from one type to another.
         EXCEPTION: it is not uncommon for classes to define conversions to bool.

        
        | explicit CONVERSION OPERATORS |
            The new standard introduced explicit conversion operators:

                class SmallInt {
                public:
                    // the compiler won't automatically apply this conversion
                    explicit operator int() const { return val; }
                };

        As with an explicit constructor, the compiler won't generally use an explicit conversion operator for implicit conversions.
            
            SmallInt si = 3;        // SmallInt constructor is not explicit, conversion from int to size_t happens
            si + 3;                 // error: implicit conversion required. operator int() explicit
            static_cast<int>(si)+3; // ok: explicitly request conversion

        If the conversion operator is explicit, we can still convert, but we must do so EXPLICITLY with a CAST
            EXCEPTION: compiler applies explicit conversion to an expression as a condition.
                    Converts expression used as:
                    - Condition of if, while or do statement
                    - Condition expression in a for statement header
                    - Operand to ! || && operators
                    - Condition expression in a conditional ? : operator

        | CONVERSION TO BOOL |
            *BEST PRACTICE* Conversion to bool is usually intended for use in conditions. As a result operator bool() should be explicit
            

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