#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
    e14.42  - Using library function objects and adaptors, define an expression to:
                - Count the number of values greater than 1024
                - Find the first string that is =! pooh
                - Multiply all values by 2;
    e14.43  - Using library function objects, determine whether a given int value is divisible by any element
                in a container of ints.
*/

void e1442a(const std::vector<int> &ivec) {
    std::greater_equal<int> GreaterEqual;
    const int value = 1024;
    int count = std::count_if(ivec.begin(), ivec.end(), [&](const int &i){ return GreaterEqual(i, value); });
    std::cout << "Count: " << count <<std::endl;
}

void e1442b(const std::vector<std::string> &svec) {
    std::not_equal_to<std::string> NotPooh;
    const std::string search("pooh");
    auto firstWord = std::find_if(svec.begin(), svec.end(), [&](const std::string &s){ return NotPooh(s, search); });
    std::cout << "First word that isn't \"Pooh\": " << *firstWord <<std::endl;
}

void e1442c(std::vector<int> &ivec) {
    std::multiplies<int> xTwo;
    std::transform(ivec.begin(), ivec.end(), ivec.begin(), [&](int &i){ return xTwo(i, 2); });
    for (auto &i : ivec) { std::cout << i << '\t'; }
    std::cout <<std::endl;
}

void e1443(int i, std::vector<int> ivec) {
    std::modulus<int> DivisibleBy;
    auto count = std::count_if(ivec.begin(), ivec.end(), [&](const int &check){ return !DivisibleBy(i, check); });

    if (count > 0) {
        std::cout << i << " is divisible by " << count << " elements in the container." <<std::endl;
    } else {
        std::cout << i << " IS NOT divisible by " << count << " elements in the container." <<std::endl;
    }
} 

int main()
{
    std::vector<int> ivec = {150, 2048, 1920, 2};
    std::vector<std::string> svec = {"pooh", "pooh", "hello", "pooh", "world"};
    //e1442a(ivec);
    //e1442b(svec);
    //e1442c(ivec);
    
    std::vector<int> elements1 = {3, 4, 7};
    std::vector<int> elements2 = {5, 10, 2, 3, 33, 24};
    e1443(10, elements1);
    e1443(20, elements2);

    return 0;
}