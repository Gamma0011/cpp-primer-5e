#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

/*
    e14.38  - Write a class that tests whether the length of a given string matches a given bound. Use that object to write a program
                to report how many words in an input file are of sizes 1 through 10 inclusive
*/

class CheckSize {
public:
    CheckSize(std::size_t u, std::size_t l) : upper(u), lower(l) { } ;
    bool operator()(const std::string &s) const { return s.length() >= lower && s.length() <= upper; }
private:
    std::size_t upper;
    std::size_t lower;
};


int main(int argi, char **argc)
{
    std::vector<std::string> svec;

    // std::ifstream open(argc[1]);
    std::ifstream open("text.txt");
    if(open) {
        std::string line, word;
        while (std::getline(open, line)) {
            std::istringstream read(line);
            while (read >> word) {
                svec.push_back(word);
            }
        }
    } else {
        std::cerr << "ERROR: No File." <<std::endl;
    }

    std::size_t upper = 5, lower = 1;
    auto count = std::count_if(svec.begin(), svec.end(), CheckSize(upper, lower));

    std::cout << count << ((count > 1 ) ? " word " : " words ") << "are within bounds " << upper  
              << " and " << lower << ".";

    return 0;
}