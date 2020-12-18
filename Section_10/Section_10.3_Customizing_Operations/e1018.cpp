#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
    e10.18 - rewrite biggies to use partition instead of find_if 

    e10.19 - rewrite 10.18 to use stable_partition

    **ORIGINAL**

void print(const std::vector<std::string> &words) { for (auto &w : words) { std::cout << w <<std::endl; } }
std::string make_plural(std::size_t c, const std::string &s, const std::string &e) { return c >= 2 ? s + e : s; }

void elimDups(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());                      // sort alphabetically
    auto unique_elem = std::unique(words.begin(), words.end()); // find first non-unique element
    words.erase(unique_elem, words.end());                      // remove all non-unique elements
}

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz) {
    elimDups(words);

    std::stable_sort(words.begin(), words.end(),                    // sort by size, maintaining alphabetical sorting within size
                    [](const std::string &a, const std::string &b) 
                    { return a.size() < b.size(); } );

    // get iterator to the first element whose size() >= sz
    auto wc = std::find_if(words.begin(), words.end(), [sz](const std::string &s) { return s.size() >= sz; });

    auto count = words.end() - wc;          // get number of elements >= sz
    std::cout << count << make_plural(count, " word", "s") << " of length " << sz << " were found." <<std::endl;
    
    std::for_each(wc, words.end(), [](const std::string &s) { std::cout << s << " "; });
    std::cout << std::endl;
}
*/


// ***** e10.18 ***** //

void elimDupes(std::vector<std::string> &s) {
    std::sort(s.begin(), s.end());      // sort alphabetically
    std::vector<std::string>::iterator i = std::unique(s.begin(), s.end());
    s.erase(i, s.end());
}

void strSize(std::vector<std::string> &svec, std::vector<std::string>::size_type sz) {
    elimDupes(svec);
    std::stable_sort(svec.begin(), svec.end(), [](const std::string &s1, const std::string &s2) { return s1.size() < s2.size(); } );

    auto n = std::partition(svec.begin(), svec.end(), [sz](const std::string &s) { return s.size() >= sz; });

    svec.erase(n, svec.end());              // remove all elements < sz
}

void print(const std::vector<std::string> &words) { for (auto &w : words) { std::cout << w <<std::endl; } }

// ***** e10.19 ***** //

void part_sort(std::vector<std::string> &svec, std::vector<std::string>::size_type sz) {
    elimDupes(svec);
    std::vector<std::string>::iterator i = std::stable_partition(svec.begin(), svec.end(), [sz](const std::string &s) { return s.size() >= sz; } );
    svec.erase(i, svec.end());
}

int main()
{
    
    std::vector<std::string> svec = {"this", "is", "another", "vector", "of", "of", "a", "vector", "strings"};

    //strSize(svec, 5);
    part_sort(svec, 7);
    print(svec);
    

    return 0;
}