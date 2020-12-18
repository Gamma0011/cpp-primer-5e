#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

/*  
    e10.20 - the library defines an algorithm named count_if. Like find_if, the function takes a pair of iterators denoting an input
        range and a predicate that it applies to each element in the range. count_if returns a count of how often the predicate is true
        Use count_if to rewrite the portion of our program that counted how many words are greater than length 6;
    
    e10.21 - write a lambda that captures a local int variable and decrements that variable until it reaches 0. Once variable == 0
        additional calls should no longer decrement that variable. The lambda should return a bool that indicates whether
        the captured variable is 0;

    e10.22 - rewrite the program to count words of size 6 or less using functions in place of lambdas

    e10.23 - How many arguments does bind take?
            For 10.22, bind takes 2 arguments. _1 is the std::string returned from iteration through .begin() to .end()
            The second argument _2 is assigned to be sz, std::string::size_type 6
    
    e10.24 - Use bind and check_size to find the first element in a vector of ints that has a value greater than the length of 
            the specified string value

    e10.25 - In the exercises 10.3.2 (pg 392) you wrote a version of biggies that uses partition, rewrite that function to use
            check_size and bind
*/

void e1020(std::vector<std::string> svec, std::vector<std::string>::size_type sz) {
    auto i = std::count_if(svec.begin(), svec.end(), [sz](const std::string &s) { return s.size() >= sz; });

    std::cout << i <<std::endl;
}

void e1021(int i) {
    auto dec = [&i]() {return i > 0 ? !--i : !i; };
    while(!dec()) {
        std::cout << i <<std::endl;
    }

    std::cout << i << std::endl;
}

bool e1022(const std::string &s, std::string::size_type sz) {
    return s.size() <= sz;
}

bool check_size(const std::string &s, std::string::size_type sz) { return s.size() >= sz; }

int main()
{
    std::vector<std::string> s = {"this", "hello", "world", "another", "trying"};
    std::string::size_type sz = 6;
    //e1020(s, 6);

    //e1021(10);

    /* e10.22
    std::cout << std::count_if(s.cbegin(), s.cend(), bind(e1022, std::placeholders::_1, sz)) <<std::endl;
    */

    /* e10.24 
    auto f = std::find_if(s.cbegin(), s.cend(), bind(check_size, std::placeholders::_1, sz));
    if (f != s.end()) { std::cout << *f <<std::endl;}
    */

    // e10.25
    auto p = std::partition(s.begin(), s.end(), bind(check_size, std::placeholders::_1, sz));
    s.erase(p, s.end());
    for (auto &c : s) { std::cout << c <<std::endl; }

    return 0;
}