#include <iostream>
using std::string;
using std::cout;
using std::cin;

void line_by_line(){
    string line;

    while(getline(cin, line)){
        cout << line <<std::endl;
    }
}

void word_by_word(){
    string word;

    while(cin >> word){
        cout << word <<std::endl;
    }
}

int main()
{
    // read standard output one line at a time
     line_by_line();
    // word_by_word();

    return 0;
}