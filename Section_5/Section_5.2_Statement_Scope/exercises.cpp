#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void e54()
{
    // explain each of the following examples and correct any problems


    // 1) while (string::iterator iter != s.end())
    // ^^^should be:

    // std::string::iterator iter = s.begin();
    // while (iter != s.end())


    // 2) while (bool status = find(word))
    //       if (!status)

    // status must be declared outside of while scope
    // bool status;
    // while (bool status = find(word));
    // if (!status);



}

int main()
{


    return 0;
}
