#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void argtoref();
void reset(int &i);
bool isShorter(const string &s1, const string &s2);
string::size_type find_char(const string &s, char c, string::size_type &occurs);
    

int main()
{
    // passing arguments by reference practice
    int j = 42;
    reset(j);                       // j is passed by reference, the falue in j is changed;
    cout << "j = " << j <<endl;     // prints j = 0


    // isShorter test
    cout << isShorter("Theres", "Test!") <<endl;

    // character counter
    string::size_type ctr;
    string s = "Hellooooooo World!";
    char c = 'o';
    cout << "First positional occurence of " << c << " is at " << find_char(s, c, ctr)
         <<  " and " << c << " occurs " << ctr << " times." <<endl;

    return 0;
}

void argtoref()
{
    int n = 0, i = 42;
    int &r = n;         // n is now 42
    r = i;              // n now has the same value as i;
    i = r;              // i has the same value as n;

}

void reset(int &i)
{
    i = 0;              // changes the value of the object to which i refers
}

// using references to avoid copies && compare the length of two strings
// ***** NOTE ***** REFERENCE PARAMETERS THAT ARE NOT CHANGED INSIDE A FUNCTION SHOULD BE REFERENCES TO CONST
bool isShorter(const string &s1, const string &s2) 
{
    // if s1 < s2, return 1 (true), else 0 (false)
    return s1.size() < s2.size();
}

// returns the index of the first occurance of c in s;
//  the reference parameter occurs counts how often c occurs;   
string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
    auto ret = s.size();            // position of the first occurence, if any
    occurs = 0;                     // set the occurence count parameter

    for (decltype(ret) i = 0; i != s.size() ; ++i) {
        if (s[i] == c) {
            if (ret == s.size()) {
                ret = i;            // remember the first occurence of c (position in string)
            }
            ++occurs;               // incremenet the occurence count
        }
    }
    return ret;                     // count is reference implicitly in occurs
}

