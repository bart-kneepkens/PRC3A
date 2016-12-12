#ifndef SLUIS_SLUICECOMPLEX_HPP
#define SLUIS_SLUICECOMPLEX_HPP

#include "Sluice.hpp"

class SluiceComplex {
private:
    const Sluice sluiceA = Sluice(5555);
    const Sluice sluiceB = Sluice(5556);
    const Sluice sluiceC = Sluice(5557, DoorType::Timed);
    const Sluice sluiceD = Sluice(5558, DoorType::NeedsNewMotors);
public:
    SluiceComplex();
    ~SluiceComplex();

    Sluice const& GetSluice(int index) const;
};

#endif  // SLUIS_SLUICECOMPLEX_HPP