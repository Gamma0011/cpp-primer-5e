#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

/*
    || CAPTURE LAMBDA BY VALUE ||
        Unlike parameters, the value of a captured variable is copied when the lambda is created, not when it is called:
            void fcn() {
                size_t v1 = 42; // local variable
                // copies v1 into the callable object named f
                auto f = [v1] { return v1; };
                v1 = 0;
                auto j = f();       // j is 42; f stored a copy of v1 when we created it
            }
        Because the value is copied when the lambda is created, subsequent changes to a captured variable have no effect on the 
        corresponding value inside the lambda (in this case, f() )
    
    || CAPTURE BY REFERENCE ||
        Lambdas can also be defined to capture variabled by reference.
            void fcn2() {
                size_t v1 = 42;     // local variable
                // object f2 contains a reference to v1
                auto f2 = [&v1] { return v1; };
                v1 = 0;
                auto j = f2();      // j is 0; f2 refers to v1; it doesn't store it 
            }

        ** NOTE ** When we capture a variable by reference, we must ensure 
            that the variable exists at the time that the lambda executes.

            As a rule, we can avoid potential problems with captures by minimizing the data we capture. Moreover,
            if possible, avoid capturing pointers or references.

    || IMPLICIT CAPTURES ||
        Rather than explicitly listing the variables we want to use from the enclosing function, we can let the compiler
        infer which variables we use from the code in the lambda's body. 

        & tells the compiler to capture by reference
        = tells the compiler to capture by value

    || LAMBDA CAPTURE LIST ||
        []                      Empty capture list. Lambda may not use variables from enclosing function.
        [names]                 names is a comma-separated list of names local to the enclosing function. By default, variables in capture 
                                list are copied. Name preceeded by & is captured by reference
        [&]                     Implicit by reference capture list. Entities from enclosing function used in lambda body are used by reference
        [=]                     Implicit by value capture list. Entities from enclosing function used in lambda body are copied into lambda body.
        [&, identifier_list]    Identifier_list is a comma-separated  list of 0 or more variabled from the enclosing function. These variables
                                    are captured by value; any implicitly captured variables are captured by reference.
        [=, reference_list]     Reference_list variables are captured by reference. Any implicitly captured variables are captured by value.

    || MUTABLE LAMBDAS ||
        By default, a lambda may not change the value of a variable that it copies by value. If we want to be able to change the value
            of a captured variable, we must follow the parameter list with the keyword mutable. Lambdas that are mutable
            may not omit the parameter list.

    || SPECIFYING THE LAMBDA RETURN TYPE ||
        By default, if a lambda body contains any statements other than a return, that lambda is assumed to return void.
            Like other statements that return void, lambdas inferred to return void may not return a value.
        
    || THE LIBRARY BIND FUNCTION ||
        Bind is defined in the functional header and can be thought of as a general-purpose function adaptor.
            It takes a callable object and generates a new callable that "adapts" the parameter list of the original object.
    
        General Form:       auto newCallable = bind(callable, arg_list);
            When we call newCallable, callable is called, passing the arguments in arg_list

        Using bind, we can replace our original lambda-based call function to find_if with one using check_size
        auto wc = std::find_if(words.begin(), words.end(), [sz](const std::string &s) { return s.size() >= sz; });
        auto wc = std::find_if(words.begin(), words.end(), std::bind(check_size, std::placeholder::_1, sz));

*/
void elimDupes(std::vector<std::string> &s) {
    std::sort(s.begin(), s.end());
    auto u = std::unique(s.begin(), s.end());
    s.erase(u, s.end());
}

void print(const std::vector<std::string> &s) { for (auto &c : s) { std::cout << c <<std::endl; } }

// Reference captures are sometimes necessary. We might want our biggies function to take a &ostream 
//  on which to write and a character to use as the separator
/*
void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz, std::ostream &os = std::cout, char c = ' ') {
    // code to reorder words as before
    elimDupes(words);
    auto i = std::stable_partition(words.begin(), words.end(), [sz](const std::string &s) { return s.size() >= sz; } );
    words.erase(i, words.end());

    std::for_each(words.begin(), words.end(), [&os, c](const std::string &s) { os << s << c; });

}
*/

void biggies2(std::vector<std::string> &words, std::vector<std::string>::size_type sz, std::ostream &os = std::cout, char c = ' ') {
    
    // os implicitly captured by reference; c explicitly captured by value
    std::for_each(words.begin(), words.end(), [&, c](const std::string &s) { os << s << c; });

    // os explicitly captured by referece; c implicitly captured by value
    std::for_each(words.begin(), words.end(), [=, &os](const std::string &s) { os << s <<c ; });
}

void mutable_lambda() {
    std::size_t v1 = 42;        // local variable;
    
    // f can change the value of the variable it captures
    auto f = [v1] () mutable { return ++v1; };
    v1 = 0;
    auto j = f();           // j is 43
    
    // v1 is a reference to a nonconst variable
    // we can change that variable through the reference inside f2
    auto f2 = [&v1] () mutable { return ++v1; };
    v1 = 0;
    auto k = f2();
    std::cout << j << " : " << k <<std::endl;
}

bool check_size(const std::string &s, std::string::size_type sz) {
    return s.size() >= sz;
}

void using_bind() {
    // check6 is a callable object that takes one arg of type string
    // and calls check_size on its given  string and the value of 6
    auto check6 = std::bind(check_size, std::placeholders::_1, 6);

    // check6 only has one placeholder, which corresponds to (const std::string &s) in check_size(), 6 is 
    //      bound to arg 2 of check_size (std::string::size_type sz)

    std::string s("Hello");
    bool b1 = check6(s);
    std::cout << b1 <<std::endl;
}

int main()
{
    std::vector<std::string> s = {"this", "hello", "vectors", "world", "world", "at"};
    //biggies(s, 3);

    
    std::vector<std::string>::size_type sz = 5;
    // sz implicitly captured by value, finds sz in program
    auto wc = std::find_if(s.begin(), s.end(), [=](const std::string &s1) { return s.size() >= sz; });

    //mutable_lambda();

    // use a lambda to replace each negative value in a sequence with its absolute value
    // since return type can be inferred from the type of conditional operator, we don't have to specify the return type
    std::vector<int> vi = {-3,-2,-1,0,1,2,3};
    std::transform(vi.begin(), vi.end(), vi.begin(), [](int i) { return i < 0 ? -i : i; });
    //for (auto &i : vi) { std::cout << i <<std::endl; }

    // error: cannot deduce the return type for lambda
    // std::transform(vi.begin(), vi.end(), vi.begin(), [](int i) { if (i < 0) return -i; else return i; });

    // When we need to define a return type for a lambda, we must use a trailing return type
    //   the -> after the parameter int denotes a return value of int
    std::transform(vi.begin(), vi.end(), vi.begin(), [](int i) -> int {if (i < 0) return -i; else return i; });

    // bind function practice
    using_bind();

    return 0;
}