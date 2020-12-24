#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <utility>

/*
    PURPOSE:    Given one string, will transform it into another. 
                Input is two files. First: Contains the rules we will use to transform text in the second file.
                                    Second: File to read and transform.
*/

const std::string &transform(const std::string &s, const std::map<std::string, std::string> &m) {
    // the actual map work; this part is the heart of the program
    auto map_it = m.find(s);
    // if this word if in the transformation map
    if (map_it != m.cend()) {
        return map_it->second;              // return replaced string
    } else {    
        return s;                           // return original string
    }
}

std::map<std::string, std::string> buildMap(std::ifstream &map_file) {
    std::map<std::string, std::string> trans_map;       // holds the transformations
    std::string key, value;                             // key - word to transform. value - word to use instead
    
    // read the first word into key and the rest of the line into value
    while (map_file >> key && std::getline(map_file, value)) {
        if (value.size() > 1) {                         // check that there is a transformation - more than just a space after read key
            trans_map[key] = value.substr(1);           // skip the leading space (go to position[1] of rest of getline rather than start at postition[0])
        } else {
            throw std::runtime_error("No rule for " + key);
        }
    }
    return trans_map;
}

void word_transformation(std::ifstream &map_file, std::ifstream &input) {
    auto trans_map = buildMap(map_file);    // store the transformations
    std::string text;                       // hold each line from input

    while (std::getline(input, text)) {
        std::istringstream stream(text);    // read each word
        std::string word;
        bool firstword = true;              // controls whether a space is printed
        while (stream >> word) {
            if (firstword) {
                firstword = false;
            } else {
                std::cout << " ";           // print a space between words
            }
            // transform returns its first argument or its transformation
            std::cout << transform(word, trans_map);        // print the output
        }
        std::cout << std::endl;             // done with this line of input
    }
}

int main()
{


    return 0;
}