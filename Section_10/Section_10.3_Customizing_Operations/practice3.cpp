#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>

/*
    || USING PLACEHOLDER NAMES ||
        The _n names are defined in the namespace std::placeholders. Writing out such declarations can be tedious 
        (as to define placeholders requires std::placeholders::_1, _2, etc), so rather than separately declading
        each placeholder, we can use a different form of using:
                Syntax: using namespace namespace_name      | Context: using namespace std::placeholder;

    || ARGUMENTS TO BIND ||
        We can use bind to fix a parameter. More generally, we can use bind to bind or rearrange the parameters in a given callable. 
        For example, assuming f is a callable object that has 5 parameters, this call to bind generates a new callable that
        takes 2 arguments, represented by placeholders _2 and _1. The new callable will pass its own arguments as the 
        3rd and 5th arguments to f. The 1st, 2nd, and 4th arguments to f are bound to the given values a, b, and c.

            auto g = std::bind(f, a, b, std::placeholder::_2, c, std::placeholder::_1);
                            ** NOTE ** a _3, b _4, c _5
            
        The arguments to g are bound positionally to the placeholders. That is, the first argument to g is bound to _1, 
        the second to _2. Thus when we call g, the first argument will be passed to the last argument to f; the second argument to g
        will be passed as g's 3rd argument, in effect, this call to bind map:
            g(_1, _2);      to f(a, b, _2, c, _1);

        Calling g(X,Y) = f(a,b,Y,c,X);

            std::sort(words.begin(), words.end(), isShorter);    
                                    - will call isShorter(A,B) which is the default
            std::sort(words.begin(), words.end(), bind(isShorter, std::placeholders::_2, std::placeholders::_1));
                                    - will call isShorter(B,A) which inverts the arguments

    || BINDING REFERENCE PARAMETERS ||
        By default, the arguments to bind that are not placeholders are copied into the callable object bind returns. However,
        as with lambdas, sometimes we have arguments that we want to bind but that we to pass by reference or we might want to
        bind an argument that has a type we cannot copy

            For example, to replace the lambda that captured an ostream by reference:
                // os is a local variable referring to an output stream
                // c is a local varaible of type char
                std::for_each(words.begin(), words.end() [&os, c](const std::string &s) {return os << s << c; });

            We can easily rewrite a function to do the same job
                std::ostream &print(std::ostream &os, const std::string &s, char c = ' ') {return os << s << c;}
        
        Because bind copies its arguments and we cannot copy an ostream, if we want to pass an object to bind without
        copying it, we must use the library ref function. The ref function returns an object that contains the given
        reference and that is itself copyable. There is also cref, that generates a class that holds a & to const. 
        Both cref and ref are defined in the functional header

            std::sort(words.begin(), words.end(), bind(print, std::ref(os), std::placeholders::_1, ' '));


*/

bool isShorter(const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
}

//void print(const std::vector<std::string> &svec) { for (auto &s : svec) { std::cout << s <<std::endl; }}

std::ostream &print(std::ostream &os, const std::string &s, char c = ' ') {return os << s << c;}

int main()
{
    std::vector<std::string> words = {"hello", "world", "how", "goes", "it", "today"};
    std::ostream &os = std::cout;

    // using bind to reorder parameters
    //  sort on word length, shortest to longest
    std::sort(words.begin(), words.end(), isShorter);
    // sort on word length, longest to shortest
    std::sort(words.begin(), words.end(), bind(isShorter, std::placeholders::_2, std::placeholders::_1));

    //print(words);

                                                    // os (ostream &os) passed by reference
    std::sort(words.begin(), words.end(), bind(print, std::ref(os), std::placeholders::_1, ' '));

    return 0;
}