#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "Sales_item.h"

// e10.32   - rewrite the bookstore problems from pg 24 using a vector to hold transactions and various algorithms to do the processing
//              use sort with compareISBN function from p387 to arrange transaction order. Use find and accumulate to do a sum

// how this works:
// read Sales_item object input into si_vec
// organize si_vec elements alphabetically by isbn
// iterate through si_vec running find_if to see if isbns match
// if they do match, accumulate the sums of matching isbns

// For Loop - assign beg == .begin(), create a copy of beg and save as end.
//      iterate through si_vec
//      run find_if, which will iterate begin() to end() and return .end() if condition not met

bool sortIsbn(const Sales_item &s1, const Sales_item &s2) { return s1.isbn() < s2.isbn(); }
void organize(std::vector<Sales_item> &s) { std::sort(s.begin(), s.end(), sortIsbn); }

int main()
{
    std::vector<Sales_item> svec;
    std::istream_iterator<Sales_item> ifs(std::cin), eof;

    while(ifs != eof) { svec.push_back(*ifs++); }
    organize(svec);

    for(auto beg = svec.cbegin(), end = beg; beg != svec.cend(); beg = end) {
        end = std::find_if(beg, svec.cend(), [beg](const Sales_item &s){ return s.isbn() != beg->isbn(); });
        std::cout << std::accumulate(beg, end, Sales_item(beg->isbn())) << std::endl;
    }


    return 0;
}