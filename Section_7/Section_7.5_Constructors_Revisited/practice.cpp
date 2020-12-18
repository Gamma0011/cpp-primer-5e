#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;

class ConstRef {
public:
    ConstRef(int ii);
private:
    int i;
    const int ci;
    int &ri;
};

/* omitting a constructor initializer for members ci and ri is an error
ConstRef::ConstRef(int ii) {
    i = ii;     // okay
    ci = ii;    // error cannot assign to a const
    ri = i;     // error ri was never initialized
}
*/

// by the time the body of the constructor begins executing, initialization is complete.
// we must initialize const or & members via constructor initializer
ConstRef::ConstRef(int ii): i(ii), ci(ii), ri(ii) { };
// **NOTE** we must use the constructor initializer list to provide values for const, & or members of a class type that do not have a default constructor
// to be efficient, use constructor initializers whenever possible - initializes directly without needing to add additional lines of code


// ORDER OF MEMBER INITIALIZATION
// While no error is thrown, i is initialized to the undefined value of j. This is because of the order in which members are initialized;
// **NOTE** It is always good practice to initialize members in the order in which they were declared and to NEVER use members to initialize other members
class X {
private:
    int i;
    int j;
public:
    // X(int val): j(val), i(j) { };
    //  This is better!
    X(int val): i(val), j(val) { };
};

int main()
{


    return 0;
}
