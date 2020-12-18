#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void practice()
{
    // sometimes we want to explicitly force an object to be converted to a different type. 
    //  For example, we might want to use floating-point division in the following code:
    int i, j;
    double slope = i/j;

    // to do this, we need a way to explicitly convert i and/or j to double. We use a CAST to request an explicit conversion.
    // NOTE** casts are inherently dangerous constructs.

    // a named cast has the following form:
    // cast-name<type> (expression);
    // type = target type of conversion, and expression is the value to be cast.
    // cast-name may be one of static_cast, dynamic_cast, const_cast, and reinterpret_cast
}

void staticcast()
{
    int i, j;
    // cast used to force floating-point divison
    double slope = static_cast<double>(j) / i;

    /* static cast is useful when a larger arithmetic type is assigned to a smaller type

    another use: perform conversion that compiler will not generate automatically
    use static_cast to retrieve a pointer value stored in a void* pointer
    void* p = &r;       // address of any noncost object can be stored in a void

    // converts void* back to original pointer type

    double *dp = static_cast<double*>(p);
    */
}

void constcast()
{
    // const_cast only changes a low-level const in its operand
    const char *pc;
    char *p = const_cast<char*>(pc);        // okay, but writing through p is undefined
    // using a const_cast in order to write to a const object results in undefined
    // however, if an object was no a const, using const_cast to obtain write-access is legal


    // NOTE:: only a const_cast mah be used to change the CONSTness of an expression
    // NOTE:: additionally, we cannot use a const_cast to change the **type** of an expression

    const char *cp;
    // error: static_cast can't cast away const
    // char *q = static_const<char*>(cp);

    static_cast<string>(cp);    // okay, converts string literal into string;
    //const_cast<string>(cp);     // error: const_cast only changes CONSTness
}


void reinterpretcast()
{
    // NOTE** reinterpret_cast is dangerous to use and machine dependent. Requires full knowledge of types involved and compiler implementations of the cast
    // reinterpret cast performs a low-level reinterpretation of the bit pattern of its operands
    int *ip;
    char *pc = reinterpret_cast<char*>(ip);
    // important to remember that the actual object addressed by pc is of type int, not a char
    // any use of pc that assumes it's a char* is likely to fail

    // string str(pc);              this will result in a weird runtime error
}

void oldstylecasts()
{
    // early c++ casts took the following forms:
    // type (expr);         // function-style cast notation
    // (type) expr;         // c-language-style cast notation

    // depending on the types involved, an old-style cast has the same behavior as a const_, static_, or reinterpret_cast. 
    // When we use an old-style cast where a static_ or const_ would be legal, the old-style does the same conversion as the respective cast.
    // if the static_ or const_ aren't legal, old-style performs reinterpret_
    int *ip;
    char *pc (char*) ip;        // ip is pointer to int

}


int main()
{

    reinterpretcast();

    return 0;
}
