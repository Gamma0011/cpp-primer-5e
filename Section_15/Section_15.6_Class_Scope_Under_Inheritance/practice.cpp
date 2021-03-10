#include <iostream>
#include <string>

/*
    Under inheritance, the scope of a derived class is nested inside the scope of its base class. If a name is unresolved within the scope of the derived class,
     the enclosing base-class scopes are searched for definition of that name.

     This allows members of the derived class to use members of its base class as if those members were part of the derived class.

     The compiler will search down the line until it's able to fine a member that matches the declared member.
        Derived Class -> Derived (from Base) -> Base.
    
    | NAME LOOKUP HAPPENS AT COMPILE TIME |
        The static type of an object, reference, or pointer determines which members of that object are visible. Even when static and dynamic types
         might differ, the static type determines what members can be used.

        ex. class Disc_quote : public Quote {
            std::pair<std::size_t, double> discount_policy() const { return {quantity, discount}; }
        };

        We can use discount_policy only through an object, pointer, or reference of type Disc_quote or a class derived from it.
            Bulk_quote bulk;
            Bulk_quote *bulkP = &bulk;      // static and dynamic types are the same
            Quote *itemP = &bulk;           // static and dynamic types differ
            bulkP->discount_policy();       // okay, bulkP has type Bulk_quote*
            itemP->discount_policy();       // error, itemP has type Quote*     (Quote is base of Disc_quote, and has no access to member function discount_policy())

    | NAME COLLISIONS AND INHERITANCE |
        Like any other scope, a derived class can reuse a name defined in one of its direct or indirect base classes. Names defined in an inner scope (derived class)
         hide uses of that name in outer (base class) scope.
         
         see. struct Base; struct Derived;

        *NOTE* A derived-class member with the same name as a member from base class hides direct use of base-class member
    
    | USING THE SCOPE OPERATOR TO USE HIDDEN MEMBERS |
        We can use a hidden base-class member by using the scope operator.

            see. int get_base_mem() { return Base::mem; }

    The scope operator overrides normal lookup and provides direction.

    *BEST PRACTICES* Aside from overriding inherited virtual functions, a derived class usually should not reuse names defined in its base class.

    | KEY CONCEPT: NAME LOOKUP AND INHERITANCE |
        Given p->mem(), the following steps happen:
        
        1) Determine static type for p. That type must be a class type.
        2) Look for mem in class corresponding to static type. If not found, look in direct base class and continue until found or until last class searched.
        3) Once found, do normal type check. Is the call legal?
        4) If call legal"
            4a) mem is virtual and call made by & or *, compiler generates code to determine at run time the version to run based on dynamic type.
            4b) mem is nonvirtual and call is an object, normal function call generated.
    
    | AS USUAL, NAME LOOKUP HAPPENS BEFORE TYPE CHECKING |
        Functions declared in inner scope do not overload functions declared in outer scope. As a result, functions defined in a derived class
         DO NOT OVERLOAD members define in base class. 
        
        If a member of derived has the same name as base, the base class member is hidden within the derived class scope. The base member
         is hidden even if the functions have different parameter lists.

         struct Base {  int memfcn(); };
         struct Derived {   int memfcn(int); }      // Base::memfcn() would be hidden despite Derived requiring int arg.

        We can specifically call the Base::memfcn() from a Derived class by:
            Derived d | d.memfcn(10);
            d.Base::memfcn();           // calls Base::memfcn();
*/

struct Base {
    Base() : mem(0) { };
protected:
    int mem;
};

struct Derived : Base {
    Derived(int i) : mem(i) { };    // Derived::mem initialized to i | Base::mem default initialized
    int get_mem() { return mem; }   // returns Derived::mem;
    int get_base_mem() { return Base::mem; }
protected:
    int mem;
};

void test() {
    Derived d(42);
    std::cout << d.get_mem() << '\t' << d.get_base_mem() <<std::endl;       // prints 42
}

int main()
{
    test();

    return 0;
}