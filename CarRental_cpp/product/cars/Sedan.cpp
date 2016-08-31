#include "Sedan.h"
#include <iostream>

bool Sedan::HasTowBar() const {
    return hasTowbar;
}

bool Sedan::NeedsCleaning() {
//    cout << lastCleanedAtKm;
//    cout << "\n";
//    cout << Car::GetKilometers();
    
    if((Car::GetKilometers() - lastCleanedAtKm) >= 1000){
        return true;
    }
    return false;
}

Sedan::Sedan(string manufacturer, string model, int buildYear,
             string licencePlate, bool hasTowbar)
: Car(manufacturer, model, buildYear, licencePlate, 0.29)
, lastCleanedAtKm(0)
, hasTowbar(hasTowbar){}

void Sedan::Clean(){
//    cout << "------------------------";
//    cout << Car::GetKilometers();
    lastCleanedAtKm = Car::GetKilometers();
}
