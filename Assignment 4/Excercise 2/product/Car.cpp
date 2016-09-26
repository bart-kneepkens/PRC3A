
#include "Wheel.h"
#include "Car.h"
#include <vector>
#include <string>
using std::string;
using std::vector;

vector<Wheel*> wheels;
string licencePlate;
string model;

Car::Car(const string& model, const string& material, int diameter, int nrWheels){
    
}

Car::~Car(){ }

string Car::getModel(){
    return "";
}

void Car::setLicencePlate(const string& licence){
    
}

string Car::getLicencePlate(){
    return "";
}

int Car::getNrWheels(){
    return -1;
}

Wheel* Car::getWheel(int index){
    return NULL;
}

void Car::removeWheel(int index){
    
}

void Car::addWheel(int diameter, const string& material){
    
}

// Copy Constructor
Car::Car(const Car& myCar){
    
}

Car& Car::operator=(const Car& myCar){
    return *this;
}

