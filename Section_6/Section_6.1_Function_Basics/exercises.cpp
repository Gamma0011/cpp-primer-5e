#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void e61()
{
    // difference between parameter and an argument
    // Parameters - established types accepted by a stated function - int fun1(int a);  int a is a parameter
    // Arguments - variables passed to the parameters of a function - fun1(60);         60 is an argument passed to the parameter int a within function fun1
}

void e62()
{
    /*  indicate which of the following functions are in error and why;

    a) int f() {
            string s;
            return s;
        }

        WRONG. int f() expects return type of int, this function returns type string
            Change string s to int s

    b) f2 (int i) {};           WRONG. No return type specified. Must denote return type. int f2(int i) {}; would work

    c) int calc(int v1, int v1) {}; WRONG cannot assign same variable and type. can fix by making int v1, int v1 to int v1, int v2

    d) double square (double x) return x * x;       WRONG. Function body needs braces (scope);
        double square (double x) {return x * x};
    */

}

double e63(double a)
{
    // write your own version of fact
    double ret = 1;

    while (a > 1) {
        ret *= a--;
    }
    return ret;
}

void e64() {

    // already did this in e63;
}


int e65(int x)
{
    // write a function to return the absolute value of it's argument
    int y;
    if (x >= 0){
        y = x;
    } else {
        y = -x;
    }
    return y;
}

void e66()
{
    // explain the differences between parameters, local variable and a local static variable;
    // give an example of a function in which each might be useful

    // Parameters - established types accepted and used within a function
    // local variable - variables used during execution of function call, re-initalized after each use
 
    // see size_t count_add(size_t n) 
}

size_t count_add(int n)
{
    static size_t cnt = 0;
            
    cnt += n;
    return cnt;
}

int e67() {
    static int counter = 0;
    return counter++;
}

void e610(int* a, int* b) 
{
    // using pointers swap the values of two ints
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    /*
    cout << "Please enter a number you'd like to know the factorial of: ";
    double x;
    cin >> x;

    cout << "Factorial of " << x << " is " << e63(x) <<endl;
    */
   //cout << e65(-430) <<endl;

    /*
   for (int i = 0; i < 10; ++i) {
       cout << count_add(i) << " ";
   }
   */

    //cout << "0:" << e67() << " 1:" << e67() << " 2:" << e67() <<endl;


    // e610
    for (int x, y; cout << "Please enter two numbers to swap: ", cin >> x >> y; /*do nothing*/) {
        e610(&x, &y);
        cout << x << " : " << y <<endl;
    }

    return 0;
}
