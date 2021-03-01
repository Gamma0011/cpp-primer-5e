#include <iostream>
#include <vector>
#include <string>
#include "quote.h"

/*
    | OVERVIEW OF OOP |
        Key ideas: Data Abstraction, Inheritance, and Dynamic Binding.
            Data Abstraction - Define classes that separate interface from implementation.
            Inheritance - Define classes that model relationships among similar types.
            Dynamic Binding - Use objects of these types while ignoring details of how they differ.
        
    | INHERITANCE |
        Classes related by inheritance forma  heirarchy. Normally, there is a BASE CLASS at the root,
         from which other classes inherit, directly or indirectly.
        
        Inheriting classes are known as DERIVED CLASSES. The base class defines those members that are
         common to the types in the heirarchy. Each derived class defines those members specific to the derived class itself.
        
        see. quote.h, which outlines base class (quote) && derived class (Bulk_quote)

        In C++, a base class distinguishes functions that are type dependent from those its expects its derived classes to inherit w/o change.
        *The base class defines functions VIRTUAL when it expects its derived classes to define them for themselves.
    
    | DYNAMIC BINDING |
        Via DYNAMIC BINDING, we can use the same code to process objects of either type Quote or Bulk_quote interchangeably. 

            see. double print_total(std::ostream &os, const Quote &item, std::size_t n);
        
        - Because item paramter is a reference to Quote, we can call this function on either an object of Quote or Bulk_quote. 
        - Because net_price is a virtual function, and because print_total calls net_price though reference,
            the version of net_price run depends on type of object passed to print_total.

                print_total(std::cout, basic, 20);  // calls Quote version of net_price
                print_total(std::cout, bulk, 20);   // calls Bulk_quote version of net_price
        
        Because the decision as to which version of net_price to run depends on the argument type, the decision cannot be made until run time.
         Therefore, dynamic binding is sometimes known as RUN-TIME BINDING.
        
    *NOTE* In C++, dynamic binding happens when a virtual function is called through & or * to a base class.
*/

double print_total(std::ostream &os, const Quote &item, std::size_t n) {
    // depending on the type of object bound to the item parameter
    // call either Quote::net_price or Bulk_quote::net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " | # Sold: " 
       << n << " | Total Due: $" << ret <<std::endl;
    
    return ret;
}


int main()
{


    return 0;
}
