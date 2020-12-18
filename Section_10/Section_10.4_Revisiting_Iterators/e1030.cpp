#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>

// Use stream iterators sort and copy to read a sequence of ints from cin, sort them, then write back output

bool check_ints(int i1, int i2) { return i1 < i2; }

int main()
{
    std::vector<int> ivec;                          // vector to hold ints
    std::istream_iterator<int> ifs(std::cin), eof;  // input stream and end of file iterator

    while(ifs != eof) { ivec.push_back(*ifs++); }   // while valid input

    std::sort(ivec.begin(), ivec.end(), bind(check_ints, std::placeholders::_1, std::placeholders::_2));            // sort 
    std::copy(ivec.cbegin(), ivec.cend(), std::ostream_iterator<int>(std::cout, " "));                              // print

    return 0;
}