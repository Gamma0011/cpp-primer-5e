#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


void e330(){
    // identify the errors in this code
    constexpr size_t array_size = 10;           // legal, no issues
    int ia[array_size];                         // legal array declaration and initialization ia[10], 10 buckets of 0;

    for (size_t ix = 1; ix <= array_size; ++ix){        // when ix == 10, 
        ia[ix] = ix;                                    // ia[ix] becomes unbuffered because ia[10] does not exist, only ia[0-9] does.
    }

    for (auto i : ia){
        cout << i <<endl;
    }
}

void e331(){
    // write a program to define an array of 10 ints;
    // give each element the same value as its position in the array

    constexpr size_t num = 10;
    int iarray[num];

    for(size_t counter = 0; counter < num; ++counter){
        iarray[counter] = counter;
    }
    for(auto i : iarray){
        cout << i << " ";
    }
}


void e332(){
    // write a program to define an array of 10 ints;
    // give each element the same value as its position in the array
    // REWRITE USING VECTORS

    constexpr int limit = 42;
    vector<int> ivec;               // 42 elements, default-initialized

    for(auto counter = 0; counter < limit; ++counter){
        ivec.push_back(counter);
    }
    for(auto i : ivec){
        cout << i << " ";
    }
}

void e333(){
    // what would happen if we did not initialize the scores array in program in 116?

    // Depends on what was uninitialzed. Not declaring dimension would result in error when trying to use unsigned scores as an array and not an unsigned int;
    //  conversely, if we didn't initialize the values of each element, they would remain default-initialized


}

int main()
{

    //e330();
    //e331();
    e332();

    return 0;
}