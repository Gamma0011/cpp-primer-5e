#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    const string hexdigits = "123456789ABCDEF";         // creation of hexdigits string
    cout << "Please enter numbers from 0 to 15"
         << " separated by a space. Hit ENTER when done: "
         <<endl;

    string result;                                      // declare string result to hold string of use input characters

    string::size_type n;

    while(cin >> n){
        if(n < hexdigits.size()){
            result += hexdigits[n];
        }
    }
    cout << "Your hex number is: " << result <<endl;

    return 0;
}
