#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <utility>

/*
    || ASSOCIATIVE CONTAINER INSERT OPERATIONS ||
        c.insert(v)         v value_type object; args are used to construct element
        c.emplace(args)     For map and set. Element inserted if an element with key not already in c.
                            Returns pair containing iterator of element and bool on whether element was inserted.
        c.insert(b,e)       For multimap and multiset, inserts element and returns iterator to new element.
                            b and e are iterators that denote a range of c::value_type values;
        c.insert(il)        il is braced list. Returns void. For map and set, inserts elements with keys that are
                            not already in c. For multimap and multiset, inserts each element in range.
        c.insert(p,v)       Like insert(v). P is an iterator used to begin search for where new element should be stored.
        c.emplace(p, args)  Like emplace(args). P is also an iterator. Returns iterator to element within given key.

        | TESTING THE RETURN FROM INSERT |
            The value returned by insert or emplace depends on the container type and parameters. For containers to have
             unique keys, the versions of insert and emplace that add a single element return a pair that lets us know 
             if the insertion happened.

             First member       == iterator to the element with the given key.
             Second memember    == bool indicating whether that element was inserted or already there. 

            return should be something like this --     pair<iterator, bool>
                            **Additionally, the returned iterator can be used to access the key and value, if referring to a map (SEE BELOW)
        
            | UNWINDING SYNTAX OF ++ret.first->second |
                (see void testingReturnInsert() and reference that for example)

                Precedence of operations ++((ret.first)->second)
                    ret             - holds the value returned by insert, which is a pair<map::iterator,bool>
                    ret.first       - first member of pair, which is a map iterator referring to element within given key
                    ret.first->     - dereferences iterator to fetch element (key). Elements in map are also pairs
                    ret.first->second   - is the (value) part of the map element pair
                    ++ret.first->second - increments that value

            ** Not using auto will require this declaration of type **
            std::pair<std::map<std::string, std::size_t>::iterator, bool> ret;
        
        | ADDING ELEMENTS TO MULTISET OR MULTIMAP |
            Sometimes, we might want to add additional elements with the same key. For example, we might want to map authors to titles
             of books they have written. In this case, there might be multiple entries for each author, so we'd use a multimap rather
             than a map. 
            
            Because keys in multi container need not be unique, INSERT on these types always inserts an element: (see void insertMultimap())

            The return of an .insert() operation into a multiset or multimap returns an iterator because a new element is ALWAYS added.
                ex. auto it = authors.insert("Author", "Book");     returns an iterator to the position in which element was inserted
                    std::multimap<std::string, std::string>::iterator it = authors.insert("Author", "Book");        // Same as above, without auto

        | ERASING ELEMENTS |
            We can erase one element or a range of elements by passing erase as an iterator or an iterator pair. For types that
             allow multiple keys (multimap and multiset), the number of elements removed could be > 1.
             
                ex. auto cnt = authors.erase("Barth, John");

                    prev:   authors.insert({"Barth, John", "Sot-Weed Factor"});
                            authors.insert({"Barth, John", "Lost in the Funhouse"});

            | REMOVING ELEMENTS FROM AN ASSOCIATIVE CONTAINER |
            c.erase(k)      Removes every element with key k from c. Returns size_type of # elements removed/
            c.erase(p)      Removes element denoted by iterator p from c. p must refer to element in c && != c.end()
                            Returns an iterator to the element after p or c.end(), if p denotes last element in c
            c.erase(b,e)    Removes the elements in the range denoted by iterator pair b,e. Returns e.


        | SUBSCRIPTING A MAP |
            Map and unordered_map provide the subscript operator [ ] and corresponding .at() function. Set types do not support
             subscripting since there is no value associated with a key in a set. Additionally, multimap or unordered_multimap do not
             support subscripting as there may be multiple values with key.

            Map subscript takes an index (key) and fetches the value associated with the key. If the key is not already present,
             a new element is created and inserted into the map for that key. Value is value initialized.

            **NOTE** Since subscripting can insert elements, only will work on non-const maps;

            When we subscript a map, we get a mapped_type object; when we dereference a map iterator, we get a value_type object
            The map subscript operator returns an lvalue, which means we can read or write the element.

            | SUBSCRIPT OPERATIONS FOR MAP AND UNORDERED_MAP |
            c[k]        Returns the element with key k; if k not in c, adds new, value-initialized element with key k
            c.at(k)     Checked access to element with key k; throws out_of_range exception if k not in c

            see. void subscriptingMap();

*/

void testingReturnInsert() {
    // more verbose way to count number of times each word occurs in the input
    std::map<std::string, std::size_t> word_count;      // empty map from string to size_t
    std::string word;
    while (std::cin >> word) {
        // inserts an element with key equal to word and value 1
        // if word already in word_count, insert does nothing
        auto ret = word_count.insert({word,1});
        if (!ret.second) {              // word was already in word_count0
            ++ret.first->second;        // increment counter
        }
    }
}

void insertMultimap() {
    std::multimap<std::string, std::string> authors;
    // add the first element with the key Barth, John
    authors.insert({"Barth, John", "Sot-Weed Factor"});
    // ok, adds the second element with they key Barth, John
    authors.insert({"Barth, John", "Lost in the Funhouse"});
}


void erasePractice() {
    std::map<std::string, std::size_t> word_count;
    std::string removal_word = "test";

    //erase key. return number of elements removed.
    if (word_count.erase(removal_word)) {
        std::cout << "found: " << removal_word << " removed" <<std::endl;
    } else {
        std::cout << removal_word << " not found!" <<std::endl;
    }
}

void subscriptingMap() {
    std::map<std::string, std::size_t> word_count;      // empty map
    // insert a value-initialized element with key Anna; then assign 1 to its value;
    word_count["Anna"] = 1;
    // Anna is key (std::stirng), 1 is value (std::size_t);

    // Working with return value of subscript operator 
    std::cout << word_count["Anna"] <<std::endl;    // fetch the element indexed by Anna; prints 1
    ++word_count["Anna"];                           // increment value of associated key "Anna" by 1
    std::cout << word_count["Anna"] <<std::endl;    // prints 2;

}

int main()
{
    subscriptingMap();

    return 0;
}