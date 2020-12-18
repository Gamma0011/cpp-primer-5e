#include <iostream>

int main()
{
    struct Sales_data
    {
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
    }
    accum, trans, *salesptr;

    /*
    This is also valid, and a better way to define objects of the class

    struct Sales_data
    {
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
    };

    Sales_data accum, trans, *salesptr;

    */
    

    return 0;
}
