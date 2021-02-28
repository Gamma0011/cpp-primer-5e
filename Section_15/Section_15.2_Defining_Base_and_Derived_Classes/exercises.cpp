#include <iostream>
#include <string>
#include "Book_Limit.h"

/*
    e15.1   - What is a virtual member?
                A virtual member is declared in a Base Class with the intention that Derived Classes with inherit
                 this member and override it.
    
    e15.2   - How does the protected access specifier differ from private?
                Protected allows derived classes to access members within the Protected Access Specifier. To other non-members,
                 those objects declared protected are otherwise treated as private. Private defines that only Base Class or 
                 classes defined as "Friend" will be able to access those members. Derived classes will not inherit these members.
    
    e15.3   - Define your own version of Quote and print_total function.
                see class Quote;

    e15.4   - Which of the following declarations are incorrect?

                class Base;
            
                a) class Derived : public Derived {};       // error impossible to derive class from itself.
                b) class Derived : private Base {};         // okay: inherits from Base private members.
                c) class Derived : public Base {};          // okay: inherits from Base public members.
    
    e15.5   - Define your own version of Bulk_quote class.
                see. class Bulk_quote;

    e15.6   - Test your print_total function by passing both Quote and Bulk_quote object to that function.

    e15.7   - Define a class that implements a limited discounts strategy, which applied a discount to books
                purchased up to a given limit. If copies exceed limit, normal price applied to those purchase beyond limit.

                see. Book_Limit.h

*/

class Quote {
public:
    Quote() = default;
    Quote(std::string bn, double p) : bookNo(bn), price(p) { };

    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
protected:
    double price;
private:
    std::string bookNo;
};

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &b, double p, std::size_t qty, double d) : 
        Quote(b, p), min_qty(qty), discount(d) { };

    double net_price(std::size_t) const override;
private:
    std::size_t min_qty;
    double discount;
};

double Bulk_quote::net_price(std::size_t n) const {
    if (n >= min_qty) {
        return price * (1 - discount) * n;
    } else {
        return price * n;
    }
}


double print_total(std::ostream &os, const Quote &q, std::size_t n) {
    double ret = q.net_price(n);
    os << "ISBN: " << q.isbn() << 
          "\nNumber of Books: " << n <<
          "\nTotal Price: $" << ret <<std::endl; 
    return ret;
}

int main()
{
    Quote book1("1-111-1111-1", 10.23);
    Bulk_quote book2("2-222-2222-2", 49.99, 10, .05);

    //print_total(std::cout, book1, 10);
    //std::cout <<std::endl;
    //print_total(std::cout, book2, 10);


    Books test1("3-33-33-3", 10);
    get_price(test1, 10);

    DiscountLimit test2("4-44-44-4", 5, 10, 0.05);
    get_price(test2, 11);


    return 0;
}