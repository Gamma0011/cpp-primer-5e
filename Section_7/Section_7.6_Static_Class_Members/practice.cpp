#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;

class Account {
public:
    // member functions can use static members without scope (since they're a part of the same class)
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    // static member functions can be declared inside or outside the class body.
    //  when defining the function outside the class, we do not need to declare static again ( see void Account::rate(double newRate))
    static void rate(double);
private:
    string owner;
    double amount;
    static double interestRate;
    static double initRate();
    static constexpr int period = 30;   // period is a constant expression
    double daily_tbl[period];
};

// even if a const static data member is initialized in the class body, that member should be defined outside the class body
constexpr int Account::period;

void Account::rate(double newRate) {
    interestRate = newRate;
}

class Bar {
public:
    //
private:
    static Bar mem1;        // ok: static member can have incomplete type;
    Bar *mem2;              // ok: pointer member can have incomplete type
    //Bar mem3;               // error: data members must have complete type;
};


// static members can be used as default arguments because it is not a part of the object to which it is a member
// **REMEMBER** static objects are objects to the whole class, not each individual member
class Screen {
public:
    // bkground refers to the static member
    // declared later in the class definition
    Screen& clear(char = bkground);
private:
    static const char bkground;
};

int main()
{
    Account Stefan;
    // static members do not belong to any object, but rather are shared by the entire class. In this case, class Account.
    //  Although static members do not belong to any object, we can use an object, & or * of class type to access a static member
    Account ac1;
    Account *ac2 = &ac1;

    double r;
    //equivalent ways to call static member rate function;
    r = ac1.rate();         // through an Account object or reference
    r = ac2->rate();        // through a pointer to an Account object

    // static members can be accessed via the scope operator
    r = Account::rate();

    return 0;
}
