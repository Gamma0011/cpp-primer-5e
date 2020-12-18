#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

/* e649 - what is a candidate function? What is a viable function?

Candidate function - functions who match the named call of a function - ex. int f(int) declared and f(2) called in main();

Viable function - functions whose arguments match number of arguments provided in the function call int f(int, int) is viable for f(10, 1);
*/

/* e650 - given the declarations for f() on pg 242, list the viable functions if any for each of the following calls
        Indicate which function is the best match or if the call is illegal, whether there is no match or why the call is ambiguous

Declarations
void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);

1)      f(2.56, 42)         Viable Functions: f(int, int) && f(double, double)
                            Call is ambigious as both arguments could meet each viable function's requirements
2)      f(42)               Viable Functions: f(int) && f(double, double = 3.14)
                            Best Match: f(int)
3)      f(42, 0)            Viable Functions: f(int, int) && f(double, double)
                            Best Match: f(int, int)
4)      f(2.56, 3.14)       Viable Functions: f(int, int) && f(double, double)
                            Best Match: f(double, double)
*/

// e651 - check e650 to see if you were right
void f() {cout << "No arguments." <<endl;}
void f(int) {cout << "1 int argument." <<endl;}
void f(int, int) {cout << "2 int arguments." <<endl;}
void f(double, double = 3.14) {cout << "2 double arguments." <<endl;}


/* e652 - given the following declarations, what is the rank of each conversion?
    void manip(int, int);
    double dobj;

    a)  manip('a', 'z');        // 3 - match through promotion. type char promoted to type int
    b)  manip(55.4, dobj);      // 4 - arithmetic conversion
*/

// e653 - explain the effects of the second declaration in each one of the following sets of declarations. Indicate which, if any are illegal

int calc(int&, int&);                   // accepts two arguments of references to type int
int calc(const int&, const int&);       // accepts two arguments of & to const ints

int calc(char*, char*);                 // accepts two arguments of pointers to type char
int calc(const char*, const char*);     // accepts two arguments of pointers to const char

int calc(char*, char*);                 // accepts two arguments of pointers to type char           - pointer to a char
int calc(char* const, char* const);     //  same argument as char* because top-level const dropped - const pointer to a char

int main()
{
    //f(2.56, 42);
    //f(42);
    //f(42, 0);
    //f(2.56, 3.14);

    return 0;
}
