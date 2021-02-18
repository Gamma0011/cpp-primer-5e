#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

/*
    e14.38  - Write a class that tests whether the length of a given string matches a given bound. Use that object to write a program
                to report how many words in an input file are of sizes 1 through 10 inclusive
*/

class CheckSize {
public:
    CheckSize(std::string &s) : sz(s.size()) { } ;
    bool operator()(const std::string &s) const { return s.size() <= limit; }
private:
    std::size_t sz;
    const std::size_t limit = 10;
};


int main(int argi, char **argc)
{



    return 0;
}