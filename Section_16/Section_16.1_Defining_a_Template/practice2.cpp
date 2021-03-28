#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "blob_template.h"
#include "blobptr_template.h"

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

            template<typename T> Blob<T>::Blob(): data(std::shared_ptr<std::vector<T>>()) { };
        
        *Initializing the default template constructors*
            Blob<std::string> b = {"test"};
            Blob<int> i = {0,1,2,3};
        
    || INSTANTIATION OF CLASS-TEMPLATE MEMBER FUNCTIONS ||
        A class template is instantiated only if the program uses that member function. If a member isn't used, it's not instantiated.
         This allows us to instantiate a class with a type that may not meet the requirements for some of the template's operations.

        *Note* By default, a member of an instantied class template is instantied only if the member is used.

        Blob<int> squares = {0,1,2,3,4,5,6,7,8,9};

        // calling squares.size() instantiates Blob<int>'s size function
        for (std::size_t i = 0 ; i != squares.size() ; ++i) {
            squares[i] = i*i;
        }

    || SIMPLIFYING USE OF A TEMPLATE CLASS NAME INSIDE CLASS CODE ||
        Inside the scope of the class template itself, we may use the name of the template WITHOUT ARGUMENTS.

        *see blobptr_template.h

        Within the scope of a class template, the compiler treats references to the template itself as if we supplied matching arguments
         to the template's own parameters.

         ex. Within BlobPtr, we can declared overloaded -- and ++ in this way:

                BlobPtr& operator++();
                BlobPtr& operator--();          instead of:
                BlobPtr<T>& operator++();
                BlobPtr<T>& operator--();

    || USING A CLASS TEMPLATE NAME OUTSIDE OF THE CLASS TEMPLATE BODY ||
        However, when we define these overloads outside of the scope of the class, we must specify that the return type returns a BlobPtr instantiated 
         with the same type as the class. When we're within the scope of the function, we are now in the scope of the class, so we don't have to 
         declare the type.

        template<typename T>
        BlobPtr<T> BlobPtr<T>::operator++() {       // sets us within class with type T
            BlobPtr ret = *this;                    // already in scope of class with type T, therefore can write BlobPtr instead of BlobPtr<T>
            ++*ret;
            return ret;
        }

        *NOTE* Inside the scope of a class template, we may refer to the template without specifying template arguments.

    || CLASS TEMPLATES AND FRIENDS ||
        When a class contains a friend declaration, the class and the friend can independently be templates or not. 
            - A class template that has a nontemplate friend grants that friend access to all the instantiations of the template.
            - A class template that has a template friend controls whether friendship includes all instantiations of the template or only specific instantations.

        || ONE-TO-ONE FRIENDSHIP ||
            Most common form of friendship establishes friendship between corresponding instantiations of the class and its friend. For example,
             our Blob class should declare the BlobPtr class and a template version of the Blob equality operator as friends.

            To refer to a specific instantiation of a template (class or function) we must first declare the template itself.

                template<typename> class BlobPtr;
                template<typename> class Blob;          // forward declaration
                template<typename T> bool operator==(const Blob<T>&, const Blob<T>&);

                // within class Blob
                friend class BlobPtr<T>;
                friend bool operator==<T>(const Blob<T>&. const Blob<T>&);

            We first start by declaring Blob, BlobPtr and operator== are templates. These are needed for the parameter declaration in operator== function
             and friend declarations in Blob. The friend declarations use Blob's template parameter as their own template argument. As a result,
             friendship is restricted to those instantiations of BlobPtr and the equality operator that are instantiated with the same type.

             Blob<char> ca;     // BlobPtr<char> and operator==<char> are friends
             Blob<int> ia;      // BlobPtr<int> and operator==<int> are friends

             The same rules of friendship apply. ca and ia are Blobs, but are unique, therefore have no special access to eachother.

        || GENERAL AND SPECIFIC TEMPLATE FRIENDSHIP ||
            A class can make every instantiation of another template its friend, or it may limit friendship to a specific instantation.
                see. pal_template.h

        || BEFRIENDING THE TEMPLATE'S OWN TYPE PARAMETER ||
            We can make a template type parameter a friend:

                template<typename T> class Bar { friend Type; };       // grants access to the type used to instantate Bar

            Whatever type is used to instantiate Bar is a friend. Instanting Bar<Sales_data> would make Sales_data a friend of Bar.
             Additionally, we can use this to create friendship with built-in types -- Bar<int>; *Not sure what the benefit of this is though*

        || TEMPLATE TYPE ALIASES ||
            An instantiation of a class template defines a class type as with any other class type, we can define a typedef referring to the instantiated class.

                typedef Blob<std::string> StrBlob;      // StrBlob synonym for Blob<std::string>

            By declaring this, we can now use StrBlob as before. Because a template is not a type, we cannot declare a synonym for Blob<T>

            With C++11, we can define a type alias for a class template:
                template<typename T> using twin = pair<T,T>;
                twin<std::string> authors;          // authors is a pair <std::string, std::string>

            When we define a template type alias, we can fix one or more of the template parameters.
                template<typename T> using PartNo = pair<T, unsigned>;
                PartNo<std::string> books;      // books is pair<string,unsigned>
                PartNo<Vehicle> cars;           // cars is pair<Vehicle,unsigned>
                PartNo<Student> kids;           // kits is pair<Student,unsigned>

        || STATIC MEMBERS OF CLASS TEMPLATES ||

            *see foo_template.h

            template<typename T> class Foo {
            public:
                static std::size_t count() { return ctr; }
            private:
                static std::size_t ctr;
            };

            Declaration of static members in templates means that there is only one instance of ctr and count for each type. 
             Foo<int>::ctr and Foo<int>::count || Foo<string>::ctr and Foo<string>::count

            Remember, instantiation happens when things are called:
                
                Foo<int> fi;                // Foo<int> class and ctr instaniated
                auto ct = Foo<int>::count;  // instantiates count()
                ct = fi.count();            // uses Foo<int>::count()
                ct = foo::count();          // error, which template type?

            *A static member function is only instantied if it is used in the program


*/

int main()
{

    return 0;
}