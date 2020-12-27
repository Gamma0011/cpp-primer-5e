#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

/*
    || USING AN UNORDERED CONTAINER ||
        Rather than using a comparison function to organize unordered container elements, these containers
         use a hash function and the key type's == operator. An unordered container is most useful when we have a key type
         for which there is no obvious ordering relationship among the elements. These containers are also useful
         for applications in which the cost of maintaining elements in order is prohibitive.

        Although hashing can give better average cast performance, it require a lot of work and tweaking. In most cases,
         it is easier and often yields better performance to use an ordered container.

        Unordered containers provide the same operations (find, insert, etc) as ordered containers, as well as additional
         operations for hashing.

         ex. void unorderedContainer()  - acts the same as program using orderedContainer, but std::string keys won't be 
            alphabetized.

        | UNORDERED CONTAINER MANAGEMENT OPERATIONS |
            -- BUCKET INTERFACE --
            c.bucket_count()            Number of buckets in use.
            c.max_bucket_count()        Largest number of buckets this container can hold.
            c.bucket_size(n)            Number of elements in the (n)th bucket    
            c.bucket(k)                 Bucket in which element with key k would be found

            -- BUCKET ITERATION --
            local_iterator              Iterator type that can access the elements in a bucket
            const_local_iterator        const version of the bucket iterator
            c.begin(n), c.end(n)        Iterator to the first, and one past the last element in bucket n
            c.cbegin(n), c.cend(n)      Returns const_local_iterator

            -- HASH POLICY --
            c.load_factor()             Average number of elements per bucket. Returns FLOAT
            c.max_load_factor()         Average bucket size c tries to maintan. c adds buckets to keep 
                                        load_factor <= max_load_factor. Returns FLOAT
            c.rehash(n)                 Reorganize storage so that bucket_count >= n and bucket_count > size/max_load_factor
            c.reserve(n)                Reorganize so that c can hold n elements without a rehash

        | REQUIREMENTS ON KEY TYPE FOR UNORDERED CONTAINERS |
            By default, unordered containers use == to compare key type. They also use an object of type hash<key_type>
                to generate the hash code for each element. The library defines hash for some types (strings or smart pointer).
                However, we cannot directly define an unordered container that uses our own class types for its key type, since
                we cannot use the default hash template directly. Instead, we will have to supply our own version of the hash 
                template (coming in Section 16).
                
*/

class Sales_data {
private:
    std::string bookNo;
public: 
    Sales_data (std::string bn) : bookNo(bn) { };       
    std::string isbn() const { return bookNo; }
};

void unorderedContainer() {
    // count occurrences, but the words won't be in alphabetical order
    std::unordered_map<std::string, std::size_t> word_count;
    std::string word;
    
    while (std::cin >> word) {  // fetch and incremenet the counter for word
        ++word_count[word];     // for each element in the map
    }

    for (const auto &w : word_count) {
        std::cout << w.first << " occurs " << (w.second > 1 ? " times." : " time.") <<std::endl;
    }
}

// defining our own hash template
// To use Sales_data as the key, we'll need to supply functions to replace both == and to calculate the hash code

//  hasher uses object of string type to generate a hash code from the isbn member
std::size_t hasher(const Sales_data &sd) { return std::hash<std::string>() (sd.isbn()); }

// eqOp function compares two Sales_data objects by comparing their isbns
bool eqOp(const Sales_data &lhs, const Sales_data &rhs) { return lhs.isbn() > rhs.isbn(); }

// we can use these functions to define an unordered_multiset as follows:
// type alias
using SD_multiset = std::unordered_multiset<Sales_data, decltype(hasher)*, decltype(eqOp)*>;

// arguments are the bucket size and pointers to the hash function and equality operator
SD_multiset bookstore(42, hasher, eqOp);


int main()
{


    return 0;
}