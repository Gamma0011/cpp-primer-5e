#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <sstream>

/*
    e12.29  - We could have written the loop to manage the interaction with the user as a do while loop.
                Rewrite the loop to use a do while. Explain which version you prefer.

                At first, I didn't like the do while statement, but the more I thought about it, the more I liked it. Rather
                than requiring a true and break statement, using do while allows us to incorporate our original if statement
                directly into the loop to return the bool value required to continue the loop or break
*/

class TextQuery {
public:
    TextQuery(std::ifstream &ifs) { };
    TextQuery query(const std::string &s);
private:
};
class ResultsQuery;

std::ostream &print(std::ostream &os, const TextQuery &t) {
    return os;
}

void runQueries(std::ifstream &inFile) {
    TextQuery tq(inFile);
    std::string s;
    do {
        std::cout << "Enter word to look for, or q to quit: ";
        std::cin >> s;
        print(std::cout, tq.query(s)) <<std::endl;
    } while ((std::cin >> s) && (s != "q"));
}

int main()
{



    return 0;
}