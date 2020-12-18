#include <iostream> 
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istream;
using std::ostream;

/*
e716 - what, if any, are the contraints on where and how often an access specifier may appear inside a class definition?
        what kind of members should be defined as a public specifier, what kinds should be private?
    - no constraints on how often, the only thing to note is that struct defaults to public and class defaults private
    - members that have to be accessed outside of the class must be specified to be public
    - members only needing to be used within the class can be private

e717 - what, if any, are the difference between class and struct
    - class, access specifier defaults to private
    - struct, access specifider defaults to public

e718 - what is encapsulation, why is it useful?
    - Encapsulation is an object oriented programming approach that hides data by assigning access levels. This prevents users from accessing or modifying the implementation

    - Data encapsulation is a mechanism of bundling the data, and the functions that use them and data abstraction is a mechanism of exposing only 
        the interfaces and hiding the implementation details from the user.

e719 - indicate which members of your person class you would declare as public and which you would declare private
    - name and address strings can be declared private since they'll only be accessible within the class.
    - everything else can be public

e720 - when are friends useful? discuss the pros and cons of friends
    - useful when we want functions outside of the class to access members and member functions of the class
    - readability, which allows us to know exactly which functions refer to and access which class

    - cons - double information on class (friend declaration, then actual function definition later in program)
    - lesses encapsulation as friends can access all private and public members of a class

e721 - see practice.cpp

e722 - update your Person class to hide it's implimentation | see below

*/

class Person {
friend istream &read(istream &, Person &);
friend ostream &print(ostream &, Person &);
private:    
    string name;
    string address;
public:
    Person() = default;             // default constructor; explicit initialization of empty strings
    Person(string n, string a) : name(n), address(a) { } ;
    string pName() const {
        return name;
    }
    string pAddress() {
        return address;
    }
};

istream &read(istream &is, Person &human) {
    cout << "Enter name, address: ";
    is >> human.name >> human.address;
    return is;
}

ostream &print(ostream &os, Person &human) {
    os << "Name: " << human.name << '\n'
       << "Address: " << human.address <<endl;
    return os;
}


int main()
{
    Person stefan("stefan", "sussex");


    return 0;
}
