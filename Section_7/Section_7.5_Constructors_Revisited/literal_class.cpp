#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;

/*  LITERAL CLASS

    - The data members all must have literal type;
    - The class must have at least one constexpr constructor;
    - If a data member has an in-class initializer, the initializer for a member of built-in type must be a const expression
        or if a member has a class type, the initializer must use the member's own constexpr construxtor
    - The class must use default definition for its destructor which is the member that destroys the class type
*/

class Debug {
public:
    constexpr Debug(bool b = true): hw(b), io(b), other(b) { }
    constexpr Debug(bool h, bool i, bool o): hw(h), io(i), other(o) { }
    constexpr bool any() const { return hw || io || other; }            // member functions that do not modify class instance should be declared const
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hw = b; }
    void set_other(bool b) { other = b; }
private:
    bool hw;        // hardwre errors other than IO errors
    bool io;        // IO errors
    bool other;     // other errors
};


int main()
{
    constexpr Debug io_sub(false, true, false);     // debugging IO
    if (io_sub.any()) {      // == if(true)
        std::cerr << "Print appropriate error messages" <<endl;
    }

    constexpr Debug prod(false);        // no debugging during production
    if (prod.any()) {      // == if(false)
        std::cerr << "Print an error message" <<endl;
    }

    return 0;
}
