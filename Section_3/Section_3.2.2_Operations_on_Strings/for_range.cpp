#include <iostream>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void book_example(){
    string s("Hello World!!!!");

    decltype(s.size()) punct_cnt = 0;

        for(auto c : s){
            if(ispunct(c)){
                punct_cnt++;
            }
        }
    cout << punct_cnt << " punctuation characters in " << s <<endl;
}

void practice(){
    string s("Meaning of life? == 42");

    decltype(s.size()) counter = 0;

    for (auto c : s){
        if(ispunct(c)){
            counter++;
        }
    }
    cout << counter << " punctuation characters detected in: \n" << s <<endl;
}

void to_upper(){
    string s("hello beautiful world!!!!");

    for (auto &c : s){
        c = toupper(c);
    }
    cout << s <<endl;
}


int main()
{
    // book_example();
    // practice();
    // to_upper();

    return 0;
}
