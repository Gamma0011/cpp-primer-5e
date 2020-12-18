#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <numeric>

/*
    e10.38  - list the five iterator categories and the operations they support:
                1) input iterator           ==, !=, ++, *, ->
                2) output iterator          ++, *
                3) forward iterator         ==, !=, ++, *, ->, 
                4) bidirectional iterator   ==, !=, ++, --, *, ->
                5) random-access iterator   ==, !=, ++, --, *, ->, >, >=, <, <=, iter[n], +, +=, -, -=

    e10.39  - what kind of iterator does list have? how about vector?
                - List has bidirectional iterator type  
                - Forward List has forward iterator type
                - Vector has random-access iterator type
    
    e10.40  - What kind of iterators do you think copy requires? What about reverse or unique?
                - Copy: input iterator (first 2 arguments), output iterator (last argument)
                - Reverse: bidirectional iterator (first arg, last arg)
                - Unique: forward iterator (first arg, last arg)

    e10.41  - Based only on the algorithms and argument names, descript the operations that each of the following algorithms performs
                - replace(beg, end, old_val, new_val);  search beg to end for old_val, if found, replace *iterator with new_val
                - replace_if(beg, end, pred, new_val);  search beg to end, if pred == true, replace *iterator with new_val
                - replace_copy(beg, end, dest, old_val, new_val);   search beg to end for old val, if found, write new_val to dest
                - replace_copy_if(beg, end, dest, pred, new_val);   search beg to end for pred == true, if found, write new_val to dest
*/


int main()
{


    return 0;
}