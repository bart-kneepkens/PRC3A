#ifndef __RENTALADMINISTRATION_H
#define __RENTALADMINISTRATION_H

#include <string>
#include <vector>
#include "cars/Car.h"
using namespace std;

class RentalAdministration {
    
private:
    vector<Car*> cars;
    
    Car* FindCar(string licencePlate);
    Car* FindCarWithException(string licencePlate);
    
public:
    vector<Car*> GetCars() const;
    
    bool Add(Car* car);
    bool RentCar(string licencePlate);
    double ReturnCar(string licencePlate, int kilometers);
    void CleanCar(string licencePlate);
};

#endif