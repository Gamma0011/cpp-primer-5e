#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <list>

/*  
    e10.34  - use reverse_iterator to print a vector in reverse order

    e10.35  - now print the elements in reverse order using ordinatory iterators

    e10.36  - use find to find the last element in a list with value 0

    e10.37  - Given a vector that has 10 elements, copy the elements from positions 3 to 7 in reverse order to a list
*/

void e1034() {
    std::vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};
    for (auto i = ivec.crbegin(); i != ivec.crend(); ++i) { std::cout << *i << std::endl; }
}

void e1035() {
    std::vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};
    for (auto i = ivec.cend(); i != ivec.cbegin(); --i) { std::cout << *i <<std::endl; }
}

void e1036() {
    std::list<int> ilist = {0,1,2,3,0,4,5,6,0,1};
    auto last = std::find(ilist.crbegin(), ilist.crend(), 0);
    std::cout << *last <<std::endl;
}

void e1037() {
    std::vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};
    std::list<int> ilist;

    for (auto start = ivec.crbegin() + 2, end = ivec.crend() - 3; start != end; ++start) { ilist.push_back(*start); }
    for (auto &i : ilist) { std::cout << i <<std::endl; }

}

int main()
{
    //e1034();
    //e1035();
    //e1036();

    e1037();

    return 0;
}