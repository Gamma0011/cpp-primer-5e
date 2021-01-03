#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <memory>
#include <new>

/*
    e12.23  - write a program to concatentate two string literals, putting the result in a dynamically allocated array of char. write a program to concatentate two library
                strings that have the same value as the literals used in the first program

*/

void e1223sl() {
    const char* a = "Hello";
    const char* b = "World";
    char s[std::strlen(a) + std::strlen(b)];
    std::strcpy(s, a);
    std::strcat(s, b);

    std::unique_ptr<char[]> c(new char[std::strlen(s)]);

    for (std::size_t i = 0, sz = std::strlen(s); i != sz ; ++i ) { c[i] = s[i]; }      // add char to dynamically-allocated array c
    for (std::size_t i = 0, sz = std::strlen(s); i != sz ; ++i ) { std::cout << c[i];}
    c.release();                                                                // released allocated memory
    std::cout << "\nReleased from memory." <<std::endl;
}

void e1223ls() {
    std::string a("Hello"), b("World");
    std::string s = a + b;

    std::unique_ptr<char[]> c(new char[s.length()]);
    for (std::size_t i = 0, sz = s.length() ; i != sz ; ++i) { c[i] = s[i]; }               // write char elements to c
    for (std::size_t i = 0, sz = s.length() ; i != sz ; ++i) { std::cout << c[i];}          // read char elements from c

    c.release();                                                                            // deallocate memory
    std::cout << "\nMemory Released." <<std::endl;

}

int main()
{
    //e1223sl();
    e1223ls();

    return 0;
}