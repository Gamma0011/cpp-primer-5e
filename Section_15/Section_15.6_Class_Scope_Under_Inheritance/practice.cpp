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
    
    | VIRTUAL FUNCTIONS AND SCOPE |
        If the base and derived members took arguments that differed from one another, there would be no way to call the
         derived version through reference or pointer to the base class.

    | CALLING A HIDDEN VIRTUAL THROUGH BASE CLASS |

        see. classes Base2, D1, D2

        Base2 bobj; D1 d1obj; D2 d2obj;
        Base *bp1 = &bobj; Base *bp2 = &d1obj; Base *bp3 = &d2obj;
        bp1->fcn() | calls Base::fcn()
        bp2->fcn() | calls Base::fcn()
        bp3->fcn() | calls D2::fcn()

        D1 *d1p = &d1obj; D2 *d2p = &d2obj;
        bp2->f2() | error: base has no members called f2()
        d1p->f2() | calls D1::f2
        d2p->f2() | calls D2::f2

        Because fcn() is virtual, the calls from objects of base class type are called at run time.

        Base *p1 = &d2obj; D1 *p2 = &d2obj; D2 *p3 = &d2obj;
        p1->fcn(42) | error: Base has no fcn(int)
        p2->fcn(42) | calls D1::fcn(int)    statically bound     
        p3->fcn(42) | calls D2::fcn(int)    statically bound

        Dynamic type doesn't matter when we call a nonvirtual function (in this case, void fcn(int)). The version
         calls only depends on the static type of the pointer itself.

    | OVERRIDING OVERLOADED FUNCTIONS |
        A virtual member function can also be overloaded. A derived class can override zero or more instances of the overloaded
         functions it inherits. If a derived class wants to make the overloaded versions available through its type, it must
         override all of them, or none of them.

        In some cases, the derived class may need to override some, but not all. Instead of overriding every base-class version
         a derived class inherits, a derived class can provide a USING declaration for the overloaded member. A using 
         declaration ONLY specified a name and may not list parameters. A using declaration for a base-class member function adds
         ALL overloaded instances of that function to the scope of the derived class. 
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

/////////////////////////////////////////////

class Base2 {
public:
    virtual int fcn();
};

class D1 : public Base2 {
public:
    int fcn(int);       // parameter list differs from fcn in Base2
    virtual void f2();
};

class D2 : public D1 {
    int fcn(int);       // nonvirtual, hides D1::fcn(int)
    int fcn();          // overrides virtual void fcn() from Base2
    void f2();          // overrides virtual void f2() from D1
};

int main()
{
    test();

    return 0;
}