#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;

/*
    e756 - what is a static class member? what are the advantages of staic members, how do they differ from normal members?
        A static class member is a member associated with the entire class and not specific to declared objects of the class. Static
        members can be used to declared things for the entire class. Addtionally, they can have incomplete types and be used as default arguments
        since they are not specific to each declared class object
    e757 - write your own version of the Account class

    e758 - which, if any, of the following static data member declarations and definitions are errors?

        // example.h
        class Example {
        public:
            static double rate = 6.5;
            static const int vecSize = 20;
            static vector<double> vec(vecSize);
        private:
        };

        //example.cpp
        #include "example.h"
        double Example::rate;
        vector<double> Example::vec;
*/

class Account {
public:
    static double returnInterest() { return interestRate; }
    double calculate() { return amount += amount * interestRate; }
    void setRate(double);
private:
    std::string owner;
    static double interestRate;
    double amount;
};

class Example {
        public:
            static constexpr double rate = 6.5;               // this will fail. Cannot be initialized in body unless declared const. must be constexpr
            static const int vecSize = 20;
            static vector<double> vec;     // cannot specify in-class initializers within parentheses
        private:
        };

int main()
{

    return 0;
}
