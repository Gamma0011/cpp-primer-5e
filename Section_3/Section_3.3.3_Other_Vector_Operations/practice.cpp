#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

void loop() {
    vector<int> v{1,2,3,4,5,6,7,8,9};

    for (auto &i : v)                   // for each element in v (note: i is reference)
        i *= i;                         // square the element value
    for (auto i : v)                    // for each element in v
        cout << i << " ";               // print the element
    cout <<std::endl;
}

void countclusters() {
    // count the number of grades by clusters of ten: 0-9, 10-19, ... 90-99, 100
    vector<unsigned> scores(11, 0);     // 11 buckets, all initially 0
    unsigned grade;
    while(cin >> grade){                // read the grades
        if(grade <=100){                // handle only valid grades
            ++scores[grade/10];         // increment the counter for the current cluster
        }
    }
}

void subscripting() {
    vector<int> ivec;                   // empty vector
    for (decltype(ivec.size()) ix = 0; ix != 10; ++ix){
        //ivec[ix] = ix;                // disaster, ivec has no elements -- error, segmentation fault
        ivec.push_back(ix);             // correct way to add new elements
    }
}

void important() {
    // it is important to note that we may use the subscript operator [] to fetch only elements that actually exist:
    vector<int> ivec;                   // empty vector
    //cout << ivec[10];                   // error! ivec has no elements

    vector<int> ivec2(10);              // vector with 10 elements;
    //cout << ivec2[10];                  // error: vector has elements 0-9

    // best way to avoid these issues is to use range for, whenever possible for subscripting
}

int main()
{
    //loop();
    //countclusters();
    //subscripting();

}
