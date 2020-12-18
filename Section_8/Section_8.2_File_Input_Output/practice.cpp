#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ostream;
using std::istream;
using std::ofstream;

/*  fstream header defines 3 types of support file IO:
        ifstream - to read from a given file
        ofstream - to write to a given file
        fstream  - which reads and writes a given file

    fstream-specific operations:
        fstream fstrm;              Creates an unbound file stream
        fstream fstrm(s);           Creates an fstream and opens the file named s. s can have type string or can be a pointer to a c-style character string
                                     these constructors are explicit. default file mode depends on the type of fstream
        fstream fstrm(s, mode);     Like the previous constructor, but opens s in the given mode
        fstrm.open(s);              Opens the file named s and binds that file to fstrm.
        fstrm.open(s, mode);        S can be a string or a pointer to a c-style character string. The default file mode depends on the type of fstream
                                    Returns void.
        fstrm.close();              Close the file to which fstrm is bound. Returns void.
        fstrm.is_open();            Returns bool indicating whether the file associated with fstrm was successfully opened and has not been closed.
*/

class Sales_data {
public:
    friend ostream &print(ostream &os, const Sales_data &item);
    friend istream &read(istream &, Sales_data&);
    Sales_data &combine(Sales_data&);
private:
    string isbn;
    unsigned units_sold;
    double revenue;
};

istream &read(istream &is, Sales_data &item) {
    double price = 0;
    is >> item.isbn >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item) {
    os << "ISBN: " << item.isbn << "\n"
       << "Units Sold: " << item.units_sold << "\n"
       << "Total Revenue: $" << item.revenue <<endl;
    return os;
}

Sales_data &Sales_data::combine(Sales_data &item) {
    revenue += item.revenue;
    units_sold += item.units_sold;
    return *this;
}


void fstream_over_iostreamRef() {
    std::ifstream input(argv[1]);               // open the file of sales transactions
    std::ofstream output(arg[2]);               // open the output file
    Sales_data total;

    if (read(input, total)) {
        Sales_data trans;
        while(read(input, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(output, total) <<endl;
                total = trans;
            }
        }
        print(output, total) <<endl;
    } else {
        std::cerr << "No data." <<endl;
    }
}

int main()
{
    std::string ifile("Hello, world!");
    std::ifstream in(ifile);                // construct an ifstream and open the given file
    cout << in.is_open() <<endl;
    std::ofstream out();                    // output file stream that is not associated with any file

    return 0;
}
