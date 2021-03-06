#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_set>

#include "sales_data.h"

/*
    e16.62  - Define your own version of hash<Sales_data> and define an unordered_multiset<Sales_data> objects. 
                Put several transations into the container and print the results.

                see. void e1662();

    e16.63  - Define a function template to count the number of occurrences of a given value in a vector.
                Pass a vector of double, ints and strings to test.

    e16.64  - Write a specialized version of the template from 16.63 to handle vector<const char*> and program this.
                see. void e1663(); tested there

    e16.65  - In 16.3, we defined overloaded two version of debug_rep and one had const char&, the other char*. 
                Rewrite these as specializations.

    e16.66  - What are the advantages and disadvantages of overloaded these debug_rep functions compared to definition specializations?

                http://www.gotw.ca/publications/mill17.htm
                
                Overload resolution considers all base templates equally and works in a way that you would naturally expect function overloading to work.
                Specializations don't overload, meaning that they will not affect which template gets used and most other things might be a better match,
                 even if logically the Specialization is the *best* match
    
    e16.67  - Would defining these specializations affect function matching for debug_rep? If so, how?
                In the case of only having the base class template and no other overloads, there would be no affect on function matching.
                However, providing an overload of the template to std::string debug_rep(T*), the compiler will chose this function match
                over any specialization -- in our case, template<> std::string debug_rep(const char* const &) is ignored.

                The compiler will always select overloaded templates over specialized ones for matching.

                template<typename T>
                std::string debug_ref(T* t) {
                    std::cout << "T* called" << std::endl;
                    std::ostringstream ret;
                    ret << t;
                return ret.str();
                }

                template<>
                std::string debug_ref(const char* const &c) {
                    std::cout << "const char* const & called" << std::endl;
                    std::ostringstream ret;
                    ret << c;
                    return ret.str();
                }

*/

/************** e16.62 **************/

void e1662() {
    Sales_data s1("1", 11, 111), s2("2", 22, 222), s3("3", 33, 333);

    std::unordered_multiset<Sales_data> SDMS;

    SDMS.insert(s1);
    SDMS.insert(s2);
    SDMS.insert(s3);

    for (auto beg = SDMS.begin() ; beg != SDMS.end() ; ++beg) { std::cout << *beg << std::endl; }
}

/************** e16.63 **************/
template<typename T>
std::size_t counter(std::vector<T> Tvec, T Search) {
    std::size_t count(0);
    if (Tvec.empty()) {
        return count;
    } else {
        for (auto beg = Tvec.begin() ; beg != Tvec.end() ; ++beg) {
            if(*beg == Search) {
                ++count;
            }
        }
        return count;
    } 
}

/************** e16.64 **************/
// specialized counter for const char*
template<>
std::size_t counter(std::vector<const char*> Cvec, const char* c) {
    std::size_t count(0);
    std::cout << "counter specialized with <const char*>" << std::endl;
    if (Cvec.empty()) {
        return count;
    } else {
        for (auto beg = Cvec.begin() ; beg != Cvec.end() ; ++beg) {
            if (*beg == c) {
                ++count;
            }
        }
        return count;
    }

}

void e1663() {
    std::vector<int> ivec = {0,1,2,3,4,5,6,7,7,7,7,7,8,8,8,4,3,3,4,32};
    std::vector<double> dvec = {0.2, 23.3, 23.2, 11.1, 9.9, 23.2};
    std::vector<std::string> svec = {"hello", "world", "hi", "hi"};
    std::vector<const char*> cvec = {"this", "is", "a", "test", "test"};

    int isearch = 7;
    double dsearch = 11.1;
    std::string ssearch = "hi";
    const char* csearch = "test";

    std::cout << isearch << "'s found: " << counter<int>(ivec, isearch) << std::endl;
    std::cout << dsearch << "'s found: " << counter<double>(dvec, dsearch) << std::endl;
    std::cout << ssearch << "'s found: " << counter<std::string>(svec, ssearch) << std::endl;
    std::cout << csearch << "'s found: " << counter<const char*>(cvec, csearch) << std::endl;
}

/************** e16.65 **************/
template<typename T>
std::string debug_ref(const T &t) {
    std::cout << "const &T called" << std::endl;
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

template<typename T>
std::string debug_ref(T* t) {
    std::cout << "T* called" << std::endl;
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

template<>
std::string debug_ref(const char* const &c) {
    std::cout << "const char* const & called" << std::endl;
    std::ostringstream ret;
    ret << c;
    return ret.str();
}

template<>
std::string debug_ref(char* const &c) {
    std::cout << "char* const & called" << std::endl;
    std::ostringstream ret;
    ret << c;
    return ret.str();
}

void e1665() {
    const char* c = "Hello!";
    //char* cp = "Goodbye!";
    std::cout << debug_ref(c) << std::endl;
    //std::cout << debug_ref(cp) << std::endl;
}

int main()
{
    //e1662();
    //e1663();
    e1665();

    return 0;
}