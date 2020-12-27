#include <iostream>
#include <vector>
#include <string>

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

*/

int main()
{


    return 0;
}