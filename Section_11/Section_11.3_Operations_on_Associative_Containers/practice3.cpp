#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <utility>

/*
    | ACCESSING ELEMENTS |
        The associative containers provide various ways to find a given element. Which operation to use depends on 
         what problems we're trying to solve. 

        || OPERATORS TO FIND ELEMENTS IN AN ASSOCIATIVE CONTAINER ||
        c.find(k);          returns an iterator to the (first) element with key k, or the off-the-end iterator if k not in container.
        c.count(k);         returns the number of elements with key k. For containers with unique keys, result is always 0 or 1.
        c.lower_bound(k);   returns iterator to the first element with key not less than k.
        c.upper_bound(k);   returns iterator to the first element with key greater than k.
        c.equal_range(k);   returns a pair of iterators denoting the elements with key k. If k not present, both members == c.end()

        | USING FIND INSTEAD OF SUBSCRIPT FOR MAPS |
            For map and unordered_map, the subscript operator provides the simplest method of retrieving a value. However,
             if we use a subscript, and the key is not already in the map, an element is inserted with that key.
            
            To find out if an element with a given key already exists (without subscripting), we can use .find()
                ex. void findForMaps();

        | FINDING ELEMENTS IN A MULTIMAP OR MULTISET |
            Finding elements in an associative container that requires unique keys is simple - it is there, or it isn't.
             For containers allowing multiple keys, the process is more complicated. There may be many elements within the
             given key. When MULTIMAP or MULTISET has multiple elements of a given key, those elements will be adjacent
             within the container.

             To find these elements, we can use a combination of .find() and .count();
                .count()        - can be used to find # elements that match
                .find()         - returns iterator (.begin()) of first matching element.

                With these two functions, we can increment through .find() the # of elements returned by .count(); i.e. ++.find() --.count()
                ex. void findForMultis();
            
            | A DIFFERENT, ITERATOR-ORIENTED SOLUTION |
                Alternatively, we can use lower_bound and upper_bound to avoid using .count() and .find() as stated above.
                 Lower_bound returns an iterator that refers to the first instance of a key. While upper_bound refers to one after the last instance

                 If the key isn't in the multimap, lower_bound (iterator) == upper_bound (iterator)

                 **NOTE** The iterator returned by lower_bound may or may not refer to an element with the given key. If the key is not in the container,
                 then lower_bound refers to the first point at which this key can be inserted while preserving element order within container.

                 REMEMBER, if .lowerbound == .upperbound, key is not in the container.

            | THE equal_range FUNCTION |
                The last way to solve the problem of iterating through elements is using the equal_range call. This function takes a key and returns a pair
                 of iterators. If they key is present, then first iterator == first instance of key, and second == one past the last instance of key. If no
                 matching pair found (it1 == it2) == .end();

    | A WORD TRANSFORMATION MAP |
        see wordTransformation.cpp
*/

void findForMaps() {
    std::map<std::string, std::size_t> word_count;
    std::string word;
    if (word_count.find("foobar") == word_count.end()) { std::cout << "foobar is not in the map." <<std::endl; }
}

void findForMultis() {
    std::multimap<std::string, std::string> authors = {{"AdB", "Book 1"},
                                                       {"AdB", "Book 2"},
                                                       {"misc", "Book 3"}};
    std::string search_item("AdB");     // author we're looking for
    auto entries = authors.count(search_item);       // number of elements for search
    auto iter = authors.find(search_item);            // first entry for this author
    
    while(entries) {
        std::cout << iter->second <<std::endl;    // print each title
        ++iter;         // advance to next title
        --entries;      // keep track of how many we've printed
    }
}

void lowerUpperBoundMultis() {
    std::multimap<std::string, std::string> authors = { {"AdB", "Book 1"},
                                                        {"AdB", "Book 2"},
                                                        {"Test", "Book 3"} };
    std::string search_item("AdB");
    // beg and end denote the range of elements for author
    for (auto beg = authors.lower_bound(search_item), end = authors.upper_bound(search_item) ; beg != end ; ++beg) {
        std::cout << beg->second <<std::endl;
    }

}

void equalRange() {
    std::multimap<std::string, std::string> authors = { {"AdB", "Book 1"},
                                                        {"AdB", "Book 2"},
                                                        {"AdB", "Book 3"},
                                                        {"Test", "Book 4"} };
    std::string search_item = "AdB";
    for (auto pos = authors.equal_range(search_item); pos.first != pos.second; ++pos.first) {
        std::cout << pos.first->second <<std::endl;     // syntax: pos(iterator pair).first(iterator 1)->second(value of key)
    }
}

int main()
{
    //findForMultis();
    //lowerUpperBoundMultis();
    equalRange();

    return 0;
}