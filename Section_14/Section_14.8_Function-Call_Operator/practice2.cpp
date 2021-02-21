#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
*/

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


int main()
{


    return 0;
}