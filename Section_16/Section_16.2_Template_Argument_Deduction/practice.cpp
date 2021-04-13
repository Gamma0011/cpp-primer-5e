#include <iostream>
#include <fstream>
#include <string>

/*
    || TEMPLATE ARGUMENT DEDUCTION ||
        By default, the compiler uses the arguments in a call to determine the template parameters for a function template. This process is
         called Template Argument Deduction. The compiler uses types of arguments in the call to find a template that generates a version
         of the function matching the given call.

    || CONVERSIONS AND TEMPLATE TYPE PARAMETERS ||
        The arguments we pass in a call to a function template are used to initialize the function's parameters. There are special rules for this
         type of initialization. Rather than converting arguments to different types, the compiler generates new instantations.

         - const conversions: function parameter that is & or * to a const can be passed a & or * to a nonconst object.
         - array- or function-to-pointer conversions: if the function parameter is not a &, then the normal pointer conversion will be applied
            to arguments of array or function type. An array argument will be converted to a pointer to its first element. A function
            argument will be converted to a pointer to the function's type.
        
         - arithmetic, derived-to-base and user-defined conversions do not happen.

            see. //conversions && void conversions();

        *Note* const conversions and array or function to pointer are the only automatic conversions for arguments to parameters within template types

    || FUNCTION PARAMETERS THAT USE THE SAME TEMPLATE PARAMETER TYPE ||
        A template type parameter can be used as the type of more than one function parameter. Because there are limited conversions, the arguments to
         such parameters must essentially have the same type.
        
        If deduced types do not match, then call is in error. 

        ex. void compare(const int&, const int&)
                long lng;
                compare(lng, 1024);         // error: cannot instantiated compare(long,int); arguments don't have same type long && int

        If we want to allow normal conversions, we can define two parameters:

                template<typename A, typename B>
                int flexibleCompare(const A &v1, const B &v2) {
                    if (v1<v2) { return -1; }
                    if (v2<v1) { return 1; }
                    return 0;
                }

        Using this template, the user can provide arguments of differing types.
        *Note* operator < must exist for comparison of those types or be defined.

    || NORMAL CONVERSIONS APPLY FOR ORDINARY ARGUMENTS ||
        A function template can have parameters that are defined using ordinary types -- types that do not involve a template type parameter.
        These arguments have no special processing and are converted as usual to type of parameter.

            template<typename T> ostream& print(ostream &os, const T &obj) {
                return os << obj;
            }

            The first parameter (ostream) is a known type. The second parameter, obj, has a template parameter type. Because os is fixed, normal conversions
             are applied to arguments passed to os when print() is called.

        *NOTE* Normal conversions are applied to arguments whose type is not a template parameter.

    || FUNCTION-TEMPLATE EXPLICIT ARGUMENTS ||
        In some situations, the compiler cannot deduce the types of template arguments. In others, we want to allow the user to control instantiation.
         This normally happens when a function return type differs from any of those in the parameter list.

        || SPECIFYING AN EXPLICIT TEMPLATE ARGUMENT ||
            

*/

// conversions
template<typename T> T fobj(T, T);              // arguments are copied
template<typename T> T fref(const T&, const T&);// references

void conversions() {
    std::string s1("a value");
    const std::string s2("const value");
    int a[10], b[20];

    //fobj(s1,s2);            // const ignored
    //fref(s1,s2);            // uses premissible conversion to const on s1
    
    //fobj(a,b);              // calls int*, int* conversion to pointers
    //fref(a,b);            // when parameters are reference, no conversion to pointer. Does not match parameters of fref(const&, const&)
}

// normal conversions template parameters
template<typename T>
std::ostream& print(std::ostream &os, const T &obj) {
    return os << obj;
}

void normalconversions() {
    //print(std::cout, "Hello");
    std::ofstream o("text.txt");
    print(o, "world");

}

int main()
{


    return 0;
}