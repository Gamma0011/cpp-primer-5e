#include <iostream>
#include <bitset>

/*
    The bitset class makes it easier to use bit operations and possible to deal with collections of bits that are larger than the largest integral type.

    || DEFINING AND INITIALIZING BITSETS ||
        The bitset class is a class template that, like the array class, has a fixed size. When we define a bitset, we say how many bits the bitset will contain:

            std::bitset<32> bitvec(1U);     // 32 bits; low-order bit is 1, remaining are 0

        The size must be a constexpr. The bits in the bitset are not named, rather are referred to positionally. The bits are numbered starting at 0. 
         Bits starting at 0 are referred to as low-order bits, and those ending at 31 are referred to as high-order bits.

    || INITIALIZING A BITSET FROM AN UNSIGNED VALUE ||
        When we use an integral value as an initialize for a bitset, that value is converted to unsigned long long and is treated as a bit pattern. The bits
         in the bitset are a copy of the pattern. If the bitset > bits in unsigned long, long, the remaining high-order bits are set to 0. If bitset < number of bits,
         then only the low-order bits from the given value are used; the high-order bits beyond the bitset object are discarded.

            *bitvec1 < initializer; higher-order bits are discarded
         std::bitset<13> bitvec1(0xbeef);           // bits are 1111011101111

            *bitvec2 > initializer, high-order bits set to 0
         std::bitset<20> bitvec2(0xbeef);           // bits are 00001011111011101111

            *on machines with 64-bit long long 0ULL is 64 bits of 0, so ~0ULL is 64 ones
         std::bitset<128> bitvec(~0ULL);            // bits 0...64 are 1; 63 to 127 are 0

    || INITIALIZING A BITSET FROM A STRING ||
        We can initialize a bitset from either a string or a pointer to an element in a character array. In either case, the characters represent the bit pattern directly.
         As usual, when we use strings to represent numbers, the characters with the lowest indices in the string correspond to high-order bits, and vise-versa:

            std::bitset<32> bitvec4("1100");        // bits 2 and 3 are 1, all others are 0;

        If the string contains fewer characters than the size of the bitset, the high-order bits are set to 0.

        *NOTE*  Indexing conventions of strings and bitsets are inversely related: the character in a string with the highest subscript (right-most character)
        *       is used to initialize the low-order bit in the bitset (the bit with subscript(0)). When you initialize a bitset from a string, it is essential to remember this.
        
        We do not need to use the entire string as the initial value for the bitset, instead we can use a substring as an initializer.

        std::string str("1111111000000011001101");
        std::bitset<32> bitvec5(str, 5, 4);             // 4 bits starting at str[5], 1100
        std::bitset<32> bitvec6(str, str.size()-4);     // use last 4 characters

    || OPERATIONS ON BITSETS ||
        There are various ways to test or set one or more bits. The bitset class also supports the bitwise operator covered on pg 152. The operators have the same meaning
         when applied to bitset objects as built-in operators have when applied to unsigned operands.

            b.any()         - any bit on b on?
            b.all()         - are all bits on b on?
            b.none()        - no bits on b on?
            b.count()       - number of bit in b that are on            - returns size_t
            b.size()        - constexpr function returns # bits in b    - returns size_t
            b.test(pos)     - returns true if bit on pos is on, false otherwise
            b.set(pos, v)   - sets bits at pos to bool value v. v defaults to true
            b.set()         - turns on all bits on b
            b.reset(pos)    - turns off the bit as pos
            b.reset()       - turns off all bits
            b.flip(pos)     - changes state of bit as pos
            b.flip()        - changes state of all bits
            b[pos]          - Give access to bit in b at pos; if b const, the b[pos] returns bool value true if bit is on
            b.to_ulong()    - Returns UL or ULL with same bit as in b. Throws overflow_error if bit pattern in b won't fit indicated result type
            b.to_ullong()   - 
            b.to_string(zero, one)  - Returns a string representing bit patter in b. Zero and One default to 0 and 1 and are used to represent bits 0 and 1 in b
            os << b         - Prints the bits in b as characters 1 or 0 to os
            is >> b         - Reads characters from is into b. If char != 0 || 1, or b.size(), reading stops

        Several operations - count, size, all, any and none take no arguments. They return info about the state of the bitset.
        Set, reset, and flip change the state of the bitset and are overloaded. In each case, the version that take no arguments applies the given operation to the entire set.

            std::bitset<32> bitvec(1U);     // 32 bits; low order bit is 1, remaining are 0;
            bool is_set = bitvec.any();     // true, 1 bit in set.
            bool is_not_set = bitvec.none();// false, one bit set.
            bool all_set = bitvec.all();    // false.
            size_t onBits = bitvec.count(); // 1
            size_t sz = bitvec.size();      // 32
            bitvec.flip();                  // reverses value of all bits on bitset
            bitvec.reset();                 // all bits off (0)
            bitvec.set();                   // all bits on (1)

            bitvec.flip(0);                 // reverses value of bit at pos 0
            bitvec.set(bitvec.size()-1);    // turn on last bit
            bitvec.set(0, 0);               // turn off bit as pos 0 (first bit)
            bitvec.reset(i);                // turn off bit as pos i
            bitvec.test(0);                 // bitvec[0] == 1 ? TRUE : FALSE

            bitvec[0]   = 0;                // turn off bit as pos 0
            bitvec[31]  = bitvec[0];        // set last bit == first bit
            bitvec[0].flip();               // flip bit as pos 0
            ~bitvec[0];                     // same as above, flip bit at pos 0
            bool b = bitvec[0];             // bitvec[0] == 1 ? TRUE : FALSE

        || RETRIEVING THE VALUE OF A BITSET.

        00000000    = 1 byte, 8 bits

*/

void bitset_practice() {
    std::bitset<32> b;
    
    std::cout << std::bitset<9>(0xbeef) << std::endl;
    std::cout << std::bitset<20>(0xbeef) << std::endl;
    std::cout << std::bitset<128>(~0ULL) << std::endl;
    std::cout << std::bitset<32>("1100") << std::endl;
    std::cout << std::bitset<32>(1U) << std::endl;
    std::cout << b.set(b.size()-1) << std::endl;

}

int main()
{
    bitset_practice();


    return 0;
}