#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istream;
using std::ostream;

struct X
{
    friend void f() { 
        /* friend function can be defined in the class body */ 
        cout << "Hello World" <<endl;}
    //X() { f(); }        // error: no declaration for f
    void g();
    void h();
};

//void X::g() { return f(); } // error: f hasn't been declared
void f();
void X::h() { return f(); }


int main()
{



    return 0;
}
