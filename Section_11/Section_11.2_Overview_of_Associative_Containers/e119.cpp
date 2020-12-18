#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <algorithm>
#include <numeric>

//  e11.9   - Define a map that associates words with a list of line numbers on which the word might occur.

void printWords(std::map<std::string, std::list<int>> pw){
    for (auto &w : pw) { 
        std::cout << w.first << " occurs on " << (w.second.size() > 1 ? "lines: " : "line: ");
        for (auto &l : w.second) {
            std::cout << l << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argi, char **argc) 
{
    std::fstream open("words.txt");                 // open supplied file - substitute with argc[1] for manual file input
    std::map<std::string, std::list<int>> words;    // map to hold words and associated lines
    std::string word;

    if(open) {
        size_t ln = 1;
        while(open >> word) { words[word].push_back(ln++); }
    } else {
        std::cerr << "ERROR: No file." <<std::endl;
    }

    printWords(words);

    return 0;
}