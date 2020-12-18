#include <iostream>
#include <vector>
#include <initializer_list>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::initializer_list;
using std::begin;
using std::end;

// e621 - write a function that takes int and a pointer to an int and returns the larger of the int value or the value to which the pointer points.
// what type should you use for the pointers?
int larger(const int &a, const int *b) {
    if (a > *b) {
        return a;
    } else {
        return *b;
    }
}

// e622 write a function to swap two int pointers;
void swapptr(int* (&a), int* (&b))
{   
    int *tmp = a;
    a = b;
    b = tmp;
}

// e623 write your own version of each of the print functions presented in this section.
// call each of these functions to print i and j as defined: int i = 0, j[2] = {0,1};

// marker
void printmarker(const char *a)
{
    while (a) {         // while no null ptr
        if (*a) {       // while no \0
            cout << *a++ <<endl;
        }
    }
}

void printasstdlibconv(const int *beg, const int *end) {
    while (beg != end) {
        cout << *beg++ << " ";
    }
}

void printpasssizeparameter(const int ci[], size_t size) {
    for (size_t i = 0; i != size; ++i) {
        cout << ci[i] << " ";
    }
}

void passbyreference(int (&arr)[2]) {
    for (auto elem : arr) {
        cout << elem << " ";
    }
}


/* e624
explain the behavior of the following functions. If there are problems, explain and fix

void print(const int ia[10]) {
    for(size_t i = 0; i != 10, ++i) {
        cout << ia[i] <<endl;
    }
}

void print takes a const int *ia, [10] says that ia has 10 elements, but doesn't really mean anything
for creates i of type size_t and assigns it 0;
while i != 10, increment prefix
print ia[i] as i is incremented up to 10;

this technically works, however, it's not the best practice.

// guaranteed to print all values in array 

void print(size_t *beg, size_t *end) {
    while (beg != end) {
        cout << *beg++ <<endl;
    }

}

void print(const int (&ia)[10]) {            //would guarantee specifically arrays with 10 elements passed
    for (auto elem : ia) {
        cout << elem <<endl;
    }
}

*/


/* main: Handling Command-Line Options

    somtimes we need to pass arguments to main. the most common use of arguments to main is to let the user specify
        a set of options to guide the operation of the program. 
        
        For example, assuming our program is an exe called prog, we might pass options:

        prog -d -o ofile data0

        such command-line options are passed to main in two (optional) parameters

        int main(int argc, char *argv[]) {}

        the second parameter, argv, is an array of pointers to C-Style strings. The first, argc, passes # of strings in that array;
        Alternatively, we can define main as: int main(int argc, char **argv) {} indicating that argv points to char*

    assuming command-line:  prog -d -o ofile data0
        argc = 5, argv holds the following c-style strings:
    argv[0] = "prog";
    argv[1] = "-d";
    argv[2] = "-o";
    argv[3] = "ofile";
    argv[4] = "data0";
    argv[5] = 0;    

        ** remember, when you use argv, the user input starts at argv[1], not argv[0], which holds the program's name
*/

// e627 - write a function that takes an initializer_list<int> and produces the sum of the elements in the list

int sum(initializer_list<int> il) 
{
    int total = 0;
    for (const auto &elem : il) {
        total += elem;
    }

    return total;
}

// e628 - in the second version of error_msg that has an ErrCode parameter, what is the type of elem in the for loop?
//  elem has type &string because of reference to elements insideo of initializer_list<string>

// e629 - when you use an initializer_List in a range for, would you ever use a reference as a loop control variable?
// if so, why, if not, why not?
// const& normally best option because normally you would not want to duplicate or change the control variable.

int main()
{
    /* e621
    int i1 = 10, i2 = 19;
    int *ip = &i2;
    cout << larger(i1, ip) <<endl;
    */

    /* e622
    int i1 = 90, i2 = 12;
    int *ptr1 = &i1, *ptr2 = &i2;
    cout << ptr1 << " & " << ptr2 <<endl;
    swapptr(ptr1, ptr2);
    cout << ptr1 << " & " << ptr2 <<endl;
    */

    // e623
    int i = 0, j[2] = {0,1};
    char hw[] = "Hello world!";
    //printmarker(hw);
    //printasstdlibconv(std::begin(j), std::end(j));
    //printpasssizeparameter(j, std::end(j) - std::begin(j));
    //passbyreference(j);

    initializer_list<int> ls = {0,1,2,3};
    cout << sum(ls) <<endl;

    return 0;
}
