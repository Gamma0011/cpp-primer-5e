#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/*
    || WRITING OVERLOADED TEMPLATES ||
        Function templates can be overloaded by other templates, or by ordinary, nontemplate functions. As usual, functions with the same name must differ by parameters.

        Function matching is affected by the presence of function templates in the following ways:
            - Candidate functions for call include any function-template instantiation for which argument deduction succeeds.
            - Candidate function templates always viable, b/c template argument deduction will have eliminated non-viable templates.
            - Viable functions (all) are ranked by conversions, if any, needed. 
            - If exactly one function provides a better match, that one is selected. If more than one matches:
                - Only one nontemplate good? Nontemplate called.
                - No nontemplates in set, but multiple templates? More specialized function template called.
                - Otherwise, call ambiguous.

        *WARNING* Correctly defining a set of overloaded function templates requires good understanding of relationship among types and restricted conversions.

        We'll build a template called debug_rep to print a string to an object of any type. 
            see template<T> debug_ref(const T& t)
        Next, we'll overload that template to accept pointers and print pointers 
            see template<T> debug_ref(T *p)

    || MULTIPLE VIABLE TEMPLATES ||
        std::string s("hi");
        const std::string *sp = &s;

        std::cout << debug_ref(sp) << std::endl;

        - Both templates are viable:
            - debug_ref(const T&) instantiation of the first version of the template with T bound to const string*
            - debug_ref(T *p) instantiation of second version of template with T bound to const string.

            Call, however, is not ambiguous because of rule that states the more specialized template will be used, in this case, (T* p)
             This rule exists because without it, there would be no way to call a pointer to const, because the const T& parameter can be called
             on almost every type, which makes it more general than T* p, which only works with pointers. 

        *NOTE* When there are several overloaded templates that provide an equally good match for a call, the most specialized version is preferred.

    || NONTEMPLATE AND TEMPLATE OVERLOADS ||
        Next, we'll just define a normal function to print argument passed to parameter, const string&

        std::string debug_ref(const std::string &s) {
            return '"" + s + '"";
        }

        Calling std::cout << debug_ref(s) will produce two equally viable functions:
            - template accepting const std::string&
            - nontemplate accepting const std::string&
        
        In this case, the nontemplate version is selected by the compiler because it's considered more specialized than the template match because it was defined.

        *NOTE* A nontemplate will always be preferred over a template when both provide equally good matches.

    || OVERLOADED TEMPLATES AND CONVERSIONS ||
        Passing a character string, rather than an lvalue:
            std::cout << debug_ref("Hello world!");         // calls debug_ref(T*)

        All three debug_ref functions are viable:
            - debug_rep(const T&) with T bound to char[12]
            - debug_rep(T *p) with T bound to const char
            - debug_rep(const string&) with requires conversion from const char* to string

        As before, debug_rep(T *p) is the more specialized version and will be called.

        If we want to handle character pointers as string, we can define 2 more nontemplate overloads:

            std::string debug_ref(char *p) { return debug_ref(std::string(p)); }
            std::string debug_ref(const char *p) { return debug_ref(std::string(p)); }

    || MISSING DECLARATIONS CAN CAUSE THE PROGRAM TO MISBEHAVE ||
        In order for the char* and const char* versions to work, there must be a const string& within scope when functions are defined.

        Unlike normal code, which won't compile if there is an issue, using template types, so long as there is a match the compiler will use that,
         even if it's not the expected type.

    *TIP* Declare every function in an overloaded set before you define any functions. That way you don't have to worry about whether the compiler
        * will instantiate the call before it sees the function you intend to call.
    
*/

template<typename T>
std::string debug_ref(const T& t) {
    std::ostringstream ret;
    ret << t;                   // uses T's output operator to print representation of t
    return ret.str();           // return copy of string to which ret bound.
}

template<typename T>
std::string debug_ref(T *p) {
    std::ostringstream ret;
    ret << "Pointer: " << p;                    // print pointer's value
    if (p) {                                    // if not nullptr
        ret << " String: " << debug_ref(*p);    // pass referenced value to debug_ref(const T& t)
    } else {
        ret << " nullptr";
    }
    return ret.str();                           // return copy of string to which ret is bound
}

std::string debug_ref(const std::string &s) {
    return '"' + s + '"';
}

void test() {
    std::string s("hi");
    std::cout << debug_ref(s) << std::endl;     // calls debug_ref(const T& t)
    std::cout << debug_ref(&s) << std::endl;    // calls debug_ref(T *p)
}

int main()
{
    test();

    return 0;
}