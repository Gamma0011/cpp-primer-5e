#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <new>
#include <map>
#include <set>

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
    std::set<TextQuery::line_no>::iterator begin() const { return lines->begin(); }
    std::set<TextQuery::line_no>::iterator end() const { return lines->end(); }
    std::shared_ptr<std::vector<std::string>> get_file() const { return file; }
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

#endif