#ifndef SLUIS_LOCK_HPP
#define SLUIS_LOCK_HPP

#include "Enumerators.hpp"

class Lock {
private:
    LockState::LockState state;
    bool locked;
public:
    Lock();
    ~Lock();

    void SetLocked(bool locked);
    bool GetLocked() const;
    LockState::LockState GetLockState() const;
};

#endif  // SLUIS_LOCK_HPP