#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>

#include "findbooks.h"

/*
    e17.1   - Define a tuple that holds three int values and initializes the members to 10, 20, and 30.

    e17.2   - Define a tuple that holds a string, vector<string> and pair<string, int>

    e17.3   - Rewrite the TextQuery program from 12.3 to use a tuple instead of the QueryResult class. 
                Which design is better? Why?

                The tuple is much easier to read and condensed. Rather than having to create three separate classes
                 to handle the operations, we were able to consolidate it down to one.

    e17.4   - Write and test your own version of findBooks() function.

*/

void e171() {
    std::tuple<int, int, int> threeInts = {10,20,30};
    std::cout << std::get<0>(threeInts) << '\t'
              << std::get<1>(threeInts) << '\t'
              << std::get<2>(threeInts) << std::endl;  
}

void e172() {
    std::tuple<std::string, std::vector<std::string>, std::pair<std::string, int>> t;
}

int main(int argc, char **argv)
{
    //e171();

    if(argc < 2) {
        std::cerr << "Files provided: " << *argv << ". Must have at least 2 files to compare" << std::endl;
        return -1;
    }
    std::vector<std::vector<Sales_data>> sales;

    while (--argc > 0) {
        std::ifstream in(*++argv);
        if (!in) {
            std::cerr << "ERROR: Cannot open " << *argv << std::endl;
            return -1;
        }
        sales.emplace_back(build_vectors(in));
    }
    reportResults(std::cin, std::cout, sales);
    return 0;
}