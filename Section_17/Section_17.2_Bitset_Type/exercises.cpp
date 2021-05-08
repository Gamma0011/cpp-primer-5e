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

                You would have to increase the bitset from 10 to 100 and also define all answers in the master_answers bitset.

    e17.12  - Using the data structure from the previous question, write a function that takes a question number and a value to indicate true/false and update quiz accordingly.
                see struct Test_Grades;
    
    e17.13  - Write an integral object that contains the correct answer for the true/false quiz. Use it to generate grades on the quiz.
                see. all of struct Test_Grades;
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

    void check_answers() {
        std::size_t number_correct = 0;
        for (std::size_t count = 0 ; count != master_answers.size() ; ++count) {
            if (master_answers[count] == user_answers[count]) {
                ++number_correct;
            }
        }
        std::cout << "Total Correct: " << number_correct << " out of " << master_answers.size() 
                  << " | " << pass_fail_check(number_correct, master_answers.size()) << std::endl;
    }

    void enter_answers() {
       std::string s;
       for (std::size_t count = 0 ; count != user_answers.size() ; ++count) {
            std::cout << "Please enter answer to question #" << count+1 << ": ";
            std::cin >> s;
            s == "t" ? user_answers.set(count) : user_answers.reset(count);
            user_answers[count] == master_answers[count] ? 
                    std::cout << "Correct" << std::endl  :
                    std::cout << "Incorrect" << std::endl;  
       }
   }

private:
    const std::bitset<10> master_answers{"0000100101"};
    std::bitset<10> user_answers;

    std::string pass_fail_check(std::size_t correct, std::size_t total) {
        if (correct >= (total*0.7)) {
            return "Pass";
        }
        return "Fail";
    }
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