#include <iostream>
#include <vector>
#include <string>
#include "sales_data.h"

/*
    e14.45  - Write conversion operators to convert a Sales_data to string and double. What values should these operators return?
                see. sales_data.h

                Sales_data::operator std::string() const {
                    std::string rev = std::to_string(revenue);
                    std::string us = std::to_string(units_Sold);
                    return "ISBN: " + bookNo + " | Units Sold: " +
                        us + " | Revenue: $" + rev;
                }

    e14.46  - Explain whether defining these sales_data conversion operators is a good idea and whether or not they should be explicit.
                Defining these conversion operators is not a good idea. No clear understanding on when or how the conversion will take place.
                During the conversion to string, what exactly is returned? When converting to double, is the ISBN being returned or is the revenue?

    e14.47  - Explain the difference between these two conversion operators:
                struct Integral {
                    operator const int();
                    operator int() const;
                };

                const int() returns a constant integer, while int() const is a constant function.
            
    e14.48  - Determine whether the class you used in 7.4 should have a conversion to bool. If so, explain why, and explain whether the operator
                should be explicit. If not, why?

                see. vehicleclass.h

                It can have a conversion to bool, but I think there's no clarity as to what it's checking. Defining a bool function would be more clear
                since it would allow us to check different class objects.

    e14.49  = Regardless of whether it is a good idea to do so, define a conversion.

                Vehicle::operator bool() const {
                    return make.empty() || manufacturer.empty() || year == 0 || mileage == 0;
                }

    e14.50  - Show the possible class-type conversion sequences for the initialization of ex1 and ex2. Are they legal?

                struct LongDouble {
                    LongDouble(double = 0.0);
                    operator double();
                    operator float();
                };
                LongDouble 1dObj;
                int ex1 = 1dObj;
                float ex2 = 1dObj;

             ex1 is illegal because the call is ambiguous - could take path of operator float() or operator double()
             ex2 is legal, takes path of operator float()

    e14.51  - Show the conversion sequences (if any) needed to call each version of calc and explain why best viable function is selected.

                void calc(int);
                void calc(LongDouble);
                double dval;
                calc(dval);     // which calc?

                Answer: error: call of overloaded 'calc(double&)' is ambiguous
    
    e14.52  - Which operator+, if any, is selected for each of the addition expressions?

                struct LongDouble {
                    //member operator+ for illustration purposes; + is usually nonmember
                    LongDouble operator+(const SmallInt &); 
                };

                LongDouble operator+(LongDouble&, double);
                SmallInt si;
                LongDouble ld;
                ld = si + ld;
                ld = ld + si;       // uses LongDouble operator+(LongDouble&, double)
*/

void calc(int i) {
    std::cout << "Int : " << i <<std::endl;
}

void calc(long double ld) {
    std::cout << "Long Double : " << ld <<std::endl;
}


int main()
{

    return 0;
}