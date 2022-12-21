#include "wrapper.h"

// constructors
ZZ_pX *ZZ_pX_zero() {
    ZZ_pX *z = new ZZ_pX();
    return z;
}; 

ZZ_pX *ZZ_pX_copy(const ZZ_pX *a) {
    ZZ_pX *z = new ZZ_pX(*a);
    return z;
};

void ZZ_pX_destroy(ZZ_pX *a) {
    delete a;
};

// coefficients
long ZZ_pX_deg(const ZZ_pX *a) {
    return NTL::deg(*a);
};

ZZ_p *ZZ_pX_coeff(const ZZ_pX *a, long i) {
    ZZ_p *z = coeff(*a, i);
    return z;
};

void ZZ_pX_SetX(ZZ_pX *x) {
    NTL::SetX(*x);
};