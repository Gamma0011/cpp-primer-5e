#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <list>
#include <iterator>

/*
    || MEMBER TEMPLATES OF ORDINARY (NONTEMPLATE) CLASSES ||
        Ordinary classes can have member templates. As an example, look at void operator() within class DebugDelete;

        In this example, our class has an overloaded operator that takes a pointer and deletes the given pointer. Because
         we want to be able to accept pointers of any and all types, we've defined operator() as a template taking a type T.

            double* d = new double;
            DebugDelete()(d);           // calls delete d;

    || OVERRIDING DEFAULT DELETER ||
        We can also use DebugDelete to override the deleter or a unique_ptr. To override, we supply the type of deleter
         inside brackets and supply an object of the deleter type to the constructor.

            ex. std::unique_ptr<int, DebugDelete> p(new int, DebugDelete());
                std::unique_ptr<std::string, DebugDelete> p(new std::string, DebugDelete());

            We've stated that p's deleter will have type DebugDelete and we have supplied an unnamed object of that type's p constructor.
             The unique_ptr destructor calls DebugDelete's call operator. As a result these definitions will have been instantiated:
                void DebugDelete::operator()(int *p) const { delete p; }
                void DebugDelete::operator()(std::string *p) const { delete p; }

    || MEMBER TEMPLATES OF CLASS TEMPLATES ||
        We can define a member template of a class template.

        template<typename T> class Blob {
            template<typename It> Blob(It b, It e);
        };

        Here, the constructor has its own template type parameter It, which it uses for its two function parameters. Member templates ARE function templates.
        
        *When we define a member template outside the body of a class template, we must provide the template parameter list for the class template
         *and for the function template. 

         ex.    template<typename T> template<typename It> Blob<T>::Blob(It b, It e) :
                    data(std::make_shared<std::vector<T>>(b,e)) { };

    || INSTANTIATION AND MEMBER TEMPLATES ||
        In order to instantiate a member template of class template, we must supply arguments for template parameters of both the class and member templates.
        
        see. void instantiating_member_templates();

            When we define a1, we explicitly specify that we want to instantiate a version of Blob of type bound to int. From there, the type parameter
             for the constructor's own parameters can be deduced from the type of begin() and end() -- int*. As a result, this is instantiated:

                Blob<int>::Blob(int*, int*);
            
            A2 already uses the instantiated Blob<int> class, but then instantiates the constructor to be Blob(std::vector<long>::iterator, std::vector<long>::iterator);

                Blob<int>::Blob(std::vector<long>::iterator, std::vector<long>::iterator);
            
            A3 does the following:  
                
                Blob<std::string>::Blob(std::list<const char*>::iterator, std::list<const char*>::iterator);
*/

class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr) : os(s) { };
    template<typename T> void operator()(T *p) const {
        os << "Deleting unique_ptr" << std::endl;
        delete p;
    }
private:
    std::ostream &os;
};

template<typename T> class Blob {
public:
    template<typename It> Blob(It b, It e);
    std::shared_ptr<std::vector<T>> data;
};

template<typename T> template<typename It> Blob<T>::Blob(It b, It e) :
    data(std::make_shared<std::vector<T>>(b,e)) { };

void function_template_in_class() {
    double* p = new double;
    DebugDelete d;
    d(p);

    int* ip = new int;
    DebugDelete()(ip);
}

void override_default_deleter() {
    std::unique_ptr<int, DebugDelete> p(new int, DebugDelete());
}

void instantiating_member_templates() {
    int ia[] = {0,1,2,3,4,5,6,7,8,9};
    std::vector<long> vi = {0,1,2,3,4,5,6,7,8,9};
    std::list<const char*> w = {"now", "is", "the", "time"};

    Blob<int> a1(std::begin(ia), std::end(ia));
    Blob<int> a2(std::begin(vi), std::end(vi));
    Blob<std::string> a3(std::begin(w), std::end(w));
}

int main()
{
    // function_template_in_class();
    instantiating_member_templates();

    return 0;
}