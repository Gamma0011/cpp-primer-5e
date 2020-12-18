#include <iostream>
#include <vector>
#include <string>
#include <list>

/*
    e941 - write a program that initializes a string from a vector<char>

    e942 - given that you want to read a character at a time into a string, and you know that you need to read at least 100 characters
            how might you improve the performance of your program?

            Setting a .reserve(100) on the string prior to reading characters into it should help to avoid the overhead cost
            associated with reallocating the vector when in need of more memory. This would also reduce the cost of the string potentially
            allocating more capacity than is needed, assuming only 100 characters.

    e943 - write a function that takes three strings, s, oldVal, and newVal. Using iterators, and the insert and erase function, 
            replace all instances of oldVal that appear in s by newVal. Test your function by using it to replace common abbreviations
            such as "tho" by "though" and "thru" by "through".

    e944 - rewrite the previous function using an index and replace

    e945 - write a function that takes a string representing a name and two other strings representing a prefix. such as "mr" or "mrs" and a suffix
            such as jr or III. Using iterators, insert, and append functions generate and return a new string with suffix and prefix added to the given name.
    
    e947 - write a program that finds each numberic character and then each alphetical character in the string "ab2c3d7R4E6". 
            Write 2 versions of the program. First should use find_first_of, and the second find_first_not_of

    e948 - given the definitions of name and numbers on pg 365, what does numbers.find(name) return?
            std::string name("r2d2");
            std::string numbers("0123456789");

            numbers.find(name);

            // npos returned no match of r2d2 in numbers

    e950 - write a program to process a vector<string> s whose elements represent integral values. Produce the sum of all the elements in that vector.
    Change the program so that it sums strings that represent floating-point

    e951 - Write a class that has three unsigned members representing year, month and day. Write a constructor that take a string representing a date.
            Your constructor should handles a variety of date formats, such as January 1, 1900, 1/1/1900, Jan 1, 1900 and so on

*/

std::string e941(std::vector<char> cvec) {
    std::string str(cvec.begin(), cvec.end());
    //for (auto &c : cvec) { str.push_back(c); }   
    return str;
}

std::string e943(std::string &s, const std::string &old, const std::string &newWord) {
    for (auto curr = s.begin() ; curr <= s.end()-old.size() ; ) {
        if (old == std::string(curr, curr + old.size())) {
            s.erase(curr, curr + old.size());
            s.insert(curr, newWord.begin(), newWord.end());
            curr += newWord.size();
        } else {
            ++curr;
        }
    }
    return s;
}   

std::string e944(std::string &s, const std::string &old, const std::string &newWord) {
    for (size_t pos = 0 ; pos <= s.size() - old.size() ; ) {
        if (old == s.substr(pos, old.size())) {
            s.replace(pos, old.size(), newWord);
            pos += newWord.size();
        } else {
            ++pos;
        }
    }

    return s;
}

std::string e945(std::string &name, const std::string &prefix, const std::string &suffix) {
    name.insert(name.begin(), prefix.cbegin(), prefix.cend());
    return name.append(suffix);
}

void e947_1() {
    std::string s("ab2c3d7R4E6");
    std::string letters("abcdRE");
    std::string numbers("0123456789");

    std::string::size_type pos = 0;


    while ((pos = s.find_first_of(numbers, pos)) != std::string::npos) {
        std::cout << "Number found: " << s[pos] <<std::endl;
        ++pos;
    }
    
    pos = 0; // reset pos

    while ((pos = s.find_first_of(letters, pos)) != std::string::npos) {
        std::cout << "Letter found: " << s[pos] <<std::endl;
        ++pos;
    }
}

void e947_2(std::string s, std::string numbers, std::string letters) {
    std::string::size_type pos = 0;

    while ((pos = s.find_first_not_of(numbers, pos)) != std::string::npos) {
        std::cout << "Letter found: " << s[pos] <<std::endl;
        ++pos;
    }

    pos = 0;            // reset pos

    while ((pos = s.find_first_not_of(letters, pos)) != std::string::npos) {
        std::cout << "Number found: " << s[pos] <<std::endl;
        ++pos;
    }

}

void e948() {
    std::string name("r2d2");
    std::string numbers("0123456789");

    if (numbers.find(name) == std::string::npos) {
        std::cout << "npos returned" <<std::endl;
    } else {
        std::cout << numbers.find(name) <<std::endl;
    }
}

void e950_i() {
    std::vector<std::string> svec = {"1", "2", "3", "4", "5"};
    int i = 0;
    int sum = 0;

    for (auto &s : svec) {
        if (s.find_first_of("0123456789") != std::string::npos) {
            sum += stoi(s.substr(s.find_first_of("0123456789")));
        }
    }

    std::cout << sum <<std::endl;
}

void e950_f() {
    std::vector<std::string> svec = {"1.1", "2", "3", "4.7", "5"};
    float sum = 0.0;

    for (auto &s : svec) {
        if (s.find_first_of(".0123456789") != std::string::npos) {
            sum += stof(s.substr(s.find_first_of(".0123456789")));
        }
    }

    std::cout << sum <<std::endl;
}

class date {
public:
    date(std::string s) : d(s) {
        if ((d.find_first_of("/")) != std::string::npos) {format = 'n'; formatDate(); }
        if ((d.find_first_of(" ")) != std::string::npos) {format = 'a'; formatDate(); }
    }

    void formatDate() {
        switch(format) {
            case 'n' :
                month = stoi(d.substr(0, d.find_first_of("/")));
                day = stoi(d.substr(d.find_first_of("/") + 1, d.find_last_of("/")));
                year = stoi(d.substr(d.find_last_of("/") + 1, 4));
            break;

            case 'a' :
                if (d.find("Jan") < d.size()) { month = 1; }
                if (d.find("Feb") < d.size()) { month = 2; }
                if (d.find("Mar") < d.size()) { month = 3; }
                if (d.find("Apr") < d.size()) { month = 4; }
                if (d.find("May") < d.size()) { month = 5; }
                if (d.find("Jun") < d.size()) { month = 6; }
                if (d.find("Jul") < d.size()) { month = 7; }
                if (d.find("Aug") < d.size()) { month = 8; }
                if (d.find("Sep") < d.size()) { month = 9; }
                if (d.find("Oct") < d.size()) { month = 10; }
                if (d.find("Nov") < d.size()) { month = 11; }
                if (d.find("Dec") < d.size()) { month = 12; }
                day = stoi(d.substr(d.find_first_of(" ") + 1, d.find_last_of(" ")));
                year = stoi(d.substr(d.find_last_of(" ") + 1, 4));
            break;
        }
    }
    void print() { std::cout << "Month: " << month << "\nDay: "  << day << "\nYear: " << year <<std::endl; }

private:
    std::string d;
    char format;
    unsigned int month;
    unsigned int day;
    unsigned int year;
};


int main()
{
    std::vector<char> c = {'H', 'e', 'l', 'l', 'o'};
    //std::cout << e941(c) <<std::endl;

    std::string s = "Running thru the woods.";
    std::string t = "I test test tho.";
    // e943
    //std::cout << e944(s, "thru", "through") <<std::endl;
    //std::cout << e944(t, "tho", "though") <<std::endl;

    // e945
    std::string n("Johnson");
    std::string p("Mr. ");
    std::string suf(" Jr.");

    //std::cout << e945(n, p, suf) <<std::endl;


    // e947 

    std::string str("ab2c3d7R4E6");
    std::string letters("abcdRE");
    std::string numbers("0123456789");
    //e947_1();
    //e947_2(str, numbers, letters);

    //e948();
    //e950_i();
    //e950_f();



    date nu("03/30/1923");
    nu.print();

    date a("Feb. 23, 1899");
    a.print();

    return 0;
}