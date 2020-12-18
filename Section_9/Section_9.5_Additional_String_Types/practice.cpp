#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>

/*
    OTHER WAYS TO CONSTRUCT STRINGS
        
        string s(cp, n)         - s is a copy of the first n characters in the array to which cp points. That array must have at least n characters
        string s(s2, pos2)      - s is a copy of the characters in string s2 starting at index pos2. Undefined if pos2 > s2.size()
        string s(s2, pos2, len2)- s is a copy of len2 from s2 starting at index pos2. Undefined if pos2 > s2.size(). len2 copies at most s2.size() - pos2 characters

    THE substr OPERATION
        The substr operation returns a string that is a copy of part or all of the original string. 
        We can pass substr an option starting position and count.

        s.substr(pos, n)        - Return a string containing n characters starting s at pos. 
                                  Pos defaults to 0 and n defaults to a value that causes the library to copy all
                                  characters in s starting from pos

        string s("Hello World");
        string s2 = s.substr(0,5);      // s2 = Hello
        string s3 = s.substr(6);        // s3 = World
        string s3 = s.substr(6,11);     // s4 = World
        string s4 = s.substr(12);       // out_of_range exception

    
    string SEARCH OPERATIONS
        The string class provides 6 different search functions, each of which has 4 overloaded versions. Each returns a 
        string::size_type value that is an index of where the match occurs. If there is no match, the function returns a static member
        named string::npos. The library defines npos as a const string::size_type initialized to -1;

        **NOTE** The string search functions return string::size_type, which is an unsigned type. As a result, it is a bad idea to use an int
        or other signed type, to hold the return from these functions.

    THE compare FUNCTIONS
        compare returns zero, or a positive or negative value depeneding on whether s is equal to, greater than or less than
        the string formed from the given arguments;
        
        s.compare(s2)                       - compare s to s2
        s.compare(pos1, n1, s2)             - compares n1 characters starting at pos1 from s to s2
        s.compare(pos1, n1, s2, pos2, n2)   - compares n1 characters starting as pos1 from s to the n2 characters starting at pos2 in s2
        s.compare(cp)                       - compares s to the null-terminated array pointed to by cp
        s.compare(pos1, n1, cp)             - comapres n1 characters starting at pos1 from s to cp
        s.compare(pos1, n1, cp, n2)         - compares n1 characters starting at pos1 from s to n2 characters starting from the pointer cp
            
    NUMERIC CONVERSIONS
        Strings often contain characters that represent numbers. A string 15 is represented differently than a short int 15

        The new standard introduced several functions that convert between numeric data and library strings

        int i = 42;
        string s = to_string(i);            // converts the int i to its character representation
        double d = stod(s);                 // converts the strings s to floating-point


        to_string(val)      - overloaded functions returning the string representation of val. Accepts any arithmetic type (int, float, double, short)
        stoi(s, p, b)       - return the initial substring of s that has numeric content as an int. 
                                P is a pointer to a size_t in which to put the index of the first nonnumeric char in s (defaults to 0, in which case no index is stored)
                                B indicates numeric base to use for the conversion; b defaults to 10
        stol(s, p, b)       - string to long
        stoul(s, p, b)      - string to unsigned long
        stoll(s, p, b)      - string to long long
        stoull(s, p, b)     - string to unsigned long long
        stof(s, p, b)       - string to float
        stod(s, p, b)       - string to double
        stold(s, p, b)      - string to long double
        
*/

void str_tests() {
    const char *cp = "Hello World!!!";          // null-terminated array
    char noNull[] = {'H', 'i'};                 // not null-terminated

    std::string s1(cp);                              // copy up to the null in cp; s1 == "Hello World!!!"
    std::string s2(noNull,2);                        // copy two elements from noNull; s2 == "Hi"
    //std::string s3(noNull);                          // undefined noNull not terminated
    std::string s4(cp + 6, 5);                       // copy 5 characters starting at cp[6]; s4 == "World"
    std::string s5(s1, 6, 5);                        // copy 5 characters starting at s1[6]; s5 == "World"
    std::string s6(s1, 6);                           // copy from s1[6] to the end of s1; s6 == "World!!!"
    std::string s7(s1, 6, 20);                       // ok, copies only to end of s1; s7 == "World!!!"
    //std::string s8(s1, 16);                          // out_of_range exception
}


void str_find() {
    std::string name = "AnnaBelle";
    auto pos1 = name.find("Anna");  // pos1 == 0;
    std::cout << pos1 <<std::endl;

    // find operation is case-sensitive
    auto pos2 = name.find("anna");
    std::cout << pos2 <<std::endl;  // pos2 == npos;

    // finding a match to any character in the search string. locate first # within n
    std::string numbers("0123456789"), n("R2D2");
    auto pos3 = n.find_first_of(numbers);
    std::cout << pos3 <<std::endl;  // pos3 = 1

    // instead of looking for a match, we might want to call find_first_not_of to find the 1st position that is NOT in search
    std::string dept("0342p9");

    auto pos4 = dept.find_first_not_of(numbers);
    std::cout << pos4 <<std::endl;  //pos4 = 4


    std::string::size_type pos = 0;
    // each iteration finds the next number in name
    while ((pos = n.find_first_of(numbers, pos)) != std::string::npos) {
        std::cout << "Found number at index: " << pos << "\nElement is: " << n[pos] <<std::endl;
        ++pos;
    }
}

void search_backwards() {
    std::string state("Mississippi");
    std::cout << "Reverse Find: " << state.rfind("is") <<std::endl;
    std::cout << "Normal Find: " << state.find("is") <<std::endl;
}

void num_conv() {
    std::string s2 = "Pi = 3.14";
    // convert the first substring in s that starts with digit, d = 3.14;
    double d = stod(s2.substr(s2.find_first_of("+-.0123456789")));
    std::cout << d <<std::endl;
}

int main()
{
    //str_tests();
    //str_find();
    //search_backwards();
    num_conv();

    return 0;
}