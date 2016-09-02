#ifndef __SEDAN_H
#define __SEDAN_H

#include "Car.h"

class Sedan: public Car {
    
private:
    int lastCleanedAtKm;
    bool hasTowbar;
    
public:
    bool HasTowBar() const;
    bool NeedsCleaning();
    Sedan(string manufacturer, string model, int buildYear,
          string licencePlate, bool hasTowbar);
    
    void Clean();
};

#endif