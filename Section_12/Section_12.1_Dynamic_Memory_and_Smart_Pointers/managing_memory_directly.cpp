#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <new>

/*
    | USING NEW TO DYNAMICALLY ALLOCATE AND INITIALIZE OBJECTS |
        The language itself defines two operators that allocate and free dynamic memory. 
            new     - allocates memory
            delete  - frees memory allocated by new
    
        Classes that do not manage their own memory and - unlike those that use smart pointers - cannot
         rely on the default definitions for the members that copy, assign and destroy class objects. As
         a result, programs that use smart pointers are likely to be easier to write and debug.
        
        Objects allocated on the free store are unnamed, so new offers no way to name the objects that it allocates.
         Instead, new returns a pointer to the object it allocates.
            int *pi = new int;      // pi points to a dynamically allocated unnamed, uninitialized int

            By default, dynamically allocated objects are default initialized, meaning that objects of built-in or 
            compound type have undefined value; objects of class type are intialized by their default constructor.

            We can initialize a dynamically allocated object using direct initialization via traditional construction (using
            parentheses) and by list initialization {using curly braces}.

            **NOTE** It is a good idea to initialize dynamically allocated objects.

        When we provide an initializer inside parentheses, we can use auto to deduce the type of the object we want to allocate.
         Because the compiler uses the initializer's type to deduce auto, we can only use a single initializer inside parentheses.

         auto p1 = new auto(obj);       // p points to an object of the type obj. p1 initialized from obj
                                        // if obj is int, p1 is int* p1
         auto p2 = new auto{a,b,c};     // error: must use parentheses for the initializer

        | DYNAMICALLY ALLOCATED CONST OBJECTS |
            It is legal to use new to allocate const objects:

                const int *pci = new const int(1024);               // allocate and initialize const int
                const std::string *pcs = new const std::string;     // allocate a default-initialized const empty string

        | MEMORY EXHAUSTION | 
            Although unlikely, there's a chance that a program can use all of its available memory, causing the new expression to fail.
             If new is unable to allocate the requested storage, it throws an exception of type bad_alloc. To prevent this, we can
             use another form of new:

                // if allocating fails, new returns a null pointer
                int *p1 = new int;              // if allocation fails, std::bad_alloc
                int *p2 = new (nothrow) int;    // if allocation fails, new returns a null pointer

            This form of new is referred to as PLACEMENT NEW. A placement new expression lets us pass additional
             arguments to new. When we pass nothrow to new, we tell new that it must not throw an exception. Both
             bad_alloc and nothrow are defined in the <new> header

        | FREEING DYNAMIC MEMORY |
            To prevent memory exhaustion, we must return dynamically allocated memory to the system once we are finished
             using it. We return memory via a DELETE expression. The delete expression takes a pointer to the object we want to free.

             ex. delete p;      // p must point to a dynamically allocated object or be null

             Delete destroys object to which its given pointer points and frees corresponding memory.
            
            Compilers will generate errors for delete when it's not deleting a pointer. One thing to note however is that a compiler
             cannot differentiate between a statically allocated and a dynamically allocated object. Technically, you CAN delete
             a static pointer, but this is ACTUALLY in error. Only dynamically allocated objects should be deleted with delete.

            see. void ptrValuesDelete()

                In error:       delete pi1;     // int *p1 = int &i
                Correct:        delete pi2;     // int *pi2 = new int(33);
        
            | DYNAMICALLY ALLOCATED OBJECTS EXIST UNTIL THEY ARE FREED |
                Unlike memory managed via shared_ptr, memory we manage using built-in pointers is not automatically deleted
                 when the last shared_ptr is destroyed. A dynamic object managed through a built-in pointer exists until it
                 is explicitly deleted.
                
                Functions that return pointers (rather than smart pointers) to dynamic memory put a burden on their callers
                 as the caller must remember to delete the memory

                 For example:
                    Foo* factory(T arg) { return new Foo(arg); } // caller responsible for deleting returned memory
                    void use_factory(T arg) { Foo *p = factory(arg); } // use p, but do not delete
                                                                        // p out of scope, but memory to which p points still not free.

                 Fixed:
                    void use_factory(T arg) { Foo *p = factory(arg); delete p; }
                        or, if other code in our system needs to use object allocated, we can have the function return a pointer to
                            the memory it allocated
                    Foo* use_factor(T arg) { Foo *p = factor(arg); return p; }  // caller must delete memory

            ** CAUTION: MANAGING DYNAMIC MEMORY IS ERROR-PRONE **
            3 common problems with using new and delete:
                1. Forgetting to delete memory. Neglecting to delete memory is known as a "memory leak".
                2. Using an object after it has been deleted.
                3. Deleting the same memory twice.

            ** BEST PRACTICE ** Use smart pointers exclusively.
*/

void usingNew() {
    int *pi = new int;                  // pi points to an uninitalized int
    std::string *ps = new std::string;  // initialized to empty string  

    // initialization via direct and list initialization

    int *pi1 = new int(1024);                       // object to which pi1 points has value 1024
    std::string *ps1 = new std::string(10, '9');    // *ps1 == "9999999999"
    // vector with 10 elements with values 0-9
    std::vector<int> *pv = new std::vector<int>{0,1,2,3,4,5,6,7,8,9};

    // value initialization 
    std::string *ps2 = new std::string;             // default initialized to the empty string
    std::string *ps3 = new std::string();           // value initialized tp empty string
    int *pi3 = new int;                             // default initialized. *pi3 undefined
    int *pi4 = new int();                           // value initialized to 0. *pi4 = 0

}

void ptrValuesDelete() {
    int i, *pi1 = &i, *pi2 = nullptr;
    double *pd = new double(33), *pd2 = pd;

    //delete i;       // error: i is not a pointer
    delete pi1;     // undefined: pi1 refers to a local
    delete pd;      // ok
    delete pd2;     // undefined: the memory pointed to by pd2 was already freed
    delete pi2;     // ok: it is always okay to delete a null pointer

    // a const dynamic object is freed by executing delete on a pointer that points to an object
    const int *pci = new const int(1024);
    delete pci;                             // ok: deletes a const object

}

int main()
{


    return 0;
}