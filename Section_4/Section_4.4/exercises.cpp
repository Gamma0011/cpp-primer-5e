#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void e413()
{
    // what are the values of each assignment?
    int i;
    double d;

    d = i = 3.5;            // i = 3, d = 3.0
    cout << d << '\t' << i <<endl;
    i = d = 3.5;            // d = 3.5, i = 3;
    cout << d << '\t' << i <<endl;
}

void e414()
{
    // explain what happens in each of the if tests;
    int i;

    /*
    if (42 = i) {               // error, lvalue required as left operand of assignment
        cout << "Test 1" <<endl;    
    } else {
        cout << "Failure test 1" <<endl;
    }
    */

    if (i = 42) {               // if 42 can be assigned to i
        cout << "Test 2 Success." <<endl;
    } else {
        cout << "Failure Test 2" <<endl;
    }
}

void e415()
{
    // the following assignment is illegal, why? how do you correct it?
    double dval;
    int ival;
    int *pi;
    // dval = ival = pi = 0;

    // correct by:
    dval = ival = 0;      // cannot assign *int (pi) to int (ival)
    pi = 0;

    cout << dval << ival << pi <<endl;
}

void e416()
{
    // although the following are legal, they do not behave as the programmer expects. Why, write as you think they should be;
    int p, i;

    // if (p = getPtr() != 0) is wrong. compiler unsure of what condition to resolve. () around (p = getPtr()) resolve that first, then p != 0;
    if ((p = getPtr()) != 0){
        cout << "1" <<endl;
    } else {
        cout << "0" <<endl;
    }

    // if (1024 = i) is wrong, trying to assign r operand to l operand
    if (i = 1024){
        cout << "1" <<endl;
    } else {
        cout << "0" <<endl;
    }

}

int main()
{
    //e413();
    //e414();
    e415();

    return 0;
}