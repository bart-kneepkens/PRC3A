#ifndef SLUIS_DOORTHATNEEDSNEWMOTORS_HPP
#define SLUIS_DOORTHATNEEDSNEWMOTORS_HPP

#include "Door.hpp"

/** A faulty sluice door that needs its engines to be restarted every few seconds. */
class DoorThatNeedsNewMotors : public Door {
public:
    DoorThatNeedsNewMotors(DoorSide::DoorSide side);

    ~DoorThatNeedsNewMotors();
};

#endif  // SLUIS_DOORTHATNEEDSNEWMOTORS_HPP