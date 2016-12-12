#include "SluiceComplex.hpp"

SluiceComplex::SluiceComplex() {

}

SluiceComplex::~SluiceComplex() {

}

Sluice const& SluiceComplex::GetSluice(int index) const {
    switch (index) {
        case 0:
            return sluiceA;
        case 1:
            return sluiceB;
        case 2:
            return sluiceC;
        default:
            return sluiceD;
    }
}
