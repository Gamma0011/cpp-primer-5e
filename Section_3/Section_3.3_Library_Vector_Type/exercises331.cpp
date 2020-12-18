#include <iostream>
#include <vector>

using std::vector;
using std::string;

void e312()
{
    // which, if any, are an error, explain

    vector<vector<int>> ivec;                   // legal, a vector whose elements are vectors, whose elements are ints;
    //vector<string> svec = ivec;                 // illegal, initialize svec whose elements are strings with ivec, whose elements are ints
    vector<string> svec(10, "null");            // legal, 10 elements initialized to "null"
}

void e313()
{
    // how many elements are there in each of the following vectors? what are the values?
    vector<int> v1;                         // standard initialization, no elements or values;
    vector<int> v2(10);                     // v2 has 10 elements, initialized to 0;
    vector<int> v3(10, 42);                 // v3 has 10 elements, initialized to 42;
    vector<int> v4{10};                     // v4 has 1 element, initialized to 10;
    vector<int> v5{10, 42};                 // v5 has 2 elements, initialized to 10 and 42;
    vector<string> v6{10};                  // v6 has 10 elements, default-initialized
    vector<string> v7{10, "hi"};            // v7 has 10 elements, initialized to "hi"
    
}

int main()
{
    //void e312();
    //e313();

    return 0;
}
