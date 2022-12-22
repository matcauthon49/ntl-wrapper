# C wrapper for polynomials in the NTL C++ library

This project contains a C interface for the NTL fast number theory library, written in C++. The wrapper provides C functions for the type `ZZ_pX`, representing polynomials over a finite field. Special focus is on polynomial multiplication, addition and division. 

## Benchmarks

The file `test.c` contains the test code. 

### Multiplication

| Size | FFT-unfriendly Prime (seconds) | FFT-Friendly Prime (seconds) |
|---|---|---|
| $10^5$ | 0.018582 | 0.012680 |
| $10^6$ | 0.175715 | 0.144150 |
| $10^8$ | 1.992733 | 1.625732 |

### Division

| Size | FFT-unfriendly Prime (seconds) | FFT-Friendly Prime (seconds) |
|---|---|---|
| $10^5$ | 0.003868 | 0.048309 |
| $10^6$ | 0.038852 | 0.401810 |
| $10^8$ | 0.384017 | 4.064041 |

Division in the FFT-unfriendly case is only over a linear polynomial.

### Modular Inversion

| Size | FFT-unfriendly Prime (seconds) | FFT-Friendly Prime (seconds) |
|---|---|---|
| $10^5$ | 0.834704 | 0.768921 |
| $10^6$ | 11.425926 | 10.404266 |
| $10^8$ | 127.299347 | 117.063843 |