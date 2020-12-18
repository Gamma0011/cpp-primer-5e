#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

int main()
{
    std::vector<std::string> svec = {"this", "is", "another", "vector", "of", "of", "a", "vector", "strings"};
    biggies(svec, 5);

    return 0;
}