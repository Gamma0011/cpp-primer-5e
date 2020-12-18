#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


/*
    for statement syntax:

        for (init-statement condition; expression)
            statement

    syntax can also be thought of as:
    
        for (initializer; condition; expression)
            statement

*/

void forstatement()
{
    // process characters in s until we run out of characters or hit a whitespace

    string s("hello world");

    /* Steps:
        1) init-statement executed once at the start of loop. index defined and initalized to zero
        2) condition check for true/false.: index != s.size() && !isspace(s[index])
            if condition == true, execute statement
        3) statement: s[index] = toupper(s[index]);
        4) expression evaluated: ++index


    */

    for (decltype(s.size())index = 0; index != s.size() && !isspace(s[index]); ++index) {
        s[index] = toupper(s[index]);       // capitalize the current character
    }

    cout << s <<endl;
}

void multipledefsinforheader()
{
    vector<int> v = {1,2};
    // remember size of v and stop when we get to the last element
    for (decltype(v.size()) i = 0, sz = v.size(); i != sz; ++i) {
        v.push_back(v[i]);
    }

    for (auto cnt : v) {
        cout << cnt << '\t';
    }
}

void omittingpartsforheader()
{
    vector<int> v = {1,2,3,4};

    auto beg = v.begin();
    
    for (/* no initializer */; beg != v.end() && *beg >= 0; ++beg) {
        ;           // nothing to do;
    }
    

    /*  we can exclude a condition, but something within the loop must break it or else it'll continue indefinitely.

    for (int i = 0; /* no condition /; ++i ) {
        ;
    }
    */

   // we can also exclude the expression from a for header

   vector<int> ivec;

   for (int i; cin >> i; /* no expression */) {
       v.push_back(i);
    }
}

int main()
{
    //forstatement();
    //multipledefsinforheader();

    return 0;
}
