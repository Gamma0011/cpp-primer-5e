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

        
    || MOVE ITERATORS ||
        The new library defines a MOVE ITERATOR adaptor. A move iterator adapts its given iterator by changing the behavior of the iterator's
         dereference operator. Normally, an iterator dereference operator returns an LVALUE reference to the element. Dereferencing a MOVE
         ITERATOR returns an RVALUE reference instead.

         From the StrVec example, we can place MOVE ITERATORS in our void reallocate() function.
            auto last = uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), first);

            Because we've passed move iterators, the dereference operator yields an rvalue reference, which means CONSTRUCT
            will use move constructor to construct the elements. Because moving the object can destroy the source, you should 
            only pass move iterators to algorithms when you are confident that the algorithm dos not access an element 
            after it has assigned to that element or passed that element to a user-defined function.

        || ADVICE: DON'T BE QUICK TO MOVE ||
            Because a moved-from object has an indeterminate state, calling std::move on an object is a dangerous operation.
            We MUST be certain there are no other users of the moved-from object. Used within class code, move can offer
            massive performance benefits. However, using in user code (instead of class implementation code) can lead to 
            hard-to-find bugs.

            *BEST PRACTICE*
            Outside of class implementation of code such as move constructors or move-assignment operators, use std::move only
            when you are certain that you need to do a move and that move is guaranteed to be safe.
*/


int main()
{

    return 0;
}