#include <iostream>
#include <string>
#include "Sales_item.h"

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;
};

int main()
{
    Sales_data data1, data2;
    // code read into data1 and data2
    // code to check whether data1 and data2 have same ISBN
    //  and if so print the sum of data1 and data2

    double price = 0;   // price per book, used to calculate total revenue

    // read the first transaction: ISBN, number of books told, price per book
    std::cin >> data1.bookNo >> data1.units_sold >> price;
    // calculate total revenue from price and units_sold
    data1.revenue = data1.units_sold * price;

    // read the second transaction: ISBN, number of books told, price per book
    std::cin >> data2.bookNo >> data2.units_sold >> price;
    // calculate total revenue from price and units_sold
    data2.revenue = data2.units_sold * price;

    if (data1.bookNo == data2.bookNo){
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;

        // print ISBN, total sold, total revenue, average price per book
        std::cout << "ISBN: " << data1.bookNo << "\nTotal Revenue: $" << totalCnt << "\nAverage Price: $" << totalRevenue <<std::endl;

        if (totalCnt != 0){
            std::cout << "Average Price: $" << totalRevenue/totalCnt <<std::endl;
        } else {
            std::cout << "(no sales)" <<std::endl;
            return 0; // indicate success
        }
    } else {
            std::cerr << "Data must refer to the same ISBN." <<std::endl;
            return -1; // indicate failure
    }

    return 0;
}
