#include <iostream>
#include <string>
#include "quote.h"

/*
    e15.24  - What kind of classes need a virtual destructor? What operations must a virtual destructor perform?
                A virtual destructor is needed for any base classes that have derived subclasses. This is important because in the case that
                static and dynamic types differ, the lack of a virtual destructor could mean that not all types are destroyed, leading to 
                undefined behavior.

                A virtual destructor must be defined so that dervied classes also inherit a destructor and correctly delete their object
                 when needed.
    
    e15.25  - Why did we define a default constructor for Disc_Quote? What effect, if any, would removing constructor have on behavior of
                Bulk_quote?

                Without declaring a default constructor, you'd be unable to create just an object of type without arguments. 
                    ex. Bulk_quote bq; would not work.

                Removing the default constructor would require you always provide arguments to initialize members of the object.
                        Disc_quote(std::string bn, double p, double d, std::size_t q) : Quote(bn, p), discount(d), quantity(q) { };
                         is the only option to actually create an object of type Disc_Quote

    e15.26  - Define Quote and Bulk_quote copy-control members to do the same job as the synthesized versions. Give them print statements.
                    see. quote.h        

    e15.27  - Redefine your Bulk_quote class to inherit its constructors.
                    see. quote.h        Default constructor now:    using Disc_quote::Disc_quote;

*/

int main()
{
    Bulk_quote bq1("Book", 9.99, .25, 10);
    std::cout << std::endl;
    Bulk_quote bq2 = bq1;
    std::cout << std::endl;
    Bulk_quote bq3(bq2);
    std::cout << std::endl;
    Bulk_quote bq4(std::move(bq3));
    std::cout << std::endl;

    return 0;
}