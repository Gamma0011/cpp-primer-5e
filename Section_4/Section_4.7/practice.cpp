#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;

// conditional operator -- ?: operator, lets us embed simple if-else logic inside an expression
// syntax -    cond ? expr1 : expr2

void condops()
{
    int grade = 90;

    string finalgrade = (grade < 60) ? "fail" : "pass";

    cout << finalgrade <<endl;
}

void nestcondops()
{
    int grade = 78;

    string finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";

    cout << finalgrade <<endl;
}

void printingcondops() 
{
    // parentheses must be used to group conditional operators together to yield expected results. 

    int grade(90);
    cout << ((grade < 60) ? "fail" : "pass") <<endl;        // yields fail/pass

}

int main()
{
    //nestcondops();
    printingcondops();

    return 0;
}