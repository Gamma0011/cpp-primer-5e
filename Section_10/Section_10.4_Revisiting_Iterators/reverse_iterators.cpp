#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>

void reverseIteration(){
    std::vector<int> ivec = {0,1,2,3,4,5,6,7};
    for (auto r_iter = ivec.crbegin(); r_iter != ivec.crend(); ++r_iter) { std::cout << *r_iter <<std::endl; }
}

void sortReverse() {
    std::vector<int> ivec = {10,3,2,8,9,5,40,23};
    std::sort(ivec.begin(), ivec.end());                // sort in ascending order
    for (auto &i : ivec) { std::cout << i << " ";}
    std::cout <<std::endl;

    std::sort(ivec.rbegin(), ivec.rend());              // sort in descending order
    for (auto &i : ivec) { std::cout << i << " "; }
    std::cout <<std::endl;
}

void reverseIteratorRelationships() {
    std::string s("FIRST,MIDDLE,LAST");
    auto comma = std::find(s.cbegin(), s.cend(), ',');
    std::cout << std::string(s.cbegin(), comma) <<std::endl;        // will print FIRST

    auto rcomma = std::find(s.crbegin(), s.crend(), ',');
    std::cout << std::string(s.crbegin(), rcomma) <<std::endl;      // will print TSAL instead of LAST
    // rcomma is currently a reverse iterator, we will need to fix this to properly print LAST
    // to do this, we need to transform rcomma back to a ordinary iterator by calling reverse iterator's base member
    // the reverse iterator is transformed into a forward iterator
    // **NOTE** the resulting transformation doesn't create an iterator that refers to the same element
    std::cout << std::string(rcomma.base(), s.cend()) <<std::endl;

}

int main()
{
    //reverseIteration();
    //sortReverse();
    reverseIteratorRelationships();

    return 0;
}
