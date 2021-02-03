#include <iostream>
#include <vector>
#include <string>
#include "sales_data.h"

/*
    e14.1   - In what ways does an overloaded operator differ from a built-in operator? In what ways are they the same?
                Overloaded operators are defined to define specifically how operators deal with objects of class type. 
                They are quite similar to built-in types because the overloaded operators should use the operators in a way
                that in unambiguous and similar to what is expected when used for object of built-in type.

    e14.2   - Write declarations for the overloaded input, output, addition, and compound-assignment operators for Sales_data

                    std::istream& operator>>(std::istream &is, Sales_data &rhs);
                    std::ostream& operator<<(std::ostream &os, const Sales_data &rhs);
                    Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
                    Sales_data operator+=(Sales_data &lhs, const Sales_data &rhs);

    e14.3   - Both string and vector define overloaded == that can be used to compare objects of those types. Assuming svec1 and svec2
                are vectors that hold string, identify which version of == is applied

                    (a) "cobble" == "stone";            // error: cannot compare string literals. Must use std::strcmp();
                    (b) svec1[10] == svec2[0];          // string overloaded comparison
                    (c) svec1 == svec2;                 // vector overloaded comparison
                    (d) svec[0] == "stone";             // string overloaded comparison

    e14.4   - Explain how to decide whether the following should be class members:
                    (a) %       Arithmetic. Nonmember.
                    (b) %=      Compound-assignment. Member.
                    (c) ++      Changes state of object. Member.
                    (d) ->      Member access arrow. Member.
                    (e) <<      Output operator. Nonmember.
                    (f) &&      SHOULD NOT BE OVERLOADED
                    (g) ==      Tests Equality. Nonmember
                    (h) ()      Call operator. Member.

    e14.5   - In exercise 7.40, you wrote a sketch of one of the following classses, decide what, if any overloaded operators your class should provide.
                    It might be worth including the << and >> operators

                        std::istream& operator>>(std::istream& is, Vehicle &v);             // replaces read
                        std::ostream& operator<<(std::ostream& os, const Vehicle &v);       // replaces print

*/

// e14.2
std::istream& operator>>(std::istream &is, Sales_data &rhs);
std::ostream& operator<<(std::ostream &os, const Sales_data &rhs);
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
Sales_data operator+=(Sales_data &lhs, const Sales_data &rhs);


// e14.5
class Vehicle {
public:
    /*
    friend ostream &print(ostream &os, const Vehicle &v);
    Vehicle() = default;
    Vehicle(unsigned y, std::string mcfr, std::string mk, double mi): year(y), manufacturer(mcfr), make(mk), mileage(mi) { };
    Vehicle(istream &is) { is >> year >> manufacturer >> make >> mileage; }         // is reads & writes into year, manufacturer, make, mileage
    */
    // e742 - rewritten using delegating constructors
    friend std::ostream &print(std::ostream &os, const Vehicle &v);

    Vehicle(unsigned y, std::string mcfr, std::string mk, double mi): year(y), manufacturer(mcfr), make(mk), mileage(mi) { }        // delegated constructor

    Vehicle(): Vehicle(0, "", "", 0) { }            // default constructor
    Vehicle(unsigned y, std::string mcfr, std::string mk): Vehicle(y, mcfr, mk, 0) { }              // only know year, manufacturer, and make
    Vehicle(std::istream &is): Vehicle() { read(is, *this); }                                            // allow cin to write arguments to object

    std::istream &read(std::istream &is, Vehicle &car) { return is; }

private:
    unsigned year;
    std::string manufacturer;
    std::string make;
    double mileage;
};

std::istream& operator>>(std::istream& is, Vehicle &v);
std::ostream& operator<<(std::ostream& os, const Vehicle &v);

int main()
{



    return 0;
}