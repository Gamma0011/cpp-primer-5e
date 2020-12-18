#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


void e428()
{
    // write a program to print the size of each of the built-in types;

    int i;
    string s;
    bool b;
    char c;
    float f;

    cout << "** Size of **" <<endl;
    cout << "Int: " << sizeof(i) <<endl;
    cout << "String: " << sizeof(s) <<endl;
    cout << "Bool: " << sizeof(b) <<endl;
    cout << "Char: " << sizeof(c) <<endl;
    cout << "Float: " << sizeof(f) <<endl;
}

void e429()
{
    // predict the output of the following code and explain your reasoning
    int x[10];          // x is an array of type int with 10 elements
    int *p = x;         // p is a pointer to the first element of x, or *p = x[0]
    int *r = p;
    cout << sizeof(x)/sizeof(*x) <<endl;        // 40/4 = 10        -- x = 10 elements of type int, therefore 10x4 = 40, dereferenced pointer of x, type int = 4
    cout << sizeof(p)/sizeof(*p) <<endl;        // 8/4 = 2          -- p = 8 is a pointer of type int, *p is a dereferenced pointer of type int = 4
}

void e430()
{
    // using table on 166, parenthesize the following expressions to match default evaluation
    // sizeof x + y         | (sizeof x) + y
    // sizeof p->mem[i]     | sizeof(p->mem[i])
    // sizeof a < b         | (sizeof a) < b
    // sizeof f()           | sizeof f() - returns undefined if void, otherwise returns function return type

}

void e431()
{
    // explain why prefix operator was used (above pg 158) and not postfix, what changes would have to be made?
    // rewrite with postfix;

    // reason: no real reason to use postfix since postfix is required to save original value in addition to inc/dec value.
    //  the compiler can get take care of the extra work needed to save the original value, but with compilated types, it could get stuck.

    // nothing changes with postfix

    vector<int> ivec = {0,1,2,3};

    vector<int>::size_type cnt = ivec.size();

    for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--){
        ivec[ix] = cnt;
        cout << ivec[ix] <<endl;
    }
}

void e432()
{
    // explain the following loop
    constexpr int size = 5;             // size initialized to 5 of type constexpr int
    int ia[size] = {1,2,3,4,5};         // int array ia created and values initialized

    for (int *ptr = ia, ix = 0; ix != size && ptr != ia+size; ++ix, ++ptr) {
        cout << ix <<endl;
    }

    // int pointer ptr initialized to the ia[0], int ia initialized to 0
    // for when ix != 5 and ptr != ia[0] + 5
    // increment ix prefix, increment ptr prefix | ix += 1, ptr[] += 1


}

int main()
{   
    //e428();
    //e429();
    e431();

    return 0;
}
