#include <iostream>
#include <vector>
#include <string>

/*
    When we define a class, we specify what happens when objects of the class type are copied, moved, assigned, and destroyed. A class controls these
     operations by defining 5 special member functions:
        1. Copy constructor
        2. Copy-assignment operator
        3. Move constructor
        4. Move-assignment operator
        5. Destructor

    COPY and MOVE constructors define what happens when an object is initialized from another object of the same type. 
    COPY- and MOVE-ASSIGNMENT operators define what happens when we assign an object of class type to another object of that same class type.
    DESTRUCTOR defines what happens when an object of the type ceases to exist.

    Collectively, we refer to these operations as COPY COMMAND.

    If a class does not define all copy-control members, the compiler automatically defines the missing operations. As a result, many classes
     ignore copy control. Sometimes not defining can lead to issues. The hardest part is knowing when to define them.

     Copy control is an essential part of defining any C++ class. Programmers new to C++ are often confused by having to define what happens when objects
      are copied, moved, assigned, or destroyed. This confusion is compounded because if we do not explicitly define these operations, the compiler
      defines them for us - although the compiler-defined versions might not behave as we intend.

*/

int main()
{

    return 0;
}