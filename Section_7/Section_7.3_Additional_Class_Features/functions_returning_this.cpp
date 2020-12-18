#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// **REMEMBER** calling a reference to an object on which is called, allows us to directly modify the contents of that object without having to copy it
// Screen &move, Screen &set, etc     - when called -   Screen &Screen::move() | Screen test | test.move();     -- test directly modified

class Screen {
public: 
    typedef std::string::size_type pos;
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen() = default;
    Screen(pos h, pos w): height(h), width(w), contents(h*w, ' ') { };
    Screen(pos h, pos w, char c): height(h), width(w), contents(h*w, c) { };
    char get() const { return contents[cursor]; }
    inline char get(pos, pos) const;
    Screen &move(pos, pos);
    Screen &display(std::ostream &os) {            
        do_display(os); return *this; }
    const Screen &display(std::ostream &os) const {         // note the 2x const - const Obj and const Func
        do_display(os); return *this; }
private:
    pos height, width, cursor;
    std::string contents;
    // function doing the work of displaying a Screen
    void do_display(std::ostream &os) const { os << contents; }
};

char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

inline Screen &Screen::move(pos r, pos c) {
    pos row = r * width;                // compute the row location
    cursor = row + c;                   // move cursor to the column within that row
    return *this;                       // return the object as an lvalue
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;           // set the new value at the current cursor location
    return *this;                    // return this object as an lvalue
}

inline Screen &Screen::set(pos r, pos c, char ch) {
    contents[r*width + c] = ch;                         // set specified location to given value
    return *this;                                       // return this object as an lvalue
}

int main()
{
    // move the cursor to a given position, and set that character
    Screen myscreen;
    //myscreen.move(4,0).set('#');

    /* if move were to return Screen and not Screen &, here's what we'd have to do:
        Screen temp = myscreen.move(4,0);       // return value (*this) copied to temp
        temp.set('#');                          // the contents inside myscreen would be unchanged

    */

    return 0;
}
