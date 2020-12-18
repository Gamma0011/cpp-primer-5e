#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    constexpr size_t sz = 5;
    int arr[sz] = {1,2,3,4,5};
    int *ip = arr;                  // equal to int *ip = &arr[0];
    int *ip2 = ip + 4;              // ip2 points to arr[4], the last element in arr;


    // ok: arr is converted to a pointer to its first element; p points one past the end of arr
    int *p = arr + sz;              // use caution, do not dereference | int *p = &arr[0] + 5;
    int *p2 = arr + 10;             // error: arr has only 5 elements, p2 has undefined value
    

    auto n = std::end(arr) - std::begin(arr);     // n is 5, the number of elements in arr
    cout << n <<endl;



    int *b = arr, *e = arr + sz;   
    while (b < e){
        // use *b
        cout << b <<endl;
        ++b;
    }

    int ia[] = {0,2,4,6,8};     // array with 5 elements of type int
    int last = *(ia + 4);       // ok, initializes last to 8, the value of ia[4];
    int last = *ia + 4;         // initializes ia[0] to int 4;

    int i = ia[2];              // i is converted to *ia[0], ia[2] fetches the element to which ia+2 points
    int *ptr = ia;              // ptr points to first element of ia
    i = *(ptr +2);              // i = *(ia[0] + 2), or i = ia[2]


    int *ptr2 = &ia[2];         // p points to the element indexed by 2
    int j = ptr2[1];            // ptr2[1] = *(ptr + 1); ptr[1] is same as ia[3];
    int k = ptr2[-2];           // k = ia[0];


    return 0;
}