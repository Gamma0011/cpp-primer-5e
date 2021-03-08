#include <iostream>
#include <vector>
#include <string>

/*
    | PROTECTED MEMBERS |
        Protected members are shared with derived classes, but protected from general access.
            - Like private, protected members are inaccessible to users of class.
            - Like public, protected members are accessible to members and friends of classes derived from this class.
        Another important property:
            - A derived class member or friend may access protected members of the base class only through a derived object. 
              The derived class has no special access to the protected members of base-class objects.

        Members and friends of a derived class can access the protected members ONLY in base-class objects embedded inside a
         derived type object; they have no special access to ordinary objects of the base type.
            ex. class Base object cannot access protected int i; But, class Derived : public Base object can.

    | PUBLIC, PRIVATE, AND PROTECTED INHERITANCE |
        
        - PUBLIC inheritance makes public members of the base class public in the derived class, and the 
            protected members of the base class remain protected in the derived class.
        - PROTECTED inheritance makes the public and protected members of the base class protected in the derived class.
        - PRIVATE inheritance makes the public and protected members of the base class private in the derived class.

    | ACCESSIBILITY OF DERIVED-TO-BASE CONVERSION |
        Success of derived-to-base conversions depend on which code is using conversion and access specifider use in derivation.
         Assuming D inherits from B:
            - User code may use derived-to-base conversion ONLY IF D inherits publicly from B. 
            - Member functions and friends of D can use conversion to B regardless of how D inherits from B. Derived-to-base
                conversion to a direct base class is ALWAYS accessible to members and friends of derived class.
            - Member functions and friends of classes derived from D may use derived-to-base conversion if D inherits from B
                using either PUBLIC or PROTECTED.
        
        *TIP* For any given point in your code, if a PUBLIC member of base class would be accessible, then the derived-to-base conversion
        *       is also accessible.
        

    | KEY CONCEPT: CLASS DESIGN AND PROTECTED MEMBERS |
        In the absence of inheritance, we can think of a class as having 2 different kinds of users: ORDINARY and IMPLEMENTORS. 

        Ordinary users write code that uses object of class type and can only access public members.
        Implementors write code contained in the members and friends of class, which can access public and private sections of code.

        Under inheritance, there is a 3rd user, derived classes. A base class makes protected those parts of implementation it wants
         its derived classes to be able to use. The protected members remain inaccessible to ordinary users. Additionally, private members
         also remain inaccessible to derived classes and their friends.

        Like any other class a class that is used as a base class makes its interface members public. A class that is used as a base class may divide
         its implementation into those members that are accessible to derived classes and those that remain accessible only to the base class and friends.
        
        An implementation member should be PROTECTED if it provided an operation or data that a derived class will need to use in its own implementation.
        Otherwise, implementation members should be PRIVATE.

    | FRIENDSHIP AND INHERITANCE |
        

*/

int main()
{

    return 0;
}