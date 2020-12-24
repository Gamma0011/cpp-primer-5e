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

                std::pair<std::string, std::vector<int>>     // argument
                std::pair<std::map<std::string, std::vector<int>::iterator, bool>>  // return
    
    e11.23  - Rewrite the map that stored vectors of children's names with a key that is the family last name
                for the exercises in 11.2.1 to use a multimap.

    e11.24  - What does the following program do?
                map<int, int> m;    // create a map with int key and int value
                m[0] = 1            // search for element with key = 0, if not found, create key 0 and value = 1

    e11.25  - Contract the following program with the one in the previous exercise:
                vector<int> v;      // create a vector that holds elements of type int;
                v[0] = 1;           // set element in position 0 == 1;

    e11.26  - What type can be used to subscript a map? What type does the subscript operator return? Give concrete a
                example -- define a map and then write the types that can be used to subscript the map and the type
                that would be returned from the subscript operator

                The standard return type of a map is its key type. However, when subscripting, the return type 

    e11.27  - What kind of problems would you use count to solve? When might you use find?
                .count() would be useful when you want to know how many elements are in a multimap or multiset, i.e. if you want to 
                 place a limit on how many matching entries there can be.
                .find() is useful in maps or sets where there cannot be unique keys, but you want to see if the elements exists. Also prevents
                 one from accidentally adding elements in the case an element is not found (unlike subscripting)
    
    e11.28  - Define and initialize a variable to hold the result of calling find on a map from string to vector of ints.

    e11.29  - What do upper_bound, lower_bound, and equal_range return when you pass a key that is not in a container?
                upper_bound     - returns the point in the container where the element can be inserted to maintain container order
                lower_bound     - returns the point in the container where the element can be inserted to maintain container order
                equal_range     - pair<it1, it2> it1 == it2, which declares the point where element can be inserted into container

    e11.30  - Explain the meaning of pos.first->second used in the output expression of the final program in this section.
                auto pos == pair<c.lower_bound(element), c.upper_bound(element)> || auto pos == pair<it1, it2>

                pos.first           - accesses the first object of the pair, which is the current iterator
                    first->second   - from the current iterator, access the key of that pointer (*first).second
                
    e11.31  - Write a program that defines a multimap of authors and their works. Use find to find an element in the multimap and erase that element.
                Be sure your program works correctly if the element you look for is not in the map.

    e11.32  - Using the multimap from the previous exercise, write a program to print the list of authors and their works alphabetically.
                **NOTE** Multimap alphabetizes the keys already, iterating through the container is simple .begin() -> .end() after matched element
                has been erased
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

void e1123() {
    std::multimap<std::string, std::string> mmap;
    std::string ln, fn;

    std::cout << "Please enter a last name and first name. Type @q to quit." << std::endl;
    for ( ; std::cout << "Last Name: ", std::cin >> ln && ln != "@q" ; ) {
        for ( ; std::cout << "First Name: ", std::cin >> fn ; ) {
            mmap.emplace(ln, fn);
            break;
        }
    }

    for (auto &s : mmap) {
        std::cout << "First Name: " << s.second << " Last Name: " << s.first <<std::endl;
    }

}

void e1126() {
    std::map<char, int> cmap;

    std::cout << typeid(std::map<char, int>::key_type).name() << std::endl;     // returns type char (key)
    std::cout << typeid(decltype(cmap['t'] = 0)).name() <<std::endl;            // returns type int (value)


}

void e1128() {
    std::map<std::string, std::vector<int>> m = { {"hello", {1,2,3,4,5}},
                                                  {"day", {1,2,3}}};
    // auto it = m.find("hello");
    std::map<std::string, std::vector<int>>::iterator it = m.find("hello"); // non-auto declaration of type
    std::cout << it->first << '\t';
    for (auto &i : it->second) { std::cout << i << '\t'; }
    std::cout << std::endl;
}

void e1131() {
    std::multimap<std::string, std::string> authors = { {"LoTR", "JRR Tolkien"},
                                                        {"The Hobbit", "JRR Tolkien"},
                                                        {"Unfinished Tales", "JRR Tolkien"},
                                                        {"Moby Dick", "Herman Melville"} };
    std::string search("The Hobbit");
    auto it = authors.find(search);
    if (it != authors.end()) { authors.erase(it); }         // don't erase if it returns off-the-end iterator
    for(auto pos = authors.begin() ; pos != authors.end(); ++pos) { std::cout << pos->first << " : " << pos->second <<std::endl; }
}

int main()
{
    //e1116();
    //e1117();
    //e1120();
    //e1123();
    //e1126();
    //e1128();
    e1131();

    return 0;
}