#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

/*
e810 - now, write a program to store each line from a file in a vector<string>. 
           use istringstream to read each element from the vector a word at a time.


    steps   - open file
            - read lines into file
            - save to vector
            - call istringstream to read elements of vector
*/

int main(int argi, char **filePath)
{
    std::ifstream open(filePath[1]);                // opens provided file
    std::string word;
    std::vector<std::string> svec;                  // vector of strings to hold words

    if(open) {
        while(open >> word) {                       // read ifstream into word
            svec.push_back(word)                    // write word as objects of svec
        }
        for(auto &w : svec) {
            std::istringstream read(w);             // isstringstream function to read words from vector
            std::string words;                      // string to hold isstringstream output

            while(read >> words) {                  // read isstring into words
                std::cout << words <<std::endl;     // display out words
            }
        }
    } else {
        std::cerr << "ERROR: File doesn't exist." <<std::endl;
    }


    return 0;
}