#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// functions that have the same name, but different parameters in the same scope are overloaded.

/* defining overloaded functions. In the case below, these overloaded functions let us define how the function lookup does its search

    Record lookup(const Account&);          // find by Account
    Record lookup(const Phone&);            // find by Phone
    Record lookup(const Name&);             // find by Name
    Account acct;
    Phone phone;
    Record r1 = lookup(acct);               // call version that takes an Account
    Record r2 = lookup(phone);              // call version that takes a Phone


We can overload based on whether the parameter is a reference or a pointer to the const or nonconst version of a given type
    // functions taking const and noncost references or pointers have different parameters
    Record lookup(Account&);                // function takes a reference to Account
    Record lookup(const Account&);          // function takes a const references to Account
    Record lookup(Account*);                // function takes a pointer to Account
    Record lookup(const Account*);          // function takes a const pointer to Account


*/

/* 

// this function takes and returns const string&. We can call nonconst string&, but we'll get const string& as a result

string &shorterString(string &s1, string &s2)
{
    return (s1.size() <= s2.size() ? s1 : s2);
}
*/

// here, we can have the compiler yield plain &  when nonconst string& are passed.
string &shorterString(string &s1, string &s2)
{
    auto &r = shorterString(const_cast<const string&>(s1), 
                            const_cast<const string&>(s2));
    return const_cast<string&>(r);

}


int main()
{
    string so = "Hello World!";
    string sp = "Hit me baby one more time";
//    cout << shorterString(so, sp) <<endl;


    return 0;
}
