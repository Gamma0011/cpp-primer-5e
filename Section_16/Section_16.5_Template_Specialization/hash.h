#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <unordered_map>
#include "sales_data.h"

/*
    Specialize hash class must define:
        1) overloaded call operator() that returns size_t and takes object of container's key type
        2) two type members, result_type and argument_type, which are the return and argument types, of call member
        3) Default constructor and copy-assignment operator (can be implicitly defined)

    We can add members to a namespace (more on that in Section 18).
    namespace std{
        *NOTE* any definitions appearing between open and close curlies will be part of std namespace
    }


    Our hash<Sales_data> defintiion starts with template<> which indicates we are defining a fully specialized template named hash, with the specialized
     version being hash<Sales_data>

    We can define the members of a specialization inside the class or out of it. The overloaded call operator must define a hashing function over the 
     values of the given type. This function is required to return the same result every time it is called for a given value. A good hash function
     will (almost always) yield different results for objects that aren't equal.

    We delegate the complexity of defining a hash function to the library for built-in types. 
        hash<std::string> object to generate code for s.bookNo
        hash<unsigned> object to generate code for s.units_sold
        hash<double> object to generate code for s.revenue

        We then use exclusive OR ^ to generate an overall hash code for the given Sales_data object. We defined our hash function to hash all three data members
         so that our hash function wll be compatible with out definition of operator== for Sales_data. By default, the unordered containers use the specialization
         of hash that corresponds to key_type along with equality operator on key type.

        Assuming out specialization is in scope, it will be used automatically when we use Sales_data as a key to one of the containers

            Uses hash<Sales_data> and Sales_data operator == from 14.3.1

            Because hash<Sales_data> uses private members of Sales_data, we must make this class a friend of Sales_data:

            

*/

// open std namespace so we can specialize std::hash
namespace std{  
    template<>                  // defining a specialization with
    struct hash<Sales_data>{    // the template parameter of Sales_data
        // type used to hash an unordered container must define these types
        typedef std::size_t result_type;
        typedef Sales_data argument_type;      // by default, this needs ==
        
        std::size_t operator()(const Sales_data& s) const;
    };

    std::size_t
    hash<Sales_data>::operator()(const Sales_data& s) const {
        return  hash<std::string>()(s.bookNo) ^
                hash<unsigned>()(s.units_Sold) ^
                hash<double>()(s.revenue);
    }

}   // close std namespace; note no semicolon



#endif