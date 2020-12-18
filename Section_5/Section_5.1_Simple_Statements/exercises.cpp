#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void e51()
{
    // what is a null statment, when might you use one?

    // a null statment is ; which denotes an empty statement
    // a null statement can be used where C++ needs a statement, but the program's logic does not. Null statements should always be commented out

    // a good example of a null statement is a while loop that doesn't take any arguments
}

void e52()
{
    // what is a block, when might you use a block?

    // a block is a section of code contained within {}. A block is useful to section of parts of code.
}

void e53()
{
    // use the comma operator to rewrite the while loop from pg 11 so it no longer requires a block. 
    // Explain where this rewrite improves or diminishes the readability of the code

    // I think it helps with readability, but more complicated statements would be difficult to follow with a comma


    int sum = 0, val = 1;

    /*
    while (val <=10) {
        sum += val;
        ++val;
    }
    cout << "Sum of 1 to 10 inclusive is " << sum <<endl;
    */

   /*
   for (val; val <=10; sum += val, ++val);
   cout << "Sum of 1 to 10 inclusive is " << sum <<endl;
   */

    while (val <= 10) {
      sum += val, ++val;
    }
    cout << "Sum of 1 to 10 inclusive is " << sum <<endl;



}

int main()
{
    e53();

    return 0;
}
