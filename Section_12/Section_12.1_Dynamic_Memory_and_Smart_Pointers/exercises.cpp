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

*/

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


int main()
{
    // e12.6
    //printElements(addElements(makeVec()));

    // 12.7
    //displayElements(insertElements(createVec()));

    return 0;
}