#include <iostream>
#include <string>
#include "query.h"

/*
    e15.31  - Given that s1, s2, s3, and s4 are strings, determine what objects are created in the following expressions.

            a) Query(s1) | (Query(s2) & ~ Query(s3))
                3x WordQuery, NotQuery(s3), AndQuery(s2 & s3), OrQuery( s1 & Outcome of AndQuery(s2 & s3))
            b) Query(s1) | Query(s2) & ~ Query(s3)
                3x WordQuery, NotQuery(s3), AndQuery(s2 & s3), OrQuery( s1 & Outcome of AndQuery(s2 & s3))
            c) (Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)))
                4x WordQuery, AndQuery(s1 & s2), AndQuery(s3 & s4), OrQuery(Outcome of AndQueries)

    e15.32  - What happens when an object of type Query is copied, moved, assigned, and destroyed.
                We've left the Query object to have its copy, assignment, move and destructors to be synthesized
                by the compiler. There is only one member of type Query, shared_ptr<Query_base> q; Shared_ptrs
                have their own destructor, which is called when reference count = 0;
    e15.33  - What about objects of Query_base? 
                Query_base is an abstract base class and therefore cannot directly have objects created. It provides
                 a common interface to its derived classes. No operations available in abstract base classes.

    e15.34  - For the expression built on pg 639:
            
            a) List constructors executed in processing expression.

            b) List calls to rep that are made from cout << q
            c) List calls to eval made from q.eval();

*/

int main()
{
    std::string s1("string"), s2("test"), s3("not");

    Query a(s1) ;

    ~a;

    return 0;
}