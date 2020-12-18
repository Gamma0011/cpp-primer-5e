#include <iostream>
#include <vector>
#include "Sales_item.h"
// a vector is a collection of objects, all of whcih have the same type
// a vector is often referred to as a container because it 'contains' other objects

using std::vector;
using std::string;

int main()
{

    vector<int> ivec(10);               // ivec holds objects of type int
    vector<Sales_item> Sales_vec;       // holds Sales_items
    vector<vector<string>> file;        // vector whose elements are vectors

    vector<string> svec;                // default initializaton, svec has no elements

    vector<int> ivec2(ivec);            // copy elements of ivec into ivec2
    vector<int> ivec3 = ivec;           // copy elements of ivec into ivec3
    //vector<string> svec(ivec);        // error: svec holds strings, not ints



    // list initializing a vector

    vector<string> articles = {"a", "an", "the"};   // correct list initialization. list of initializers supplied with curly braces
    //vector<string> artciles2 = ("a", "an", "the");  // error, cannot supply a list of initializers with paratheses


    // value initialization
    vector<int> ivec2(10);          // ten elements, each initialized to 0
    vector<string> svec(10);        // ten elements, each an empty string
    //vector<int> v1 = 10;            // ERROR: must use direct initialization.
                                    // Here we are using 10 to instruct a vector that we want it to hold 10 value-initalized elements, not copying 10 into vector.
                                    // we cannot use the copy form of initialization

    // Ways to initialize a vector
    
    // vector<T> v1                 // vector holds objects of type T. default initialization
    // vector<T> v2(v1)             // v2 has a copy of each element in v1
    // vector<T> v2 = v1            // v2 has a copy of each element in v1, equivalent to v2(v1)
    // vector<t> v3(n, val)         // v3 has n elements with value val
    // vector<T> v4(n)              // v4 has n copies of a value-initialized object
    // vector<T> v5{a,b,c}          // v5 has many elements as there are initializers, elements are initialized by corresponding initializers
    // vector<T> v5 = {a,b,c}       // equivalent to v5{a,b,c}


    vector<int> v1(10);             // v1 with 10 elements of value 0;
    vector<int> v2{10};             // v2 with 1 element of value 10;
    vector<int> v3(10,1);           // v3 with 10 elements of value 1;
    vector<int> v4{10,1};           // v4 with 2 elements of values 10 and 1

    // parentheses, values supplied to be used to contruct object
    // curly braces, list initialize the object
    
    //      if no way to list initialize object, values will be used to construct object
    //      examples:
    vector<string> v5{"hi"};        // list initialization, v5 has one element
    vector<string> v5("hi");        // error: can't construct a vector from a string literal
    vector<string> v7{10};          // v7 has 10 default-initialized elements -- 10 was passes as int, not string
    vector<string> v8{10, "hi"};    // v8 has 10 elements with value "hi"



    return 0;
}
