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


        Although the compiler will not complain, it is an error to bind another smart pointer to the pointer returned by .get()
            shared_ptr<int> p(new int(42));     // ref count == 1
            int *q = p.get();                   // ok: don't use q in any way that might delete its pointer
                { // new block
                    // undefined: two independent shared_ptrs point to same memory
                    shared_ptr<int>(q);
                    } // block ends and q is destroyed. memory to which q points freed
                    int foo = *q;           // undefined, memory in which p points freed
            
            ** Use get only to pass access to the pointer to code you know will not delete the pointer. In particular,
                never use get to initialize or assign to another smart pointer. **
            
        || OTHER SHARED_PTR OPERATIONS ||
            The shared_ptr class gives us a few other operation. Reset can be used to assign a new pointer to a shared_ptr
                p = new int(1024);      // error: cannot assign a pointer to a shared_ptr
                p.reset(new int(1024)); // ok; p points to a new object
            
            Like assignment, reset updates the ref count and deletes the object to which p points. Reset is often used
                together with unique to control canges to the object shared among several shared_ptrs.

            Before changing the underlying object, we check whether we're the only user. 
            If not, we make a new copy before making change
                see. void resetFunction();
                
*/

// coordination of smart pointers
void process(std::shared_ptr<int> ptr) { }  // use ptr, then it leaves scope. Entering, ptr ref count == 2, leaving == 1

void resetFunction() {
    std::shared_ptr<std::string> p(new std::string("Hello World!"));
    std::cout << *p <<std::endl;
    std::string newVal(" Hello Universe!");

    if (!p.unique()) {
        p.reset(new std::string(*p));
    }
    *p += newVal;
    std::cout << *p <<std::endl;

}

int main()
{
    // coordination of smart pointers continued...
    std::shared_ptr<int> p(new int(42));        // reference count == 1
    process(p);                                 // copying p increments count, in process reference count == 2
    int i = *p;                                 // ok: reference count is 1

    resetFunction();

    return 0;
}