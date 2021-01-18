#include <iostream>
#include <vector>
#include <string>

/*
    || COPY CONTROL AND RESOURCE MANAGEMEN ||
        Ordinarily, classes that manage resources that do not reside in the class must define the copy-control members. 
        Once a class needs a destructor, it most-likely needs a copy constructor and copy-assignment operator.

        In order to define these members, we first have to decide what copying an object of our type will mean. We have 2 choices,
         we can define the copy operations to make the class behave like a:
            1) value            (or)
            2) pointer

            | VALUE |
            Classes that behave like values have their own state. When we copy a valuelike object, 
             the copy and the original are independent. Changes made to the copy have no effect on original, and vice versa.
            
            | POINTER |
            Classes that act like pointers share state. When we copy objects of such classes, the copy
             and the original use the same underlying data. Changes made to the copy also change original, and vice versa.

        Of the library classes we've used, the library containers and string class have valuelike container. The shared_ptr
        class provides pointerlike behavior, as does our StrBlob class. IO types and unique_ptr do not allow copying or assignment,
        they provide neither valuelike nor pointerlike behavior.

        What we do when we copy the pointer member of a class determines whether a class has valuelike or pointerlike behavior.

        | CLASSES THAT ACT LIKE VALUES |
            The provide valuelike behavior, each object has to have its own copy of the resource that the class manages. That means that
             each HasPtr object must have its own copy of the string to which ps points. To implement valuelike behavior:

                - A copy constructor that copies the string, not just the pointer.
                - A destructor that frees the string. 
                - A copy-assignment operator that frees the object's existing string and copy the string from its right-hand operand.

*/


class HasPtr {
private:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { };
    HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i) { };                   // each HasPtr has its own copy of the string to which ps points
    HasPtr& operator=(const HasPtr &);
    ~HasPtr() { delete ps; }

public:
    std::string *ps;
    int i;

};

int main()
{


    return 0;
}