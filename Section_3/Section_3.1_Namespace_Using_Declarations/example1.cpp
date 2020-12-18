#include <iostream>

using std::cin;

int main()
{
    int i;
    cin >> i;       // okay: cin is a synonym for std::cin
    std::cout << i; // need to explicitly use cout from namespace std;

    return 0;
}