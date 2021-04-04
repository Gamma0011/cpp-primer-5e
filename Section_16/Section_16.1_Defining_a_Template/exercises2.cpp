#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

#include "blob_template.h"
#include "screen.h"
#include "vec.h"
//#include "debug_delete.h"
#include "text_query.h"

/*
    e16.9   - What is a function template? What is a class template?
                Function template - creates an outline for a function to be instantiated with.
                Class template - creates an outline for a class to be instantiated.
    
    e16.10  - What happens when a class template is instaniated?
                When a class is instantied, the specific constructor is called and instantiates whatever is used. Unused functions
                 or objects remain non-stantiated until called.
    
    e16.11  - The following definition of List is incorrect. How would you fix it?

                ListItem must have type declared within context of class List:
                *Correct:
                        void insert(ListItem<elemType> *ptr, elemType value);
                        ListItem<elemType> *front, *end;

                template<typename elemType> class ListItem;
                template<typename elemType> class List {
                public:
                    List<elemType>();
                    List<elemType>(const List<elemType> &);
                    List<elemType>& operator=(const List<elemType> &);
                    ~List();
                    void insert(ListItem *ptr, elemType value);
                private:
                    ListItem *front, *end;
                };
    
    e16.12  - Write your own versions of Blob and BlobPtr. Including various const members not shown in text.

                see. blobptr_template.h and blob_template.h
    
    e16.13  - Explain which kind of friendship you chose for the equality and the relational operators in BlobPtr.
                Since all classes are templates, we use one-to-one friendship, declared in blob_template.h as a forward declaration
                 friend template<typename T> class BlobPtr; then within the Blob class as friend class BlobPtr<T>

    e16.14  - Write a Screen class template that uses nontype parameters to define the height and width of a screen.    

    e16.15  - Implement input and output operations for your screen template. Which if any, friends are needed to make input and output operators work?
                I had to make both the input and operators friends of class Screen. Input operators should be friends so that they can write to private members,
                 in which case my class had 2. However, I couldn't get the output operator to work by calling public get() members to access the returns of
                 the private members.
    
    e16.16  - Rewrite StrVec class as a template named Vec.

                see. vec.h

    e16.17  - What, if any, are the differences between a type parameter that is declared as a typename and one declared as a class? When must typename be used.

                There's no real difference between the use case of typename and class, and for the most part, they can be interchangeable. However, when 
                 there is a need for use to specifically tell the compiler that we will be passing a type member via a template, we must declare typename
                 within the template parameters list and at the function call to tell the compiler that we are using a type and not a variable.

                        ex. template<typename T> typename T::value_type foo();
    
    e16.18  - Explain each of the following function template declarations and whether any are illegal.

                a)  template<typename T, U, typename V> void f1(T, U, V);           // illegal, need typename
                    template<typename T, typename U, typename V> void f1(T, U, V);
                b)  template<typename T> T f2(int &T);                              // illegal, redefines T
                    template<typename T> T f2(int &t);                              // t is unique parameter definition
                c)  inline template<typename T> T foo(T, unsigned int*);            // illegal. inline in wrong position. need to declare template first
                    template<typename T> inline T foo(T, unsigned int*);        
                d)  template<typename T> f4(T,T);                                   // illegal. no return type declared
                    template<typename T> T f4(T,T);
                e)  typedef char Ctype; template<typename Ctype> Ctype f5(Ctype a); // messy, but legal. Template parameters with same names in global scope hide global scope

    e16.19  - Write a function that takes a reference to a container and prints the elements in that container. Use containers size_type and size members to control loop.  

                see. template<typename T> void print1(const T& t);

    e16.20  - Rewrite the function from the previous exercise to use iterators returned from begin and end to control the loop

                see. template<typename T> void print2(const T& t);

    e16.21  - Write your own version of DebugDelete;
                see. debug_delete.h
    
    e16.22  - Revise our TextQuery programs from 12.3 (pg 484) so that the shared_ptr members use DebugDelete as their deleter.

    e16.23  - Predict when a call operator will be executed in the query program. 
                Every time the shared_ptr's counter == 0, the delete operator is called. Since we're using DebugDelete's operator(),
                 that is called instead of default_delete.
    
    e16.24  - Add a constructor that takes two iterators to your Blob template.
                
                see. blob_template.h

                template<typename T>
                template<typename It>
                Blob<T>::Blob(It b, It e) : data(std::make_shared<std::vector<T>>(b,e)) { };

*/

template<typename T>
void print1(const T& t) {
    if (t.size() == 0) {
        std::cout << "No elements in container." << std::endl;
    } else {
        for (typename T::size_type iter = 0 ; iter != t.size() ; ++iter) {
            std::cout << t[iter] << std::endl;
        }
    }
}

template<typename T>
void print2(const T& t) {
    if (t.size() == 0) {
        std::cout << "No Elements in container." <<std::endl;
    } else {
        for (auto iter = t.begin() ; iter != t.end() ; ++iter) {
            std::cout << *iter <<std::endl;
        }
    }
}

void e1614() {
    Screen<std::size_t> screen1;
    std::cin >> screen1;
    std::cout << screen1;
}

void e1616() {
    Vec<int> ivec;
    int a = 1;
    int b = 2;

    std::cout << ivec.size() << " " << ivec.capacity() << "\n";

    ivec.push_back(a);
    ivec.push_back(b);

    std::cout << ivec.size() << " " << ivec.capacity() <<std::endl;
}

void e1619() {
    std::vector<int> ivec = {1,2,3,4,5};
    print1<std::vector<int>>(ivec);

    std::string s = "Hello World";
    print1<std::string>(s);
}


void e1620() {
    std::vector<int> ivec = {1,2,3,4,5};
    print1<std::vector<int>>(ivec);

    std::string s = "Hello World";
    print1<std::string>(s);
}

void e1621() {
    int *ip = new int;
    DebugDelete()(ip);
}

void e1622() {
    std::ifstream open("text.txt");

    if (!open) {
        std::cerr << "ERROR: Cannot open file." <<std::endl;
    } else {
        TextQuery document(open);
        print(std::cout, document.query("C++"));
    }

}

void e1624() {
    std::vector<std::string> ivec = {"hello", "world"};

    Blob<std::string> sb(ivec.begin(), ivec.end());
}

int main()
{
    //e1614();
    //e1616();
    //e1619();
    //e1620();
    //e1621();
    //e1622();

    return 0;
}