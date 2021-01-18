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
                Operator is used to tell the compiler how objects of the same class should be copied.
                The copy-assignment operator is synthesized when no operator is defined in the code.

    e13.7   - What happens when we assign on StrBlob to another? What about StrBlobPtrs?
                Both will use synthesized constructors since there is no copy-assignment operator defined within the classes.
                The operators will look like this:

                    StrBlob(const Strblob&);                    // copy constructor
                    StrBlob& operator=(StrBlob &orig) {
                        data = orig.data;                       // new data increases the usage count of orig.data
                        return *this;
                    }

                    StrBlobPtr(const StrBlobPtr&);              // copy constructor
                    StrBlobPtr& operator=(StrBlobPtr &orig) {
                        wptr = orig.wptr;                       // copied, but usage count does not increase
                        curr = orig.curr;                       // orig.curr copied to new curr
                        return *this;
                    }

    e13.8   - Write the assignment operator for the HasPtr class from 13.5. As with the copy constructor, your assignment 
                operator should copy the object to which ps points.

                HasPtr& operator=(const HasPtr &orig) {
                    if (this != orig) {
                        std::string *ts = new std::string(*orig.ps);
                        ps = ts;
                        i = orig.i;
                    }
                    return *this;
                }

    e13.9   - What is a destructor? What does the synthesized destructor do? When is a destructor synthesized?
                Destructor frees resources of a class and any nonstatic data members of the destroyed object.
                Synthesized destructor provides a (usually empty) function prior to the memberwise destruction phase. In some cases.
                 the synthesized destructor my disallow destruction.
                A destructor is synthesized when no destructor is created in the code.
    
    e13.10  - What happens when a StrBlob object is destroyed? What about a StrBlobPtr?
                StrBlob -  the shared_ptr is deleted and the usage_count decremeneted. If usage_count == 0, memory is freed.
                StrBlobPtr  - the weak_ptr is destroyed, but no change to usage_count.

    e13.11  - Add a destructor to your HasPtr class from the previous exercises.
                ~HasPtr() { };

    e13.12  - How many destructor calls occur in the following code fragment?

                bool fcn(const Sales_data *trans, Sales_data accum) {
                    Sales_data item1(*trans), item2(accum);
                    return item1.isbn() != item2.isbn();
                }

                3 times - Destructor called on accum, item1, and item2.

    e13.14  - Assume that numbered is a class with a default constructor that generates a unique SN for each object, 
                stored as a data member called mysn. Assuming numbered uses the synthesized copy-control members and
                given the following function:

                    void f(numbered s) { std::cout << s.mysn <<std::endl; }

                What is the output of this?

                    numbered a, b = a, c = b;
                    f(a); f(b); f(c);

                Answer: Output is the random number generated by the default constructor a.

    e13.15  - Assume numbered has a copy constructor that generates a new serial number. Does that change the output
                of the calls in the previous exercise? If so, why? What is the output.

                Answer: rand() return copied to new object's mysn member. We declared that when copying objects, rand() should execute and assign return to int mysn;
    
    e13.16  - What if the parameter in f were const numbered& ? Does that change the output? If so, why?

                Answer: Yes, the output changes because no copy operator is executing when calling f();

    e13.17  - Write versions of numbered and f corresponding to the previous three exercises and check whether you were correct.

                See:    class Numbered;
                        void f(const Numbered &);
                        void f(Numbered);
                        void e1314();
                        void e1315();

    e13.18  - Define an Employee class that contains an employee name and a unique employee ID. Give the class
                a default constructor and a constructor that takes a string representing the name. Each constructor 
                should generate a unique ID by incrementing a static data member.

    e13.19  - Does your Employee class need to define its own version of the copy-control members? If so, why? If not, why not?
                Implement the members it needs.

                No reason to define as there's no need to copy since we'd want to keep the name info and unique ID, not reset it.

    e13.20  - Explain what happens when we copy, assign or destroy objects of our TextQuery and QueryResult Classes.

                TextQuery:  std::shared_ptr<std::vector<std::string>> svec;
                            std::map<std::string, std::shared_ptr<std::set<int>>> smap;

                            Copy -  pointer to svec - usage counter increments
                                    map and elements recreated, pointer to shared_ptr of each value, usage counter increments
                            Assign - svec (copied) shares a pointer to the elements of the original svec.
                                    map and key (strings) are copied, but values share pointer to elements of original ints
                            Destructor - svec usage counter decrements. counter < 1 ? delete.
                                         shared_ptr values counter decrement, count < 1 ? delete. Strings are then deleted and map deleted.

                QueryResult:    std::string searchedWord;
                                std::shared_ptr<std::vector<std::string>> qrVec;
                                std::shared_ptr<std::set<int>> qrSet;

                            Copy -  string copied, qrVec and qrSet share pointers to original element. Usage counter increases.
                            Assign  - new string(old string), qrVec and qrSet receive shared pointers
                            Destructor - string destroyed, qrVec and qrSet stop pointing to original elements. Usage counter decremenets.
                                            usage count < 1 ? delete

    e13.21  - Do you think the TextQuery and QueryResult classes need to define their own copy-control members? Why or why not.
                Both classes do not requirement a non-synthesized copy contructor or copy-assignment member. The default
                works as-expected and there is no special need to do otherwise.
*/

class Employee {
public:
    Employee() = default;
    Employee(std::string n) : name(n) { ++id; };
    Employee(const Employee &) = delete;
    Employee& operator=(const Employee &) = delete; 

    void printinfo() { std::cout << "Name: " << name << " | ID: " << id <<std::endl; }

private:
    static int id;
    std::string name;
};

int Employee::id = 0;




class Numbered {
public:
    //friend void f(Numbered);
    friend void f(const Numbered &);
    Numbered() : mysn(std::rand()) { };                     // default constructor
    Numbered(const Numbered &n) { mysn = std::rand(); }     // copy constructor
    Numbered& operator=(const Numbered &n);                 // copy-assignment operator

private:
    int mysn;
};

class HasPtr {
public:
    HasPtr(const HasPtr &h) : ps(new std::string(*h.ps)), i(h.i) { };
    HasPtr& operator=(const HasPtr &orig) {
        if (this != &orig) {
            std::string *temp = new std::string(*orig.ps);
            ps = temp;
            i = orig.i;
        }
        return *this;
    }
    ~HasPtr() { };

    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { };
private:
    std::string *ps;
    int i;
};

//void f(Numbered s) { std::cout << s.mysn <<std::endl; }
void f(const Numbered &s) { std::cout << s.mysn <<std::endl; }


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

void e1314() {
    Numbered a, b = a, c = b;
    std::cout << "f(a) : "; f(a);
    std::cout << "\nf(b) : "; f(b);
    std::cout << "\nf(c) : "; f(c);
}

void e1315() {
    Numbered a, b = a, c = b;
    std::cout << "f(a) : "; f(a);
    std::cout << "\nf(b) : "; f(b);
    std::cout << "\nf(c) : "; f(c);
}


int main()
{
    //e133();
    //HasPtr t1(std::string("Hello World"));
    //HasPtr t2(t1);

    //e1314();
    //e1315();

    return 0;
}