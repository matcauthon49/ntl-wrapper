#ifndef C_WRAPPER_H_
#define C_WRAPPER_H_

#ifdef __cplusplus
    #include <NTL/ZZ_pX.h>
    #include <NTL/ZZ_p.h>
    #include <NTL/ZZ.h>
    #include <iostream>

    using namespace NTL;
extern "C" {
#else
    typedef struct ZZ_pX ZZ_pX;
    typedef struct ZZ_p ZZ_p;
    typedef struct ZZ ZZ;
#endif

// constructor for ZZ
ZZ *ZZ_zero();
ZZ *ZZ_set_long(long a);
ZZ *ZZ_set_string(const char *a);

// constructor for ZZ_p
ZZ_p *ZZ_p_zero();
ZZ_p *ZZ_p_set_long(long a);
ZZ_p *ZZ_p_set_string(const char *a);

// init field modulus
void init_modulus(const ZZ *p);

// constructor and destructor
ZZ_pX *ZZ_pX_zero(); // initializes zero polynomial
ZZ_pX *ZZ_pX_copy(const ZZ_pX *a); // copy
void ZZ_pX_destroy(ZZ_pX *a); // destroy

/* Note: Best practice to construct a poly is to 
   first run ZZ_pX_zero(); and then use SetCoeff.*/

// coefficients
long ZZ_pX_deg(const ZZ_pX *a); // return deg(a)
const ZZ_p *ZZ_pX_coeff(const ZZ_pX *a, long i); // returns the coefficient of X^i
const ZZ_p *ZZ_pX_LeadCoeff(const ZZ_pX *a); // returns the lead coefficient
const ZZ_p *ZZ_pX_ConstTerm(const ZZ_pX *a); // returns constant term

// set coefficients
void ZZ_pX_SetCoeff_fp(ZZ_pX *x, long i, const ZZ_p *a);
void ZZ_pX_SetCoeff_long(ZZ_pX *x, long i, long a);

// set length and remove leading zeroes
void ZZ_pX_SetLength(ZZ_pX *x, long n);
void ZZ_pX_normalize(ZZ_pX *x);
void ZZ_pX_SetX(ZZ_pX *x);

// comparison
long ZZ_pX_eq(ZZ_pX *x, ZZ_pX *y);
long ZZ_pX_neq(ZZ_pX *x, ZZ_pX *y);

// addition (procedural)
void ZZ_pX_add(ZZ_pX *x, const ZZ_pX *a, const ZZ_pX *b); // x = a + b
void ZZ_pX_sub(ZZ_pX *x, const ZZ_pX *a, const ZZ_pX *b); // x = a - b
void ZZ_pX_neg(ZZ_pX *x, const ZZ_pX *a); // x = -a

// multiplication (procedural)
void ZZ_pX_mul(ZZ_pX *x, const ZZ_pX *a, const ZZ_pX *b);
void ZZ_pX_sqr(ZZ_pX *x, const ZZ_pX *a); // x = a^2
void ZZ_pX_power(ZZ_pX *x, const ZZ_pX *a, long e);

// division (procedural)
void ZZ_pX_divRem(ZZ_pX *q, ZZ_pX *r, const ZZ_pX *a, const ZZ_pX *b);
void ZZ_pX_div(ZZ_pX *q, const ZZ_pX *a, const ZZ_pX *b);
void ZZ_pX_div_fp(ZZ_pX *q, const ZZ_pX *a, const ZZ_p *b);
void ZZ_pX_div_long(ZZ_pX *q, const ZZ_pX *a, long b);
void ZZ_pX_rem(ZZ_pX *r, const ZZ_pX *a, const ZZ_pX *b);

// I/O
void ZZ_pX_print(ZZ_pX *x);

// reverse
void ZZ_pX_reverse(ZZ_pX *x, const ZZ_pX *a, long hi);

// random
void ZZ_pX_random(ZZ_pX *x, long n);

// eval
void ZZ_pX_eval(ZZ_p *b, const ZZ_pX *f, const ZZ_p *a);

// modular arithmetic
void ZZ_pX_mulmod(ZZ_pX *x, const ZZ_pX *a, const ZZ_pX *b, const ZZ_pX *f);
void ZZ_pX_sqrmod(ZZ_pX *x, const ZZ_pX *a, const ZZ_pX *f);
void ZZ_pX_invmod(ZZ_pX *x, const ZZ_pX *a, const ZZ_pX *f);


#ifdef __cplusplus
}
#endif

#endif