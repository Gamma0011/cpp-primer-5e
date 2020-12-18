#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void e44()
{
    // parenthesize the folliwng expressions to show how they're evaluated.
    
    cout << "No Parenthesizes: " << 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 <<endl;
    cout << "With Parenthesizes: " << ((12 / 3) * 4) + (5 * 15) + (24 % (4 / 2)) <<endl;

}

void e45()
{
    // determine the results of the following expressions
    
    // (-30 * 3) + (21 / 5) = -90 + 4 = -86
    cout << -30 * 3 + 21 / 5 <<endl;

    // -30 + ((3 * 21) / 5) = -30 + (63 / 5) = -30 + 12 = -18
    cout << -30 + 3 * 21 / 5 <<endl;

    // 30 / 3 * 21 % 5 = ((30 / 3) * 21) % 5 = (10 * 21) % 5 = 210 % 5 = 0
    cout << 30 / 3 * 21 % 5 <<endl;

    // -30 / 3 * 21 % 4 = ((-30 / 3) * 21) % 4 = (-10 * 21) % 4 = -210 % 4 = -2
    cout << -30 / 3 * 21 % 4 <<endl;

}

void e46() 
{
    // write an expression to determine whether an int is even or odd;
    int arr[] = {1,2,3,4,5,6};

    for (auto i : arr){
        if(i % 2 == 0){
            cout << i << " is even." <<endl;
        } else {
            cout << i << " is odd." <<endl;
        }
    }
}

void e47()
{
    // what does overflow mean, show 3 expressions that will overflow.
    // overflow is when a value is computed that is outside the range of values that the specified type can represent

    // example 1, division by 0
    //cout << 10/0 <<endl;

    // example 2, exceeding bits allocated for number
    short short_value = 32768;
    cout << short_value <<endl;

    // example 3, multiplication of short values
    short v1 = 10000;
    short v2 = 5000;

    short v3 = v1*v2;
    cout << v3 <<endl;


}

int main()
{
    //e44();
    //e45();
    //e46();
    e47();

    return 0;
}
