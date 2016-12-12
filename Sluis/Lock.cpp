#include "Lock.hpp"

Lock::Lock(DoorSide::DoorSide side) : side(side) { }

Lock::~Lock() { }

void Lock::SetLocked(bool locked) const {
    if (locked) {
        SetLockPower(side, Power::On);
    }
    else {
        SetLockPower(side, Power::Off);
    }
}

LockState::LockState Lock::GetLockState() const {
    return GetDoorLockState(side);
}


