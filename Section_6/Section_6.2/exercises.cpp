#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

 void reset(string &s)
 {
     s = "Reset!";
 }

int e612(int &a, int &b)
{
    // rewrite e610 to swap numbers using references instead of pointers
    // which do you think is easier? I prefer references no need to pass &x &y in function call, but I see how pointers could be useful. 
    int tmp = a;
    a = b;
    b = tmp;
    return a, b;
}

void e613()
{
    // assuming T is a type, explain the difference between a function declared as void f(T) and void f(T&)
    // void f(T) argument passed by value. Nothing can be done to effect the argument
    // void f(T&) argument passed by reference, bound to whatever object we pass
}

void e614()
{
    // give an example of when a parameter should be a reference type
            // void reset(int &i) { i = 0; }

    /* give an example of when a parameter should not receive a reference
        
        ** see void count(); **
        no need to pass char by reference since there's no intent to change char c declaration
    */

}

void e615()
{
    // explain the rational behind the type of each of find_char's parameters?
    // why is s ref to const? - don't want to copy or change s, therefore &s references the string, but cannot change it;
    // why is occurs a plain reference? - we need to change occurs to update the counter of how many times c occurs in s;
    // why is char c not a reference?  - we don't want to change char c and is a temp variable in this function
    // what would happen if we made s a &? - s could possibly be changed or altered in the function.
    // what if we made occurs const &?  - occurs counter would not be able to update. Therefore counter would be what it was initialized as.

}

void count(string &s, char c, int &count) 
{
    for (decltype(s.size()) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            ++count;
        }
    }
}

// e616
// bool is_empty(string&s) should be:
bool is_empty(const string &s) 
{
    return s.empty();
}
// Function does not change the argument, so therefore const should be passed

// e617 - parameters used in bool is_capital() and void to_lower() are not the same type, is capital is a const reference
//  because we want to preserve the arguments, while to_lower is a reference to the string, because we want to change it;
bool is_capital(const string &s)
{
    for (auto c : s) {
        if (isupper(c)) {
            return true;
        }
    }
    return false;
}

void to_lower(string &s) 
{
    for (decltype(s.size()) i = 0; i != s.size(); ++i) {
        s[i] = tolower(s[i]);
    }
}


// e618 a
// write a function named compare that returns bool and has two parameters that are references to class named matrix
/*
bool compare(matrix &m1, matrix &m2) {};
*/

// e618 b
// a function named change_val that returns a vector<int> iterator and takes two parameters, one is an int and the other is an iterator for vector<int>
/*
vector<int>::iterator change_val(int, vector<int>::iterator) {}:
*/

void e619()
{
    /* given the following declarations, determine which calls are legal and which are illegal, why?

    double calc(double);
    int count (const string &, char);
    int sum(vector<int>::iterator, vector<int>::iterator, int);
    vector<int> vec(10);

    a) calc(23.4, 55.1);            illegal, calc only accepts one argument
    b) count("abcda", 'a');         legal
    c) calc(66);                    legal
    d) sum(vec.begin(), vec.end(), 3.8);    legal, 3.8 will be trunicated to int
    */
    double calc(double);
    int count (const string &, char);
    int sum(vector<int>::iterator, vector<int>::iterator, int);
    vector<int> vec(10);
}

void e620()
{
    // when should reference parameters bbe references to const
    // what happens if we make a parameter a plain reference when it should be reference to const

    // we should use const & whenever we have no intention of intenionally or accidentally changing the parameter
    // plain & should only be used if we aim to change the passed argument in some way
}


int main()
{
    // testing void reset();
    /*
    string s2 = "Hello World";
    cout << s2 <<endl;
    reset(s2);
    cout << s2 <<endl;

    // e612 test
    for (int x, y; cout << "Enter two numbers: ", cin >> x >> y;) {
        e612(x,y);
        cout << x << " : " << y <<endl;
    }
    

    string s1 = "This is a string.";
    char c1 = 't';
    int counter = 0;
    count(s1, c1, counter);
    cout << c1 << " occurs " << counter << " times in the string: " << s1 <<endl;

    */

   string s1 = "Hello WOrld.";
   cout << is_capital(s1) <<endl;
   to_lower(s1);
   cout << s1 <<endl;
    return 0;
}
