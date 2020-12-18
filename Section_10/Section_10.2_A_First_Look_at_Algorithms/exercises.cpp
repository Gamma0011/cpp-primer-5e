#include <iostream>
#include <vector>
#include <numeric>
#include <list>
#include <algorithm>
#include <string>

/*
    e103 - use accumulate to sum the elements in a vector of ints

    e104 - assuming v is a vector<double> what, if anything, is wrong with calling accumulate(v.cbegin(), v.cend(), 0);
            setting the 3rd arg as 0 would make it return an int rather than a double
            need to declare 0 explicitly as double(0)

    e105 - In the call to equal on rosters, what would happen if both rosters held C-style strings rather than library strings?
            No real different, vector would hold const char* rather than strings

    e106 - using fill_n, write a program to set a sequence of int values to 0

    e107 - determine if there are any errors in the following programs and, if so, correct the error(s)

            (a) vector<int> vec; list<int> lst, int i;
                while (cin >> i) {
                    lst.push_back(i);
                }
                copy(lst.begin(), lst.end(), vec.begin());

                // this is wrong. cannot write to vec because it is currently empty. Must use back_iterator to write
                vector<int> vec; list<int> lst, int i;
                while (cin >> i) {
                    lst.push_back(i);
                }
                copy(lst.begin(), lst.end(), back_inserter(vec));
            
            (b) vector<int> vec;
                vec.reserve(10);        // reserve 10 elements
                fill_n(vec.begin(), 10, 0);

                // reserving doesn't produce any errors, but even with reservations, vec.begin() does not write 10 elements of 0
                    vec.begin must become std::back_inserter(vec)

    e108 - We said that algorithms do not change the size of the containers over which they operate. Why doesn't 
                back_inserter invalidate that claim?

            back_inserter is a part of the iterator header and not a part of algorithm functions themselves. Algorithms can function
            without needing to write new elements to containers, for example, writing 10 new elements to a container with 10 elements
            would produce no errors. But, when trying to write to empty containers, we must use back_inserter to ALLOW algorithms the
            ability to write. By themselves, there is no such functionality.

    e109 - implement your own version of elimDups. Test your program by printing the vector after you read the input, 
            after the call to unique and after the call to erase.
    
    e1010 - Why do you think the algorithms don't change the size of containers?

            Because algorithms operate on iterators, not container functions and therefore have no means to directly interact
            or change the container. The combination of algorithms, iterators, and container functions allow us to change the container elements.
*/

void e103() {
    std::vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};  
    int sum = std::accumulate(ivec.cbegin(), ivec.cend(), 0);

    std::cout << "Sum of vector<int> is " << sum <<std::endl;
}
void e104() {
    std::vector<double> dvec = {1.1, 2.2, 3.3, 4.5};
    double d = std::accumulate(dvec.cbegin(), dvec.cend(), double(0));

    std::cout << d <<std::endl;
}
void e105() {
    std::vector<const char*> roster1 = {"This", "is", "a", "string"};
    std::vector<const char*> roster2 = {"This", "is", "a", "of"};

    std::equal(roster1.cbegin(), roster1.cend(), roster2.cbegin()) ? (std::cout << "Both rosters match" <<std::endl)
                                                                   : (std::cout << "Rosters do not match" <<std::endl);
}
void e106() {
    std::vector<int> ivec;
    std::fill_n(std::back_inserter(ivec), 2, 0);
    for (auto &i : ivec) { std::cout << i <<std::endl; }
}
void e107a() {
    std::vector<int> vec; std::list<int> lst; int i;
    while (std::cin >> i) {
        lst.push_back(i);
        }
    std::copy(lst.begin(), lst.end(), std::back_inserter(vec));
}
void e107b() {
    std::vector<int> vec;
    //vec.reserve(10);        // reserve 10 elements
    std::fill_n(std::back_inserter(vec), 10, 0);

    for (auto &i : vec) { std::cout << i <<std::endl; }
}
void e109(std::vector<std::string> &svec) {
    
    std::sort(svec.begin(), svec.end());                            // sort elements
    for (auto &s : svec) { std::cout << s << " ";}                  // print sorted elements
    std::cout <<"Vector size: " << svec.size() << std::endl;

    auto unique_end = std::unique(svec.begin(), svec.end());        // return iterator of last unique element
    for (auto &s : svec) { std::cout << s << " ";}                  // print unique elements
    std::cout <<"Vector size: " << svec.size() << std::endl;

    svec.erase(unique_end, svec.end());                             // remove any non-unique elements from svec
    for (auto &s : svec) { std::cout << s << " ";}                  // print all elements of container with duplicates removed
    std::cout <<"Vector size: " << svec.size() << std::endl;
}

int main()
{
    //e103();
    //e104();
    //e105();
    //e106();
    //e107a();
    //e107b();

    std::vector<std::string> v = {"hello", "world", "hello", "this", "a", "beautiful", "a", "a", "this"};
    e109(v);

    return 0;
}