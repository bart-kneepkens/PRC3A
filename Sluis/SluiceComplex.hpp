#ifndef SLUIS_SLUICECOMPLEX_HPP
#define SLUIS_SLUICECOMPLEX_HPP

#include "Sluice.hpp"

class SluiceComplex {
private:
    Sluice sluiceA;
    Sluice sluiceB;
    Sluice sluiceC;
    Sluice sluiceD;
public:
    SluiceComplex();
    ~SluiceComplex();

    Sluice GetSluice(int index) const;
};

#endif  // SLUIS_SLUICECOMPLEX_HPP