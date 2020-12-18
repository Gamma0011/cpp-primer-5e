#include <iostream>

int match(int b1, int b2, int b3);

class Sales{
private:
public:
    int ISBN;
    float price;

    Sales(int ISBN, float price){
        this->ISBN=ISBN;
        this->price=price;
    }
};

int main()
{
    Sales book1(10, 23.99);
    Sales book2(10, 14.99);
    Sales book3(10, 20.00);

    if(match(book1.ISBN, book2.ISBN, book3.ISBN) == 1){
        float revenue = book1.price + book2.price + book3.price;
        std::cout << "ISBNs match\nTotal revenue: $" << revenue <<std::endl;
    }else{
        std::cout << "ISBNs don't match\nCouldn't calculate sales." <<std::endl;
    }


    return 0;
}

int match(int b1, int b2, int b3){
    if(b1 == b2 && b2 == b3){
        return 1;               // return 1 if all ISBNs match
        }else{
            return 0;           // return 0 if ISBNs don't match
    }
}