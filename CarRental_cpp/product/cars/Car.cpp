#include <stdexcept>
#include <iostream>
#include <sstream>
using namespace std;

#include "Car.h"

        //Getters
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

    bool Car::GetNeedsCleaning() const {
        return needsCleaning;
    }

    int Car::GetKilometers() const {
        return kilometers;
    }

    bool Car::GetIsAvailable() const {
        return isAvailable;
    }
    
        //Setters
    void Car::SetKilometers(int kilometers_) {
        kilometers = kilometers_;
    }
    void Car::SetIsAvailable(bool isAvailable_) {
        isAvailable = isAvailable_;
    }
    
    
        //Functions
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
            throw out_of_range("Cars can not be built before 1890.");
        }
        
        if(pricePerKm < 0){
            throw out_of_range("Cannot be smaller than 0.");
        }
    }
    
    string Car::ToString() const {
            // Ook bouwjaar en km stand
        ostringstream ostr;
        ostr << buildYear;
        
        return manufacturer + " - " + model + ", " + licencePlate + " (" + ostr.str() + ") \n";
    }
