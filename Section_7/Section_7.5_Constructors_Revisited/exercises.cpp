#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;

/*
    e736 - the following initialize is in error. identify and fix the problem
    struct X {
        X (int i, int j): base(i), rem(base % j) { }
        int rem, base;
    };

    // FIXED
    struct X {
        int base, rem;
        X(int i, int j): base(i), rem(i % j) { }
    };

    e737 - using the version of Sales_data from this section, determine which constructor is used to initialize each of the following variables
           and list the values of the data members in each object
    
    Sales_data first_item(cin);                 // uses Sales_data(istream &is) { read(is, *this); }    | values are cin

    int main() {
        Sales_data next;                        // uses Sales_data(std::string s = ""): bookNo(s) { }   | Initializes to bookNo = "", units_sold = 0, revenue = 0
        Sales_data last("9-999-99999-9");       // uses Sales_data(std::string s = ""): bookNo(s) { }   | Initializes to bookNo = "9-999-99999-9", units_sold = 0, revenue = 0
    }

    e738 - we might want to supply cin as a default argument to the constructor that takes an istream&. Write the constructor declaration that uses cin as a default argument

    e739 - would it be legal for both the constructor that takes a string and the one that takes an istream & to have default arguments?
         This would be illegal because overloaded call for Sales_data() is ambiguous.
    
    e740 - Choose one of the following abstractions. Determine what data are needed in the class. Provide an appropriate set of constructors
            Chosen: Vehicle

    e741 - rewrite your own version of Sales_data class to use delegating constructors. Add a statement to the body of each that prints a message when executed

    e742 - rewrite Vehicle class using delegating constructor

    e743 - create class called NoDefault that has a constructor taking an int, but no default. 
           then create a class C that has a member of type NoDefault. define the default constructor for C

    e744 - is the following declaration legal, why or why not?

            vector<NoDefault> vec(10);

            this is illegal - creates a vector (vec) of 10 default-initialized objects of NoDefault
    e745 - what if we defined the vector of the previous exercise to hold objects of type C?

            vector<C> vec(10);

            This will work. No arguments provided, therefore C is default-initialized, which default-initialized objects (def) of NoDefault class
    e746 - Which of the following statements is untrue? Why?
        a) A class must provide at least one constructor.       Untrue - not explicitly. No declared constructors implicitly declares a default constructor
        b) A default constructor is a constructor with an empty parameter list - Untrue. Default constructor default-initializes arguments of set parameters;
        c) If there are no meaningful default values for a class, the class should not provide a default constructor. - Untrue. Class should always provide values;
        d) If a class does not define a default constructor, the compiler generates one that initializes each data member to the default value of associated type.
                Untrue. If our default constructor does not explicitly define any constructors, the compiler will implicitly define the default constructor for us

    e747 - explain whether the Sales_data constructor that takes a string should be explicit. What are the benefits/drawbacks of making a constructor explicit?
            explicit declaration depends on how we think users will use this constructor - conversion from string to Sales_data 

            benefits -  prevents the use of a function for implicit conversion
                        can define a constructor that only uses direct initialization rather than copy
            drawbacks - only viable for constructors accepting one argument
    e748 - Assuming Sales_data constructors are no explicit, what operations happen during the following definitions?
        string null_isbn("9-999-99999-9");          // direct initilization of string null_isbn;
        Sales_data item1(null_isbn);                // explicit conversion from string to type Sales_data
        Sales_data item2("9-999-99999-9");          // implicit conversion of string to Sales_data type

    e749 - for each of the three following declarations of combine, explain what happens if we call i.combine(s) where i is Sales_data and s is a string
        a) Sales_data &combine(Sales_data);                     Sales_data object called copied to temp Sales_data where .combine() is called
        b) Sales_data &combine(Sales_data &);                   temp Sales_data object references called Sales_data object, .combine() is called
        c) Sales_data &combine(const Sales_data &) const;       temp Sales_data object declared const (cannot change values of referenced object), .combine() then declared const

    e750 - Determine whether any of your Person class constructors should be explicit
            None need to be explicit at the moment. The only constructor that accepts one argument accepts string and no conversion would happen.
    
    e751 - Why do you think vector defines its single-argument constructor as explicit, but string doesn't?
        Because best practice for a single-argument constructor of any class type should be declared explicit to avoid any unintentional implicit conversions
        I think the declaration of vector<type> also assumes that there is no desire to convert types or else another declaration of vector type would be made

    e752 - Using the first version of Sales+data from pg.72, explain the following initialization. Fix any errors:
                Sales_data item = {"9-99999-999", 25, 15.99};

            struct Sales_data {
                std::string bookNo;
                unsigned units_sold = 0;
                double revenue = 0.0;
            }

            Sales_data is an aggregate class. However, for this to work, Sales_data cannot have any in-class initializers. 
            item is initialized via list initialization of sequential data members of class Sales_data
            // FIXED //
            struct Sales_data {
                std::string bookNo;
                unsigned units_sold;
                double revenue;
            }
    e753 - define your own version of Debug

    e754 - Should the members of debug that begin with set_ be delcared as constexpr?
            They should not be declared constexpr or const because they modify class members.
            Only member functions that do not modify class members should be declared as const
                In our case, bool show() should be constexpr because it only returns read || write

    e755 - Is the Data class from pg 298 a literal class. If not, why not, if so, explain.
            
            struct Data {
                int ival;
                string s;
            }

        struct Data is not a literal class because there are no constructors. At least one constexpr constructor must exist
            for a class to be considered literal
*/

class Debug {
public:
    friend void print(Debug &);
    constexpr Debug(bool b = true): read(b), write(b) { }          // by default, no read/write errors detected
    constexpr Debug(bool r, bool w): read(r), write(w) { }
    constexpr bool show() { return read || write; }           // return info on read/write errors
    void set_read(bool b) { read = b; }
    void set_write(bool b) { write = b; }                    
private:
    bool read;
    bool write;
};

void print(Debug &e) {
    if(e.read == false && e.write == false) {
        cout << "No Errors Detected." <<endl;
    } if (e.read && e.write) {
        std::cerr << "Read/Write Errors." <<endl;
    } if (e.write && e.read == false) {
        std::cerr << "Write Errors." <<endl;
    } if (e.read && e.write == false) {
        std::cerr << "Read Errors." <<endl;
    }
}

class Vehicle {
public:
    /*
    friend ostream &print(ostream &os, const Vehicle &v);
    Vehicle() = default;
    Vehicle(unsigned y, std::string mcfr, std::string mk, double mi): year(y), manufacturer(mcfr), make(mk), mileage(mi) { };
    Vehicle(istream &is) { is >> year >> manufacturer >> make >> mileage; }         // is reads & writes into year, manufacturer, make, mileage
    */
    // e742 - rewritten using delegating constructors
    friend ostream &print(ostream &os, const Vehicle &v);
    Vehicle(unsigned y, std::string mcfr, std::string mk, double mi): year(y), manufacturer(mcfr), make(mk), mileage(mi) { }        // delegated constructor
    Vehicle(): Vehicle(0, "", "", 0) { }            // default constructor
    Vehicle(unsigned y, std::string mcfr, std::string mk): Vehicle(y, mcfr, mk, 0) { }              // only know year, manufacturer, and make
    Vehicle(istream &is): Vehicle() { read(is, *this); }                                            // allow cin to write arguments to object

    istream &read(istream &is, Vehicle &car) { return is; }

private:
    unsigned year;
    std::string manufacturer;
    std::string make;
    double mileage;
};

// e741
class Sales_data {
public:
    //Sales_data(istream &is = std::cin) { read(is, *this); }
    Sales_data(std::string b, unsigned u, double p): bookNo(b), units_sold(u), revenue(u*p) { } // 3 arguments. Maximum and base
    Sales_data(): Sales_data("", 0, 0) { }                  // no arguments
    Sales_data(std::string b): Sales_data(b, 0, 0) { }      // only bookNo argument
    Sales_data(istream &is): Sales_data() { read(is, *this); }  // allow cin to read arguments into object of Sales_data
    Sales_data &combine(Sales_data);
    Sales_data &combine(Sales_data &);
    Sales_data &combine(const Sales_data &) const;

    istream &read(istream &is, Sales_data &item) { return is; }
private:
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};

struct X {
    int base, rem;
    X(int i, int j): base(i), rem(i % j) { }
};

ostream &print(ostream &os, const Vehicle &v) {
        os << v.year << " " << v.manufacturer
           << " " << v.make << " with " << v.mileage << " miles\n";
        return os;
    }

// e743
class NoDefault {
public:
    friend class C;
    NoDefault(int j): i(j) { };
private:
    int i;
};

// e743 continued..
class C {
public:
    C(): def(0) { }
private:
    NoDefault def;
};

class Person {
public:
    friend ostream &printProfile(ostream &os, Person &);
    Person(string n, unsigned a): name(n), age(a) { }
    Person(string n): Person(n, 0) { }


private:
    string name;
    unsigned age;
};

ostream &printProfile(ostream &os, Person &p) {
    os << "Name: " << p.name << "\nAge: " << p.age <<endl;
    return os;
}

int main()
{
    Vehicle Neon(2000, "Plymouth", "Neon", 190000);
    Vehicle Unknown;
    //print(cout, Neon);
    //print(cout, Unknown);

    //vector<NoDefault> vec(10);
    vector<C> vec(10);

   string null_isbn("9-999-99999-9");          // direct initialization of string null_isbn;
        Sales_data item1(null_isbn);                // explicit conversion from string to type Sales_data
        Sales_data item2("9-999-99999-9");          // implicit conversion of string to Sales_data type

    Person Stefan("Stefan", 26);
    // printProfile(cout, Stefan);

    Debug test(false, false);
    test.show();
    print(test);
    
    // read errors detected, change
    test.set_read(true);
    print(test);


    return 0;
}