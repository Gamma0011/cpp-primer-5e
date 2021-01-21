#include <iostream>
#include <vector>
#include <string>

/*
    || SWAP ||
        In additional to defining the copy-control members, classes that manage resources often also define a function
         called swap. Defining swap is particularly important for classes that we plan to use with algorithms that
         reorder elements. These algorithms call swap when they need to change two elements.

        The swap function is defined by the library, unless defined within the class.

        Although we don't know how swap is implemented, conceptually it involves a copy and 2 assignments.

            Example (Values):
                HasPtr temp = v1;       // make temporary copy of value of v1
                v1 = v2;                // assign the value of v2 to v1
                v2 = temp;              // assign the saved value of v1 to v2

            Example (Pointers):
                string *temp = v1.ps;   // make a temporary copy of the pointer in v1.ps
                v1.ps = v2.ps;          // assign the pointer in v2.ps to v1.ps
                v2.ps = temp;           // assign the saved pointer in v1.ps to v2.ps

        | WRITING OUR OWN SWAP FUNCTION |
            We can override the default behavior of swap by defining a version that operates on our class.

            see class HastPtr && void swap;

            We start by declaring swap as a friend and give it access to HasPtr's private data members. Because swap
             exists to optimize our code, we've defined swap as an inline function. The body of swap calls swap on each
             of the data members of the object.

            **NOTE** Unlike the copy-control members, swap is never necessary. However, defining swap can be an important
             optimization for classes that allocate resources.

        | SWAP FUNCTIONS SHOULD CALL SWAP, NOT STD::SWAP |
            It is essential that swap functions all swap and not std::swap. std::swap calls the library version of swap and not the
             one defined for that particular object.

             Correct Usage!!
                void swap(HasPtr &lhs, HasPtr &rhs) {
                    using std::swap;
                    swap(lhs.ps, rhs.ps);
                    swap(lhs.i, rhs.i);
                }

        | USING SWAP IN ASSIGNMENT OPERATORS |
            Classes that define swap often use swap to define their assignment operator. These operators use a technique called COPY AND SWAP.
             The left-hand operand is swapped with a copy of the right-hand operand.

            
            HasPtr& operator=(HasPtr rhs) {     // rhs passed by value. Copy constructor copies string in right-hand operand into rhs.
                swap(*this, rhs);               // rgs now points to memory this object had used.
                return *this;                   // rhs is destroyed, which deletes pointer to rhs
            }

        **Assignment operators that use copy and swap are automatically exception safe and correctly handle self-assignment.

*/

class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);

    HasPtr& operator=(HasPtr rhs) {
        swap(*this, rhs);
        return *this;
    }

private:
    std::string *ps;
    int i;
};

void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);       // swap pointers (not string data)
    swap(lhs.i, rhs.i);         // swap ints
}


int main()
{

    return 0;
}