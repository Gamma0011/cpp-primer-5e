#include <iostream>
#include <vector>
#include <string>
#include <memory>

//     e12.14  - Write your own version of a function that uses shared_ptr to manage a connection.

struct destination {
    std::string street;
    int houseNo;
    destination(std::string s, int hn) : street(s), houseNo(hn) { };
};

struct connection {
    std::string street;
    int houseNo;
    connection(std::string s, int hn) : street(s), houseNo(hn) { };
};

connection convert(destination *d) {
    std::shared_ptr<connection> c(new connection(d->street, d->houseNo));
    return *c;          // return dereferenced connection
}

void disconnect(connection c) { std::cout << "Old Address: " << c.houseNo << " " << c.street <<std::endl; }

void end_connection(connection *c) { disconnect(*c); }

void f(destination &d) { 
    connection c = convert(&d);
    std::shared_ptr<connection> p(&c, end_connection);
}

int main()
{
    destination test("Main", 90);
    f(test);

    return 0;
}