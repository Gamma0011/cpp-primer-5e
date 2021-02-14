#include <iostream>
#include <vector>
#include <string>
#include <set>

/*
    e14.33  - How many operands may an overloaded function-call operator take?  
                A function-call operator can take as many operands as it needs, so long
                 as there are no duplicates of type and number.
    
    e14.34  - Define a function-object to perform an if-then-else operator: The call operator for this class
                should take 3 parameters. It should test its first parameter, if that succeeds, it returns second.
                Otherwise, should return 3rd.

                see. struct TestNums;

    e14.35  - Write a class like PrintString that reads a line of input from an istream and returns a string representing what was read.
                If read fails, return empty string.

                see. class ReadStrings && void e1435();

    e14.36  - Use the class from e14.35 to read the input storing each line as an element in vector

                see. void e1346();

    e14.37  - Write a class that tests whether two values are equal. Use that object and library algorithms to write a program to replace
                all instances of a given value in a sequence.
*/

/************ CLASSES ************/

struct TestNums {
    int operator()(int a, int b, int c) {
        return a < b ? b : c;
    }
};

class ReadStrings {
public:
    friend std::ostream& operator<<(std::ostream&, const ReadStrings&);
    ReadStrings() : is(std::cin), os(std::cout), w(std::string("")) { };
    //void operator()() { while (w != "@!") { is >> w ? os << w <<std::endl : os << "" <<std::endl; } }
    void operator()() {
        while (w != "@!") {
            is >> w && w != "@!" ? svec.push_back(w) : svec.push_back("");
        }
    }
private:
    std::vector<std::string> svec;
    std::string w;
    std::istream &is;
    std::ostream &os;
};

std::ostream& operator<<(std::ostream &os, const ReadStrings &rs) {
    for (auto e : rs.svec) {
        os << e << " ";
    }
    return os;
}

class SwapNums {
public:
    friend void operator>>(std::istream&, SwapNums&);
    friend std::ostream& operator<<(std::ostream&, const SwapNums&);
    SwapNums() = default;
    void operator()(int a, int b) {
        for (auto it = ivec.begin() ; it != ivec.end() ; ++it) {
            *it == a ? *it = b : *it ;
        }
    }
private:
    std::vector<int> ivec;
};

/************ FUNCTIONS ************/

void e1434() {
    TestNums t;
    std::cout << t(1, 3, 10) <<std::endl;
}

void e1435() {
    ReadStrings rs;
    rs();
}

void e1436() {
    ReadStrings rs;
    rs();
    std::cout << rs;
}

void e1437() {
    SwapNums s;
    std::cin >> s;
    s(1, 10);
    std::cout << s;
}

void operator>>(std::istream &is, SwapNums &s) {
    int i;
    while (is >> i && i != -1) { 
        s.ivec.emplace_back(i);    
    } 
}

std::ostream& operator<<(std::ostream &os, const SwapNums &s) {
    for (auto e : s.ivec) { os << e << " "; }
    return os;
}

int main()
{
    // e1434();
    // e1435();
    // e1436();
    e1437();
    return 0;
}