#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

/*
    e101 - the algorithm header defines a function names count that, like find, takes a pair of iterators and a value. count returns a count
            of how often that value appears. Read a sequences of ints into a vector and print the count of how many elements have a given value;

    e102 - repeat the previous program but with a list of strings;
*/

void e101() {
    int i;                  // read into
    int val = 3;            // looking for
    std::vector<int> ivec;

    while(std::cin >> i) {
        ivec.push_back(i);          // write input ints into ivec
    }

    int result = count(ivec.cbegin(), ivec.cend(), val);

    std::cout << "The number " << val << " appears "
              << result << " times." <<std::endl;
}

void e102() {
    std::string s;
    std::list<std::string> slist;
    std::string toFind("hello");

    while (std::cin >> s) {
        slist.push_back(s);
    }

    auto result = count(slist.begin(), slist.end(), toFind);

    std::cout << "The Phrase '" << toFind << "' appeared " << result << " times." <<std::endl;

}

int main()
{
    //e101();
    e102();

    return 0;
}