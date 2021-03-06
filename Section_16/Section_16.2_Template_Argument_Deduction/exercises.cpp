#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <utility>

/*
    e16.32  - What happens during template argument deduction?
                Mostly instantiation. There are very few cases where conversions happen instead of instantation.
                    1st case - conversion from non-const to const type.
                    2nd case - conversion from reference to pointer type.
    
    e16.33  - Name two type conversion allowed on function arguments involved in template argument deduction.
                Non-const to const type conversions and reference to pointer type conversions.

    e16.34  - Given only the following code, explain whether each of these calls is legal.

                template<class T> int compare(const T&, const T&);
                a) compare("Hi", "World");          // types differ - both passed as arrays, but hi is const char[2], world is const char[5]; 
                b) compare("bye", "dad");           // objects of same type and length; legal

    e16.35  - Which, if any of the following calls are errors? If call is legal, what is type T?

                template<typename T> T calc(T, int);
                template<typename T> T fcn(T,T);

                double d; float f; char c;

                a) calc(c, 'c');            // legal. conversion from char to int. T is type char
                b) calc(d, f);              // legal, conversion from float to int. T is type double
                c) fcn(c, 'c');             // legal, types are the same. const-ness of 'c' dropped.
                d) fcn(d, f);               // illegal, types differ and template expects only one type.

    e16.36  - What happens in the following calls?

                template<typename T> f1(T,T);
                template<typename T1, typename T2> f2(T1,T2);

                int i = 0, j = 42, *p1 = &i, *p2 = &j;
                const int *cp1 = &i, *cp2 = &j;

                a) f1(p1, p2);          // legal (int*, int*)
                b) f2(p1, p2);          // legal (int*, int*)
                c) f1(cp1, cp2);        // legal (const int*, const int*)
                d) f2(cp1, cp2);        // legal (const int*, const int*)
                e) f1(p1, cp1);         // cannot deduce T, types don't match - passes (int*, const int*)
                f) f2(p1, cp1);         // legal (int*, const int*)

    e16.37  - The library max function has two function parameters and returns the larger of the args. This function has one template parameter.
                Could you call max passing an int and a double? If so, how, why or why not?

                You cannot pass an int or a double in the way of generic comparison or by variable. However, you can do so by specifying explicitly
                 the type you want the compiler to use.

                    ex. max<int>(10.23, 11);
                        max<double>(100.23, 99);

    e16.38  - When we call make_shared, we have to provide an explicit template argument. Explain why the argument is needed and how it is used.
                https://www.cplusplus.com/reference/memory/make_shared/

                make_shared<T> specifies the type in the return of shared_ptr<T>.

                    auto a = std::make_shared<int>(19);     a is std::shared_ptr<int>

    e16.39  - Use an explicit template argument to make it sensible to pass two string literals to the original versions of compare.

    e16.40  - Is the following function legal? Why or why not? What are the restrictions on the argument types that can be passed and what is the return type?

                template<typename T>
                auto fcn3(It beg, It end) -> decltype(*beg + 0) {
                    return *beg;
                }

                The following function is legal, but it does have restrictions. The most glaring is that because of the + 0, *beg must be an arithmetic type. 
                 So, iterations of char or string would not be valid.
    
    e16.41  - Write a version of sum with a return type that is guaranteed to be large enough to hold the result of the addition.
                
                template<typename T>
                auto sum(T x, T y) -> decltype(x + y) {
                    return x+y;
                }

    e16.42  - Determine the type of T and val in each of the following calls:

                template<typename T> void g(T&& val);

                int i = 0; const int ci = i;

                a) g(i);        // int& &&, collapses to int&
                b) g(ci);       // const int& &&, collapses to const int&
                c) g(i * ci);   // arithmetic of i * ci == int&& &&, collapses to int&&

    e16.43  - Using the function defined in the previous exercise, what would the template parameter of g be if we called g( i = ci ) ?
                i = ci would be an lvalue. Deduced as int& because of collapsing int& &&.

    e16.44  - Using the same three calls in e16.42, determine the types for T if g's function parameter is declared as T and not T&&. 
                What if we use const T&?

                T
                a) g(i);    // i is type int. 
                b) g(ci);   // i is deduced as int. top-level const ignored
                c) g(i*ci); // rvalue, deduced as int, copied to lvalue int

                const T&
                a) g(i);    // i is type int, becomes const int&
                b) g(ci);   // i is deduced as int, top-level const ignored
                c) g(i*ci); // rvalue deduced as int. 

                *REMEMBER* Lvalues can accept rvalues

    e16.45  - Given the following template, explain what happens if we call g on a literal value such as 42. What if we call g on a variable of type int?
                template<typename T> void g(T&& val) { std::vector<T> v; }

                g(42);      42 is an rvalue type int. T resolves to int. vector<int>
                g(i);       i is an lvalue. Collapses to int&. T is int&. Because of this, vector<int&>

    e16.46  - Explain this loop from StrVec::reallocate()

                for (std::size_t i = 0 ; i != size() ; ++i) {
                    alloc.construct(dest++, std::move(*elem++));
                }

                This works by getting the size() of the current container. While iterating through each element of that container, we call on
                 .construct() which takes two arguments, first the destination, and the second the source. We call std::move on the dereferenced element
                 and move that into destination. After that, destination is incremented to the next position, as is the container from elem.

    e16.47  - Write your own version of the flip function and test it by calling functions that have rvalue and lvalue reference parameters.

*/

template<typename T>
T fcn(T a, T b);

// e16.39
template<typename T>
int compare(const T &s1, const T &s2) {
    if (s1 > s2) return 1;
    if (s1 < s2) return -1;
    return 0;
}

template<typename T>
auto fcn3(T beg, T end) -> decltype(*beg + 0) {
    return *beg;
}

template<typename T>
auto sum(T x, T y) -> decltype(x + y) {
    return x+y;
}

// e16.44
template<typename T>
void g(T) {
    std::cout << "g(T)" << std::endl;
}

template<typename T>
void g(T&& val) {
    std::vector<T> v;
}

// e16.47   
template<typename F, typename T1, typename T2>
void flipdis(F f, T1 &&t1, T2 &&t2) {
    f(std::forward<T1>(t1), std::forward<T2>(t2));
}

/*
template<typename T>
void g(const T&) {
    std::cout << "g(const T&)" << std::endl;
}
*/


void e1634() {
    char c = 'c';
    //fcn(c, 'c');
}

void e1637() {
    int i = 10;
    double d = 123.03;

    std::cout << std::max<int>(i,d) << '\t'
              << std::max<double>(i,d) << std::endl;
}

void e1638() {
    int i = 10;
    auto a = std::make_shared<int>(i);
    std::cout << a << '\t' << *a << std::endl;
}

void e1639() {
    std::cout << compare<const char*>("Hello", "World") 
              << std::endl;
}

void e1640() {
    std::vector<std::string> svec = {"hello", "world"};
    std::vector<int> ivec = {0,1,2,3,4,5};
    std::vector<float> fvec = {1.2,5.4};

    //std::cout << fcn3(svec.begin(), svec.end()) << std::endl;
    std::cout << fcn3(ivec.begin(), ivec.end()) << std::endl;
    std::cout << fcn3(fvec.begin(), fvec.end()) << std::endl;
}

void e1641() {
    short x = 32766;
    short y = 32766;

    std::cout << x << '\t' << y <<std::endl;
    std::cout << "Sum: " << sum(x,y) << std::endl; 
}

void recall(const int &a, const int &b) {
    std::cout << b << '\t' << a << std::endl;
}

void e1647() {
    // pass rvalues
    flipdis(recall, 42, 10);

    // pass lvalues
    int a(100), b(2);
    flipdis(recall, a, b);

    // pass r and lvalues
    flipdis(recall, 77, b);

}

int main()
{
    //e1638();
    //e1639();
    //e1640();
    //e1641();
    e1647();

    return 0;
}