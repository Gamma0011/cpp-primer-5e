#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void e514()
{
    // write a program to read strings from std input, looking for duplicated words following itself and keeping count;
    // how now now now brown cow cow            now should == 3, cow == 2

    vector<string> svec;
    string in;
    string prevStr;
    int cnt = 1;

    // read std input into svec
    while (cin >> in) {
        svec.push_back(in);
    }

    auto beg = svec.begin();
    auto end = svec.end() + 1;

    while (beg != end) {
        if (*beg == prevStr){
            ++cnt;
        } else if (*beg != prevStr && prevStr != "\0") {
            cout << prevStr << " occured " << cnt << " times in a row." <<endl;
            cnt = 1;
        }

        prevStr = *beg;
        ++beg;
    }

    /*
    for (auto s : svec) {
        cout << s <<endl;
    }
    */


}

void e515()
{
    // explain each of the following loops, correct any problems

    /*
    
    a)  problem: ix declared in for header and cannot be accessed outside of for header
        for (int ix = 0; ix != sz; ++ix) {}
        if (ix != sz) {}

    fix:
        int ix = 0;

        for (/* /; ix != sz; ++ix) {}
        if (ix != sz) {}

    b)  problem: missing init-statement (initializer) 
        int ix;
        for (ix != sz; ++ix)

    fix:
        int ix;
        for (/* /; ix != sz; ++ix) {}

    c)  problem: increment operator not attached to sz. 
        for (int ix = 0; ix != sz; ++ix, ++ sz) {}

    fix:
        for (int ix = 0; ix != sz; ++ix, +sz) {}

    */
}

void e516()
{
    // write a while and for loop that do the same thing, which would you chose and why?

    // I prefer the for header, it's cleaner and declarations can be made within in the for loop, which stops you from initializing unnecessarily

    vector<int> ivec = {1,2,3,4};

    // for
    for (decltype(ivec.size()) i = 0; i != ivec.size(); ++i) {
        cout << ivec[i] <<endl;
    }


    // while
    auto beg = ivec.begin();
    int counter = 0;

    while (beg != ivec.end()) {
        cout << ivec[counter] <<endl;
        ++beg, ++counter;
    }
}

void e517()
{
    // give two vectors of ints, write program to determine whether vector is a prefix of the other
    // for vectors of unequal length, compare the number of elements of the smaller vector

    // for example, vector 0,1,1,2 and vector 0,1,1,2,3,5,8 should return true

    vector<int> ivec1 = {0,1,1,2};
    vector<int> ivec2 = {0,1,1,2,3,5,8};

    /*
    for (decltype(ivec1.size()) i = 0; i != ivec1.size() || i != ivec2.size() && ivec1[i] == ivec2[i]; ++i) {
        cout << "Vector 1 is a prefix of Vector 2." <<endl;
    }
    */
    // steps:
    // check if vectors equal length
    // else not
    // then take smaller vector 
    if (ivec1.size() == ivec2.size()) {
        if (ivec1 == ivec2) {
            cout << "Vector 1 is a prefix of Vector 2." <<endl;
        } else {
            cout << "Vector 1 is NOT a prefix of Vector 2." <<endl;
        }
    } else if (ivec1.size() > ivec2.size()) {                   // ivec1 greater than ivec2
        decltype(ivec2.size()) i = 0;
        while (i != ivec2.size() && ivec1[i] == ivec2[i]) {
            ++i;
        } 
        if (i == ivec2.size()){
            cout << "Vector 2 is a prefix of Vector 1." <<endl;
        } else {
            cout << "Vector 2 is NOT a prefix of Vector 1." <<endl;
        }
    } else if (ivec1.size() < ivec2.size()) {                   // ivec1 less than ivec2
        decltype(ivec1.size()) i = 0;
        while (i != ivec1.size() && ivec1[i] == ivec2[i]){
            ++i;
        }
        if (i == ivec1.size()) {
            cout << "Vector 1 is a prefix of Vector 2." <<endl;
        } else {
            cout << "Vector 1 is NOT a prefix of Vector 2." <<endl;
        }
    }

}

void e518()
{
    // explain each of the following loops. correct any problems you detect

    /*
    a)          ** {} don't block off do statement, will fail
        do
            int v1, v2;
            cout << "Please enter two numbers to sum: ";
            if (cin >> v1 >> v2) {
                cout << "Sum is " << v1 + v2 <<endl;
            } 
        while (cin);


        ** CORRECT **
        do {
            int v1, v2;
            cout << "Please enter two numbers to sum: ";
            if (cin >> v1 >> v2) {
                cout << "Sum is " << v1 + v2 <<endl;
            }
        } while (cin);

    b)      ** int ival shouldn't be declared in this scope
        do {
        } while (int ival = get_response());



        ** CORRECT **
        int ival;
        do {
        } while (ival = get_response());


    c)      ** ival declared in do block, must be declared outside block for use in while
        do {
            int ival = get_response();
        } while (ival);


        ** CORRECT **
        int ival = get_response();
        do {
            ival = get_response();
        } while (ival);
    */
}

void e519()
{
    // write a program that uses a do while loop repetitvely requests 2 strings from the user and report which string is less than the other
    string s1, s2;
    string cont;

    do {
        cout << "Please enter two strings: ";
        cin >> s1 >> s2;

        if (s1.size() == s2.size()) {
            cout << "Both strings are the same length." <<endl;
        } else if (s1.size() > s2.size()) {
            cout << "String 1 is longer than String 2." <<endl;
        } else {
            cout << "String 2 is longer than String 1." <<endl;
        }

        cout << "\nWould you like to enter more? (Yes/No): ";
        cin >> cont;

    } while (cont[0] != 'n');


}

int main()
{
    //e514();
    //e516();
    //e517();
    //e518();
    e519();

    return 0;
}
