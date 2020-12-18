#include <iostream>
#include <vector>
#define NDEBUG

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

// e647 - revise the program in e632 (pg 228) that used recursion to print contents of a vector to conditionally print info about its execution
// for example, print the size of the vector on each call, compile and run the program with debugging on and off

void printElements(vector<int> ivec)            // make a copy, we don't want the iteration to be destructive
{
    #ifndef NDEBUG
        cout << "Vector Size: " << ivec.size() <<endl;
    #endif

    if (!ivec.empty()) {
        auto tmp = ivec.back();         // grab element, save as tmp
        ivec.pop_back();               // remove element
        printElements(ivec);            // recusion of function until !empty() condition met
        cout << tmp << '\t';            // print element
    }
}

int main()
{
    vector<int> ivec = {0,1,2,3,4,5,6,7,8};
    printElements(ivec);

    if (ivec.empty()) {
        cout << "e" <<endl;
    }

    return 0;
}
