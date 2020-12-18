#include <iostream>
using std::string;

int main()
{
    string s1;              // default initialization, s1 is an empty string
    string s2 = s1;         // s2 is a copy of s1
    string s3 = "hi";       // s3 is a copy of string literal hi
    string s4(10, 'c');     // s4 is cccccccccc
    string s5 = "hiya";     // copy initialization
    string s6("hiya");      // direct initialization
    string s7(10, 'c');     // direct initialization, s7 is cccccccccc

    // when we want to use several values, we can indirectly use the copy form of initialization
    //  by explicitly creating a (temporary) object to copy
    string s8 = string(9, 'u');     // copy initialization, s8 is uuuuuuuuu



    return 0;
}