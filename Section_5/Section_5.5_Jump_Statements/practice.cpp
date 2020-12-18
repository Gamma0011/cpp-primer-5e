#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void e520()
{ 
    // write a program to read a sequence of strings from the std::cin 
    //   until the same word occurs twice in succession, or until all words have been read

    // use a while loop to read one word at a time, use a break statement to terminate the loop, if the word occurs 2x in succession
    // print word if it occurs twice in succession or print a message that no word was repeated

    string s, stored;

    while (cin >> s) {
        if (s == stored) {
            break;
        } else {
            stored = s;
        }
    }
    if (cin.eof()) {
        cout << "No words duplicated in succession." <<endl;
    } else {
        cout << "The word '" << stored << "' was typed twice in succession." <<endl;
    }
}

void e521() 
{
    // revise e520 so that it only looks for duplicated words that start with an uppercase letter

    string s, stored;

    while (cin >> s) {
        if (s == stored) {
            break;
        } 
        if (isupper(s[0])) {
            stored = s;
        }
    }
    if (cin.eof()){
        cout << "There were no words typed in succession." <<endl;
    } else {
        cout << "'" << stored << "' was typed twice." <<endl;
    }


}

void e522()
{
    // rewrite the last example in this section as a loop to eliminate goto (pg 192)

    /*
    begin:
        int sz = get_size();
        if (sz <= 0) {
            goto begin;
        }
    */

   /*
    for (int sz = get_size(); sz <= 0; sz = get_size());

    // OR

    int sz = get_size();
    while (sz <= 0) {
        sz = get_size();
    }

    */
}

void e523()
{
    // write a program that reads 2 ints froms std::cin && prints results of dividing first number by second;

    cout << "Please enter two numbers to divide: " <<endl;
    int i1, i2;

    while (cin >> i1 >> i2) {
        if (i2 == 0) {
            throw std::runtime_error("Cannot divide by zero.");
        }
        cout << i1 << " / " << i2 << " = " << i1/i2 <<endl;
    }
}

void e524()
{
    // revise e523 to throw an ex eption if the second number is zero, see what happens if your sustem doesn't catch exception

    // ALREADY DID THIS IN e524

    int x, y;

    cout << "Please enter two numbers to divide: " <<endl;
    while (cin >> x >> y) {
        if (y == 0) {
            throw std::runtime_error("Cannot divide by zero.");
            break;
        }
        cout << x << " divided by " << y << " = " << x/y <<endl;
    }
}

void e525()
{
    // revise previous program to use a try block to catch the exception
    // catch clause should print a message to the user and ask them to supply a new number and repeat the code inside of the try;

    int x, y;

    cout << "Enter two numbers to divide: " <<endl;

    while (cin >> x >> y) {
        try {
            if (y == 0) {
                throw std::runtime_error("ERROR: Cannot divide by zero.");
            } else {
                cout << x << " divided by " << y << " = " << x/y <<endl;
            }
        } catch (std::runtime_error error) {
            cout << error.what() << "\nWould you like to enter another pair of numbers? (y/n)" <<endl;

            char c;
            cin >> c;
            if (!cin || c == 'n') {
                break;
            }
        }
    }


}

int main()
{

    //e520();
    //e521();
    //e523();
    //e524();
    e525();

    return 0;
}
