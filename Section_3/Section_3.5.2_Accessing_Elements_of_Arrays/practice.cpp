#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    // count the number of grades by clusters of ten: 0-9, 10-19, etc

    unsigned scores[11] = {};       // 11 buckets initialized to 0;
    unsigned grade;

    while(cin >> grade){
        if(grade <= 100){
            ++scores[grade/10];     // increment the counter for current cluster
        }
    }


    return 0;
}









