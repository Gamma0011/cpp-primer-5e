#include <iostream>
#include <vector>
#include <string>
#include <memory>

/*
    | UNIQUE_PTR |
        A unique_ptr "owns" the object to which it points. Unlike shared_ptr, only one unique_ptr at a time can point to a given object.
         Unlike shared_ptr, there is a no make_shared function that returns a unique_ptr. To define a unique_ptr, we bind it to a pointer
         returned by new using direct initialization:

            std::unique_ptr<double> p1;             // unique_ptr that can point to a double
            std::unique_ptr<int> p2(new int(42));   // p2 points to int with value 42

        Because unique_ptr owns the object to which it points, there is no support for copy or assignment:

            std::unique_ptr<std::string> p1(new std::string("hello"));      
            std::unique_ptr<std::string> p1(p2);                        // error: no copy for unique_ptr;
            p2 = p1;                                                    // error: no assign for unique_ptr;
        
        | UNIQUE_PTR OPERATIONS |
        unique_ptr<T> u1        null unique_ptr points to objects of type T. u1 will use delete to free pointer.
        unique_ptr<T, D> u2     u2 will use a callable object of type D to free pointer
        unique_ptr<T, D> u(d)   null unique_ptr points to objects of type T. uses d, which must be object of type D in place of delete.
        u = nullptr             Deletes the object to which u points, makes u null
        u.release()             Relinquishes control of the pointer u had held. returns the pointer u had held and makes u null
        u.reset()               Deletes object to which u points
        u.reset(p)              If built-in pointer q supplied, makes u point to that object
        u.reset(nullptr)        Makes u null

        Although we cannot copy or assign a unique_ptr, we can transfer ownership from one (nonconst) unique_ptr to another by calling
         release or reset:

            // transfers ownership from p1 to p2
            std::unique_ptr<std::string> p2(p1.release());              // release makes p1 null
            std::unique_ptr<std::string> p3(new std::string("World"));  //
            p2.reset(p3.release());                                     // reset deletes memory to which p2 had pointed

        .release() breaks the connection between a unique_ptr and the object it had been managing. Often, .release() is used to initialize
         or assign another smart pointer. However, if we do not use a smart pointer to hold the return from .release(), our program
         takes over responsibility for freeing that resource:

            p2.release();           // WRONG: p2 won't free the memory and we've lost pointer
            auto p = p2.release();  // ok, but we must remember to delete p;

        || PASSING AND RETURNING UNIQUE_PTR ||
            There is one exception to the rule that we cannot copy a unique_ptr: We can copy or assign a unique_ptr that is about to be destroyed,
             for example, when we return a unique_ptr from a function:

                std::unique_ptr<int> clone(int p) { std::unique_ptr<int> ret(new int(p)); return ret; }

                Since the compiler knows that the object ret is about to be destroyed, it does a special kind of copy.

        || PASSING A DELETER TO UNIQUE_PTR ||
            By default, unique_ptr uses delete to free the object to which unique_ptr points. We can also override the deleter in a unique_ptr. 
             Unique_ptr manages its deleter differently than shared_ptr. Overriding the deleter in a unique_ptr affects the unique_ptr type as well
             as how we construct (or reset) objects of that type. Similar to overriding the comparison operator of an associate container, we must
             supply the deleter type inside of angle brackets as well as the type to which the unique_ptr can point

                // p points to an object of type objT and uses an obj of type delT to free object
                // it will call an object named fcn of type delT
                std::unique_ptr<objT, delT> p(new objT, fcn);

                ex. void f();
*/

void uniqueptrPractice() {
    std::unique_ptr<std::string> p1(new std::string("hello"));
        std::cout << *p1 <<std::endl;
    std::unique_ptr<std::string> p2(p1.release());              // release makes p1 null
        (p1 == nullptr) ? std::cout << "Nullptr" << std::endl : std::cout << *p1 <<std::endl;
    std::unique_ptr<std::string> p3(new std::string("World"));  //
        std::cout << *p3 <<std::endl;
    p2.reset(p3.release());                                     // reset deletes memory to which p2 had pointed, p2 now points to object of p3
        std::cout << *p2 <<std::endl;
}

/*
void f(destination &d) {
    connection c = connection(&d);      // open the connection;
    // when p is destroyed, the connection will be closed
    std::unique_ptr<connection, decltype(end_connection)*> p(&c, end_connection);
    // use connection
    // when f exits, even by an exception, the connection will be properly closed
}
*/

int main()
{
    uniqueptrPractice();

    return 0;
}