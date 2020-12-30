#include <iostream>
#include <vector>
#include <string>
#include <memory>

/*
    Programs that use expection handling to continue processing after an exception occurs need to ensure that resources are
     properly freed if an exception occurs. One easy way to make sure resources are freed is to use smart pointers. When we use
     a smart pointer, the smart pointer class ensures that memory is freed when it is no longer needed, even if the block
     is exited prematurely.

     ex. void f1();

        Conversely, any function using built-in pointers that throws an exception before function is exited will not free memory.
            ex. void f2();

    | SMART POINTERS AND DUMB CLASSES |
        Classes that allocate resources - and that do not define destructors to free those resources - can be subject to the 
        same kind of errors that arise when we use dynamic memory. It is easy to forgot to release the resource

        ex. // smart pointers and dumb classes comment

    || TO USE SMART POINTERS CORRECTLY ||
    1. Don't use same built-in pointer value to initialize or reset more than 1 smart pointer
    2. Don't delete the pointer returned from get()
    3. Don't use get() to initialize or reset another smart pointer
    4. If you use a pointer returned by get(), remember that pointer will become invalid when the last corresponding smart pointer goes away
    5. If you use a smart pointer to manage a resource other than memory allocated by new. Pass a deleter. shared_ptr<>(ptr, deleter) 

*/

void f1() {
    std::shared_ptr<int> sp(new int(1024));     // allocate a new object.
    // code that throws an exception that is not caught inside of f
}   // shared_ptr freed automatically when function ends

void f2() {
    int *ip = new int(42);      // dynamically allocate a new object
    // code throws exception that is not caught inside of f
    delete ip;                  // free memory before exiting
}

/* smart pointers and dumb classes
struct destination;         // represents what we are connecting to
struct connection;          // information needed to use connection
connection connect(destination*);   // open connection;
void disconnect(connection);        // close given connection;
void f(destination &d) {
    // get a connection; must remember to close when done.
    //connection c = connect(&d);
    // use connection
    // if we forget to call disconnect before exiting f, there is no way to close c
}

void end_connection(connection *p) { disconnect(*p); }

// using shared_ptr
void f(destination &d) {
    connection c = connect(&d);
    shared_ptr<connection> p(&c, end_connection);
    // use connection
    // when f exits, even by exception, the connection wil be properly closed
}

*/

int main()
{


    return 0;
}