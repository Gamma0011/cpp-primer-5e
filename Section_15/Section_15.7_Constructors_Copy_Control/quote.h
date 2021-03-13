#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>

class Quote {
public:
    Quote() = default;
    Quote(std::string bn, double p) : bookNo(bn), price(p) { };
    Quote(const Quote &rhs) { 
        std::cout << "Quote(const Quote&)" << std::endl; 
        bookNo = rhs.bookNo;
        price = rhs.price;
    }
    Quote(Quote &&rhs) { 
        std::cout << "Quote(Quote&&)" << std::endl; 
        bookNo = rhs.bookNo;
        price = rhs.price;
    }
    Quote& operator=(const Quote &rhs) { 
        std::cout << "Quote& operator=(const Quote&)" << std::endl; 
        bookNo = rhs.bookNo;
        price = rhs.price;
        return *this;
    }   
    Quote& operator=(Quote &&rhs) { 
        std::cout << "Quote& operator=(Quote &&)" << std::endl; 
        bookNo = rhs.bookNo;
        price = rhs.price;
        return *this;
    }
    virtual ~Quote() = default;

    std::string print() { return bookNo; }
    virtual std::ostream& getInfo(std::ostream &os) const {
        os << bookNo << "\t" << price;
        return os;
    }
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(std::string bn, double p, double d, std::size_t q) :
        Quote(bn, p), discount(d), quantity(q) { };
    Disc_quote(const Disc_quote &rhs) { 
        std::cout << "Disc_quote(const Disc_quote&)" << std::endl; 

    }
    Disc_quote(Disc_quote &&rhs) { 
        std::cout << "Disc_quote(Disc_quote&&)" << std::endl; 
        Quote(rhs);
        discount = rhs.discount;
        price = rhs.price;
    }
    Disc_quote& operator=(const Disc_quote &rhs) { 
        std::cout << "Disc_quote& operator=(const Disc_quote&)" << std::endl; 
        Quote::operator=(rhs);
        discount = rhs.discount;
        quantity = rhs.quantity;
        return *this;
    }
    Disc_quote& operator=(Disc_quote &&rhs) { 
        std::cout << "Disc_quote& operator=(Disc_quote&&)" << std::endl;
        Quote::operator=(rhs);
        discount = rhs.discount;
        quantity = rhs.quantity;
        return *this; 
    }
    

    virtual double net_price(std::size_t) const = 0;
    std::ostream& getInfo(std::ostream&) const override;
protected:
    double discount;
    std::size_t quantity;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(std::string bn, double p, double d, std::size_t q) :
        Disc_quote(bn, p, d, q) { };
    double net_price(std::size_t) const override;
};

class Limited_discount : public Disc_quote {
public:
    Limited_discount() = default;
    Limited_discount(std::string bn, double p, double d, std::size_t q, std::size_t mq) :
        Disc_quote(bn, p, d, q), max_qty(mq) { };
    double net_price(std::size_t) const override;
private:
    std::size_t max_qty;
};

double Bulk_quote::net_price(std::size_t n) const {
    if (quantity > n) {
        return (price * quantity) * discount;
    } else {
        return price * quantity;
    }
}

double Limited_discount::net_price(std::size_t n) const {
    if (n > max_qty) {
        std::size_t noDiscount = n - max_qty;
        return (noDiscount * price) + ((max_qty * price) * discount);
    } else {
        return (n * price) * discount;
    }
}

std::ostream& Disc_quote::getInfo(std::ostream &os) const {
    Quote::getInfo(os);
    os << "\t" << discount << "\t" << quantity << std::endl;
    return os;
}


#endif