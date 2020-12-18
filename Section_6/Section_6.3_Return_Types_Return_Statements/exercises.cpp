#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void e630()
{
    // compile the version of str_subrange on pg 223 to see what your compilr does with indicated error
    //  see bool str_subrange
}

/*
bool str_subrange(const string &str1, const string &str2)
{
    // same sizes: return normal equality
    if (str1.size() == str2.size()) {
        return str1 == str2;
    }                               // okay: returns bool
    auto size = (str1.size() < str2.size() ? str1.size() : str2.size());
    for (decltype(size) i = 0; i != size; ++i) {
        if (str1[i] != str2[i]) {
            return ;            // error #1: no return value, compilers hould detect this error
        }
    }
    // error #2: control might flow off the end of the function with a return
    // compiler might not detect this error
}
*/

void e631()
{
    // when is it valid to return a reference? a reference to const?
    // Return a reference: When the reference exists as a global object. References of local objects cannot be returned as they exist with scope of function
}

// e632
int &get(int *array, int index) {return array[index];}
// this is a legal function, gave values 0-9

void e633(vector<int>::const_iterator begin, vector<int>::const_iterator end)
{
    // write a recursion function to print the contents of a vector;
    if (begin != end) {
        cout << *begin << '\t';
        e633(++begin, end);
    }
}

void e634()
{
    // what would happen if the stopping condition in factorial were if (val != 0)
    // see int factorial()

    // case 1: if int is positive, function stops at 0;
    // case 2: if int is negative, function never stops;
}

int factorial(int val)
{
    if (val != 0) {
        return factorial(val-1) * val;
    }
    return 1;
}

void e635()
{
    // in factorial(), why did we pass val-1 instead of val--;

    // we get a segmentation fault error. val is being decremeneted postfix, which causes a recursive loop error; Never any decrementation
    // avoid postfix operators whenever possible
}

// e636 write a function that returns a reference to an array of 10 strings;
// string (func(string (&arrStr)[10]))[10];

// e637 - write 3 additional declarations for function in e636 (alias, trailing return, decltype), which do you prefer?

/* 
Alias

typedef string strT[10];        // strT is synonym for type array of 10 strings;
*strT func(int i);              // func returns a pointer to an array of 10 strings;


Trailing Return
auto func(string s) -> str(*)[10];

Decltype

string s[10];
decltype((s)& func3() )
*/

decltype(odd) &arrRef(int i)
{
    // revise arrPtr function on to return a reference to an array
    return (i % 2) ? odd : even;

}

int main()
{
    int ia[10];
    for (int i = 0; i != 10; ++i) {
        get(ia, i) = i;
    }

    vector<int> ivec = {0,1,2,3,4,5};
    // e633(ivec.begin(), ivec.end());
    
    int i = 3;
    cout << factorial(i) <<endl;

    return 0;
}
