#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <map>

// functions
int add(int a, int b) { return a + b; }
int subtract(int a, int b){ return a - b; }

// library function object (directly created in map)
std::multiplies<int> multiply;

// lambda function
auto divide = [](int a, int b){ return a / b; };

// class-object function
struct modus {
    int operator()(int a, int b) {
        return a % b; 
    }
};

int main()
{
    std::map<std::string, std::function<int(int, int)>> binops = {
        {"+", add},
        {"-", subtract},
        {"*", multiply},
        {"/", divide},
        {"%", modus()}
    };

    std::cout << binops["+"](100,10) <<std::endl;
    std::cout << binops["-"](100,10) <<std::endl;
    std::cout << binops["*"](100,10) <<std::endl;
    std::cout << binops["/"](100,10) <<std::endl;
    std::cout << binops["%"](100,10) <<std::endl;



    return 0;
}