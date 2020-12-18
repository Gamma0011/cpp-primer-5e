#include <iostream>
#include <vector>
#include <list>
#include <deque>

/*
    e92 - define a list that holds elements that are deques that hold ints

        std::list<std::deque<int>> e;

    e93 - what are the contraints of iterators that form iterator ranges
        1 - they refer to elements of, or one past the end of the same container
        2 - "end" iterator cannot precede the "begin" iterator

    e94 - write a function that takes a pair of iterators to a vector<int> and an int value. look for that value in the range and 
            return bool indicating if the value was found
            - see bool e94(int search, std::vector<int> ivec)

    e95 - rewrite the previous program to return an iterator to the requested element. Must handle the case were the element is not found
            - see auto e95(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int search) {

    e96 - what is wrong with the following program? how might you correct it?
            list<int> lst1;
            list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
            while (iter1 < iter 2) {};

        FIXED
            std::list<int> lst1;
            std::list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
            while (iter1 != iter2) {
            ++iter1;
            }
    
    e97 - what type should be used as the index into a vector of ints?
            std::vector<int>::size_type it;

    e98 - what type should be used to read elements in a list of strings? to write them?
            read elements   - std::list<std::string>>::const_iterator           -- don't want to change elements while reading
            write elements  - std::list<std::string>>::iterator                 -- ability to change elements directly

    e99 - what is the difference betwen begin() and cbegin()?
        - begin is an iterator that will use the constness of the member object (e.g const member, const_iterator | non-const, iterator)
        - cbegin explicitly declares that the iterator will be const

    e910 - What are the types of the following four objects?
        std::vector<int> v1;                        - v1 is a vector of ints
        const std::vector<int> v2;                  - v2 is a const vector of ints
        auto it1 = v1.begin(), it2 = v2.begin();    - it1 is an iterator of a vector of ints                std::vector<int>::iterator;
                                                      it2 is a const_iterator of a const vector of ints     const std::vector<int>::const_iterator;
        auto it3 = v1.cbegin(), it4 = v4.cbegin();  - it3 is a const_iterator of a vector of ints           std::vector<int>::const_iterator;
                                                      it4 is a const_iterator of a const vector of ints     const std::vector<int>::const_iterator;

    e911 - show an exampe of each of the six ways to create an initialize a vector. Explain what values each vector contains;
        1) std::vector<int> ivec;           // 0 - default initialization                       
        2) std::vector<int> ivec = {0,1,2}; // 0, 1, 2 - list initialization
        3) std::vector<int> ivec(a);        // elements of a - copy initialization, assuming std::vector<int> a;
        4) std::vector<int> ivec(10);       // 10 elements of 0;
        5) std::vector<int> ivec(10, 2);    // 10 elements of 2;
        6) std::vector<int> ivec(a.begin(), a.end());       // same as 3. all elements in std::vector<int> a;

    e912 - explain the differences between the constructor that takes a container to copy and the constructor that takes two iterators;
        - the container makes a direct copy of all elements in the copied container, assuming types match
        - constructor that takes two iterators specifies the range of values to be copied into the other container. container types do not have to match
            and, element types don't have to match, so long as they can be converted

        std::vector<int> i1 = {1,2,3,4};
        std::vector<int> i2(i1);                        // direct copy of i1
        std::list<int> i3(++i1.begin(), --i1.end());    // i3 = {2,3};                      copy to different container type
        std::list<double> i4(i1.begin(), i1.end());     // i4 = {1.0, 2.0, 3.0, 4.0};       different container and conversion to implicit type

    e913 - how would you initialize a vector<double> from a list<int> ? From a vector<int>?

        std::list<int> i1 = {1,2,3};
        std::vector<double> d1(i1.begin(), i1.end());           // iteration, different container and types

        std::vector<int> i2 = {1,2,3};
        std::vector<double> d2(i2.begin(), i2.end());           // iteration because i2 elements are int, d2s are double.


*/

bool e94(int search, std::vector<int> ivec) {
    auto beg = ivec.begin();
    auto end = ivec.end();

    for ( ; beg != end; ++beg) {
        if (*beg == search) {
            return 1;
        }
    }
    return 0;
}

auto e95(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int search) {

    for ( ; begin != end; ++begin) {
        if (*begin == search) {
            return begin;
        }
    }
    return end;
}

int main()
{
    std::list<std::deque<int>> e;   
    std::vector<int> ivec = {0,1,2,3,4};

    //std::cout << ivec.size() <<std::endl;
    //std::cout << ivec.max_size() <<std::endl;

    int i = 10;

    std::cout << e94(i, ivec) <<std::endl;
    e95(ivec.begin(), ivec.end(), i);
    

    std::list<int> lst1;
    std::list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
    while (iter1 != iter2) {
        ++iter1;
    }

    return 0;
}
