#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>

/*
    e918 - write a program to read a sequence of strings from the standard input into a deque. 
            use iterators to write a loop to print the elements in the deque
    
    e919 - rewrite the program from the previous exercise to use a list. List the changes you needed to make
            no real changes, just change deque to list

    e920 - write a program to copy elements from a list<int> into two deques.
            the even-valued elements should go into one deque, odds into another

    e921 - explain how the loop from pg 345 that used insert to add elements to a list would 
            work if we inserted into a vector instead

            // it's the same process. 

        // original
            list<string> lst;
            auto iter = lst.begin();
            while (cin >> word) {
                iter = lst.insert(iter, word);
            }
        
        // vector
            std::string word;
            std::vector<std::string> svec;
            auto iter = svec.begin();           // iter first iterator in svec;
            while (cin >> word) {
                iter = svec.insert(iter, word);
            }

    e922 - assuming iv is a vector of ints, what is wrong with the following program? how might you correct the problem?

            -- need to increment iter in order to loop, might be easier to make it a for loop instead!
    
        std::vector<int> iv;
        std::vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;

        while (iter != mid) {
            if (*iter == some_val) {
                iv.insert(iter, 2 * some_val);
            }
        }


        // FIXED
        std::vector<int> iv;
        std::vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;

        for ( ; iter != mid ; ++iter) {
            if (*iter == some_val) {
                iv.insert(iter, 2 * some_val);
            }
        }

    e923 - in the first program in this section on page 346, what would the values of val, val2, val3, and val4 be if c.size() is 1;

            auto val = *ivec.begin();           // return 0
            auto val2 = ivec.front();           // return 0
            auto last = ivec.end();
            auto val3 = *(--last);              // return 0
            auto val4 = ivec.back();            // return 0

    e924 - write a program that fetches the first element in a vector using at, 
        the subscript operator front, and begin, test your program on an empty vector;



*/

void e918() {
    std::deque<std::string> sdeq;
    std::string s;

    for (std::string s; std::cin >> s; sdeq.push_back(s));

    for (auto it = sdeq.begin(); it != sdeq.end(); ++it) {
        std::cout << *it <<std::endl;
    }
}

void e919() {
    std::list<std::string> slist;
    std::string s;

    for (std::string s; std::cin >> s; slist.push_back(s));

    for (auto it = slist.begin(); it != slist.end(); ++it) {
        std::cout << *it <<std::endl;
    }
}

void e920(std::list<int> ilist) {
    std::deque<int> ideq;
    std::deque<int> even;
    std::deque<int> odd;

    ideq.assign(ilist.cbegin(), ilist.cend());          // copy ilist values to ideq

    for (auto &i : ideq) {
        if (i%2) {          // if remainder when i/2, odd
            odd.push_back(i);
        } else {            // if no remainder
            even.push_back(i);
        }   
    }

    for (auto &e : even) {std::cout << "Even: " << e <<std::endl;}
    for (auto &o : odd) {std::cout << "Odd: " << o <<std::endl;}
}

void e921() {
    std::string word;
    std::vector<std::string> svec;
    auto iter = svec.begin();           // iter first iterator in svec;
    while (std::cin >> word) {
        iter = svec.insert(iter, word);
    }

    for (auto &s : svec) {
        std::cout << s <<std::endl;
    }
}

void e922() {
    int some_val = 6;
    std::vector<int> iv = {0,1,2,3,4,5,6};
    std::vector<int>::iterator iter = iv.begin(), mid = (iv.begin() + iv.size()/2);

    for ( ; iter != mid ; ++iter) {
        if (*iter == some_val) {
            iv.insert(iter, (2 * some_val));
        }
    }

    for (auto &i : iv) {
        std::cout << i <<std::endl;
    }
}

void e923() {
    std::vector<int> ivec = {0};
    std::cout << "Size: " << ivec.size() <<std::endl;

    auto val = *ivec.begin();           // return 0
    auto val2 = ivec.front();           // return 0
    auto last = ivec.end();
    auto val3 = *(--last);              // return 0
    auto val4 = ivec.back();            // return 0

    std::cout << "val 1: " << val << '\n'
              << "val 2: " << val2 << '\n'
              << "val 3: " << val3 << '\n'
              << "val 4: " << val4 <<std::endl;
}

void e924(std::vector<int> ivec) {              // accept argument vector
    if(!ivec.empty()) {
        auto a = ivec.at(0);                    // fetch first element - using at
        auto f = ivec.front();                  // fetch first element - using front
        auto b = *ivec.begin();                 // fetch first element - using dereferenced iterator

        std::cout << ".at() : " << '\t' << a << '\n'
                  << ".front() : " << '\t' << f << '\n'
                  << ".begin() : " << '\t' << b <<std::endl;

    } else {
        std::cerr << "ERROR: Empty Vector." <<std::endl;
    }
}

int main()
{
    //e918();
    //e919();

    std::list<int> l1 = {2,3,4,5,6};
    //e920(l1);
    //e921();
    //e922();
    //e923();

    //std::vector<int> i = {4,5,6,7};
    std::vector<int> i;
    e924(i);

    return 0;
}