#include <iostream>
#include <string>

/*
    || MEMBER TEMPLATES OF ORDINARY (NONTEMPLATE) CLASSES ||
        Ordinary classes can have member templates. As an example, look at void operator() within class DebugDelete;

        In this example, our class has an overloaded operator that takes a pointer and deletes the given pointer. Because
         we want to be able to accept pointers of any and all types, we've defined operator() as a template taking a type T.

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


int main()
{


    return 0;
}