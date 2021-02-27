#ifndef QUOTE_CLASS_H
#define QUOTE_CLASS_H

#include <iostream>
#include <string>

/*
    New parts of this class are use of Virtual on the net_price function and destructor, and the PROTECTED access specifier.
    *NOTE*  Base classes used as the root of inheritance heirarchy almost ALWAYS define a virtual destructor.
    *       Virtual destructors are needed, even if they do no work.

*/

class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) :
                bookNo(book), price(sales_price) { };


    // FUNCTIONS
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual ~Quote() = default;         // dynamic binding for destructor

private:
    std::string bookNo;
protected:
    double price = 0.0;                 // normal undiscounted price.
};


#endif