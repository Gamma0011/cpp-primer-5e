#include <iostream>
#include <vector>
#include <string>

/*
    || INCREMENT AND DECREMENT OPERATORS ||
        (++) and (--) are most often implemented for iterator classes. These operators let the class move between elements
         of a sequence. There is no language requirement that these operators be members of the class. However, because
         these operators change state of objects, our preference is to make them members.

        *NOTE* Classes that define increment and decrement operators should define both prefix and postfix versions, all
        * defined as members.
        
        | Defining Prefix Increment/Decrement Operators |
            see. StrBlobPtr& operator++(); StrBlobPtr& operator--(); in strBlobPtrClass.h

            ex. StrBlobPtr& operator++() {
                    check(curr, "Increment Past End of StrBlobPtr");
                    ++curr;
                    return *this;
                }

            * To be consistent with the built-in operators, the prefix operators should return a &
            *   to the incremented or decremented object.
        
        | DIFFERENTIATING PREFIX AND POSTFIX OPERATORS |   
            There is one problem defining both prefix and postfix operators:
             Normal overloading cannot distinguish between these. The prefix and postfix versions
              use the same symbol, meaning that the overloaded versions have the same name. They also
              have the same number and type of operands.
            
            To solve this, the postfix versions take an extra (unused) parameter of type int. When we use a postfix
             operator, the compiler supplies 0 as the argument. Although the operator can use this extra parameter, 
             it normally should not. 

            *NOTE* int parameter not needed for anything other than to distinguish postfix from prefix versions of incr/decr operators

            see. StrBlobPtr operator++(int); StrBlobPtr operator--(int); in strBlobPtrClass.h

            * To be consistent with the built-in operators, the postfix operators should return old (unincremented or undecremented) value.
            * The value returned is a value, not a reference.
            
            ex. StrBlobPtr operator++(int) {
                    StrBlobPtr ret = *this;
                    ++*this;                // calls prefix++ to do validity check and increase state
                    return ret;             // return saved state
                }

            Each of our operators calls its own prefix version to do the actual work when the postfix increment operator calls ++*this;
             This expression calls the prefix increment operator, which checks that the increment is safe and either throws an exception,
             or increments curr. Assuming check doesn't throw an exception, the postfix function returns the stored copy in ret.

            *NOTE* The int parameter is not used, so we do not give it a name.

        | CALLNG THE POSTFIX OPERATORS EXPLICITLY | 


*/


int main()
{

    return 0;
}