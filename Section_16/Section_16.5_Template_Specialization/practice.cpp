#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_set>

#include "sales_data.h"

/*
    It's not always possible to write a single template that is best suited for every possible template argument in which the template might be instantiated.

    In some cases, general definition might not compile or might do the wrong thing. Other times, we may take advantage of some specific knowledge
     to write more efficient code than would be instantiated from the template.

    We can define a specialized version in these instances.
        see. int compare versions

        Specialized version for string literals
        template<std::size_t M, std::size_t N>
        int compare(const char (&)[M], const char (&)[N]);

        The version of compare that has two nontype template parameters will only be called when passing a string literal or an array.
            compare(s1, s2);            // calls int compare(const T&, const T&);
            compare("hello", "world");  // calls int compare(const char(&)[M], const char(&)[N])

    To handle character pointers (as opposed to arrays), we can define a template specialization of the first version of compare. This is a separate
     definition of the template in which one or more template parameters are specified to the particular types.

    || DEFINING A FUNCTION TEMPLATE SPECIALIZATION ||
        In order to specialize a function, we must supply arguments for every template parameter in the original template. To denote specialization, 
        we use template<> The empty angle brackets indicate that arguments will be supplied for all template parameters in original template.

        Special version of compare to handle pointers to character arrays:
            template<>
            int compare(const char* const &p1, const char* const &p2) { return strcmp(p1, p2); }

        In this case, we are specializing:
            template<typename T>
            int compare(const T&, const T&);

            T is of type const char*. Since we need a type that is const&, we must make the whole parameter type const char* const &

    || FUNCTION OVERLOADING VS TEMPLATE SPECIALIZATIONS ||
        When we define a function template specialization, we are taking over the job of the compiler by supplying the defintiion to use for a specific instantiation
         of the original template. It is important to realize that a specialization is an instantiation; not an overloaded instance.

        *NOTE* Specializations instantiate a template, they do not overloaded it.

        Whether we define a particular function as a specialization or as an independent, nontemplate function can impact function matching. 
         Calling compare() on 2x string literals shows two equally viable templates, however, since the template taking arguments of type
         const char (&)[] is more specialized, that one is called.

         In the case that int compare(const char*, const char*) was a nontemplate function, this too would be viable and would be chosen istead.

    *KEY CONCEPTS* 
        To specialize a template, a declaration for the original template must be in scope. Additionally, a declaration for a specialization must be in scope
         before any code uses that instantation of the template.

        With ordinary classes and functions, missing declarations are usually easy to find as the compiler won't be able to process code. However, if a specialization
         declaration is missing, the compiler will generate code using original template. Because of this, errors in declaration order between a template and
         its specializations are difficult to find.

        *BEST PRACTICE* Templates and specializations should be declared in the same header file. Declarations for all templates with a given name should appear first.

    || CLASS TEMPLATE SPECIALIZATIONS ||
        We can also specialize class templates. 
            see. hash.h and sales_data.h

        *NOTE* To enable users of Sales_data to use specialization of hash, we should define this specialization in the Sales_data header

    || CLASS-TEMPLATE PARTIAL SPECIALIZATIONS ||
        A class template specialization does not have to supply an argument for every template parameter. We can specify some, but not all,
         of the template parameters or some, but not all, aspects of the parameters.

        A class template partial specialization is itself a template. Users must supply arguments for those parameters that are not fixed by specialization.

        *NOTE* We can partially specialize only a class template. We cannot partially specialize a function template.

        The library type remove_reference is a template that works through specialization.
            see struct remove_reference(s)

            template<class T> struct remove_reference       - most generic
            template<class T> struct remove_reference<T&>   - partial specialization
            template<class T> struct remove_reference<T&&>  - partial specialization

        After the class name, (struct remove_reference) we specify arguments for the template parameters we are specializing.
         These arguments are listed inside angle brackets following the template name and correspond positionally to parameters in original template.

        The template parameter list of a partial specialization is a subset of or a specialization of the parameter list of the original template.
         In this case, the specializations have the same number of parameters as the original. However, the type in specializations differ from the original.

         see. void partial_specialization();

    || SPECIALIZING MEMBERS BUT NOT THE CLASS ||
        We can also only specialize specific member functions.

            see. template foo;
*/

// original, most generic template
template<class T> struct remove_reference {
    typedef T type;
};

// partial specializations used for lvalue and rvalue references
template<class T> struct remove_reference<T&> {     // lvalue
    typedef T type;
};
template<class T> struct remove_reference<T&&> {    // rvalue
    typedef T type;
};

/************** compare **************/
template<typename T>
int compare(const T&, const T&);

template<std::size_t M, std::size_t N>
int compare(const char (&)[M], const char (&)[N]);

template<>
int compare(const char* const &p1, const char* const &p2) {
    return strcmp(p1, p2);
}

/************** foo **************/

template<typename T> struct Foo {
    Foo(const T &t = T()) : mem(t) { };
    void Bar();
    T mem;
};

template<>
void Foo<int>::Bar() {
    std::cout << "Foo<int>" << std::endl;
}

/************** partial specialization **************/

void partial_specialization() {
    int i;
    remove_reference<decltype(i)>::type lvalue;                 // type int
    remove_reference<decltype(42)>::type d;                     // type int
    remove_reference<decltype(std::move(i))>::type rvalue;      // type int
}

void foo_bar() {
    Foo<std::string> fs;        // instantiates Foo<string>::Foo()
    fs.Bar();                   // instantiates Foo<string>::Bar();
    Foo<int> fi;                // instantiates Foo<int>::Foo();
    fi.Bar();                   // uses partial specialization Foo<int>::Bar();
}

int main()
{
    // std::unordered_multiset<Sales_data> SDset;
    foo_bar();

    return 0;
}