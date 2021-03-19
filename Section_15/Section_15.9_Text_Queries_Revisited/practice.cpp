#include <iostream>
#include <string>
#include "query.h"

/*
    We will now expand the original query.h from Chapter 12 to support additional functionality. This includes:

        - Finaling all lines that match a given string
        - ~ operator to print lines not matching string
        - | operator returning lines of either two queries
        - & operator, returning lines for both

        _ Additionally, we should be able to combine these: fiery & bird | wind

    We'll use normally C++ precedence rules, meaning we'll match whatever comes first, either fiery & bird or wind

    Our output will print the query, using parentheses to indicate the way in which the query was interpreted.

    || AN OBJECT-ORIENTED APPROACH ||
        We might think we should use the TextQuery class to represent our word query and derive our other queries from that class.
         However, that is flawed.

        The four query classes (WordQuery, NotQuery, AndQuery, OrQuery) are all siblings and not related by inheritance. However,
         they do share the same interface, therefore, we'll want to create an ABSTRACT BASE CLASS (Query_base), which will
         serve as the root of our Query hierarchy.
        
        eval and rep will be pure virtual functions. Each class that represents a particular query must override these functions.

        WordQuery and NotQuery will be directly dervied from our Abstract Base. AndQuery and OrQuery will inherit from a derived
         class of Query Base (Abstract Base class).

         Base_Query -> WordQuery
                    -> NotQuery
                    -> BinaryQuery  -> AndQuery
                                    -> OrQuery

    *Note* Design of inheritance is very complicated and well beyond this book. However, there is one important design guide
    * to be familiar with. When we define a class as publicly inherited from another, the derived class should reflect
    * an "Is A" relationship to the base class. In well-designed class hierarchies, objects of publicly derived class
    * can be used whenever an object of base class is expected.
    * 
    * Another common relationship among type is "Has A" relationship. This implies membership. An example is the Bookstore program,
    * Bulk_quote is kind of a quote, but has a different pricing strategy. The Bookstore classes must HAVE A price and ISBN.
    
    || HIDING HIERARCHY IN AN INTERFACE CLASS ||
        We'll define an interface class named Query, which will hide the hierarchy. The Query class will store a pointer to Query_base
         That pointer will be bound to an object of type derived from Query_base. The Query class will provide the same operations as
         Query_base: eval to evaluate query and rep to generate a string version of the query. It will also define an overloaded
         output operator to display the query.

        Users will create and manipulate Query_base objects indirectly through Query. We'll create 3 overloaded operators and a
         Query constructor that takes a string. These functions will dynamically allocate a new object of type derived from Query_base.

         - & operator will generate Query bound to a new AndQuery
         - | operator will generate Query bound to a new OrQuery
         - ~ operator will generate Query bound to a new NotQuery
         - Query constructor takes string and generates a new WordQuery

    || UNDERSTANDING HOW THE CLASSES WORK ||
        Most of the work in the application consist of building objects to represent the user's query. Once the tree of objects is build up,
         evaluating a query is basically a process of following each link, asking each object to evaluate or display itself. 

        If we call eval on q (Query q = Query("fiery") & Query("bird") | Query("wind"); ), the call asks the OrQuery to which q points to eval itself.
         This calls eval on the two operands, WordQuery ("wind") and AndQuery ("fiery") & ("bird"). AndQuery is responsible for generating the results of its
         two WordQueries. 
        
        The hardest part of OOP is understanding the design. Once you are thoroughly comfortable with the design, implementation flows naturally. 
            See 15.1 as a guide for how to design the Query class.


*/

int main()
{


    return 0;
}