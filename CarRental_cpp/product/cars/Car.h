#ifndef __CAR_H
#define __CAR_H

#include <string>
using namespace std;

class Car {
private:
    double pricePerKm;
    string manufacturer;
    string model;
    int buildYear;
    string licencePlate;
    bool needsCleaning;
    int kilometers;
    bool isAvailable;
public:
        //Getters
    string GetManufacturer() const;
    string GetModel() const;
    int GetBuildYear() const;
    string GetLicencePlate() const;
    virtual bool NeedsCleaning() = 0;
    int GetKilometers() const;
    bool IsAvailable() const;
    
        //Setters
    void SetKilometers(int kilometers);
    void SetIsAvailable(bool isAvailable);
    
    
        //Functions
    bool Rent();
    virtual double Return(int kilometers);
    
    Car(string manufacturer, string model, int buildYear, string licencePlate, double pricePerKm);
    
    virtual void Clean() = 0;
    
    string ToString() const;
    
};

#endif
