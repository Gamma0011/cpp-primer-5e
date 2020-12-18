#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void e190(){
    // write a program that uses while to sum numbers from 50 to 100;

    int num = 50;
    int total = 0;

    while(num <= 100){
        total += num;
        num ++;
    }
    cout << "Sum of all numbers from 50 to 100 is " << total <<endl;
}

void e110(){
    // use decrement operator to write a while that prints numbers from 10 to 0

    int cnt = 10;

    while(cnt >= 0){
        cout << cnt <<endl;
        cnt--;
    }
}

void e111(){
    // prompt user for two numbers, print range between two numbers

    int higher = 0, lower = 0;      // declare and initialize
    
    cout << "Let's count! Please enter the numbers you'd like to count from and to.\nLower first: " <<endl;
    cin >> lower;
    cout << "Now, what's that higher number?" <<endl;
    cin >> higher;

    while(lower <= higher){
        cout << lower <<endl;
        lower++;
    }

}

int main()
{
    //e190();
    //e110();
    e111();

    return 0;
}