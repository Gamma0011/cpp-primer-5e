#include <iostream>
#include <fstream>
#include <string>
#include <type_traits>
#include <vector>

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
            In some cases, we might want the user to specify which type to use. We'll define a function template named sum that takes arguments of two different
             types. We'll let the user specify the type of the result. We do this by allowing the user to define a third template parameter representing the return type.

            see. // explicit returns

            No argument can be used to deduce T1 in T1 sum(T2, T3); The caller must provide an explicit template argument for this parameter on each call to sum.

            To supply an explicit template argument the same way we define an instance of class template:
                auto val3 = sum<long, long>(i, lng);        // long long sum(int, long)

                This call specifies the type for T1. The compiler will deduce the types from i and lng

            Explicit templates are matched to parameter from left to right. T1->T2->T3. An explicit template may be omitted only for the right-most parameters,
             and then only if these can be deduced from the function parameters. 

                This is an example of poor design, which requires users to specify explicitly all three template parameters:
                    template<typename T1, typename T2, typename T3>
                    T3 sum(T2,T1);

                We're have to write:    auto val2 = sum<long long, int, long>(i, lng);
        
        || NORMAL CONVERSIONS APPLY FOR EXPLICITLY SPECIFIED ARGUMENTS ||
            In the same way normal conversions are permitted for parameters defined using ordinary types, normal conversions also apply for arguments
             whose template type parameter is explicitly stated:

                long lng;
                compare(lng, 1024);         // error, template parameters don't match   (long, int)
                compare<long>(lng, 1024);   // okay: instantiates as compare(long, long)
                compare<int>(lng, 1024);    // okay: instantiates as compare(int, int)

    || TRAILING RETURN TYPES AND TYPE TRANSFORMATION ||
        Explicit template return types work well when we want the user to determine the return type. In other cases, requiring explicit template arguments
         can be a burden. 

        As an example, we might want to write a function that takes a pair of iterators denoting a sequence and returns a & to an element in the sequence.

            template<typename It>
            _ &fcn(It beg, It end) {
                // process sequence
                return *beg;
            }

        We don't know the exact type we want to return, but we do know it'll be a & to the element type of the sequence we're processing. Our function will
         return *beg, and we know we can use decltype(*beg) to obtain the type from the expression. However, beg doesn't exist until the parameter list
         has been seen. To define this function, we must use a trailing return type because the return appears after the parameter list.

         // trailing return lets us declare the return type after the parameter list is seen
         template<typename It>
         auto &fcn(It beg, It end) {
             / process
             return *beg;
         }

        The compiler knows that fcn's return is the same as the type returned by dereferencing the beg parameter. The dereference operator returns an lvalue,
         so the type deduced by decltype is a reference to the type of element beg denotes.

        What this means is that a call on a sequence of strings returns string& and a int sequence int&

    || TYPE TRANSFORMATION LIBRARY TEMPLATE CLASSES ||
        There are no iterator operations that yield elements (opposed to references to elements).
         To obtain the element type, we can use a library type transformation template. These templates are defined in the <type_traits> header.

        The classes in type_trails are used for so-called template metaprogramming, a topic outside the scope of C++ Primer. However, these templates are useful
         in ordinary programing 

         remove_reference can be used to obtain an element type, having only one type parameter and a public member named type.
         If we instantiate remove_reference with a reference type, then type will be the referred-to-type.

            ex. remove_reference<int&> will return type member int
                
                remove_reference<decltype(*beg)>::type  
                    is the type of element to which beg refers: decltype(*beg) returns & type of element type
                    remove_reference::type strings off the reference, leaving the element instead
            
        Using remove_reference and decltype, we can write a function to return a copy of an element's value:

            *NOTE* Must use typename to use a type member of a template parameter. This declares that type represents a type

            template<typename T>
            auto fcn(T beg, T end) ->
                typename remove_reference<decltype(*beg)>::type {
                / process
                return *beg;
            }

        For each type transformation (Table 16.1, pg. 685), the template has a public member named type that represents a type. That type may be 
         related to the template's own template type parameter in a way that is indicated by the template's name. If it is not responsible
         or necessary to transform the template's parameter, the type member is the template parameter itself.

         ex. if T is * type, then remove_pointer<T>::type is type to which T points. If T != pointer type, type is same as T

         
*/

// conversions
template<typename T> T fobj(T, T);              // arguments are copied
template<typename T> T fref(const T&, const T&);// references

// explicit returns
template<typename T1, typename T2, typename T3> 
T1 sum(T2, T3);

// compare
template<typename T>
T compare(T a, T b);

// transformation library template classes
template<typename It> auto fcn(It beg, It end) ->
typename std::remove_reference<decltype(*beg)>::type {
    return *beg;
}

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
    std::vector<int> ivec = {3,2,3,4,5,6,7};

    std::cout << fcn(ivec.begin(), ivec.end()) << std::endl;

    return 0;
}