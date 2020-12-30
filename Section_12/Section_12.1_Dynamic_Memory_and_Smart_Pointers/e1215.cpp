#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <utility>

//     e12.15  - Rewrite 12.14 to use a lambda function of end_connection function

struct destination {
    std::string street;
    int houseNo;
    destination(std::string s, int i) : street(s), houseNo(i) { };
};

struct connection {
    std::string street;
    int houseNo;
    connection(std::string s, int i) : street(s), houseNo(i) { };
};

connection convert(destination *d) {
    std::shared_ptr<connection> c(new connection(d->street, d->houseNo));
    return *c;
}

void disconnect(connection c) { std::cout << "Address: " << c.houseNo << " " << c.street <<std::endl; }

void f(destination &d) {
    connection c = convert(&d);
    std::shared_ptr<connection> p(&c, [](connection *p){disconnect(*p); });
}

int main()
{
    destination test("Main", 90);
    f(test);


    return 0;
}


