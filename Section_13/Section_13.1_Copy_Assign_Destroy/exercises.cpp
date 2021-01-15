#include <iostream>
#include <vector>
#include <string>
#include <memory>

/*
    e13.1   - What is a copy constructor, when is it used?
                A copy constructor is either a compiler-created or explicitly written constructor that deals with copying objects
                of class type. It is used when we want to define how to copy members of one object of a class to another object of the same class

    e13.2   - Explain why the following declaration is illegal.
                Sales_data::Sales_data(Sales_data rhs);
                
                Copy constructors must be of reference type, and typically are declared const. Failing to do so can cause an infinite loop or error by compiler.
                Sales_data::Sales_data(const Sales_Data &rhs);

    e13.3   - What happens when we copy a StrBlob? What about a StrBlobPtr?
                StrBlob - The new object of class StrBlob shares ownership of data's assets and increases the use count. 
                            https://www.cplusplus.com/reference/memory/shared_ptr/shared_ptr/
                StrBlobPtr - wptr use_count doesn't change. If an argument x is passed, and x is not empty, the weak_ptr object becomes part 
                        of the owning group of x, giving access to that object's assets until expired without taking ownership itself (and without increasing its use count).
                            http://www.cplusplus.com/reference/memory/weak_ptr/weak_ptr/
    
    e13.4   - Assuming Point is a class type with a public copy constructor, identify each use of the copy constructor in this program fragment.    
                    Point global;
                    Point foo_bar(Point arg) {                              
                        Point local = arg, *heap = new Point(global);       // arg is copied to local, *heap is a dynamically allocated pointer to object global.
                        Point pa[4] = { local, *heap };                     // pa[0] copy initialized by local, pa[1] copy initialized by *heap
                        return *heap;    
                    }

    e13.5   - Given the following sketch of a class, write a copy constructor that copies all the members. Your constructor should dynamically allow a new string
                and copy the object to which ps points, rather than copying ps itself.

                    class HasPtr {
                    public:
                        HasPtr(const std::string &s = std::string()) :
                            ps(new std::string(s), i(0)) { };
                    private:
                        std::string *ps;
                        int i;
                    }

                Copy Initializer:    HasPtr(const HasPtr &h) : ps(new std::string(*h.ps)), i(h.i) { };
    
    e13.6   - What is a copy-assignment operator? When is the operator used? What does the synthesized copy-assignment operator do? When is it synthesized?
                Copy-assignment operator - controls how objects of the class as assigned. Denoted by returning a reference to the class and using operator= function
                Operator is used

*/

class HasPtr {
public:
    HasPtr(const HasPtr &h) : ps(new std::string(*h.ps)), i(h.i) { };
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { };
private:
    std::string *ps;
    int i;

};


class StrBlob {
    friend class StrBlobPtr;
public:
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

void e133() {
    StrBlob sb1;
    std::cout << "Before: " << sb1.usage() <<std::endl;
    StrBlob sb2(sb1);
    std::cout << "After: " << sb1.usage() <<std::endl;

    StrBlobPtr sbp1(sb1);
    std::cout << "Before: " << sbp1.usage() <<std::endl;
    StrBlobPtr sbp2(sb1);
    std::cout << "Before: " << sbp1.usage() <<std::endl;
}


int main()
{
    e133();

    HasPtr t1(std::string("Hello World"));
    HasPtr t2(t1);

    return 0;
}