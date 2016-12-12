#include "Lock.hpp"

Lock::Lock(unsigned int port, DoorSide::DoorSide side) : port(port), side(side) { }

Lock::~Lock() { }

void Lock::SetLocked(bool locked) const {
    if (locked) {
        SetLockPower(port, side, Power::On);
    }
    else {
        SetLockPower(port, side, Power::Off);
    }
}

LockState::LockState Lock::GetLockState() const {
    return GetDoorLockState(port, side);
}


