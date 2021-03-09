#include <iostream>
#include <vector>
#include <string>
#include "e1520.h"
#include "graphical_file_formats.h"

/*
    e1518   - Given the classes from 612 and 613, determine which of these assignments are legal. Which are illegal and why?

            RULE:
                - User code may use derived-to-base conversion ONLY IF D inherits publicly from B.

        Base *p = &d1;      // d1 has type Pub_Derv                 // legal
        p = &d2;            // d2 has type Priv_Derv                // illegal - User code may use derived-to-base conversion ONLY IF D inherits publicly from B
        p = &d3;            // d3 has type prot_derv                // illegal - User code may use derived-to-base conversion ONLY IF D inherits publicly from B
        p = &dd1;           // dd1 has type Derived_from_Public     // legal
        p = &dd2;           // dd2 has type Derived_from_Private    // illegal - User code may use derived-to-base conversion ONLY IF D inherits publicly from B
        p = &dd3;           // dd3 has type Derived_from_Protected  // illegal - User code may use derived-to-base conversion ONLY IF D inherits publicly from B

    e15.19  - Assume each of the classes from 612 and 613 has a member function of the form:
                void memfcn(Base &b) { b = *this; }
            For each class, determine whether this function is legal.

                RULES:
                    - Member functions and friends of D can use conversion to B regardless of how D inherits from B.
                    - Member functions and friends of classes derived from D may use derived-to-base conversion if D inherits from B using either PUBLIC or PROTECTED.

            Class Base - legal.
            Class Sneaky - legal.
            struct Pub_Derv - legal.
            struct Priv_Derv - legal.
            struct Derived_from_Public - illegal. derived class inherits from Public
            struct Derived_from_private - illegal. Derived class inherits from Private.

    e15.20  - Write code to test your answers to the previous two exercises
                see. e1520.h && void e1520();

    e15.21  - Choose one of the following general abstractions containing a family of types, organize into an inheritance hierarchy.
                a) Graphical file formats   - see graphical_file_formats.h
    
    e15.22  - For the class you chose, identify some of the likely virtual functions as well as public and protected members  
*/

void e1520() {
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Protected dd3;
    

    Base *p = &d1;      // d1 has type Pub_Derv                 // legal
    //p = &d2;            // d2 has type Priv_Derv                // illegal - User code may use derived-to-base conversion ONLY IF D inherits publicly from B
    //p = &d3;            // d3 has type prot_derv                // illegal - User code may use derived-to-base conversion ONLY IF D inherits publicly from B
    p = &dd1;           // dd1 has type Derived_from_Public     // legal
    //p = &dd2;           // dd2 has type Derived_from_Private    // illegal - User code may use derived-to-base conversion ONLY IF D inherits publicly from B
    //p = &dd3;           // dd3 has type Derived_from_Protected  // illegal - User code may use derived-to-base conversion ONLY IF D inherits publicly from B

}

void get_info(Graphical_File &f, std::ostream &os) {
    f.print(os);
}

int main()
{
    GIF g1("test.gif", 12, 300, 300, 4);
    JPEG j1("mountains.jpeg", 3, 1920, 1080, 90);
    get_info(g1, std::cout);
    std::cout <<std::endl;
    get_info(j1, std::cout);

    

    return 0;
}