#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;
using std::ofstream;

/*
    e81 - write a function that takes and returns an istream&. The function should read the stream until it hits end-of-file
          The function should print what it reads to the std::cout. Reset the stream so it is valid before returning the stream.

    e82 - test your function by calling it, passing cin as an arg

    e83 - what causes the following while to terminate?
            while (cin >> i)

        CMD+D to terminate the program, or the wrong type of input being read into i (char input when i is of type int)
*/

istream &read(istream &is) {
    int buff;
    while (is >> buff) {
        std::cout << buff <<endl;
    }
    is.clear();
    return is;
}

int main()
{
    read(cin);

    return 0;
}
