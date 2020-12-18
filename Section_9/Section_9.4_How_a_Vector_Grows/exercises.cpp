#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>

/*
    e935 - explain the difference between a vector's capacity and its size;
            capacity - the current amount of memory allocated
            size - the number of elements current in the vector

    e936 - Can a container have a capacity less than its size?
            No, at a minimum, the container's size and capacity can be the same.
    
    e937 - explain why lists or array don't have a capacity member
            lists are stored in non-contiguous memory
            arrays are fixed, therefore their capacity == size

    e938 - write a program to explore how vectors grow in the library you use
    
    e939 - Explain what the following program fragment does:
            Vector of strings svec created -> reserves 104 places in memory -> create variable string
            Write input to word -> place string word into svec -> increase "size" to 150% by creating value-initialized elements of type string

            std::vector<std::string> svec;
            svec.reserve(1024);                  // reserve 104 spaces in memory for svec
            std::string word;
            while (cin >> word) {
                svec.push_back(word);
            }
            svec.resize(svec.size() + svec.size()/2)    // resize to elements to 150% size
    
    e940 - If the program in the previous exercise reads 256 words, what is its likely capacity after it is resized? What if it reads 512? 1000, 1048?
            
            Assuming that the 1024 is actually allocated when .reserve(1024) is called:
                512 Elements - 768 Size - Capacity remains 1024
                1000 Elements - 1500 Size - Capacity increases. In earlier exercises, we've seen this to be 2x previous capacity. Therefore, it should be 2048 now. However,
                        the each vector can choose its own allocation strategy
                1048 Elements - 1572 Size - Capacity remains 2048;

*/

void e938() {
    std::vector<int> ivec;
    int i;

    while (std::cin >> i) { ivec.push_back(i); }

    std::cout << "Size: " << ivec.size() << '\n'
              << "Capacity: " << ivec.size() <<std::endl;
}

void e939() {
    std::vector<std::string> svec;
    svec.reserve(104);                  // reserve 104 spaces in memory for svec
    std::string word;
        while (std::cin >> word) {
            svec.push_back(word);
        }
    svec.resize(svec.size() + svec.size()/2);    // resize to size + 1/2 size    

    std::cout << "Size: " << svec.size() << '\n'
              << "Capacity: " << svec.capacity() <<std::endl;
}


int main()
{
    e938();
    //e939();

    return 0;
}