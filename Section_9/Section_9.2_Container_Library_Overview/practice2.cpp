#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <array>

/*
    ASSIGNMENT AND SWAP

    || BUILT-IN ARRAYS ||
    c1 = c2;            // replace the contents of c1 with a copy of the elements in c2;
    c1 = {a,b,c};       // after the assignment c1 has size 3;

    || LIBRARY ARRAY ||
    unlike built-in arrays, the liobrary array type does not allow assignment. the left-hand and right-hand operands must have the same type
    std::array<int, 10> a1 = {0,1,2,3,4,5,6,7,8,9};         // elements all have value 0
    a1 = a2;                                                // replaces elements in a1;
    a2 = {0};                                               // error: cannot assign to an array from a braced list
    
    // because the size of the right-hand operand might differ from the size of the left-hand operand, the array type
        does not support assign and it does not allow assignment from a braced list of values

    USING ASSIGN

    The assignment operator requires the left- and right-hand operands to have the same type. It copies all the elements from the
     right-hand operand to the left-hand operand. Sequential containers (except arrays) allow for a member called assign that
     lets us assign from a different, but compatible type, or assign from a subsequence of a container. The assign operation
     replaces all the elements in the left-hand container with (copies of) the elements specified by its arguments

    std::list<std::string> names;
    std::vector<const char*> oldstyle;
    names = oldstyle;                   // error: container types don't match;
    // ok: can convert from const char * to string;
    names.assign(oldstyle.cbegin(), oldstyle.cend());           // .cbegin() && .cend() dictate how many elements copied to names

    **NOTE** because the existing elements are replaced, the iterators passed to assign must not refer to the container on which assign is called;

    A second version of assign takes an integral value and an element value. It replaces the elements in the container 
     with the specified number of elements, each of which has the specified element value;
    
    // equivalent to slist1.clear();
    // followed by slist1.insert(slist1.begin(), 10, "hi!");
    std::list<std::string> slist(1);                            // one element, empty string;
    slist1.assign(10, "hi!");                                   // 10 elements, each one is hi!

    USING SWAP

    The swap operation exchanges the contents of two container of the same type. After the call to swap, the elends of the two containers are interchanged/

    std::vector<std::string> svec1(10);         // 10 empty strings;
    std::vector<std::string> svec2(24);         // 24 empty strings;
    swap(svec1, svec2);                         // svec1 contains 24 elements, svec2 contains 10 elements

    CONTAINER SIZE OPERATIONS
        size        - returns the # of elements in the container
        empty       - return bool that is true if size == 0 and false otherwise
        max_size    - returns a number that is greater than or equal to the number of elements a container of that type can contain

    RELATIONAL OPERATORS
        == and != supported by all container types
        < <= > >= must be the same kind of container and elements (ex. list<string> >= list<string> works)
        
*/

int main()
{
    std::vector<std::string> svec1(10);         // 10 empty strings;
    std::vector<std::string> svec2(24);         // 24 empty strings;
    std::cout << svec1.size() << "\n" 
              << svec2.size() <<std::endl;
    swap(svec1, svec2);                         // svec1 contains 24 elements, svec2 contains 10 elements

    std::cout << svec1.size() << "\n" 
              << svec2.size() <<std::endl;

    return 0;
}
