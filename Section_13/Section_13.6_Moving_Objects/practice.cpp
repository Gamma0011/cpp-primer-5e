#include <iostream>
#include <string>
#include <vector>
#include <utility>

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