#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

/*  e813
    rewrite the phone number program from this section to read from a named file rather than cin

    e814
    why did we declare entry and nums as const auto &
    a - references are more effective since we don't need to copy the data, only reference it
        const is important because we don't want to make any changes to the values referenced
*/

struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};

int main(int argi, char **fileInput)
{   
    std::string line, word;
    std::vector<std::string> people;
    while(getline(fileInput[1], line)) {
        PersonInfo info;
        std::istringstream record(info);
        record >> word;
        while (record >> word) {
            info.phones.push_back(word);
        }
        people.push_back(info);         // append this record to people
    }

    for (const auto &entry : people) {
        std::ostringstream formatted, badNums;
        for (const auto &nums : entry.phones) {
            if (!valid(nums)) {
                badNums << " " << nums;
            } else {
                // writes to formatted's string
                formatted << " " << format(nums);
            }
        }
    }
    if (badNums.str().empty()) {
        os << entry.name << " "
           << formatted.str() <<std::endl;
    } else {
        std::cerr << "input error: " << entry.name
                  << "invalid number(s)" << badNums.str() <<std::endl;
    }


    return 0;
}