#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <new>

/*
    || DYNAMIC ARRAYS ||
        The NEW and DELETE operators allocate one object at a time. Objects such as vectors and strings store their elements in contiguous memory and must allocate
         several elements at once whenever the container has to be reallocated. To support such usage, the language and library provide two ways to allocate an array
         of objects at once. The library includes a template class called ALLOCATOR that lets us separate allocation from initialization. Using ALLOCATOR generally
         provides better performance and more flexible memory management.

         When applications need a varying number of objects, it is almost always easier and faster to use a vector (or another library container).

         **NOTE** Most applications should use a library container rather than dynamically allocated arrays. Using a container is easier, less likely to contain 
         memory-management bugs, and is likely to give better performance.

         Classes that allocate dynamic arrays MUST DEFINE THEIR OWN VERSIONS OF THE COPY, ASSIGNMENT, and DESTRUCTION operands to manage objects.

        | NEW AND ARRAYS |
            New allocates number of objects requested in [] and returns a pointer to first object.
                // call get_size to determine how many ints to allocate
                int *pia = new int[std::get_size()];

                The size inside the brackets must have integral type, but need not be const. We can also allocate an array using type alias

                typedef int arrT[42];       // arrT names the type array of 42 ints
                int *pia = new arrT;        // allocates an array of 42 ints; p points to the first one

        | ALLOCATING AN ARRAY YIELDS A POINTER TO THE ELEMENT TYPE |
         When we use NEW to allocate an array, we do not get an object with an array type. Instead, we get a pointer to the element type of the array.
         Because allocated memory does not have an array type, we cannot call .begin() or .end() on a dynamic array. Additionally, we cannot use a range
         for to process elements in "dynamic arrays".

         ex. int *pia = new int[4];     // returns pointer to first element of array, which is a pointer to an int, not a pointer to an array of ints.

        | INITIALIZING AN ARRAY OF DYNAMICALLY ALLOCATED OBJECTS |
         By default, objects allocated by new are default initialized. We can value initialize by following array size with an pair of parentheses. Under C++11,
         we can also provide a braced list of element initializers

         ex.    int *pia = new int[10];                         // ten uninitialized ints
                int *pia2 = new int[10]();                      // ten ints initialized to 0
                string *psa = new string[10];                   // ten empty strings
                string *psa2 = new string[10]();                // ten empty strings
                int *pia3 = new int[10]{0,1,2,3,4,5,6,7,8,9};   // array of ten elements from 0-9
                string *psa3 = new string[10]{"a", "an", string(3,'x')};    // array of ten elements, 3 value initialized, remaining 7 default initialized
        
        For any arrays with value initialized elements below total element count, the remaining are default initialized. If more elements are initialized then declared,
        new throws an exception of type bad_array_new_length. Defined in <new> header

        **NOTE** we cannot use auto to allocate an array.

        | IS IT LEGAL TO DYNAMICALLY ALLOCATE AN EMPTY ARRAY |
            Calling new[n] when n == 0 is legal, even though we cannot create an array variable of size 0. The pointer returned acts as an off-the-end pointer for a zero-element array.
            The pointer cannot be dereferenced as there is no element. 

        | FREEING DYNAMIC ARRAYS |
            To free a dynamic array, we use a special form of delete that includes an empty pair of square brackets:
                
                delete p;       // p must point to a dynamically allocated object or be null
                delete [] pa;   // pa must point to a dynamically allocated array or be null

            If we used a type alias to define an array type, we must use brackets when we delete that array too:

                typedef int ArrT[10];
                int *p = new ArrT;
                delete [] ArrT;
            
            **NOTE** The compiler is unlikely to warn of forgotten brackets when deleting a pointer to an array.
        
        | SMART POINTERS AND DYNAMIC ARRAYS |
            The library provides a version of unique_ptr that can manage arrays allocated by new. To use, we must include a pair of empty brackets after object type.

                ex. std::unique_ptr<int []> up(new int[10]);
                    up.release();                               // automatically uses delete[] to destroy its pointer
            
            The brackets inside of the object type denote that up points to an array of ints and not just an int itself. 

            When a unique_ptr points to an array, we cannot use the . or -> operators since it points to an array and not a single element. However, we can use 
             the subscript operator to access elements in the array.

                see. void uPtrSubScript();

            | UNIQUE_PTRS to ARRAYS |
                unique_ptr<T[]> u       u can point to a dynamically allocated array of type T
                unique_ptr<T[]> u(p)    u points to a dynamically allocated array to which built-in pointer p points. P must be convertible to T*
                u[i]                    Returns the object at position i in array u owns. u must point to an array!

            | SHARED_PTRS and ARRAYS |
             Unlike unique_ptr, shared_ptr have no direct support for managing a dynamic array. If we want to use a shared_ptr, we must provide our own deleter.
             If we neglect to supply a deleter, the code is undefined because the call to delete on the shared ptr is similar to delete rather than delete[]

                see. void sPtrArrays();

             Additionally, since there is no subscript operator for shared_ptrs, the smart pointer types do not support pointer arithmetic. To access elements, we must use
             .get() to obtain a built-in pointer.

                see. void iteratingsPtrArrays();

        
    || THE ALLOCATOR CLASS ||
        An aspect of new that limits its flexibility is that new combines allocating memory with constructing objects in that memory. Delete combines destruction with deallocation.
         Combining initialization with allocation is usually what we want when we allocate a single object. When we allocate a block of memory, we often plan to construct objects
         in that memory as needed. In this case, we'd like to decouple memory allocation from object construction.
        
        Decoupling construction from allocation means we can allocate memory in large chunks, and pay the overhead of constructing objects only when we need to create them.

        Generally, coupling allocation and construction can be wasteful.
            see. void allocConstruct();

            In the example above, we create an array of 10 strings, but we might not need 10 strings. Therefore, we might have created objects that are never used. Additionally,
             for the objects that are used, we immediately assign new values over the previously initialized strings, causing 2 writes - default initialization and when 
             we assign new objects.

             Classes that do not have default constructors cannot be allocated as an array.

        | THE ALLOCATOR CLASS |
            The library allocator class, defined in <memory> header, lets us separate allocation from construction. It provides type-aware allocation of raw, unconstructed memory.
             Like vector, allocator is a template. To define allocator, we must specify the type of objects a particular allocator can allocate. When an allocator object allocates
             memory, it allocates memory that is appropriately sized and aligned to hold objects of the given type.

             std::allocator<std::string> alloc;         // object that can allocate strings
             auto const p = alloc.allocate(2);          // allocate 2 unconstructed strings that are pointed to by p
             alloc.construct(p, "Hello");               // at the memory pointed to by p, initialize string to be "Hello"
             alloc.construct(p+1, "World");             // at memory pointed to by p + 1, initialize string to be "World"
             alloc.destroy(p);                          // destruct object at p (Hello)
             alloc.destroy(p+1);                        // destruct object at p+1 (World)
             alloc.deallocate(p, 2);                    // deallocate storage for p

             Steps:     Create Allocator >> Create Pointer to [allocator].allocate(size) >> [allocator].construct(*, arg) 
                            >> [allocator].destroy(*) >> [allocate].deallocate(*, size);

            | STANDARD ALLOCATOR CLASS AND CUSTOMIZED ALGORITHMS |
            allocator<T> a          defines an allocator object named a that can allocate memory for objects of type T 
            a.allocate(n)           allocates raw, unconstructor memory to hold n objects of type T
            a.deallocate(p, n)      deallocates memory that help n objects in type T starting at address of pointer p; P must be a pointer
                                     previously returned by allocate, and n must be the size requested when p was created. The user must call
                                     destroy on any objects that were constructed in this memory before calling deallocate.
            a.construct(p, args)    p must be a pointer to type T that points to raw memory, args are passed to a constructor for type T, which is
                                     used to construct an object in the memory pointed to by p
            a.destroy(p)            Runs the destructor on the object pointed to by the T* pointer p

            Any size argument passed to deallocate must be the same size used in the call to allocate used to allocate memory to that pointer.            

        | ALGORITHMS TO COPY AND FILL UNINITIALIZED MEMORY |
            As a companion to the allocator class, the library also defines two algorithms that can construct objects in uninitialized memory. 
                Defined in the <memory> header

            || ALLOCATOR ALGORITHMS ||
            uninitialized_copy(b, e, b2)        Copies elements from input range b and e into unconstructed raw memory noted by iterator b2.
            uninitialized_copy_n(b, n, b2)      Copies n elements starting from one denoted by iterator b into raw memory starting at b2.
            uninitialized_fill(b, e, t)         Constructs objects in the range of raw memory denoted by iterators b and e as a copy of t
            uninitialized_fill_n(b, n, t)       Constructs an unsigned number n objects starting at b. b must denote unconstructed raw memory > # inserted objects

            see. allocAlgPractice();
*/

std::size_t get_size() { return 10; }

void allocateEmptyArray() {
    std::size_t n = get_size();
    int* p = new int[n]{0,1,2,3,4,5,6,7,8,9};
    for (int *q = p; q != p + n ; ++q) { std::cout << *q <<'\t';}
    delete [] p;
    std::cout << "Memory Deallocated." <<std::endl;
}

void uPtrSubScript() {
    std::unique_ptr<int []> up(new int[10]{0,1,2,3,4,5,6,7,8,9});
    for (int i = 0; i != 10; ++i) { std::cout << up[i] << ' '; }
    up.release();
    std::cout << "unique_ptr up released." <<std::endl;
}

void sPtrArrays() { 
    // to use a shared_ptr, we must supply a deleter
    std::shared_ptr<int[]> sp(new int[10], [](int *p) { delete [] p; });
    sp.reset();         // uses the lambda we supplied that uses delete[] to free the array
}

void iteratingsPtrArrays() {
    std::shared_ptr<int[]> sp(new int[10], [](int *p){ delete [] p; });
    // for (std::size_t i = 0; i != 10; ++i) { sp[i] = i; }                 // wrong but works?
    for (std::size_t i = 0; i != 10; ++i) { *(sp.get() + i) = i; }          // way the book recommends
    for (std::size_t i = 0; i != 10; ++i) { std::cout << sp[i] <<' '; }
    std::cout << "Deallocating sp." <<std::endl;
    sp.reset();
}

void allocConstruct() {
    std::string *const p = new std::string[10];     // construct 10 empty strings
    std::string s;
    std::string *q = p;                                 // q points to p[0]

    while (std::cin >> s && q != p + 10) { *q++ = s; }

    const std::size_t size = q - p;                     // remember how many strings we read
    delete [] p;
}

void allocPractice() {
    std::allocator<std::string> alloc;
    auto const p = alloc.allocate(10);
    auto q = p;                 // q will point to one past the last constructed element
    alloc.construct(q++);       // *q is an empty string
    //alloc.construct(++q, 10, 'c');  // *q is cccccccccc
    //alloc.construct(++q, "hi");     // *q is hi

    std::cout << *q <<std::endl;
    // std::cout << *p <<std::endl;     // disaster, q points to unconstructed memory

    while (q != p) {
        alloc.destroy(--q);             // free the strings we allocated
    }

    alloc.deallocate(p, 10);            // free memory
}

void allocAlgPractice() {
    // copy vector of ints into dynamic memory
    std::vector<int> vi = {0,1,2,3,4,5,6,7,8,9};

    // allocate 2x many elements as vi holds
    std::allocator<int> alloc;
    auto p = alloc.allocate(vi.size() * 2);

    // construct elements starting at p as copies of elements in vi
    auto q = std::uninitialized_copy(vi.begin(), vi.end(), p);      // q is an iterator to one past the last element copied into p

    // initialize the remaining elements to 42
    std::uninitialized_fill_n(q, vi.size(), 42);

}

int main()
{
    // allocateEmptyArray();
    // uPtrSubScript();
    //iteratingsPtrArrays();
    //allocPractice();


    return 0;
}