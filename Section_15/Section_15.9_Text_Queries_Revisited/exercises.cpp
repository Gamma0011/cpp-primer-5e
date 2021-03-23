#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
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

    e15.34  - For the expression built on pg 638:
                Query q = Query("fiery") & Query("bird") | Query("wind");


            a) List constructors executed in processing expression.
                    Query("fiery") - Query, WordQuery Constructor
                    Query("bird") - Query, WordQuery Constructor
                    Query("wind") - Query, WordQuery Constructor
                    & - Query, AndQuery, BinaryQuery
                    | - Query, OrQuery, BinaryQuery
            b) List calls to rep that are made from cout << q
                    Query -> Query_base ->
                            OrQuery (lhs) -> Query -> Query_base ->
                            AndQuery (lhs) -> Query -> Query_base -> WordQuery
                            AndQuery (rhs) -> Query -> Query_base -> WordQuery
                            OrQuery (rhs) -> Query -> Query_base -> Word_Query

                            ((fiery & bird) | wind)

            c) List calls to eval made from q.eval();
                Query -> Query_base -> WordQuery ("fiery")
                Query -> Query_base -> WordQuery ("bird")
                Query -> Query_base -> WordQuery ("wind")
                Query -> Query_base -> AndQuery ("fiery", "bird")
                Query -> Query_base -> OrQuery (AndQuery Outcome, "wind")

                
    
    e15.39  - Implement the Query and Query_base classes. Test your application by evaluating and printing a query.

*/

void e1539() {
    Query q = Query("fiery") & Query("bird") | Query("wind");
    std::cout << q;


}

int main(int argi, char **argc)
{
    std::ifstream open(argc[1]);
    std::ifstream open("text.txt");

    if (open) {
        
    } else {
        std::cerr << "No File Provided!" <<std::endl;
        return -1;
    }


    return 0;
}