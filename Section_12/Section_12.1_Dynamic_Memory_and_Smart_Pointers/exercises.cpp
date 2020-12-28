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

int main()
{


    return 0;
}