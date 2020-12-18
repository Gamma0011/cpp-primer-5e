#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


void interator_types(){

    //const vs normal iterators

    vector<int>::iterator it;           // it can read and write vector<int> elements;
    string::iterator it2;               // it2 can read and write characters in a string;
    vector<int>::const_iterator it3;    // it3 can read but not write elements;
    string::const_iterator it4;         // it4 can ready but not write characters;

}

void begin_end_operations(){
    vector<int> v;
    const vector<int> cv;
    auto it1 = v.begin();               // it1 has type vector<int>::iterator
    auto it2 = cv.begin();              // it2 has type vector<int>::const_iterator


    //C++ 11 introduced cbegin and cbegin to denote const_iterators
    auto it3 = v.cbegin();              // it3 has type vector<int>::const_iterator;
}


void combine_dereference_member_access(){

    // when we dereference an iterator, we get the object that the iterator denotes
    // print each line in text up to first blank line
    vector<string> text{"This is a test."};

    for (auto it = text.cbegin(); it !=text.cend() && !it->empty(); ++it){
        cout << *it <<endl;
    }

}
int main()
{

    combine_dereference_member_access();

    return 0;
}