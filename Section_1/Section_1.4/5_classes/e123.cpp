#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item currItem, remItem;

    if(std::cin >> currItem){
        int cnt = 1;
        while(std::cin >> remItem){
            if(currItem.isbn() == remItem.isbn()){
                cnt++;
            }else{
                std::cout << "ISBN: " << currItem.isbn() << " | Entries: " << cnt <<std::endl;
                cnt = 1;
                currItem = remItem;
            }
        }
        std::cout << "ISBN: " << currItem.isbn() << " | Entries: " << cnt <<std::endl;
    }

    return 0;
}