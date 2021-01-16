#include <iostream>
#include <vector>
#include <string>

/*
    | THE DESTRUCTOR |
        The destructor operates inversely to the constructors: 
            - Constructors initialize the nonstatic data members of an object and may do other work.
            - Destructors do whatever work is needed to free the resources used by an object and destroy the nonstatic data members of the object.

            The destructor has no return value and takes no parameters:

                ~Foo();     // destructor

        A constructor initializes members in the same order in which they appear in the class. A destructor destroys members in reverse order.
         The function body of a destructor does whatever operations the class designer wishes to have executed subsequent to the last use
         of an object. Typically, the destructor frees resources it allocated during its lifetime.

        There is no initializer list to control how members are destroyed as the destruction is implicit. What happens when a member is destroyed
         depends on the type of the member. Members of class type are destroyed by running the member's own destructor. The built-in types do no have
         destructors, so nothing is done to destroy members of built-in type.

        **NOTE** The implicit destruction of a member of built-in pointer type does not delete the object to which the pointer points.

        Unlike ordinary pointers, the smart pointers are class types and have destructors. Members that are smart pointers are automatically
         destroyed during the destruction phase.

        | WHEN A DESTRUCTOR IS CALLED |
            The destructor is used automatically whenever an object of its type is destroyed:
                - Variables are destroyed when they go out of scope.
                - Members of an object are destroyed when the object of which they are a part of is destroyed.
                - Elements in a container, whether library or an array, are destroyed when container is destroyed.
                - Dynamically allocated objects are destroyed when the delete operator is applied to a pointer to the object.
                - Temporary objects are destroyed at the end of the full expression in which the temporary was created.
        
        Because destructors are run automatically, our programs can allocate resources and usually not worry about when those resources are released.

        **NOTE** The destructor is NOT run when a reference or a pointer to an object goes out of scope.

        | THE SYNTHESIZED DESTRUCTOR |
            The compiler defines a synthesized destructor for any class that does no define its own destructor. In some classes, a synthesized destructor
             disallows objects of the type from being destroyed. Otherwise, the synthesized destructor has an empty function body.

            ~Sales_data() { };

            Members are automatically destroyed after the (empty) destructor body is run. The destructor body does not directly destroy the members
             themselves. Members are destroyed as part of the implicit destruction phase following the destructor body. The destructor body is executed
             IN ADDITION to the memberwise destruction that takes place as part of destroying the object.

*/

class Test {
public:
    Test();                             // Default Constructor
    Test(const Test&);                  // Copy Constructor
    Test& operator=(const Test &orig);  // Copy-Assignment Operator
    ~Test() { };                            // Destructor
private:
    std::string s;
    int i;
};

int main()
{


    return 0;
}