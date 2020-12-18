#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

/*
    e10.29  - Write a program using stream iterators to read a text file into a vector of strings.
*/

int main(int argi, char **filePath) 
{   
    std::ifstream open(filePath[1]);
    std::vector<std::string> svec;          // vector to hold input
    std::istream_iterator<std::string> ifs(open), eof;      // istream for reading open and end-of-file iterator

    if(open) {
        std::copy(ifs, eof, std::back_inserter(svec));      // write filePath input into svec
        std::copy(svec.cbegin(), svec.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));    // print elements in svec
    } else {
        std::cerr << "ERROR: No File." <<std::endl;
        return -1;
    }


    return 0;
}