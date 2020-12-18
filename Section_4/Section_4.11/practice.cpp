#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void conv()
{
// in c++ some types are related to each other.
// when two types are related, we can use an object or value of one type where an operand of the related type is expected

// two types are related if there is a conversion between them, for example;

int ival = 3.541 + 3;       // compiler might warn about loss of precision
cout << ival <<endl;

// c++ defines a set of conversions to transform the operands to a common type and are carried out automatically without programmer intervention
//  these are referred to as IMPLICIT CONVERSIONS

// IMPLICIT CONVERSIONS are defined to preserve precision, if possible.

// Compiler automatically converts operands in the following circumstances:
// - in most expressions, values of integral types smaller than int are first promoted to an appropriate larger integral type;
// - in conditions, nonbool expressions are converted to bool;
// - in initializations, the initializer is converted to the type of the variable.
// - in assignments, the right-hand operand is converted to the type of the left-hand operand
// - in arithmetic, the relational expressions with operands of mixed type are converted to a common type
// - conversions also happen during function calls


}

int main()
{
    conv();

    return 0;
}