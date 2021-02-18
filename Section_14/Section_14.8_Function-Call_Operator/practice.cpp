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

    || LAMBDAS ARE FUNCTION OBJECTS ||
        When we write a lambda, the compiler translates that expression into an unnamed object of an unnamed class. 
         The classes generated from a lambda contain an overloaded function-call operator.

         ex. the lambda that we passed as the last argument to stable_sort:
            
                stable_sort(words.begin(), words.end(),
                            [](const string &a, const string &b) { return a.size() < b.size(); });
            ACTS LIKE
                class ShorterString {
                public:
                    bool operator()(const string &s1, const string &s2) const { return s1.size() < s2.size(); }
                };
            
        The generated class has a single member, which is a function-call operator that takes 2 strings and compares length. The
         parameter list and function body are the same as the lambda. Lambdas may not change captured variables. As a result, 
         by default, the function-call operator in a class generated from lambda is a const member function. 
        
        If the lambda is declared as mutable, then the call operator is not const. 

        We can rewrite stable_sort to use this class instead of a lambda.

            ex. stable_sort(words.begin(), words.end(), ShorterString());
        
        | CLASSES REPRESENTING LAMBDAS WITH CAPTURES |
            When a lambda captures a variable by reference, it is up to the program to ensure that the variable to which the reference refers
             exists when the lambda is executed. The compiler is permitted to use the reference directly without storing that reference
             as a data member in the generated class.

            In contrast, variables captured by value are copied into the lambda. Classes generated from lambdas that capture variables by value
             have data members corresponding to such variable. 

             *This lambda:
                auto wc = find_if(words.begin(), words.end() [sz](const string &a))
             *Generates a class like this:
                class SizeComp {
                public:
                    SizeComp(size_t n): sz(n) { } // parameter for each captured variable
                    // call operator with the same return type, parameters, and body as lambda
                    bool operator()(const string &s) const { return s.size() > sz; }
                private:
                    size_t sz;      // a data member for each variable captured by value
                }
            * To use this class, we must pass an argument:
                auto wc = find_if(words.begin(), words.end(), SizeComp(sz));

            Classes generated from a lambda expression have a deleted default constructor, deleted assignment operator,
             and a default destructor. Copy/Move constructors depends on types of captured data members.
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