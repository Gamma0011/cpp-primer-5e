#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

// ** NOTE ** in C++, name lookup preceeds type checking. print & print found, then (int) vs (string) selected

/*
string read();

void print(const string&);
void print(double);             // overloads the print function

void fooBar(int ival)
{
    bool read = false;          // new scope: hides the outer declaration of read;
    string s = read();          // error: read is a bool variable, not a function;
    // bad practice: usually it's a bad idea to declare functions at local scope!!
    void print(int);            // new scope: hides the previous instances of print
    print("Value: ");           // error: print (const string&) is hidden, currently print accepts arguments of type int
    print(ival);                // okay: print(int) available
    print(3.14);                // okay: calls print(int); but print(double) hidden. Value is trunicated
}
*/

// redoing this to resolve these calls differently by declaring functions at global scope rather than local
void print(const string&);
void print(double);             // overloads print function
void print(int);                // another overloaded instance
void foobar(int ival)
{
    print("Value: ");           // calls print(const string&);
    print(ival);                // calls print(int);
    print(3.14)                 // calls print(double);

}

int main()
{

    return 0;
}
