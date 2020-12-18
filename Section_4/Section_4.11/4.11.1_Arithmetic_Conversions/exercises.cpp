#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;


void e434()
{
    // given the variable definition in the section, explain the conversions
    
    // if (fval);                   fval converted to bool, if fval exists = 1/0
    // dval = fval + ival           double = float + ival || float & ival converted to type double
    // dval + ival * cval           cval converted to int, ival & cval converted to double
}

void e435()
{
    // identify implicit type conversion, if any, taking place. definitions:
    // char cval;   int ival;   unsigned int ui;    float fval;     double dval;    


    // *** double has more precisions than float ****

    // cval = 'a' + 3;              'a' promoted to int, int a + 3 is then converted to char;
    // fval = ui - ival + 1.0;      ui & ival promoted to double, double ui and ival added to 1.0, then trunicated to float by fval;
    // dval = ui * fval;            ui promoted to float, multiplied by fval, then converted to double;
    // cval = ival + fval + dval;   ival and fval converted to double, added to dval, then trunicated to char cval;


}

int main()
{
    //e434();
    e435();


    return 0;
}