#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int concatenation_practice(){
    string sentence, word;

    if(cin >> sentence){
        while(cin >> word){
            sentence += word;
        }
        cout << sentence <<endl;
    } else {
        std::cerr << "No input!" <<endl;
        return -1;
    }
    return 0;
}

int add_spaces(){
    string sentence, word;
    
    if(cin >> sentence){
        while(cin >> word){
            sentence += ' ' + word;
        }
        cout << sentence <<endl;
    } else {
        std::cerr << "No input!" <<endl;
        return -1;
    }
    return 0;
}

int main()
{
    // concatenate multiple inputs into one sentence
    // concatenation_practice();

    // concatenate multiple inputs and put spaces between words;
    add_spaces();

    return 0;
}