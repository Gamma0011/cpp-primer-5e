#include <iostream>
#include <vector>
#include <string>
#include <memory>

/*
    || WEAK_PTR ||
        A weak_ptr is a smart pointer that does not control the lifetime of the object to which it points. Instead,
         a weak_ptr points to an object that is managed by a shared_ptr. Binding a weak_ptr to a shared_ptr does NOT
         change the reference count of that shared_ptr. The object itself will be deleted even if there are weak_ptrs
         pointing to it - hence the name weak pointer. 

            see. void weakptrPractice();

        Because the object might no longer exist, we CANNOT use a weak_ptr to access its object directly. To access the
         object, we must call the lock function. Lock checks whether the object to the weak_ptr still exists. If so, lock
         returns a shared_ptr to the shared object. As with any other shared_ptr, we are guaranteed that the underlying object
         to which shared_ptr points continues to exist as long as the returned share_ptr exists.
            
            see. if statement in void weakptrPractice();

        | WEAK_PTRS |
        weak_ptr<T> w       Null weak_ptr that can point to an object of type T
        weak_ptr<T> w(sp)   weak_ptr that points to the same object as the shared_ptr sp. T must be convertible to type sp points
        w = p               p can be a shared_ptr or a weak_ptr. After the assignment, w shares ownership with p
        w.reset()           Makes w null
        w.use_count()       The number shared_ptrs that share ownership with w.
        w.expired()         Returns true if w.use_count() is zero. False otherwise.
        w.lock()            If expired == True, returns null shared_ptr. Else returns shared_ptr to object to which w points

        To see how a weak_ptr is useful, look at StrBlobPtr.cpp

*/

void weakptrPractice() {
    auto p = std::make_shared<int>(42);   
    std::weak_ptr<int> wp(p);                           // wp weakly shares with p; use count in p is unchanged
    //p.reset();
    if(std::shared_ptr<int> sp = wp.lock()) {           // true if sp is not null
        std::cout << "P still exists." <<std::endl;     // inside if, sp shared its object with p
    } else {                                            // if p no longer exists, shared_ptr == null
        std::cout << "P no longer exists. wp.lock() returns null." <<std::endl;
    }
}


int main()
{
    weakptrPractice();

    return 0;
}