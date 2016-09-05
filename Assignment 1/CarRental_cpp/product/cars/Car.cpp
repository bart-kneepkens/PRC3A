#include <stdexcept>
#include <sstream>
using namespace std;

#include "Car.h"

Car::Car(string manufacturer, string model, int buildYear,
         string licencePlate, double pricePerKm)
:pricePerKm(pricePerKm)
, manufacturer(manufacturer)
, model(model)
, buildYear(buildYear)
, licencePlate(licencePlate)
, kilometers(0)
, isAvailable(true)
{
    if(manufacturer.empty() || model.empty() || licencePlate.empty()){
        throw invalid_argument("Parameters need to not be empty!");
    }
    
    if(buildYear < 1890){
        throw invalid_argument("Cars can not be built before 1890.");
    }
    
    if(pricePerKm < 0){
        throw out_of_range("Cannot be smaller than 0.");
    }
}

string Car::GetManufacturer() const {
    return manufacturer;
}

string Car::GetModel() const {
    return model;
}

int Car::GetBuildYear() const {
    return buildYear;
}

string Car::GetLicencePlate() const {
    return licencePlate;
}

int Car::GetKilometers() const {
    return kilometers;
}

bool Car::IsAvailable() const {
    return isAvailable;
}

bool Car::Rent() {
    if (!isAvailable)
    {
        return false;
    }
    
    isAvailable = false;
    return true;
}

double Car::Return(int kilometers_) {
    if (isAvailable)
    {
        throw invalid_argument("Car is not rented!");
    }
    if (kilometers_ < kilometers)
    {
        throw invalid_argument("Car is returned with less kilometers than it had");
    }
    
    double cost = pricePerKm * (kilometers_ - kilometers);
    kilometers = kilometers_;
    isAvailable = true;
    return cost;
}

string Car::ToString() const {
    ostringstream byStr, kmStr;
    byStr << buildYear;
    kmStr << kilometers;
    
    return manufacturer + " - " + model + " (" + byStr.str() + "), " + licencePlate + ", " + kmStr.str() + " km";
}
