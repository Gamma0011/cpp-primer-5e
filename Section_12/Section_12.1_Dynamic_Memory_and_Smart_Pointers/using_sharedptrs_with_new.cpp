#include <iostream>
#include <vector>
#include <string>
#include <new>
#include <memory>

/*
    | USING SHARED_PTRS WITH NEW |
        We do not initialize smart pointers, rather, they are initialized as a null pointer.
         Additionally, we can initialize a smart pointer from a pointer returned by new.

         shared_ptr<double> p1;          // shared_ptr that can point at a double.
         shared_ptr<int> p2(new int(42)) // p2 points to an int with value 42
        
        Smart pointer constructors that take pointers are explicit. Hence, we can not implicitly convert a built-in pointer
         to a smart pointer; we must use direct initialization to initialize a smart pointer:

         shared_ptr<int> p1 = new int(1024);        // error: must use direct initialization;
         shared_ptr<int> p2(new int(1024));         // ok: uses direct initialization

        For this same reason, we cannot implicitly convert a plain pointer in a return statement:
         
         shared_ptr<int> clone(int p) { return new int(p); }                    // error: implicit conversion to shared_ptr<int>
         shared_ptr<int> clone(int p) { return shared_ptr<int>(new int(p)); }   // explicitly create shared_ptr

        By default, a pointer used to initialize a smart pointer must point to dynamic memory because smart pointers
         use delete to free the associated object. 

        !! This is an example of how NOT to use pointers and smart pointers!!
            int *x(new int(1024));          // dangerous, x is point pointer, not smart pointer
            process(x);                     // error: cannot convert int* to shared_ptr<int>
            process(shared_ptr<int> x);     // legal, but memory will be deleted once out of scope
            int j = *x;                     // undefined, x is dangling pointer

            Explained: shared_ptr<int> x reference count drops to 0 after end of process function scope. Therefore, memory
                    for x is freed, making x a dangling pointer.

        || OTHER WAYS TO DEFINE AND CHANGE SHARED_PTRS ||
        shared_ptr<T> p(q)      p manages the object to which the built-in pointer q points; q must point to memory allocated by new
        shared_ptr<T> p(u)      p assumes ownership of the unique_ptr u; make u null
        shared_ptr<T> p(q, d)   p assumes ownership of object to which q points. p will use callable object d in place of delete to free q
        shared_ptr<T> p(p2, d)  p is copy of shared_ptr p2. p uses callable object d instead of delete
        p.reset()               if p is only shared_ptr pointing to object, reset frees p's object to null
        p.reset(q)              if optional pointer q is passed, makes p point to q, otherwise makes p null
        p.reset(q, d)           if d supplied, will call d to free q, otherwise, uses delete to free q    
*/

// coordination of smart pointers
void process(std::shared_ptr<int> ptr) { }  // use ptr, then it leaves scope. Entering, ptr ref count == 2, leaving == 1

int main()
{
    // coordination of smart pointers continued...
    std::shared_ptr<int> p(new int(42));        // reference count == 1
    process(p);                                 // copying p increments count, in process reference count == 2
    int i = *p;                                 // ok: reference count is 1

    return 0;
}