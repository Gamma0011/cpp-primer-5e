#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void e324(){
    // redo last exercise from 3.3.3 using iterators
    // read a set of integers into vector. print sum of each pair of adjacent elements
    //  then print the sum of the first and last elements followed by second- so on

    vector<int> ivec{1,2,3,4,5,6,7,8,9,10};

    for(auto it = ivec.cbegin(); it < ivec.cend()-1; ++it){
        cout << *it + *(it +1) << '\t';
    }
    
    auto mid = ivec.cbegin() + (ivec.end() - ivec.cbegin())/2;
    for(auto it = ivec.cbegin(); it < mid; ++it){
        cout << *it + (ivec.cend()-(it)) << '\t';
    }
}

void e325(){
    // rewrite grade cluster program using iterators
    // count the number of grades by clusters of ten: 0-9, 10-19, etc;

    /*      Original

    vector<unsigned> scores(11,0);      // 11 buckets, all initialized to 0;
    unsigned grade;
    while(cin >> grade){
        if (grade <= 100){
            ++scores[grade/10];         // grade/10 +1 (accounting for 0)
        }
    }

    */

   vector<unsigned> scores(11,0);
   unsigned grade;

   while(cin >> grade){
       ++*(scores.begin() + grade/10);
   }
   for(auto &elem : scores){
       cout << elem << " ";
   }

}

int main()
{
    //e324();
    //e325();
    // 3.26 First, there is no operator + for two iterators. Second, for arithmetic types, using mid = (beg + end) / 2 may lead to overflow.

    return 0;
}
