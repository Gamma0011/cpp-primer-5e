#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istream;
using std::ostream;

class Person {
public:    
    string name;
    string address;

    Person() = default;             // default constructor; explicit initialization of empty strings

    string pName() const {
        return name;
    }
    string pAddress() {
        return address;
    }

};

int main()
{



    return 0;
}