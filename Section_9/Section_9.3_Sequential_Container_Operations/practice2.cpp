#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>

/*
    ERASING ELEMENTS
        There are several ways to remove elements. 
        **NOTE** The memebers that remove elements do not check the arguments. The programmer must ensure that elements exist before removing them.
    
        pop_front and pop_back Members 
            .pop_front() - removes the first element   | no pop_front for strings or vectors
            .pop_back() - removes the last element     | no pop_back for forward_list

            These operations return void - if you need to call the value, you should store it beforehand

            while(!c.empty()) {
                process(ilist.front());     // do something with the current top of ilist
                ilist.pop_front();          // done; remove first element
            }
        
        erase Members
            .erase(p)   - removes element at iterator p  | container<type>::iterator p
            
            We can delete a single element denote by an iterator or a range of elements marked by a pair of iterators.
            Both forms of erase return an iterator referring to the location AFTER the (last) element that was removed.
            If J is the element following I, then erase(I) will return an iterator referring to J

            std::list<int> lst = {0,1,2,3,4,5,6,7,8,9};
            auto it = lst.begin();                     
            while (it != lst.end()) {
                if (*it % 2) {                  // if the element is odd
                    it = lst.erase(it);         // erase it
                } else {
                    ++it;                       // if even, incremenet
                }
            }

            The iterator-pair version of erase lets us delete a range of elements:

            // delete the range of elements between two iterators
            // returns an iterator to the element just after the last removed element
            elem1 = slist.erase(elem1, elem2);          // after the call elem1 == elem2

        clear Member
            .clear()    - remove all elements from container

            std::list<int> ilist = {0,1,2}; 
            ilist.clear();                              // remove all elements from ilist
            ilist.erase(ilist.begin(), ilist.end());    // same as calling .clear()

    SPECIALIZED forward_list OPERATIONS
        Operations to add or remove elements in a forward_list operate by changing the element after the given element. That way
        we always have access to the elements that are affected by the change.

        .before_begin()     - iterator denoting the nonexistent element just before the beginning of the list.
        .cbefore_begin()    - const_iterator
        .insert_after(p,t)  - Inserts elements after the one denoted by iterator p. T is an object, n is a count.
        .insert_after(p,n,t)- 
        .insert_after(p,b,e)- b and e are iterators denoting a range
        .insert_after(p, il)- il is a braced list.
                                All these return an iterator to the last inserted element. If the range is empty, 
                                returns p. Undefined if p is off-the-end iterator
        emplace_after(p, args)- uses args to construct an element after the one denoted by iterator p. returns an iterator to the new element.
                                Undefined if p is off-the-end iterator.
        erase_after(p)    - removes the element after the one denoted by iterator p
        erase_after(b,e)  - range of elements from one after the iterator b up to but not including iterator e
                                Returns an iterator to the element after the one deleted

    RESIZING A CONTAINER
        The the exception of arrays, we can use resize to make a container larger or smaller.
        If the current size is greater than the requested size, elements are deleted from the back of the container. 
        If the current size is less than the new size, elements are added to the back of the container

        std::list<int> ilist(10,42);            // 10 ints initialized to 42;
        ilist.resize(15);                       // adds five elements of value 0 to the back of ilist (value initialized)
        ilist.resize(25, -1);                   // adds ten elements of value -1 to the back of ilist
        ilist.resize(5);                        // erases 20 elements from the back of ilist

        **NOTE** If the container holds elements of a class type and resize adds elements, we must supply an initializer or 
            the element type must have a default constructor.
        
    CONTAINER OPERATIONS MAY INVALIDATE ITERATORS
        Using an invalid pointer, reference, or iterator is a serious programming error and likely to lead to 
        the same kind of problems as using an uninitialized pointer

        When you use an iterator (or a reference or pointer to a container element), it is a good idea to minimize
        the part of the program during which an iterator must stay valid. Because code that adds or removes elements to a container
        can invalidate iterators, you need to ensure that the iterator is repositioned, as appropriate, after each operation
        that changes the container. This is especially true for vector, string, and deque.

    WRITING LOOPS THAT CHANGE A CONTAINER
        Loops that add or remove elements of a vector, string or deque must cater to the fact that iterators, reference, or pointers might be invalidated
        insert and erase return iterators, which we can use to reset the iterator

            // loop to remove even-valued elements and insert a duplicate of odd-valued elements
            std::vector<int> vi = {01,2,3,4,5,6,7,8,9};
            auto iter = vi.begin();
            while (iter != vi.end()) {
                if (*iter % 2) {
                    //iter = iv.insert(iter, *iter++);      // TESTING FOR EXERCISE 932
                    iter = vi.insert(iter, *iter);       // duplicate the current element
                    iter += 2;                          // advance past this element and the one inserted before it
                } else {
                    iter = vi.erase(iter);              // remove even element
                    // don't advance the iterator. iter denotes the element after the one we erased
                }
            }

    AVOID STORING THE ITERATOR RETURNED FROM END
        The iterator returned by end is always invalidated. Thus, any loops that ADD or REMOVE elements should always 
        call end rather than use a stored copy.
            // in this case, do not use auto end = vi.end() or something similar
            // while (begin != vi.end()) will work. .begin() can be assigned

        This is because one an element is ADDED or REMOVED, the iterator stored (auto end = vi.end()) is invalidated.

        **NOTE** Don't cache the iterator returned from .end() in loops that insert or delete elements in a deque, string or vector

            // Rather than storing end, we must recompute it after each insertion
            while (begin != vi.end()) {
                ++begin;                        // want to insert after element
                begin = vi.insert(begin,42);    // insert new value at begin
                ++begin;                        // advance past new element
            }

*/

void fwd_list() {
    std::forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
    auto prev = flst.before_begin();                        // denotes element "off the start" of flst
    auto curr = flst.begin();                               // denote the first element of flst
    while (curr != flst.end()) {                            // while still elements to process
        if (*curr % 2) {                                    // if element is odd
            curr = flst.erase_after(prev);                  // erase it and move curr
        } else {
            prev = curr;                                    // move the iterators to denote the next
            ++curr;                                         // element and one before the next element
        }
    }

    for (auto &i : flst) {
        std::cout << i <<std::endl;
    }
}

void loop_container() {
    // loop to remove even-valued elements and insert a duplicate of odd-valued elements
    std::vector<int> vi = {1,2,3,4,5,6,7,8,9};
        auto iter = vi.begin();
        while (iter != vi.end()) {
            if (*iter % 2) {
                //iter = vi.insert(iter, *iter++);      // TESTING FOR EXERCISE 932
                iter = vi.insert(iter, *iter);       // duplicate the current element
                iter += 2;                          // advance past this element and the one inserted before it
            } else {
                iter = vi.erase(iter);              // remove even element
                // don't advance the iterator. iter denotes the element after the one we erased
            }
        }

        for (auto &i : vi) {
            std::cout << i <<std::endl;
        }
}

void pop_elements() {
    std::list<int> ilist = {0,1,2,3,4}; 

    //ilist.pop_front();                // remove only first element of container
    while (!ilist.empty()) {            // empty out container
        ilist.pop_front();
    }

    for (auto &i : ilist) {
        std::cout << i <<std::endl;
    }
}


int main()
{
    //pop_elements();
    //fwd_list();
    loop_container();

    return 0;
}
