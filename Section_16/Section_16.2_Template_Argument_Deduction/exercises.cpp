#include <iostream>
#include <vector>
#include <string>
#include <memory>

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

int main()
{
    //e1638();
    e1639();

    return 0;
}