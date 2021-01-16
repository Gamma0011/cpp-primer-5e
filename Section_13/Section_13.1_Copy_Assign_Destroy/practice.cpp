#include <iostream>
#include <vector>
#include <string>

/*
    When we define a class, we specify what happens when objects of the class type are copied, moved, assigned, and destroyed. A class controls these
     operations by defining 5 special member functions:
        1. Copy constructor
        2. Copy-assignment operator
        3. Move constructor
        4. Move-assignment operator
        5. Destructor

    COPY and MOVE constructors define what happens when an object is initialized from another object of the same type. 
    COPY- and MOVE-ASSIGNMENT operators define what happens when we assign an object of class type to another object of that same class type.
    DESTRUCTOR defines what happens when an object of the type ceases to exist.

    Collectively, we refer to these operations as COPY COMMAND.

    If a class does not define all copy-control members, the compiler automatically defines the missing operations. As a result, many classes
     ignore copy control. Sometimes not defining can lead to issues. The hardest part is knowing when to define them.

     Copy control is an essential part of defining any C++ class. Programmers new to C++ are often confused by having to define what happens when objects
      are copied, moved, assigned, or destroyed. This confusion is compounded because if we do not explicitly define these operations, the compiler
      defines them for us - although the compiler-defined versions might not behave as we intend.

    There is no requirement that we define all of these operations: We can define one or two of them without having to define them all. However,
     ordinarily these operations should be thought of as a unit. In general, it is unusual to need one without needing to define them all.

        | CLASSES THAT NEED DESTRUCTORS NEED COPY AND ASSIGNMENT |
            Often, the need for a destructor is more obvious than the need for a copy constructor or copy-assignment operator. If the class needs
            a destructor, it needs a copy constructor and copy-assignment operator.

            In the case of HasPtr, the class allocated dynamic memory in its constructor. Therefore, the class needs to define a destructor to 
             free that memory:

                    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { };        // copy constructor
                    HasPtr& operator=(const HasPtr &hp);                                                    // copy-assignment operator
                    ~HasPtr() { delete ps; }                                                                // destructor

                **IMPORTANT RULES** 
                    1) If we define a destructor, we must also define a copy constructor and copy-assignment operator.
                    3) If a class needs a copy constructor, it almost always needs a copy-assignment operator. However, not always a need for a destructor.

        
        | USING = DEFAULT |
            We can explicitly as the compiler to generate the synthesized versions of the copy-control members by defining them as = default;

            class Sales_data {
            public:
                // copy control; use defaults
                Sales_data() = default;
                Sales_data(const Sales_data&) = default;
                Sales_data& operator=(const Sales_data&);
                ~Sales_data() = default;
            };

            Sales_data& Sales_data::operator=(const Sales_data&) = default;

            When we specify = default on the declaration of member inside of the class, the synthesized function is implicitly inline. If we do not want the 
             synthesized member to be an inline function, we can specify = default on the member's definition.

            **NOTE** We can use = default only on member functions that have a synthesized version.

*/

class HasPtr {
public:
    HasPtr() = default;
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { };
    HasPtr& operator=(const HasPtr &hp) {
        if (ps != hp.ps) {
            auto t = new std::string(*hp.ps);
            ps = t;
        }
        i = hp.i;
        return *this;
    }
    ~HasPtr() { delete ps; }


private:
    std::string *ps;
    int i;

};

int main()
{

    return 0;
}