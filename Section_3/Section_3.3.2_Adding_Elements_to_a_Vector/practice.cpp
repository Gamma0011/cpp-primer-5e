#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

// KEY IDEA: vectors grow efficiently, therefore it is better to not define the size of a vector

int main()
{

    // push_back operation -- takes a value and pushes that value as a new last element onto the back of the vector

    vector<int> v2;                 //empty vector
    for (int i = 0; i !=100; ++i){
        v2.push_back(i);            // append sequential integers to v2
    }                               // at the end of loop, v2 has 100 elements, valued 0 to 99;

    // we can also use the same approach when we don't know how many elements a vector should have.
    //  in this example, we read the input and store values in the vector

    string word;
    vector<string> text;            // empty vector
    while (cin >> word){
        text.push_back(word);       // append word to text
    }

    return 0;
}
