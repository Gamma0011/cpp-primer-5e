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
    using ScreenIndex = std::vector<Screen>::size_type;
    // add a Screen to the window and return its index
    ScreenIndex addScreen(const Screen&);
    inline void clear(ScreenIndex);
private:
    std::vector<Screen> screens;
};

class Screen {
public:
    typedef std::string::size_type pos;
    friend inline void Window_mgr::clear(ScreenIndex);
    Screen() = default;
    Screen(pos h, pos w, char c): height(h), width(w), contents(h*w, c) { };
    //pos size() const { return height * width; }
    pos size() const;
    inline char get();
    inline char get(pos, pos);
private:
    pos height, width;
    pos cursor;
    std::string contents;
};

char Screen::get() {
    return contents[cursor];
}

char Screen::get(pos r, pos c) {
    pos row = r * width;
    return contents[row + c];
}

// return type is seen before we're in the scope of Window_mgr
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) {
    screens.push_back(s);
    return screens.size() - 1;
}
void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

// outside the class scope, ordinary data and function member may only be accessed through an object, reference or a pointer using a member access operator
Screen::pos ht = 24, wd = 80;       // use the pos type defined by Screen
Screen scr(ht, wd, 'Y');            
Screen *p = &scr;
char c = scr.get();                 // fetches the get member from the object scr
char ch = p->get();                 // fetches the get member from the object to which p points

// pos size() defined outside Screen class
Screen::pos Screen::size() const { return height * width; }

int main()
{


    return 0;
}
