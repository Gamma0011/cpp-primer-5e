#ifndef VEHICLE_CLASS
#define VEHICLE_CLASS

#include <iostream>
#include <string>
#include <vector>


class Vehicle {
public:
    /*
    friend ostream &print(ostream &os, const Vehicle &v);
    Vehicle() = default;
    Vehicle(unsigned y, std::string mcfr, std::string mk, double mi): year(y), manufacturer(mcfr), make(mk), mileage(mi) { };
    Vehicle(istream &is) { is >> year >> manufacturer >> make >> mileage; }         // is reads & writes into year, manufacturer, make, mileage
    */
    // e742 - rewritten using delegating constructors
    friend std::ostream &print(std::ostream &os, const Vehicle &v);
    friend std::ostream& operator<<(std::ostream&, const Vehicle&);
    friend std::istream& operator>>(std::istream&, Vehicle&);

    Vehicle(unsigned y, std::string mcfr, std::string mk, double mi): year(y), manufacturer(mcfr), make(mk), mileage(mi) { }        // delegated constructor

    Vehicle(): Vehicle(0, "", "", 0) { }            // default constructor
    Vehicle(unsigned y, std::string mcfr, std::string mk): Vehicle(y, mcfr, mk, 0) { }              // only know year, manufacturer, and make
    Vehicle(std::istream &is): Vehicle() { read(is, *this); }                                            // allow cin to write arguments to object

    std::istream &read(std::istream &is, Vehicle &car) { return is; }

private:
    unsigned year;
    std::string manufacturer;
    std::string make;
    double mileage;
};

std::istream& operator>>(std::istream& is, Vehicle &v);
std::ostream& operator<<(std::ostream& os, const Vehicle &v);


#endif