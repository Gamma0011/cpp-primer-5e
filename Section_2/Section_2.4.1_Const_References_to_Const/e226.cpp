#include <iostream>

int main()
{
    // const int buf;           //illegal, const needs initialization at declaration
    int cnt = 0;

    const int sz = cnt;

    ++cnt;
    std::cout << cnt <<std::endl;

    //++sz;                      //illegal, const int cannot change after initialization


    return 0;
}
