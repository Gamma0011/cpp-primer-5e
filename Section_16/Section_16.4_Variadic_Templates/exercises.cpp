#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include "vec.h"
#include "strVecClass.h"
#include "shared_ptr.h"

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

    e16.54  - What happens if we call print on a type that doesn't have a << operator?
                Compiler will return an error "no match for operator<<"
    
    e16.55  - Explain how the variadic version of print would execute if we declared a nonvariadic version of print after the definition of a variadic function
                Compiler will call an error on not being about to find print(os, const T&) because it's used before declaration.
                    'error: no matching function for call to 'print(std::ostream&)'
                        return print(os, remainder...);

    e16.56  - Write and test a variadic version of errorMsg.

    e16.57  - Compare your variadic version of errorMsg to the error_msg function on pg 220. What are the advantages and disadvantages of each?

                    Pg. 220 works well when you know that a stream of error codes will be written into and read from an initializer list.
                    However, in the case where there might be multiple different types of returns, a variadic version would allow for this functionality.

                    I do think that the error_msg function is a bit more readable because there's more explicit statements in what is being done, as opposed to
                    a template type where types are unknown.

    e16.58  - Write emplace_back() function for your StrVec class and for Vec class in Chapter 16.
                see. strVecClass.h and vec.h

                // vec.h
                template<typename T>
                template<class...Args>
                inline
                void Vec<T>::emplace_back(Args&&...args) {
	                chk_n_alloc();
	                alloc.construct(first_free++, std::forward<Args>(args)...);
                }

                // strVecClass.h
                template<class...Args>
                inline
                void StrVec::emplace_back(Args&&...args) {
                    check_n_allocate();
                    alloc.construct(lelem++, std::forward<Args>(args)...);
                }

    e16.59  - Assuming s is a string, explain svec.emplace_back(s);
                s is an lvalue&, which becomes & &&, and collapses down to lvalue&. 
                check_n_allocate() called to make sure there is enough room in container to store additional values.
                construct called which iterates to next store in the heap and passes s via forward, maintianing type information because of the perfect cast.
                lelem becomes a pointer to an object of type string.

    e16.60  - Explain how make_shared works.
                make_shared works by returning a pointer to specific memory and keeping track of how many times that object's memory is being accessed. When the object 
                is referenced, the counter goes up, when the object stops being used, the counter goes down. When reference count = 0, the memory is automatically deleted, or when the program ends.

    e16.61  - Define your own version of make_shared

                template<typename T, typname ... Args>
                shared_ptr<T> make_shared(Args&&(args)...) {
                    return shared_ptr<T>(new T(std::forward(args)...));
                }


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


/************* e1653 *************/

struct Sales_data {
    Sales_data() = default;
    Sales_data(std::string s) : item(s) { };
    std::string item;
};

void e1654() {
    //Sales_data sd("Hello");
    //print(std::cout, sd);
}

/************* e1656 *************/
template<typename T>
std::string debug_ref(const T& t) {
    std::cout << "Call to debug_ref" << std::endl;
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

template<typename ... Args>
std::ostream& errorMsg(std::ostream &os, const Args& ... rest) {
    std::cout << "Call to errorMsg" << std::endl;
    return print(os, debug_ref(rest)...);
}

std::string retStr(const std::string &s) {
    return s;
}

void e1655() {
    int i = 10;
    std::string h("hello"), w("world");
    double d = 9.22;

    errorMsg(std::cout, i, h, w, d, retStr(h));
}

/************* e1661 *************/
template<typename T, typename ... Args>
shared_ptr<T> make_shared(Args&&...args) {
    return shared_ptr<T>(new T(std::forward<Args>(args)...));
}

void e1661() {
    int i = 10;
    auto sip = make_shared<int>(i);
    auto two = sip;
    std::cout << sip << '\t' << *sip << std::endl;
    std::cout << two << '\t' << *two << std::endl;

}

int main()
{
    //e1652();
    //e1653();
    //e1654();
    //e1655();
    e1661();

    return 0;
}