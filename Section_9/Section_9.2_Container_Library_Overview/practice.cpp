#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <array>

/*
    In general, each container is defined in a header file with the same name as the type.
    As with vectors, we must supply additional information to generate a particular container type:
        list<Sales_data>    - a list of elements with type Sales_data
        deque<double>       - a deque of elements with type double

    We can also define a container whose element type is itself another container
        vector<vector<string>> line     - line is a vector containing elements that are vectors of strings

    // assume noDefault is a type without a default constructor
    vector<noDefault> v1(10, int);      // ok: element initializer supplied
    vector<noDefault> v1(10);           // error: must supply an element initilizer

    Some classes do not have a default constructor, we can define a container that holds objects of such types, 
    but we cannot construct such containers using only element count;


    ITERATORS

    An interator range is denoted by a pair of iterators each of which refers to an element, or to one past the last element, in the same container

    .begin() denotes the first element of the container
    .end() denotes one past the last element

    Written out, it looks like this:
    [begin, end)        -- from begin up to, but not including end (this is because end doesn't exist as it is one past the last element)

    Two iterators, begin and end, form an iterator range if:
    - they refer to elements of, or one past the end of, the same container, **AND**
    - it is possible to reach end by repeatedly incrementing begin. In other words, end must not precede begin;


    CONTAINER TYPE MEMBERS
    // iter is the iterator type defined by list<string>
    std::list<std::string>::iterator iter;
    // count is the difference_type type defined by std::vector<int>
    std::vector<int>::difference_type count;
    

    DEFINING AND INITIALIZING A CONTAINER
     When we pass iterators, there is no requirement that the container types be identical,
     Moreover, the element types of the new and original container can differ as long as it is possible to convert the elements
     we're copying to the element type of the container we're initializing:
     
    // each container has three elements, initialized from the given initializers
    std::list<std::string> authors = {"Milton", "Shakespear", "Austen"};
    std::vector<char*> articles = {"a", "an", "the"};
    std::list<std::string> list2(author);               // ok: types match
    std::deque<std::string> authList(authors);          // error: container types don't match
    std::vector<std::string> words(articles);           // error: element types must match
    // ok: converts const char* elements to string
    std::forward_list<std::string> words(articles.begin(), articles.end());

    **NOTE** When we initialize a container as a copy of another container, the container type and element type of both containers must be identical

    // copies up to, but not including the element denoted by it
    std::deque<std::string> authList(authors.begin(), it);

    // under the new standard, we can list initialize a container:
    // each container has three elements, initialized from the given initializers
    //  doing so EXPLICITY specifies the values for each element in the container. Container size is IMPLICIT.
    std::list<std::string> authors = {"Milton", "Shakespear", "Austen"};
    std::vector<const char*> articles = {"a", "an", "the"};


    LIBRARY ARRAYS HAVE FIXED SIZE

    Just as the size of a built-in array is part of its type, the size of a library array is part of its type.
    When we define an array, in addition to specifying the element type, we also specify the container size:

    std::array<int, 42> a;          // type is: array that holds 42 ints;
    std::array<std::string, 10> b;  // type is: array that holds 10 strings;

    TO USE AN ARRAY TYPE WE MUST SPECIFY BOTH THE ELEMENT TYPE AND THE SIZE:
    std::array<int, 42>::size_type a;   // array type includes element and size;
    std::array<int>::size_type j;       // error: array<int> is not a type

    std::array<int, 10> ia1;                            // 10 default-initialized ints
    std::array<int, 10> ia2 = {0,1,2,3,4,5,6,7,8,9};    // list initialization
    std::array<int, 10> ia3 = {42};                     // ia3[0] = 42, all remaining elements are 0

    ALTHOUGH WE CANNOT COPY OR ASSIGN OBJECTS OF BUILT-IN ARRAY TYPES, THERE IS NO SUCH RESTRICTION ON ARRAY:
    int digs[10] = {0,1,2,3,4,5,6,7,8,9};  
    int cpy[10] = digs;                                 // error: no copy or assignment for built-in arrays
    std::array<int, 10> digits = {0,1,2,3,4,5,6,7,8,9;
    std::array<int, 10> copy = digits;                  // ok: so long as array types match

*/

// BEGIN AND END MEMBERS
std::list<std::string> a = {"Milton", "Shakespear", "Austen"};
auto it1 = a.begin();                   // std::list<std::string>::iterator
auto it2 = a.rbegin();                  // std::list<std::string>::reverse_iterator
auto it3 = a.cbegin();                  // std::list<std::string>::const_iterator
auto it4 = a.crbegin();                 // std::list<std::string>::const_reverse_iterator

// type is explicitly specified
std::list<std::string>::iterator it5 = a.begin();
// iterator or const_iterator depending on a's type
auto it7 = a.begin();                   // const_iterator only if a is const
auto it8 = a.cbegin();                  // it8 is a const_iterator

// **NOTE** when write access is not needed, use cbegin and cend!!

int main()
{
    std::array<int, 10> ia1;            // 10 default-initialized ints

    return 0;
}
