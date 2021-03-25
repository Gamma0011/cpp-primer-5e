#include <iostream>
#include <string>
#include <vector>
#include <list>

/*
    e16.1   - Define instantiation.
                The creation of a function or class by the compiler from a template.

    e16.2   - Write and test your own versions of the compare functions.
                see bool compare(), class c1, bool operator==(), and void e162()

    e16.3   - Call your compare function on two Sales_data objects
                *Similar to the class c1 implementation. Sales_data would need to define bool operator==.
                error: no match for 'operator=='

                Works after definiting bool operator==(const Sales_data&, const Sales_data&);

    e16.4   - Write a template that acts like the library find algorithm. Function needs two template type parameters:
                1st - represent function's iterator
                2nd - for value type

                Use function to find a given value in a vector<int> and list<string>

                template<typename T, typename C> 
                    std::string lookup(T t, C c) {
                        for (auto i = c.begin() ; i != c.end() ; ) {
                            if (*i == t) {
                                return "Element exists in the container.";
                            } else {
                                ++i;
                            }
                        }
                    return "Element does not exist in the container";
                }

    e16.5   - Write a template version of the print function from pg 217 that takes a array& and can handle arrays of any size and element type.

                void print(const int ia[], size_t size) {
                    for (size_t i = 0; i != size; ++i) {
                        std::cout << ia[i] <<std::endl;
                    }
                }

                *Template Version:*
                template<typename C, typename N>
                    void print(const C c, N n) {
                    for (N i = 0 ; i != n ; ++i) {
                        std::cout << c[i] <<std::endl;
                    }
                }
    e16.6   - How do you think the library begin and end functions that take an array argument work? Define a version of these functions.
                *NEED TO DO*

*/

// e16.4
template<typename T, typename C> 
std::string lookup(T t, C c) {
    for (auto i = c.begin() ; i != c.end() ; ) {
        if (*i == t) {
            return "Element exists in the container.";
        } else {
            ++i;
        }
    }
    return "Element does not exist in the container";
}

// e16.5
template<typename C, typename N>
void print(const C c, N n) {
    for (N i = 0 ; i != n ; ++i) {
        std::cout << c[i] <<std::endl;
    }
}

// e16.2
template<typename T>
bool compare(const T& v1, const T& v2) {
    if (v1 == v2) return true;
    return false;
}

class c1 {
    friend bool operator==(const c1&, const c1&);
public:
    c1() = default;
    c1(int x) : i(x) { };

private:
    int i;
};
// bool operator== overload for c1 comparison
bool operator==(const c1& a, const c1& b) {
    return a.i == b.i;
}

void e162() {
    std::cout << compare(1,3) << std::endl;

    c1 a(10);
    c1 b(10);
    std::cout << compare(a,b) << std::endl;
}

// Sales_data

class Sales_data {
    friend bool operator==(const Sales_data&, const Sales_data&);
public:
    Sales_data() = default;
    Sales_data(std::string bn, std::size_t us, double p) : 
        book_no(bn), units_sold(us), price(p), revenue(p*us) { };
private:
    std::string book_no;
    std::size_t units_sold;
    double price;
    double revenue;
};

bool operator==(const Sales_data& s1, const Sales_data& s2) {
    return s1.book_no == s2.book_no;
}


void e163() {
    Sales_data s1("1-111-1", 10, 9.99), s2("1-111-1", 20, 19.99);

    std::cout << compare(s1, s2) <<std::endl;
}

void e164() {
    std::vector<int> ivec{0,1,2,3,4,5,6};
    std::list<std::string> slist{"hello", "world", "today", "is"};

    std::cout << lookup(3, ivec) <<std::endl;
    //std::cout << lookup("yes", slist) <<std::endl;   
}

void e165() {
    std::size_t sz = 5;
    int ia[sz] = {0,1,2,3,4};

    print(ia, sz);
}

int main()
{
    // e162();
    // e163();
    // e164();
    e165();
    

    return 0;
}