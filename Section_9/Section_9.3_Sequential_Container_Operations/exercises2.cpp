#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>

/*
    e925 - in the program on pg 349, that erased a range of elements, what happens if elem1 and elem2 are equal? What if both elem1 and elem2 are
        off-the-end iterator?

         elem1 == elem2             - nothing happens. Returns elem1
         elem1 && elem2 off-the-end - returns a blank line. nothing happens

    e926 - using the following definition of ia, copy ia into a vector and into a list. use the single-iterator form of erase to remove
            the elements with odd values from your list and even values from your vector

            int ia[] = {0,1,1,2,3,5,8,13,21,55,89};

    e927 - write a program to find and move the odd-valued elements in a forward_list<int>

    e928 - write a function that takes a forward_list<string> and two additional string arguments. The function should find the first string
            and insert the second string immediately following the first. If the first is not found, then insert the second string at the end of the list

    e929 - given that vec holds 25 elements, what does vec.resize(100) do? What if we reworte to vec.resize(10)?
        vec.resize(100) - adds 75 additional elements to the end of vector. values are default-initialized
        vec.resize(10)  - removes 90 elements from the end of vector. Elements 0-9 remain

    e930 - what, if any, restrictions does using the version of resize that takes a single argument place on element type?
        using the single-argument restrict the type of elements, or requires us to be more mindful of the elements we're
        resizing with. Elements will be default-initialized and elements of particular types (classes, struct, etc) will require
        a default constructor to properly initialized uninialized, resized containers
    
    e931 - the program on pg 354 to remove even-valued elements and duplicate odd ones will not work on a list or a forward_list. Why?
            revise the program so that it works on those types as well

            list and forward list won't work with this program because of the way lists deal with off-the-end iterators. lists and forward_lists
            use before_begin(), begin() and end() to iterate through elements

            see e931_fwd() and e931_list for the two variations
    
    e932 - in the program on page 354, would it be legal to write the call to insert as follows?
            iter = iv.insert(iter, *iter++);            // *iter then ++iter

            This would not be useful in this case. It would deference the interator to int then increment +1 - Segmentation Fault
    e933 - in the final example of the section, what would happen if we did not assign insert to begin?
            A - just keeping iv.insert(begin, 42) just inserts 42 at the current position of begin. As it loops, begin increments.
                Not what I expected.
    e934 - Assuming vi is a container of ints that includes even and odd values, predicit the behavior of the following loop. After you've
            analyzed this loop, write a program to test whether you were correct.

            - I predict this will loop indefinitely. Since .insert() inserts element before position, and returns 
              the position of the inserted element, it won't ever reach .end();

              Adding std::advance(iter,2); will set iter 2 positions to properly iterate
              
            iter = vi.begin();
            while (iter != vi.end()) {
                if (*iter % 2) {
                    iter = vi.insert(iter, *iter);
                } else {
                    ++iter;
                }
            }


*/

void e925() {
    std::list<std::string> slist = {"Hello", "World", "!"};
    //auto elem1 = slist.begin();
    //auto elem2 = slist.begin();
    auto elem1 = slist.end();
    auto elem2 = slist.end();
    elem1 = slist.erase(elem1, elem2);          // after the call elem1 == elem2;

    std::cout << *elem1 <<std::endl;
}

void e926() {
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    std::vector<int> ivec;
    std::list<int> ilist;

    for (auto &i : ia) {            // copy elements from ia to ivec && ilist
        ivec.push_back(i);
        ilist.push_back(i);
    }

    auto it1 = ivec.begin();
    auto it2 = ilist.begin();
    while(it1 != ivec.end() && it2 != ilist.end()) {
        if (*it1 % 2 && *it2 % 2) {
            ++it1;                        // move to next element
            it2 = ilist.erase(it2);       // erase odds from list
        } else {
            it1 = ivec.erase(it1);        // erase evens from vector
            ++it2;                        // move to next element
        }
    }

    for (auto &i : ivec) {
        std::cout << "Ivec: " << i <<std::endl;
    }
     for (auto &i : ilist) {
        std::cout << "Ilist: " << i <<std::endl;
    }


}

void e927(std::forward_list<int> f) {
    auto curr = f.begin();
    auto prev = f.before_begin();

    while (curr != f.end()) {
        if (*curr % 2) {                // if curr even
            curr = f.erase_after(prev); // remove current curr, assign curr to return of .erase_after()
        } else {
            prev = curr;
            ++curr;
        }
    }
    for (auto &i : f) {
        std::cout << i <<std::endl;
    }
}

void e928(std::forward_list<std::string> &slist, std::string to_find, std::string word) {
    auto curr = slist.begin();
    auto prev = slist.before_begin();

    for ( ; curr != slist.end(); ++curr, ++prev) {
        if (*curr == to_find) {
            slist.insert_after(curr, word);
            return;
        }
    }

    slist.insert_after(prev, word);             // if to_find not found, append word to end
}

void e931_fwd(std::forward_list<int> &ilist) {
    auto prev = ilist.before_begin();
    auto curr = ilist.begin();
    
    while (curr != ilist.end()) {
        if (*curr % 2) {
            curr = ilist.insert_after(curr, *curr);
            prev = curr;
            ++curr;
        } else {
            curr = ilist.erase_after(prev);
        }
    }
}

void e931_list(std::list<int> &ilist) { 
    auto it = ilist.begin();

    while (it != ilist.end()) {
        if (*it % 2) {                          // if ODD
            int &tmp = *it;                     // holds *it temporarily
            ++it;                               // increment 1 past value
            it = ilist.insert(it, tmp);         // insert (before) current value, return position of new value
            ++it;                               // iterate
        } else {                                // if EVEN
            it = ilist.erase(it);               // erase element, returns 1 past erased element
        }
    }
}

void e933(std::list<int> &v) {
    auto begin = v.begin();

    while (begin != v.end()) {
        ++begin;
        v.insert(begin, 42);
    }
}

void e934(std::list<int> &vi) {
auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2) {
            iter = vi.insert(iter, *iter);
            //std::advance(iter,2);
        } else {
            ++iter;
        }
    }
}

int main()
{
    //e925();
    //e926();

    std::forward_list<int> ifl = {0,1,2,3,4,5,6,7,8,9,10,11};
    std::list<int> il = {0,1,2,3,4,5,6,7,8,9,10,11};
    //e927(ifl);

    std::forward_list<std::string> slist = {"Hello", "World!", "What", "a", "day"};
    std::string a = "the";
    std::string b = "beautiful";
    e928(slist, a, b);

    //for (auto &s : slist) {std::cout << s << " ";}

    //e931_fwd(ifl);
    //e931_list(il);
    //for (auto &i : il) {std::cout << i <<std::endl;}

    //e933(il);
    e934(il);
    for (auto &i : il) {std::cout << i <<std::endl;}

    return 0;
}
