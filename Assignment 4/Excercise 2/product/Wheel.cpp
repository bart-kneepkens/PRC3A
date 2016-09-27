#include "Wheel.h"
#include <stdexcept>
#include <iostream>

using std::invalid_argument;

Wheel::Wheel(int diameter, const string& material) {
	
	if (diameter <= 0) {
		throw invalid_argument("diameter must be > 0");
	}
	
	this->diameter = diameter;
	this->material = material;
}

string Wheel::getMaterial() const {
	return material;
}

void Wheel::setMaterial(const string& material) {
	this->material = material;
}

int Wheel::getDiameter() const {
	return diameter;
}

Wheel::Wheel(const Wheel& myWheel) {
	diameter = myWheel.getDiameter();
	material = myWheel.getMaterial();
}

