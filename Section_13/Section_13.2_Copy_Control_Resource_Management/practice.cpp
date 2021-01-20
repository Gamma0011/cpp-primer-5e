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

            | VALUELIKE COPY-ASSIGNMENT OPERATOR |
                When possible, we should write our own assignment operators so that they will leave the left-hand operand in a sensible
                 state should an exception occur.
                In this case, we can handle self-assignment -- and make our code safe should an exception happen -- by first copying the
                 right-hand side. After the copy is made, we'll free the left-hand side and update the pointer to point to the newly allocated string

                see. HasPtr& operator=(const HasPtr &);

                The first line of the copy-assignment operator is doing the work of the copy constructor ( auto newp = new std::string(*rhs.ps); ) 
                 As in the destructor, we (delete ps), the string to which ps currently points. We then copy the pointer to the newly allocated string
                 and the int value.

        **IMPORTANT**
        There are 2 points to keep in mind when you write an assignment operator
            1.  Assignment operators must work correctly if the object is assigned to itself.
            2. Most assignment operators share work with the destructor and copy constructor.
        
        A good pattern to use when writting assignment operator:
            1. Copy the right-hand operator into local temp
            2. After copying, destroy existing left-hand operand.
            3. Once left-hand operand destroyed, copy data from temp to left-hand operand


        | DEFINING CLASSES THAT ACT LIKE POINTERS |
            For our class to act like a pointer, we need the copy constructor and copy-assignment operator to copy the pointer member, 
             not the string to which the pointer points. Our class will need its own destructor to free the memory allocated by the constructor
             that takes a string.
            
            The easiest way to make a class act like a pointer is to use shared_ptr to manage the resources in the class. Copying (or assigning)
             a shared_ptr copies the pointer to which the shared_ptr points. The shared_ptr itself keeps track of how many users are sharing the pointed-to
             object. When == 0, memory is freed.

            In cases where we want to manage a resource directly, it's useful to use reference count.

        
            REFERENCE COUNTING WORKS AS FOLLOWS:
                - In addition to initializing the object, each constructor creates a counter. This counter will keep track of how many objects share state with the object we're creating.
                  When we create an object, we initialize counter to 1;
                - Copy constructor does not allocate a new counter; instead, it copies the data members of its given object, including the counter. The copy constructor increments shared counter,
                  indicating there is another user of object's state.
                - The destructor decrements the counter, indicating that there is one less user of shared state. If count == 0, destructor deletes state.
                - Copy-assignment operator increments right-hand operand's counter and decrements left-hand's. If counter for left-hand == 0, no more users. Copy-assignment operator must
                  destroy the state of left-hand operand.
                

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

HasPtr& HasPtr::operator=(const HasPtr&rhs) {
    auto newp = new std::string(*rhs.ps);       // copy the underlying string
    delete ps;                                  // free old memory
    ps = newp;                          
    i = rhs.i;
    return *this;                               // return the object
}


class HasPtrPointerlike {
public:
    // constructor allocates a new string and a new counter, which it sets to 1
    HasPtrPointerlike(const std::string &s = std::string()) : ps(new std::string(s)), use( new std::size_t(1)), i(0) { };
    // copy constructor copies all three data members and increments counter
    HasPtrPointerlike(const HasPtrPointerlike &hppl) : ps(hppl.ps), i(hppl.i), use(hppl.use) { ++*use; };
    HasPtrPointerlike& operator=(const HasPtrPointerlike &);
    ~HasPtrPointerlike();
private:
    std::string *ps;
    int i;
    std::size_t *use;           // member to keep track of how many objects share *ps
};

HasPtrPointerlike& HasPtrPointerlike::operator=(const HasPtrPointerlike &rhs) {
    ++*rhs.use;             // increment the use count of the right-hand operand
    if (--*use == 0) {      // decremenet the object's counter
        delete ps;          // if no users, free memory
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

HasPtrPointerlike::~HasPtrPointerlike() {
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}

int main()
{


    return 0;
}