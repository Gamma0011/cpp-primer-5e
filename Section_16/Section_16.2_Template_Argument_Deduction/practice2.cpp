#include <iostream>
#include <string>
#include <vector>
#include <type_traits>

/*
    || FUNCTION POINTERS AND ARGUMENT DEDUCTION ||
        When we initialize or assign a function pointer from a function template, the compiler uses the type of the pointer to deduce the template arguments.
         
        In this example, we can use the pointer function to point to an instantiation of compare:
            
            template<typename T> int compare(const T&, const T&);
            int (*pf1)(const int&, const int&) = compare;

        The type of parameters in pf1 determine the type of template argument for T. The template argument for T is of type int. The pointer pf1 points to
         is the instantiation of compare with T bound to int.

        Overloaded versions of func; each takes a different function pointer type:
            void func(int(*)(const string&, const string&));
            void func(int(*)(const int&, const int&));
            func(compare);          // error: which instantiation of compare?

        For func(compare), we cannot determine a unique type for the template argument. The call could take the int or the string version.
         However, we can use explicit template arguments:
            func(compare<int>);     // calls version of func that takes a function pointer with two const int& params

        *Note* When the address of a function-template instantiation is taken, the context must be such that it allows a unique type or value to be determined for each template parameter.

    || TEMPLATE ARGUMENT DEDUCTION AND REFERENCES ||

        Looking at this function:       template<typename T> void f(T &p);
            Remember, Normal binding rules apply and consts are low level.

        || TYPE DEDUCTION FROM LVALUE REFERENCE FUNCTION PARAMETERS ||
            When a function param is Lvalue& (T&), binding rules say we can only pass an Lvalue, which may or may not be a const type. If const, const T deduced:

                f(i);       // i is int; template parameter is int
                f(ci);      // ci is const int; template parameter is const int
                f1(5);      // error: arg must be Lvalue

        If a function parameter has const T& type, we can pass any argument (const or otherwise). When the function parameter itself is const, the type
         deduced for T will not be const. Const is already a part of the function parameter; therefore, it does not also become a part of the template parameter.

            template<typename T> void f2(const T &p);

                f1(i);      // i is int; template parameter is const int
                f1(ci);     // ci is const int; template parameter is int
                f1(5);      // a const& parameter can be bound to Rvalue; T is int

        || TYPE DEDUCTION FROM RVALUE REFERENCE FUNCTION PARAMETERS ||
            When function parameter is rvalue reference (T&&), normal binding rules say that we can pass an rvalue to this parameter.
             Doing this, the deduced type for T is an rvalue

                template<typename T> void f2(T&&);
                f3(42);         // argument is an rvalue of type int. T is int

        || REFERENCING COLLAPSING AND RVALUE REFERENCE PARAMETERS ||
            The language defines two exceptions to normal binding rules, which also forms the foundation for how std::move operates:
            
            EXCEPTION 1:    When we pass an Lvalue, the compiler deduces the template parameter type as the argument's lvalue reference type.
                             Calling f3(i), would deduce T as int&, not int. Ordinarily, we cannot directly define a reference to a reference,
                             however, it is possible to do so indirectly through a type alias or through a template type parameter.
            
            EXCEPTION 2:    If we indirectly create a reference to a reference, then those references "collapse". In all but one case, an lvalue
                             reference type is formed. References collapse to form an rvalue reference only in the specific case of an rvalue reference
                             to an rvalue reference.

                        ex. X& &, X& &&, X&& & all collapse to X&
                            X&& && collapses to X&&
            
            *NOTE* Reference collapsing only applies when a reference to a reference is created indirectly, such as in a type alias or a template parameter.

                    f3(i);      // argument is an lvalue, template parameter T is T&
                    f3(ci);     // argument is an lvalue, template parameter T is const T&

                When a template parameter T is deduced as a reference type, the collapsing rule says that the function parameter T&& collapses to an lvalue
                 reference type, which would look like this:

                        void f3<int&>(int& &&);

            Two important consequences happen because of these rules:
                1) A function parameter that is an rvalue & to a template parameter (T&&) can be bound to an lvalue
                2) If arg is lvalue, deduced arg type will be an lvalue& and function parameter will be instantiated as normal lvalue& (T&)

                Therefore, we can pass any type of argument to a T&& function parameter. A parameter of such a type can be used with rvalues as well as lvalues.
        
        || WRITING TEMPLATE FUNCTIONS WITH RVALUE REFERENCE PARAMETERS ||

            template<typename T> void f3(T&& val) {
                T t = val;      // copy or binding?
                t = fcn(t);     // does assignment change only t or val and t?
                if (val == t).. // always true if T is a reference type
            }

        When we call f3 on an rvalue, such as literal 42, T is int. For the above example, local t has type int, initialized by copying value val.
         val remains unchanged.

        When we call f3 on lvalue i, then T is int&. Defining and initializing t makes it of type T& (int&). t is bound to val, meaning the if(val == t) is always true.

        In practice, rvalue reference parameters are used in one of two contexts:
            1) When template is forwarding its arguments.
            2) Template is overloaded.

            Function templates that use rvalue references often use overloading in the same way we saw in chapter 13:
                template<typename T> void f(T&&);           // binds to noncost rvalues
                template<typename T> void f(const T&);      // lvalues and const rvalues

    || UNDERSTANDING STD::MOVE ||
        std::move is a good illustration of a template that uses rvalue references. Looking at how move works can help our
         understanding of templates. Move is a function template and can take arguments of essentially any type.

         std::move obtains an rvalue reference bound to an lvalue

        || HOW STD::MOVE IS DEFINED ||
            Move is defined as follows. see // move

            - move's function parameter (T&&) is an value reference to a template parameter type
            - Via reference collapsing, this parameter can match arguments of any type, can pass rvalue or lvalue

        || HOW STD::MOVE WORKS ||

            consider:   string s1("hi!"), s2;

            s2  = std::move(string("bye"));
                - Passing an rvalue to an rvalue reference function parameter, the type deduced from argument is referred-to-type
                - The deduced type of T is string
                - remove_reference instantiated with string
                - type member of remove_reference<string> is string
                - return type of move is string&&
                - parameter t has type string&&
                - instantiates function:    string&& move(string &&t);


            s2  = std::move(s1);

        
*/

// move
template<typename T>
typename std::remove_reference<T>::type&& move(T&& t) {
    return static_cast<typename std::remove_reference<T>::type&&>(T);
}


int main()
{

    return 0;
}