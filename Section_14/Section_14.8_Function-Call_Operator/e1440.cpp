#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

/*
    e14.40  - Rewrite the biggies function from 10.3.2 to use function-object classes in place of lambdas
*/

class ShorterString {
public:
    bool operator()(const std::string &a, const std::string &b) { return a.size() < b.size(); }
};

class FindIf {
public:
    FindIf(std::vector<std::string>::size_type s) : sz(s) { };
    bool operator()(const std::string &s) const { return s.size() > sz; }
private:
    std::vector<std::string>::size_type sz;
};

class ForEach {
public:
    void operator()(const std::string &s) { std::cout << s << " "; }
};

void elimDups(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies
(std::vector<std::string> &words, std::vector<std::string>::size_type sz) {
elimDups(words);        // put words in alphabetical order and remove duplicates
std::stable_sort(words.begin(), words.end(), ShorterString());

auto wc = std::find_if(words.begin(), words.end(), FindIf(sz));

auto count = words.end() - wc;

std::cout << count << " " << (count > 1 || count == 0 ? "words" : "word") << " of length "
          << sz << " or longer." <<std::endl;

std::for_each(wc, words.end(), ForEach());
std::cout << std::endl;
}


int main(int argi, char **argc)
{
    // std::ifstream open(argc[1]);
    std::ifstream open("text.txt");
    std::vector<std::string> svec;

    if(open) {
        std::string line, word;
        while (std::getline(open, line)) {
            std::stringstream read(line);
            while (read >> word) {
                svec.push_back(word);
            }
        }
    } else {
        std::cerr << "ERROR: File not found." <<std::endl;
    }

    biggies(svec, 20);

    return 0;
}
