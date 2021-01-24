#include <iostream>
#include <vector>
#include <string>
#include <utility>

/*
    || CLASSES THAT MANAGE DYNAMIC MEMORY ||
        Some classes need to allocate a varying amount of storage at run time. Those classes should use
         a library containe (such as a vector) to manage storage of elements.
        
        However, this won't work for every class and some might have to do their own allocation. These classes
         will have to define their own copy-control members to manage the memory they allocate.

        For our StrVec class, we'll use an allocator to obtain raw memory. Since allocator allocates unconstructed memory,
         we'll use the allocator's construct member to create objects in the space when we need to add an element. When we
         remove an element, we'll use the destroy member.

                Each StrBev will have 3 pointers into the space it uses for its elements:
                    - elements, which points to the first element in allocated memory
                    - first_free, which points to just after the last element.
                    - cap, which points just past the end of the allocated memory.
                
                Additional members:
                    - alloc, static data member of type allocator<string>
                    - alloc_n_copy, allocate space and copy given range of elements
                    - free, destroy constructed elements and deallocate space
                    - chk_n_alloc, ensure there is room to add at least 1 element to StrVec. Will call reallocate if not
                    - reallocate, reallocate StrVec when it runs out of space

            The class body defines several members:
                - Default constructor implicitly initializes alloc and explicitly initializes pointers to nullptr
                - Size member returns # elements in use. 
                - Capacity returns total # elements StrVec can hold
                - chk_n_alloc causes reallocation when cap == first_free
                - begin and end return pointers to first and one past last element

        **NOTE** calling .construct on an std::allocator<type> will require two arguments (arg 1 = pointer to position, arg 2 = element to insert)

            Constructing the reallocate member:
                - Allocate memory for a new, larger array of string
                - Construct the first part of that space to hold existing elements
                - Destroy the elements in existing memory and deallocate memory
            
                Our performance will be much better if we don't copy the data from the existing memory to new memory - avoids 
                 overhead of allocating and deallocating strings themselves each time we reallocate
                
        || MOVE CONSTRUCTORS AND STD::MOVE ||
            Several library classes, including string define "move constructors". These operate by "moving" resources 
             from the given object, to the object being constructed. The move constructor guarantees the "moved-from"
             string remains in a valid, destructable state. Presumably, the move constructor copies the pointer to each string
             rather than allocating space for copy the strings themselves.

            std::move is defined in the <utility> header. If we omit the std::move signal, the copy constructor is used. 
            Unlike std::swap, we do not declare a using declaration.

                see reallocate();       uses move
            


*/

// Simplified implementation of the memory allocation strategy for a vector-like class
class StrVec {
public:
    StrVec();                               // the allocator member is default initialized
    StrVec(const StrVec&);                  // copy constructor
    StrVec& operator=(const StrVec&);       // copy-assignment operator
    ~StrVec();                              // destructor

    void push_back(const std::string&);     // copy elements
    
    std::size_t size() const { return first_free - elements; }
    std::size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }

private:
    static std::allocator<std::string> alloc;   // allocates the elements
    void chk_n_alloc() {
        if (size() == capacity()) { 
            realloc; }
    }
    // utilities used by copy constructor, assignment operator, and destructor
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);

    void free();            // destroy elements and free space
    void reallocate();      // get more space and copy existing elements
    std::string *elements;  // pointer to first element of array
    std::string *first_free;// pointer to first free element of array
    std::string *cap;       // pointer to one past end of array
};

/***************** StrVec COPY-CONTROL MEMBERS *****************/
StrVec::StrVec(const StrVec &s) {
    // call alloc_n_copy to allocate exactly as many elements as in s
    auto newdata = alloc_n_copy(s.begin(), s.end());            // alloc_n_copy returns pair<iterator begin, iterator end>
    elements = newdata.first;                                   // elements of StrVec object assigned iterator begin
    first_free = cap = newdata.second;                          // first_free && cap assigned iterator end
}

StrVec& StrVec::operator=(const StrVec &rhs) {
    // call alloc_n_copy to allocate exactly as many elements in rhs
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec::~StrVec() { free(); }

/***************** StrVec MEMBER FUNCTIONS *****************/
void StrVec::push_back(const std::string &s) {
    chk_n_alloc();                      // ensure that there is room for another element
    alloc.construct(first_free++, s);   // construct a copy of s in the element to which first_free points, increment pointer position postfix
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    // allocate space to hold as many elements as are in range
    auto data = alloc.allocate(e - b);

    // initialize and return a pair constructed from data and the value returned by uninitialized_copy
    return {data, std::uninitialized_copy(b, e, data)};     // return 1- pointer to initial element of block storage
                                                            // return 2- iterator one past last element of the block storage where elements have been copied
}

void StrVec::free() {
    // may not pass deallocator a 0 pointer; if elements is 0, no work to do
    if (elements) {                                                 // check that elements is not nullptr
        for (auto p = first_free; p != elements; /* empty */) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate() {
    // we'll allocate space for twice as many elements as the current size
    auto newcapacity = size() ? 2 * size() : 1;             // determine size of array. if size == 0, return 1
    auto newdata = alloc.allocate(newcapacity);             // allocate block new memory == newcapacity

    // move the data from the old memory to new
    auto dest = newdata;                        // points to the next free position in the new array ( presumably newdata.begin())
    auto elem = elements;                       // points to the next element in old array ( first element of old block raw memory )
    
    for (std::size_t i = 0; i != size(); ++i) {
        alloc.construct(++dest, std::move(*elem++));    // at position dest, move value at position elem, increment positions of both, continue until i == size old block memory
    }                                                   // calling std::move will transfer ownership of strings from elem to dest
    free();                                             // deallocate old memory

    // update our data structure to point to new elements
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;       
}

int main()
{


    return 0;
}