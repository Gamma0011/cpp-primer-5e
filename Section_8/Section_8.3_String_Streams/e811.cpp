#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

/*  e811
    what changes do you need to make if record were defined outside this loop?
    rewrite the program, moving the definition of record outside the while. and see whether you thought of all the changes involved

    e812
    why didn't we use in-class initializers in struct PersonInfo?
    a - specifically initializing vector<string> phones could have limited the number of entries allowed.
        this is an aggregate class (public-only) and shouldn't have in-class initializers


*/

struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};

int main()
{
    std::string line, word;
    std::vector<PersonInfo> people;
    std::istringstream record;

    while(getline(std::cin, line)) {
        PersonInfo info;
        record.clear();                   // clear state
        record.str(line);                 // read string (line) into read istringstream function
        record >> info.name;
        while (record >> word) {
            info.phones.push_back(word);
        }
        people.push_back(info);             // append record to people;
    }

    for(auto &p : people) {
        std::cout << p.name <<std::endl;
        for(auto &num : p.phones) {
            std::cout << "Phone Numbers: " << num <<std::endl;
        }

    }

    return 0;
}