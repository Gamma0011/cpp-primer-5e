#include <iostream>
#include <vector>
#include <string>
#include <memory>

/*
    | PREVENTING COPIES |
        BEST PRACTICE - Most classes should define, either implicitly or explicitly, the default and copy constructors, and the copy-assignment operator.

        Although most classes should (and usually do) define a copy constructor and a copy-assignment operator, for some classes, 
         there is really no meaning for these operations. In such cases, the class must be defined tso as to prevent copies or assignments
         from being made.

        For example, the iostream classes prevent copies to avoid letting multiple objects write to or read from the same IO buffer. No definting the 
         copy-control members is not a solution as the compiler will synthesize them.

        We can prevent copies by defining the copy constructor and copy-assignment operator as deleted functions. A deleted function is one
         that is declared but may not be used in any other way. This is indicated by = delete.

            see. struct NoCopy;

        = delete signals that we are intentionally not defining these members. 
         Unlike (= default), (= delete) must appear at the first declaration of the function. The compiler needs to know that a function is deleted
         in order to prohibit operations that attempt to use it. 

        Also, unlike (= default), which can only be used on default constructor and copy-control members, (= delete) can be specified on any function.

        | THE DESTRUCTOR SHOULD NOT BE A DELETED MEMBER |
            If the destructor is deleted, then there is no way to destroy objects of that type. The compiler will not let us define variables or create
             temporaries of a type that has a deleted destructor. Moreover, we cannot define variables or temporaries of a class that has a member whose
             type has a deleted destructor. If a member has a deleted destructor, the member and therefore the object cannot be destroyed.

            struct NoDtor {
                NoDtor() = default;     // used synthesized default constructor
                ~NoDtor() = delete;     // we can't destroy objects of type NoDtor
            };

            NoDtor nd;                  // error: NoDtor destructor is deleted
            NoDtor *p = new NoDtor();   // ok: but we can't delete p.
            delete p;                   // error: NoDtor destructor is deleted

        **NOTE** It is not possible to define an object or delete a pointer to a dynamically allocated object of a type with a deleted destructor.

        | THE COPY-CONTROL MEMBERS MAY BE SYNTHESIZED AS DELETED |
            As we've seen, if we do not define the copy-control members, the compiler defines them for us. Similarly, if a class defines no constructors, the compiler
             synthesizes a default constructor for that class. 

            For some classes, the compiler defines these synthesized members as deleted functions:
            
             - Synthesized destructor = delete if class has a member whose own destructor is deleted or inaccessible (private)
             - Synthesized copy constructor is defined as deleted if the class has a member whose own copy constructor is deleted or inaccessible.
                If is also deleted if class has a member with a deleted or inaccessible destructor.
             - Synthesized copy-assignment operator is defined as deleted if a member has a deleted or inaccessible copy-assignment operator, or
                if the class has a const or & member.
             - Synthesized default constructor is defined as deleted if class has a member with deleted or inaccessible destructor; or has a 
                & member that does not have an in-class initializer

            In essence, these rules mean that if a class has a data member that cannot be default constructed, copied, assigned, or destroyed,
             then the corresponding member will be a deleted function.
        
        | PRIVATE COPY CONTROL |
            Prior to C++11, classes prevented copies by declaring copy constructor and copy-assignment as private members of a class.

            So long as the destructor was public, objects of the class could be created and deleted, but not copied. However, friends
             and members of the class can still make copies. 
            
            To prevent copies by friends and members, we declare these members as private, but do not define them.

            **C++11 BEST PRACTICE**
            Classes that want to prevent copying should define their copy constructor and copy-assignment operator using = delete and not as private members.

*/

struct NoCopy {
    NoCopy() = default;                             // use synthesized default constructor
    NoCopy(const NoCopy &) = delete;                // no copy;
    NoCopy& operator=(const NoCopy&) = delete;      // no assignment;
    ~NoCopy() = default;                            // use synthesized default destructor
};


int main()
{


    return 0;
}