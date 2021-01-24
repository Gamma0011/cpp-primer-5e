#include <iostream>
#include <vector>
#include <string>
#include <utility>

/*
    e13.39  - write your own version of StrVec, including version of reserve (x), capacity, and resize (x);

*/

class StrVec {
public:
    StrVec() : beg(nullptr), lelem(nullptr), cap(nullptr) { };  // default constructor
    StrVec(const StrVec &);             // copy constructor
    StrVec& operator=(const StrVec &);  // copy-assignment operator
    ~StrVec();                          // destructor

    std::size_t size() { return cap - beg; }                        // total memory allocated
    std::size_t capacity() { return cap - lelem; }                  // space remaining
    std::size_t reserve() { return (size() ? size() * 2 : 1); }     // reserve 2x current size for reallocation
    auto resize(std::size_t sz) { return alloc.allocate(sz); }      // return pointer to newly created block of raw data
    std::string *begin() const { return beg; }
    std::string *end() const { return lelem; }

    void push_back(const std::string&);

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
        reallocate();
    }
}
void StrVec::reallocate() {
    auto sz = reserve();
    auto newblock = resize(sz);

    auto dest = newblock;
    auto source = beg;

    for (auto i = 0; i != size() ; ++i) {
        alloc.construct(++dest, std::move(*source++));
    }
    free();

    beg = newblock;         // first element of string array
    lelem = dest;           // final element when for loop ended
    cap = beg + sz;         // beg element + size of elements allocated

}

void StrVec::free() {
    if (beg) {
        for ( auto e = lelem; e != beg; ) {
            alloc.destroy(--e);
        }
    }
    alloc.deallocate(beg, cap - beg);
}

std::pair<std::string*, std::string*> 
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    auto dest = alloc.allocate(e-b);
    return {dest, std::uninitialized_copy(b, e, dest)};
}

int main()
{



    return 0;
}