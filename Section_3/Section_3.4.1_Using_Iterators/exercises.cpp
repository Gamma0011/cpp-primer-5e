#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void intreturn(const vector<int> &v){
    for(auto it = v.cbegin(); it != v.cend(); ++it){
        cout << *it <<endl;                             // dont forget to dereference
    }
}

void strreturn(const vector<string> &v){
    for(auto it = v.cbegin(); it != v.cend(); ++it){
        cout << *it <<endl;                             // dont forget to dereference
    }
}

void e321(){
    // redo 3.3.3 using iterators
    // write a program to print the size and contents of vectors from e313
    vector<int> v1;                     // empty int
    vector<int> v2(10);                 // vector with 10 elements, initialized to 0
    vector<int> v3(10, 42);             // vector with 10 elements, initialized to 42
    vector<int> v4{10};                 // vector with 1 element, initialized to 10
    vector<int> v5{10, 42};             // vector with 2 elements, initalized to 10 and 42
    vector<string> v6{10};              // vector with 10 elements, empty strings
    vector<string> v7{10, "hi"};        // vector with 10 elements, "hi" strings

    intreturn(v1);
    intreturn(v2);
    intreturn(v3);
    intreturn(v4);
    intreturn(v5);
    strreturn(v6);
    strreturn(v7);
}

void e322(){
    // revise the loop printed to instead change the elements in test to all uppercase
    vector<string> text{"string becomes uppercase", "this one should too"};

    for(auto it = text.cbegin(); it != text.cend(); ++it){
        for(auto elem : *it){
            elem = toupper(elem);
            cout << elem;
        }
        cout <<endl;
    }
}

void e323(){
    // write program to create a vector with ten int elements. using iterator, assign each element a value that is 2x current value

    vector<int> ivec;

    // create values in ivec 1-10
    for(int counter = 1; counter != 11; ++counter){
        ivec.push_back(counter);
    }
    
    // double using range for
    for(auto elem : ivec){
        elem *=2;
        cout << elem << " ";
    }
    
    cout <<endl;

    // double using iterator
    for(auto it = ivec.cbegin(); it != ivec.cend(); ++it){
        auto elem = (*it) *2;
        cout << elem << " ";
    }


}

int main()
{
    //e321();
    //e322();
    e323();

    return 0;
}