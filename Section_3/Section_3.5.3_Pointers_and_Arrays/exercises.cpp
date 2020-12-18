#include <iostream>
#include <vector>
#include <array>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


void e334(){
    // p1 and p2 point to elements in the same arry, what does this do? any values that make this code illegal?
    // p1 += p2 - p1;
        // this sets p1 = p2 | p1 = p2 - p1 + p2
        // making p2 more than one outside the range of the array would make it illegal 
}

void e335(){
    // using pointers, write a program to set the elements in an array to zero;

    int arr[5] = {1,2,3,4,5};
    int *b = std::begin(arr), *e = std::end(arr);
    while(b < e){
        *b = 0;
        b++;
    }
    for(auto i : arr){
        cout << i << '\t';
    }
}

void e336(){
    // write a program to compare two arrays for equality.
    // write the same program for vectors.

   
}

bool comparison(int *const a1b, int *const a1e, int *const a2b, int *const a2e){
    if((a1e-a1b) != (a2e - a2b)){
        return false;
    }
    for(int *i = a1b, *j = a2b; (i != a1e) && (j != a2e); ++i, ++j){
        if(*i != *j){
            return false;
        }
    }
    return true;
}


int main()
{
    //e335();

    //e336()
    int arr1[] = {1,2,3,3,5};
    int arr2[] = {1,2,3,4,5};
    if(comparison(std::begin(arr1), std::end(arr1), std::begin(arr2), std::end(arr2))){
        cout << "The two arrays are equal." <<endl;
    } else {
        cout << "The arrays are different." <<endl;
    }


    vector<int> vec1 = {1,2,3,4,5};
    vector<int> vec2 = {1,2,2,4,5};

    if(vec1 == vec2){
        cout << "The vectors are equal." <<endl;
    } else {
        cout << "The vectors are different." <<endl;
    }

    return 0;
}
