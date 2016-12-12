#ifndef SLUIS_DOORTHATNEEDSNEWMOTORS_HPP
#define SLUIS_DOORTHATNEEDSNEWMOTORS_HPP

#include "Door.hpp"

class DoorThatNeedsNewMotors : public Door {
public:
    DoorThatNeedsNewMotors(unsigned int port, DoorSide::DoorSide side);
    ~DoorThatNeedsNewMotors();
private:
    const int needsRebootMotorAfter;
};

#endif  // SLUIS_DOORTHATNEEDSNEWMOTORS_HPP