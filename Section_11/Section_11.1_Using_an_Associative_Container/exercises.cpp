#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

/*
    e11.1   - describe the difference between a map and a vector
                A map works as a key-value pair in which they key is used to access the value. This is different than a vector
                in that a vector accesses values by position
    e11.2   - give an example of when each of list, vector, deque, map, and set might be most useful
                list - accessing members in sequential order
                vector - random access of members
                deque - front/end access of members
                map - storing key-value pairs with a requirement to access quickly via key
                set - storing values that we don't want to be read into a map
    e11.3   - write your own version of the word-counting program

    e11.4   - extend your program to ignore case and punctuation. ex. Example and example should increment the same counter

*/

void e113() {
    std::map<std::string, std::size_t> word_count;
    std::string word;

    while(std::cin >> word) {
        ++word_count[word];
    }

    for(const auto &w : word_count) {
        std::cout << w.first << " occurs " << w.second << (w.second > 1 ? " times." : " time.") <<std::endl;
    }
}
void formatStr(std::string &s) {
    for(auto &c : s) { c = std::tolower(c); }
}

void e114() {
    std::map<std::string, std::size_t> word_count;
    std::string s;

    while(std::cin >> s) {
        formatStr(s);           // convert any uppercase chars to lower
        s.erase(std::remove_if(s.begin(), s.end(), ispunct), s.end());      // remove any non-alphanumeric or space characters
        ++word_count[s];
    }

    for(const auto &w : word_count) { 
        std::cout << w.first << " occurs " << w.second << (w.second > 1 ? " times." : " time.") << std::endl; 
    }
}

int main()
{
    //e113();
    e114();

    return 0;
}