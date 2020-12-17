#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

/*
    e11.5   - Explain the difference between map and set. When might you use one or the other?
                A map contains a key-value pair while a set only contains a key. A map might be useful when creating a dictionary
                with words and definitions, while a set might be useful for excluding words you don't want defined.
    
    e11.6   - Explain the difference between a set and a list. When might you use one or the other. A list is a doubly-linked container
                with elements accessed via position. Useful for storing sequential elements that don't need fast access or their positions
                don't need to be known. A set can be accessed via its key with no position required. Useful if looking for stored keys when you
                don't know the element's position or want to iterate through the list.

    e11.7   - Define a map for which the key is the family's last name and the value is a vector of the children's names. Write code to add new
                families and to add new children to an exisiting family.

    e11.8   - Write a program that stores the excluded words in a vector instead of a set. What are the advantages of a set?
                Advantage is that finding the word in a set is much more concise. only have to do exclude.find[word] instead of std::find(exclude.begin(), exclude.end(), word)
*/

// e11.7
auto makeFamilies() {
    std::map<std::string, std::vector<std::string>> fmap;

    std::cout << "Please enter each person's last and first name. Use @q to go back or to exit." << std::endl;
    for (std::string ln; std::cout << "Last Name: ", std::cin >> ln && ln != "@q"; ) {
        for(std::string cn; std::cout << "Child's Name: ", std::cin >> cn && cn != "@q"; )
            fmap[ln].push_back(cn);
    }
    return fmap;
}

void printFamilies(std::map<std::string, std::vector<std::string>> const &families) {
    
    for(auto &l : families) {
        std::cout << "Last Name: " << l.first << " | ";
        for (auto &c : l.second) {
            std::cout << c << ", ";
        }
        std::cout <<std::endl;
    }
}

void e118() {
    std::vector<std::string> exclude = {"this", "that", "these", "those"};
    std::string word;
    std::map<std::string, int> smap;
    std::set<std::string> excluded = {"a", "and", "the"};

    while (std::cin >> word && word != "@q") {
        if(std::find(exclude.begin(), exclude.end(), word) == exclude.end()) {      // if excluded words not found
            if(excluded.find(word) == excluded.end()) {                             // excluded using set instead of vector
                ++smap[word];
            }
        }
    }

    for (const auto &w : smap) {
        std::cout << w.first << " occurs " << w.second << (w.second > 1 ? " times." : " time.") <<std::endl;
    }
}

int main()
{
    //printFamilies(makeFamilies());
    e118();
    return 0;
}