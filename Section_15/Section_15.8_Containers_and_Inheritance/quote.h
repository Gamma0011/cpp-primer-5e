#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>

class Quote {
public:
    Quote() = default;
    Quote(std::string bn, double p) : bookNo(bn), price(p) { std::cout << "Quote constructor." << std::endl; }

    Quote(const Quote &rhs) : bookNo(rhs.bookNo), price(rhs.price)
        { std::cout << "Quote(const Quote&)" << std::endl; }
    Quote(Quote &&rhs) noexcept : bookNo(rhs.bookNo), price(rhs.price)
        { std::cout << "Quote(Quote&&)" << std::endl; }
    Quote& operator=(const Quote &rhs) { 
        std::cout << "Quote& operator=(const Quote&)" << std::endl; 
        bookNo = rhs.bookNo;
        price = rhs.price;
        return *this;
    }   
    Quote& operator=(Quote &&rhs) noexcept { 
        std::cout << "Quote& operator=(Quote &&)" << std::endl; 
        bookNo = rhs.bookNo;
        price = rhs.price;
        return *this;
    }
    virtual ~Quote() {std::cout << "~Quote()" << std::endl; };
 
    virtual Quote* clone() const & { return new Quote(*this); }         // virtual function to return a dynamically allocated copy of itself
    virtual Quote* clone() && { return new Quote(std::move(*this)); }   // these members use reference qualifiers

    std::string print() { return bookNo; }
    virtual std::ostream& getInfo(std::ostream &os) const {
        os << bookNo << "\t $" << price;
        return os;
    }

    virtual double net_price(std::size_t n) const { return price * n; }
    std::string isbn() { return bookNo; }
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(std::string bn, double p, double d, std::size_t q) :
        Quote(bn, p), discount(d), quantity(q) { std::cout << "Disc_quote constructor." << std::endl; }

    Disc_quote(const Disc_quote &rhs) : Quote(rhs),
        quantity(rhs.quantity), discount(rhs.discount) 
        { std::cout << "Disc_quote(const Disc_quote &rhs)" <<std::endl; }
    Disc_quote(Disc_quote &&rhs) noexcept : Quote(std::move(rhs)), 
        quantity(rhs.quantity), discount(rhs.discount)
        { std::cout << "Disc_quote(Disc_quote&&)" << std::endl; }

    Disc_quote& operator=(const Disc_quote &rhs) { 
        std::cout << "Disc_quote& operator=(const Disc_quote&)" << std::endl; 
        Quote::operator=(rhs);
        discount = rhs.discount;
        quantity = rhs.quantity;
        return *this;
    }
    Disc_quote& operator=(Disc_quote &&rhs) noexcept { 
        std::cout << "Disc_quote& operator=(Disc_quote&&)" << std::endl;
        Quote::operator=(std::move(rhs));
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

/*
class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(std::string bn, double p, double d, std::size_t q) :
        Disc_quote(bn, p, d, q) { };
    Bulk_quote(const Bulk_quote &rhs) : Disc_quote(rhs)
        { std::cout << "Bulk_quote(const Bulk_quote &rhs)" <<std::endl; }
    Bulk_quote(Bulk_quote &&rhs) noexcept :
        Disc_quote(std::move(rhs)) 
        { std::cout << "Bulk_quote(Bulk_quote &&rhs)" <<std::endl; }
    Bulk_quote& operator=(const Bulk_quote &rhs) {
        Bulk_quote::operator=(rhs);
        std::cout << "Bulk_quote& operator=(const Bulk_quote &rhs)" << std::endl; 
        return *this;
    }

    Bulk_quote& operator=(Bulk_quote &&rhs) noexcept {
        Disc_quote::operator=(std::move(rhs));
        std::cout << "Bulk_quote& operator=(Bulk_quote &&rhs)" << std::endl;
        return *this;
    }

    double net_price(std::size_t) const override;
};
*/

class Bulk_quote : public Disc_quote {
public:
    using Disc_quote::Disc_quote;
    Bulk_quote(const Bulk_quote &rhs) : Disc_quote(rhs) 
        { std::cout << "Bulk_quote(const Bulk_quote &rhs)" << std::endl; }
    Bulk_quote(Bulk_quote &&rhs) noexcept : Disc_quote(std::move(rhs))
        { std::cout << "Bulk_quote(Bulk_quote &&rhs)" << std::endl; }
    Bulk_quote& operator=(const Bulk_quote &rhs) {
        Disc_quote::operator=(rhs);
        std::cout << "Bulk_quote& operator=(const Bulk_quote &rhs)" << std::endl;
        return *this;
    }
    Bulk_quote& operator=(Bulk_quote &&rhs) noexcept {
        Disc_quote::operator=(std::move(rhs));
        std::cout << "Bulk_quote& operator=(Bulk_quote &&rhs)" << std::endl;
        return *this;
    }

    double net_price(std::size_t) const override;

    Bulk_quote* clone() const & { return new Bulk_quote(*this); }
    Bulk_quote* clone() && { return new Bulk_quote(std::move(*this)); }
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
        return (price * quantity) * (1 - discount);
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

double print_total(std::ostream &os, const Quote &q, std::size_t n) {
    double ret = q.net_price(n);
    q.getInfo(os);
    std::cout << std::endl;
    return ret;
}


#endif