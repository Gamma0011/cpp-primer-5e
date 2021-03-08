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
        A class containing (or inheriting without overriding) a pure virtual function is an ABSTRACT BASE CLASS, which defines an
         interface for subsequent classes to override. We cannot directly create objects of a type that is an abstract base class.

         ex. class Disc_quote : public Quote defines double net_price(size_t) = 0, which means we cannot define an object of 
          class type Disc_quote.

            Disc_quote discounted;      // error: cannot define a Disc_quote object
            Bulk_quote bulk;            // ok: Bulk_quote has no pure virtual functions.
        
        Classes that inherit from Disc_quote must define net_price or those classes will be abstract as well.
    
        *NOTE* We may not create object of a type that is an abstract base class.

    | A DERIVED CLASS CONSTRUCTOR INITIALIZES ITS DIRECT BASE CLASS ONLY |
        *note* Changing inheritance of Bulk_quote from Quote to Disc_quote

        Adding Disc_quote to the Quote heirarchy (Quote <- Disc_quote <- Bulk_quote) is an example of refactoring, which involved redesigning
         a class heirachy to move operations and/pr data from one class to another.
         
        Refactoring is common in object-oriented applications. It is noteworth that even though we changes the inheritance heirarchy, code
         that uses Bulk_quote or Quote would not need to change. However, when classes are refactored, we must recompile code that uses those classes.

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

/* ORIGINAL
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
*/

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc) :
        Quote(book, price), quantity(qty), discount(disc) { };
    virtual double net_price(std::size_t) const = 0;                    // VIRTUAL FUNCTION
private:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double price, std::size_t qty, double disc) :
        Disc_quote(book, price, qty, disc) { };
    
    // overrides the base version to implement the bulk purchase discount policy
    double net_price(std::size_t) const override;
};

int main()
{
    return 0;
}