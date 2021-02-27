#include <iostream>
#include <string>

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
    Bulk_quote(const std::string &b, double p) : Quote(b, p) { };

    double net_price(std::size_t n) const override {
        return n * price;
    }
};

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
    Bulk_quote book2("2-222-2222-2", 49.99);

    print_total(std::cout, book1, 10);
    std::cout <<std::endl;
    print_total(std::cout, book2, 10);


    return 0;
}