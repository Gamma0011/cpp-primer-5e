#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

void e314()
{
    // write a program to read a sequence of ints from cin and store those in a vector
    int num;
    vector<int> ivec;

    while (cin >> num){
        ivec.push_back(num);
    }
}

void e315()
{
    // repeat the previouis program, but read strings instead;

    string str;

    vector<string> svec;

    while(cin >> str){
        svec.push_back(str);
    }
}

int main()
{
    //e314();
    e315();

    return 0;
}
