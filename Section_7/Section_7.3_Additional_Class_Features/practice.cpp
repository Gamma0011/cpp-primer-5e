#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istream;
using std::ostream;

class Screen {
public:
    typedef std::string::size_type pos;     // typedef creates an alias of std::string::size_type called pos
    Screen() = default;                     // needed because Screen has another constructor
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht*wd, c) { }       // pos ht == std::string::size_type ht
    char get() const { return contents[cursor]; }   // get contents at cursor | implicitly inline because within class body
    inline char get(pos ht, pos wd) const;          // explicitly inline | get contents from supplied ht and wd
    Screen &move(pos r, pos c);                     // can be made inline later
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

// use of the mutable keyword
class ScreenMutable {
public:
    void some_member() const;
private:
    mutable size_t access_ctr;      // may change even in a const object
    //.. other members as before
};

void ScreenMutable::some_member() const 
{
    ++access_ctr;           // keep a count of the calls to any member function
    // whatever other work this member needs to do
}

// in-class initializer
class Window_mgr {
private:
    // Screens this Window_mgr is tracking
    // by default, a Window_mgr has one standard sized blank Screen
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};


inline                              // specified inline in definition
Screen &Screen::move(pos r, pos c) 
{
    pos row = r * width;        // compute the row location
    cursor = row;               // move cursor to the column within that row
    return *this;               // return this object as an lvalue
}

char Screen::get(pos r, pos c) const  // declared as inline in the class
{
    pos row = r * width;            // computer row location
    return contents[row + c];      // return character at given column

}

int main()
{
    Screen myscreen;
    char ch = myscreen.get();       // calls Screen::get()
    ch = myscreen.get(0,0);         // calls Screen::get(pos, pos);

    return 0;
}
