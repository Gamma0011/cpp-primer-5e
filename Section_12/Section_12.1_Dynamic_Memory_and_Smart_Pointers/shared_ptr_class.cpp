#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <memory>

/*
    | THE shared_ptr CLASS |
        Smart pointers are templates and therefore require a type to which the pointer can point. As with vectors,
         we supply the type inside of angled brackets that follow the name of the kind of smart pointer we're defining:

         std::shared_ptr<std::string> p1;       // shared_ptr that can point to a string
         std::shared_ptr<std::list<int>> p2;    // shared_ptr that can point to a list of ints
        
        A default initialized smart pointer holds a null_ptr. When we used a smart pointer in a condition, the effect is
         to test whether the pointer is null.
         ex. void smart_null();

    | OPERATIONS SPECIFIC TO shared_ptr |
    make_shared<T>(args)    - Returns a shared_ptr pointing to a dynamically allocated object of type T. Uses args to initialize object
    shared_ptr<T>p(q)       - p is a copy of the shared_ptr q. Increments the count in q. Point in q must be convertible to T*
    p = q                   - p and q are shared_ptrs holding pointers that can be converterted to one another. Decrements p's reference
                                count and increments q's count; deletes p's existing memory if p's count goes to 0
    p.unique()              - Returns true if p.use_count() is 1. Otherwise false
    p.use_count()           - Returns # of objects sharing with p; may be slow operation. Intended for debugging

    | OPERATIONS COMMON TO shared_ptr AND unique_ptr |
    shared_ptr<T> sp        - Null smart pointer that can point to objects of type T
    unique_ptr<T> up        - Null smart pointer that can point to objects of type T
    p                       - Use p as a condition; true if p points to an object
    *p                      - dereference p to get object to which p points
    p->mem                  - Synonym for (*p).mem
    p.get()                 - Returns the pointer to p. Use caution; the object to which the returned pointer points will
                                disappear when the smart pointer deletes it.
    swap(p,q)               - Swaps the pointers in p and q.
    p.swap(q)               - Swaps the pointers in p and q.


    | THE make_shared FUNCTION |
        The safest way to allocate and use dynamic memory is to call a library function named make_shared
        This allocates and initializes an object in dynamic memory and returns a shared_ptr that points to that object.

        If we do not pass any arguments, then the object is value initialized.

        ex. void makeSharedFunction();

        | COPYING AND ASSIGNING shared_ptrs |
            When we copy or assign a shared_ptr, each shared_ptr keeps track of how many other shared_ptrs point to the same object.
            ex. void copyingSharedPtrs();

            We can think of a shared_ptr as if it has an associated counter, usually referred to as a reference count. Whenever
             we copy a shared_ptr, the count is incremented. The count is decremented when we assign a new value to the shared_ptr
             and when the shared_ptr itself is destroyed, such as when a local shared_ptr goes out of scope.

            Once a shared_ptr's counter goes to ZERO, shared_ptr automatically frees the object it manages.
            ex. void freeingSharedPtrs();

        The class keeps track of how many shared_ptrs point to the same object and automatically frees that object when appropriate.

        | shared_ptrs AUTOMATICALLY DESTROY THEIR OBJECTS | 
            When the last shared_ptr pointing to an object is destroyed, the shared_ptr class automatically destroys the object
             to which that shared_ptr points. It does so through a member function known as a DESTRUCTOR. Destructors generally
             free the resources that an object has allocated. The destructor for shared_ptr decrements the reference count
             of the object to which that shared_ptr points. When the count == 0, destructor destroys the object to which shared_ptr
             points and frees memory used previously by that object.

             ex. // FREEING DYNAMIC MEMORY //

             You should be sure to ERASE shared_ptr elements once you no longer need them.

        **NOTE** If you put shared_ptrs in a container, and you subsequently need to use some, but not all of the elements,
                remember to ERASE the elements you no longer need.

        | CLASSES WITH RESOURCES THAT HAVE DYNAMIC LIFETIME |
            Programs tend to use dynamic memory for one of three purposes:
                1. They don't know how many objects they'll need.
                2. They don't know the precise type of the object they'll need.
                3. They want to share data between several objects.

            So far, the classes we've used allocate resources tht exist only as long as the corresponding objects.
             For example, each vector "owns" its own elements. When we copy a vector, the elements in the original vector
             and in the copy are separate. The elements allocated by a vector exist only while the vector itself exists.
             When a vector is destroyed, the elements in the vector are destroyed.

        ** One common reason to use dynamic memory is to allow multiple objects to share the same state **

*/

void smart_null() {
    std::shared_ptr<std::string> p1;

    if(p1 && p1->empty()) {         // if p1 not null, check whether it's the empty string
        *p1 = "Hello world";        // if so, dereference p1 to assign a new value to that string
    }
}

void makeSharedFunction() {
    // shared_ptr that points to an int with value 42
    std::shared_ptr<int> p3 = std::make_shared<int>(42);
    // p4 points to a string with value 9999999999
    std::shared_ptr<std::string> p4 = std::make_shared<std::string>(10, '9');
    // p5 points to an int that is value-initialized to 0
    std::shared_ptr<int> p5 = std::make_shared<int>();
    // p6 points to a dynamically allocated, empty vector<string>
    auto p6 = std::make_shared<std::vector<std::string>>();
}

void copyingSharedPtrs() {
    auto p = std::make_shared<int>(42);     // object to which p points has one user
    auto q(p);                              // object to which p and q point has two users
}

void freeingSharedPtrs() {
    auto p = std::make_shared<int>(42);     // object to which p points has one user
    auto q(p);                              // object to which p and q point has two users
    auto r = std::make_shared<int>(42);     // int to which r points has 1 user
    r = q;                                  // assign q to r, pointing it to object to which q points. r has 0 users, object to which q points has 3 users
                                            // the object r had pointed to no longer has users; object automatically deleted
}

// FREEING DYNAMIC MEMORY //

// factory returns a shared_ptr pointing to a dynamically allocated object
std::shared_ptr<int> factory(int i) {
    // process args as appropriate
    // shared_ptr will take care of deleting this memory;
    return std::make_shared<int>(i);
}
void use_factory(int i) {
    std::shared_ptr<int> p = factory(i);
    // use p
    // p goes out of scope; the memory to which p points is automatically freed
}
std::shared_ptr<int> use_factory_return(int i) {
    std::shared_ptr<int> p = factory(i);
    return p;                               // p out of scope, but since it's being used elsewhere, memory is not freed
}

int main() 
{
    //smart_null();


    return 0;
}