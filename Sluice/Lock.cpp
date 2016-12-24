#include "Lock.hpp"

Lock::Lock(DoorSide::DoorSide side) : side(side) {}

Lock::~Lock() {}

void Lock::SetLocked(bool locked) const {
    if (locked) {
        sluice_client::CLIENT->SetLockPower(side, Power::On);
    } else {
        sluice_client::CLIENT->SetLockPower(side, Power::Off);
    }
}

LockState::LockState Lock::GetLockState() const {
    return sluice_client::CLIENT->GetDoorLockState(side);
}


