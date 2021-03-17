#ifndef BASKET_H
#define BASKET_H

#include <iostream>
#include <string>
#include <memory>
#include <set>
#include "quote.h"

class Basket {
public:
    // Basket uses synthesized default constructor and copy-control members
    void add_item(const Quote &q) { items.insert(std::make_shared<Quote>(q.clone())); }         // lvalue
    void add_item(Quote &&q) { items.insert(std::make_shared<Quote>(std::move(q).clone())); }   // rvalue
    // prints total price for each book and the overall total for all items in Basket
    double total_receipt(std::ostream&) const;
private:
    // function to compare shared_ptr needed by the multiset member
    static bool compare(const std::shared_ptr<Quote> &lhs,
                        const std::shared_ptr<Quote> &rhs)
        { return lhs->isbn() < rhs->isbn(); } 
    // multiset to hold multiple quotes, ordered by the compare member
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};

double Basket::total_receipt(std::ostream &os) const {
    double sum = 0.0;       // holds the running total

    // iter refers to the first elements in a batch of elements with the same ISBN
    // upper_bound returns an iterator to the element just past the end of the batch
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
        // we know there's at least one element with this key in the Basket
        // print the line item for this book
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: $" << sum << std::endl;
    return sum;
}


#endif