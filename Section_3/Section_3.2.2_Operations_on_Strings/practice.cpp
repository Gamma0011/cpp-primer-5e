#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    string s = "hello world!";

    if (!s.empty()){
        cout << s[0] <<endl;
    }

    if (!s.empty()){
        s[0] = toupper(s[0]);
    }
    cout << s <<endl;

    // process characters in s until we run out of characters or hit a whitespace
    for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)
        s[index] = toupper(s[index]); // capitalize current character
    
    cout << s <<endl;

    return 0;
}
