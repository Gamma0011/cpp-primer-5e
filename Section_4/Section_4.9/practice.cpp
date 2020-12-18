#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// sizeof Operator -- output is const expression and of type size_t, it takes 2 forms
// 1. sizeof (type)
// 2. sizeof expression   -- returns the size of the type given by the expression

class Sales_data{
public:
    int revenue = 10;
};


void sizeofpractice()
{
    Sales_data data, *p;
    sizeof(Sales_data);         // size requires to hold an object of type Sales_data
    sizeof data;                // size of data's type, i.e. sizeof(Sales_data);
    sizeof p;                   // size of a pointer
    sizeof *p;                  // size of the type to which p pointers, i.e. sizeof(Sales_data);
    //sizeof data.revenue();      // size of the type of Sales_data's revenue member;
    sizeof Sales_data::revenue; // alternative way to get the size of revenue;


    int arr[10] = {0,1,2,3,4,5,6,7,8,9};

    // sizeof(ia)/sizeof(*ia) returns the number of elements in ia
    constexpr size_t sz = sizeof(arr)/sizeof(*arr);
    int arr2[sz];
    cout << sz <<endl;
}

int main()
{
    sizeofpractice();

    return 0;
}
