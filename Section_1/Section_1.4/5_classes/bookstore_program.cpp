#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total;                               // variable that will hold data for next transaction
                                                    // read the first transaction and ensure that there is data to progress

    if(std::cin >> total){
        Sales_item trans;                           // variable to hold the running sum
                                                    // read and write process the remaining transactions
            while(std::cin >> trans){   
                if(total.isbn() == trans.isbn()){     // if we're processing the same book
                    total+=trans;                   // update the running total
                }else{
                    std::cout << total <<std::endl;
                    total = trans;                  // total now refers to next book
                }
            }
            std::cout << total <<std::endl;         // print the last transation
    }else{                                          // if no input is detected, throw no input error
        std::cerr << "No data!" <<std::endl;
        return -1;                                  // indicate failure
    }

    return 0;
}