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

    e14.38  - Write a class that tests whether the length of a given string matches a given bound. Use that object to write a program
                to report how many words in an input file are of sizes 1 through 10 inclusive

                    see. e1438.cpp

    e14.39  - Revise the previous program to report the count of words that are sizes 1 through 9 and 10 or more.
                Default-initialize parameter upper limit. 

                    see. e1439.cpp
    
    e14.40  - Rewrite the biggies function from 10.3.2 to use function-object classes in place of lambdas

                    see. e1440.cpp

    e14.41  - Why do you suppose the new standard added lambdas? Explains when you would use a lambda and when you'd write a class instead.
                Lambdas work well when doing only modest comparisons. In most cases, the purpose of a lambda is to return a bool statement 
                about two or more variables. In cases where there are a lot more variables, or even significantly more calculations needed,
                a class might work better, especially if certain member objects need to be initialized for later use. 

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