#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

/*
    e14.39  - Revise the previous program to report the count of words that are sizes 1 through 9 and 10 or more.
                Default-initialize parameter upper limit. 
*/

class CheckSize {
public:
    CheckSize(std::size_t l, std::size_t u = -1) : lower(l), upper(u) { } ;
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

    std::size_t upper = 10, lower = 1, max = 100;
    auto range = std::count_if(svec.begin(), svec.end(), CheckSize(lower, upper));
    auto above = std::count_if(svec.begin(), svec.end(), CheckSize(upper));

    std::cout << range << ((range > 1 ) ? " word " : " words ") << "are within bounds " << lower  
              << " and " << upper << "." <<std::endl;
    std::cout << above << ((range > 1) ? " word " : " words ") << "are above " << upper << "." <<std::endl;

    return 0;
}