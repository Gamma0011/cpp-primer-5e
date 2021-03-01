#ifndef QUOTE_CLASS
#define QUOTE_CLASS

#include <iostream>
#include <string>

// quote is the base class, representing undiscounted books.
// another class, Bulk_quote will be a derived class representing books solid with a quantity discount
// two member functions - isbn() defined in base, net_price(size_t) defined in both Quote and Bulk_Quote
// *The base class defines functions VIRTUAL when it expects its derived classes to define them for themselves.


// BASE CLASS
class Quote {
public:
    std::string isbn() const;
    virtual double net_price(std::size_t n) const;
};

/*  A derived class must specify the class(es) from which it intends to inherit.
    This is done in a class derivation list, a colon followed by comma-separated list of base classes with an access specifier (public, private).
    Because Bulk_quote uses public in its derivation list, we can use objects of type Bulk_quote as if they were Quote objects

    A derived class must include in its own class body a declaration of all the virtual functions it intends to define for itself. 
    A derived class may include VIRTUAL on those functions, but is not required to do so.

    *In C++11, a derived class can explicitly note that it intends to OVERRIDE a virtual it inherits by specifying overide after parameter list.
        ex. double net_price(std::size_t n) const override;
*/

// DERIVED CLASS
class Bulk_Quote : public Quote {
public:
    double net_price(std::size_t n) const override;
};


#endif