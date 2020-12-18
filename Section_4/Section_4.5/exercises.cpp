#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void e417() {
    // explain difference between prefix and postfix increment
    // prefix: ++i, --i increments/decrements the variable +1 or -1
    // postfix: i++, i-- increments/decrements the variable +1 or -1, but saves a copy of the original in memory
    //  creating two separate variables at the time, i and i +1 or i -1
}

void e418() {
    // what would happen if the while loop on pg 148 that prints the elements from a vector used the prefix increment operator
    // Answer: it would increment the elements, but skip the first element of the vector, then also print one past the last element of the vector,
    //  overloading the function

    /*
    vector<int> v = {0,1,2,3,4};

    auto pbeg = v.begin();
    
    while (pbeg != v.end() && *beg >= 0;) {
        cout << *pbeg << endl;
    }
    */

   vector<int> v = {0,1,2,3,4};
   auto pbeg = v.begin();

   while (pbeg != v.end() && *pbeg >= 0){
       cout << *++pbeg <<endl;
   }
}

void e419() {
    // explain behavior of each expression, which are incorrect, why, how can they be fixed?
    // ptr = int* && vector<int> vec

    int ival = 1;
    int *ptr = &ival;
    vector<int> vec = {0,1,2,3};


    if (ptr != 0 && *ptr++){            // check ptr is not nullptr, then increment ptr postfix
        cout << 't' <<endl;
    } else {
        cout << 'f' <<endl;
    }

    if (ival++ && ival) {               // checks that ival can be incremented, and if ival exists
        cout << 't' <<endl;
        cout << ival <<endl;
    } else {
        cout << 'f' <<endl;
    }

    //if (vec[ival++] <= vec[ival]){      undefined behavior, correct way
    if (vec[ival] <= vec[ival + 1]){   
        cout << 't' <<endl;
    } else {
        cout << 'f' <<endl;
    }
}

int main()
{
    //e418();
    e419();

    return 0;
}