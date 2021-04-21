#include <iostream>
#include <vector>
#include <string>

/*
    e16.51  - Determine what sizeof...(Args) and sizeof...(rest) return for each call to foo in section.
                sizeof... returns how many arguments are in the pack itself.

    template<typename T, typename ... Args>
        void foo(const T& t, const Args& ... rest);

    int i = 0; double d = 3.14; std::string s = "Hello";
        foo(i, s, 42, d);       // 3 type parameters, 3 function parameters
        foo(s, 42, "hi");       // 3 type parameters, 2 function parameters
        foo(d, s);              // 2 type parameters, 1 function parameters
        foo("hi");              // 1 type parameter, 0 function parameters

    e16.52  - Write a program to check your answer to the previous question.
                see. void e1652();

        I got this wrong. I was right in thinking the declared function parameter wouldn't be used, but was 
         wrong in thinking that the declared type parameter (T) wouldn't be included and that int and 42 wouldn't cause a sizeof.. discrepency because of same type.

    e16.53  - Write your own version of print functions and test them by printing 1, 2, and 5 arguments of different types.
                see. void e1653();

*/

/************* e1652 *************/

template<typename T, typename ... Args>
void eval(const T& t, const Args& ... rest) {
    std::cout << "Template Parameters: " << sizeof...(Args) << std::endl;
    std::cout << "Function Parameters: " << sizeof...(rest) << std::endl;
}

void e1652() {
    int i = 10; double d = 3.14; std::string s("hello");

    eval(i, s, 42, d);       // 3 type parameters, 3 function parameters
    eval(s, 42, "hi");       // 2 type parameters, 2 function parameters
    eval(d, s);              // 1 type parameters, 1 function parameters
    eval("hi");              // 0 type parameter, 0 function parameters
}


/************* e1653 *************/

template<typename T>
std::ostream& print(std::ostream &os, const T &t) {
    return os << t;
}

template<typename T, typename ... Args>
std::ostream& print(std::ostream &os, const T &t, const Args& ... remainder) {
    os << t << '\t';
    return print(os, remainder...);
}

void e1653() {
    std::string s("hello"); int i = 42; double d = 4.322 ; float f = 9.009; char c = 'a';

    //print(std::cout, s);
    //print(std::cout, s, i);
    print(std::cout, s, i, d, f, c);
}

int main()
{
    //e1652();
    e1653();

    return 0;
}