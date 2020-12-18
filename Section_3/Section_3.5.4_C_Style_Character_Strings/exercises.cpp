#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;


void e337()
{
    // what would the following program do?
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char *cp = ca;
    while (*cp) {
        cout << *cp <<endl;
        ++cp;
    }

    // this program will create character elements of each character in hello, into const char array ca
    // const char pointer cp created and set == ca[0], or 'h'
    //  while *cp != null, loop,
    // print the char at position, newline
    // increment position

    // will cause issues however because no null character present in ca
    //   const char ca[] = {'h', 'e', 'l', 'l', 'o', '\0'} would be better ---- const char ca[] = "hello"; also works
}

void e338() 
{
    // adding pointers is meaningless because pointers are just memory addresses
    //  they cannot be added because it's just a location of where the element pointer to exists in memory
}

void e339()
{
    // write a program that compares two strings;
    //  then write a program to compare the values of two C-Style strings

    // standard string comparisons
    string s1 = "String 1";
    string s2 = "String 2";

    cout << "** Standard String Comparison **" <<endl;
    if (s1 < s2) {
        cout << s1 << " less than " << s2 <<endl;
    } else {
        cout << s1 << " greater than " << s2 <<endl;
    }

    cout << "** C-Style String Comparison **" <<endl;
    const char cs1[] = "C-Style String 1";
    const char cs2[] = "C-Style String 2";

    if (strcmp(cs1, cs2) < 0) {
        cout << cs1 << " less than " << cs2 <<endl;
    } else {
        cout << cs1 << " greater than " << cs2 <<endl;
    }

}


void e340()
{
    // write a program to define two character arrays initialized from string literals
    //  then define a 3rd character array to hold the concatenation of the two arrays
    //   use strcpy and strcat to copy arrays into third

    const char arr1[] = "hello";
    const char arr2[] = "world";
    char arr3[11];

    strcpy(arr3, arr1);
    strcat(arr3, " ");
    strcat(arr3, arr2);

    cout << arr3 <<endl;


}

int main()
{
    //e337();
    //e339();
    e340();

    return 0;
}
