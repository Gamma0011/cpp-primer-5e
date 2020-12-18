#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{

    int ia[3][4];           // array of size 3; each element is an array of ints of size 4
    
    // array of size 10, each element is a 20-element array whose elements are arrays of 30 ints
    int arr[10][20][30] = {0};      // initialize all elements to 0


    // multidimensional arrays may be initialized by using specialized brackets for each row

    int ib[3][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };
    // alternative, although less readable; int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
    
    // we can also initialize only the first element in each row like this
    int ic[3][4] = {
        {0},
        {1},
        {2}
    };

    // this code only initializes the first row of elements in the array
    int ix[3][4] = {0,1,2,3,4};


    // nested for loops to process elements of multidimensional array

    constexpr size_t rowCnt = 3, colCnt = 4;
    int iarr[rowCnt][colCnt];                   // create multidimension array that can hold 12 elements
    // for each row
    for(size_t i = 0; i != rowCnt; ++i){
        // for each column
        for(size_t j = 0; j !=colCnt; ++j){
            // assign element's positional number
            iarr[i][j] = i * colCnt + j;
        }
    }

    // with C++ 11, we can simplify this

    size_t cnt = 0;
    for (auto &row : iarr){
        for(auto &column : iarr){
            column = cnt;
            ++cnt;
        }
    }

    // we can write a loop using begin and end functions

    // p points to the first array of ia
    for (auto p = std::begin(ia); p != std::end(ia); ++p){
        // q points to first element in inner array of ia
        for(auto q = std::begin(*p); q != std::end(*p); ++q){
            cout << *q << ' ';              // prints int value to which q points
        }
    }

    return 0;
}