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

*/

int main()
{


    return 0;
}