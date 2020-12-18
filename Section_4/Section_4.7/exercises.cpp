#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::endl;

void e421()
{
    // write a program to use a conditional operator to find elements in a vector that have odd value and double value of element
    vector<int> ivec = {2,4,7,8,10,3,1,9,8};

    for (auto &i : ivec){
        cout << ((i%2 != 0) ? i*2 : i) << '\t';
    }
}

void e422()
{
    // extend high pass program. to assign low pass for 60-75. Write two versions, one with ?: and other with multiple if statements
    // definitely prefer multiple if statements, although that too doesn't look too nice. It's much more readable though

    int grade(100);
    cout << ((grade > 90) ? "High Pass" : (grade > 75) ? "Pass" : (grade > 60) ? "Low Pass" : "Fail") <<endl;


    if (grade > 90) {
        cout << "High Pass" <<endl;
    } if (grade < 90 && grade > 75) {
        cout << "Pass" <<endl;
    } if (grade < 75 && grade > 60) {
        cout << "Low Pass" <<endl;
    } if (grade < 60) {
        cout << "Fail" <<endl;
    }
}

void e423()
{
    // this expression fails to compile due to operator precedence. explain why it fails and fix.
    string s = "word";
    // operator precedence wrong. Need to solve s[s.size -1] and check equality, then conditional check before appending to string literal
    // string p1 = s + s[s.size() - 1] == 's' ? "" : "s";
    string p1 = s + (s[(s.size() - 1)] == 's' ? "" : "s");
    cout << p1 <<endl;
}

void e424()
{
    int grade(78);
    string finalgrade;
    finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
    cout << finalgrade <<endl;

    // left associative will always produce fail, finalgrade is undefined and won't resolve == expression
}

int main()
{

    //e421();
    //e422();
    //e423();
    e424();

    return 0;
}
