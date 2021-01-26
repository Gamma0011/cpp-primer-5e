#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <sstream>

/*
    e12.28  - Write a program to implement text queries without defining classes

        Steps:  1. Read file and write to vector, and map
                2. Allow queries and searches for words.
                3. If found, return info
*/

std::vector<std::string> createVec(std::ifstream &ifs) {
    std::vector<std::string> strVec;
    for(std::string line ; std::getline(ifs, line) ; strVec.push_back(line));
    return strVec;
}

std::map<std::string, std::set<int>> createMap(const std::vector<std::string> &v) {
    std::map<std::string, std::set<int>> strMap;
    int lineNum = 0;
    std::string word;

    for (auto &l : v) {
        for (std::istringstream iss(l) ; iss >> word ; strMap[word].insert(lineNum)) { };
        ++lineNum;
    }
    return strMap;
}

std::ostream &print(std::ostream &os, std::string &s, const std::vector<std::string> &v, const std::map<std::string, std::set<int>> &m) {
    auto search = m.find(s);
    if (search == m.end()) {
        os << "\"" << s << "\"" << " not found." << std::endl;
    } else {
        os << s << " found " << search->second.size() << (search->second.size() > 1 ? " times.\n" : " time.\n");
        for (auto &ln : search->second) {
            os << "Line " << ln << ": " << v[ln] <<std::endl;
        }
    }
    return os;
}

int main(int argi, char **argc)
{
    //std::ifstream open(argc[1]);
    std::ifstream open("test.txt");

    std::vector<std::string> svec;
    std::map<std::string, std::set<int>> smap;

    if (open) {
        svec = createVec(open);
        smap = createMap(svec);
    } else {
        std::cerr << "ERROR: No file." <<std::endl;
        return -1;
    }

    for (std::string w; std::cout << "Please type a word to search. Type q to quit: ", std::cin >> w && w != "q"; print(std::cout, w, svec, smap)) { };

    return 0;
}