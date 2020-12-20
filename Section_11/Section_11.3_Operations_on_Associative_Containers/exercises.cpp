#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <utility>

/*
    e11.15  - What are the mapped_type, key_type, and value_type of a map from int to vector<int>?
                std::map<int, std::vector<int>>
            
                mapped_type     - vector<int>
                key_type        - int
                value_type      - std::pair<const int, std::vector<int>>

    e11.16  - Using a map iterator, write an expression that assigns a value to an element

    e11.17  - 
*/

void e1116() {
    std::map<std::string, std::size_t> m = { {"one", 0},
                                             {"two", 0} };

    auto it = m.begin();

    while (it != m.end()) {
        std::cout << "Write the numeric of " << it->first << ": ";
        std::cin >> it->second;
        ++it;
    }

    for (auto &e : m) { std::cout << e.first << " " << e.second <<std::endl; }      // print elements

}

int main()
{
    e1116();

    return 0;
}