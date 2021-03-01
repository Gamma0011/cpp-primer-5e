#ifndef BOOK_LIMIT_H
#define BOOK_LIMIT_H

#include <iostream>
#include <string>

class Books {
public:
    Books() = default;
    Books(const std::string &bn, double p) : bookNo(bn), price(p) { };

    std::string isbn() const { return bookNo; }
    virtual double total_price(std::size_t) const;
private:
    std::string bookNo;
protected:
    double price;
};

double Books::total_price(std::size_t units) const {
    return price * units;
}

class DiscountLimit : public Books {
public:
    DiscountLimit() = default;
    DiscountLimit(const std::string &bn, double p, std::size_t qty, double d) :
        Books(bn, p), max_qty(qty), discount(d) { };

    double total_price(std::size_t) const override;
private:
    std::size_t max_qty;
    double discount;
};

double DiscountLimit::total_price(std::size_t units) const {
    if (units >= max_qty) {
        std::size_t no_discount = units - max_qty;
        return (max_qty * ((1 - discount) * price)) + (no_discount * price);
    } else {
        return units * price;
    }
}

double get_price(const Books &b, std::size_t units) {
    double ret = b.total_price(units);
    std::cout << "ISBN: " << b.isbn()
              << "\nUnits: " << units
              << "\nTotal Price: $" << ret <<std::endl;
    return ret;
}

#endif