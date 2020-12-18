#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <iterator>
#include <list>

/*
    The library defines several additional kinds of iterators in the iterator header.

        INSERT ITERATORS:   Bound to a container and can be used to insert elements into a container
        STREAM ITERATORS:   Bound to input or output streams and can be used to iterate through the associated IO stream.
        REVERSE ITERATORS:  Move backward, rather than forward. 
        MOVE ITERATORS:     Special-purpose iterators move rather than copy elements.

    || INSERT ITERATORS ||
        3 different kinds:

        back_inserter -     creates an iterator that uses push_back
        front_inserter -    creates an iterator that uses push_front
        inserter       -    creates an interator that uses insert. This function takes a 2nd arg, which must be an iterator
                            into the given container. Elements are inserted ahead of the element denoted by iterator.

            it = t      inserts the value t at the current position denoted by it. Depending on kind of insert iterator, will call
                        c.push_back(t)      c.push_front(t)     or      c.insert(t, p) where p is position
            
            *it ++it it++   operations exist but do nothing to it, each operator returns it

    || IOSTREAM ITERATORS ||

        istream_iterator    - reads an input stream
        ostream_iterator    - writes an output stream

        Each corresponding stream treats their corresponding stream as a sequence of elements of a specified type. Using a stream
        iterator, we can use the generic algorithm to read data from or write data to stream objects.

            istream_iterator<T> in(is);     in reads values of type T from input stream is
            istream_iterator<T> end;        off-the-end iterator for an istream_iterator that reads values of type T
            in1 == in2                      in1 and in2 must read same type. == if both are end value or bound to same input stream
            in1 != in2                      otherwise !=
            *in                             returns the value read from the input stream
            in->mem                         synonym for (*in).mem
            ++in, in++                      reads next value from input stream using >> for element type. Prefix returns & 
                                            to incremented iterator. Postfix returns old value prior to increment
        
        || USING STREAM ITERATORS WITH ALGORITHMS ||

            ex. std::istream_iterator<int> in(std::cin), eof;
                std::cout << std::accumulate(in, eof, 0) <<std::endl;       // will add all value int inputs and print sum

    || OPERATIONS ON OSTREAM_ITERATOR ||

        An ostream_iterator can be defined for any type that has an output operator. When we create an ostream_iterator, we may (optionally) provide
        a second argument that specifies a character string to print following each element. THAT STRING MUST BE A C-STYLE CHARACTERT STRING. There 
        is no empty or off-the-end ostream_iterator

            ostream_iterator<T> out(os);        out writes values of type T to the output stream os
            ostream_iterator<T> out(os, d);     out writes values of type T to the output stream os. d points to a null-terminated character array
            out = val                           writes val to the ostream to which out is bound using << val must be of type compatible with type out can write
    
    || USING STREAM ITERATORS WITH CLASS TYPES ||

        We can create an istream_iterator for any type that has an input operator. Additionally, we can 
        define an ostream_iterator so long as the type has an output operator.

        For example, we can define istream and ostream iterators to work for input and outputting class objects
            std::istream_iterator<Sales_item> iter_in(std::cin), eof;
            std::ostream_iterator<Sales_item> iter_out(std::cout, "\n");

*/

void insert_it() {
    std::list<int> lst = {1,2,3,4};
    std::list<int> lst2, lst3;          // empty lists
    // after copy completes, lst2 contains 4,3,2,1
    std::copy(lst.cbegin(), lst.cend(), std::front_inserter(lst2));
    // after copy completes, lst3 container 1,2,3,4
    std::copy(lst.cbegin(), lst.cend(), std::inserter(lst3, lst3.begin()));

    for(auto &i : lst) { std::cout << i << " "; }
    std::cout << std::endl;
    for(auto &i : lst2) { std::cout << i << " "; }
    std::cout << std::endl;
    for(auto &i : lst3) { std::cout << i << " "; }
    std::cout << std::endl;
}

void istream_it() {
    std::vector<int> vec;
    std::istream_iterator<int> int_it(std::cin);        // reads ints from cin;
    std::istream_iterator<int> int_eof;                 // end iterator value;
    //std::ifstream in("afile");                              
    //std::istream_iterator<std::string> str_it(in);      // reads strings from "afile"

    // we can use an istream_iterator to read the standard input into a vector
    /*
    std::istream_iterator<int> in_iter(std::cin);       // read ints from cin
    std::istream_iterator<int> eof;                     // istream "end" iterator
    */
    
    // more concise version of above    | in_iter(cin), eof end iterator, read into ivec range in_iter to eof
        std::istream_iterator<int> in_iter(std::cin), eof;  // read ints from cin
        std::vector<int> ivec(in_iter, eof);                     // construct vec from an iterator range

    /*
    while (in_iter != eof) {                            // while there's valid input to read
                                                        // postfix increment reads the stream and returns old value of iterator
                                                        // we dereference that iterator to get previous value read from stream
        vec.push_back(*in_iter++);                       // *it++    increment post-fix, dereference previous value
    }
    */

   for (auto &i : ivec) { std::cout << i <<std::endl; }
}

void ostream_it(const std::vector<int> &vec) {
    // we can use ostream_iterator to write a sequence of value
    std::ostream_iterator<int> out_iter(std::cout, " ");
    //for(auto &e : vec) { *out_iter++ = e; }         // the assignment writes this element to cout;
    //for (auto &e : vec) { out_iter = e; }        // also valid

    // rather than writing the loop ourselves, we can more easily print the elements in vec by calling copy
    std::copy(vec.cbegin(), vec.cend(), out_iter);

    std::cout << std::endl;
}

int main()
{
    std::vector<int> ivec = {0,1,2,3,4,5,6};
    //insert_it();
    //istream_it();
    ostream_it(ivec);

    return 0;
}