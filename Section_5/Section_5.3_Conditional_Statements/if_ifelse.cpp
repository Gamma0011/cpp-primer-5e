#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/*
if (condition)
    statement


if (condition)
    statement
else
    statement2


the condition in an if statement must always be enclosed in () and the condition must have a type convertable to bool

*/

void ifelsestatement()
{
    const vector<string> scores = {"F", "D", "C", "B", "A", "A+"};

    // if grade is < 60, F. 
    int grade = 56;
    string lettergrade;

    if (grade < 60){
        lettergrade = scores[0];
    } else {
        lettergrade = scores[(grade - 50) /10];
    }

    cout << lettergrade <<endl;



}

int main()
{
    ifelsestatement();

    return 0;
}
