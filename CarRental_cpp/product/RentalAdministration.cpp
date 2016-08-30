#include "RentalAdministration.h"
#include <stdexcept>
#include <iostream>


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
        throw out_of_range("Licenceplate Not found!!");
    }
    return found;
}

bool RentalAdministration::Add(Car* car){
    if(!car){
            // Exception
    }
    
    if(FindCar(car->GetLicencePlate()) == NULL){
        return false;
    }
    
    
    if(!FindCar(car->GetLicencePlate())){
        return false;
    }
    
    cars.push_back(car);
    return true;
    
}

bool RentalAdministration::RentCar(string licencePlate){
    if(licencePlate.empty()){
            // Exception
    }
    
    Car* found = FindCarWithException(licencePlate);
    
    return found->Rent();
}

double RentalAdministration::ReturnCar(string licencePlate, int kilometers){
    if(licencePlate.empty()){
            // Exception
    }
    Car* found = FindCarWithException(licencePlate);
    
    if(found->GetIsAvailable()){
            // Exception
    }
    
    return found->Return(kilometers);
}

void RentalAdministration::CleanCar(string licencePlate){
    if(licencePlate.empty()){
            // Exception
    }
    Car* found = FindCarWithException(licencePlate);
    
    found->Clean();
}

RentalAdministration::RentalAdministration(){
    
}
