#include <iostream>
#include <string>

/*
    KEY CONCEPT: CONVERSIONS AMONG TYPES RELATED BY INHERITANCE
        - The conversion from derived to base applies only to pointer or reference types.
        - No implicit conversion from base-class type to derived type.
        - The derived-to-base conversion may be inaccessible due to access controls.

    | VIRTUAL FUNCTIONS |
        Dynamic binding happens when a virtual member function is called through & or * to base-class type.
         Because we don't know the version of a function at compile, virtual functions must ALWAYS be defined.
         We MUST DECLARED every virtual fuction, regardless of whether it is used, because the compiler will have
         no way of determining whether a virtual function is used.

    | CALLS TO VIRTUAL FUNCTIONS MAY BE RESOLVED AT RUN TIME |
        When a virtual function is called through & or *, the compiler generates code to decide at run time which function to call.
        The called function is the one that corresponds to the dynamic type of the object bound to that pointer or reference.

        Dynamic binding only happens when a virtual function is called through a pointer or reference. ex. Quote&, which allows
         calls from base type or derived type, and works because net_price(size_t) is a virtual function

            double print_total(std::ostream &os, const Quote &q, std::size_t n) {
                return q.net_price(n);

            }
        
        When we call a virtual function in an expression that has a plain (nonreference or non-pointer type), that call is bound
         at compile time. Ex. const Quote q would be of base-class type at compile type and would be static.

            double print_total(std::ostream &os, const Quote q, std::size_t n);

    
    *KEY CONCEPT: POLYMORPHISM IN C++*
        Key idea of OOP is polymorphism, derived from a Greek word meaning "many forms". Types related by inheritance as polymorphic types,
        because we can use the "many forms" of these types while ignoring the differences among them.

        The fact that static and dynamic types of reference and pointers can differ is the cornerstone of C++ Polymorphism.

        Calls to nonvirtual functions are bound at compile time. Calls to any function (virtual or nonvirtual) on an object are also bound at 
         compile time. The type of object is fixed and there s nothing we can do to make it dynamic from its static type. Therefore, calls
         made on an object are bound at compile time to the version defined b the object's type.

        *Virtuals are resolved at run time ONLY if the call is made through a & or *. Only in these cases is it possible for an object's 
        * dunamic type to differ from it's static type.
        
    | VIRTUAL FUNCTIONS IN A DERIVED CLASS |
        A derived class overriding a virtual function may repeat the virtual keyword. Once it is declared virtual, it is virtual in all derived classes.

        A derived-class function overriding an inherited virtual function must have exactly the same # of parameter types as base-class function it overrides.

        The return type of a virtual in derived class must match return type of function from base class, except for in one case. The exception being when virtuals 
         return a & or * to types that are themselves related by inheritance. 

            ex. If D is derived from B, then base class virtual can return a B* and verion in derived can return a D*. 
        
        *NOTE* A function that is virtual in a base class is implicitly virtual in derived. When derived overrides a virtual, the paramters in base and derived must match.

    | THE FINAL AND OVERRIDE SPECIFIERS |
        It is legal for a derived class to define a function with the same name as a virtual in base, but with different paramters. This function would be considered
         independent from base-class virtual function. However, is most cases, this is often a mistake when the author incorrectly writes the parameter list.

        Specifying OVERRIDE on a virtual function in derived class makes our intention clear that we wish to override the base-class virtual.

            see. struct B {...} ; struct D1 : public B {...};

        We can also designate a function as final, meaning that any attempt to override a function defined as final will be in error.

            see. struct D2 : B {...} ; struct D3 : D2 {...};

        OVERRIDE and FINAL appear after the parameter list and any const or & qualifiers, and after a trailing return.

    | VIRTUAL FUNCTIONS AND DEFAULT ARGUMENTS | 
        Like any other function, a virtual function can have default args. If there is a call that uses default args, the value used is one defined
         by the static type through which the function is called.
        
        When a call is made through a & or * to base, the default args are defined in base, and will be used even if a derived version of the function is run.

        In this case, the derived function will be passed default base-class args. However if the derived class requires passing of different or additional args,
         the program will not execute properly.
        
        *Best Practices* Virtual functions that have default args should use the same default args in base and derived classes.

    | CIRCUMVENTING THE VIRTUAL MECHANISM |
        We might want to prevent the dynamic binding of a call to a virtual function, forcing the call to use a particular version of that virtual.
         To do this, we can use the scope operator.

         ex. double undiscounted = baseP->Quote::net_price(42);

            In this case, baseP will always call the base-class version of net_price, regardless of baseP being of base or derived type. Call will be
             resolved at compile time and not at run time.
            
        *NOTE* Only code inside member functions (or friends) should need to use scope operator to circumvent the virtual mechanism.

        The most common reason to use this is when a derived virtual member calls the version from the base class. In such cases, the base-class version might
         do work common to all types in the heirarchy. The versions defined in the derived classes would do whatever additional work is needed for their
         own particular type.

        *WARNING* If a derived virtual function that intended to call its base-class version omits the scope operator, the call will be resolved at run time
        * as a call to the derived version itself, resulting in infinite recursion.
        

*/

struct B {
    virtual void f1(int) const;
    virtual void f2();
    void f3();
};

struct D1 : public B {
    void f1(int) const override;    // okay: f1 matches f1 base
    //void f2(int) override;        // error: B has no f2(int) function. Marked override by does not override.
    //void f3() override;           // error: f3() not virtual
    //void f4() override;           // B does not have function named f4
};

struct D2 : B {
    // inherits f2() and f3() from be and overrides f1(int)
    void f1(int) const final;       // subsequent classes cannot override f1(int)
};

struct D3 : D2 {
    void f2();                      // ok: overrides f2 inherited from its indirect base
    //void f1(int) const;           // error: virtual function overriding final function

};


int main()
{

    return 0;
}