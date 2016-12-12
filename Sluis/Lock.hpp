#ifndef SLUIS_LOCK_HPP
#define SLUIS_LOCK_HPP

#include "SluiceSocketClient.hpp"

class Lock {
private:
    const unsigned int port;
    const DoorSide::DoorSide side;
public:
    Lock(unsigned int port, DoorSide::DoorSide side);
    ~Lock();

    void SetLocked(bool locked) const;
    LockState::LockState GetLockState() const;
};

#endif  // SLUIS_LOCK_HPP