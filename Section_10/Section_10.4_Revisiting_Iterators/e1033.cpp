#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>

/*
    e10.33  - Write a function that takes the names of an input file and two output files. The input file should hold ints.
        Using istream_iterator, read the input file, Using ostream_iterator, write the odd numbers into the first input file,
        followed by a space. Write the even numbers into the second input file, each of those values should be separated by a newline
*/

void writeEven(std::vector<int> e) {
    std::ofstream outFile("even.txt");
    std::ostream_iterator<int> output_Iterator(outFile, "\n");
    std::copy(e.begin(), e.end(), output_Iterator);
    outFile.close();
}

void writeOdd(std::vector<int> o) {
    std::ofstream outFile("odd.txt");
    std::ostream_iterator<int> out_Iterator(outFile, " ");
    std::copy(o.begin(), o.end(), out_Iterator);
    outFile.close();
}

int main(int argi, char **filePath)
{
    std::ifstream open(filePath[1]);
    std::istream_iterator<int> ifs(open), eof;
    std::vector<int> even, odd;

    if(open) {
        while(ifs != eof) {
            if(*ifs % 2) {          // int is odd
                odd.push_back(*ifs++);
            } else {                // int is even
                even.push_back(*ifs++);
            }
        }
        writeEven(even);
        writeOdd(odd);
    } else { 
        std::cerr << "ERROR: No File." << std::endl; 
    }

    return 0;
}