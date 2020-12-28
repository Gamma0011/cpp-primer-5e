#include <iostream>
#include <vector>
#include <string>
#include <memory>

/*
    | USING NEW TO DYNAMICALLY ALLOCATE AND INITIALIZE OBJECTS |
        The language itself defines two operators that allocate and free dynamic memory. 
            new     - allocates memory
            delete  - frees memory allocated by new
    
        Classes that do not manage their own memory - unlike those that use smart pointers - cannot
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


int main()
{


    return 0;
}