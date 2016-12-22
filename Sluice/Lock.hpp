#ifndef SLUIS_LOCK_HPP
#define SLUIS_LOCK_HPP

#include "SluiceSocketClient.hpp"

class Lock {
private:
    const DoorSide::DoorSide side;
public:
    Lock(DoorSide::DoorSide side);
    ~Lock();

    void SetLocked(bool locked) const;
    LockState::LockState GetLockState() const;
};

#endif  // SLUIS_LOCK_HPP