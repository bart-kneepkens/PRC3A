#include "Limousine.h"

static const double PricePerKm = 2.5;

Limousine::Limousine(string manufacturer, string model, int buildYear,
                     string licencePlate, bool hasMinibar)
: Car(manufacturer, model, buildYear, licencePlate, PricePerKm)
, needsCleaning(false)
, hasMinibar(hasMinibar){}

bool Limousine::HasMinibar() const{
    return hasMinibar;
}
bool Limousine::NeedsCleaning() {
    return needsCleaning;
}

double Limousine::Return(int kilometers){
    double price = Car::Return(kilometers);
    needsCleaning = true;
    return price;
}

void Limousine::Clean(){
    needsCleaning = false;
}
