#include <iostream>
#include <string>
#include <vector>

using std::cin; 
using std::cout; 
using std::endl; 
using std::string;
using std::vector;

// goto provides an unconditional jump from the goto to another statement in the same function.

// BEST PRACTICE: programs should NOT use gotos as they are hard to understand and modify

void practice()
{
    int ix;
    goto end;

    ix = 10;

    end: 
        // bypass ix = 10 and initialize ix to value of 42;
        ix = 42;
    
    cout << ix <<endl;
}

void practice2()
{

    // go to can also go backwards in the program.

    begin:
    string s;
    char yn;

    cout << "Please enter a word: " <<endl;
    cin >> s;

    cout << "Would you like to enter another word? (y/n)" <<endl;
    cin >> yn;
    if (yn == 'y') {
        goto begin;
    } else {
        cout << "The last word you entered was: " << s <<endl;
    }





}

int main()
{
    //practice();
    practice2();


    return 0;
}
