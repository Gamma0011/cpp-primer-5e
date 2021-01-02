#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "strblobs.h"       // holds StrBlob, StrBlobPtr, and ConstStrBlob classes

// e12.22  - What changes would need to be made to StrBlobPtr to create a class that can be used with a const StrBlob? Define a class named ConstStrBlobPtr that can point to a const StrBlob

int main()
{
    std::fstream openFile("text.txt");

    if(openFile) {
        std::string line;
        StrBlob sb;
        for( ; std::getline(openFile, line) ; sb.push_back(line) );
        for(ConstStrBlobPtr beg(sb.cbegin()), end(sb.cend()); beg != end; beg.incr()) {
            std::cout << beg.deref() << std::endl;
        }
    } else {
        std::cerr << "ERROR: File not found." <<std::endl;
        return -1;
    }

    return 0;
}