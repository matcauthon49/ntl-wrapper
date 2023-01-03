#include "wrapper.h"

// ZZ constructors
ZZ *ZZ_zero() {
    ZZ *z = new ZZ();
    return z;
};

ZZ *ZZ_set_long(long a) {
    ZZ *z = new ZZ();
    *z = a;
    return z;
};

 ZZ *ZZ_set_string(const char *a){
    ZZ *x = new ZZ();
    ZZ z(INIT_VAL, a);
    *x = z;
    return x;
};

// ZZ_p constructors
ZZ_p *ZZ_p_zero() {
    ZZ_p *z = new ZZ_p();
    return z;
};

ZZ_p *ZZ_p_set_long(long a) {
    ZZ_p *z = new ZZ_p();
    *z = a;
    return z;
};

 ZZ_p *ZZ_p_set_string(const char *a){
    ZZ_p *x = new ZZ_p();
    ZZ z(INIT_VAL, a);
    ZZ_p w = to_ZZ_p(z);
    *x = w;
    return x;
};

// initiate field modulus
void init_modulus(const ZZ *p){
    ZZ_p::init(*p);
};

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

// addition (procedural)
void ZZ_pX_add(ZZ_pX *x, const ZZ_pX *a, const ZZ_pX *b){
    add(*x, *a, *b);
};

void ZZ_pX_sub(ZZ_pX *x, const ZZ_pX *a, const ZZ_pX *b){
    sub(*x, *a, *b);
};

void ZZ_pX_negate(ZZ_pX *x, const ZZ_pX *a){
    negate(*x, *a);
};

// multiplication (procedural)
void ZZ_pX_mul(ZZ_pX *x, const ZZ_pX *a, const ZZ_pX *b) {
    mul(*x, *a, *b);
};

void ZZ_pX_sqr(ZZ_pX *x, const ZZ_pX *a) {
    sqr(*x, *a);
}; // x = a^2

void ZZ_pX_power(ZZ_pX *x, const ZZ_pX *a, long e){
    power(*x, *a, e);
};

// division (procedural)
void ZZ_pX_divRem(ZZ_pX *q, ZZ_pX *r, const ZZ_pX *a, const ZZ_pX *b){
    DivRem(*q, *r, *a, *b);
};

void ZZ_pX_div(ZZ_pX *q, const ZZ_pX *a, const ZZ_pX *b){
    div(*q, *a, *b);
};

void ZZ_pX_div_fp(ZZ_pX *q, const ZZ_pX *a, const ZZ_p *b){
    div(*q, *a, *b);
};

void ZZ_pX_div_long(ZZ_pX *q, const ZZ_pX *a, long b){
    div(*q, *a, b);
};

void ZZ_pX_rem(ZZ_pX *r, const ZZ_pX *a, const ZZ_pX *b){
    rem(*r, *a, *b);
};

void ZZ_pX_print(ZZ_pX *x){
    std::cout << *x;
};

// reverse
void ZZ_pX_reverse(ZZ_pX *x, const ZZ_pX *a, long hi){
    reverse(*x, *a, hi);
};

void ZZ_pX_random(ZZ_pX *x, long n) {
    random(*x, n);
};

void ZZ_pX_eval(ZZ_p *b, const ZZ_pX *f, const ZZ_p *a){
    eval(*b, *f, *a);
};

// modular arithmetic
void ZZ_pX_mulmod(ZZ_pX *x, const ZZ_pX *a, const ZZ_pX *b, const ZZ_pX *f){
    MulMod(*x, *a, *b, *f);
};

void ZZ_pX_sqrmod(ZZ_pX *x, const ZZ_pX *a, const ZZ_pX *f){
    SqrMod(*x, *a, *f);
};

void ZZ_pX_invmod(ZZ_pX *x, const ZZ_pX *a, const ZZ_pX *f){
    InvMod(*x, *a, *f);
};
