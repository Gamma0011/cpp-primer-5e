#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
    e10.11 - write a program that uses stable_sort and isShorter to sort a vector passes to your version of elimDupes. Print the vector.

    e10.12 - write a function named compareIsbn that compares the isbn() members of two Sales_data objects. Use that function to sort a vector that holds
        Sales_data objects

    e10.13 - write a function that takes a string and returns a bool indicating whether the string has 5 characters or more. Use that function
        to partition words. Print elements that have five or more characters    
        
        **NOTE** std::partition takes a predicate and partitions the container so that values for which the predicate 
                 is true appear first, false appears last

    e10.14 - write a lambda that takes two ints and returns their sums

    e10.15 - write a lambda that captures an int from its enclosing function and takes an int parameter. return the sum

    e10.16 - write your own version of biggies using lambdas

    e10.17 - rewrite exercise 10.12 to use lambda in the call to sort instead of compareIsbn function

    e10.18 - rewrite biggies to use partition instead of find_if            see biggies.cpp

*/

class Sales_data {
private:
    unsigned units_sold;
    double price;
public:
    std::string isbn;

    Sales_data() : isbn(""), units_sold(0), price(0) { } ;
    Sales_data(std::string i, unsigned u, double p) : isbn(i), units_sold(u), price(p) { } ;
};

/************************************/
/***********EXERCISE 10.11***********/

void elimDupes(std::vector<std::string> &svec) {
    std::sort(svec.begin(), svec.end());                // sort elements of svec by alphabetical order
    auto dup = std::unique(svec.begin(), svec.end());   // find start of non-unique elements in rearranged list
    svec.erase(dup, svec.end());                        // erase from first non-unique element to end of svec
}
bool isShorter(const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
}
void e1011() {
    // e10.11
    std::vector<std::string> vec = {"the", "quick", "brown", "fox", "fox", "the", "jumped", "over", "red", "jumped"};   // vector to test
    elimDupes(vec);                                         // sort by alphabetical order, remove duplicates
    std::stable_sort(vec.begin(), vec.end(), isShorter);    // sort by alphabetical order & element size
    for (const auto &s : vec) { std::cout << s << " "; }    // print newly-sorted elements of vec
    std::cout <<std::endl;
}

/************************************/
/***********EXERCISE 10.12***********/
bool sortIsbn(const Sales_data &s1, const Sales_data &s2) {
    return s1.isbn < s2.isbn;
}
void compareIsbn(std::vector<Sales_data> &s) {
    std::sort(s.begin(), s.end(), sortIsbn);
}
void e1012() {
    Sales_data b1("0-000-00-0", 10, 25);            // object 1
    Sales_data b2("1-111-11-1", 45, 10);            // object 2
    Sales_data b3("0-000-11-1", 45, 10);            // object 2
    std::vector<Sales_data> obj = {b1, b2, b3};

    compareIsbn(obj);

    for (auto &o : obj) { std::cout << o.isbn << std::endl; }

}

/************************************/
/***********EXERCISE 10.13***********/

bool checkChar(std::string &s) {
    return s.size() >= 5;
}

void e1013() {
    std::vector<std::string> str = {"Hello", "world", "It's", "a", "beautiful", "day", "out", "earth"};
    // sort str by checkChar. .size() >= 5 true, <5 false
    auto f = std::partition(str.begin(), str.end(), checkChar);     // assign f to be first false element
    
    str.erase(f, str.end());            // remove all string elements that are .size() <5 
    
    for (const auto &s : str) { std::cout << s <<std::endl; }
}

int e1015(int a) {

    auto f = [a](int b = 10){ return a + b; };

    return f();
}

void e1017() {
    Sales_data b1("0-000-00-0", 10, 25);            // object 1
    Sales_data b2("1-111-11-1", 45, 10);            // object 2
    Sales_data b3("0-000-11-1", 45, 10);            // object 2

    std::vector<Sales_data> salesVec = {b1,b2,b3};

    std::sort(salesVec.begin(), salesVec.end(), [](const Sales_data &s1, const Sales_data &s2) { return s1.isbn < s2.isbn; });

    for (auto &s : salesVec) { std::cout << s.isbn <<std::endl; }

}

void e1016(std::vector<std::string> &svec, std::vector<std::string>::size_type sz) {     // 2 args - vector and size of string elements
    // sort
    std::sort(svec.begin(), svec.end());                                        // sort alphabetically
    svec.erase((std::unique(svec.begin(), svec.end())), svec.end());            // remove duplicates

    std::stable_sort(svec.begin(), svec.end(), [](const std::string &s1, const std::string &s2) { return s1.size() < s2.size(); });    // sort .size()
    auto n = std::find_if(svec.begin(), svec.end(), [sz](const std::string &s) { return s.size() >= sz; });             // sort by sz arg

    auto count = svec.end() - n;

    std::for_each(n, svec.end(), [](const std::string &s) {std::cout << s <<std::endl;});


}

int main()
{
    //e1011();
    //e1012();
    //e1013();

    /*e10.14
    int a = 10, b = 20;
    auto f = [a,b]() { return a + b;};
    std::cout << f() <<std::endl;
    */

   /*e10.15
   int i = 23;
   std::cout << e1015(i) <<std::endl;
   */

  //e1016();

  std::vector<std::string> s = {"hello", "world", "how", "are", "are", "this", "yeah"};

  e1016(s, 5);


    return 0;
}