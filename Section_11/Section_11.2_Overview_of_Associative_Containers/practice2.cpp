#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

/*
    | REQUIREMENTS ON KEY TYPE |
        By default, the library uses the < operator for the key type to compare the keys. In the set types, the key is the element type;
            In the map types, the key is the first element type.

        **NOTE ** Callable objects passed to a sort algorithm must meet the same requirements as do the keys in an associative container.

        | KEY TYPES FOR ORDERED CONTAINERS |
            We can also supply our own operation to use in place of the default < operator on keys. The specified operation MUST define
            a STRICT WEAK ORDERING over the key type. We can think of a strict weak ordering as "less than", although our function might use
            a more complicated procedure. The comparison function must have the following properties:

            - Two keys cannot both be "less than" eachother; if k1 is "less than" k2, then k2 must never be "less than" k1.
            - If k1 is "less than" k2, and k2 is "less than" k3.
            - If there are two keys, and neither key is "less than" the other, then we'll say that those keys are "equal" If k1 is "equal"
                to k2, and k2 is "equal" to k3, then k1 must be "equal" to k3.

            If two keys are ==, the container treats them as ==. When used as a key to a map, there will only be one element associated with those keys
            and either key can be used to access the corresponding value.

            **NOTE** In practice, what's important is that a type that defines a < operator that behaves normally can be used as a key.

        | USING A COMPARISON FUNCTION FOR THE KEY TYPE |

    | THE PAIR TYPE |
        Pair is defined in the utility header <utility>. A pair holds two data members and we must supply two type names when we create a pair.
        
            std::pair<std::string, std::string> anon;           // holds 2 strings
            std::pair<std::string, std::size_t> word_count;     // holds a string and a size_t
            std::pair<std::string, std::vector<int>> line;      // holds string and a vector<int>

        The default pair constructor value initializes the data members. Ex. anon holds 2 empty strings, and line holds an empty string and vector.
        Additionally, we can provide initializers for each member.

            std::pair<std::string, std::string> author{"James", "Joyce"};

        | OPERATIONS ON PAIRS |
            pair<T1, T2> p;             p is a pair with value initialized members of types T1 and T2
            pair<T1, T2> p{v1, v2};     p is a pair with types T1 and T2. First and second members are initialized from v1 and v2;
            pair<T1, T2> p = {v1, v2};  same as above ^^
            make_pair(v1, v2);          Returns a pair initialized from v1 and v2. The type of pair is inferred from types v1 and v2;
            p.first                     returns the (public) data member of p named first;
            p.second                    returns the (public) data member of p named second;
            p1 relop p2                 relational operators (<,>,<=,>=) ex. p1.first < p2.first || !(p1.second < p2.second)
            p1 == p2;                   Two pairs are equal if their first and second members are equal. Uses element's == operator
            p1 != p2;                   
        
*/

class Sales_data {
public:
    std::string book_no;
    std::string isbn() { return book_no; }
private:
};

bool compareIsbn(Sales_data &lhs, Sales_data &rhs) {
    return lhs.isbn() > rhs.isbn();
}

std::pair<std::string, int> process(std::vector<std::string> &v) {
    if(!v.empty()){
        return {v.back(), v.back().size()};                 // return pairs of last string of v and size of that string
    } else {
        return std::pair<std::string, int>();               // else return default-initialized pair
    }
}

int main()
{
    // bookstore can have several transactions with the same ISBN
    // elements in bookstore will be in ISBN order
    //std::multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);
    
    // pairs testing
    std::vector<std::string> svec = {"this", "is", "a", "test"};
    process(svec);

    return 0;
}
