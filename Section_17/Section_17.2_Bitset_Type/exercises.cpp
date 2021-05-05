#include <iostream>
#include <string>
#include <bitset>

/*
    e17.9    - Explain the following bit pattern that each of the following bitsets contains.

    e17.10  - Using sequence 1,2,3,5,8,13,21 initialize a bitset that has 1 bit in each position for the corresponding number.
                Default initialize another bitset and write a small program to turn on each of the appropriate bits.

                see. void e1710() and bool check_size()

    e17.11  - Define a data structure that contains an integral object to track responses to true/false quiz containing 10 questions. What changes
                would you make if the structure of the quiz had 100 questions?

*/

void e179(){
    std::cout << std::bitset<64>(32) << std::endl;      // 32 is of type int, which is 16 bits. remaining high-orders will be 0.
    std::cout << std::bitset<32>(1010101) << std::endl; // binary of 1010101 written into bitset. Even though it exceeds int max value, it doesn't matter here
    std::string bstr;
    std::cin >> bstr;
    std::cout << std::bitset<8>(bstr) << std::endl;     // bstr must have values of 0 or 1. If # of char > 8, then high orders are discarded. 
}

bool check_size(std::size_t n1, std::size_t n2, std::size_t t) {
    if (n1+n2 > t) {
        return false;
    } else {
        return true;
    }
}

void e1710() {
    std::bitset<32> bits;
    std::pair<std::size_t, std::size_t> nums(0,1);
    std::size_t sum;

    while(check_size(nums.first, nums.second, bits.size())) {
        sum = nums.first + nums.second;
        bits.set(sum);   // turn on bit
        nums.first = nums.second;
        nums.second = sum;     
    }
    std::cout << bits << std::endl;

}

// steps: ask for t or f, convert t or f to 1 0. Write up to size. Return error if cin != t or f

struct Test_Grades {
    Test_Grades() = default;

    void enter_answers() {
        char c;
        for (std::size_t count = 0 ; count != user_answers.size() ; ++count) {
            std::cout << "Please enter Student's answer for Question #" << count+1 << "\n(T/F): ";
            std::cin >> c;
            if (c == 'T' || 't') {
                user_answers.set(count);
            }
            if (c == 'F' || 'f') {
                user_answers.reset(count);
            }
            else {
                std::cerr << "ERROR: Invalid character. Please only use T or F." << std::endl;
            }
        }
        std::cout << user_answers << std::endl;
        std::cout << master_answers << std::endl;
    }

    void check_answers() {
        std::size_t number_correct;
        for(std::size_t count = 0 ; count != master_answers.size() ; ++count) {
            if (master_answers.test(count) == user_answers.test(count)) {
                ++number_correct;
            }
        }
        std::cout << "Total Correct: " << number_correct << " out of " << master_answers.size() << std::endl;
    }

private:
    std::bitset<10> master_answers{"0110100101"};
    std::bitset<10> user_answers;
};

void e1711() {
    Test_Grades student1;
    student1.enter_answers();
    student1.check_answers();
}

int main()
{
    //e179();
    //e1710();
    e1711();

    return 0;
}