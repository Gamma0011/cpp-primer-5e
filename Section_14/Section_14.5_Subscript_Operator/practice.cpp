#include <iostream>
#include <vector>
#include <string>
#include "strVecClass.h"

/*
    || SUBSCRIPT OPERATOR ||
        Classes that represent containers from which elements can be retrieved by position often
         define the subscript operator; operator[]

        *NOTE* The subscript operator MUST be a member function

        The subscript operator normally returns a reference to the element it fetched. By returning a &
         the subscript can be used on either side of an assignment. It is also a good idea to define both
         a const and nonconst version of the operator. When applied to a const object, subscript should
         return a const &, so it is not possible to assign returned object.
        
        *NOTE* If a class has operator[], it usually should define a & and const & version.

        class StrVec {
        public:
            std::string& operator[](std::size_t n) {
                return elements[n];
            }
            const std::string& operator[](std::size_t n) const {
                return elements[n];
            }
        private:
            std::string *elements;      // pointer to the first element in array
        };

        If the StrVec is nonconst, we can assign to element; if we subscript a const object, we can't.
*/

void subscriptOperator() {
    StrVec svec;       
    const StrVec cvec = svec;   // copy elements from svec to cvec
    if (svec.size() && svec[0].empty()) {
        svec[0] = "zero";       // subscript returns a & to a string
        //cvec[0] = "zip";        // error, cannot assign to const
    }
    std::cout << svec;
}


int main()
{
    subscriptOperator();
    return 0;
}
