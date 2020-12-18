#include <iostream>

int main()
{
    int i = 0, &r = i;        // int
    auto a = r;             // int
    
    const int ci = i, &cr = ci; // const int
    auto b = ci;                // const int
    auto c = cr;                // const int
    auto d = &i;                // int *
    auto e = &ci;               // const int *
    const auto f = ci;          // const int
    auto &g = ci;               // const int &

    
    std::cout << "A before = " << a <<std::endl;        // 0 
    a = 42;
    std::cout << "A after = " << a <<std::endl;         // 42
    // i, r, a = 42


    std::cout << "B before = " << b <<std::endl;        // 0
    b = 42;
    std::cout << "B after = " << b <<std::endl;         // 42

    std::cout << "C before = " << c <<std::endl;        // 0
    c = 42;
    std::cout << "C after = " << c <<std::endl;         // 42

    std::cout << "D before = " << d <<std::endl;        // Memory Address of int i
    // d = 42;
    // std::cout << "D after = " << d <<std::endl;      // Error: invalid conversion from int to int*

    std::cout << "E before = " << e <<std::endl;        // Memory Address of const int ci
    // e = 42;
    // std::cout << "E after = " << e <<std::endl;      // Error: Invalid conversion from int to const int*

    std::cout << "G before = " << g <<std::endl;        // 0
    // g = 42;
    // std::cout << "G after = " << g <<std::endl;      // Error: Assignment of read-only reference


    return 0;
}
