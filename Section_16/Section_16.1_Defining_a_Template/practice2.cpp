#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "blob_template.h"

/*
    || CLASS TEMPLATES ||  
        A class template is a blueprint for generating classes. The compiler cannot deduce the template parameter types for a class template.

        In order to use a class template, we must supply additional information inside angle brackets following the template's name. That
         additional information is the list of template arguments to use in place of template parameters.        

    || DEFINING A CLASS TEMPLATE ||
        We'll implement a template of StrBlob, naming it Blob to denote that it can now be used on objects of any type. We'll use template parameters
         as stand-ins for types or values that will be supplied when the template is used.

            *see blob_template.h

    || INSTANTIATING A CLASS TEMPLATE ||
        When we use a class template, we must supply extra information in the form of EXPLICIT TEMPLATE ARGUMENTS, bound to the template's parameters.

        The compiler will instantiate a class from the template.

        To define a Blob class:
            Blob<int> ia;           // empty Blob<int>
            Blob<int> ib = {0,1,2}; // Blob<int> with 3 elements
        
        With these two class definitions, the compiler with create two Blob classes of type <int>, replacing each instance of <T> with the given 
         template argument, in our case, int.

            Blob<std::string> would instantiate instances of <T> with <std::string> in the same way Blob<std::size_t> would created <std::size_t>s


        *NOTE* Each instantiation of a class template constitutes an independent class. The type Blob<string> IS NOT RELATED TO Blob<int> and HAS NO ACCESS TO MEMBERS.

    || REFERENCES TO A TEMPLATE TYPE IN THE SCOPE OF THE TEMPLATE ||
        Remember that the name of a class template is not the name of a type. A class template is used to instantiate a type, and an instantiated type
         always includes template arguments. Class templates can be confusing because they generally don't use the name of an actual type (or value)
         as a template argument. Instead, we often use the template's own parameter(s) as the template arguments.

        In our class Blob template, data uses two templates, vector and shared_ptr. We supply the type (for example Blob<int>) to instantiate data:
            std::shared_ptr<std::vector<int>> data;
    
    || MEMBER FUNCTIONS OF CLASS TEMPLATES ||
        We can define the member functions of a class template either inside or outside the class body. As with any other class, members defined inside
         the class body are implicitly inline.
        
        A class template member function is a normal function, but each instantiation of the class template has its own versions of the member functions.

        A member function defined outside the class template body starts with the keyword template followed by the class' template parameter list.

        *void check() member function defined outside of class template.
            template<typename T> void Blob<T>::check(size_type i, const std::string &msg) const;
        
    || BLOB CONSTRUCTORS ||
        A constructor starts by declaring the template parameters for the class template for which it is a member:

            template<typename T> void Blob<T>::Blob(): data(std::shared_ptr<std::vector<T>>()) { };

        *STOPPED HERE*


*/

int main()
{

    return 0;
}