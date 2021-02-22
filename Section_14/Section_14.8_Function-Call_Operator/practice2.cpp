#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <functional>

/*
    || LIBRARY-DEFINED FUNCTION OBJECTS ||
        The standard library defines a set of classes that represent arithmetic, relational, and logical operators.
        These classes are templates to which we can supply a single tye. That type specifies the parameter type
         for the call operator. plus<std::string> applies the string addition operator to string objects. plus<int> 's 
         operands are ints, plus<Sales_data> + to Sales_datas, etc.

            see. void functionObjects();

        | Library Function Objects |
            ARITHMETIC
            plus<type>
            minus<type>
            multiplies<type>
            divides<type>
            modulus<type>
            negate<type>

            RELATIONAL
            equal_to<type>
            not_equal<type>
            greater<type>
            greater_equal<type>
            less<type>
            less_equal<type>

            LOGICAL
            logical_and<type>
            logical_or<type>
            logical_not<type>

        | USING A LIBRARY FUNCTION OBJECT WITH THE ALGORITHMS |
            The function-object classes that represent operators are often used to override the default operator used by the algorithm.
            
            *passes a temporary function object that applies the > operator to two strings
                std::sort(svec.begin(), svec.end(), greater<string>());
            *Rather than calling sort's default < operator, greater applies > operator to string elements.

            One important aspect of these library function objects is that the library guarantees that they will work for pointers. 
            For example, we might want to sort a vector of pointers based on their addresses in memory. Although it would be undefined
             for us to do so directly, we can do this through one of the library function objects.

                see. void sortingPointers();

            *The associative containers use less<key_type> to order elements. As a result, we can define a set of pointers or use a pointer
            * as the key to a map without specifying less directly.
        
        | CALLABLE OBJECTS AND FUNCTIONS | 
            There are several kinds of callable objects:
                - Functions and pointers to functions
                - Lambdas
                - Objects created by Bind
                - Classes that overload function-call operator
            
            Every callable object has a type. For example, each lambda has its own unique (unnamed) class type.
            However, two callable objects with different types may share the same call signature. 
        
        | DIFFERENT TYPES CAN HAVE SAME CALL SIGNATURE |
            Sometimes we want to trade several callable objects that share a call signature as if they had the same type.

            Ordinary function   - int add(int i, int j) { return i + j; }
            Lambda              - auto mod = [](int i, int j) { return i % j; };
            Function-object Class - struct divide { int operator()(int denominator, int divisor) { return denominator/divisor; } };

            All of these apply a unique operator to its parameters, but they share the same call signature -- int(int, int);

            We might want to use these callables to build a simgple desk calculator. To do so, we'd need to define a function table
             to store "POINTERS" to these callables.

            Function tables are easy to implement using a map. When we want to evaluate a given operator, we'll index the map with that
             operator and call the resulting element.  

             see. void callSignaturePractice();

             Because lambdas have their own class type, it does not match the type of values storaed in binops int(*)(int, int)

             Using a library type named FUNCTION, defined in <functional> header can fix this.

                SYNTAX: function<int(int, int)> OR function<TYPE>

            A function type can represent a callable object that return a result to its parameters.
                see. void functionTypePractice();
            
            We can now also redefine our map to use the function type.

                std::map<std::string, std::function<int(int, int)>> binops;

                std::map<std::string, std::function<int(int, int)>> binops = {
                    {"+", add},                     // function pointer
                    {"-", std::minus<int>()},       // library function object
                    {"/", divide()},                // user-defined function object
                    {"*", [](int i, int j) { return i * j; }},
                    {"%", mod}                      // named lambda object
                };

            When we index a map, we get a & to the associated value. When we index binops, 
             we get a & to an object of type function. This function type overloads the call operator,
             which then takes its own arguments and passes them along to its stored CALLABLE object.

            binops["+"](10,5);      // calls add(10,5)
            binops["-"](10,5);      // calls minus<int>()
            binops["/"](10,5);      // calls divide() -- int operator()(int, int)
            binops["-"](10,5);      // calls minus<int>()
            binops["*"](10,5);      // calls lambda function object
            binops["%"](10,5);      // calls lambda function object

        | OVERLOADED FUNCTIONS AND std::function |
            We cannot (directly) store the name of an overloaded function in an object of type function:

                int add(int i, int j) { return i + j; }
                Sales_data add(const Sales_data&, const Sales_data&);
                std::map<std::string, std::function<int(int, int)>> binops;
                binops.insert( {"+", add} );    // error: which add?
            
            One way to resolve this is to store a function pointer istead of the function name:
                int (*fp)(int, int) = add;      // pointer to the version of add that takes 2 ints;
                binops.insert( {"+", fp});      // ok: fp points to the right version of add
            
            Another way, using lambdas:
                binops.insert( { "+", [](int i, int j) { return add(i, j);} });
            
            The call inside the lambda body passes 2 ints. That call can match only the version of add that takes 2 ints.

            *NOTE* Function class in the new library is not related to unary_function and binary_function

        | OPERATIONS ON FUNCTION |
        
        function<T> f;              f is a null function object that can store callable objects with call signature == function type T
        function<T> f(nullptr);     explicitly construct null function
        function<T> f(obj);         stores a copy of the callable object obj in f
        f                           use f as a condition. True if f holds callable object, otherwise false
        f(args);                    calls the objects in f passing args

        | TYPES DEFINED AS MEMBERS OF FUNCTION<T> |
        result_type                 type returned by this function type's callable object
        argument_type               types defined when T has exactly 1 or 2 args
        first_argument_type         if T has 1 arg, synonym for that type
        second_argument_type        if T has 2 args, synonym for second type

*/

struct divide {
    int operator()(int denominator, int divisor) { 
        return denominator/divisor; 
    }
};


void functionObjects() {
    std::plus<int> intAdd;      // function object that can add two int values
    std::negate<int> intNegate; // function object that can negate two ints
    
    // uses intAdd::operator(int, int) to add 10 and 20
    int sum = intAdd(10, 20);           // equivalent to sum = 30;
    sum = intNegate(intAdd(10, 20));    // equivalent to sum = 30;

    // uses intNegate::operator(int, int) to generate -10 as second parameter
    sum = intAdd(10, intNegate(10));    // sum = 0
}

void sortingPointers() {
    std::vector<std::string *> nameTable;       // vector of pointers
    
    // error: the pointers in nameTable are unrelated, so < is undefined.
    // std::sort(nameTable.begin(), nameTable.end(), [](std::string *a, std::string *b) { return a < b; });

    // ok: library guarantees that less on pointer types is defined
    std::sort(nameTable.begin(), nameTable.end(), std::less<std::string*>() );
}

int add(int i, int j) { 
    return i + j; 
} 

void callSignaturePractice() {
    auto mod = [](int i, int j){ return i % j; };

    // maps an operator to a pointer to a function taking two ints and returning an int.
    std::map<std::string, int(*)(int, int)> binops;

    // ok: add is a pointer to function of the appropriate type.
    binops.insert({"+", add});  // {"+", add} is a pair
    // error: mod is not a pointer to a function
    // binops.insert({"%", mod}); 
}

void functionTypePractice() {
    std::function<int(int, int)> f1 = add;                  // function pointer
    std::function<int(int, int)> f2 = divide();             // object of a function-object class
    std::function<int(int, int)> f3 = [](int i, int j) {    // lambda
        return i * j;
    };

    auto mod = [](int i, int j){ return i % j; };

    // map to hold table of callable objects corresponding to binary operator
    std::map<std::string, std::function<int(int, int)>> binops = {
        {"+", add},                     // function pointer
        {"-", std::minus<int>()},       // library function object
        {"/", divide()},                // user-defined function object
        {"*", [](int i, int j) { return i * j; }},
        {"%", mod}                      // named lambda object
    };

    binops["+"](10,5);      // calls add(10,5)
    binops["-"](10,5);      // calls minus<int>()
    binops["/"](10,5);      // calls divide() -- int operator()(int, int)
    binops["-"](10,5);      // calls minus<int>()
    binops["*"](10,5);      // calls lambda function object
    binops["%"](10,5);      // calls lambda function object

}


int main()
{
    functionTypePractice();

    return 0;
}