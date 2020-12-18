#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// integral promotions - convert the small integral type to a larger type;
// bool, char, signed char, unsigned char, short and unsigned short are all promoted to int if values can fit. Otherwise, promoted to unsigned int

int main()
{

    bool flag;
    char cval;
    short sval;
    unsigned short usval;
    int ival;
    unsigned int uival;
    long lval;
    unsigned long ulval;
    float fval;
    double dval;

    cout << 3.14159L + 'a' <<endl;              // a promoted to int, then that int converted to long double;
    dval + ival;                                // ival promoted to double;
    dval + fval;                                // fval converted to double;
    ival = dval;                                // dval converted && trunicated to type int
    flag = dval;                                // if dval is 0, the flag is false, otherwise true;
    cval + fval;                                // cval promoted to type int, then converted to float;
    sval + cval;                                // sval && cval promoted to type int;
    cval + lval;                                // cval promoted to type long
    ival + ulval;                               // ival converted to type unisgned law;
    usval + ival;                               // conversion depends on the size of unsigned short and int;
    ulval + ival;                               // conversion depends on size of unsigned long and int;


    return 0;
}