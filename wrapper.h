#ifndef C_WRAPPER_H_
#define C_WRAPPER_H_

#ifdef __cplusplus
    #include <NTL/ZZ_pX.h>
    #include <NTL/ZZ_p.h>

    using namespace NTL;
extern "C" {
#else
    typedef struct ZZ_pX ZZ_pX;
    typedef struct ZZ_p ZZ_p;
#endif


// constructor and destructor
ZZ_pX *ZZ_pX_zero(); // initializes zero polynomial
ZZ_pX *ZZ_pX_copy(const ZZ_pX *a); // copy
void ZZ_pX_destroy(ZZ_pX *a); // destroy

/* Note: Best practice to construct a poly is to 
   first run ZZ_pX_zero(); and then use SetCoeff.*/

// coefficients
long ZZ_pX_deg(const ZZ_pX *a); // return deg(a)
ZZ_p *ZZ_pX_coeff(const ZZ_pX *a, long i); // returns the coefficient of X^i
ZZ_p *ZZ_pX_LeadCoeff(const ZZ_pX *a); // returns the lead coefficient
ZZ_p *ZZ_pX_ConstTerm(const ZZ_pX *a); // returns constant term

// set coefficients
void SetCoeff(ZZ_pX *x, long i, const ZZ_p *a);
void SetCoeff(ZZ_pX *x, long i, long a);

// set length and remove leading zeroes
void ZZ_pX_SetLength(ZZ_pX *x, long n);
void ZZ_pX_normalize(ZZ_pX *x);

// comparison
long ZZ_pX_eq(ZZ_pX *x, ZZ_pX *y);
long ZZ_pX_neq(ZZ_pX *x, ZZ_pX *y);

// addition
ZZ_pX *ZZ_pX_add(ZZ_pX *x, ZZ_pX *y);
ZZ_pX *ZZ_pX_sub(ZZ_pX *x, ZZ_pX *y);
ZZ_pX *ZZ_pX_neg(ZZ_pX *x);

// addition (procedural)
void ZZ_pX_addp(ZZ_pX *x, const ZZ_pX *a, const ZZ_pX *b); // x = a + b
void ZZ_pX_subp(ZZ_pX *x, const ZZ_pX *a, const ZZ_pX *b); // x = a - b
void ZZ_pX_negp(ZZ_pX *x, const ZZ_pX *a); // x = -a

// addition with constants
ZZ_pX *ZZ_pX_add_const_fp(ZZ_pX *x, const ZZ_p *a);
ZZ_pX *ZZ_pX_add_const_long(ZZ_pX *x, long a);
ZZ_pX *ZZ_pX_sub_const_fp(ZZ_pX *x, const ZZ_p *a);
ZZ_pX *ZZ_pX_sub_const_long(ZZ_pX *x, long a);

// multiplication
ZZ_pX *ZZ_pX_mul(ZZ_pX *x, const ZZ_pX *a);
ZZ_pX *ZZ_pX_mul_fp(ZZ_pX *x, const ZZ_p *a);
ZZ_pX *ZZ_pX_mul_long(ZZ_pX *x, long a);
ZZ_pX *ZZ_pX_sqr(const ZZ_pX *a);
ZZ_pX *ZZ_pX_power(const ZZ_pX *a, long e);

// multiplication (procedural)
void ZZ_pX_mulp(ZZ_pX *x, const ZZ_pX *a, const ZZ_pX *b);
void ZZ_pX_sqrp(ZZ_pX *x, const ZZ_pX *a); // x = a^2
void ZZ_pX_powerp(ZZ_pX *x, const ZZ_pX *a, long e);

// division
ZZ_pX *ZZ_pX_div(ZZ_pX *x, const ZZ_pX *a);
ZZ_pX *ZZ_pX_div_fp(ZZ_pX *x, const ZZ_p *a);
ZZ_pX *ZZ_pX_div_long(ZZ_pX *x, long a);
ZZ_pX *ZZ_pX_rem(ZZ_pX *x, const ZZ_pX *a);

// division (procedural)
void ZZ_pX_divRem(ZZ_pX *q, ZZ_pX *r, const ZZ_pX *a, const ZZ_pX *b);
void ZZ_pX_divp(ZZ_pX *q, const ZZ_pX *a, const ZZ_pX *b);
void ZZ_pX_div_fpp(ZZ_pX *q, const ZZ_pX *a, const ZZ_p *b);
void ZZ_pX_div_longp(ZZ_pX *q, const ZZ_pX *a, long b);
void ZZ_pX_remp(ZZ_pX *q, const ZZ_pX *a, long b);

// I/O
void ZZ_pX_print(ZZ_pX *x);

// reverse
void ZZ_pX_reversep(ZZ_pX *x, const ZZ_pX *a, long hi);
ZZ_pX *ZZ_pX_reverse(const ZZ_pX *a, long hi);

// random
void ZZ_pX_randomp(ZZ_pX *x, long n);
ZZ_pX *ZZ_pX_random(long n);

// eval
void ZZ_pX_evalp(ZZ_p *b, const ZZ_pX *f, const ZZ_p *a);
ZZ_p ZZ_pX_eval(const ZZ_pX *f, const ZZ_p *a);

#ifdef __cplusplus
}
#endif

#endif