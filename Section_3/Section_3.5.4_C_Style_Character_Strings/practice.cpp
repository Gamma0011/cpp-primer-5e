#include <iostream>
#include <cstring>

using std::string;
using std::cin;
using std::cout;
using std::endl;

// C-Style String Functions
// strlen(p)                returns the length of p, not counting the null
// strcmp(p1,p2)            compares p1 and p2 for equality. Returns 0 if p1 == p2, a positive value if p1 > p2 and a negative if p1 < p2
// strcat(p1,p2)            appends p2 to p1, returns p1
// strcpy(p1,p2)            copies p2 into p1, returns p1

int main()
{
    char ca[] = {'c', '+', '+'};        // not null terminated
    cout << strlen(ca) <<endl;          // disaster, ca isn't null terminated


    // C-Style strings compare the pointer values, not the strings themselves
    //  **ca1 and ca2 are character arrays, therefore ca1 = ca1[0], which is a pointer value
    const char ca1[] = "A string example"; 
    const char ca2[] = "A different string";

    // because ca1 & ca2 are pointers, we must use strcmp to compare them as strings, not pointers
    if(strcmp(ca1, ca2) < 0){               // same as string comparison s1 < s2
        cout << "ca1 < ca2" <<endl;
    } else {
        cout << "ca1 > ca2" <<endl;
    }

    // because s1, s2, and largeStr are strings, concatenation works. 
    string s1 = "Another string example";
    string s2 = "A different example";
    string largeStr = s1 + " " + s2;
    cout << largeStr <<endl;

    // ca1 and ca2 cannot do this normally because they are arrays and ca1 + ca2 would add pointers (illegal), not characters

    
    // this is disasterous if size of largeStr miscalculated
    strcpy(largeStr1, ca1);          // copies ca1 into largeStr
    strcat(largeStr1, " ");          // adds a space at the end of largeStr
    strcat(largeStr1, ca2);          // adds ca2 to the end of largeStr
    cout << largeStr1 <<endl;


    return 0;
}
