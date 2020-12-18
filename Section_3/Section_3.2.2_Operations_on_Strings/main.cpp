#include <iostream>
using std::cin;
using std::cout;
using std::string;
using std::endl;

/*

os << s                     writes s onto output stream os, returns os;
is >> s                     reads whitespace-separated string from is into s, returns is;
getline(is, s)              reads a line of input from is into s, return is;
s.empty()                   returns true if s is empty, otherwise, returns false
s.size()                    returns number of characters in s
s(n)                        returns a referenve to the char at position n in s, positions start at 0
s1 + s2                     returns a string that is a concatenation of s1 and s2
s1 = s2                     replaces the characters in s1 with a copy of s2
s1 == s2                    the strings s1 and s2 are equal, if they contain same characters
s1 != s2                    the strings s1 and s2 are different, if they contain different characters
<, <=, >, >=                comparisons are case-sensitive and use dictionary ordering

*/

void hello(){
     // this only reads input up until the first whitespace "hello world" prints "hello"
    string s;           // empty string;
    cin >> s;           // read a whitespace-separated string into s
    cout << s <<endl;   // write s to output
}

void helloworld(){
    // this reads and prints both hello & world
    string s1, s2;              // empty string;
    cin >> s1 >> s2;            // read a whitespace-separated string into s
    cout << s1 << s2 <<endl;    // write s to output
}

int unknown_num_strings(){
    string word;
    while(cin >> word){
        cout << word <<endl;
    }
    return 0;
}

int getline_practice(){
    string line;
    // read input a line at a time until end-of-file
    while(getline(cin, line)){
        cout << line <<endl;
    }
    return 0;
}

void string_empty(){
    string line;
    // read input a line at a time and discard blank lines
    while (getline(cin, line)){
        if(!line.empty()){
            cout << line <<endl;
        }
    }
}

void size_member(){
    string line;
    // read input a line at a time and print lines that are longer than 80 characters
    while(getline(cin, line)){
        if(line.size() > 80){
            cout << line <<endl;
        }
    }
}

int main()
{
    //hello();
    //helloworld();
    //unknown_num_strings();
    //getline_practice();
    //string_empty();
    //size_member();

    return 0;
}

