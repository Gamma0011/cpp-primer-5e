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
        
    || CONTROLLING INSTANTIATIONS ||
        The fact that instantiations are generated when a template is used means that the same instantiations may appear in multiple object files.
         When two or more separately compiled source files use the same template with the same arguments, there is an instantiation of that template
         in each of those files.
        The overhead associated with instantiating the same template in multiple files can be significate. To avoid this, we can declare an
         EXPLICIT INSTANTIATION.

            Syntax:     extern template declaration;        // instantiation declaration   
                        template declaration;               // instantiation definition

        When the compiler sees EXTERN declaration, it will not generate code for that instantiation file under the premise that there will be a 
         NON-EXTERN declaration use of that instantiation elsewhere in the program. There must be exactly ONE definition for that instantiation.
         The EXTERN declaration must appear before any code that uses that instantiation:

            File name: application.cc
            /** these templates must be instantiated elsewhere in the program
            extern template class Blob<std::string>;
            extern template int compare(const int&, const int&);
            Blob<std::string> sa1, sa2;     // instantiation will appear elsewhere

            /** Blob<int> and its initializer_list constructor instantiate file
            Blob<int> a1 = {0,1,2,3,4,5,6,7,8,9};
            Blob<int> a2(a1);                       // copy constructor instantiated in this file
            int i = compare(a1[0], a2[0]);          // instantiation will appear elsewhere.

        The file application.o will contain instantiations for Blob<int>, initializer_list and copy constructors for class Blob.
         compare<int>() and Blob<string> will not be instantiated. As a result, there must be definitions in some other file in program:

            File name: templatebuild.cc
            /** instantiation file must provide a nonextern definition for every type and function that other files declare as extern
            template int compare(const int&, const int&);
            template class Blob<std::string>;               // instantiated all members of class template.

        When the compiler sees an instantiation definition, it generates code. The file templatebuild.o will contain definitions for
         compare<int>() and Blob<string> class. We MUST link templatebuild.o with application.o files

        *REMEMBER* There must be an explicit instantiation definition somewhere in the program for every instantiation declaration.
    
    || INSTANTIATION DEFINITIONS INSTANTIATE ALL MEMBERS ||
        An instantiation definition instantiates all members, including those inline. The compiler cannot see which functions the program
         uses from the instantiation definition, and therefore will instantiate all members of class.
        
        *NOTE* An instantiation definition can only be used for types that can be used with every member function of a class template.
    
    || EFFICIENCY AND FLEXIBILITY ||
         The differences between a shared_ptr and a unique_ptr is the strategy of managing the pointers they hold:
            shared_ptr  - shared ownership
            unique_ptr  - owns pointer it holds

        These classes also differ in how they let users override default deleters. 
            We can easily override the deleter of a shared_ptr by passing a callable object when we create or reset the pointer. 
            In contrast, the deleter is part of the type of a unique_ptr, making it more complicated to provide a user deleter.
        
        || BINDING DELETER AT RUN TIME ||
            

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