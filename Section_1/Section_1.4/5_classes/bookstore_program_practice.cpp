#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item currItem, newItem;

    if(std::cin >> currItem){
        int cnt = 1;
            while(std::cin >> newItem){
                if(currItem == newItem){
                    cnt++;
                }else{
                    std::cout << currItem << " entered " << cnt << " times." <<std::endl;
                    cnt = 1;
                    currItem = newItem;
                }
            }
            std::cout << currItem << " entered " << cnt << " times." <<std::endl;
    }else{
        std::cerr << "Error. No input!" <<std::endl;            // throw error
        return -1;                                              // return failure
    }

    return 0;
}