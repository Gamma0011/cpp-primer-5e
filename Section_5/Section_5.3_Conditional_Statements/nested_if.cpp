#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void nestedifs()
{
    // to make our program more interesting, we'll add a plus or minus to passing grades. 
    // a plus is assigned to grades ending in 8 or 9, and a minus to those ending in 0,1,2
    
    int grade;
    cout << "Please enter a grade: ";
    cin >> grade;
    const vector<string> scores = {"F", "D", "C", "B", "A", "A+"};
    string lettergrade;

    if (grade < 60) {
        lettergrade = scores[0];
    } else {
        lettergrade = scores[(grade - 50) / 10];
        if (grade != 100)
            if (grade % 10 > 7)
                lettergrade += '+';
            else if (grade % 10 < 3)
                lettergrade += '-';
    }
    cout << "You got a " << lettergrade <<endl;



}

int main()
{
    nestedifs();

    return 0;
}
