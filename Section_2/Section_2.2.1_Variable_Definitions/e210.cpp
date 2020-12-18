#include <iostream>



std::string global_str;         // declaration of string variable global_str. Outside function, compiler sets as empty
int global_int;                 // declaration of int variable global_int. Outside function, compiler sets as 0

int main()
{
    int local_int;              // declaration of int variable, inside function, assigned 0.
    std::string local_str;      // declaration of string variable, inside function, assigned empty.

    std::cout << " Global Str: " << global_str <<std::endl;
    std::cout << " Global Int: " << global_int <<std::endl;
    std::cout << " Local Str: " << local_str <<std::endl;
    std::cout << " Local Int: " << local_int <<std::endl;

    return 0;
}
