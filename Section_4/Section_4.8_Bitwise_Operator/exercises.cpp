#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

void e425()
{
    // what is the value of ~'q' << 6 on a machine with 32-bit ints and 8 bit chars that uses
    //  Latin-1 character set in which q has the bit pattern 01110001

    // ~ inverts the bit pattern, replacing 0s with 1s and vise-versa.

    // ~'q' = 10001110
    // ~'q' << 6        // bits promoted to int, 32-bit and moved left 6 bits
    // output: 00000000 00000000 00100011 10000000
}

void e426()
{
    // in our grading example, what would happen if we used unsigned int? unsigned long was used
    // not all systems allocate 32 bits for type int, therefore, bit 27 might not have existed. 

    // using type long guarantees that 32 bits exist
}

void e427()
{
    // what is the result of each of these expressions? 
    unsigned long ul1 = 3, ul2 = 7;
    
    // ul1 & ul2     BITWISE AND- comparison of the two expressions. for each bit that == 1 on both operands, 1 is saved to the bit, otherwise, 0 is saved
    // 3 = 00000011, 00000111 -- AND, 00000011
    cout << (ul1 & ul2) <<endl;

    // ul1 | ul2     BITWISE OR- comparison via, as long as 1 operand bit == 1, output of that bit is 1, otherwise, it is 0
    // 3 = 00000011, 00000111 -- OR, 00000111
    cout << (ul1 | ul2) <<endl;

    // ul1 && ul2    LOGICAL AND - ul1 and ul2 exist, therefore, (1) true
    cout << (ul1 && ul2) <<endl;

    // ul1 || ul2    LOGICAL OR - ul1 passes, therefore (1) true, if ul1 failed, ul2 would have to pass, or else expression = false
    cout << (ul1 || ul2) <<endl;

}

int main()
{
    e427();

    return 0;
}
