#include "Sedan.h"

bool Sedan::GetHasTowbar() const {
    return hasTowbar;
}

bool Sedan::GetNeedsCleaning() const {
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
    lastCleanedAtKm = Car::GetKilometers();
}
