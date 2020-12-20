#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <iterator>

/*
    e11.15  - What are the mapped_type, key_type, and value_type of a map from int to vector<int>?
                std::map<int, std::vector<int>>
            
                mapped_type     - vector<int>
                key_type        - int
                value_type      - std::pair<const int, std::vector<int>>

    e11.16  - Using a map iterator, write an expression that assigns a value to an element

    e11.17  - Assuming c is a multiset of strings, and v is a vector of strings, explain the following calls. Is each legal?
            copy(v.begin(), v.end(), inserter(c, c.end()))
            copy(v.begin(), v.end(), back_inserter(c));

    e11.18  - Write the type of map_it from the loop on page 430 without using auto or decltype
            see void e1118()

    e11.19  - Define a variable that you initialize by calling begin() on the multiset named bookstore from 425.
                Write the variable's type without using auto or decltype.

                std::multiset<Sales_data, bool(*)(const Sales_data &lhs, const Sales_data &rhs)>::iterator it = bookstore.begin();

    e11.20  - Rewrite the word-counting program from 11.1 (pg 421) to use insert instead of subscripting. 
              Which is easier to write. Why?

    e11.21  - Assuming word_count is a map from string to size_t and word is a string, explain this loop:
                while (cin >> word) { ++word_count.insert({word,0}).first->second; }

                                    ++(((word_count.insert({word,0})).first)->second);

                Step 1: Insert cin >> word into map (key) with (value) == 0;
                Step 2: Access the iterator of the pair returned by .insert() pair<iterator, bool>
                Step 3: Dereference the iterator and access second of pair<key, value>
                Step 4: Increment value

                This works because if an element has not been created, the initial value inserted is 0, then incremented to 1.
                If element exists, key is found, but value is incremented by 1.

    e11.22  - Given a map<string, vector<int>> write the types used as an argument and as the return value for the version
                of insert that inserts one element.

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

void e1117() {
    std::set<std::string> c = {"set"};
    std::vector<std::string> v = {"this", "is", "a", "vector"};

    // copy elements from v.begin to .end into c.
    // std::copy(v.begin(), v.end(), std::inserter(c, c.end()));
    // for (auto &r : c) { std::cout << r <<std::endl;}

    // illegal, no push_back in set
    // std::copy(v.begin(), v.end(), std::back_inserter(c));
    // for (auto &r : c) { std::cout << r <<std::endl;}

    // legal copy elements from set to vector.
    // std::copy(c.begin(), c.end(), std::inserter(v, v.end()));
    // for (auto &s : v) { std::cout << s <<std::endl; }

    // legal, copy elements from set to vector
    std::copy(c.begin(), c.end(), std::back_inserter(v));
    for (auto &s : v) { std::cout << s <<std::endl; }
}

void e1118() {
    /* get iterator positioned on the first element
    std::map<std::string, std::size_t> word_count;

    // original - auto map_it = word_count.cbegin();
    std::map<std::string, std::size_t>::iterator map_it = word_count.cbegin();

    // compare the current iterator to the off-the-end iterator
    while (map_it != word_count.cend()) {
        std::cout << map_it->first << " occurs " 
                  << map_it->second << (map_it->second > 1 ? " times." : " time.") << std::endl;
    }
    */
}

void e1119() {
    // std::multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);
    // std::multiset<Sales_data, bool(*)(const Sales_data &lhs, const Sales_data &rhs)> bookstore(compareIsbn);
    
    
    // std::multiset<Sales_data, bool(*)(const Sales_data &lhs, const Sales_data &rhs)>::iterator it = bookstore.begin();
}

void e1120() {
    std::map<std::string, std::size_t> word_count;
    std::string word;

    std::cout << "Please type words. Type @q when finished: " <<std::endl;
    while(std::cin >> word && word != "@q") {
        auto it = word_count.insert({word, 1});
        if(!it.second) {        // if not true, element was not inserted, therefore element already exists
            ++it.first->second; // increment value of associated key
        }
    }

    for (auto &w : word_count) { 
        std::cout << w.first  << " was entered " 
                  << w.second << (w.second > 1 ? " times." : " time.") <<std::endl;
    }
}

void e1121() {
    std::map<std::string, std::vector<int>> smap;


}

int main()
{
    //e1116();
    //e1117();
    e1120();

    return 0;
}