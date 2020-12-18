#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::initializer_list;

// C++ provides two primary ways to write a function that takes a varying number of arguments/
// if arguments are of the same tpye, we can pass a library type named initializer_list;
// if arguments vary, we can write a special kind of function, known as a varidic template (covered in Chapter 16)

// C++ also has a special parameter type, ellipsis, which can be used to pass a varying # of arguments;
// NOTE ** ellipsis only used in programs that need to interface to C functions


/*  Operations on initializer_list (exists in #include <initializer_list>)

initializer_list<T> lst;                default initializationl an empty list of elements of type T
initializer_list<T> list{a,b,c,...}     lst has as many elements as there are initalizers; elements are copies of corresponding initializers. elements in list are const
lst2(lst)                               *copying or assigning an initializer_list does not copy the elements
lst2 = lst;                                 after the copy, the original and the copy SHARE the elements*
lst.size();                             # of elements in the list
lst.begin();                            returns pointer of first element;
lst.end();                              returns 1 past the pointer of the last element;



LIKE vector, initializer_list is a template type. When we define initializer_list, we must specify the type of elements it will contain
UNLIKE vector, initializer_list are always const calues, no way to change the value of an element in an initializer_list

_____________________


Ellipsis Parameters allow programs to interface to C code that uses a C library named varargs.
 Generally, elipsis parameters should not be used for other purposes, and only used for types common to both C and C++.
 Most class types are not copies properly when passes to an ellipsis parameter.



 void foo(parm_list, ...);          // type checking passed arguments against parm_list
 void foo(...);                     // no type checking for any passes arguments

*/


void error_msg1(initializer_list<string> il) 
{   
    for(auto beg = il.begin(); il.begin() != il.end(); ++beg) {
        cout << *beg << " ";
    }
    cout <<endl;
}
/*
void error_msg2(ErrCode e, initializer_list<string> il1) 
{
    cout << e.msg() << ": ";
    for (const auto &elem : il1) {
        cout << elem << " ";
    cout <<endl;
    }
}
*/

int main()
{
    //std::initializer_list<string> ls;   // initializer_list of strings
    //initializer_list<int> li;           // initializer_list of ints

    string expected("Expected");
    string actual("Expected");

    if (expected != actual) {
        error_msg1({"functionX", expected, actual});
    } else {
        error_msg1({"functionX", "okay"});
    }

    return 0;
}
