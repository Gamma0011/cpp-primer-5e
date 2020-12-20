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
    authors.insert("Barth, John", "Sot-Weed Factor");
    // ok, adds the second element with they key Barth, John
    authors.insert("Barth, John", "Lost in the Funhouse");
}

int main()
{


    return 0;
}