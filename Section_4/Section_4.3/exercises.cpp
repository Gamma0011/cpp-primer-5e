#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void e48()
{
    // explain when operands are evaluated in the logical AND, logical OR, and equality operators
    // AND, evaluated left to right operand. Moves to right operand only if left == TRUE
    // OR, evaluted left to right operand. Moves right only if left == FALSE;
    // equality operators evaluate left to right. Left must != or == right to resolve to TRUE or FALSE
}

void e49()
{
    // explain the behavior of the condition in the following if:
    const char *cp = "Hello World";
    if (cp && *cp) {                // if cp variable exists and has a pointer
        cout << "True" <<endl;
    } else {
        cout << "False" <<endl;
    }
}

void e410()
{
    // write the condition for a while loop that would read ints from the std input and stop when value == 42

    int i;
    cout << "Please enter a number: " <<endl;
    while(cin >> i && i != 42){
        cout << "Please enter a number: " <<endl;
    }
    cout << "You guessed the nummber, it was " << i <<endl;
}

void e411()
{
    // write an expression that tests 4 values, a, b, c, d, and ensures that a is greater than b, which is greater than c, which is greater than d
    cout << "Please enter 4 sequentially increasing numbers: " <<endl;
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a < b && b < c && c < d){
        cout << "Thanks! All numbers were sequential." <<endl;
    } else {
        cout << "Error: Not all numbers sequential and increasing." <<endl;
    }
}

void e412()
{
    // assuming i,j,k ints, what does i != j < k mean?
    // in order of operations, this means that j < k == True/False, then i != 1 or 0, depending on true or false

    int i = 1, j = 2, k = 10;

    cout << (i != j < k) <<endl;
}

int main()
{
    //e49();
    //e410();
    //e411();
    e412();

    return 0;
}
