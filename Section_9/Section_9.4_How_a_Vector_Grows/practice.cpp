#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <deque>

/*
    To support fast random access, each vector element is stored contiguously - each element is adjacent to the previous.
     Since elements are contiguous and the size of the container is flexible, consider what must happen when we add an element to
     a vector or a string and if there is no room for the new element and elements MUST be contiguous.
     -The container must allocate new memory to hold the exisiting elements PLUS the new one, move the elements
      from the old location into the new space, add the element, and deallocate the old memory,

      If a vector constantly did memory allocation with each element added, the performance would be very, very slow.

      To avoid the costs, library implementors use allocation strategies that reduce the # of times the container must be reallocated.
      When vector and strings need new memory, these implementations allocate capacity beyond what is immediately needed. The container
      holds this storage in reserve and uses it to allocate new elements as they are added. 
      Thus, there is no need to reallocate the container for each new element.

      A vector grows more efficiently than a list or a deque, even though it must move all elements each time it reallocates memory.
      

        CONTAINER SIZE MANAGEMENT
        c.shrink_to_fit()       - Request to reduce capacity() to equal size()
        c.capacity()            - Number of elements c can have before reallocation is necessary
        c.reserve(n)            - Allocate space for at least n elemenets

        **NOTE** Reserve does not change the # of elements in the container; it affects only how much memory the vector preallocates
                A call to reserve only changes the capacity only if the requested space > current capacity. If > it will allocate at least
                (or more than) the requested amount
                Reserve will never reduce the amount of space a container uses.

    CAPACITY AND SIZE

        .size()     - the number of elements it currently holds
        .capacity() - the number of elements it can hold before more space must be reallocated
*/

void cap_size() {
    std::vector<int> ivec;
    // size should be 0; capacity is implementation defined
    std::cout << "ivec size: " << ivec.size()
              << " | ivec capacity: " << ivec.capacity() <<std::endl;
    
    // give ivec 24 elements
    for (std::vector<int>::size_type ix = 0; ix != 24; ++ix) {
        ivec.push_back(ix);
    }

    // size should be 24, capacity should be >= 24 and is implementation defined
    std::cout << "ivec size: " << ivec.size()
              << " | ivec capacity: " << ivec.capacity() <<std::endl;

    // reserve additional space
    ivec.reserve(50);           // sets capacity to AT LEAST 50; might be more
    std::cout << "ivec size: " << ivec.size()
              << " | ivec capacity: " << ivec.capacity() <<std::endl;

    // fill additional elements in ivec with 0 up to capacity
    while (ivec.size() != ivec.capacity()) {
        ivec.push_back(0);
    }
    std::cout << "ivec size: " << ivec.size()
              << " | ivec capacity: " << ivec.capacity() <<std::endl;

    // add one more element to ivec and check size/capacity
    ivec.push_back(42);
    std::cout << "ivec size: " << ivec.size()
              << " | ivec capacity: " << ivec.capacity() <<std::endl;

    // RETURNING MEMORY, sometimes
    ivec.shrink_to_fit();
    std::cout << "ivec size: " << ivec.size()
              << " | ivec capacity: " << ivec.capacity() <<std::endl; 
}

int main()
{
    cap_size();


    return 0;
}
