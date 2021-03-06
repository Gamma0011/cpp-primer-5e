#include <iostream>
#include <vector>
#include <string>

/*
    | ABSTRACT BASE CLASSES |

    | PURE VIRTUAL FUNCTIONS |
        Unlike ordinary virtuals, a pure virtual function does not have to be defined. We specify that a virtual function
         is a pure virtual by writing = 0 in place of a function body (i.e. right before semicolon). The = 0 may appear
         only on a declaration of a virtual function in the class body

        see. class Disc_quote : public Quote;

        We can provide a definition for a pure virtual, however, the function body must be defined outside the class. We cannot
         provide a function body inside the class for a function = 0;
            
    | CLASSES WITH PURE VIRTUALS ARE ABSTRACT BASE CLASSES |
        

*/

class Quote {
public:
    Quote() = default;
    Quote(std::string bn, double p) : bookNo(bn), price(p) { };

    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual std::ostream& debug(std::ostream &os) const {
        os << bookNo << '\t' << price << std::endl;
        return os; 
    }
protected:
    double price;
private:
    std::string bookNo;
};

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(std::string bn, double p, std::size_t q, double d) :
        Quote(bn, p), quantity(q), discount(d) { };
    std::ostream& debug(std::ostream &os) const override {
        Quote::debug(os);
        os << quantity << '\t' << discount << std::endl;
        return os;
    }
private:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc) :
        Quote(book, price), quantity(qty), discount(disc) { };
    double net_price(std::size_t) const = 0;                    // VIRTUAL FUNCTION
private:
    std::size_t quantity = 0;
    double discount = 0.0;
};


int main()
{
    return 0;
}