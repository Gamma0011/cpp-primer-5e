#include <iostream>
#include <vector>
#include <string>

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

*/

template<typename T>
T fcn(T a, T b);

int main()
{
    char c = 'c';

    fcn(c, 'c');

    return 0;
}