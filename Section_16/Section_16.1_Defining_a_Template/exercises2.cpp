#include <iostream>
#include <string>
#include <vector>

#include "screen.h"

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

                **TO DO**
*/


void e1614() {
    Screen<std::size_t> screen1;
    std::cin >> screen1;
    std::cout << screen1;
}

int main()
{
    e1614();

    return 0;
}