#include <iostream>
#include <string>
#include <vector>

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

*/


int main()
{

    return 0;
}