# C/Rust wrapper for polynomials in the NTL C++ library

This project contains a C/Rust interface for the NTL fast number theory library, written in C++. The wrapper provides C functions for the type `ZZ_pX`, representing polynomials over a finite field. Special focus is on polynomial multiplication, addition and division. 

## Running 

Clone the repository using `git clone https://github.com/matcauthon49/ntl-wrapper`.

#### Test C code

```bash
gcc -g -O2 -std=c++11 -pthread -march=native test.c wrapper.cpp -lstdc++ -o foo -lntl -lgmp -lm
```

#### Test Rust Code

```bash
cd wrapper_bindings
cargo build
cargo run
```

## Benchmarks (for test.c)

The file `test.c` contains the test code. 

### Multiplication

| Size | FFT-unfriendly Prime (seconds) | FFT-Friendly Prime (seconds) |
|---|---|---|
| $10^5$ | 0.018582 | 0.012680 |
| $10^6$ | 0.175715 | 0.144150 |
| $10^7$ | 1.992733 | 1.625732 |

### Division

| Size | FFT-unfriendly Prime (seconds) | FFT-Friendly Prime (seconds) |
|---|---|---|
| $10^5$ | 0.003868 | 0.048309 |
| $10^6$ | 0.038852 | 0.401810 |
| $10^7$ | 0.384017 | 4.064041 |

Division in the FFT-unfriendly case is only over a linear polynomial.

### Modular Inversion

| Size | FFT-unfriendly Prime (seconds) | FFT-Friendly Prime (seconds) |
|---|---|---|
| $10^5$ | 0.834704 | 0.768921 |
| $10^6$ | 11.425926 | 10.404266 |
| $10^7$ | 127.299347 | 117.063843 |

## Benchmarks (for Rust)

### Multiplication

| Size | FFT-unfriendly Prime (seconds) | FFT-Friendly Prime (seconds) |
|---|---|---|
| $10^5$ | 0.01857 | 0.01258 |
| $10^6$ | 0.18121 | 0.14375 |
| $10^7$ | 1.96 | 1.75 |

### Division

| Size | FFT-unfriendly Prime (seconds) | FFT-Friendly Prime (seconds) |
|---|---|---|
| $10^5$ | 0.00366 | 0.04257 |
| $10^6$ | 0.03771 | 0.40307 |
| $10^7$ | 0.37110 | 4.18 |

Division in the FFT-unfriendly case is only over a linear polynomial.

### Modular Inversion

| Size | FFT-unfriendly Prime (seconds) | FFT-Friendly Prime (seconds) |
|---|---|---|
| $10^5$ | 0.83528 | 0.76754 |
| $10^6$ | 11.28 | 10.41 |
| $10^7$ | killed* | killed* |

*NOTE: Cargo killed the $10^7$ inversion before it could be fully completed.