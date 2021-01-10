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

    | DEFINING THE QUERY PROGRAM CLASSES |
        The hardest part about the TextQuery class is untangling the class names. As usual, for code that will go in a header file,
         we use std:: when we use a library name.
*/

class QueryResult;      // declaration needed for return type in the query function
std::string make_plural(std::size_t, const std::string &, const std::string &);         // function prototyping


class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string &) const;
private:
    std::shared_ptr<std::vector<std::string>> file;     // input file
    // map each word to the set of lines in which that word appears
    std::map<std::string, 
             std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult {
friend std::ostream &print(std::ostream &, const QueryResult &);
public:
    QueryResult(std::string s,
                std::shared_ptr<std::set<std::vector<std::string>::size_type>> p,
                std::shared_ptr<std::vector<std::string>> f) :
                sought(s), lines(p), file(f) { };
private:
    std::string sought;                                                     // word this query represents
    std::shared_ptr<std::set<std::vector<std::string>::size_type>> lines;   // line nums it's on
    std::shared_ptr<std::vector<std::string>> file;                         //input file

};

TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>) {
    std::string text;
    while(std::getline(is, text)) {
        file->push_back(text);              // remember this line of text
        int n = file->size() - 1;           // remember current line number
        std::istringstream line(text);      // separate the line into words
        std::string word;
        while(line >> word) {
            // if word isn't already in wm, subscripting adds a new entry
            auto &lines = wm[word];                     // insert or find word within wm. Returns location or null depending. lines is a shared_ptr
            if (!lines) {                               // that pointer is null the first time we see word
                lines.reset(new std::set<line_no>);     // allocate a new set
            }
            lines->insert(n);                           // insert this line number
        }
    }
}

QueryResult TextQuery::query(const std::string &sought) const {
    // we'll return a pointer to a set if we don't find sought
    static std::shared_ptr<std::set<std::vector<std::string>::size_type>> nodata(new std::set<std::vector<std::string>::size_type>);
    // use find and not a subscript to avoid adding words to wm
    auto loc = wm.find(sought);

    if (loc == wm.end()) {
        return QueryResult(sought, nodata, file);               // sought word not found
    } else {
        return QueryResult(sought, loc->second, file);          
    }
}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
    // if the word is found, print the count and all occurrences
    os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") <<std::endl;
    for (auto num : *qr.lines) {
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) <<std::endl;
    }

    return os;
}

std::string make_plural(std::size_t sz, const std::string &w, const std::string &pl) {
    std::string word;
    sz > 1 ? (word = w + pl) : word = w;
    return word;
}   

int main()
{


    return 0;
}