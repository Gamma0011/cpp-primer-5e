#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>

/*
    e11.14  - Extend the map of children to their family name that you wrote for exercises in 11.2.1 by having
              the vector store a pair that holds the child's name and birthday.

    Format
        Last name ->    Child 1         -> Birthday
                        Child 2, etc    -> Birthday

    std::map<std::string 1, std::vector<std::pair<std::string 2, std::string 3>>>

            string 1 = last name
            string 2 = first name       ** Str2 && Str3 are pairs stored as elements in vector.
            string 3 = birthday             
*/

void printMap(const std::map<std::string, std::vector<std::pair<std::string, std::string>>> &m) {
    for (auto &f : m) {                 // access last name from map (std::string)
        for (auto &s : f.second) {      // access first name - birthday pairs within vector
            std::cout << "First Name: " << s.first 
                      << " | Last Name: " << f.first 
                      << " | Birthday: " << s.second <<std::endl;
        }
    }
}

int main()
{
    std::map<std::string, std::vector<std::pair<std::string, std::string>>> nmap;   // map to hold data
    std::string ln, fn, bd;         // strings to store last name, first name, birthday

    std::cout << "Please enter last name, first name, and birthday. Type @q to finish." <<std::endl;
    for ( ; std::cout << "Last Name: ", std::cin >> ln  && ln != "@q"; ) {  // type @q to quit
        for ( ; std::cout << "First Name: ", std::cin >> fn ; ) {
            for ( ; std::cout << "Birthday: ", std::cin >> bd ; ) {
                nmap[ln].emplace_back(fn, bd);              // enter data into nmap
                break;                                      // end birthday loop
            }
            break;                                          // end first name loop, return to last name loop
        }
    }

    printMap(nmap);             // once data has finished being entered, print the entered data

    return 0;
}