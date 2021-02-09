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
    friend std::ostream& print(std::ostream &os, const Vehicle &v);
    friend std::ostream& operator<<(std::ostream&, const Vehicle&);
    friend std::istream& operator>>(std::istream&, Vehicle&);
    friend bool operator==(const Vehicle&, const Vehicle&);
    friend bool operator!=(const Vehicle&, const Vehicle&);

    Vehicle(unsigned y, std::string mcfr, std::string mk, double mi): year(y), manufacturer(mcfr), make(mk), mileage(mi) { }        // delegated constructor
    Vehicle(): Vehicle(0, "", "", 0) { }            // default constructor
    Vehicle(unsigned y, std::string mfr, std::string mk): Vehicle(y, mfr, mk, 0) { }              // only know year, manufacturer, and make

    Vehicle(const Vehicle&);                        // copy constructor
    Vehicle& operator=(const Vehicle&);             // copy-assignment operator
    Vehicle(Vehicle&&) noexcept;                    // move constructor
    Vehicle& operator=(Vehicle&&) noexcept;         // move-assignment operator


    void updateMileage(double m) { mileage = m; }

private:
    unsigned year;
    std::string manufacturer;
    std::string make;
    double mileage;
};

std::istream& operator>>(std::istream& is, Vehicle &v) {
    is >> v.year >> v.manufacturer >> v.make >> v.mileage;
    if (!is) { v = Vehicle(); }
    return is;
}
std::ostream& operator<<(std::ostream& os, const Vehicle &v) {
    os << v.year << " " << v.manufacturer << " " << v.make << " " << v.mileage;
    return os;
}

/***************** Vehicle COPY CONTROL *****************/

Vehicle::Vehicle(const Vehicle &v) {
    year = v.year;
    manufacturer = v.manufacturer;
    make = v.make;
    mileage = v.mileage;
}

Vehicle& 
Vehicle::operator=(const Vehicle &v) {
    year = v.year;
    manufacturer = v.manufacturer;
    make = v.make;
    mileage = v.mileage;
    return *this;
}

/***************** Vehicle MOVE CONTROL *****************/

Vehicle::Vehicle(Vehicle &&v) noexcept {
    year = std::move(v.year);
    manufacturer = std::move(v.manufacturer);
    make = std::move(v.make);
    mileage = std::move(mileage);
}

Vehicle& Vehicle::operator=(Vehicle &&v) noexcept {
    if (this != &v) {
        year = std::move(v.year);
        manufacturer = std::move(v.manufacturer);
        make = std::move(v.make);
        mileage = std::move(mileage);
    }
    return *this;
}

#endif