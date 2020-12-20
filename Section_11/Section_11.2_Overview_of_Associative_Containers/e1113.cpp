#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>

// e11.13   - There are at least 3 ways to create pairs in e11.12. Write 3 versions and explain which for, you think is easist. Why?

void v1() {
    std::string s;
    int i;

    std::vector<std::pair<std::string, int>> pvec;

    std::cout << "Please type a word and a number: ";
    while(std::cin >> s >> i) {
        if ( s == "@q") {
            break;
        }
        //pvec.push_back(std::pair<std::string, int>(s,i)); // original
        //pvec.push_back(std::make_pair(s,i));              // v1
        //pvec.push_back({s,i});                            // v2
        pvec.emplace_back(s,i);                             // v3 - this is the most efficient
    }

    for(auto &w : pvec) {
        std::cout << "Word: " << w.first << " | Number: " << w.second <<std::endl;
    }
}

int main()
{
    v1();

    return 0;
}