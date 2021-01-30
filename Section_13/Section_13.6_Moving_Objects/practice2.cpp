#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "strClass.h"

/*
        | COPY-AND-SWAP ASSIGNMENT OPERATORS AND MOVE |
            Adding a move constructor to the HasPtr class, will effectively give it a move assignment operator as well:

            class HasPtr {
                HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) { p.ps = 0; }
                HasPtr& operator=(HasPtr rhs) {
                    swap(*this, rhs); return *this;
                }
            };

            The move constructor body sets p.ps to zero in order to ensure that it is safe to destroy the moved-from object.

            The assignment operator has a non-reference parameter, which means the parameter is copy-initialized. Depending
             on the type of argument, copy initialization uses either the copy or move constructor; lvalue copied, rvalues moved.
             Because of this, this single assignment operator acts as both the copy-assignment and move-assignment operator.

             hp = hp2;              // hp2 is an lvalue, copy constructor used to copy hp2;
             hp = std::move(hp2);   // hp2 is rvalue, move constructor moves hp2;

        ADVICE: UPDATING THE RULE OF THREE
            All 5 copy-control members should be thought of as a unit. If a class defines any, it should define all. Some class MUST
            define a copy constructor, copy-assignment operator, and destructor to work properly. Copying a resource entails overhead,
            defining a move constructor in these classes can avoid overhead in cases where copies are not needed.

        
*/


int main()
{


    return 0;
}