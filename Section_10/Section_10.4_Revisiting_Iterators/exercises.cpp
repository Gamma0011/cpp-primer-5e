#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

    /*  
        e10.26  - Explain the differences between the 3 insert iterators

                front_inserter    - inserts elements at beginning of the container.
                back_inserter     - inserts elements at end of the container.
                insert            - inserts elements before p (iterator) denoted as 2nd arg
        
        e10.27  - in addition to unique, the library defines function named unique_copy that takes a 3rd iterator denoting destination
                into which to copy. Write a program that uses unique_copy to copy the unique elements from a vector into a list

        e10.28  - Copy a vector that holds values from 1 to 9 inclusive, into 3 other containers. Use inserter, back_inserter, and
                front_inserter to add elements to each of these containers. predict the output sequences
    */

void e1027(const std::vector<int> &ivec) {
    std::list<int> ilist;
    //std::unique_copy(ivec.cbegin(), ivec.cend(), std::front_inserter(ilist));             
    std::unique_copy(ivec.cbegin(), ivec.cend(), std::inserter(ilist, ilist.begin()));      
    for (auto &i : ilist) { std::cout << i << std::endl;}
}

void e1028(const std::vector<int> &ivec) {
    std::vector<int> vec1, vec2, vec3;

    std::copy(ivec.cbegin(), ivec.cend(), std::back_inserter(vec1));                // push_back, 0-9
    //std::copy(ivec.cbegin(), ivec.cend(), std::front_inserter(vec2));             // error, vector doesn't support push_front
    std::copy(ivec.cbegin(), ivec.cend(), std::inserter(vec3, vec3.begin()));       // 0-9

    for (auto &i : vec1) { std::cout << i << " "; }
    std::cout << std::endl;
    for (auto &i : vec2) { std::cout << i << " "; }
    std::cout << std::endl;
    for (auto &i : vec3) { std::cout << i << " "; }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> ivec = {0,1,2,2,3,3,3,4,4,4};
    //e1027(ivec);

    std::vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    e1028(vec);

    return 0;
}