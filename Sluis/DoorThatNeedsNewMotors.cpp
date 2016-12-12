#include "DoorThatNeedsNewMotors.hpp"

DoorThatNeedsNewMotors::DoorThatNeedsNewMotors(unsigned int port, DoorSide::DoorSide side) :
        Door(port, side), needsRebootMotorAfter(1000) {}

DoorThatNeedsNewMotors::~DoorThatNeedsNewMotors() {}


