#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>

void alg_int_practice() {
    std::vector<int> vec = {0,1,2,3,2,5,6,7};
    int val = 42;       // val we're looking for
    // result will denote the element we want if it's in vec, or vec.cend() if not
    auto result = find(vec.cbegin(), vec.cend(), val);

    std::cout << "The value " << val
              << (result == vec.cend() ? " is not present." : " is present.") <<std::endl;
}

void alg_str_practice() {
    std::list<std::string> lst = {"This is a test.", "hello world", "HELLO WORLD!"};
    std::string s("hello world");

    auto result = find(lst.cbegin(), lst.cend(), s);

    std::cout << "The word: '" << s << "'" 
              << (result == lst.cend() ? " is not present." : " was found.") <<std::endl;
}

void alg_array_practice() {
    int ia[] = {27, 210, 12, 47, 109, 83};
    int val = 83;
    int *result = std::find(std::begin(ia), std::end(ia), val);
    // search elements from ia[1] and up to, but not including ia[4]
    auto result2 = std::find(ia+1, ia+4, val);

    std::cout << "The number " << val
              << (result == std::end(ia) ? " was not found." : " was found.") <<std::endl; 

    std::cout << "The number " << val
              << (result2 == (ia + 4) ? " was not found in that range." : " was found in that range.") <<std::endl; 
}

int main()
{
    alg_int_practice();
    alg_str_practice();
    alg_array_practice();

    return 0;
}
