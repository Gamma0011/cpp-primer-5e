#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


void e316() {
    // write a program to print the size and contents of vectors from e313
    vector<int> v1;                     // empty int
    vector<int> v2(10);                 // vector with 10 elements, initialized to 0
    vector<int> v3(10, 42);             // vector with 10 elements, initialized to 42
    vector<int> v4{10};                 // vector with 1 element, initialized to 10
    vector<int> v5{10, 42};             // vector with 2 elements, initalized to 10 and 42
    vector<string> v6{10};              // vector with 10 elements, empty strings
    vector<string> v7{10, "hi"};        // vector with 10 elements, "hi" strings

    for(decltype(v3.size()) counter = 0; counter < v3.size(); ++counter){
        cout << v3[counter] <<endl;
    }

    for(decltype(v4.size()) counter = 0; counter < v4.size(); ++counter){
        cout << v4[counter] <<endl;
    }
    for(decltype(v5.size()) counter = 0; counter < v5.size(); ++counter){
        cout << v5[counter] <<endl;
    }
    for(decltype(v6.size()) counter = 0; counter < v6.size(); ++counter){
        cout << v6[counter] <<endl;
    }
    for(decltype(v7.size()) counter = 0; counter < v7.size(); ++counter){
        cout << v7[counter] <<endl;
    }
}

void e317() {
    // read sequence of words from cin and store in vector
    // afterwards, process the vector and change each word to uppercase and print 8 words to a line

    vector<string> svec;
    string word;
    
    while(cin>>word){
        svec.push_back(word);
    }
    for(auto &elem : svec){
        for(auto &c : elem){
            c = toupper(c);
        }
    }
    for(decltype(svec.size()) cnt; cnt < svec.size(); ++cnt){
        cout << svec[cnt] << '\t';
            if((cnt+1) % 8 == 0){
                cout <<endl;
            }
    }
}

void e318() {
    // is the following program legal
    // illegal. must add with pushback
    vector<int> ivec;
    // ivec[0] = 42;                // wrong
    ivec.push_back(42);             // correct
    cout << ivec[0] <<endl;
}

void e319(){
    // list three ways to define a vector and give it 10 elements, each with a value of 42; preferred way and why
    vector<int> vec1{42,42,42,42,42,42,42,42};
    vector<int> vec2(10, 42);                   // this is the most efficient way to add elements
    vector<int> vec3;
    for(int cnt = 0; cnt < 10; ++cnt){          // this is the correct way to add elements
        vec3.push_back(42);
    }
}

void e320(){
    // read a set of integers into a vector. print the sum of each pair of adjacent elements.
    // print the sum of the first and last elements, followed by the sum of the second to last elements, etc.

    vector<int> ivec{1,2,3,4,5,6,7,8,9,10};
    int size = ivec.size();

    for(decltype(ivec.size()) counter = 0; counter < ivec.size() - 1; ++counter){
        ivec[counter] += ivec[counter+1];
        cout << ivec[counter] << '\t';
            }
        
        cout <<endl;

    // symmetrical summation
    auto mid = (ivec.size() +1) / 2;
    for(decltype(mid) counter2 = 0; counter2 != mid; ++counter2){
        cout << ivec[counter2] + ivec[ivec.size() - 1 - counter2] << '\t';
    }
    

}

int main()
{
    //e316();
    //e317();
    //e318();
    //e319();
    e320();

    return 0;
}
