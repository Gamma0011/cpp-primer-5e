#include <iostream>
#include <vector>
#include <string>
#include <memory>

/*
    | PREVENTING COPIES |
        BEST PRACTICE - Most classes should define, either implicitly or explicitly, the default and copy constructors, and the copy-assignment operator.

        Although most classes should (and usually do) define a copy constructor and a copy-assignment operator, for some classes, 
         there is really no meaning for these operations. In such cases, the class must be defined tso as to prevent copies or assignments
         from being made.

        For example, the iostream classes prevent copies to avoid letting multiple objects write to or read from the same IO buffer. No definting the 
         copy-control members is not a solution as the compiler will synthesize them.

        We can prevent copies by defining the copy constructor and copy-assignment operator as deleted functions. A deleted function is one
         that is declared but may not be used in any other way. This is indicated by = delete.

            see. struct NoCopy;

        = delete signals that we are intentionally not defining these members. 
         Unlike (= default), (= delete) must appear at the first declaration of the function. The compiler needs to know that a function is deleted
         in order to prohibit operations that attempt to use it. 

        Also, unlike (= default), which can only be used on default constructor and copy-control members, (= delete) can be specified on any function.

        | THE DESTRUCTOR SHOULD NOT BE A DELETED MEMBER |


*/

struct NoCopy {
    NoCopy() = default;                             // use synthesized default constructor
    NoCopy(const NoCopy &) = delete;                // no copy;
    NoCopy& operator=(const NoCopy&) = delete;      // no assignment;
    ~NoCopy() = default;                            // use synthesized default destructor
};


int main()
{


    return 0;
}