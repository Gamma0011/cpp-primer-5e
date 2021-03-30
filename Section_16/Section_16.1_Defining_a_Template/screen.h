#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <iostream>
#include <string>

template<typename T> class Screen;          // forward declaration of class

template<typename T>
std::istream& operator>>(std::istream &is, Screen<T> &s);

template<typename T> 
std::ostream& operator<<(std::ostream &os, const Screen<T> &s);

template<typename T>
class Screen {
public:
    Screen() : width(0), height(0) { };
    Screen(T w, T h) : width(w), height(h) { };

    T getTotalPixels() { return width*height; }

    T getHeight() { return height; }
    T getWidth() { return width; }

    friend std::istream& operator>>(std::istream &is, Screen<T> &s) {
        is >> s.width >> s.height;
        return is;
    }

    friend std::ostream& operator<<(std::ostream &os, const Screen<T> &s) {
        os << "Screen Resolution: " << s.width << "x" << s.height << std::endl;
        return os;
    }

private:
    T width;
    T height;
};

#endif