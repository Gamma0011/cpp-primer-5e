#include <iostream>
#include <vector>


// using an istringstream       -- people.txt is our test file
struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};

int main()
{
    std::string line, word;                     // will hold a line and word from input
    std::vector<PersonInfo> people;             // will hold all the records from the input accepts objects of class PersonInfo

    // read the input a line at a time until cin hits end-of-file (or another error)
    while(getline(cin, line)) {
        PersonInfo info;                    // create an object to hold record's data
        std::istringstream record(line);    // bind record to the line we just read
        record >> info.name;                // read the name
        while (record >> word) {            // read the phone numbers
            info.phones.push_back(word);    // and store them
        }
        people.push_back(info);             // append this record to people
    }   

    /* using an ostringstream
   ostringstream is useful when we want to build up our output a little at a time, but do not want to print the output until later

   for example, we might want to validate and reformat the phone numbers we read. if all numbers are valid, we want to print a new file containing the
   formatted numbers. if a person has invalid numbers, we wont put them in the file. instead, we'll write an error message containing the 
   person's name and a list of their invalid number

   because we dont want to include any data for a person with an invalid number, 
   we cannot produce the output until we've seen and validated all their numbers.
   we can however, "write" the output to an in-memory ostringstream
    */
    for(const auto &entry : people) {           // for each entry in people
        std::ostringstream formatted, badNums;  // objects created on each loop
        for(const auto &nums : entry.phones) {  // for each number
            if (!valid(nums)){
                badNums << " " << nums;         // string in badNums
            } else {
                // "writes" to foramtted's string
                formatted << " " << format(nums);
            }
        }
        if (badNums.str().empty()) {            // if there were no bad numbers
            os << entry.name << " "             // print the name
               << formatted.str() <<std::endl;  // and reformatted numbers
        } else {                                // otherwise print the name and bad numbers
            std::cerr << "input error: " << entry.name
                      << "invalid numbers: " << badNum.str() <<std::endl;
        }
    }


    return 0;
}