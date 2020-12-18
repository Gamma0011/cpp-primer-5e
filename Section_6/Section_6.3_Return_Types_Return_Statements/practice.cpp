#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// return statement terminates the function that is currently executing and returns control to the point from which the function was called;
// Two forms: 
//      return;
//      return expression;

void swap(int &v1, int &v2)
{
    // if the values are already the same, no need to swap, just return;
    if (v1 == v2) {
        return;         // this return type may only be used with void. Implicit return at end of void, but pre-end
                        //  denotes an intentional break in the function, kind of like a break statement;
    }     
    // if we're here, there's work to do;
    int tmp = v2;
    v2 = v1;
    v1 = tmp;
    // no explicit return necessary, values have been swapped;
}

bool str_subrange(const string &str1, const string &str2) 
{
    if (str1.size() == str2.size()) {
        return str1 == str2;            // returns bool;
    }
    // find the smaller string;
    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();

    // look at each element up to the size of the smaller string
    for (decltype(size) i = 0; i != size; ++i) {
        if (str1[i] != str2[i]) {
            return str1[i] != str2[i];
        }
    }
    return str1 == str2;
}

// how values are returned
// return the plural version of the word if ctr is greater than 1
string make_plural(size_t ctr, const string &word, const string &ending) 
{
    return (ctr > 1) ? word + ending : word;
}

// return a reference to the shorter of two strings
const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

/*  NEVER RETURN A REFERENCE OR POINTER TO A LOCAL OBJECT - this is an example of that
        Storage in which the local objects reside is cleared when the function ends, therefores, both returns refer to memory no longer available

    const string &manip()
    {
        string ret;
        if (!ret.empty()) {
            return ret;             // WRONG: returning a refrence to a local object;
        } else {
            return "EMPTY";         // WRONG: "Empty" is a local temporary string;
        }
    }

    // **NOTE** One way to ensure that the return is safe, is to ask:
    //            "To what preexisting object is the reference referring?"

*/

// reference returns are Lvalues
char &get_val(string &str, string::size_type ix) 
{
    return str[ix];         // get_val assumes the given index is valid
}

// if the return type is a const&, then we may not assign to the result of the call:
//      shorterString("hi", "bye") = "X";       // error: return value is const



// List Initializaing the Return Value
//   Functions can return a braced list of values.
vector<string> process()
{
    string expected("expected");
    string actual("actual");
    // expected and actual are strings
    if (expected.empty()) {
        return {};      // return an empty vector;
    } else if (expected == actual) {
        return {"functionX", "okay"};
    } else {
        return {"functionX", expected, actual};
    }


}

int main()
{
    /*
    size_t counter = 2;
    string item("parrot");
    string plural("s");
    cout << make_plural(counter, item, plural) <<endl;

    string s1("Hello World!");
    string s2("Hi!");

    // Functions that return Class Types and the Call Operator
    // Because of associativity and precedence, if a function returns a pointer, reference or an object of class type,
    //  we can use the result of a call to call a member of the resulting object;
    auto sz = shorterString(s1,s2).size();
    cout << sz <<endl;
    */

   /* reference returns are Lvalues
   string s("a value");
   cout << s <<endl;        // prints a value
   get_val(s, 0) = 'A';     // changes s[0] to A
   cout << s <<endl;        // print A value
    */



    return 0;
}
