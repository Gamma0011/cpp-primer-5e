#include <iostream>
#include <vector>
#include <string>

/*
    *BEST PRACTICES*
        - Don't define mutually converting classes. If class Foo has constructor that takes object of Class Bar, don't give Bar conversion to type Foo
        - Avoid conversions to built-in arithmetic types.
            - Do not define overloaded versions of operators that take arithmetic types. 
            - Do not define a conversion to more than one arithmetic type. Let the standard conversions provide conversions to other arithmetic types.
        - With the exception of an explicit conversion to bool, avoid defining conversion functions and limit nonexplicit constructors to those that are "obviously right"


    | AVOIDING AMBIGUOUS CONVERSIONS |
        If a class has one or more conversion, it's imporatnt to ensure that there is only one way to convert
         from the class type to target type.
        
        Ways multiple conversions can happen:
        1) Class A defines converting constructor that takes object of Class B. B itself defines conversion operator to A.
        2) Generate multiple conversion paths to/from types that are related by conversions. 

        *NOTE* Ordinarily, it is a bad idea to define classes with mutual conversion or to define conversions to or from 2 arithmetic types.

    | ARGUMENT MATCHING AND MUTUAL CONVERSIONS |

        - Example 1 - Class A constructor accepts Class B object A(const B&). Class B object defines a conversion to class A object (operator A())
        - Example 2 - Class A has 2 constructors and two conversions. A(int), A(double); operator int() const; operator double() const;
                        Providing a convertible arithmetic type (long double) throws error. No clear path on which to use. Call ambiguous.

    *NOTE* When two user-defined conversions are used, the rank of standard conversion is used to select the best match.

    | OVERLOADED FUNCTIONS AND CONVERTING CONSTRUCTORS |
        Choosing among multiple conversions is further complicated when we call overloaded functions. If two or more provide a match,
         then conversions are equally good. 

         example:
            struct C { C(int); };
            struct D { D(int); };

            void manip(const C&);
            void manip(const D&);

            manip(10);      // error! ambiguous. C or D?
            manip(C(10));   // clear. calls manip(const C&)
    
    *NOTE* Needing to use a constructor or a cast to convert an arg in call to overloaded function is a sign of bad design.


    | OVERLOADED FUNCTIONS AND USER-DEFINED CONVERSION |
        
        example:
            struct C { C(int); };
            struct E { E(double); };

            void manip2(const C&);
            void manip2(const E&);

            manip2(10);         // error: could be either int or int->double implicit conversion. ambiguous 

    In a class to an overloaded function, the rank of an additional standard conversion (if any) matters only if the viable functions
    require the same user-defined conversion. If different user-defined conversions are needed, the call is ambiguous

    | FUNCTION MATCHING AND OVERLOADED OPERATORS |
        Overloaded operators ARE overloaded functions. Normal function matching is used to determine which operator, built-in or user-defined,
         should apply.

    *NOTE* The set of candidate functions for an operator used in an expression can contain both nonmember and member functions.


*/

class SmallInt {
    friend  SmallInt operator+(const SmallInt&, const SmallInt&);
public:
    SmallInt(int i = 0) : val(i) { };       // conversion from int
    operator int() const { return val; }    // conversion to int
private:
    std::size_t val;
};

SmallInt operator+(const SmallInt &a, const SmallInt &b) {
    SmallInt c;
    c.val = a.val + b.val;
    return c;
}


int main()
{
    SmallInt s1(1), s2(2);
    SmallInt s3 = s1 + s2;
    //int i = s3 + 0;         // error: ambiguous overload for 'operator+'

    return 0;
}