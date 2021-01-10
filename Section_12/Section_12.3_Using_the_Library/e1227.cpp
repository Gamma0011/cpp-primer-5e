#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <new>
#include <map>
#include <set>


/*
    | DESIGN OF THE QUERY PROGRAM |
        A good way to start the design of a program is to list the program's operations. Knowing what operations we need can help us see what data structures we'll need.
         Our tasks for the text-query program:
            - When it reads the input, the program must remember the line(s) in which each word appears. The program will need to read the input a line at a time
                and break up the lines from the input into separate words
            - When it generators the output:
                - The program must be able to fetch the line numbers associated with the given word.
                - The line numbers must appear in ascending order with no duplicates
                - The program must be able to print the text appearing in the input file at a given line number.
            
            - These requirements can be met neatly by using various library facilities:
                - Vector<string> to store a copy of input file. Each line in the input file will be an element in the vector.
                    When we want to print a line, we can fetch the line using its line number as an index.
                - istringstream to break each line into words
                - set to hold line numbers on which each word in the input appears. Using set guarantees that each line will appear only
                    once and that the line numbers will be stored in ascending order
                - We'll use a map to associate each word with the set of line numbers on which the word appears. Using a map will let us fetch the
                    set for any given word.
                - Shared_ptrs will also be used.


    e12.27  - the TextQuery and QueryResult classes only use capabilities that we have already covered. Without looking ahead, write your own versions of these classes.
*/

class QueryResult;

class TextQuery {
public:
    friend class QueryResult;
    TextQuery(std::ifstream &ifs) {
        int lineNo = 0;                                                                     
        for (std::string line, word ; std::getline(ifs, line) ; svec->push_back(line)) {    // write lines into svec
            for (std::istringstream iss(line); iss >> word ;  ) {
                smap[word]->insert(lineNo);                                                 // read words from line into smap, note line number
            }
            ++lineNo;                                                                       // increment line counter
        };
    };
    QueryResult query(const std::string &) const { };
private:
    std::shared_ptr<std::vector<std::string>> svec;
    std::map<std::string, std::shared_ptr<std::set<int>>> smap;
};

class QueryResult {
public:
    friend std::ostream &print(std::ostream &, const QueryResult &);
    QueryResult(std::string s, std::shared_ptr<std::vector<std::string>> v, std::shared_ptr<std::set<int>> i) : searchedWord(s), qrVec(v), qrSet(i) { };
private:
    std::string searchedWord;
    std::shared_ptr<std::vector<std::string>> qrVec;
    std::shared_ptr<std::set<int>> qrSet;

};

QueryResult TextQuery::query(const std::string &search) const {
    std::shared_ptr<std::set<int>> defaultSet;
    auto lookFor = smap.find(search);
    if (lookFor == smap.end()) { return QueryResult(search, svec, defaultSet); }        // return search word, vector, and default-initialized set
    else { return QueryResult(search, svec, lookFor->second); }                         // return search word, vector, and set of lineNos
}; 

void runQueries(std::ifstream &infile) {
    TextQuery tq(infile);
    while (true) {
        std::cout << "Enter a word to look for, or type q to quit: ";
        std::string s;
        if (!(std::cin >> s) || (s == "q")) { break; }
        print(std::cout, tq.query(s)) <<std::endl;
    }
}

std::ostream &print(std::ostream &os, const QueryResult &q) {
    os << q.searchedWord << " occurs " << q.qrSet->size() << (q.qrSet->size() > 1 ? " times.\n" : " time.\n");
    for (auto i : *q.qrSet) {
        os << "Line " << (i+1) << q.qrVec->at(i) << std::endl;
    }
    return os;
}


int main()
{


    return 0;
}