#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void bitwise()
{
    unsigned char bits = 0223;
    cout << bits <<endl;
    // << and >> shift the bits left and right respectively
    bits << 8;              // bits promoted to int and then shifted left by 8 bits
    bits << 31;             // left shift 31 bits, left-most bits discarded
    bits >> 3;              // right shift 3, 3 right-most bits discarded

    // ~ (NOT operator) generates new value with the bits of the operand inverted;
    ~bits;
    cout << bits <<endl;

    // & (AND)    | (OR)     and  ^ (XOR) generate new values with the bit patterns composed from its two operands;
    unsigned char b1 = 0145;
    unsigned char b2 = 0257;
    cout << b1 << '\t' << b2 <<endl;

    // b1 & b2          the bit is 1 if both operands contain 1; otherwise result is 0;
    // b1 | b2          bit is 1 if either or both operands contain 1;
    // ^ (exclusive or) bit is 1 if either but not both operands contain 1, otherwise result is 0;
}


void bitwise_practice()
{
    unsigned long quiz1 = 0;        // we'll use this value as a collection of bits; long int, has 32 in total and is set to 0 across the board

    // we'd like to be able to set the bit corresponding to student 27, to indicate a pass
    //  we can obtain a value indicating s27 passed by using left-shift operator and an unsigned long int literal 1 (ints only guaranteed 16 bits, not 32)
    
    1UL << 27;          // generate a value with only bit number 27 set

    // this is the same as quiz1 = quiz1 | 1UL << 27;
    quiz1 |= 1UL << 27;     // indicate student 27 has passed

    quiz1 &= ~(1UL << 27);    // turn off the bit


    bool status = quiz1 & (1UL << 27);      // how did student 27 do?
    cout << status <<endl;
}

int main()
{
    //bitwise();
    bitwise_practice();

    return 0;
}
