#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void e341()
{
    // write a program to initialize a vector from an array of ints

    int arr[] = {0,1,2,3,4,5,6,7};

    vector<int> ivec(std::begin(arr), std::end(arr));

    for(auto i : ivec){
        cout << i << '\t';
    }
}

void e342()
{
    // write a program to copy a vector of ints into an array of ints
    vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};
    int arr[ivec.end() - ivec.begin()];         // initialize with number of elements in ivec

    for(auto position = ivec.begin(); position != ivec.end(); ++position) {
        arr[*position] = ivec[*position];
    }

    for (auto i : arr) {
        cout << i << endl;
    }
}

void e343()
{
    // write 3 versions of a program to print elements of ia
    // 1: range for to manage iteration
    // 2: ordinary for loop using subscripts
    // 3: ordinary for loop using pointers

    int ia[5][3] = {
        {0,1,2},            // row 1
        {3,4,5},            // row 2
        {6,7,8},            // row 3
        {9,10,11},          // row 4
        {12,13,14}          // row 5
    };

    cout << "Print with Range For Loop:" <<endl;
    for (int(&row)[3] : ia){
        for (int(&col) : row){
            cout << col << " ";
        }
    }
    cout << "\nPrint using Subscripts:" <<endl;
    for (int row = 0; row != 5; ++row){
        for (int col = 0; col != 3; ++col){
            cout << ia[row][col] << " ";
        }
    }
    cout << "\nPrint using Pointers:" <<endl;
    for (int (*row)[3] = ia; row != ia + 5; ++row){
        for (int (*col) = *row; col != *row + 3; ++col)
            cout << *col << " ";
    }
}

void e344() {

    // rewrite using alias

    int ia[5][3] = {
        {0,1,2},            // row 1
        {3,4,5},            // row 2
        {6,7,8},            // row 3
        {9,10,11},          // row 4
        {12,13,14}          // row 5
    };

    cout << "Print with Range For Loop:" <<endl;
    using int_arr = int[3];
    for (int_arr& a : ia){
        for (int b : a){
            cout << b << " ";
        }
    }

    
    cout << "\nPrint using Subscripts:" <<endl;
    for (int row = 0; row != 5; ++row){
        for (int column = 0; column != 3; ++column){
            cout << ia[row][column] << " ";
        }
    }
    
    cout << "\nPrint using Pointers:" <<endl;
    for (int_arr* p = ia; p != ia + 5; ++p){
        for (int *q = *p; q != *ia + 3; ++q){
            cout << *q << " ";
        }
    }
}

void e345()
{
    int ia[4][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11},
        {12,13,14,15}
    };

    // using range for
    cout << "Print with Range For Loop:" <<endl;
    for (auto &r : ia){
        for (auto c : r){
            cout << c << " ";
        }
    }

    // using subscripts
    cout << "\nPrint using Subscripts:" <<endl;
    for (auto r = 0; r != 4; ++r){
        for (auto c = 0; c != 4; ++c){
            cout << ia[r][c] << " ";
        }
    }

    // using pointers
    cout << "\nPrint using Pointers:" <<endl;
    for (auto *p = ia; p != ia + 4; ++p){
        for (auto *q = *p; q != *p + 4; ++q){
            cout << *q << " ";
        }
    }
}


int main()
{
    //e341();
    //e342();
    //e343();
    //e344();
    e345();

    return 0;
}
