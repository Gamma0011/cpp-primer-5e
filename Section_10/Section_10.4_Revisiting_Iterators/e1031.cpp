#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

// Update the program from the previous exercise so that it prints only the unique elements. Use unique_copy

int main(int argi, char **filePath) 
{   
    std::vector<std::string> svec;
    std::fstream open(filePath[1]);         // opens argument
    std::istream_iterator<std::string> ifs(open), eof;

    if(open) {
        std::unique_copy(ifs, eof, std::back_inserter(svec));
        std::copy(svec.cbegin(), svec.cend(), std::ostream_iterator<std::string>(std::cout, " "));
    } else {
        std::cerr << "ERROR: No File." <<std::endl;
    }

    return 0;
}