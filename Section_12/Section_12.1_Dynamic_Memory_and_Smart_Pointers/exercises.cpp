#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>

/*
    e12.1   - How many elements do b1 and b2 have at the end of this code?
                StrBlob b1;                             // b1 object of class StrBlob
                {   StrBlob b2 = {"a", "an", "the"};    // b2 initialized to std::vector<std::string>> articles
                    b1 = b2;                            // b1 points to elements of b2
                    b2.push_back("about"); }            // "about" appended to object to which b2 points
                                                        // b2 destroyed because end of scope. however, elements to which
                                                        //  b1 points (b2) exist. b1 has 4 elements, b2 no longer exists

    e12.2   - Write your own version of the StrBlob class including the const version of front and back.
                see class NewStrBlob {};

                    const std::string &front() const;       // front is a const function returning a const string&, return by reference rather than return by value (copying)
                    const std::string &back() const;        // back is a const function returning a const string&, return by reference rather than return by value (copying)

                ** VERY USEFUL: https://stackoverflow.com/questions/5496491/c-const-members-return-const-int-vs-return-int **

    e12.3   - Does this class need const version of push_back and pop_back? If so, add them. If not, why aren't they needed?

                While the compiler doesn't complain about issues when declaring void pop_back() const, and void push_back() const, 
                the declaration of a const member function should denote that the function does not modify any members of the class. In the case
                of the pop_back and push_back functions, elements are added or removed from data, therefore, modifications are technically being made.
                As a result, best practice should be to not declare either function const.

               https://stackoverflow.com/questions/7907235/what-is-intention-of-making-a-function-const
    
    e12.4   - In our check function, we didn't check whether i was greater than zero. Why is it okay to omit that check?
                Not necessary to check since the main reason for running check is to make sure that the .size() of the std::vector<std::string> is not empty.
                If the vector is empty, it returns 0 on the .size() check. There might be reason for us wanting to customize the .size() 
                check, so having i >= vec.size() gives us the latitude to do so.

                std::vector<std::string>::size_type also is unsigned, therefore anything < 0 will become positive
    
    e12.5   - We did not make the constructor that takes an initializer_list explicit. Discuss the pros and cons of this design choice.
                
                Declaring the constructor explicit would prevent the conversion from initializer_list<string> to object of type NewStrBlob
                    Pros: Compiler will not use contructor in an automatic conversion
                    Cons: Cannot use copy initialization because constructor is explicit

    e12.6   - Write a function that returns a dynamically allocated vector<int>. Pass that vector to another function that reads
                the std::cin to give values to the elements. Pass the vector to another function to print the values read.
                Remember to delete the vector at the appropriate time.

    e12.7   - Redo the previous exercise, this time using shared_ptr

    e12.8   - Explain what, if anything is wrong with the following function.
                bool b() { int* p = new int;     return p; }

                pointer is converted to boolean value. While valid, p cannot be freed and memory leakage will occur.

                "A prvalue of integral, floating-point, unscoped enumeration, pointer, and pointer-to-member types can 
                be converted to a prvalue of type bool. "
                Source: https://en.cppreference.com/w/cpp/language/implicit_conversion
    
    e12.9   - Explain what happens in the following code:
                int *q = new int(42), *r = new int(100);        // q & r point to dynamically allocated objects 42 and 100
                r = q;                                          // r points to object of q now | *r = 42, *q = 42;
                                                                // memory leak occurs. original object r not deleted and now not accessible
                auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
                r2 = q2;                                        // r2 points to object q2. r2 memory automatically freed.

    e12.10  - Explain whether the following call to the process function defined on page 464 is correct. If not, how would you 
                correct the call?
                    shared_ptr<int> p(new int(42));
                    process(shared_ptr<int>(p));

                    Legal, but not needed. p is already of type shared_ptr<int> and doesn't require conversion

    e12.11  - What would happen if we called process as follows?
                process(shared_ptr<int>(p.get()));

                Once p leaves scope (process function ends), object of p will be deleted and memory freed. 

    e12.12  - Using the declarations of p amd sp, explain each of the following calls to process. If the call is legal,      
                explain what it does. If not legal, why?
                
                auto p = new int();             p pointer to statically allocated memory
                auto sp = make_shared<int>();   sp pointer to dynamically allocated memory
                a) process(sp);         // no issues. sp is shared_ptr<int>
                b) process(new int());  // error: will need to convert to shared_ptr<int>(new int()) for function to work
                c) process(p);          // error: will need to pass shared_ptr<int>(p) to work. cannot convert from int*
                d) process(shared_ptr<int>(p)); // okay, will work. int* converted to shared_ptr<int>
    
    e12.13  - What happens if we execute the following code?
                auto sp = make_shared<int>();           // dynamically allocated 
                auto p = sp.get();                      // pointer to sp returns and assigned to p. p 
                delete p;                               // p deleted

                see. void e1213();

    e12.16  - Compilers don't always give easy-to-understand error messages if we attempt to copy or assign a unqiue_ptr.
                Write a program that contains these errors to see what your compiler does.

                see. void e1216();
    
    e12.17  - Which of the following unique_ptr declarations are illegal or likely to result in subsequent program error?
                Explain what the problem is.

                see. void e1217();

    e12.18  - Why doesn't shared_ptr have a release member?
                Release exists for unique_ptr because only one unique_ptr at a time can refer to an object. To properly transfer
                 ownership, we must release ownership from one and assign to another. Shared_ptr can have mutiple pointers pointing
                 to the same object. As pointers stop pointing or leave scope, the program automatically "releases" them and reduces
                 the use count until a point that .use_count() == 0 and the object is deleted.

    e12.21  - We could have written StrBlobPtr's deref member as follows. Which do you think is better and why?
                std::string& deref() { return (*check(curr, "dereference past end"))[curr]; }

                I think the original return (*p)[curr]; is better because it is clear what the return is. Whatever auto p = check(curr, " ") returns will be dereferenced then returned at that [curr] element
                 This also might be better since the rest of our program's functions run the check() function then print their return, rather than combining it.

    e12.22  - What changes would need to be made to StrBlobPtr to create a class that can be used with a const StrBlob? Define a class named ConstStrBlobPtr that can point to a const StrBlob
                    see strblobs.h (class ConstStrBlobPtr)

*/

std::shared_ptr<int> process(std::shared_ptr<int> p) { return p; }

class NewStrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    NewStrBlob() : data(std::make_shared<std::vector<std::string>>()) { };
    NewStrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) { };
    size_type size() { return data->size(); }
    bool empty() { return data->empty(); }
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();

    const std::string &front() const;       // front is a const function returning a const string&, return by reference rather than return by value (copying)
    const std::string &back() const;        // back is a const function returning a const string&, return by reference rather than return by value (copying)
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

void NewStrBlob::check(size_type i, const std::string &msg) const { if (i >= data->size()) { throw std::out_of_range(msg); } }

void NewStrBlob::pop_back() { 
    check(0, "Pop_back on empty string.");          // check that condition not met (throw std::out_of_range(msg))
    data->pop_back();                               // if no error
}

const std::string &NewStrBlob::front() const {
    check(0, "Front on empty StrBlob");             // check that condition not met (throw std::out_of_range(msg))
    return data->front();                           // if no error
}

const std::string &NewStrBlob::back() const {
    check(0, "Back on empty StrBlob.");             // check that condition not met (throw std::out_of_range(msg))
    return data->back();                            // if no error
}

// e12.6
std::vector<int>* makeVec() {
    std::vector<int> *ivec = new std::vector<int>;
    return ivec;
}
std::vector<int>* addElements(std::vector<int> *ivec) {
    int i;
    while(std::cin >> i && i != -1) { ivec->push_back(i); }
    return ivec;
}
void printElements(std::vector<int> *ivec) {
    for (auto &i : *ivec) { std::cout << i << '\t'; }
    std::cout <<std::endl;
    delete ivec;
}

// e12.7
std::shared_ptr<std::vector<int>> createVec() {
    auto pv = std::make_shared<std::vector<int>>();
    return pv;
}
std::shared_ptr<std::vector<int>> insertElements(std::shared_ptr<std::vector<int>> pv) {
    int i;
    std::cout << "Please enter numbers. Type -1 to exit: " << std::endl;
    while (std::cin >> i && i != -1) { pv->push_back(i); }
    return pv;
}
void displayElements(std::shared_ptr<std::vector<int>> pv) {
    for (auto &i : *pv) { std::cout << i << '\t'; }
    std::cout <<std::endl;
}

void e1210() {
    std::shared_ptr<int> p(new int(42));
    std::cout << p.use_count() << std::endl;
    process(std::shared_ptr<int>(p));
    std::cout << p.use_count() << std::endl;
}

void e1211() {
    std::shared_ptr<int> p(new int(24));
    process(std::shared_ptr<int>(p.get()));
        std::cout << *p <<std::endl;
}

void e1213() {
    auto sp = std::make_shared<int>();          // sp points to value-initialized object of type int
    auto p = sp.get();                          // p is int* to sp;
    std::cout << sp.use_count() <<std::endl;
    delete p;                                   // int* removed, which also frees memory for sp; sp now dangling pointer;
    std::cout << sp.use_count() <<std::endl;
}

void e1216() {
    std::unique_ptr<int> p1(new int(42));   
    std::unique_ptr<int> p2;
    //p2 = p1;                      // error: use of deleted function
    //std::unique_ptr<int> p3(p1);  // error: use of deleted function
    std::unique_ptr<int> p4(p1.release());
    (p1 == nullptr) ? std::cout << "p1 == nullptr" <<std::endl : std::cout << *p1 <<std::endl;
    std::cout << "p4 == " << *p4 <<std::endl;
}

void e1217() {
    int ix = 1024, *pi  = &ix, *pi2 = new int(2048);
    typedef std::unique_ptr<int> IntP;
    //IntP p0(ix);              // ix needs to be declared as new. IntP p0(new int(ix));
        IntP p0(new int(ix));   // fixed
    //IntP p1(pi);              // pi will compile, but is in error since this is a static pointer and not one formed by new
        IntP p1(new int(*pi));  // fixed, p1 points to object of pi
    //IntP p2(pi2);             // will cause dangling pointer when out of scope. p2 deletes object of pi2, but pi2 still exists
    //IntP p3(&ix);             // &ix returns a reference to memory for ix. will compile, but is also in error. object not created with new
    IntP p4(new int(2048));     // proper way to declare
    //IntP p5(p2.get());          // two unique_ptrs pointing to same object (pi2).
        //IntP p5(p2.release());  // technically correct, but p2 still causes dangling pointer
}

int main()
{
    // e12.6
    //printElements(addElements(makeVec()));

    // 12.7
    //displayElements(insertElements(createVec()));

    //e1210();
    //e1211();
    //e1213();
    //e1216();
    e1217();

    return 0;
}