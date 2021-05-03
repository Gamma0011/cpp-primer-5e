#ifndef FIND_BOOKS_H
#define FIND_BOOKS_H

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <tuple>
#include <vector>
#include "sales_data.h"

// matches has 3 members: index of store, and iterators to that store's vector
typedef std::tuple<std::vector<Sales_data>::size_type,
                   std::vector<Sales_data>::const_iterator,
                   std::vector<Sales_data>::const_iterator> matches;

// files holds transactions for each store
// findBook returns a vector with entry for each store that sold given book
std::vector<matches>
findBook(const std::vector<std::vector<Sales_data>> &files,
         const std::string &book) 
{
    std::vector<matches> ret;       // initially empty
    for (auto it = files.cbegin() ; it != files.cend() ; ++it) {
        // find range of Sales_data that have same ISBN
        auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
        if (found.first != found.second) {        // this store had sales
            // remember index of store and range
            ret.push_back(std::make_tuple(it - files.cbegin(), found.first, found.second));
        }

    }
    return ret;     // empty if no matches found
}

void reportResults(std::istream &in, std::ostream &os,
                   const std::vector<std::vector<Sales_data>> &files) {
    std::string s;  // book to look for
    while (in >> s) {
        auto trans = findBook(files, s);    // stores that sold this book
        if (trans.empty()) {
            std::cout << s << " not found in stores." << std::endl;
            continue;           // get next book to look for
        }
        for (const auto &store : trans) { // for every store with a sale
            // get<n> returns specified member from tuple in store
            os << "store " << std::get<0>(store) << " sales: "
               << std::accumulate(std::get<1>(store), std::get<2>(store), Sales_data(s))
               << std::endl;
        }
    }

}

#endif