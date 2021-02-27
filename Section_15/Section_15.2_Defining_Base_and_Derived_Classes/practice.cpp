#include <iostream>
#include <vector>
#include <string>
#include "Quote_Class.h"

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
        

*/

int main()
{


    return 0;
}