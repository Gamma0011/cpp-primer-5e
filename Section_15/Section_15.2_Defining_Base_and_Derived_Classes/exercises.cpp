#include <iostream>
#include <string>
#include "Book_Limit.h"

// Good explaining on the need for inheritance in OOP
// https://www.geeksforgeeks.org/inheritance-in-c/

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

    e15.8   - Define static type and dynamic type.
                Static type is always known at compile time (return type or declared). Dynamic types aren't known until run time
                 and is variable.

                Functions or expressions with the ability to use an object of base or derived type is dynamic because the object that
                 will be used is unknown until run time.

    e15.9   - When is it possible for an expression's static type to differ from its dynamic type. Give 3 examples.
                Base Class - Base ; Derived Class - Derived

                When an expression is a reference or a pointer.

                1) Pass expression to function via & or *
                    Derived d;
                    void foo(Base &);
                    foo(&d);
                
                2) Point a pointer of base class at a derived object
                    Derived d;
                    Base *b = d;
                
                3) Reference a derived class type using base class type &
                    Derived d;
                    Base &d = d;

    e15.10  - Recalling the discussion from pg. 311, explain how the program on page 317 that passed an ifstream 
                to the Sales_data read function works.

            ifstream is a derived class of istream and therefore objects of type ifstream are accepted where class istream is expected.
            Read then uses the members of istream to read the input from the original ifstream object and return type istream.

            ************************************************          
                                BASE        DERIVED
            ios_base <- ios <- istream  <- iostream
                                        <- ifstream
                                        <- istringstream

            https://www.cplusplus.com/reference/istream/istream/

            ************************************************ 

            std::istream& read(std::istream&, Sales_data&;

            ifstream input(argv[1]);
            ofstream output(argv[2]);
            Sales_data total;
            if(read(input, total)) {
                Sales_data transfer;
                while(read(input, transfer)) {
                    if (total.isbn() == trans.isbn()) {
                        total.combine(trans);
                    } else {
                        print(output, total) <<std::endl;
                        total = trans
                    }
                }
                print(output, total) <<std::endl;
            } else {
                std::cerr << "No data" <<std::endl;
            }

    e15.11  - Add a virtual debug function to your Quote class heirarchy that displays data members of each respective class.

                Base:       virtual std::ostream& debug(std::ostream&) const;
                Derived:    std::ostream& debug(std::ostream&) const override;

    e15.12  - Is it ever useful to declare a member function as both override and final?
                This could be useful if you plan on not allowing additional derived classes to override the declared virtual function from base class.
                This prevents any further modifications or changes in subsequent derived class types.
    
    e15.13  - Given the following classes, explain each print function. If there is a problem with this code, how would you fix it?
                see. class Base;

                - virtual void print(std::ostream &os) const { os << basename; } | of base class type. prints member basename to ostream
                - void print(std::ostream &os) const { print(os) ; os << " " << i; } | of derived class type. calls base print() then does additional work.

                The print() in derived class is a mistake. We must call an override or else there will be an infinite recursion.

                void print(std::ostream &os) const override {
                    base::print(os);
                    os << " " << i;
                }

    e15.14  - Given the classes from the previous exerise and the following objects, determine which function is called at run time:
                base bobj;      base *bp1 = &bobj;      base &br1 = bobj;
                derived dobj;   base *bp2 = &dobj;      base &br2 = dobj;

                a) bobj.print();    called at compile. Base class static type.
                b) dobj.print();    called at compile. Type is known.
                c) bp1->name();     called at compile. Name not virtual
                d) bp2->name();     called at compile. Name not virtual
                e) br1.print();     called at run.
                d) br2.print();     called at run.

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
    Bulk_quote(const std::string &b, double p, std::size_t qty, double d) : 
        Quote(b, p), min_qty(qty), discount(d) { };

    double net_price(std::size_t) const override;
    std::ostream& debug(std::ostream &os) const override;

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

std::ostream& Bulk_quote::debug(std::ostream &os) const {
    Quote::debug(os);
    os << min_qty << '\t' << discount << std::endl;
    return os;
}


double print_total(std::ostream &os, const Quote &q, std::size_t n) {
    double ret = q.net_price(n);
    os << "ISBN: " << q.isbn() << 
          "\nNumber of Books: " << n <<
          "\nTotal Price: $" << ret <<std::endl; 
    return ret;
}

class base {
public:
    std::string name() { return basename; }
    virtual void print(std::ostream &os) const { os << basename; }
private:
    std::string basename;
};

class derived : public base {
public:
    // void print(std::ostream &os) { print(os); os << " " << i; } // wrong
    void print(std::ostream &os) const override{
        base::print(os);
        os << " " << i;
    }
private:
    int i;
};


int main()
{
    Quote book1("1-111-1111-1", 10.23);
    Bulk_quote book2("2-222-2222-2", 49.99, 10, .05);

    book1.debug(std::cout);
    book2.debug(std::cout);

    //print_total(std::cout, book1, 10);
    //std::cout <<std::endl;
    //print_total(std::cout, book2, 10);


    Books test1("3-33-33-3", 10);
    //get_price(test1, 10);

    DiscountLimit test2("4-44-44-4", 5, 10, 0.05);
    //get_price(test2, 11);


    return 0;
}