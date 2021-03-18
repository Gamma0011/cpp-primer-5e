#include <iostream>
#include <vector>
#include <memory>
#include <set>
#include "quote.h"

/*
    e15.28  - define a vector to hold Quote objects but put Bulk_quote objects into that vector.
                compute the total net_price() of all elements in the vector.

                see. void e1528();

    e15.29  - Repeat your program, but this time store shared_ptrs to objects of type Quote. Explain any differences
                in the sum generated by this version and the previous one. If no difference, why not?

                see. void e1529();

                Everything it working as expected. The Quote::net_price() function is called for Quote objects.
                In e15.28, the Bulk_quote::net_price() was called as expected
    
    e15.30  - Write your own version of Basket class and use it to computer prices for the same transactions you used in e15.28/29

*/

class Basket {
public:
    void add_item(const Quote &q) { items.insert(std::shared_ptr<Quote>(q.clone())); }
    void add_item(Quote &&q) { items.insert(std::shared_ptr<Quote>(std::move(q).clone())); } 
    double total_receipt(std::ostream&) const;
private:
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) 
        { return lhs->isbn() < rhs->isbn(); }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare}; 
};

double Basket::total_receipt(std::ostream &os) const {
    double sum = 0.0;
    for (auto iter = items.cbegin() ; iter != items.cend() ; iter = items.upper_bound(*iter)) {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Purchase: $" << sum << std::endl;
    return sum;
}

void e1528() {
    std::vector<std::shared_ptr<Quote>> basket;
    Bulk_quote bq1("1-111-1", 10, .25, 100);
    Bulk_quote bq2("2-222-2", 20, .25, 200);
    Bulk_quote bq3("3-333-3", 30, .25, 300);

    basket.push_back(std::make_shared<Bulk_quote>(bq1));
    basket.push_back(std::make_shared<Bulk_quote>(bq2));
    basket.push_back(std::make_shared<Bulk_quote>(bq3));

    for (auto e : basket) { std::cout << e->net_price(10) << std::endl; }
}

void e1529() {
    std::vector<std::shared_ptr<Quote>> basket;
    Quote q1("1-111-1", 10);
    Quote q2("2-222-2", 20);
    Quote q3("3-333-3", 30);

    basket.push_back(std::make_shared<Quote>(q1));
    basket.push_back(std::make_shared<Quote>(q2));
    basket.push_back(std::make_shared<Quote>(q3));

    for (auto e : basket) { std::cout << e->net_price(10) << std::endl; }
}

void e1530() {
    Basket b;
    Quote q1("1-111-1", 10);
    Quote q2("2-222-2", 20);
    Quote q3("3-333-3", 30);

    b.add_item(q1);
    b.add_item(q2);
    b.add_item(q3);

    b.total_receipt(std::cout);
}

int main()
{
    //e1528();
    //e1529();
    e1530();

    return 0;
}