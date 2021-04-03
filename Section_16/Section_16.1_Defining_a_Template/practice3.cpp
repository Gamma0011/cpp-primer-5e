#include <iostream>
#include <string>

/*
    A template parameter list has no intrinsic meaning -- we normally use Typename T, but T can be anything. 

        ex. template<typename Foo> Foo calc(const Foo&, const Foo&);

    
    || TEMPLATE PARAMETER AND SCOPE ||
        Templates follow the normal rules of scope, meaning that parameters declared within the context of the template
         exist within the template. However, be sure to note that a template named used as a parameter cannot be
         reused within that template scope.

        ex. template<typename A, typename B> void f(A a, B b) {
            A temp = a;     // okay, a has same type.
            double b;       // error, redeclares b from type B to type double
        }

        Additionally, a template name cannot be reused within a parameter list. This is illegal: template<typename V, typename V>

    || TEMPLATE DECLARATIONS ||
        A template declaration MUST include template parameters. ex. template<typename T> 

        *NOTE* Declarations for all the templates needed by a given file usually should appear together at the beginning of that file before any code uses those names.

    || USING CLASS MEMBERS THAT ARE TEMPLATES ||
        By default, the compiler assumes that a name accessed through scope operator is not a type. As a result, if we want to use a type member of
         a template type parameter, we must explicitly tell the compiler that the name is a type.

        ex. template<typename T>
            typename T::value_type top(const T& c) {
                if (!c.empty()) {
                    return c.back();
                } else {
                    return typename T::value_type();
                }
            }
        
        *Note* When we want to inform the compiler that a name represents a type, we must use keywork typename and not class.

    || DEFAUlT TEMPLATE ARGUMENTS ||
        We can also supply default template arguments. 

        ex. see int compare;
        
        In this template, typename F is the std::less<T> function, which is default initialized as parameter 3 in function int compare()
         In the case of passing standard types, int, string, double, std::less can be used. For user-defined types, such as Sales_data,
         we must pass a bool function doing our own custom comparison.

        *A template parameter may have a default argument only if all the parameters to its right also have default arguments.
    
    || TEMPLATE DEFAULT ARGUMENTS AND CLASS TYPES ||
        Whenever we have a class template, we must always follow the template's name with brackets, which indicate that a class must
         be instantiated from a template. If a class template provides default arguments for its template parameters, and we want to use
         those defaults, we must put an empty bracket pair following the template's name.

            see. template<class T = int> class Numbers { };

                Numbers<long double> lots_of_precision; // uses long double
                Numbers<> average_precision;            // defaults to int
        
*/

template<typename T, typename F = std::less<T>>
int compare(const T &v1, const T &v2, F f = F()) {
    if (f(v1, v2)) return -1;
    if (f(v2, v1)) return 1;
    return 0;
}

template<class T = int> class Numbers {
public:
    Numbers(T v = 0) : val(v) { };
private:
    T val;
};

Numbers<long double> lots_of_precision; // uses long double
Numbers<> average_precision;            // defaults to int

int main()
{


    return 0;
}