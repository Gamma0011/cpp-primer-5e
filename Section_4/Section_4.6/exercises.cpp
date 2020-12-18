#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

void e420()
{
    // assuming iter is a vector<string>::iterator, which are legal, explain behavior and why which ones arent legal
    // *iter++              legal, increments the iterator then dereferences the pointer
    // (*iter)++            illegal, cannot increment a string
    // *iter.empty()        illegal, iter is a pointer that has not member called .empty | (*iter).empty() is correct way to type
    // iter->empty()        legal, same as (*iter).empty(); dereference pointer iter then check if empty, return bool
    // ++*iter              illegal, ++ cannot increment a string ++(*iter)
    // iter++->empty()      legal, dereference incremented iter element and check if empty, increments iter (*iter)++->empty()
}

int main()
{


    return 0;
}
