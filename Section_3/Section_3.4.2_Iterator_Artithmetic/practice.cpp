#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// iter + n                 denotes moving forwards or backwards n number of elements within a container
// iter - n
// iter1 += n               compound-assignment for iterator addition and subtraction. assigns to iter1 the value of adding n to or subtracting n from iter1
// iter1 -= n
// iter1 - iter2            subtracting 2 iterators yields the number that when added to the right-hand iterator yields the left-hand iterator
// > >= < <=                relational operators on iterators. one iterator is less than another if it refers to an element that appears in the 
//                           container before the one referred to by the other iterator. ,must denote elements in, or one past the end of the same container

void midpoint(){
    vector<int> vi(10,42);

    // compute an iterator to the element closes to the midpoint of vi
    auto mid = vi.begin() + vi.size() / 2;

    for(auto it = vi.cbegin(); it < mid; ++it){
        cout << *it << " ";
    }
}

void binarysearch(){
    // text must be sorted
    // beg and end will denote the range we're searching

    vector<string> text{"This", "is", "a", "test", "."};
    string sought("is");

    auto beg = text.begin(), end = text.end();
    auto mid = text.begin() + (end - beg)/2;    // original midpoint

    // while there are still elements to look at and we haven't yet found sought
    while (mid != end && *mid != sought){
        if (sought < *mid){
            end = mid;
        } else {
            beg = mid + 1;
        }
        mid = beg + (end-beg)/2;
    }

}


int main()
{
    
    binarysearch();

    return 0;
}