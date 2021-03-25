#include <iostream>
#include <cstring>
#include <string>

/*
template<typename T>
int compare(const T &v1, const T &v2) {
    if (v1 < v2) return -1;
    if (v1 > v2) return 1;
    return 0;
}
*/

// this type will also work on pointers
template<typename T>
int compare(const T& v1, const T& v2) {
    if (std::less<T>() (v1,v2)) return -1;
    if (std::less<T>() (v2, v2)) return 1;
    return 0;
}

template<typename T>
T foo (T* p) {
    T temp = *p;
    return temp;
}

template<unsigned m, unsigned n>
int compare(const char (&p1)[m], const char (&p2)[n]) { return strcmp(p1, p2); }

/*
    Templates are the foundation for generic programming in C++. A template is a blueprint or formula for creating classes or functions.
     When we use a generic type, such as vector of a generic function such as find, we supply information needed to transform that
     blueprint into a specific class or function. This happens during compilation and NOT at run time. 

    || DEFINING A TEMPLATE ||
        Rather than defining a new function for each type, we can define a function template, which is a formula from which we can
         generate type-specific versions of that function.

        template<typename T>
        int compare(const T &v1, const T &v2) {
            if (v1 < v2) return -1;
            if (v1 > v2) return 1;
            return 0;
        }

        A template definition starts with keyword TEMPLATE followed by a template parameter list contained within <>
        *NOTE* This parameter list cannot be empty.

        The purpose of a function parameter list is to define local variables of a specified type, but does not say how to 
         initialize them. At run time, arguments are supplied to initialize parameters.

        int compare declares one type parameter 'T'. Inside of compare, we use the name T to refer to a type - that type is
         determined at compile time based upon compare's usage

    || INSTANTIATING A FUNCTION TEMPLATE ||
        When we call a function template, the compiler uses the arguments of the call to deduce the template arguments. 

        ex. compare(1,0) T is of type int

        If the compiler can deduce this, it will bind that argument to the template parameter T.

        The compiler uses deduced template parameters to instantiate a specific version of the function for us. When it does this,
         it creates a "new instance" of the template using the actual args in place of the template parameters.

         ex.    compare(1,0) instantiates compare(const int&, const int&)
                compare(vec1, vec2) instantiates compare(const vector<int>&, const vector<int>&);

    *NOTE* Compiler-generated functions are referred to as INSTANTIATION OF THE TEMPLATE.
    
    || TEMPLATE TYPE PARAMETERS ||
        We can also use a type parameter as a type specifier in the same way we use built-in or class type specifiers. 
         This can be used to name the return type or a function body parameter type, or for variable declarations within the function body.

         template<typename T> T foo(T* p) {
             T temp = *p;
             return temp;
         }

        Each type parameter must be preceded by the keyword class or typename. Additionally, there is no difference between typename and class
            (cannot write <typename T, Y> must be <typename T, class Y>)

        Class is a holdover from earlier C++, typename is a newer version. Both are supported in templates.

    || NONTYPE TEMPLATE PARAMETERS ||
        We can also define templates that take nontype parameters, which represent a value rather than a type. Nontype parameters are specified
         by using a specific type name instead of the typename or class keyword.

        When the template is instantiated, nontype parameters are replaced with a value supplied by the user or deduced by the compiler. 
        *NOTE* Template arguments used for nontype templates must be CONST EXPRESSIONS.

        There is a case for this if we want to compare two string literals with our compare function. 

            template<unsigned m, unsigned n>
            int compare(const char (&p1)[m], const char (&p2)[n]) { return strcmp(p1, p2); }

    || INLINE AND CONSTEXPR FUNCTION TEMPLATES ||
        A function template can be INLINE or CONSTEXPR

        syntax: template<typename T> inline T min(const T&, const T&);

        *NOTE* inline falls after template and parameter list, but precedes the function return type

        The int compare() function illustrated two important principales for writing generic code:
            - Function parameters are const& (functions can be used on types that cannot be copied)
            - Tests in body only use < comparisons ()

        *NOTE* Template programs should try to minimize the number of requirements placed on the argument type.

        // this version of compare will be correct even if used on pointers
        template<typename T> int compare(const T &v1, const T &v2) {
            if (less<T>() (v1,v2)) return -1;
            if (less<T>() (v2,v1)) return 1;
            return 0;
        }

    || TEMPLATE COMPILATION ||
        Template code is only generated when we instantiate a specific instance of the template. This causes two things:
            1. How we organize our source code
            2. When errors are detected

        Normally, when we call a function, the compiler needs only a declaration. For an object of class type, the definition must be 
         available, but the definitions of member functions need not be present. 

        Therefore, we put class definitions and function declarations in header files and definitions of ordinary and class-member functions in source files.

        
        For a template: to generate an instantiation, the compiler needs to have the code that defines function template or class template member function.
        *NOTE* Headers for templates typically include definitions as well as declarations.

    || KEY CONCEPT: TEMPLATES AND HEADERS ||
        Templates contain two kinds of names:
            - Those that do not depend on a template parameter.
            - Those that do.

        All names not dependent on a template parameter must be visible when template is used. Additionally, the definition of the template,
         must be visible when the template is instantiated.

        The user of the template must ensure that everything needed to instantiate the template are visible when needing to be.

        Authors of templates should provide a header that contains template definitions and declarations for all names used in class template 
         or definitions of its members. Users must include a header for the template and any types used to instantiate that template.

    || COMPILATION ERRORS ARE MOSTLY REPORTED DURING INSTANTIATION ||
        Type-related errors are normally found during instantiation. A template might not be overtly type specific, but there are some 
         assumptions that need to be made about the type that will be used.

         ex. if (v1 < v2) return -1; // assumes objects of type T support < operator

        *NOTE* It is up to the caller to guarantee that the arguments passed to templates support required operations.

*/

int main()
{
    std::cout << compare("te", "test") <<std::endl;

    return 0;
}