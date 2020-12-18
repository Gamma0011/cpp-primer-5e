#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <string>

/*
    e914 - write a program to assign the elements from a list of char * pointers to c-style character strings to a vector of strings

    e915 - write a program to determine whether two vector<int>s are equal

    e916 - repeat the last program but compare elements in a list<int> to a vector<int>

    e917 - assuming c1 and c2 are containers, what (if any) constraints does the following usage place on the types of c1 and c2?
            if (c1 < c2); 
            c1 and c2 must be same container type and have same elements within their respective containers
*/

void e914() {
    std::list<const char*> cl = {"this", "that", "these", "those"};
    std::list<std::string> cs;
    std::vector<std::string> svec;

    cs.assign(cl.cbegin(), cl.cend());
    svec.assign(cs.cbegin(), cs.cend());

    for (auto &s : svec) {
        std::cout << s <<std::endl;
    }
}

bool e915(std::vector<int> v1, std::vector<int> v2) {
    if (v1 == v2) {
        return true;
    } else {
        return false;
    }
}

bool e916(std::list<int> l1, std::vector<int> v2) {

    std::vector<int> v1;
    v1.assign(l1.cbegin(), l1.cend());

    if (v1 == v2) {
        return true;
    } else {
        return false;
    }

}  

int main()
{
    //e914();

    std::vector<int> vec1 = {0,1,2,3};
    std::vector<int> vec2 = {0,1,2,3,4};
    std::list<int> lst1 = {0,1,2,3};
    //std::cout << e915(vec1, vec2) <<std::endl;
    std::cout << e916(lst1, vec1) <<std::endl;

    return 0;
}
