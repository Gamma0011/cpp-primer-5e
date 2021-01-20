#include <iostream>
#include <vector>
#include <string>
#include <memory>

/*
    e13.22  - Assume we want HasPtr to behave like a value. That is, each object should have its own copy
                of the string to which the object points. You already know everything you need to know about how to implement this.
                Write HasPtr copy constructor and copy-assignment operator.

                see class HasPtr {};


    e13.23  - Compare the copy-control members that you wrote for solutions to the previous section's exercises to the code here. Be sure you understand the difference.

                class HasPtr copies orig.ps to temp element, frees memory to ps and then copies temp to freed ps before returning *this. This works as expected and is correct.

    e13.24  - What would happen if the version of HasPtr in this section didn't define a destructor? A copy constructor?
                Destructor - the compiler would synthesize one for us, but since we've manually allocated memory with the new statement and no shared_ or unique_ptrs, the compiler
                    will not deal with memory management. Therefore, member ps won't be deleted and the object that ps is a member of won't be deleted either. int i will be deleted.

                Copy Constructor - the compiler will also synthesize this for us. The copy will happen using pointerlike behavior with the pointer being copied to the lefthand-side.
                    No temp object made and old memory freed in synthesized version.

    e13.25  - Assume we want to define a version of StrBlob that acts like a value. Also assume that we want to continue to use a shared_ptr so that our StrBlobPtr class can still use
                a weak_ptr to the vector. The revised class will need a copy constructor and copy-assignment operator but will not need a destructor. Explain what the copy 
                constructor and copy-assignment operators must do. Explain why the class does not need a destructor.

                The copy constructor and copy-assignment operator should dynamically allocate the memory as the object's own.   data = std::make_shared<std::vector<std::string>>(*sb.data); 
                The destructor is not needed because shared_ptr automatically increments or decrements the usage count depending on how many pointers point to the object. Once usage == 0, memory is freed.

                Weak_ptrs have no usage count and so long as the object to which they point exists, they will work. Normal copy constructor will work, and no destructor needed since once their object is 
                 freed, they too no longer exist.

    e13.26  - Write your own version of StrBlob class from e13.25

                see. class StrBlob && class StrBlobPtr

*/

class HasPtr {
public:
    HasPtr(const HasPtr &h) : ps(new std::string(*h.ps)), i(h.i) { };
    HasPtr& operator=(const HasPtr &orig) {
        std::string *temp = new std::string(*orig.ps);
        delete ps;                                      // free ps memory
        ps = temp;
        i = orig.i;
        return *this;
    }
    ~HasPtr() { delete ps; };

    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { };
private:
    std::string *ps;
    int i;
};


class StrBlob {
    friend class StrBlobPtr;
public:
    StrBlob(const StrBlob &sb) : data(std::make_shared<std::vector<std::string>>(*sb.data)) { }; 
    StrBlob& operator=(const StrBlob &sb) {
        data = std::make_shared<std::vector<std::string>>(*sb.data);
        return *this; 
    }

    StrBlob() : data(new std::vector<std::string>) { };
    StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) { };

    std::size_t size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();

    std::string& front();
    std::string& back();

    int usage() { return data.use_count(); }
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(std::size_t i, const std::string &msg) const;
};

class StrBlobPtr {
public:
    StrBlobPtr(const StrBlobPtr &sbp) : wptr(sbp.wptr), curr(sbp.curr) { };
    StrBlobPtr& operator=(const StrBlobPtr &sbp) {  
        wptr = std::weak_ptr<std::vector<std::string>>(sbp.wptr);
        curr = sbp.curr;
        return *this;
    };

    StrBlobPtr() : curr(0) { };
    StrBlobPtr(StrBlob &a, std::size_t sz = 0) :
        wptr(a.data), curr(sz) { };
    std::string& deref() const;
    StrBlobPtr& incr();

    int usage() { return wptr.use_count(); }
private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};


int main()
{
    return 0;
}