#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "strClass.h"
#include "strVecClass.h"

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


        || RVALUE REFERENCES AND MEMBER FUNCTIONS ||
            Member functions other than constructors and assignment operators can benefit from providing both copy and move versions. 
            Move-enabled members typically use the same paramter patter as the copy/move constructor and assignment operators.
                - One version takes an lvalue reference to const
                - Second version takes rvalue reference to nonconst.

                    void push_back(const X&);   // copy: binds to any kind of X
                    void push_back(X&&);        // move: binds only to modifiable rvalues of type X
                
                In the copy version, we can pass any object that can be converted to type X.
                In the move version, we can only pass an rvalue that is not a const. This version will be run when 
                 we pass a modifiable rvalue (std::move(X))

            Ordinarily, there is no need to define versions of the operation that take a const X&& or nonconst X&. We normally
             pass an rvalue reference when we want to "steal" from the argument. To do so, the arg must NOT be const.
             Additionally, we shouldn't ever change the object being copied, so there is no need to define a nonconst &;
            
            *NOTE* Overloaded functions that distinguish between moving and copying parameters typically have two versions
                *1 const T&
                *2 T&&
        
        || RVALUE AND LVALUE REFERENCE MEMBER FUNCTIONS ||
            In order to maintan backwards compatability, the library classes continue to allow assignment to rvalues. However,
             we might want to prevent such usage in our classes. We can force a left-hand operand (object to which this points) 
             to be an lvalue.  

                see class Foo;

            The reference qualifier can be either & or &&, indicating this may point to an rvalue or an lvalue
                Foo &retFoo();      // returns a reference; a call to retFoo is an lvalue
                Foo retVal();       // returns a value; a call to retVal is an rvalue
                Foo i, j;           // lvalues
                i = j;              // ok: i is lvalue
                retFoo() = j;       // ok: retFoo returns lvalue
                retVal() = j;       // error: retVal returns rvalue
                i = retVal();       // ok: can pass rvalue as right-hand operand to assignment

            Additionally, a function can be both const and reference qualified:
                Foo someMem() const &;

        || OVERLOADING AND REFERENCE FUNCTIONS ||
            Just as we can overload a member function based on constness, we can also overload based on & qualifier and if it is const.

            see.
                Foo sorted() &&;            // rvalue
                Foo sorted() const &;       // lvalue

            When we sort an rvalue, it is safe to sort the data because an rvalue has no other users. 
            When running sort on a const or lvalue, we must copy the data before sorting.

            Overload resolution uses the lvalue/rvalue property of the object that calls sorted to determine which version is used:
                retVal().sorted();      // retVal() is an rvalue; calls Foo sorted() &&;
                retFoo().sorted();      // retFoo() is lvalue; calls Foo sorted() const &;
            
            *NOTE* If a member function has a reference qualifier, all versions of that member with the same parameter must have reference qualities.
                    ex. 'Foo sorted() &&' means the lvalue const must be 'Foo sorted() const &';

*/

class Foo {
public:
    Foo &operator=(const Foo&) &;     // may assign only to modifiable lvalues
    Foo someMem() const &;

    Foo sorted() &&;
    Foo sorted() const &;
private:
    std::vector<int> data;
};

Foo &Foo::operator=(const Foo&rhs) & {
    // do whatever is needed to assign rhs to this object
    return *this;       // this points to an lvalue
}

// this object is an rvalue, so we can sort in place
Foo Foo::sorted() && {
    std::sort(data.begin(), data.end());
    return *this;
}   

// this object is const or lvalue, we cannot sort in place
Foo Foo::sorted() const & {
    Foo ret(*this);                                 // make a copy
    std::sort(ret.data.begin(), ret.data.end());    // sort the copy
    return ret;                                     // return the copy
}


/**************************************/

void strVecTest() {
    StrVec vec;     // empty StrVec
    std::string s = "Hello World";
    vec.push_back(s);               // calls push_back(const std::string &s);
    vec.push_back(std::move(s));    // calls push_back(std::string &&s);
    vec.push_back("HELLO");         // calls push_back(std::string &&s);
}


int main()
{
    strVecTest();

    return 0;
}