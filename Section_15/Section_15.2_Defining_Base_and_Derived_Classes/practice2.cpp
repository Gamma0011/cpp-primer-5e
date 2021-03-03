#include <iostream>
#include <vector>
#include <string>

/*
    | CONVERSIONS AND INHERITANCE |
        Understanding conversions between base and derived classes is essential to understanding OOP.

        Ordinarily, we can bind a reference or a pointer only to an object that has same type or has an 
         acceptable const conversion. Classes related by inheritance are an exception to this rule.
         We can bind a pointer or reference to a base-class type to an object of derived type from its base class.

        For example, we can use Quote& to refer to a Bulk_object, and we can assign the address of a Bulk_quote
         object to Quote*.

        The fact that we can bind a reference or pointer to a base-class type to a derived type has an important implication:
         When we use a & or * to base-class type, we don't know the actual type of the object to which the & or * is bound.
         It can be an object of base or derived class.
        
        *NOTE* Like built-in pointers, smart pointer classes support derived-to-base conversions.
    
    | STATIC TYPE AND DYNAMIC TYPE |
        Static type  - always known at compile time. It is the type with which variable is declared or expression yields.
        Dynamic type - object in memory that the variable or expression represents. May not be known until run time.

        ex. when print_total() calls net_price()

            double ret = item.net_price(n);
        
        We know that the static type of item is Quote&. Dynamic type depends on the object to which item is bound. Therefore,
         we will not know item until run time. If we pass a Bulk_quote object, the static type of item will differ from that of a Quote object.
        
        The dynamic type of an expression that is neither a & or * is always the same as that expression's static type. A variable of type Quote
         is always a Quote object, nothing will change this.

        Static type - Quote&
        Dynamic type - Bulk_quote object

        *NOTE* The static type of a * or & to base class may differ from its dynamic type.

    | THERE IS NO IMPLICIT CONVERSION BETWEEN BASE TO DERIVED |
        The conversion from derived to base exists because every derived class contains a base-class part to which a pointer or reference of the 
         base-class type can be bound. There is no similar guarantee for base-class objects.

        A base-class object can exist either an an independent object or as part of a derived class. A base object that is not part of a derived class
         only has members defined by the base class; it doesn't have members defined by the derived class.

        There is no automatic conversion from base class to its derived class.

            Quote base;
            Bulk_quote* bulkP = &base;      // error cannot convert base to derived
            Bulk_quote& bulkRef = base;     // error cannot convert base to derived.

        We cannot convert from base to derived, even when a base pointer or reference is bound to a derived object:

            Bulk_quote bulk;    
            Quote *itemP = &bulk;       // ok: dynamic type is Bulk_quote
            Bulk_quote *bulkP = itemP;  // error: cannot convert base to derived

        The compiler has no way to know (at compile) that a specific conversion will be safe to run. It only looks at the static
         types of the pointer or reference to determine legality of conversion

        If the base class has one or more virtual functions, we can use a dynamic_cast to request a conversion that is checked at run time.
        In cases where we KNOW a conversion from base to derived is safe, we can use static_cast to override compiler.

    | NO CONVERSIONS BETWEEN OBJECTS |
        The automatic derived-to-base conversion applied only for conversion to a & or * type. There is no conversion from derived-class type to
        base-class type.

        It is possible to convert an object of derived class to base-class type. But, this might not always work as intended.

        When we initialize an object of class type, we are actually calling a function (constructor). When we assign, we're calling 
         the assignment operator (operator= or [class](const [class]&))) These members normally have a parameter that is const& of class type (const Quote&)

        Because these members take reference, the derived-to-base conversion lets us pass a derived object to a base-class copy/move operation.

        When we pass a derived object to a base-class constructor, the constructor run is define in the base class. It only knows about the members
         in the base class itself. If we assign a derived object to a base object, the assignment operator run is the one in the defined
         in the base class.

            Bulk_quote bulk;    // object of derived type
            Quote item(bulk);   // uses Quote::Quote(const Quote&) constructor
            item = bulk;        // calls Quote::operator=(const Quote&)
        
            When item is constructed, the Quote copy constructor is called. It only knows about its member objects and ignores the rest in Bulk_quote.
            Additionally, when bulk is assigned to item, only the Quote part of bulk is assigned.
        
            This is phrase as "the derived class portion of that object is SLICED DOWN"
        
        *NOTE* When we initialize or assign an object of a base type from an object of derived type, only the base-class part of the derived object is copied,
        * moved or assigned. The derived part is ignored.
        

*/

int main()
{


    return 0;
}