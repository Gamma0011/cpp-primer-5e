#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// e723 - write your own version of the Screen Class
// e724 - write 3 constructors - one as default, one as 2 args, one as 3 args
// e725 - can Screen safely rely on the default versions of cppy and assignment, why or why not?
//         class Screen will work correctly. Per 7.1.5 (pg, 267)
//         1 - Synthesized versions are unlikely to work correctly for classes that allocate resources that reside outside the class objects themselves
//         2 - Classes that manage dynamic memory, generally cannot rely on synthesized versions of these operations - use Strings or Vectors to store data
// e726 - define Sales_data::avg_price as an inline function
/* e727 - add move, set, and display operations to your Screen class, test by executing:
        Screen myscreen(5, 5, 'X');
        myscreen.move(4,0).set('#').display(cout);
        cout << "\n";
        myscreen.display(cout);
        cout << "\n";
// e728 - what would happen if the return type of move, set, and display was Screen and not Screen &?
        A copy of the object would have to be made, then that copied object returned. The Screen& directly modifies or calls the object
// e729 - revise Screen to see what happens when using Screen instead of Screen&
// e730 - it is legal but redundant to refer to members through the this pointer. Discuss pros and cons of explicitly using this pointer to access members  
            Pros:
                - Easier to chain multiple member function calls together
                - Explicit return (return local object)
            Cons:
                - sometimes redundant
                - more to read std::string getAddr() const { return this->addr; } // unnecessary

// e731 - define a pair of classes X and Y, in which X has a pointer to Y, and Y has an object of type X.
    class Y;

    class X {
        Y *y = nullptr;
    };

    class Y {
        X obj1;
    };
*/




class Screen {
public:
    typedef std::string::size_type pos;
    Screen() = default;                 // default constructor;
    Screen(pos h, pos w): height(h), width(w), contents(h*w, ' ') { };                      // accept 2 arguments, char defaults to ' '
    Screen(pos h, pos w, char c): height(h), width(w), contents(h*w, c) { };                // accept 3 arguments, height, width, char
    char get() const { return contents[cursor]; }
    Screen &move(pos, pos);
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &os) { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const { do_display(os); return *this; }
private:
    pos height, width, cursor;
    std::string contents;

    //do_display function
    void do_display(std::ostream &os) const { os << contents; };
};

Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

Screen &Screen::set(char ch) {
    contents[cursor] = ch;
    return *this;
}

Screen &Screen::set(pos r, pos c, char ch) {
    contents[r * width + c] = ch;
    return *this;
}

class Sales_data {
public:
    Sales_data() = default;
    Sales_data(std::string b, unsigned u, double r): bookNo(b), units_sold(u), revenue(r) { };
    double avg_price() const;
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

inline double Sales_data::avg_price() const {
    return revenue/units_sold;
}

int main()
{
    /*
    Screen test(323,453,'t');
    Sales_data book("book", 32, 320);
    cout << book.avg_price() <<endl;
    */

    Screen myscreen(5, 5, 'X');
    Screen test = myscreen.move(4,0).set('#').display(cout);
    cout << "\n";
    test.display(cout);
    cout << "\n";
    myscreen.display(cout);
    cout << "\n";

    return 0;
}