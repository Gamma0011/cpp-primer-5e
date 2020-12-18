#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// e71 - write a version of the transaction-processing program from (p24) using the Sales_data class you defined in the exercieses on pg 72
struct Sales_data
{
    // e72 - add combine() and isbn() to your Sales_data struct
    string isbn() const { return bookNo; };             // member function isbn()
    Sales_data& combine(const Sales_data&);             // member function combine

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;   // add the members of rhs into
    revenue += rhs.revenue;         // the members of "this" object
    return *this;                   // return the object on which the function was called
}

// e74 - write a class named Person that represents the name and address of a person. Use a string to hold each of these elements

class Person 
{
public:    
    // e75 - provide operations in your class to return the name and address
    // should these be const? Don't have to be, but I think name has a chance of being const since address is likely to change over time
    string pName() const {
        return name;
    }
    string pAddress() {
        return address;
    }

    string name;
    string address;
};

int main()
{
    // e73 - revise your program to use isbn() and combine()
    /*
    Sales_data total;           // create an object of class Sales_data
    
    if (cin >> total.bookNo >> total.units_sold >> total.revenue) {     // check initial data exists
        Sales_data temp;                                                // create Sale_data object to hold input
        while (cin >> temp.bookNo >> temp.units_sold >> temp.revenue) {
            if (total.bookNo == temp.bookNo) {                          // ISBNs match
                total.combine(temp);                                    // object total calls combine() and passes by reference argument temp
                //total.units_sold += temp.units_sold;                    // update total books sold
                //total.revenue += total.revenue;                         // update revenue
            } else {                                                    // ISBNs don't match
                cout << "ISBN : " << total.isbn() << '\n'               // call isbn() function to print bookNo
                     << "Units sold : " << total.units_sold << '\n'
                     << "Total Revenue : $" << total.revenue <<endl;
                total.bookNo = temp.bookNo;                             // update to reflect new ISBN and data to check again
                total.units_sold = temp.units_sold;
                total.revenue = temp.revenue;   
            }
        }
        cout << "ISBN : " << total.bookNo << '\n'               // print data for last ISBN
             << "Units sold : " << total.units_sold << '\n'
             << "Total Revenue : $" << total.revenue <<endl;
    } else {
        std::cerr << "ERROR: No input" <<endl;
        return -1;
    }
    */


   Person stefan;
   stefan.name = "Stefan";
   stefan.address = "112 Sussex";
   cout << stefan.pName() << endl;
   cout << stefan.pAddress() << endl;

    return 0;
}