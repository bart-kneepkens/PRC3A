#ifndef __SEDAN_H
#define __SEDAN_H

#include "Car.h"

class Sedan: public Car {
    
private:
//    static const double pricePerKm = 0.29;
    int lastCleanedAtKm;
    
    bool hasTowbar;
    
public:
    bool GetHasTowbar() const;
    bool GetNeedsCleaning() const;
    
    Sedan(string manufacturer, string model, int buildYear,
              string licencePlate, bool hasTowbar);
    
    void Clean();
};

#endif
