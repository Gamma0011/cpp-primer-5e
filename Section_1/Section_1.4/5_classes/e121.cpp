#include <iostream>

class Sales_Item{
    public:
    int ISBN;
    float income;

        Sales_Item(int ISBN, float income){
            this->ISBN=ISBN;
            this->income=income;
        }
    };

int main()
{
    Sales_Item book1(10, 45.93);
    Sales_Item book2(1, 50.00);

    if(book1.ISBN == book2.ISBN){
        float totalSales = book1.income + book2.income;

        std::cout << "The book with ISBN #" << book1.ISBN << " has made $" << totalSales <<std::endl;
    }else{
        std::cout << "The two ISBN don't match." <<std::endl;
    }

    return 0;
}
