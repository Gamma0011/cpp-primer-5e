#ifndef E1520_H
#define E1520_H

#include <iostream>

class Base {
public:
    void pub_mem();
    void memfcn(Base &b) { b = *this; }
protected:
    int prot_mem;
private:
    char priv_mem;
};

struct Pub_Derv : public Base {
    int f() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base {
    int f1() const { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv : protected Base {
    int f2() const { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv {
    int use_base() { return prot_mem; }
    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Private : private Priv_Derv {
    // int use_base() { return prot_mem; }
    // void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Protected : protected Prot_Derv {
    int use_base() { return prot_mem; }
    // void memfcn(Base &b) { b = *this; }
};



#endif