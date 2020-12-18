#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>
#include <string>
#include <iterator>

// e10.42   - reimplement the program that eliminated duplicate words that we wrote in 10.2.3 to use list instead of vector

void elimDupes(std::list<std::string> &slist) {
    slist.sort();           // default < sort
    slist.unique();         // remove non-unique elements

    for(auto &s : slist) { std::cout << s << std::endl; }
}

int main()
{   
    std::list<std::string> slist = {"the", "fox", "fox", "quick", "quick", "quick", "brown", "jumped", "fox", "jumped"};
    elimDupes(slist);


    return 0;
}
