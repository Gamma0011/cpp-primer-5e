#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/*
    e16.48  - Write your own versions of the debug_ref functions

    e16.49  - Explain what happens in each of the following calls
                template<typename T> void f(T);
                template<typename T> void f(const T*);
                template<typename T> void g(T);
                template<typename T> void g(T*);

                int i = 42, *p = &i;
                const int ci = 0, *p2 = &ci;

                g(42);      // will call g(T)
                g(p);       // will call g(T*)
                g(ci);      // will call g(T)
                g(p2);      // will call g(T*)
                f(42);      // will call f(T)
                f(p);       // will call f(T)       const T* requires const, so T only viable.
                f(ci);      // will call f(T)
                f(p2);      // will call f(const T*)

    e16.50  - Test your answers above.

*/

// e16.48

template<typename T>
std::string debug_ref(const T& t) {
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

template<typename T>
std::string debug_ref(T* p) {
    std::ostringstream ret;
    ret << "Pointer Address: " << p;
    if (p) {
        ret << " | Value: " << debug_ref(*p);
    } else {
        ret << " nullptr";
    }
    return ret.str();
}

std::string debug_ref(const char *c) {
    return debug_ref(std::string(c));
}

std::string debug_ref(char *c) {
    return debug_ref(std::string(c));
}

void e1648() {
    std::string s("awk");
    std::cout << debug_ref(s) << std::endl;

    std::string *sp = &s;
    std::cout << debug_ref(sp) << std::endl;

    std::cout << debug_ref("Character literal") << std::endl;

    int i = 10;
    std::cout << debug_ref(&i) << std::endl;
}

template<typename T> void f(T) { std::cout << "void f(T)" << std::endl; }
template<typename T> void f(const T*) { std::cout << "void f(const T*)" << std::endl; }
template<typename T> void g(T) { std::cout << "void g(T)" << std::endl; }
template<typename T> void g(T*) { std::cout << "void g(T*)" << std::endl; }

void e1649() {
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;

    g(42);      // will call g(T)
    g(p);       // will call g(T*)
    g(ci);      // will call g(T)
    g(p2);      // will call g(T*)
    f(42);      // will call f(T)
    f(p);       // will call f(T)       const T* requires const, so T only viable.
    f(ci);      // will call f(T)
    f(p2);      // will call f(const T*)
}

int main()
{
    //e1648();
    e1649();

    return 0;
}