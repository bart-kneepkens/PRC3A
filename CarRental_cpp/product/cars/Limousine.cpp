#include "Limousine.h"

bool Limousine::GetHasMinibar() const{
    return hasMinibar;
}
bool Limousine::GetNeedsCleaning() const{
    return needsCleaning;
}
    
Limousine::Limousine(string manufacturer, string model, int buildYear,
                     string licencePlate, bool hasMinibar)
: Car(manufacturer, model, buildYear, licencePlate, 2.5)
, needsCleaning(false)
, hasMinibar(hasMinibar){}

    
double Limousine::Return(int kilometers){
    double price = Car::Return(kilometers);
    needsCleaning = true;
    return price;
}

void Limousine::Clean(){
    needsCleaning = false;
}
