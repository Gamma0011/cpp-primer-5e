#include <iostream>
#include <vector>
#include <sstream>
#include <string>

/*
    e89 - use the function you werote for the first exercise in 8.1.2 to print contents of an istringstream object

    e810 - now, write a program to store each line from a file in a vector<string>. 
           use istringstream to reach each element from the vector a word at a time.

*/

// e89
std::istream &read(std::istream &is) {
    std::string buff;
    while (is >> buff) {
        std::cout << buff <<std::endl;
    }
    is.clear();
    return is;
}

int main()
{
    // e89
    std::istringstream in("hello world! how's your day?");
    read(in);

    return 0;
}