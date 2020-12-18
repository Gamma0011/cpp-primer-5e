#include <iostream>
#include <array>

using std::cin;
using std::cout;
using std::endl;
using std::array;
using std::string;

int main()
{
    string nums[] = {"one", "two", "three"};    // array of strings   
    string *s = &nums[0];                       // p points to the first element in nums

    // however, arrays have a special property - in most places, when we use an array, the compiler
    //  automaticallly substitutes a pointer to the first element

    string *s2 = nums;          // equivalent to p2 = &nums[0];

    // one implication of this is that when we use an array as an initializer for a variable defined using auto, the deduced type is a pointer, not an array

    int ia[] = {0,1,2,3,4,5,6,7,8,9};     // ia is an array of ten ints
    auto ia2(ia);                       // ia2 is an int* that points to the first element of ia | same as auto ia2(&ia[0]);
    // ia2 = 42;                        // error: ia2 is a pointer, and we can't assign an int to a pointer


    // this does not happen when we use decltype
    decltype(ia) ia3 = {0,1,2,3,4,5,6,7,8,9};           // ia3 is an array of 10 ints
    // ia3 = p                                          // error: can't assign an int* to an array
    int i = 92;
    ia3[4] = i;                                         // ok: assigns the value of i to an element in ia3
    cout << ia3[4] <<endl;

    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int *p = arr;                       // p points to the first element of arr
    ++p;                                // points to the second element of arr | arr[1]

    // we can use iterators to traverse arrays in the same we traverse vectors
    //  we can obtain the off-the-end pointer by taking the address of the nonexistant element one past the last element of the array
    int *e = &arr[10];                  // 10 doesn't exist because array spans arr[0-9]

    for(int *b = arr; b != e; ++b){
        cout << *b <<endl;              // print elements in arr
    }


    // the new standard makes finding the beginning and end of arrays easier:
    int newarr[] = {0,1,2,3,4,5,6,7,8,9};                   // newarr is an array of ten ints
    int *beg = std::begin(newarr);
    int *end = std::end(newarr);

    int *pbeg = std::begin(arr);
    int *pend = std::end(arr);

    while(pbeg != pend && *pbeg >= 0){
        cout << *pbeg << '\t';
        ++pbeg;
    }


    return 0;
}
