#ifndef STRVEC_CLASS
#define STRVEC_CLASS

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

class StrVec {
    friend bool operator==(const StrVec&, const StrVec&);
    friend bool operator!=(const StrVec&, const StrVec&);
    friend bool operator<(const StrVec&, const StrVec&);
    friend bool operator>(const StrVec&, const StrVec&);
public:
    std::size_t size() { return cap - beg; }                        // total memory allocated
    std::size_t capacity() { return cap - lelem; }                  // space remaining
    std::size_t reserve(std::size_t sz) { return (sz ? size() * 2 : 1); }     // reserve 2x current size for reallocation
    auto resize(std::size_t sz) { return alloc.allocate(sz); }      // return pointer to newly created block of raw data
    std::string *begin() const { return beg; }
    std::string *end() const { return lelem; }

    StrVec() : beg(nullptr), lelem(nullptr), cap(nullptr) { };  // default constructor
    StrVec(std::initializer_list<std::string> il) {
        reallocate();
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
    StrVec(StrVec &&) noexcept;         // move constructor
    StrVec& operator=(StrVec &&) noexcept;  // move-assignment operator
    ~StrVec();                          // destructor

    StrVec& operator=(std::initializer_list<std::string>);

    // push_back copy version
    void push_back(const std::string&);
    // push_back move version
    void push_back(std::string&&);

private:
    static std::allocator<std::string> alloc;       // used to allocate a block of strings
    std::string *beg;       // points to first element of array
    std::string *lelem;     // points to last element of array
    std::string *cap;       // points to one past last element of array

    void check_n_allocate();
    void reallocate();      // reallocate current strings to new block of memory
    void free();            // free old memory
    std::pair<std::string*, std::string*> alloc_n_copy
        (const std::string*, const std::string*);
};

// alloc must be defined in the StrVec implementation file
std::allocator<std::string> StrVec::alloc;

/***************** StrVec ASSIGNMENT OPERATOR *****************/

StrVec&
StrVec::operator=(std::initializer_list<std::string> il) {
    auto data = alloc_n_copy(il.begin(), il.end());         // create a set .first == beg, .second == end
    free();                                                 // free memory used by StrVec&
    beg = data.first;
    lelem = cap = data.second;
    return *this;
}

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
/***************** StrVec MOVE CONTROL *****************/

StrVec::StrVec(StrVec &&s) noexcept : beg(std::move(s.beg)), 
                                      lelem(std::move(s.lelem)),
                                      cap(std::move(s.cap)) {
    s.beg = s.lelem = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept {
    if (this != &rhs) {
        free();             
        beg = std::move(rhs.beg);
        lelem = std::move(rhs.lelem);
        cap = std::move(rhs.cap);
        rhs.beg = rhs.lelem = rhs.cap = nullptr;        // remove pointers to rhs, making it okay to delete
    }
    return *this;
}

/***************** StrVec DESTRUCTOR *****************/

StrVec::~StrVec() {
    free();
}

/***************** StrVec PUBLIC MEMBER FUNCTIONS *****************/

// push_back copy version
void StrVec::push_back(const std::string &s) {
    check_n_allocate();                 // check there is space, if none, function calls reallocate();
    alloc.construct(lelem++, s);        // at lelem, insert s
}

// push_back move version
void StrVec::push_back(std::string &&s) {
    check_n_allocate();
    alloc.construct(lelem++, std::move(s));
}

/***************** StrVec PRIVATE MEMBER FUNCTIONS *****************/
void StrVec::check_n_allocate() {
    if (size() == capacity()) { 
        reallocate();
    }
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto first = alloc.allocate(newcapacity);
    auto last = std::uninitialized_copy(std::make_move_iterator(begin()),
                                        std::make_move_iterator(end()),
                                        first);
    free();
    beg = first;                // first element of string array
    lelem = last;               // final element when for loop ended
    cap = beg + newcapacity;    // beg element + size of elements allocated
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



#endif