#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

// ** NOTE** BEST PRACTICE
// Default arguments ordinarily should be specified with the function declaration in the appropriate header.

typedef string::size_type sz;           // typedef
string screen(sz ht = 24, sz w = 80, char background = ' ');
// here we've provided a default for each parameter and is specified as an initalizer for a parameter in the parameter list


// it is legal to redeclare functions multiple times, however, default parameters can only be declared one
// additionally, defaults can only be defined if parameters to the right already have defaults

// no default for h or w parameters
string screen1(sz, sz, char = ' ');

// error: redeclaration
// string screen1(sz, sz, char = '*');

// however, we can add default arguments
string screen1(sz = 24, sz = 80, char);     // okay, adds default arguments to sz and sz



// DEFAULT ARGUMENT INITALIZERS
// local variables may not be used as default arguments.
// a default argument can be any expression that has a type that is convertihle to the type of the parameter (as we saw with string::size_type '?')
sz wd = 80;
char def = ' ';
sz ht();
string screen2(sz = ht(), sz = wd, char = def);
string window = screen2();                           // calls screen(ht(), 80, ' ');


// names used as default arguments are resolved in the scope of the function declaration. 
// the value that those names represent is evaluated at the time of the call
void f2()
{
    def = '*';          // changes value of a default argument
    sz wd = 100;        // THIS IS A DECLARED VARIABLE OF LOCAL SCOPE -- hides the outer definition of wd, but does not change the default;
    window = screen()); // calls screen(ht(), 100, '*');



}

int main()
{
    // if we want to use default arguments, we omit that argument when we call the function.
    // because screen provides defaults for all its paramters, we can call screen with 1, 2, or 3 arguments:
    string window;
    window = screen();              // == screen(24, 80, ' '); default args
    window = screen(66);            // == screen(66, 80, ' '); 
    window = screen(66, 256);       // == screen(66, 256, ' ');
    window = screen(66, 256, '#');  // == screen(66, 256, '#');

    // arguments in the call are resolved by position. To pass an argument for char background, we must also supply args for ht and w
    // window = screen( , , '#')        // error, cannot omit only trailing arguments

    // this technically is legal
    window = screen('?');               // this passes ? to the first argument, in this case ht || screen(63, 80, ' ');
    // because ht is of type string::size_type, which is an unsigned integral type, the char argument is implicitly converted to string::size_type
    // '?' has a hexadecimal value of 0x3F, which is decimal 63, therefore 63 is passed to ht;

    return 0;
}
