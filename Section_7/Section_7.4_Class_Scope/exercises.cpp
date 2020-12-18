#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;

/*
    e733 - What would happen if we gave Screen a size member defined as follows? Fix any problems
        pos Screen::size() const { return height * width; }

        Since size() is declared and defined within Screen, no scope resolution operator needed
            pos size() const { return height * width; }

        If we were to define outside the scope of screen, here's how we'd write it:
            Screen::pos Screen::size() const { return heigh * width; }

    e734 - What would happen if we put typedef of pos in the Screen class on pg 285 as the last line in class?
        error thrown, pos does not name a type and has not been declared before use

    e735 - Explain the following code, indicating which definition of Type or initVal is used for each of those names. Say how you'd fix errors.

typedef string Type;    // alias: string == Type
Type initVal();         // initVal() is function with return type string
class Exercise {
public:
    typedef double Type;    // alias: double == Type (within scope of Exercise class)
    Type setVal(Type);      // setVal accepts argument of type double and returns double
    Type initVal();         // initVal() function within class Exercise returns double
private:
    int val;
};

/*
Type Exercise::setVal(Type parm) {  
    // this will have an error. Type is of global scope, returning type String, 
    // while setVal() within class Exercise has return type double
    val = parm + initVal();
    return val;
}


// fixed
Exercise::Type Exercise::setVal(Type parm) {   // double Exercise::setVal(double parm)
    val = parm + initVal();                     // int = double + double
    return val;
}


*/


int main()
{


    return 0;
}
