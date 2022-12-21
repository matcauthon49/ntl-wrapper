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

const ZZ_p *ZZ_pX_coeff(const ZZ_pX *a, long i) {
    const ZZ_p *z = &coeff(*a, i);
    return z;
};

const ZZ_p *ZZ_pX_LeadCoeff(const ZZ_pX *a) {
    const ZZ_p *z = &LeadCoeff(*a);
    return z;
};

const ZZ_p *ZZ_pX_ConstTerm(const ZZ_pX *a) {
    const ZZ_p *z = &ConstTerm(*a);
    return z;
};

void ZZ_pX_SetCoeff_fp(ZZ_pX *x, long i, const ZZ_p *a) {
    SetCoeff(*x, i, *a);
};

void ZZ_pX_SetCoeff_long(ZZ_pX *x, long i, long a){
    SetCoeff(*x, i, a);
};

void ZZ_pX_SetLength(ZZ_pX *x, long n){
    (*x).SetLength(n);
};

void ZZ_pX_normalize(ZZ_pX *x){
    (*x).normalize();
};

void ZZ_pX_SetX(ZZ_pX *x) {
    NTL::SetX(*x);
};

// equality
long ZZ_pX_eq(ZZ_pX *x, ZZ_pX *y){
    return *x == *y;
};

long ZZ_pX_neq(ZZ_pX *x, ZZ_pX *y){
    return *x != *y;
};

// addition
ZZ_pX *ZZ_pX_add(const ZZ_pX *x, const ZZ_pX *y){
    ZZ_pX *z = &(*x+*y);
    return z;
};

ZZ_pX *ZZ_pX_sub(const ZZ_pX *x, const ZZ_pX *y){
    ZZ_pX *z = &(*x-*y);
    return z;
};

ZZ_pX *ZZ_pX_neg(const ZZ_pX *x){
    ZZ_pX *z = &(-*x);
    return z;
};

void ZZ_pX_addp(ZZ_pX *x, const ZZ_pX *a, const ZZ_pX *b){
    add(*x, *a, *b);
};

void ZZ_pX_subp(ZZ_pX *x, const ZZ_pX *a, const ZZ_pX *b){
    sub(*x, *a, *b);
};

void ZZ_pX_negatep(ZZ_pX *x, const ZZ_pX *a){
    negate(*x, *a);
};