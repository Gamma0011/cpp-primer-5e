#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>

// e11.12  - Write a program to read a sequence of strings and ints, storing each into a pair. Store those pairs in a vector. 

int main()
{
    std::string s;
    int i;

    std::vector<std::pair<std::string, int>> pvec;

    std::cout << "Please type a word and a number: ";
    while(std::cin >> s >> i) {
        pvec.push_back(std::pair<std::string, int>(s,i));
    }

    for(auto &w : pvec) {
        std::cout << "Word: " << w.first << " | Number: " << w.second <<std::endl;
    }

    return 0;
}