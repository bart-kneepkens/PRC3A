#include "DoorThatNeedsNewMotors.hpp"

DoorThatNeedsNewMotors::DoorThatNeedsNewMotors(DoorSide::DoorSide side) :
        Door(side), needsRebootMotorAfter(1000) {}

DoorThatNeedsNewMotors::~DoorThatNeedsNewMotors() {}


