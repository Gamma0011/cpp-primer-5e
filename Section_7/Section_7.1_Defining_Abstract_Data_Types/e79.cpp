#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;

// add operations to read and print Person objects

class Person 
{
public:    
    // e75 - provide operations in your class to return the name and address
    // should these be const? Don't have to be, but I think name has a chance of being const since address is likely to change over time
    string pName() const {
        return name;
    }
    string pAddress() {
        return address;
    }

    string name;
    string address;
};

istream &read(istream &is, Person &human) {
    is >> human.name >> human.address;
    return is;
}

ostream &print(ostream &os, Person &human) {
    os << "Name: " << human.name << "\n"
       << "Address: " << human.address <<endl;
    return os;
}


int main()
{



    return 0;
}