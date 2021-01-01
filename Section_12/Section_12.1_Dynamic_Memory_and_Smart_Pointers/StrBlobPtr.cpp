#include <iostream>
#include <initializer_list>
#include <vector>
#include <string>
#include <memory>

/*
    class StrBlobPtr will store a weak_ptr to the data member of the StrBlob from which it was initialized. By using
     weak_ptr, we don't affect the lifetime of the vector to which a given StrBlob points. However, we can prevent the
     user from attempting to access a vector that no longer exists.

    StrBlobPtr will have two data members; wptr, which is either NULL or points to a vector in StrBlob, and CURR, which
     is the index of the element that this object currently denotes.

*/
class StrBlobPtr;

class StrBlob {
public:
    friend class StrBlobPtr;
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();      // default constructor
    StrBlob(std::initializer_list<std::string> il);
    size_type size() { return data->size(); }
    bool empty() const { return data-> empty(); }
    // add and remove elements
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
    // element access
    std::string &front();
    std::string &back();
    StrBlobPtr begin();
    StrBlobPtr end();
private:
    std::shared_ptr<std::vector<std::string>> data;
    // throws msg if data[i] invalid
    void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) { };
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) { };

void StrBlob::check(size_type i, const std::string &msg) const { 
    if (i >= data->size()) { throw std::out_of_range(msg); } 
}

std::string &StrBlob::front() {
    // if vector empty, check will throw
    check(0, "Called front on empty StrBlob.");
    return data->front();
}

std::string &StrBlob::back() {
    check(0, "Called back on empty StrBlob.");
    return data->back();
}

void StrBlob::pop_back() {
    check(0, "Called pop_back on empty StrBlob.");
    data->pop_back();
}


// StrBlobPtr throws exception on attempts to access a nonexistent element.
class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) { };                 // default constructor generates a null StrBlobPtr
    StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) { };
    std::string& deref() const;
    StrBlobPtr& incr();         // prefix version
private:
    // check returns a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
    // store weak_ptr, which means underlying vector might be destroyed
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();                                             // is the vector still around?
    if(!ret) { throw std::runtime_error("Unbound StrBlobPtr"); }        // if null
    if(i >= ret->size()) { throw std::out_of_range(msg); }              
    return ret;                                             // return shared_ptr to vector
}

std::string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];      //  (*p) is the vector to which the object points
}

StrBlobPtr& StrBlobPtr::incr() {        // prefix: return a reference to the incremented object
    // if curr already points past the end of the container, cannot increment
    check(curr, "Increment past end of StrBlobPtr.");
    ++curr;         // advance current state
    return *this;
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

int main()
{
    return 0;
}