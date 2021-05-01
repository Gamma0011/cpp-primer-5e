#include <iostream>
#include <tuple>

/*
    || THE TUPLE TYPE ||
        A tuple is a template that is similar to a pair. Each pair type has different types for its members, but every pair always
         has exactly 2 members. A tuple also has members whose types vary from one tuple type to another, but a tuple can have
         any number of members. Each distinct tuple type has a fixed number of members, but the number of members in one tuple
         can differ from the members in another.

        Tuples are most useful when we want to combine some data into a single object, but do not want to bother to define a data
         structure to represent those data.

        *NOTE* Think of a tuple as a quick and dirty data structure.

    || DEFINING AND INITIALIZING TUPLES ||
        To define a tuple, we must define the types of each member:
        tuple<int, int, int> threeI;        // default initialized to 0
        tuple<int, int, int> threeI(3,2,1); // initialized to 3, 2,1 

        Default tuples are value initialized, however, we can supply initializers for each member.
        The constructor is explicit, so we must use direct initialization syntax:
        tuple<int, int, int> test = {1,2,3};            // error!
        tuple<int, int, int> test{1,2,3)};               // works

        We can also use std::make_tuple to create a tuple object:
        auto obj = std::make_tuple("book", 19.99, 10);          obj == tuple<const char*, double, int>

    || OPERATIONS ON TUPLES ||
        t1 relop (<, >, etc) t2     - Relational operations on tuples using dictionary ordering. Must have same # members.
        get<i>(t)                   - Returns & to ith data member of t. If t is lvalue. returns lvalue&, otherwise, rvalue. All members of tuple are public
        tuple_size<type>::value     - Class template instantiated by tuple type and has public constexpr static data member named value of type size_t with # members in tuple type
        tuple_element<i, type>::type- Class template instantiated by integral constant and tuple type. Has public member named type that is type of specified members in specified tuple type.

    || ACCESSING MEMBERS OF A TUPLE ||
        A pair always has 2 members, which makes it possible for the library to give these members named (first, second). For tuples, there is no limit on # of members. 
         Therefore, members are unnamed. Instead, we access with get. To use get, we specify an explicit template argument which is the position of the member we want to access.
         We pass a tuple object to get, which returns a reference to the specified member.

        see. void tuple_test();

        auto book = std::get<0>(item);          // returns first member of item

        The value inside the brackets must be an integral constant expression. As usual, we count from 0 with <0> being the first member.

        If we have a tuple whose precise type details we don't know, we can use two auxilary class template to find the number and types of the tuple's members.

            typedef decltype(item) trans;                           // trans is the type of item;
            std::size_t sz = std::tuple_size<trans>::value;         // return size of item
            std::tuple_element<1, trans>::type cnt = get<1>(item);  // cnt is an int;

        In order to use tuple_size or tuple_element, we need to know the type of a tuple object. The easiest way to do this is with decltype. 

            typedef decltype(item(trans);   defines a type alias for the type of item, which is used to instantiate both templates.

            tuple_size has a public static data member named value which is the # of members in the tuple. 
            tuple_element template takes an index as well as tuple type, and has a public member named type that is the type of the specified
             member of the specified tuple type. tuple_element uses indexes starting at 0.

        || RELATIONAL AND EQUALITY OPERATORS ||
            Tuple relational and equality operators operate the same as any other container. We can compare 2 tuples only if they have == # members
             and are of same type.

        *NOTE* because type defines < and == operations, we can pass sequences of tuples to algorithms and can use a type as a key type in an ordered container.

    || USING A TUPLE TO RETURN MULTIPLE VALUES ||
        A common use of tuple is to return multiple values from a function. In the case of our bookstore program, our bookstore might be one of several. 
        Each store would have a transaction file holding data for each book. We might want to look at sales for a given book at all stores.

        We'll assume some function reads each store's transaction file into a vector<Sales_data>, then puts those into a vector of vectors.

            std::vector<std::vector<Sales_data>> files;

        We'll write a function that will search files looking for the store that sold a given book. For each store with a matching transaction, we'll create
         a tuple to hold the index of the store and two iterators. Index will be position of matching store in files. Iterators will mark first and 1 past last
         record for given book in the store's vector<Sales_data>

         
*/


void tuple_test() {
    auto item = std::make_tuple("bookno", 3, 19.99);
    std::tuple<int, int, int> test{1,2,3};
    auto n1 = std::get<0>(test);
    auto n2 = std::get<1>(test);
    auto n3 = std::get<2>(test);

    std::cout << n1 << '\t' << n2 << '\t' << n3 << std::endl;

    typedef decltype(item) trans;
    std::size_t sz = std::tuple_size<trans>::value;
    std::tuple_element<0, trans>::type cnt = std::get<0>(item);

    std::cout << sz << '\t' << cnt << std::endl;
}

int main()
{
    tuple_test();

    return 0;
}