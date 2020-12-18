#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void e55()
{
    // using if-else write your own version of the pgorame to generate a letter grade from a numeric grade

    int grade;
    string lettergrade;
    vector<string> letters = {"F", "D", "C", "B", "A", "A+"};

    cout << "Please enter your number grade: ";
    cin >> grade;

    if (grade < 60) {
        lettergrade = letters[0];
    } else {
        if (grade == 100){
            lettergrade = letters[5];
        } else {
            lettergrade = letters[(grade - 50) / 10];
        } if (grade % 10 < 3) {
            lettergrade += "-";
        } else if (grade % 10 > 7) {
            lettergrade += "+";
        }
    }

    cout << "You received a " << lettergrade <<endl;
}

void e56()
{
    // rewrite your program in e55 to use the conditional operators : ?

    int grade;

    vector<string> letters = {"F", "D", "C", "B", "A", "A+"};

    cout << "Please enter your numeric grade: " <<endl;
    cin >> grade;

    string lettergrade = (grade < 60) ? letters[0] 
                                      : (grade == 100) ? letters[5] : letters[(grade - 50) / 10];
    
    lettergrade += (grade % 10 > 7) ? "+"
                                    : (grade % 10 < 3) ? "-" : "";
    
    cout << lettergrade <<endl;
}


void e57()
{
    // correct the errors in each of the following code fragments;

    /*

    a) if (ival != ival2)
        ival 1 = ival2
        else ival1 = ival2 = 0;

    a1) if (ival != ival2) {
            ival1 = ival2;
        } else {
            ival 1 = ival2 = 0;
        }

    b) if (ival < minval)
            minval = ival;
            occurs = 1;
    
    b1) if (ival < minval) {
            minval = ival;
            occurs = 1;
        }


    c) if (int ival = get_value())
            cout << "ival = " << ival <<endl;
        if (!ival)
            cout << "ival = 0\n";

    c1) if (int ival = get_value()) {
            cout << "ival = " << ival <<endl;
        } else if (!ival) {
            cout << "ival = 0\n";
        }

    d) if (ival = 0)
            ival = get_value();

    d1) if (ival == 0) {
            ival = get_value();
        }

    */
}

void e57()
{
    // what is a dangling else, how are else clauses resolved in c++?

    // a dangling else if when there are more ifs than there are elses. this poses the problem of knowing to which if, each else belongs
    // C++ resolves this by pairing a danging else to the closest, preceeding, unmatched if
}

int main()
{
    //e55();
    e56();

    return 0;
}
