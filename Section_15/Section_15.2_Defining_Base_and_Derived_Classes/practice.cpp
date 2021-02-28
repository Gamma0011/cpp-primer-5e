#include <iostream>
#include <vector>
#include <string>
#include "Quote_Class.h"
#include "Base_Class.h"

/*
    | DEFINING A BASE CLASS |

        see. Quote_Class.h

    *NOTE*  Base classes used as the root of inheritance heirarchy almost ALWAYS define a virtual destructor.
    *       Virtual destructors are needed, even if they do no work.

      | DERIVED CLASSES AND INHERITANCE |
        Derived classes inherit the members of their base class. However, a derived class needs to be able to 
         provide its own definition for operations, such as net_price, that are type dependent.
        
        In these cases, the derived class needs to OVERRIDE the definition inherited from the base class,
         by providing its own definition.
        
        In C++, a base class MUST distinguish the functions it expects its derived classes to inherit without change.
        The base class defines as VIRTUAL, functions it expects its derived classes to override.

        When we call a virtual function though * or &, the call will be DYNAMICALLY BOUND. Depending on the type of the object
         to which the reference or pointer is bound, the version in the base class or in one of the derived classes, is executed.

        A base class specifies that a member function should be dynamically bound by preceding its declaration with VIRTUAL. Any nonstatic 
         member function other than a constructor may be virtual. The virtual keyword only appears at declaration insdie the class 
         and may not be used on a function defintiion that appears outside the class body.
        
        A function declared VIRTUAL in the base class is IMPLICITLY VIRTUAL in DERIVED CLASSES.

        Member functions not declared VIRTUAL are resolved at compile time, not run time. Non-virtual functions also are not dependent
         on any details of the derived class. For example. isbn() will stay the same in both Quote and Bulk_quote

        | ACCESS CONTROL AND INHERITANCE |
            A derived class inherits the members defined in its base class. However, the member functions in a derived class may not 
             necessarily access the members that are inherited from the base class.
            
            A derived class may access the public members of its base class, but may not access private members. However, sometimes a base class
             has members that it wants to let others use, while still prohibiting access to those same members by other users.

            We specify these members with a PROTECTED access specifier.

            The Protected declaration allows derived classes to access these objects, but to non-members, these objects are private.

            Example. In Quote_Class.h, std::string bookNo is declared private because derived classes are expected to access this the same way
             as ordinary users: via std::string isbn() function. bookNo is not inherited by derived classes.
             double price is declared protected, because derived classes must be able to use this, but other non-members shouldn't.

    | DEFINING A DERIVED CLASS |
        A derived class must specify from which class(es) it inherits. It does so in its CLASS DERIVATION LIST, ( : [Access] [Base Class] {} )
        Each base class name may be preceded by an optional access specifier, Public, Protected, or Private. 
        
        * A derived class must declare each inherited member function it intends to override.

        see. class Bulk_quote : public Quote {};

        Our Bulk_quote inherits the isbn() function, bookNo, and price data members of its base class (class Quote).
         It then adds additional data members, min_qty and discount. 

        When the derivation is public, public members of base class become part of interface of derived class as well.
         The use of public in Bulk_quote derivation list implicitly converts isbn(), allowing us to use a Bulk_quote
         object where a pointer or reference to Quote is expected when calling isbn().

        Most classes directly inherit from only one base class. This is known as "Single Inheritance".

    | VIRTUAL FUNCTIONS IN THE DERIVED CLASS |
        Derived classes frequently, but not always override virtual functions that they inherit. If a derived class does
         not override a virtual from its base, the derived class inherits the base class version.

        A derived class may include the virtual keyword on functions it intends to override, but is not needed. For the derived
         class to explicitly note it intends a member function to override a virtual, it specified override after parameter list
         or after the const or reference qualifiers if member is const or reference function.

    | DERIVED-CLASS OBJECT AND THE DERIVED-TO-BASE CONVERSION |
        A derived object contains multiple parts:
            - A subobject containing (nonstatic) members defined in derived class.
            - Subobjects corresponding to each base class from which the derived class inherits.        
        
        In Bulk_quote, there are 4 elements - bookNo and price (base class), min_qty and discount (Bulk_quote derived class)

        *NOTE* base and derived parts of objects are not guaranteed to be store contiguously in memory
    
        Because a derived class contains subparts of base class, we can use an object of derived type AS IF it were an object of base type.
        We can bind a base-class reference or pointer to the base-class part of a derived object.

            ex. Quote item;         // object of base type
                Bulk_quote bulk;    // object of derived type
                Quote *p = &item;   // p points to Quote object
                p = &bulk;          // p points to Quote part of bulk
                Quote &r = bulk;    // r bound to Quote part of bulk
        
        This conversion is often referred to as the derived-to-base conversion, and is applied implicitly.

        *NOTE* The fact that a derived object contains subobjects for its base class is key to how inheritance works.

    | DERIVED-CLASS CONSTRUCTORS |
        Like any other code that creates an object of base-class type, a derived class must use a base-class constructor to initialize its base-class type.

        The base-class part of an object is initialized, along with data members of derived class. A derived-class constructor uses its constructor
         initializer list to pass args to a base-class constructor.

         Bulk_quote(const std::string &bn, double p, std::size_t mq, double d) :
            Quote(bn, p), min_qty(mq), discount(d) { };

        The first two paramters pass to Quote constructor Quote(bn, p), which initialized Bulk_quote's base-class part.
         The second two parameters initialize members of Bulk_quote, min_qty(mq), discount(d).

        As with a data member, unless we say otherwise, the base part of a derived object is default initialized. To use a different
         base-class constructor, we provide a constructor initializer using name of base class, followed by a parenthesized list of args.
         Those args are used to select which base-class constructor to use to initialize the base-class part of derived class.

        *Note* The base class is initialized first, then members of derived class in order in which they are declared within class.

        *Note 2* A derived class may access the public and protected members of its base class.
            see. double Bulk_quote::net_price(std::size_t) const;

        It is worth noting that the scope of a derived class is nested inside the scope of its base class. As a result, there is no distinction
         between how member of the derived class uses members defined in its own class and how it uses members defined in its base class.

    *KEY CONCEPT: RESPECTING THE BASE-CLASS INTERFACE*
        It is essential to understand that each class defines its own interface. Interactions with an object of class-type should use the interface
         of its class, even if that object is the base-class part of the derived class.
         As a result, derived-class constructor may not directly initialize members of its base class. The constructor body of a derived 
         constructor can assign values to its public or protected base-class members. Although it CAN assign to those members, it generally
         SHOULD NOT DO SO. Like any other user of the base class, a derived class should respect the interface of its base class by using 
         a constructor to initialize its inherited members.
        
        CORRECT: (Base class objects initialized via Base class constructor)
        Bulk_quote(const std::string &bn, double p, std::size_t mq, double d) :
            Quote(bn, p), min_qty(mq), discount(d) { };

    | INHERITANCE AND STATIC MEMBERS |
        If a base class defines a static member, there is only one such member defined for the entire hierarchy. Regardless of the # 
         derived classes, there exists a single instance of each static member

            see. Base_Class.h

            class Base {
            public:
                static void statmem();
            };

        Static members object normal access control. If member is private in base class, derived class has no access to it. 
         Assuming member is accessible, we can use a static member either through base or derived class.
    
            void Derived::f(const Derived &derived_obj) {
                Base::statmem();        // ok: Base defined statmem
                Derived::statmem();     // ok: Derived inherits statmem
                derived_obj.statmem();  // accessed through a Derived Object
                statmem();              // accesses through this object
            }

    | DECLARATIONS OF DERIVED CLASSES |
        A derived class is declared like any other class. The declaration contains the class name,
         but does not include derivation list.  

         WRONG: class Bulk_quote : public Quote;
         RIGHT: class Bulk_quote;

    | CLASSES USED AS A BASE CLASS |
        A class must be defined, not just declared before we can use it as a base class. Each derived class contains
         and may use members it inherits from its base class. To use those members, the derived class must know what they are.

        A base class itself can be a derived class.

        class Base;
        class D1 : public Base;
        class D2 : public D1;

        Base is a DIRECT BASE to D1, and an INDIRECT BASE to D2 (inherited from D1).
        
        DIRECT BASE - Named in derivation list
        INDIRECT BASE - Inherited through its base class. 

        Each class inherits all members of its direct base class. The most derived object contains a subobject for its direct
         base and for each of its indirect bases.

    | PREVENTING INHERITANCE |
        We can prevent a base class from being used as a base with FINAL. This is possible to be done with derived classes as well,
         preventing them from being used as base classes.

        class NoDerived final {};       // cannot be used as a base class.

        class Base {};
        class Test final : public Base {};  // cannot be used as a base class.

*/

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;     // default constructor
    Bulk_quote(const std::string &bn, double p, std::size_t mq, double d) :
        Quote(bn, p), min_qty(mq), discount(d) { };

    double net_price(std::size_t) const override;
private:
    std::size_t min_qty = 0;    // minimum purchase for discount to apply
    double discount = 0.0;      // fractional discount to apply
};

double Bulk_quote::net_price(std::size_t cnt) const {
    if (cnt >= min_qty) {
        return cnt * (1 - discount) * price;
    } else {
        return cnt * price;
    }
}

void Derived::f(const Derived &derived_obj) {
    Base::statmem();        // ok: Base defined statmem
    Derived::statmem();     // ok: Derived inherits statmem
    derived_obj.statmem();  // accessed through a Derived Object
    statmem();              // accesses through this object
}

class NoDerived final {};

int main()
{


    return 0;
}