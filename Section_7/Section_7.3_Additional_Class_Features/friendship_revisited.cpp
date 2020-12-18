#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;

class Screen;

class Window_mgr {
public:
    // location ID for each screen on the window
    using ScreenIndex = std::vector<Screen>::size_type;
    // reset the Screen at the given position to all blanks
    inline void clear(ScreenIndex);
private:
    std::vector<Screen> screens;
};

// overloaded storeOn functions
extern std::ostream& storeOn(std::ostream &, Screen &);

class Screen {
public: 
    // grant class Window_mgr access to private members of class Screen
    //friend class Window_mgr;
    // grant only Windows_mgr function void clear() access to class Screen
    typedef std::string::size_type pos;
    friend void Window_mgr::clear(ScreenIndex);
    // extern ostream friendship declaration
    friend std::ostream& storeOn(std::ostream&, Screen&);
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

void Window_mgr::clear(ScreenIndex i) {
    // s is a reference to the Screen we want to clear
    Screen &s = screens[i];
    // reset the contents of that Screen to all blanks
    s.contents = string(s.height * s.width, ' ');
}

int main()
{


    return 0;
}
