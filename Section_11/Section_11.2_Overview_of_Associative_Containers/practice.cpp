#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

/*  
    | DEFINING AN ASSOCIATIVE CONTAINER |
        Under the new standard, we can also list initialize the elements of map and set

        std::map<std::string, std::size_t> word_count;      // empty
        // list initialization
        std::set<std::string> exclude = {"this", "that", "these", "those"};
        std::map<std::string, std::string> authors = { {"Joyce", "James"},
                                                       {"Austens", "Jane"},
                                                       {"Dickens", "Charles"} };

        When we initialize a map, we must provide both the key and the value, wrapped in {} {key, value}

    | INITIALIZING A MULTIMAP OR MULTISET |
        The keys in a map or set must be unique. There can only be one element with a given key. However,
        multimap and multiset containers have no such restrictions.
*/

void multisetPractice() {
    // define a vector with 20 elements, holding 2 copies of each number from 0-9
    std::vector<int> ivec;
    for(int i = 0; i != 9; ++i) { ivec.push_back(i); ivec.push_back(i); }

    //iset holds unique elements from ivec; miset holds all 20 elements
    std::set<int> iset(ivec.begin(), ivec.end());
    std::multiset<int> miset(ivec.begin(), ivec.end());

    std::cout << "ivec size: " << ivec.size() <<std::endl;      // print ivec size
    std::cout << "iset size: " << iset.size() <<std::endl;      // print iset size
    std::cout << "miset size: " << miset.size() <<std::endl;    // print miset size

}

int main()
{
    multisetPractice();


    return 0;
}