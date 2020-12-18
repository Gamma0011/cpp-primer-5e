#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>

/*
    || ITERATOR CATEGORIES ||

        | INPUT ITERATORS |
            - Equality and inequality operators (== , !=) to compare two iterators
            - Prefix and postfix incremenet (++) to advance the iterator
            - Dereference operator (*) to read an element; dereference may apprear only on the right-hand side of an assignment
            - The arrow operator (->) as synonym for (*it).member. Dereference the iterator and fetch a member from the underlying object.

            find and accumulate use input iterators

        | OUTPUT ITERATORS |
            - Prefix and postfix incremenet (++) advance the iterator
            - Dereference (*) which may appear only as the left-hand side of an assignment.

            the third parameter of copy uses an output iterator

        | FORWARD ITERATORS |
            - Can read and write a given sequence
            - Only move in one direction
            - Can read or write the same element multiple times and can be used to make multiple passes through a sequence

            replace requires a forward iterator
        
        | BIDIRECTIONAL ITERATORS |
            - Can read or write a sequence forward or backward
            - Supports the same operations as a forward iterator as well as the prefix and postfix decremenet (--) operator

            reverse requires a bidirectional iterator

        | RANDOM-ACCESS ITERATORS |
            - The relational operators (<, <=, >, >=) to compare relative positions
            - Additional and subtraction operators (+, +=, -, -=) on an iterator and an integral value. The result is the iterator
                advanced or retreated the integral number of elements within the sequence
            - The subtraction operator (-) when applied to two iterators, which yields the distance between two iterators
            - The subscript operator (iter[n]) as a synonym for *(iter + n)

            sort requires random-access iterators. iterators for array, deque, string, and vector are random-access iterators,
                as are pointers when used to access elements of a built-in array

    || ALGORITHM PARAMETER PATTERNS ||

        Most common algorithm forms:            (beg && end denote an input range) (dest, beg2, end2 are all iterators)
            alg(beg, end, other args);
            alg(beg, end, dest, other args);
            alg(beg, end, beg2, other args);
            alg(beg, end, beg2, end2, other args);

    || ALGORITHMS WITH SINGLE DESTINATION ITERATORS ||
        A dest parameter is an iterator that denotes a destination in with the algorithm can write its output. Algorithms
        assume it is safe to write as many elements as needed into the destination

            If dest is an iterator referring directly to a container, the algorithm writes its output to existing container elements.
            More commonly, dest is bound to an insert iterator or an ostream_iterator
            - Insert iterators add new elements, ensuring there is always enough space
            - Ostream_iterators write to an output stream

    || ALGORITHMS WITH A SECOND INPUT SEQUENCE ||
        beg2 and/or beg2, end2 denote a second input range
            - Algorithms that only take beg2 treat it as the first element. These algorithms assume the range starting at beg2
                is at least as large as the one denoted by beg, end.
            
    || ALGORITHM NAMING CONVENTIONS ||

        || ALGORITHMS THAT USE OVERLOADING TO PASS A PREDICATE ||
            Some algorithms can use the element type's operator to compare elements, other times, it'll allow for a second
            parameter that is a predicate to use in the place of < or ==
            ex.     unique(beg, end);               // uses default == operator to compare elements
                    unique(beg, end, comp);         // uses comp to compare elements, returns true or false

        || ALGORITHMS WITH _IF VERSIONS ||
            Algorithms that take an element value typically have a second named (non-overloaded) version that takes a predicate
            in place of a value. algorithms with _if take predicates
            ex.     find(beg, end, val);            // find the first instance of val in the input range
                    find_if(beg, end, pred);        // find the first instance in which pred == true
            
        || DISTINGUISHING VERSIONS THAT COPY FROM THOSE THAT DO NOT ||
            By default, algorithms that rearrange elements write the rearranged elements back into the given input range. 
            These also provide a second version that write to a specified output destination, these use _copy
            ex.     reverse(beg, end);              // reverse the elements in input range
                    reverse_copy(beg, end, dest);   // copy elements in reverse order into dest

            Additionally, some algorithms provide both _copy and _if versions, which take a dest iterator and a predicate
            ex.         // removes odd elements from v1
                    remove_if(v1.begin(), v1.end(), [](int i){ return i % 2; });                        
                        // copies only the even elements from v1 into v2; v1 is unchanged
                    remove_copy_if(v1.begin(), v1.end(), bacK_inserter(v2), [](int i){ return i % 2; });

*/

int main()
{
    test();

    return 0;
}
