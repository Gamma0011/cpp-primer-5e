#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void switchstatement()
{
    // initialize counters for each vowel;
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;

    char ch;
    while (cin >> ch) {
        // if ch is a vowel, incremenet the appropriate counter;
        switch(ch) {
            case 'a':
                ++aCnt;
                break;
            case 'e':
                ++eCnt;
                break;
            case 'i':
                ++iCnt;
                break;
            case 'o':
                ++oCnt;
                break;
            case 'u':
                ++uCnt;
                break;
        }
    }
    cout << "Number of vowel a: \t" << aCnt << '\n'
         << "Number of vowel e: \t" << eCnt << '\n'
         << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n'
         << "Number of vowel u: \t" << uCnt << endl;
}


void flowcontrol()
{
    unsigned int vowelcounter = 0;
    char ch;

    while (cin >> ch) {
        switch(ch) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            /* alternative way to write this

            case 'a' : case 'e' : case 'i' : case 'o' : case 'u':
                ++vowelcounter;
                break;
                
            */
                ++vowelcounter;
                break;
        }
    }

    cout << "Total vowels detected:\t" << vowelcounter <<endl;
}

void defaultstatement()
{
    unsigned int vowelCnt = 0, otherCnt = 0;
    char ch;

    while (cin >> ch) {
        switch(ch) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ++vowelCnt;
                break;
            default:
                ++otherCnt;
                break;
        }
    }

    cout << "Vowels: " << vowelCnt << "\nConsonants & Spaces: " << otherCnt <<endl;
}

void variabledefsinswitchstatements()
{
    /*

    case true:
        {
            // okay: declaration statement within a statement block;
            string file_name = get_file_name();
        }
    case false:
        {
            // error: file_name not in scope;
            if (file_name.empty())

        }
    */


}

int main()
{
    //switchstatement();
    //flowcontrol();
    //defaultstatement();
    variabledefsinswitchstatements();

    return 0;
}
