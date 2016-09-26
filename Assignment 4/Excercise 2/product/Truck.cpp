#include "Truck.h"
#include <stdexcept>

using std::invalid_argument;

Truck::Truck(const string& model, const string& material, int diameter, 
	int nrWheels, int power) : Car(model, material, diameter, nrWheels) {
	
	if (power < 1) {
		throw invalid_argument("power must be > 0");
	}
	
	this->power = new int(power);
}

Truck::~Truck() {
	delete power;
}

int Truck::getPower() const {
	return *power;
}

Truck::Truck(const Truck& myTruck) : Car(myTruck) {
	this->power = new int(myTruck.getPower());
}

Truck& Truck::operator=(const Truck& myTruck) {
	
	if (&myTruck == this) 
		return *this;
		
	Car::operator=(myTruck);
	delete power;
	power = new int(myTruck.getPower());
	return *this;
}



