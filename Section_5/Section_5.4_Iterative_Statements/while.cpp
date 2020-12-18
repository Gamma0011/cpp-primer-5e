#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void whileloop()
{
    vector<int> v;
    int i;

    // read until end-of-file or other input failure;
    while (cin >> i) {
        v.push_back(i);
    }

    auto beg = v.begin();

    while (beg != v.end() && *beg >= 0) {
        ++beg;
    }

    if (beg == v.end()) {
        ; // e know that all elements in v are greater than or equal to zero;
    }


}

int main()
{
    /* While loop syntax:

        while (condition)
            statement
    */

   whileloop();

    return 0;
}
