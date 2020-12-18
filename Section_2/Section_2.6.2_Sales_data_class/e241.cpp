#include <iostream>
#include <string>
#include "Sales_item.h"

struct Sales_data
{
    std::string bookNo;
    unsigned units_Sold = 0;
    double revenue = 0;
};

int e1_21(){
    Sales_data data1, data2;

    // Create and Initialize price
    double price = 0;

    // take input of data1
    std::cout << "Please enter ISBN, Units Sold, and Price per Book" <<std::endl;
    std::cin >> data1.bookNo >> data1.units_Sold >> price;
    data1.revenue = data1.units_Sold * price;

    // take input of data1
    std::cout << "Please enter ISBN, Units Sold, and Price per Book" <<std::endl;
    std::cin >> data2.bookNo >> data2.units_Sold >> price;
    data2.revenue = data2.units_Sold * price;

    if(data1.bookNo == data2.bookNo){
        // create and initialize totalRevenue
        double totalRevenue = data1.revenue + data2.revenue;
        std::cout << "Total Revenue: $" << totalRevenue <<std::endl;
        return 0;       // indicate success
    } else {
        std::cerr << "ISBNs don't match!" <<std::endl;
        return -1;      // indicate failure
    }

    return 0;
}

int e1_22(){
    // take transactions for matching ISBNs, keep tally while they match
    Sales_data total, data;

    // Create and Initialize Price
    double price = 0;
    std::cout << "Please enter the first book's ISBN, Units Sold, and Price per Book" <<std::endl;
    if(std::cin >> total.bookNo >> total.units_Sold >> price){
        // calculate total.revenue
        total.revenue = total.units_Sold * price;
        std::cout << "Please enter the next book's ISBN, Units Sold, and Price per Book" <<std::endl;
        while(std::cin >> data.bookNo >> data.units_Sold >> price){
            std::cout << "Please enter the next book's ISBN, Units Sold, and Price per Book" <<std::endl;
            data.revenue = data.units_Sold * price;
                if(total.bookNo == data.bookNo){
                    total.units_Sold += data.units_Sold;
                    total.revenue += data.revenue;
                } else {
                    std::cout << "Different ISBN entered!" <<std::endl;
                    std::cout << "ISBN: " << total.bookNo << "\nTotal Units Sold: " << total.units_Sold << "\nRevenue: $" << total.revenue <<std::endl;
                    return 0; // success, end of program
                }
            }
        } else {
            std::cerr << "No Input!" <<std::endl;
            return -1; // indicate failure
        }
    return 0;
}

int e1_23(){
    // count how many transactions occur for each matching ISBN
    
    Sales_data total, data;

    // create and initialize price & transaction counter
    double price = 0;
    int transactions = 1;
    
    std::cout << "Please enter the first book's ISBN, Units Sold, and Price." <<std::endl;
    if(std::cin >> total.bookNo >> total.units_Sold >> price){
        total.revenue = total.units_Sold * price;
        std::cout << "Please enter the next book's ISBN, Units Sold, and Price." <<std::endl;
            while(std::cin >> data.bookNo >> data.units_Sold >> price){
                std::cout << "Please enter the next book's ISBN, Units Sold, and Price." <<std::endl;
                data.revenue = data.units_Sold * price;
                    if(total.bookNo == data.bookNo){
                        total.units_Sold += data.units_Sold;
                        total.revenue += data.revenue;
                        transactions++;
                    } else {
                        std::cout << "Different ISBN entered!\nTotal Transations: " << transactions <<std::endl;
                        return 0; // end of program
                    }
            }
    } else {
        std::cerr << "No books entered!" <<std::endl;
        return -1;
    }
    return 0;
}

int main()
{
    // e1_21();
    // e1_22();
    // e1_23();

    return 0;
}