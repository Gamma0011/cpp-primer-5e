#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

/*
    e11.37  - What are the advantages of an unordered container compared to the ordered version? What are the advantages 
                of the ordered version?

            Unordered container - Keys unorganized. Useful for programs where the cost of maintaining the organization 
                        of elements is prohibitive. Allows for our own management.
            Ordered container   - Automatically organizes keys. Easy to use.
    
    e11.38  - Rewrite the word-counting (pg 421) and word_transformation program (pg 440) to use an unordered_map.

*/

void wcProgram() {
    std::unordered_map<std::string, std::size_t> word_counting;
    std::string word;

    while (std::cin >> word) { ++word_counting[word]; }     // store word 

    for (const auto &w: word_counting) {
        std::cout << w.first << " occurs " << w.second << (w.second > 1 ? " times." : " time.") << std::endl;
    }
}

// word transformation program
std::unordered_map<std::string, std::string> buildMap(std::ifstream &i) {
    std::unordered_map<std::string, std::string> um;
    std::string key, value;
    
    while (i >> key && std::getline(i, value)) {
        if (value.size() > 1) {
            um[key] = value.substr(1);
        } else {
            std::cerr << "ERROR: No replacement for " << key <<std::endl;
        }
    }
    return um;
}

std::string compare(std::string s, std::unordered_map<std::string, std::string> um) {
    std::unordered_map<std::string, std::string>::iterator it = um.find(s);

    if (it != um.cend()) { return it->second; }
    return s;
}

void wtProgram(std::ifstream &newWords, std::ifstream &text) {
    std::string line;
    auto mp = buildMap(newWords);

    while (std::getline(text, line)) {
        std::string word;
        std::istringstream read(line);
        bool firstWord = true;
        
        while (read >> word) {
            if (firstWord) { 
                firstWord = false;
            } else { 
                std::cout << " " <<std::endl; 
            }
        }
        std::cout << compare(word, mp) <<std::endl;
    }
}

int main()
{
    std::ifstream words("replace.txt"), text("text.txt");
    wtProgram(words, text);


    return 0;
}