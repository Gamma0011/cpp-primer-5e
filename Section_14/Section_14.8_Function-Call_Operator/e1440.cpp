#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
    e14.40  - Rewrite the biggies function from 10.3.2 to use function-object classes in place of lambdas
*/

void elimDups(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}
void biggies
(std::vector<std::string> &words, std::vector<std::string>::size_type sz) {
elimDups(words);        // put words in alphabetical order and remove duplicates
std::stable_sort(words.begin(), words.end(), 
                 [](const std::string &a, const std::string &b) 
                 { return a.size() < b.size(); });

auto wc = std::find_if(words.begin(), words.end(),
                       [sz](const std::string &a) 
                       { return a.size() > sz; });

auto count = words.end() - wc;

std::cout << count << " " << (count > 1 ? " words " : " word ") << " of length "
          << sz << " or longer." <<std::endl;

std::for_each(wc, words.end(), [](const std::string &s){ std::cout << s << " "; });
std::cout << std::endl;
}

class EliminateDuplicates {
public:
    EliminateDuplicates(const std::vector<std::string> &s) : svec(s) { };
    bool operator()(const std::string &a, const std::string &b) { return ; }
private:
    std::vector<std::string> svec;
};

int main()
{


    return 0;
}
