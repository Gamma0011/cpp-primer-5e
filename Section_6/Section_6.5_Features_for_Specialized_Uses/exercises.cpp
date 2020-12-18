#include <iostream>
#include <vector>
#include <cassert>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// ** NOTE ** The constexpr specifier declares that it is possible to evaluate the value of the function or variable at compile time. 

//e640 - which, if either, of the following declarations are errors? Why?
// in order to declare default arguments, all args to the right of an arg declaration must also be declared
//  this is why char *int errors. wd and background must be defined since they're right of ht
int ff(int a, int b = 0, int c = 0);                // this is okay. 
//char *init(int ht = 24, int wd, char background);   // missing default arg for wd and background.

//e641 - which of the following calls are illegal. why?
// which are legal but unlikely to match the programmer's intent, why?

char *init(int ht, int wd = 80, char background = ' ');
//init(); // this call is illegal, requires at least one argument
//init(24, 10); // this call is legal. init(24, 10, ' ');
// init(14, '*'); // this call is legal, but will unlikely match the programmer's intent. * will be converted to hexadecimal number and declared as int rather than char

// e642 - give the second parameter of make_plural a default argument of 's'
// test by pluralizing success and failure

// e646 - would it be possible to define isShorter() as a constexpr?
// no, because isShorter() would not return a literal type

string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

// e643 - which of the following declarations and defintions would you put in a header? In a source file? Why?
// inline function should be put into a header file
// inline bool eq(const BigInt&, const BigInt&) {};
// this is the declaration of a useful function, can also end up in header file
void putValue(int *arr, int size);

// e644 - rewirte the isShorter function to be inline
inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

/* e645 - review the programs you've written from earlier exercises and decide whether they should be define as line.
   if so, do so, if not, explain why

this is no possible since std::string::size is not a constant expression function and s1.size() == s2.size() is not a constexpr
 since bool isShorter2() cannot be evaluated at compile time, it fails.

constexpr bool isShorter2(const string &s1, const string &s2)
{

    return s1.size() < s2.size();
}

*/

int main()
{
    cout << make_plural(1, "failure") <<endl;
    cout << make_plural(2, "failure") <<endl;

    cout << make_plural(1, "success") <<endl;
    cout << make_plural(2, "success", "es") <<endl;

    cout << isShorter("test", "meeting") <<endl;


    // e648 - explain what this loop does and whether it is a good use of assert
    // This is not good use of assert because cin always (unless CTRL + D) resolves as true. 
    //  assert(s == sought); is better
    string s;
    string sought = "yes";

    while (cin >> s && s != sought) {};     // empty body
    assert(cin);

    return 0;
}

