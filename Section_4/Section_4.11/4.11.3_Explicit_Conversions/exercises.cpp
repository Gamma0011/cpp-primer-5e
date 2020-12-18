#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void e436()
{
    // assuming i is int, and d is double, write the expression i *= d so that it does integral, rather than floating-point multiplication
    int i = 10;
    double d = 8.909;

    // resolve d as type int, multiply by i and assign output to i
    i *= static_cast<int>(d);
    cout << i <<endl;
}

void e437()
{
    // reqrite each of the following old-style casts to use a named cast;

    int i;
    double d;
    const string *ps;
    char *pc;
    void *pv;

    //pv = (void*)ps;
    pv = const_cast<string*>(ps);

    // i = int(*pc);
    i = static_cast<int>(*pc);

    // pv = &d;
    pv = static_cast<void*>(&d);

    // pc = (char*) pv;             == char *pc = (char*) pv;
    pc = static_cast<char*>(pv);
}


void e438()
{
    // explain
    int i = 10;
    double j = 7.692;
    double slope = static_cast<double>(j/i);

    cout << slope <<endl;
    cout << (j/i) <<endl;

    // slope is of type double and is initialized as j/i, both whose types are resolves as double for this expression
    
}

int main()
{
    //e436();
    e438();

    return 0;
}
