#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

/*
    READ-ONLY ALGORITHMS
        Find function and Count Function are read-only, as is accumulate, which is defined in the numeric header

        || ACCUMULATE ||
        Accumulate takes 3 arguments, the first 2 are the range of elements, and the third is an initial value for the sum.

        || EQUAL ||
        Lets us determine whether two sequences hold the same values. Compares each element from the first sequence to the corresponding
        element in the second. Returns TRUE if elements are equal, FALSE otherwise. It takes 3 iterators: first 2 denote range of elements
        in the first sequence, the third denotes the first element in the second sequence.

        Because equal operates in terms of iterators, we can call equal to compare elements in containers of different types. Moreover,
        the element types also need not be the same so long as we can use == to compare the element types. For example, roster1 could be
        a vector<sting> and roster2 a list<const char*>

        Equal makes one important assumption: that the second sequence is at least as big as the first

    ALGORITHMS THAT WRITE CONTAINER ELEMENTS
        Some algorithms assign new values to elements in a sequence. When we assign elements using algorithms, we must take care to ensure that the 
        sequence into which the algorithm writes is at least as large as the number of elements we ask the algorithm to write.
        REMEMBER - ALGORITHMS DO NOT PERFORM CONTAINER OPEARATIONS AND HAVE NO WAY TO CHANGE THE SIZE OF A CONTAINER
    
        || FILL ||
        Takes a pair of iterators that denote a range and a third argument that is a value. 
        Fill assigns the give value to each element in the input sequence.

        || FILL_N ||
        Takes a single iterator, a count, and a value. It assigns the given value to the specified number of elements starting
        at the first element, denoted by the iterator. We might use this to assign new values to elements in a vector.

        fill_n assumes that it is safe to write the specified # of elements:     fill_n(dest, n, val);
        It also assumes that dest refers to an element and that there are at least n elements in sequence starting from dest

            **NOTE** It is a common mistake to call fill_n (or other write algorithms) on empty containers. This will return an error!
            Cannot call write algorithms on containers with no elements as there is nothing to write to.

        || BACK_INSERTER ||
        One way to ensure that an algorithm has enough elements to hold the output is to use an insert iterator.
        An insert iterator ADDS elements to a container. Normally, when we assign to a container element through an iterator, we assign
        to the element the iteraotr denotes. When we assign through an insert iterator, a new element equal to the right-hand value is added to the container

        back_inserter is defined in the <iterator> header. It takes a reference to a container and returns an insert iterator bound to that container.
        When we assign through that iteratorm, the assignment calls push_back to add an element with the given value to the container

        We frequently use back_inserter to create an iterator to use as the destination of an algorithm.

        || COPY ||
        Takes 3 iterators. The first 2 denote an input range; the third denotes the beginning of the destination sequence. This algorithm
        copies elements from its input range into elements in the destination. It is essential that the destination passed to copy be at least
        as large as the input range

        || REPLACE ||
        Reads a sequence and replaces every instance of a given value with another value
            std::replace(iterator start, iterator end, val to find, new val to replace with);

        || REPLACE COPY ||
        If we want to leave the original sequence unchanged, we can call replace_copy. That alrogithm takes a 3rd iterator argument
            denoting a destination in which to write the adjusted sequence.

    ALGORITHMS THAT REORDER CONTAINER ELEMENTS
        Some algorithms rearrange the order of elements within a container.

        || SORT ||
        Arranges the elements in the input range into sorted order using the element type's < operator

        || UNIQUE ||
        Reorders the elements of a container so that unique elements appear in the first part of the container.

*/

void acc_func() {
    std::vector<int> ivec = {1,2,3,4,5,6,7,8,9};
    std::vector<std::string> svec = {"Hello", "World", "!", "!"};

    int isum = std::accumulate(ivec.cbegin(), ivec.cend(), 0);
    std::cout << isum <<std::endl;

    // calling accumulate on a vector of strings will concatenate the elements of vector<string>
    std::string ssum = std::accumulate(svec.cbegin(), svec.cend(), std::string(""));    // NOTE: 3rd argument explicitly declares string, cannot pass string literal ""
    //std::string ssum = std::accumulate(svec.cbegin(), svec.cend(), "");    // this will not work, string literal "" and object holding sum would be const char*. No concatenate + operator for const char*
    std::cout << ssum <<std::endl;
}

void equal_func() {
    // roster 2 should have at least as many elements as roster 1;
    std::vector<int> ivec1 = {0,1,2,3,4,5};
    std::vector<int> ivec2 = {0,1,2,3,4,5,6,7,8,9};

    std::vector<std::string> roster1 = {"Hello", "World"};
    std::list<const char*> roster2 = {"Hello", "World"};

    if (std::equal(ivec1.cbegin(), ivec1.cend(), ivec2.cbegin())) {
        std::cout << "Both Vectors Match" <<std::endl;
    } else {
        std::cout << "Vectors Do Not Match" <<std::endl;
    }

    // comparing vector<string> to list<const char*>
    std::equal(roster1.cbegin(), roster1.cend(), roster2.cbegin()) ? (std::cout << "Both rosters match" <<std::endl) : (std::cout << "Rosters don't match" <<std::endl);

}

void fill_func() {
    std::vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};

    std::cout << std::accumulate(ivec.cbegin(), ivec.cend(), 0) <<std::endl;

    std::fill(ivec.begin(), ivec.end(), 0);         // resets each element in ivec to 0
    std::cout << std::accumulate(ivec.cbegin(), ivec.cend(), 0) <<std::endl;

    std::fill(ivec.begin(), ivec.begin() + ivec.size()/2, 10);         // set a subset of elements to 10
    std::cout << std::accumulate(ivec.cbegin(), ivec.cend(), 0) <<std::endl;
}

void fill_n_func() {
    std::vector<int> ivec;

    for (int i = 0; i != 10; ++i) {
        ivec.push_back(i);
    }
    std::cout << std::accumulate(ivec.cbegin(), ivec.cend(), 0) <<std::endl;            // print out sum
    
    std::fill_n(ivec.begin(), ivec.size(), 0);                                          // reset all the elements of vec to 0
    std::cout << std::accumulate(ivec.cbegin(), ivec.cend(), 0) <<std::endl;            // print out sum
}

void back_inserter_func() {
    std::vector<int> ivec;                  // vector of empty ints;
    auto it = std::back_inserter(ivec);     // assigning through it adds elements to the vec
    *it = 42;                               // vec now has one element with a value 42;

    // using back_inserter to initialize an empty vector with elements via fill_n   
    std::vector<int> i;
    std::fill_n(std::back_inserter(i), 10, 10);         // back_inserter create an insert iterator that adds elements to i, appends 10 elements of value 10 to i
}

void copy_func() {
    int a1[] = {0,1,2,3,4,5,6,7,8,9};
    int a2[sizeof(a1)/sizeof(*a1)];     // a2 has same size as a1
    // ret points just past the last element copies into a2
    auto ret = std::copy(std::begin(a1), std::end(a1), a2);

    for (auto &i : a2) {
        std::cout << i <<std::endl;
    }
}

void replace_func() {
    int a1[] = {0,1,2,3,4,5,6,7,8,9};
    std::replace(std::begin(a1), std::end(a1), 0, 42);

    for (auto &i : a1) { std::cout << i <<std::endl; }
}

void replace_copy() {
    // use back_inserter to grow destination as-needed
    std::list<int> ilist = {0,1,2,3,4,5,6,7,8,9};
    std::vector<int> ivec;

    // replace copy will replace all instances of old_val with new val and leave the original container (ilist) unchanged.
    // using back_inserter will allow us to copy into and grow ivec as-needed
    std::replace_copy(ilist.begin(), ilist.end(), std::back_inserter(ivec), 0, 42);

    for (auto &i : ivec) { std::cout << i <<std::endl; }
}

void elim_dups(std::vector<std::string> &words) {

    // sort words alphabetically so we can find duplicates
    std::sort(words.begin(), words.end());
    for (auto &w : words) { std::cout << w << " "; }

    std::cout <<std::endl;
    
    // unique reorders the input range so that each word appears once in the front portion 
    //  of the range and returns an iterator one past the unique range
    auto end_unique = std::unique(words.begin(), words.end());
    for (auto &w : words) { std::cout << w << " "; }

    std::cout <<std::endl;

    // erase uses a vector (container) operation to remove the nonunique elements
    // elements from iterator end_unique to words.end() deleted
    words.erase(end_unique, words.end());
    for (auto &w : words) { std::cout << w << " "; }
}

int main()
{
    //acc_func();
    //equal_func();
    //fill_func();
    //fill_n_func();
    //copy_func();
    //replace_func();
    //replace_copy();

    std::vector<std::string> svec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elim_dups(svec);

    return 0;
}