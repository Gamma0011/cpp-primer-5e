#include <iostream>
using std::cin;
using std::cout;
using std::string;
using std::endl;

int equal_to(){
    string s1, s2;

    cout << "Please enter two stings. We'll figure out if they're equal." <<endl;
    if(getline(cin, s1) && getline(cin, s2)){
        if(s1 == s2){
            cout << "Both strings are equal!" <<endl;
        } else if(s1 > s2){
            cout << s1 << " is larger than " << s2 <<endl;
        } else {
            cout << s1 << " is smaller than " << s2 <<endl;
        }
    } else {
        std::cerr << "No input!" <<endl;
        return -1;
    }

    return 0;
}

int check_length(){
    string s1, s2;

    if(getline(cin, s1) && getline(cin, s2)){
        cout << s1 << " | Length: " << s1.size() << "\n"
             << s2 << " | Length: " << s2.size() <<endl;
        if(s1.size() == s2.size()){
            cout << "Both strings are of the same length!" <<endl;
        } else if(s1.size() > s2.size()){
            cout << s1 << " is longer than " << s2 <<endl;
        } else {
            cout << s1 << " is shorter than " << s2 <<endl;
        }

    } else {
        std::cerr << "No input!" <<endl;
        return -1;
    }
    return 0;
}

int main()
{
    // report if both string are equal. if not, report which is larger
    // equal_to();

    // now report if string have same length. if not, report which is longer
    check_length();

    return 0;
}