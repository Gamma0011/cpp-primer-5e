#ifndef BASE_CLASS_H
#define BASE_CLASS_H

class Base {
public:
    static void statmem();
};

class Derived : public Base {
    void f(const Derived&);
};


#endif