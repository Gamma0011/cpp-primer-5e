#include <iostream>
#include <vector>
#include <string>

/*
    || FUNCTION-CALL OPERATOR ||
        Classes that overload the function call operator allow objects of its type to be used as if they
         were a function. Because such classes can also store state, they can be more flexible than ordinary functions.

         ex. 
         struct absInt {
             int operator()(int val) const {
                 return val < 0 ? -val : val;
             }
         };

            see. void checkAbsInt();
        Even though absObj is an object, not a function, we can "call" this object. Calling an object
        runs its overloaded call operator. In this case, the operator takes an int value and returns
        its absolute value.

        *NOTE* The function-call operator MUST be a member function. A class may define multiple versions of the call operator,
                each of which must differ as to the number or types of their parameters.
        
        Objects of classes that define call operators are referred to as FUNCTION OBJECTS.

        | FUNCTION-OBJECT CLASSES WITH STATE |
            A function-object class can have additional members aside from operator(). Function-object classes
             often contain data members that are used to customize operations in the call operator.
            
            see. class PrintString;

            Function objects are most often used as arguments to the generic algorithms. For example, we can use the library for_each
             algorithm and our PrintString class to print contents of a container.
            
            std::for_each(vs.begin(), vs.end(), PrintString(std::cerr, '\n'));

                The 3rd argument to for_each is a temporary object of type PrintString that we initialize from cerr and a newline character.
                The call to for_each will print each element in vs to cerr followed by a newline


*/

struct absInt {
    int operator()(int val) const { return val < 0 ? -val : val; }
};

void checkAbsInt() {
    int i = -42;
    absInt absObj;
    int ui = absObj(i);
    std::cout << ui <<std::endl;
}

class PrintString {
public:
    PrintString(std::ostream &o = std::cout, char c = ' ') :
        os(o), sep(c) { };
    void operator()(const std::string &s) const { os << s << sep; }
private:
    std::ostream &os;       // stream on which to write
    char sep;               // character to print after each output
};

void printStringExample() {
    std::string s("Hello");
    PrintString printer;    // uses the defaults; prints to cout
    printer(s);             // prints s followed by a space on cout
    PrintString errors(std::cerr, '\n');
    errors(s);              // prints s followed by a newline on cerr
}


int main()
{
    printStringExample();


    return 0;
}