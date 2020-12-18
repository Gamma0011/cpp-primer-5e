#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;

// define your own versions of Screen and Window_mgr in which
// clear is a member of Window_mgr and a friend of Screen

class Screen;

class Window_mgr {
public:
    // location ID for each screen on the window
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens;
};

class Screen {
public:
    typedef std::string::size_type pos;
    // friend declarations
    friend void Window_mgr::clear(ScreenIndex);
    Screen() = default;                 // default constructor
    Screen(pos h, pos w): height(h), width(w), contents(h*w, ' ') { };
    Screen(pos h, pos w, char ch): height(h), width(w), contents(h*w, ch) { };
    char get() const { return contents[cursor]; }
    char get(pos, pos) const;
    Screen &display(std::ostream &os) {
        do_display(os); return *this; }
    const Screen &display(std::ostream &os) const {
        do_display(os); return *this; }
    Screen &move(pos, pos);
    Screen &set(char);
    Screen &set(pos, pos, char);
private: 
    pos height, width;
    pos cursor;
    std::string contents;
    void do_display(std::ostream &os) const { os << contents; }
};

char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

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
    pos row = r * width;
    contents[row + c] = ch;
    return *this;
}

// clear char at index #
void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');

}

int main()
{


    return 0;
}