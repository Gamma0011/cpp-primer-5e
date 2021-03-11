#include <iostream>
#include <string>

/*
    e15.23  - Assuming class D1 on pg 620 had intended to override its inherited fcn() function, how would you fix the class?
                Assuming you had fixed the class so that fcn matched the defintion in base, how would calls be resolved?

            In D1, I would specify virtual void fcn() override. This declares that we'd like to continue to use fcn as we move 
             through various base and derived classes, and that we intend to override fcn() in D1.

            If we made fcn() exactly the same as Base, we'd then have to look to see if it was declared as "override". If it was, 
            an object of type D1 or D2, assuming fcn() wasn't overrode in D2, would call D1 over Base. If we matched and didn't declare 
            override of that the function was virtual, an object of that class type would use its class function, but it would be 
            statically bound.
*/

class Base {
public:
    virtual int fcn(); 
};

class D1 : public Base {
public:
    virtual int fcn() override;
    int fcn(int);
    virtual void f2();
};

class D2 : public D1 {
public:
    int fcn(int);
    int fcn();
    void f2();
};

int main()
{


    return 0;
}