#include <iostream>
#include <string>

/*
    Like any other class, a class in an inheritance heirarchy controls what happens when objects of its type are created, copied, moved, assigned and destroyed.
     If a class (base or derived) does not define one of the copy-control operations, the compiler will synthesize that operator. Also, as usual,
     the synthesized version of any of these members might be a deleted function.

    | VIRTUAL DESTRUCTORS |
        The primary direct impact that inheritance has on copy control for base class is that a base class generally should define a virtual destructor.
        *The destructor needs to be virtual to allow objects in the inheritance heirachy to be dynamically allocated. Remember, a destructor is run
        *  when we delete a pointer to a dynamically allocated object.
        
        In inheritance, it's possible that the static type of a pointer will differ from the dynamic type being destroyed. 

        A virtual destructor is needed if a base pointer pointing to a derived object is deleted.

        Like any other virtual, the virtual nature of the destructor is inherited. Thus, classes derived from Quote have virtual destructors, whether they
         use the synthesized destructor or define their own. So long as the base class has a virtual destructor, when we delete a pointer to base,
         the correct destructor will be run.

            Quote *itemP = new Quote;   // same static and dynamic type
            delete itemP;               // destructor for Quote called
            itemP = new Bulk_Quote;     // static and dynamic type differ
            delete itemP;               // destructor for Bulk_quote called

    *IMPORTANT* Executing delete on a pointer to base that points to a derived object has undefined behavior if the base's destructor is not virtual

    | VIRTUAL DESTRUCTORS TURN OFF SYNTHESIZED MOVE |
        If a class defines a destructor -- even if it uses = default, the compiler will not synthesize a move operation for the class.

    | SYNTHESIZED COPY CONTROL AND INHERITANCE |
        The synthesized copy-control members in a base or derived class execute like any other synthesized constructor, assignment operator or destructor.
         They memberwise initialize, assign, or destroy the members of the class itself. Additionally, they initialize, assign, or destroy the direct base
         part of the object by using the corresponding operation from the base class.
        
        Ex.
            - Synthesized Bulk_quote default constructor runs Disc_Quote default constructor, which then runs Quote default constructor.
            - Quote default constructor initializes bookNo member to "" and in-class initializes price = 0.0
            - Quote constructor finishes, Disc_Quote constructor then in-class initializes qty and discount.
            - Disc_Quote constructor finishes, Bulk_quote constructor continues with no work to do.

            The same thing happens in the case of synthesized default copy constructors. Since the Base class (Quote) defines a virtual destructor,
             there are no synthesized move operations (move = delete). As a direct result, all dervied classes also lack the move operation

    | BASE CLASSES AND DELETE COPY CONTROL IN THE DERIVED |
        Rules:
            - If the default constructor, copy constructor, copy-assignment operator, or destructor in base class = delete or inaccessible, the corresponding
              member in derived class is also deleted. 
            - If base class has inaccessible or deleted destructor, then the synthesized default and copy constructors in derived classes are = delete. There
              is no way to destroy the base part of the derived object.
            - Compiler will not synthesize a deleted move operation. If we use = default to request move operation, it will be a deleted function in derived
              if corresponding operation in base is delete or inaccessible. Move constructor also deleted if base class destructor deleted or inaccessible.

            see. class B; class D : public B;

    | MOVE OPERATIONS AND INHERITANCE |
        Most base classes define a virtual destructor. Because of this, by default, base classes do not get synthesized move operations.
         A class derived from a base class does not have their move operations synthesized either. 

        Because of this, base classes SHOULD explicitly define move operations, if needed. If move operations are defined, so too should copy operations.
            see. class Quote

    | DERIVED-CLASS COPY-CONTROL MEMBERS |
        The copy and move constructors for a derived class must copy/move the members of its base part as well as the members in its derived.
         The same goes for the assignment operator.

        Unlike constructors and assignment operators, the destructor is responsible only for destroying resources allocated by derived class. 
    
    *NOTE* When a derived class defines a copy or move operation, that operation is responsible for copying or moving the entire object, including base-class members.

    | DEFINING A DERIVED COPY OR MOVE CONSTRUCTOR |
        We normally use the corresponding base-class constructor to initialize the base part of a derived object.
            see. class D2 : public Quote;

        By default, the base class default constructor initializes the base part of the object. To use the copy or move constrctor, we must
         explicitly call that constructor in the constructor initializer list.

    *NOTE* By default, the base-class default constructor initializes the base-class part of a derived object. If we copy (or move) the base-class part,
    *       we must explicitly use the copy (or move) constructor for the base class in the derived's constructor initializer list.
    
    | DERIVED-CLASS ASSIGNMENT OPERATOR |
        Like copy and move contructors, a derived-class assignment operator must assign its base part explicitly.

        *Base::operator=(const Base&) not invoked automatically
        D &D::operator=(const D &rhs) {
            Base::operator=(rhs);
            return *this;
        }

    | DERIVED-CLASS DESTRUCTOR |
        Data members of an object are implicitly destroyed after the destructor body completes. The base-class parts of a object are
         also implicitly destroyed. Unlike constructors and assignment operators, a derived destructor is responsible only for
         destroying the resources allocated by the derived class.

         class D : public B {
             public:
                *Base::~Base() called automatically
                ~D();
         }

        Objects are destroyed in the opposite order from which they were constructed:
            - Derived destructor -> Base destructor
        
    | CALLS TO VIRTUALS IN CONSTRUCTORS AND DESTRUCTORS |
        The base-class part of a derived object is constructed first. While this happens, the derived part of the object is uninitialized.
         When destroyed, the derived part of an object is destroyed before its base part.
        
        The compiler treats the object as if its type changes during construction and destruction. While an object is being constructed, it is
         treated as if it has the same class as the constructor. Calls to virtual functions are bound as if the object has the same type as the constructor itself.
         Same goes for destructors. 
        
        *NOTE* If a constructor or destructor calls a virtual, the version run corresponds to that one within the type itself.

*/

class B {
public:
    B() = default;
    B(const B&) = delete;
    //virtual ~B();
};

class D : public B {
public:
};

void practice() {
    D d;                // D's synthesized default constructor uses B's default constructor
    //D d2(d);            // error: D's synthesized copy constructor is deleted (Base class copy = delete)
    //D d3(std::move(d)); // error: implicitly uses D's deleted copy constructor
}

class Quote {
public:
    Quote() = default;
    Quote(const Quote&) = default;              // memberwise copy
    Quote(Quote&&) = default;                   // memberwise copy
    Quote& operator=(const Quote&) = default;   // copy assign
    Quote& operator=(Quote&&) = default;        // move assign
    virtual ~Quote() = default;                 // destructor
};

class D2 : public Quote {
public:
    D2(const D2& d) : Quote(d) { };             // explicitly call Quote copy constructor
    D2(D2&& d) : Quote(std::move(d)) { };       // explicitly call Quote move assignment operator
    D2& operator=(const D2&);                   // copy-assignment operator
};

D2& D2::operator=(const D2 &rhs) {              // copy-assignment operator initializing base-class members
    Quote::operator=(rhs);
    return *this;
}

int main()
{


    return 0;
}