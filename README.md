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