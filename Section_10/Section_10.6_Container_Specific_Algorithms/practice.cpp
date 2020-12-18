#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <numeric>

/*
    || CONTAINER-SPECIFIC ALGORITHMS ||
        list and forward_list define several algorithms as members. The list types define their own versions of sort, merge,
        remove, reverse, and unique.

        | ALGORITHMS THAT ARE MEMBERS OF LIST AND FORWARD_LIST |
        
        lst.merge(lst2)         Merges elements from lst2 to lst. Elements are removed from lst2. Uses default < operator
        lst.merge(lst2, comp)   Uses comp for merging lst2 to lst
        lst.remove(val)         Calls erase to remove each element == val
        lst.remove_if(pred)     Calls erase on elements == unary predicate
        lst.reverse()           Reverses the order of elements in lst
        lst.sort()              Default sorts elements of lst using < operator
        lst.sort(comp)          Uses comp for sorting elements of lst
        lst.unique()            Calls erase to remove consecutive copies of the same value (using ==)
        lst.unique(pred)        Uses binary predicate to call erase

        | SPLICE MEMBERS |

        lst.splice(args)    or      flst.splice_after(args)

        (p, lst2)       p is an iterator to an element in lst or an iterator one before an element in flst.
                        moves all elements from lst2 into lst just before p or into flst just after p. Elements are
                        removed from lst2. Lists' elements must be of same type
        (p, lst2, p2)   p2 is a valid iterator into lst2. Moves elements denoted by p2 into lst or moves the element
                        just after p2 into flst. lst2 can be the same as lst or flst
        (p, lst2, b, e) b and e must denote a valid range in lst2. Moves the elements in the given range from lst2.
                        lst2 and lst (or flst) can be the same list but p must not denote an element in the given range

*/

int main()
{


    return 0;
}