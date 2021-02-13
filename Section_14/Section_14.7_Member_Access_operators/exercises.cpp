#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "strBlobClass.h"
#include "conststrblob.h"
#include "strBlobPtrClass.h"

/*
    e14.30  - Add dereference and arrow operators to StrBlobPtr class and ConstStrBlobPtr class.
                *Note* ConstStrBlobPtr must return const& because it points to const Vector

                see.    strBlobPtrClass.h
                        conststrblob.h

                    std::string& StrBlobPtr::operator*() const {
                        auto e = check(curr, "ERROR");
                        return (*e)[curr];
                    }
                    std::string* StrBlobPtr::operator->() const {
                        auto e = check(curr, "ERROR");
                        return & this->operator*();
                    }
                    const std::string& ConstStrBlob::operator*() const {
                        auto e = check(curr, "ERROR");
                        return (*e)[curr];
                    }
                    const std::string* ConstStrBlob::operator->() const {
                        auto e = check(curr, "ERROR");
                        return & this->operator*();
                    }
    e14.31  - Our StrBlobptr class does not define the copy constructor, assignment operator, or a destructor.
                Is that okay?

                This is okay because only two objects are defined, both of which contain destructors of built-in type.
                A weak pointer only refers to an object, but does not hold any data itself. And, size_t is a build-in type
                that will call its own destructor.
    
    e14.32  - Define a class that holds a pointer to a StrBlobPtr. Define the overloaded arrow operator for the class.
                    see. class PtrStrBlobPtr;
*/

class PtrStrBlobPtr {
public:
    PtrStrBlobPtr();
    PtrStrBlobPtr(StrBlobPtr p) : psbp(std::make_shared<StrBlobPtr>(p)) { };

    std::string& PtrStrBlobPtr::operator*() const {
        auto e = psbp->check(psbp->curr, "ERROR");
        return (*e)[psbp->curr];
    }
    std::string* PtrStrBlobPtr::operator->() const {
        return & this->operator*();
    }
private:
    std::shared_ptr<StrBlobPtr> psbp;
};

int main()
{


    return 0;
}