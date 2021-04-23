#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/*
    A variadic template is a template function or class that can take a varying number of parameters. 
     These varying parameters are known as a parameter pack, of which there are two types:
        1) A template parameter pack, which represents 0 or more template parameters
        2) A function parameter pack, which represents 0 or more function parameters

    We use ellipsis (...) to indicate that a template or function parameter represnts a pack. In a template parameter list,
     class ... or typename ... indicates that the following parameters represent a list of 0 or more types.
     The name of a type, followed by an elipsis represents a list of zero or more nontype parameters of the given type.

    In a function parameter list, a parameter whose type is a template parameter pack is a function parameter pack.

    - Args is a template parameter pack, representing 0 or more template type parameters
    - Rest is a function parameter pack, representing 0 or more function parameters
        
    template<typename T, typename ... Args>
        void foo(const T& t, const Args& ... rest);
    
    void foo() is declared a variadic function that has one type parameter named T and a template parameter pack called Args. This pack
     represents 0 or more additional parameters.

    The function parameter list of foo has one parameter, with type const T&, and a function parameter pack named rest. That pack represents 0 or more function parameters.

    The compiler deduces the template parameter types from the function's arguments. For a variadic template, the compiler also deduces the number of parameters in the pack.

        int i = 0; double d = 3.14; std::string s = "Hello";
        foo(i, s, 42, d);       // 3 parameters in the pack
        foo(s, 42, "hi");       // 2 parameters in pack
        foo(d, s);              // 1 parameter in pack
        foo("hi");              // empty pack

        foo(const int&, const string&, const int&, const double&);  // instantiatied
        foo(const string&, const int&, const char[3]&);
        foo(const double&, const string&);
        foo(const char[3]&);

        T is deduced from the type of the first argument. Remaining args provide number of and types for additional arguments to function.
    
    || THE SIZEOF... OPERATOR ||
        When we need to know how many elements are in a pack, we can use sizeof... operator. Like sizeof, sizeof... returns constexpr and does not eval arguments.

        template<typename ... Args> void g(Args ... args) {
            std::cout << sizeof...(Args) << std::endl;      // # of template parameters
            std::cout << sizeof...(args) << std::endl;      // # of function parameters
        }
    
    || WRITING A VARIADIC FUNCTION TEMPLATE ||
        Initializer_lists are useful when we know that we need a list of same types. Variadic functions are used when we know neither the number
         nor the types of arguments we want to process.

        Variadic functions are often recursive -- the first call processes the first argument in the pack, then calls itself on remaining args.
         To stop recursion, we need to define a nonvariadic function that will take a string and an object.
        
        Function to end recursion and print the last element. This function must be declared before variadic version is defined.

            template<typename T>
            std::ostream& print(std::ostream &os, const T &t) {
                return os << t;
            }

            template<typename T, typename ... Args>
            std::ostream& print(std::ostream &os, const T& t, const Args& ... rest) {
                os << t << " ";
                return print(os, rest...);      // recursive call; print other arguments.
            }

        The first version of print(ostream&, const T&) stops the recursion and prints the last argument in the initial call to print.
        The second, variadic version prints the arguments bound to t and calls itself to print remaining values in function parameter pack.
        
        The key part in the call to print inside the variadic function:
            return print(os, rest...);

        The variadic version of our print function takes 3 parameters- an ostream&, const T&, and a parameter pack. Yet, it only passes 2 arguments.
         The first argument in rest is bound to t. The remaining arguments in rest form the parameter pack for the next call to print.
         With each call, the first argument in the pack is removed from the pack and becomes the argument bound to t.

         Call                   t                   rest
         -----------------------------------------------
         print(cout, i, d, s)   i                   d, s
         print(cout, d, s)      d                   s
         print(cout, s)         s                   ---     // calls nonvariadic function print();

        The first two calls can only match the variadic version of print because it accepts more arguments than the nonvariadic version. For the last call,
         print(cout, s), there is exactly 2 arguments, matching the nonvariadic function, but also the variadic version. A nonvariadic template is more
         specialized, therefore print(ostream&, const T&) is called.

        *WARNING* A declaration for a nonvariadic version of a function must be in scope when a variadic version is defined. Otherwise, the variadic function will recurse indefinitely.

        || PACK EXPANSION ||
            Aside from taking its size, the only other things we can do with a parameter pack is to expand it. When we expand a pack, we also provide a pattern to be used
             on each expanded element. Expanding a pack separates the pack into its constituent elements, applying to each patter as it does so.
            
            We can trigger an expansion by putting (...) to the right of the pattern.

            template<typename T, typename ... Args>             // EXPAND ARGS
            std::ostream& print(std::ostream &os, const T& t, const Args& ... rest) {
                os << t << " ";
                return print(os, rest...);      // EXPAND REST
            }

            The first expansion (args) expands the template parameter pack and generates the function parameter list for print.
            The second expansion (rest) generates the argument list for the call to print.

            The expansion of Args applies pattern const Args& to each element in the parameter pack. The expansion of this pattern is a comma-separated
             list of zero or more parameter types, each with the form const T&.

                print(cout, s, i, d) has 2 parameters in the pack

                The call is instantiated as ostream& print(ostream&, const string&, const int&, const double&)

            The second expansion happens in the (recursive) call to print. In this case, the pattern is the name of the function parameter pack (rest).
             This pattern expands to a comma-separated list of elements in the pack, same as:  

                print(os, i, d);
            
        || UNDERSTANDING PACK EXPANSIONS ||
            The expansion of print just expanded the pack into its constituent parts. We can make a more complicated pattern, in this case, a second
             variadic function that calls debug_ref on each arguments, then calls print to print strings.

            template<typename ... Args>
            std::ostream& errorMsg(std::ostream &os, const Args& ... rest) {
                return print(os, debug_ref(rest)...);
            }

            *Note* The pattern in an expansion applies separately to each element in the pack.

        || FORWARDING PARAMETER PACKS ||
            
*/

template<typename T>
std::string debug_ref(const T& s) {
    std::ostringstream ret;
    ret << s;
    return ret.str();
}

template<typename T>
std::ostream& print(std::ostream &os, const T& t) {
    return os << t;
}

template<typename T, typename ... Args>
std::ostream& print(std::ostream &os, const T& t, const Args&... rest) {
    os << t << " ";
    return print(os, rest...);
}

template<typename ... Args>
std::ostream& errorMsg(std::ostream &os, const Args&... rest) {
    return print(os, debug_ref(rest)...);
}

int main()
{
    std::string s("this"), t("is"), u("string");

    errorMsg(std::cout, s, t, u);

    return 0;
}