#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "strClass.h"

/*
    || MOVING OBJECTS ||
        During reallocation, there is no need to copy - rather than move - the elements from old memory
         to new. A second reason to move rather than copy is in classes such as IO or unique_ptr. These
         resources may not be shared.

         **NOTE** 
            String and shared_ptr support move and copy
            IO and unique_ptr only support move
        
        | RVALUE REFERENCES |
            An rvalue reference is a reference that must be bound to an rvalue. This is obtained by
             using && rather than &. An rvalue reference may ONLY be bound to an object that 
             is about to be destroyed. As a result we are free to "move" resources from an rvalue
             reference to another object.
            
            Generally speaking, the differences between lvalue and rvalue
                lvalue - refers to an object's identity
                rvalue - refers to an object's value

            We cannot bind regular (or lvalue references &) to expressions that require a conversion to literals
             or to expressions that return an rvalue. Rvalues references are the opposite; We can bind an rvalue
             reference to these kind of expressions, but we cannot directly bind an rvalue reference to an lvalue

            see. void lrval();

        | LVALUE REFERENCE RETURNS |
            Can be bound to : Assignment, Subscript, Dereference, and Prefix Incr/Decr Ops

        | RVALUE REFERENCE RETURNS |
            Can be bound to : Arithmetic, Rational, Bitwise, and Postfix Incr/Decr Ops

            In this case, the return can be bound to a (const &), or a rvalue reference (&&)

        | LVALUES PERSIST; RVALUES ARE EPHEMERAL |
            Lvalues have a persistent state. Rvalues however are either literals, or temp objects 
             created in the process of evaluating expressions.

             Because the rvalue references can ONLY be bound to temporaries, we know:
                - Referred-to object is about to be destroyed
                - There can be no other users of object
            
            *NOTE* Rvalues references refer to objects that are about to be destroyed. Hence, we can "steal" state from an object bound to an &&

        | VARIABLES ARE LVALUES |
            A variable is an expression with one operand and no operator. 
            One interesting thing, is that we cannot bind an && to another variable defined as &&

            int &&r1 = 42;      // ok: 42 is a literal and literals are rvalues
            int &&r2 = r1;      // error: expression rr1 is an lvalue

            *NOTE* A VARIABLES IS AN LVALUE. WE CANNOT DIRECTLY BIND AN && TO A VARIABLE, EVEN IF THAT VARIABLE WAS DEFINED AS TYPE &&

        | THE LIBRARY MOVE FUNCTION | 
            Although we cannot directly bind an &&  to an lvalue, we can explicitly cast an lvalue to its corresponding && type.
            Additionally, we can obtain a && bound to an lvalue by calling std::move in the <utility> header.

            Calling move tells the compiler that we have an lvalue we want to treat as an rvalue. 
                see. void moveFunction();
        
                    int &&rr1 = 42;     // ok: literal is an rvalue
                    int &&rr2 = std::move(rr1);

                The call to move declares that we do not intend to use rr1 again except for assignment or destruction. 
                After a call to move, we cannot make any assumptions about the value of the moved-from object. 
                
                *NOTE* We can destroy a moved-from object and can assign a new value to it, but we cannot use the value of a moved-from object.

        | MOVE CONSTRUCTOR AND MOVE ASSIGNMENT |
            In addition to copy constructors and copy-assignment operators, we can also define move constructors and move-assignment operators. 
             These function by "stealing" resources from their given object rather than copying them.
            
            The move constructor must ensure that the moved-from object is left in a state such that destroying the object will be harmless.
             Once resources are moved, the original object must no longer point to those moved resources.
            
            StrVec::StrVec(StrVec &&s) noexcept         // won't throw any exceptions
                // member initializers take over the resources in s
                : elements(s.elements), first_free(s.first_free), cap(s.cap) {
                    // leave s in a state in which it is safe to run destructor
                    s.elements = s.first_free = s.cap = nullptr;
                }

            Unlike the copy constructor, the move constructor does not allocate any new memory; it takes over memory
             frm the given StrVec. Having taken over the memory, the constructor body sets the pointers in the given object to
             nullptrs. Eventually, the moved-from object (s) will be destroyed. Not changing s.first_free or any other member data
             to nullptr would delete the memory just moved.

                Steps: &&s rvalue to object s, ownership moved to new object calling move constructor, once ownership moved, reset
                        memory so that memory can be deleted. Once deleted, new object has ownership of members of old object.
        
        | MOVE OPERATIONS, LIBRARY CONTAINERS, EXCEPTIONS |
            Move operations normally do not allocate resources. As a result, the move operations will not throw any exceptions.
             When we write a move operation that cannot throw, we should inform the library of the fact, by declaring noexcept
             If we don't, it'll do extra work to cater to the possibility that moving an object of our class type might throw.

             noexcept is a way for us to promise that the function does not throw any exceptions.
             In a function, no except exists after the parameters, in a constructor, it exists between the paramters and initializer list

            **NOTE** we must specify noexcept on both declaration in the class header and on the defintion, if that definition appears
            outside of the class 
                ex.
                    class C{
                        C(C&&) noexcept;
                    };
                    C::C(C &&c) noexcept : {};

            Move constructors and move assignment operators that cannot throw exceptions should be marked as such - noexcept
*/

void lrval() {
    int i = 2;             
    int &r = i;                 // ok: r refers to i
    //int &&rr = i;             // error: cannot bind rvalue reference to an lvalue 
    //int &r2 = i * 42;         // error i * 42 is an rvalue
    const int &r3 = i * 42;     // ok: we can bind a reference to const to an rvalue
    int &&rr2 = i * 42;         // ok: bind rr2 to the result of i * 42;

    /* The reason why int &&rr2 = i * 42 works and &&r2 = i doesn't is because 
        the rvalue of i * 42 would be otherwise destroyed. While i already exists
        as an identity of a value (2), an lvalue
    */
}

void moveFunction() {
    int &&rr1 = 42;     // ok: literal is an rvalue
    int &&rr2 = std::move(rr1);
}


int main()
{
    lrval();
    moveFunction();

    return 0;
}