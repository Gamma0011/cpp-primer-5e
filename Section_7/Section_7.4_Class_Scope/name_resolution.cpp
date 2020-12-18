#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;

int height;         // defines a name subsequently used inside Screen

class Screen {
public:
    typedef std::string::size_type pos;
    void setHeight(pos);
    pos height = 0;         // hides the declaration of height in the outer scope
};

Screen::pos verify(Screen::pos);        // function of return type pos (std::string::size_type)

void Screen::setHeight(pos var) {
    // var: refers to the parameter
    // height: refers to the class member
    // verify: refers to the global function
    height = verify(var);
}

int main()
{


    return 0;
}
