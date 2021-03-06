#ifndef __LIMOUSINE_H
#define __LIMOUSINE_H

#include "Car.h"

class Limousine: public Car {
    
private:
    bool needsCleaning;
    bool hasMinibar;
    
public:
    bool HasMinibar() const;
    bool NeedsCleaning();
    Limousine(string manufacturer, string model, int buildYear,
              string licencePlate, bool hasMinibar);
    double Return(int kilometers);
    void Clean();
};

#endif
