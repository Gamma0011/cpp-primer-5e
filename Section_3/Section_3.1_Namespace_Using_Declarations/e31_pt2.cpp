#include <iostream>
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::endl;

void e121(){
    
    Sales_item book1, book2;

    cin >> book1 >> book2;
    cout << book1 + book2 <<endl;
}

int e122(){
    Sales_item total, item;

    if(cin >> total){
        while(cin >> item && total.isbn() == item.isbn()){
            total+=item;
        }
        cout << total <<endl;
        return 0;

    } else {
        std::cerr << "No input!" <<endl;
        return -1;
    }
    return 0;
}

int e123(){
    Sales_item total, item;

    if(cin >> total){\
        int cnt = 1;
        while(cin >> item && total.isbn() == item.isbn()){
            cnt++;
        }
        cout << "Book entered " << cnt << " times." <<endl;
    } else {
        std::cerr << "No input!" <<endl;
    }
    return 0;
}

int bookstore_program(){
    Sales_item total;

    if(cin >> total){
        Sales_item trans;
            while(cin >>trans){
                if(total.isbn() == trans.isbn()){
                    total += trans;
                } else {
                    cout << total <<endl;
                    total = trans;
                }
            }
        cout << total <<endl;
    } else {
        std::cerr << "No input!" <<endl;
        return -1;
    }
    return 0;
}



int main()
{
    // e121();
    // e122();
    // e123(); // e124() same as e123();
    bookstore_program();

    return 0;
}
