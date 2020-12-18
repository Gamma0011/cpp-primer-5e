#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;


void e36()
{
    // use range for to change all characters in a string to X
    string s = "Hello World!";
    cout << s <<endl;

    for(decltype(s.size()) position = 0; position != s.size(); ++position){
        s[position] = 'X';
    }
    cout << s <<endl;
}

void e38(){
    // rewrite e36 as while loop
    string s = "Hello World!";
    cout << s <<endl;

    decltype(s.size()) position = 0;      // create position tracker
    while(position != s.size()){
        s[position] = 'X';
        ++position;
    }
    cout << s <<endl;
}

void e39()
{
    // this program declares a string variable called s then asks c++ to print out the first character of the string.
    // this is an empty string, so nothing will be output
    string s;
    cout << s[0] <<endl;
}

void e310()
{
    // write a program that reads a string of characters including punctuation, but returns what was read minus punctuation

    string s = "!! Hello? World**";
    cout << s <<endl;

    for (decltype(s.size()) position = 0; position != s.size(); ++position){
        if(ispunct(s[position])){
            s[position] = ' ';
        }
    }
    cout << s <<endl;

}

void e311()
{
    // the range for is legal the type c is of const char &
    const string s = "Keep out!";
    for (auto &c : s){
    }
    cout << s <<endl;
}

int main()
{
    //e36();
    //e37();    // X is defined as const char* and not string
    //e38();      // I prefer the for loop, it's more compact and information is contained within loop rather than declared before loop
    //e39();
    //e310();
    //e311();

    return 0;
}