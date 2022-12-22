#include "wrapper.h"
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void check_mul(int degree, ZZ *p){
    init_modulus(p);
    ZZ_pX *z = ZZ_pX_zero();
    ZZ_pX *f = ZZ_pX_zero();
    ZZ_pX *g = ZZ_pX_zero();

    ZZ_pX_random(f, degree);
    ZZ_pX_random(g, degree);

    float startTime = (float)clock()/CLOCKS_PER_SEC;
        ZZ_pX_mul(z, f, g);
    float endTime = (float)clock()/CLOCKS_PER_SEC;

    float timeElapsed = endTime - startTime;
    printf("Multiplication %d: %f\n", degree, timeElapsed);
}

void check_div(int degree, ZZ *p, bool linear){
    init_modulus(p);
    ZZ_pX *z = ZZ_pX_zero();
    ZZ_pX *f = ZZ_pX_zero();
    ZZ_pX *g = ZZ_pX_zero();

    if (linear) {
        ZZ_pX_random(f, degree);
        ZZ_pX_random(g, 2);
    }
    else {
        ZZ_pX_random(f, 2*degree);
        ZZ_pX_random(g, degree);
    }

    float startTime = (float)clock()/CLOCKS_PER_SEC;
        ZZ_pX_div(z, f, g);
    float endTime = (float)clock()/CLOCKS_PER_SEC;

    float timeElapsed = endTime - startTime;
    printf("Division %d: %f\n", degree, timeElapsed);
}

void check_inv(int degree, ZZ *p){
    init_modulus(p);
    ZZ_pX *z = ZZ_pX_zero();
    ZZ_pX *f = ZZ_pX_zero();
    ZZ_pX *g = ZZ_pX_zero();

    ZZ_pX_random(f, degree);
    ZZ_pX_random(g, 2*degree);

    float startTime = (float)clock()/CLOCKS_PER_SEC;
        ZZ_pX_invmod(z, f, g);
    float endTime = (float)clock()/CLOCKS_PER_SEC;

    float timeElapsed = endTime - startTime;
    printf("Inversion %d: %f\n", degree, timeElapsed);
}


int main() 
{
   ZZ *p = ZZ_set_string("57896044618658097711785492504343953926634992332820282019728792003956564819949");
   ZZ *q = ZZ_set_string("21888242871839275222246405745257275088548364400416034343698204186575808495617");
   
   // FFT Unfriendly Arithmetic
   check_mul(10000,p);
   check_mul(100000,p);
   check_mul(1000000,p);

   check_div(10000,p,true);
   check_div(100000,p,true);
   check_div(1000000,p,true);

   check_inv(10000,p);
   check_inv(100000,p);
   check_inv(1000000,p);

   // FFT Friendly Arithmetic
   check_mul(10000,q);
   check_mul(100000,q);
   check_mul(1000000,q);

   check_div(10000,q,false);
   check_div(100000,q,false);
   check_div(1000000,q,false);

   check_inv(10000,q);
   check_inv(100000,q);
   check_inv(1000000,q);

   return 0;
}
