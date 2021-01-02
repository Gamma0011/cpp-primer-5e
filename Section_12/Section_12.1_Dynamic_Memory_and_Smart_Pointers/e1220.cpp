#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>

#include "strblobs.h"

// e12.20   - Write a program that reads an input file a line at a time into a StrBlob and uses a StrBlobPtr to print each element in that StrBlob 

int main(int argi, char **argc) 
{
    //std::ifstream openFile(argc[1]);
    std::ifstream openFile("text.txt");

    if(openFile) {
        std::string line;
        StrBlob sb;
        for ( ; std::getline(openFile, line) ; sb.push_back(line) );                    // write lines to StrBlob object
        for (StrBlobPtr beg(sb.begin()), end(sb.end()) ; beg != end ; beg.incr()) {     // read elements via StrBlobPtr
            std::cout << beg.deref() <<std::endl;
        }
    } else {
        std::cerr << "ERROR: File not found." <<std::endl;
        return -1;
    }

    return 0;
}