#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <utility>

/*
    For set types, the key_type and the value_type are the same; the values held in a set are keys.
     In a map, the elements are key-value pairs. That is, each element is a pair object containing a key and an
     associated value. Because we cannot change the element's key, the key part of these pairs is const.

        | ASSOCIATIVE CONTAINER ADDITIONAL TYPE ALIASES |
            key_type        Type of key for this container type
            mapped_type     Type associated with each key; map types only
            value_type      For sets, same as key_type. For maps, pair<const key_type, mapped_type>
    ex. (See void acAliases())

    || ASSOCIATIVE CONTAINER ITERATORS ||
        When we dereference an iterator, we get a & value of the container's value_type 
                                        (sets return key, maps return pair<CONST key, & value>)

        **NOTE** value_type of map is a pair. We can change the value of the pair, but not the key
                std::pair< CONST key, & value>
        
    ex. mapIterators()

        | ITERATORS FOR SETS ARE CONST |
            Although set types define both the iterator and const_iterator types, both types give us
             read-only access to the elements in a set. Keys in a set are also const. Set iterators
             are used to read, but not write an element's value.
        ex. setIterators()

        | ITERATING ACROSS AN ASSOCIATIVE CONTAINER |
            Maps and sets provide all the usual .begin() and .end() operations.
        ex. void iteratingWord_Counter()

        | ASSOCIATIVE CONTAINERS AND ALGORITHMS |
            Associative containers can be used with algorithms that read elements. Because elements in an associative
            container can be found quickly by their key, it is almost always a bad idea to use a generic search algorithm.
            
            As an example, associative container function .find(key) directly fetches the element with the given key. 
            Using the generic find function would require a sequential search.

    || ADDING ELEMENTS ||
        Because map and set (as well as other corresponding unordered types) contain unique keys, inserting
         an element that already is present has no effect. (ex. void addingElementsSet(), addingElementsMap())
    
        **NOTE** When inserting elements into a map, we must remember that the element type is a pair. Often,
         we don't have a pair object that we want to insert. Instead, we create a pair in the arg list to insert.
*/

void acAliases() {
    std::set<std::string>::value_type v1;           // v1 is a string
    std::set<std::string>::key_type v2;             // v2 is a string
    std::map<std::string, int>::value_type v3;      // v3 is a pair<const string, int>
    std::map<std::string, int>::key_type v4;        // v4 is a string
    std::map<std::string, int>::mapped_type v5;     // v5 is an int; int associated with string (key-value)
}

void mapIterators() {
    // get an iterator to an element in word_count
    std::map<std::string, std::size_t> word_count = { {"Hello", 0},
                                                      {"World", 1},
                                                      {"Testing", 2} };

    auto map_it = word_count.begin();
    // *map_it is a & to a pair<const string, size_t> object
    std::cout << map_it->first <<std::endl;         // prints key for element
    std::cout << map_it->second <<std::endl;        // prints value for element
    // map_it->first = "new key"                    // error: key is const
    ++map_it->second;                               // we can change the value though an iterator
}

void setIterators() {
    std::set<int> iset = {0,1,2,3,4,5,6,7,8,9};
    std::set<int>::iterator set_it = iset.begin();
    if (set_it != iset.end()) {
        std::cout << *set_it <<std::endl;
        // *set_it = 42;                    // error keys in set are read-only
    }
}

void iteratingWord_Counter() {
    std::map<std::string, std::size_t> word_counter = { {"Hello", 12},
                                                         {"World", 42},
                                                         {"Earth", 9} };
    auto it = word_counter.cbegin();
    while (it != word_counter.cend()) {
        std::cout << it->first << " occurs " << it->second 
                 << (it-> second > 1 ? " times." : " time.") << std::endl;
        ++it;
    }
}

void addingElementsSet() {
    std::vector<int> ivec = {2,4,6,8,2,4,6,8};      // ivec has 8 elements
    std::set<int> set2;                             // empty set                {}
    set2.insert(ivec.begin(), ivec.end());          // set2 has 4 elements      {2,4,6,8}  
    set2.insert({1,3,5,7,1,3,5,7});                 // set2 now has 8 elements  {1,2,3,4,5,6,7,8}
}

void addingElementsMap() {
    std::map<std::string, int> word_count;
    std::string word;

    // four ways to add word to word_count
    word_count.insert({word, 1});                               // under C++11, this is the easiest way to create a pair
    word_count.insert(std::make_pair(word, 1));                 // call to make_pair
    word_count.insert(std::pair<std::string, int>(word, 1));    // explicitly construct pair
    word_count.insert(std::map<std::string, int>::value_type(word, 1)); // constructs new object of pair type and inserts into map
}

int main()
{
    // acAliases();
    // mapIterators();
    // setIterators();
    // iteratingWord_Counter();

    return 0;
}