#include <iostream>
#include <vector>
#include <string>
#include "strBlobClass.h"
#include "strBlobPtrClass.h"

/*
    || MEMBER ACCESS OPERATORS ||
        The dereference (*) and arrow (->) operators are often used in classes that represent iterators and in smart pointer
         classes. We can logically add them to 
         our StrBlobPtr class as well:

         see. strBlobPtrClass.h
            std::string& operator*() const;
            std::string* operator->() const;

            std::string& StrBlobPtr::operator*() const {
                auto e = check(curr, "Dereference past end");
                return (*e)[curr];
            }
            std::string* StrBlobPtr::operator->() const {
                return & this->operator*();
            }

        The dereference operator checks that curr is still in range, and if so, returns a reference to the element denoted by curr.
        The arrow operator avoids doing work of its own by calling dereference operator and returning address of
         the element returned by that operator.
        
        *Note* operator->() MUST be a member. operator*() is not required to be a member, but usually should

        It is worth noting that we defined these operators as const members. Unlike increment and decrement, fetching elements
         does not change the state of StrBlobPtr. Also, these operators return a reference or a pointer to a nonconst string.
         We do this because StrBlobPtr can only be bound to a nonconst StrBlob
        
        | CONSTRAINTS ON THE RETURN FROM OPERATOR ARROW |
            As with most other operators, we can define operator* to do whatever we'd like, even though that is not best practice.
            However, operator-> never loses its fundamental meaning of member access. When we overload operator-> we change the object
             from which arrow fetches the specified member. We cannot change the fact that arrow fetches a member.
            
            When we write point->mem, point must be a pointer to a class object or must be an object of class with overloaded operator->
                (*point).mem;           // point is a built-in pointer type
                point.operator()->mem;             // point is an object of class type
            
            point->mem executes as follows:
            1) If point is a pointer, then built-in arrow is applied, which means expression is synonym for (*point).mem.
            2) If point is object of class that defines operator->, point.operator()->mem used to fetch mem. If the result
                is an object that itself has an overloaded operator->(), then this step is repeated on that object and continues
                until either a pointer to an object with member is returned or other value returned (in error).
            
            *Note* The overloaded arrow operator MUST return either a pointer to a class type or an object of a class type
             that defines its own operator->
             
*/

void memberAccessPractice() {
    StrBlob a1 = {"hi", "bye", "now"}; 
    StrBlobPtr p(a1);                   // p points to the vector inside of a1
    *p = "okay";                        // assigns to the first element of a1
    std::cout << p->size() <<std::endl; // prints 4, the size of the first element in a1
    std::cout << (*p).size() <<std::endl;   // equivalent to p->size();
}

int main()
{
    memberAccessPractice();

    return 0;
}