#ifndef SLUIS_DOORTHATNEEDSNEWMOTORS_HPP
#define SLUIS_DOORTHATNEEDSNEWMOTORS_HPP

#include "Door.hpp"

class DoorThatNeedsNewMotors : public Door {
public:
    DoorThatNeedsNewMotors();
    ~DoorThatNeedsNewMotors();
private:
    int needsRebootMotorAfter;
};

#endif  // SLUIS_DOORTHATNEEDSNEWMOTORS_HPP