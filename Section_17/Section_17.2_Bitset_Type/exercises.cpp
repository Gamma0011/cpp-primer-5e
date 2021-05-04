#include <iostream>
#include <string>
#include <bitset>

/*
    e17.9    - Explain the following bit pattern that each of the following bitsets contains.

*/

void e179(){
    std::cout << std::bitset<64>(32) << std::endl;      // 32 is of type int, which is 16 bits. remaining high-orders will be 0.
    std::cout << std::bitset<32>(1010101) << std::endl; // binary of 1010101 written into bitset. Even though it exceeds int max value, it doesn't matter here
    

    std::string bstr;
    std::cin >> bstr;
    std::cout << std::bitset<8>(bstr) << std::endl;     // bstr must have values of 0 or 1. If # of char > 8, then high orders are discarded. 

}

int main()
{
    e179();

    return 0;
}