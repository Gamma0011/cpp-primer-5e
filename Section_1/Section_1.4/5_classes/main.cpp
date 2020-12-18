#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item book; 

    std::cin >> book;               // read ISBN, number of books sold, and sales price
    std::cout << book <<std::endl;  // print ISBBN, number of books sold, total revenue, and average sales price.

    return 0;
}
