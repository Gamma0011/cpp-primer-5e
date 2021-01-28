#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <utility>
#include <memory>
#include <new>
#include <map>
#include <set>

// e13.42  - Test your StrVec class by using it in place of the vector<string> in your TextQuery and QueryResults classes.

class QueryResult;

class StrVec {
public:
    std::size_t size() { return cap - beg; }                        // total memory allocated
    std::size_t capacity() { return cap - lelem; }                  // space remaining
    std::size_t reserve(std::size_t sz) { return (sz ? size() * 2 : 1); }     // reserve 2x current size for reallocation
    auto resize(std::size_t sz) { return alloc.allocate(sz); }      // return pointer to newly created block of raw data
    std::string *begin() const { return beg; }
    std::string *end() const { return lelem; }

    StrVec() : beg(nullptr), lelem(nullptr), cap(nullptr) { };  // default constructor
    StrVec(std::initializer_list<std::string> il) {
        reallocate(il.size());
        /*
        auto ns = resize(il.size());
        auto el(ns);                    // el will be used to increment
        */

        for (auto s : il) { alloc.construct(beg++, s); }     // at position el, insert s
        // at end of iteration through initializer_list, el == end
        //beg = ns;           // ns denotes start of new strings
        //lelem = cap = el;   // el denotes last element and cap of new strings
    }

    StrVec(const StrVec &);             // copy constructor
    StrVec& operator=(const StrVec &);  // copy-assignment operator
    ~StrVec();                          // destructor

    void push_back(const std::string&);

private:
    static std::allocator<std::string> alloc;       // used to allocate a block of strings
    std::string *beg;       // points to first element of array
    std::string *lelem;     // points to last element of array
    std::string *cap;       // points to one past last element of array

    void check_n_allocate();
    void reallocate(std::size_t);      // reallocate current strings to new block of memory
    void free();            // free old memory
    std::pair<std::string*, std::string*> alloc_n_copy
        (const std::string*, const std::string*);
};

// alloc must be defined in the StrVec implementation file
std::allocator<std::string> StrVec::alloc;

/***************** StrVec COPY CONTROL *****************/

StrVec::StrVec(const StrVec &s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    beg = newdata.first;
    lelem = cap = newdata.second;
}

StrVec& StrVec::operator=(const StrVec &s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    free();
    beg = newdata.first;
    lelem = cap = newdata.second;
    return *this;
}

StrVec::~StrVec() {
    free();
}

/***************** StrVec PUBLIC MEMBER FUNCTIONS *****************/
void StrVec::push_back(const std::string &s) {
    check_n_allocate();                 // check there is space, if none, function calls reallocate();
    alloc.construct(lelem++, s);        // at lelem, insert s
}

/***************** StrVec PRIVATE MEMBER FUNCTIONS *****************/
void StrVec::check_n_allocate() {
    if (size() == capacity()) { 
        reallocate(size());
    }
}

void StrVec::reallocate(std::size_t sz) {
    auto newblock = (sz) ? sz : (size()) ? 2 * size() : 1;
    auto newdata = alloc.allocate(newblock);
    auto dest = newdata;
    auto elem = beg;

    for (auto i = 0; i != size() ; ++i) {
        alloc.construct(++dest, std::move(*elem++));
    }
    free();

    beg = newdata;         // first element of string array
    lelem = dest;           // final element when for loop ended
    cap = beg + newblock;         // beg element + size of elements allocated

}

void StrVec::free() {
    if (beg) {
        for ( auto e = lelem; e != beg; ) {
            alloc.destroy(--e);
        }
    alloc.deallocate(beg, cap - beg);
    }
}

std::pair<std::string*, std::string*> 
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    auto dest = alloc.allocate(e-b);
    return {dest, std::uninitialized_copy(b, e, dest)};
}

// function prototyping
std::string make_plural(std::size_t, const std::string &, const std::string &);

class TextQuery {
public:
    TextQuery(std::ifstream &ifs) : svec(new StrVec) {
        for (std::string line ; std::getline(ifs, line) ; svec->push_back(line)) {
            /*
            std::string word;
            std::vector<std::string>::size_type n = svec->size();
            for(std::istringstream read(line) ; read >> word ; ) { 
                auto &lines = smap[word];
                if (!lines) {
                    lines.reset(new std::set<std::vector<std::string>::size_type>);
                } 
                lines->insert(n);
            }
            */
        }
    }
    QueryResult query(const std::string &) const;
private:
    //StrVec sv;
    std::shared_ptr<StrVec> svec;
    std::map<std::string, std::shared_ptr<std::set<std::vector<std::string>::size_type>>> smap;
};

class QueryResult {
    friend std::ostream &print(std::ostream &, const QueryResult &);
public:
    QueryResult(const std::string &w,
                std::shared_ptr<StrVec> v,
                std::shared_ptr<std::set<std::vector<std::string>::size_type>> s) :
                word(w), qrvec(v), qrs(s) { };
private:
    std::string word;
    std::shared_ptr<StrVec> qrvec;
    std::shared_ptr<std::set<std::vector<std::string>::size_type>> qrs;
};

QueryResult TextQuery::query(const std::string &s) const {
    std::shared_ptr<std::set<std::vector<std::string>::size_type>> defaultSet(new std::set<std::vector<std::string>::size_type>);
    auto lookup = smap.find(s);
    if (lookup == smap.end()) { 
        return QueryResult(s, svec, defaultSet);
    } else {
        return QueryResult(s, svec, lookup->second);
    }
}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
    os << qr.word << " occurs " << qr.qrs->size() << make_plural(qr.qrs->size(), " time", "s");
    for (auto &line : *qr.qrs) {
        os << "\nline " << line + 1 << " : "
           << *(qr.qrvec->begin() + line) << std::endl;
    }

    return os;
};

std::string make_plural(std::size_t sz, const std::string &w, const std::string &p) {
    return (sz > 1 ? (w + p) : w);
}

void runQueries(std::ifstream &inFile) {
    TextQuery tq(inFile);
    while(true) {
        std::cout << "Enter a word to look for, or q to quit: ";
        std::string s;
        if(!(std::cin >> s) || s == "q") {
            break;
        } else {
            print(std::cout, tq.query(s)) <<std::endl;
        }
    }
}


int main()
{
    std::ifstream open("test.txt");;
    runQueries(open);


    return 0;
}