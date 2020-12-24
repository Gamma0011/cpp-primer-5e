#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>

// e11.33   - Implement your own version of the word-transformation program.

std::map<std::string, std::string> createMap(std::ifstream &i) {
    std::map<std::string, std::string> m;       // map to store key/value pairs
    std::string key, value;

    while (i >> key && std::getline(i, value)) {
        if (value.size() > 1) {
            m[key] = value.substr(1);
        } else {
            throw std::runtime_error("No replacement specified for " + key);
        }
    } 
    return m;
}

const std::string &replaceWords(const std::string &s, const std::map<std::string, std::string> &m) {
    auto m_it = m.find(s);

    if (m_it != m.cend()) {
        return m_it->second;    // key found, return value
    } else {
        return s;               // no matching key found, return original string
    }
}

int main(int argi, char **argv)
{
    //std::ifstream readMapFile(argv[1]);
    std::ifstream readMapFile("text.txt");
    //std::ifstream readTransFile(argv[2]);
    std::ifstream readTransFile("replace.txt");
    std::string original;

    if (readMapFile && readTransFile) {
        std::map<std::string, std::string> m = createMap(readMapFile);             // from first file, create the map
        while(std::getline(readTransFile, original)) {
            std::istringstream read(original);
            std::string words;                  // string to hold the input of read(original)
            bool space = true;
            while (read >> words) {
                if (space) {
                    space = false;
                } else {
                    std::cout << " ";
                }
            }
            std::cout << replaceWords(words, m) <<std::endl;
        }
    } else {
        std::cerr << "ERROR: Must provide two files." <<std::endl;
        return -1;
    }
    return 0;
}