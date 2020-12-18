#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    // if we need to access a control variable, then that variable must be defined outside the statement

    vector<int> v = {0,1,2,3,4,10,21};
    // find the first negative element
    auto beg = v.begin();

    while (beg != v.end() && *beg >= 0)
        ++beg;
    if (beg == v.end()){
        cout << "No negative numbers detected." <<endl;
    } else {
        cout << *beg << " detected in vector." <<endl;
    }

    return 0;
}