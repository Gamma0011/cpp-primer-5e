#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

/*
    || ASSOCIATIVE CONTAINERS ||
    Support efficient lookup and retrieval by a key. The two primary associative-container types are MAP and SET.
        map - elements are key-value pairs. Key serves as an index into the map, and the value represents data
                associated with that index. A dictionary is a good example of a map, a word is the key, definition is value
        set - contains only a key; a set supports efficient queries as to whether a given key is present. We might
                use set to hold words we want to ignore during some kind of text processing

        Headers - map, unordered_map and set, unordered_set are used to define

        | ELEMENTS ORDERED BY KEY |
        map         Associative array; holds key-value pairs
        set         Container in which the key is the value
        multimap    map in which a key can appear multiple times
        multiset    set in which a key can appear multiple times

        | UNORDERED COLLECTIONS |
        unordered_map           map organized by a hash function
        unordered_set           set organized by a hash function
        unordered_multimap      Hashed map; keys can appear multiple times
        unordered_multiset      Hashed set; keys can appear multiple times

    || USING A MAP ||
        The map type is often referred to as an associative array. An associative array is like a normal array,
        except that its subscripts don't have to be integers. Values in map are found by a key, rather than my position.
    
    || USING A SET ||
        A set is simply a collection of keys. A set is most useful when we want to know whether a value is present.
        For example, a business might define a set named bad_checks to hold names of individuals who have written bad checks.
        Before accepting a check, a business would query bad_checks to see whether a name was present.
*/

void map_practice() {
    // a classic word-counting program
    // count the number of times each word occurs in the input
    std::map<std::string, std::size_t> word_count;          // empty map from string to size_t
    std::string word;

    while(std::cin >> word) {
        ++word_count[word];     // fetch and increment the counter for word
    }

    for (const auto &w : word_count) {
        std::cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times."  : " time.") << std::endl;
    }
}

void set_practice() {
    // count the number of times each word occurs in the input
    std::map<std::string, std::size_t> word_count;      // empty map from string and size_t
    std::set<std::string> exclude = {"The", "But", "And", "Or", "An", "A",
                                     "the", "but", "and", "or", "an", "a"};
    std::string word;

    while(std::cin >> word) {
        // count only words that are not in exclude
        if(exclude.find(word) == exclude.end()) {   // if word not found in exclude
            ++word_count[word];                     // fetch and increment the counter for word
        }
    }

    for(const auto &w : word_count) {
        std::cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times." : " time.") <<std::endl;
    }
}


int main()
{
    //map_practice();
    set_practice();

    return 0;
}
