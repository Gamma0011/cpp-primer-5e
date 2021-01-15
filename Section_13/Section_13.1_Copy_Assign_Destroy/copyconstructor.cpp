#include <iostream>
#include <vector>
#include <string>

/*
    | THE COPY CONSTRUCTOR |
        A constructor is the copy constructor if its first parameter is a reference to the class type and any additional
         parameters have default parameters.

        class Foo {
        public:
            Foo();                  // default constructor
            Foo(const Foo&);        // copy constructor
        }

        The first parameter MUST be a & type, and is ALMOST ALWAYS a & to const. The copy constructor is used implicitly in several
         circumstances and therefore should not be explicit.

        | THE SYNTHESIZED COPY CONSTRUCTOR |
            Unlike the synthesized default constructor, a copy constructor is synthesized even if we define other constructors. 

            Somtimes, the SYNTHESIZED COPY CONSTRUCTOR prevents us from copying objects of that class type. 
            Otherwise, the SYNTHESIZED COPY CONSTRUCTOR MEMBERWISE COPIES the members of its argument into the object being created.

            The compiler copies each nonstatic member in turn from the given object into the one being created.
        
            Members of class type are copied by the copy constructor, while members of build-in type are copied directly. Although we cannot
             copy an array, the SYNTHESIZED COPY CONSTRUCTOR copies members of the array type by copying each element.

            Elements of class type are copied using the elements' copy constructor.

        | COPY INITIALIZATION |
            Differences between direction and copy initialization:

                string dots(10, '.);            // direct initialization
                string s(dots);                 // direct initialization
                string s2 = dots;               // copy initialization
                string null_book = "0-000-00";  // copy initialization
                string nines = string(10, '9'); // copy initialization

            When we use direct initialization, we are asking the compiler to use ordinary function matching to select the 
             constructor that best matches the arguments we provide.
            
            When we use COPY INITIALIZATION, we are asking the compiler to copy the right-hand operand into the object being
             created, converting that object if necessary.

            Sometimes, if a class has a move constructor, copy initialization may use that instead.

            COPY INITIALIZATION also occurs when:
                - An object is passed as an argument to a parameter of a nonreference type.             void pass(Sales_data sd)    | sd copy-initialized
                - An object is returned from a function that has a nonreference type.                   return sd                   | sd copy-initialized
                - Elements are brace-initialized in an array or the members of an aggregate class.      {1,2,3,4,5,6}               | copy initialized
            
            .insert() or .push() members copy initialize their elements, where as .emplace() direct initializes them.

        | CONSTRAINTS ON COPY INITIALIZATION |
            Whether we use copy or direct initialization matters if we use an initializer that requires conversion
             by an explicit constructor.

            vector<int> v1(10);             // ok: direct initialization
            vector<int> v2 = 10;            // error: constructor that takes a size is explicit
            void f(vector<int>);            // f's parameter is copy initialized
            f(10);                          // error: can't use an explicit constructor to copy an argument
            f(vector<int>(10));             // ok: directly construct a temp vector from int

        **NOTE** The compiler can bypass the copy constructor to write the object directly. However, it is not obligated to do so.
            Even if the compiler omits the call to copy/move constructor, the constructors must still exist and be accessible (not private).

*/

class Sales_data {
public:
    // other member and constructors as before
    Sales_data();
    Sales_data(std::string bn, int us, double unit_price) : bookNo(bn), units_sold(us), revenue(unit_price * us) { };
    Sales_data(const Sales_data&);      // copy constructor
private:
    std::string bookNo;
    int units_sold = 0;
    double revenue = 0.0;
};

// equivalent to the copy constructor that would be synthesized for Sales_data
Sales_data::Sales_data(const Sales_data &orig) : 
    bookNo(orig.bookNo),
    units_sold(orig.units_sold),
    revenue(orig.revenue) { };



int main()
{


    return 0;
}