#include <iostream>
#include <string>

/*
    When we use a container to store objects from an inheritance hierarchy, we must store these objects indirectly.
     We cannot put objects of types related by inheritance directly into a container, because there is no way to define
     a container that holds elements of differing types.

        ex.
            std::vector<Quote> basket;
            
            // this copies only the Quote part of the object into basket
            basket.push_back(Quote("0-000-000-0", 50));
            // calls version defined by Quote, prints 750 (50*15)
            std::cout << basket.back().net_price(15) << std::endl;

    Elements in basket are Quote objects. If we were to add Bulk_quote, its derived parts would be ignored.

    *NOTE* Because derived objects are "sliced down" when assigned to base-class type, containers and types related by inheritance do not work well.

    | PUT (SMART) POINTERS, NOT OBJECTS, INTO CONTAINERS |
        When we need a container to hold objects related by inheritance, we can create a container to hold smart pointers to the base class.
         The dynamic type of the object to which those pointers point might be base-class or derived type from that base.

        ex.
            std::vector<std::shared_ptr<Quote>> basket;

            basket.push_back(std::make_shared<Quote>("0-000-000-0", 50));
            basket.push_back(std::make_shared<Bulk_quote>("1-111-111-1", 50, 10, .25));

            // calls the version defined by Quote; printing 562
            std::cout << basket.back()->net_price(15) << std::endl;

        We must dereference the value returned by basket.back() to get the object type needed to run net_price()
        
        In the same way that we can convert an ordinary pointer to a derived type to a pointer of base-class type,
         we can also convert smart pointers in the same way. This is why make_shared<Bulk_quote> returns a 
         shared_ptr<Bulk_quote> object, converted to a shared_ptr<Quote> we can call push_back with.

         In practice, because of this, all objects in the basket vector have the same type.

    | WRITING A BASKET CASE |
        In C++ we cannot use objects directly to support OOP. We must use pointers and references. Because pointers impose
         complexity on our programs, we often define auxiliary classes to help manage the complexity. 

         see. basket.h

        Users are still responsible for dynamic memory because add_item takes a shared_ptr. Because of this, users have to write
         code, such as:
            Basket bsk;
            bsk.add_item(make_shared<Quote>("123", 45));
            bsk.add_item(make_shared<Bulk_quote>("345", 45, 4, .15));
        
        The next step is redefining add_item so that it takes a Quote object instead of a shared_ptr. This new version of add_item
         will handle all memory allocation. This will be done with:
            void add_item(const Quote &sale);       // copy given object
            void add_item Quote &&sale);            // move given object

        add_item doesn't know which type to allocate however. To solve this, we'll give our Quote classes a virtual member that
         allocates a copy itself. 

            see.    quote.h functions:
                    virtual Quote* clone() const & { return new Quote(*this); }
                    virtual Quote* clone() && { return new Quote(std::move(*this)); }
                    Bulk_quote* clone() const & { return new Bulk_quote(*this); }
                    Bulk_quote* clone() && { return new Bulk_quote(std::move(*this)); }

            Our clone function in base Quote is virtual, which allows for the compiler to use the dynamic type of the object provided at run time.
                (ex. object of type Quote or Bulk_quote will call its respective clone rvalue or lvalue function)
             With this, clone returns a pointer to a newly allocated object of its own type. We bind a share_ptr to that object and call insert to
              add the newly allocated object to the items multiset. 

            *Note* Because shared_ptr supports derived-to-base conversion, we can bind a shared_ptr<Quote> to a Bulk_quote*


*/



int main()
{


    return 0;
}