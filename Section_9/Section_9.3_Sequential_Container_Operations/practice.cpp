#include <iostream>
#include <vector>
#include <list>
#include <deque>

/*
    USING PUSH_BACK
        Every Sequential Container (aside from array and forward_list) supports pushback - including string.

        // Ex. read from standard input, putting each word onto the end of container.
            string word;
            while (cin >> word) {
                container.push_back(word);
            }

        Because string is just a container of characters, we can push_back to add characters to the end of string
            void pluralize(size_t cnt, string &word) {
                if (cnt > 1) {
                    word.pushback('s');     // same as word += 's';
                }
            }
    
    USING PUSH_FRONT
        list, forward_list, and deque support an analogous operation called push_front. This operation inserts a new element at the front of the container

        // Ex. add elements to the start of ilist
        std::list<int> ilist;
        for (size_t ix = 0; ix != 4, ++ix) {
            ilist.push_front(ix);
        }

    ADDING ELEMENTS AT A SPECIFIED POINT IN A CONTAINER
        Even though some containers do not have a push_front operation, there is no similar constraint on insert. We can insert 
        elements at the beginning of a container without worrying about whether the container has push_front.

        std::vector<std::string> svec;
        std::list<std::string> slist;
            // equivalent to calling slist.push_front("Hello!");
        slist.insert(slist.begin(), "Hello!");
            // no push_front on vector, but we can insert "Hello" before begin
        svec.insert(svec.begin(), "Hello!");

        **NOTE** IT IS LEGAL TO INSERT ANYWHERE IN A VECTOR, DEQUE, OR STRING. BUT, IT IS AN EXPENSIVE OPERATION.

    INSERTING A RANGE OF ELEMENTS
        Arguments that appear after the initial iterator in a .insert() are analogous to the container constructors that take the same argument

        // inserts 10 elements at the end of svec and initializes each of those to be "Anna"
        svec.insert(svec.end(), 10, "Anna");

        std::vector<std::string> v = {"quasi", "simba", "frollo", "scar"};
        // insert the last two elements of v at the beginning of slist
        slist.insert(slist.begin(), v.end() - 2, v.end());
        slist.insert(slist.end(), {"this", "that", "these", "those"});

        // ERROR: iterators denoting the range to copy from must not refer to the same container as the one we are changing
        slist.insert(slist.begin(), slist.begin(), slist.end());

    USING THE RETURN FROM INSERT
        We can use the value returned by insert to repeatedly insert elements at a specified position in the container
        
            std::list<std::string> lst;
            auto iter = lst.begin();                    // std::list<std::string>::iterator iter;
            while (cin >> word) {
                iter = lst.insert(iter, word);          // same as calling push_front
                                                        // reassignment of iter with new value denoting lst.begin();
            }

    USING THE EMPLACE OPERATIONS
        The new standard introduced three new members - emplace_front, emplace, and emplace_back - that construct rather than copy elements.
        When we call an emplace member, we pass arguments to a constructor for the element type. The emplace members use those arguments
        to construct an element directly in space managed bu the container

        // assuming c holds Sales_data
            // construct a Sales_data object at the end of c
            // uses three-argument Sales_data constructor
                c.emplace_back("9-999-99999-9", 25. 15.99);
            // ERROR: there is no version of push_back that takes three arguments
                c.push_back("9-999-99999-9", 25. 15.99);
            // ok: we create a temporary Sales_data object to pass to push_back
                c.push_back(Sales_data("9-999-99999-9", 25. 15.99));

        // iter refers to an element in c, which holds Sales_data elements
            c.emplace_back();                               // uses the Sales_data default constructor
            c.emplace(iter, "0-000-00-0");                  // uses Sales_data string, default initialization of units_sold and price;
            c.emplace_front("2-22-22-2", 25, 14.99);        // uses Sales_data constructor with 3 elements
        
        **NOTE** the emplace functions construct elements in the container. The arguments to these functions
            must match a constructor for the element type.

    ACCESSING ELEMENT
        Each sequential container, including array, has a front member, and all except for forward_list have a back member

        // check that there are elements before dereferencing an iterator or calling front or back
        if (!c.empty()) {
            // val and val2 are copies of the value of the first element of c
            auto val = *c.begin(), val2 = c.front();
            // val3 and val4 are copies of the last element of c
            auto last = c.end();
            auto val3 = *(--last);          // cannot decrement forward_list iterators
            auto val4 = c.back();           // not supported by forward list;
        }

        **NOTE** Calling front or back on an empty container, like using a subscript that is out of range is a serious programming error.
            ALWAYS check if (!c.empty())

        Members that access elements of a container (i.e. front, back, subscript, and at) return references.
            If the container is a const object, the return is a const&. If the container is not const, the return is & and 
            can be used to change the value of the fetched element
        
        if (!c.empty()) {
            c.front() = 42;         // assigns 42 to the first element of c
            auto &v = c.back();     // gets a reference to the last element
            v = 1024;               // changes element c
            auto v2 = c.back();     // v2 is not a reference, it's a copy of c.back();
            v2 = 0;                 // no change to element c
        }

        **REMEMBER** if we use auto to store the return from one of these functions and we want to use that variable to change the element
            we must remember to define our variable as a reference type (i.e. auto &v2 = c.front();)

        SUBSCRIPTING AND SAFE RANDOM ACCESS
            The containers that provide fast random access (STRING, VECTOR, DEQUE, and ARRAY) also provide the subscript operator.
            The subscript operator takes an index and returns a reference to the element at that position in the container.
            The index must be in range (i.e. greater than or equal to 0 and less than the size of the container). It's up to the program
            to ensure that the index is valid. The subscript operator does not check whether the index is in range. 
            **AN OUT-OF-RANGE VALUE FOR AN INDEX IS A SERIOUS PROGRAMMING ERROR, BUT ONE THAT THE COMPILER WILL NOT DETECT**

            If we want to ensure that the index is valid, we can use the at member instead. The at member acts like the subscript operator, but if 
            the index is invalid, at throw and out_of_range exception

            std::vector<std::string> svec;          // empty vector
            std::cout << svec[0] <<std::endl;       // run-time error: there are no elements in svec
            std::cout << svec.at(0) <<std::endl;    // throws an out_of_range exception


*/

class Sales_data {
public: 
    Sales_data() = default;
    Sales_data(std::string bn) : isbn(bn) { };
    Sales_data(std::string bn, unsigned us, double p) : isbn(bn), units_sold(us), price(p) { };
private:
    std::string isbn;
    unsigned units_sold;
    double price;
};

int main()
{
    //std::vector<Sales_data> vec;
    //vec.emplace_back("9-999-999-9", 20, 10.99);

    std::vector<int> ivec = {0,1,2};
    std::cout << ivec.at(2) <<std::endl;

    return 0;
}
