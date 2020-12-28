#include <iostream>
#include <vector>
#include <string>
#include <memory>

/*
    So far, our programs have only used static or stack memory. 
        Static Memory   - used for local static objects for class static data members, and for
                          variables defined outside any function.
        Stack Memory    - used for nonstatic objects defined inside functions.
    
    Objects allocated in static or stack memory are automatically created and destroyed by the compiler. STACK objects
     exist only while the block in which they're defined is executing; STATIC objects are allocated before they're used
     and destroyed when the program ends.
    
    In addition to static and stack memory, every program also has a pool of memory that it can used, referred to as 
     the FREE STORE or HEAP. Programs use the heap for objects they DYNAMICALLY ALLOCATE - that is, for objects that 
     the program allocates at runtime. The program controls the lifetime of dynamic objects; our code must explicitly destroy
     such objects when they are no longer needed

     **NOTE** Dynamic memory is notoriously tricky to manage correctly.

    Dynamic memory is managed through a pair of operators:
        new     - allocates and optionally initializes an object in dynamic memory and returns * to object
        delete  - takes a * to a dynamic object, destroys it, and frees associated memory

        Dynamic memory is problematic because it is hard to ensure that we free memory at the right time. Either we forget
         to free the memory - in which we have a memory leak - or we free memory when there are still pointers to that memory
         - in which case we have a * that refers to invalid memory -
        
    To make memory management easier (and safer), the new library provides two smart pointer types that manage dynamic
     objects. A smart pointer acts like a regular pointer with the important exception that it automatically deletes
     the object to which it points. There are two kinds of smart pointers: 
        shared_ptr  - allows multiple pointers to refer to the same object
        unique_ptr  - "owns" the object to which it pointers.

    Additionally, the library defines a companion class named weak_ptr
        weak_ptr    - weak reference to an object managed by a shared_ptr.

    **DEFINED IN MEMORY HEADER**

*/

int main()
{


    return 0;
}