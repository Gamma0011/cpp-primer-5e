#include <iostream>
#include <vector>
#include <memory>
#include "quote.h"

/*
    e15.28  - define a vector to hold Quote objects but put Bulk_quote objects into that vector.
                compute the total net_price() of all elements in the vector.

                **NEEDS MORE WORK**
            
*/

void e1528() {
    std::vector<std::shared_ptr<Quote>> basket;
    Bulk_quote bq1("1-111-1", 10, .25, 100);
    Bulk_quote bq2("2-222-2", 20, .25, 200);
    Bulk_quote bq3("3-333-3", 30, .25, 300);

    basket.push_back(std::make_shared<Bulk_quote>(bq1));
    basket.push_back(std::make_shared<Bulk_quote>(bq2));
    basket.push_back(std::make_shared<Bulk_quote>(bq3));

    for (auto e : basket) {
        std::cout << std::endl;
    }
}

int main()
{

    return 0;
}