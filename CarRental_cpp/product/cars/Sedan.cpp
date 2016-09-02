#include "Sedan.h"

static const double PricePerKm = 0.29;

Sedan::Sedan(string manufacturer, string model, int buildYear,
             string licencePlate, bool hasTowbar)
: Car(manufacturer, model, buildYear, licencePlate, PricePerKm)
, lastCleanedAtKm(0)
, hasTowbar(hasTowbar){}

bool Sedan::HasTowBar() const {
    return hasTowbar;
}

bool Sedan::NeedsCleaning() {
    if((Car::GetKilometers() - lastCleanedAtKm) >= 1000){
        return true;
    }
    return false;
}

void Sedan::Clean(){
    lastCleanedAtKm = Car::GetKilometers();
}