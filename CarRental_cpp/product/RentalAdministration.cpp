#include "RentalAdministration.h"
#include <stdexcept>
#include <iostream>
#include <vector>


Car* RentalAdministration::FindCar(string licencePlate){
    
    for (unsigned int i = 0; i < cars.size();i++)
    {
        if(cars[i]->GetLicencePlate() == licencePlate){
            return cars[i];
        }
    }
    
    return NULL;
}

Car* RentalAdministration::FindCarWithException(string licencePlate){
    Car* found = FindCar(licencePlate);
    
    if(!found){
        throw out_of_range("Licenceplate Not found!");
    }
    return found;
}

vector<Car*> RentalAdministration::GetCars() const {
    return cars;
}

bool RentalAdministration::Add(Car* car){
    if(!car){
        throw invalid_argument("Car paramater can't be null!");
    }
    
    if(FindCar(car->GetLicencePlate()) != NULL){
        return false;
    }
    
    cars.push_back(car);
    return true;
    
}

bool RentalAdministration::RentCar(string licencePlate){
    if(licencePlate.empty()){
        throw invalid_argument("License plate can't be empty!");
    }
    
    Car* found = FindCarWithException(licencePlate);
    
    return found->Rent();
}

double RentalAdministration::ReturnCar(string licencePlate, int kilometers){
    if(licencePlate.empty()){
        throw invalid_argument("License plate can't be empty!");
    }
    Car* found = FindCarWithException(licencePlate);
    
    if(found->IsAvailable()){
        throw invalid_argument("The car is not even rented!");
    }
    
    return found->Return(kilometers);
}

void RentalAdministration::CleanCar(string licencePlate){
    if(licencePlate.empty()){
        throw invalid_argument("License plate can't be empty!");
    }
    Car* found = FindCarWithException(licencePlate);
    
    found->Clean();
}

RentalAdministration::RentalAdministration(){}