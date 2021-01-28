#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <memory>
#include <algorithm>

/*  
    e13.44  - Write a class named String that is a simplified version of the library string class. Your class should have
                at least a default constructor and a constructor that takes a pointer to a c-style string.
                Use an allocator to allocate memory for your String class to use.
*/

class String {
public:
    String() : beg(nullptr), lastelement(nullptr), end(nullptr) { };
    String(const char*);

    ~String() { 
        freeMemory(); 
    }

private:
    std::allocator<const char*> alloc;
    const char *beg, *lastelement, *end;

    void freeMemory();
};

String::String(const char *c) {
    std::size_t sz = strlen(c);
    auto cbeg = alloc.allocate(sz);         // allocate sz memory
    auto clastelement = cbeg;

    for (std::size_t i = 0 ; i != sz ; ++i){
        alloc.construct(clastelement++, c[i]);
    }

    beg = *cbeg;
    end = lastelement = *clastelement;
}

void String::freeMemory() {
    if (beg) {
        for_each(beg, end, [](const char *e){alloc.destroy(e); });
    }
    alloc.deallocate(beg, end - beg);
}

int main() 
{

    return 0;
}