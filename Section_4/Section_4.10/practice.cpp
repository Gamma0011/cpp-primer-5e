#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// the comma operator takes two oeprands, which it evaluates from L->R

int main()
{
    vector<int> ivec = {0,1,2,3,4};
    // comma operator, common use in for loop
    vector<int>::size_type cnt = ivec.size();               // size 5
    //assigns values from size...1 to elements in ivec

    for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt){
        ivec[ix] = cnt;

        //cnt = 5; ix = 0, for when ix != 5, increment ix and decrement cnt
        // ivec[ix] = cnt;      ivec[0] = 5, [1] = 4, etc
    }

    return 0;
}
