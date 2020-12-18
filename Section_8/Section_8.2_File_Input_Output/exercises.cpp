#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;
using std::ofstream;

/*
    e84 - write a function to open a file for input and read its contents into a vector of strings, storing each line as separate elements in the vector
    e85 - write a function to read each work into a vector
    e86 - rewrite the bookstore program from pg 256 to read its transactions from a file. pass the name of the file as an arg to main (pg 281)
*/

// e84
void ReadLinesToFile(const string &filePath, vector<string> &svec) {     // function accepting args for filePath and vector to hold read lines
    std::ifstream in(filePath);                                     // function in of type ifstream - open filePath
    if (in) {                                                       // check if filePath open
        string buf;                                                 // create string to hold lines read from open file
        while (getline(in, buf)) {                                  // while there are lines to be read from ifstream into buf
            svec.push_back(buf);                                    // write buf to svec
        }
    } else {
        std::cerr << "ERROR: File cannot be opened." <<endl;        // Return error, file cannot be opened.
    }
}

// e85
void ReadWordsToFile(const string &filePath, vector<string> &svec) {
    std::ifstream in(filePath);                                     // function in of type ifstream 
    if (in) {
        string buf;
        while (in >> buf) {
            svec.push_back(buf);
        }
    } else {
        std::cerr << "ERROR: File cannot be opened." <<endl;         
    }
}

int main()
{
    vector<string> books;
    vector<string> words;

    ReadLinesToFile("/Users/stehuene/Documents/_Cpp_Primer_Projects/Section_8/Section_8.2/books.txt", books);
    for (auto b : books) {
        cout << b <<endl;
    }

    ReadWordsToFile("/Users/stehuene/Documents/_Cpp_Primer_Projects/Section_8/Section_8.2/books.txt", words);
    for (auto w : words) {
        cout << w << '\t'
    }

    return 0;
}