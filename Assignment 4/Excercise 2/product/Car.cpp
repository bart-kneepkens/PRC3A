#include "Car.h"
#include <stdexcept>
#include <iostream>

using std::invalid_argument;
using std::out_of_range;

Car::Car(const string& model, const string& material, int diameter, int nrWheels) {
    
    if (diameter < 1) {
		throw invalid_argument("diameter must be > 0");
	}
	
	if (nrWheels < 3) {
		throw invalid_argument("nrWheels must be > 2");
	}
	
	this->model = model;
	
	for (int i = 0; i < nrWheels; i++) {
		wheels.push_back(new Wheel(diameter, material));
	}
}

Car::~Car() {
	for (unsigned int i = 0; i < wheels.size(); i++)
		delete wheels[i];
		
	wheels.clear();
}

string Car::getModel() const {
    return model;
}

void Car::setLicencePlate(const string& licence) {
    this->licencePlate = licence;
}

string Car::getLicencePlate() const {
    return licencePlate;
}

int Car::getNrWheels() const {
    return wheels.size();
}

Wheel* Car::getWheel(int index) const {
	
    if (index < 0 || index >= (int) wheels.size()) {
		throw out_of_range("illegal index");
	}
	
	return wheels[index];
}

void Car::removeWheel(int index) {
    
    if (index < 0 || index >= (int) wheels.size()) {
		throw out_of_range("illegal index");
	}
	
	wheels.erase(wheels.begin() + index);
}

void Car::addWheel(int diameter, const string& material) {
    
    if (diameter < 1) {
		throw invalid_argument("diameter must be > 0");
	}
	
	wheels.push_back(new Wheel(diameter, material));
}

Car::Car(const Car& myCar) {
    
        //std::cout << "copy constructor.\n";
    
    for (int i = 0; i < myCar.getNrWheels(); i++) {
		wheels.push_back(new Wheel(*(myCar.getWheel(i))));
	}
	
	licencePlate = myCar.getLicencePlate();
	model = myCar.getModel();
}


    // Does not get called for some reason.
Car& Car::operator=(const Car& myCar) {
	
    std::cout << "= operator!\n\n\n";
    if (&myCar == this) 
		return *this;

    // Delete this car's wheels.
    for (unsigned int i = 0; i < wheels.size(); i++)
		delete wheels[i];
		
	wheels.clear();

	// Copy wheels from myCar to this.
    for (int i = 0; i < myCar.getNrWheels(); i++)
		wheels.push_back(new Wheel(*(myCar.getWheel(i))));
    
    licencePlate = myCar.getLicencePlate();
	model = myCar.getModel();   
    return *this;
}

