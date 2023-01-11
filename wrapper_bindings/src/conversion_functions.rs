#![allow(non_snake_case)]
#![allow(dead_code)]

use std::ffi::CString;

use num::{BigUint, BigInt, Num};
use ark_poly::{self, univariate::DensePolynomial, UVPolynomial};
use ark_bls12_381::Fq as F;

use wrapper_bindings::ZZ_p;
use wrapper_bindings::ZZ_pX;
use wrapper_bindings::ZZ_p_random;
use wrapper_bindings::ZZ_p_print;
use wrapper_bindings::ZZ_pX_coeff;
use wrapper_bindings::ZZ_pX_deg;
use wrapper_bindings::ZZ_p_to_string;
use wrapper_bindings::ZZ_p_zero;
use wrapper_bindings::init_modulus;
use wrapper_bindings::ZZ_set_string;
use wrapper_bindings::ZZ_p_set_string;
use wrapper_bindings::ZZ_pX_SetCoeff_fp;

// Takes a field element and initiates the NTL modulus.
pub fn ark_NTL_modulus_init<F: ark_ff::PrimeField>() {
    let mut modulus_u64 = F::characteristic().to_vec(); 
    let mut bytes:Vec<u8> = vec![];
    for e in modulus_u64.iter_mut(){
        for _i in 0..8{
            bytes.push((*e%256).try_into().unwrap());
            *e = *e/256;
        }
    }
    let ans =  CString::new(BigUint::from_bytes_le(bytes.as_slice()).to_string()).unwrap();
    unsafe{
        init_modulus(ZZ_set_string(ans.as_ptr() as *const i8));
    }
    println!("modulus is {:?}", ans);
}

// Converts arkworks Field element to an NTL ZZ_p.
pub fn ark_to_NTL_ZZ_p<F: ark_ff::PrimeField>(p: F, x: *mut ZZ_p, mod_init: bool) {

    let p_cstr: CString =  CString::new(BigInt::from_str_radix(
                                           &p.into_repr()
                                               .to_string(), 16)
                                               .unwrap()
                                               .to_string())
                                               .unwrap();

    let p_str = p_cstr.as_ptr() as *const i8;

    unsafe {
        if mod_init {
            ark_NTL_modulus_init::<F>();
        }
        ZZ_p_set_string(p_str, x);
    }
}


// Converts an arkworks polynomial to an NTL ZZ_pX.
pub fn ark_to_NTL_ZZ_pX<F: ark_ff::PrimeField>(p: DensePolynomial<F>, x: *mut ZZ_pX) {

    let coeff_list: Vec<F> = p.coeffs;
    let length:i64 = coeff_list.len() as i64;

    unsafe {
        ark_NTL_modulus_init::<F>();
        let ziter: *mut ZZ_p = ZZ_p_zero();
        
        for i in 0..length {
            ark_to_NTL_ZZ_p(coeff_list[i as usize], ziter, false);
            ZZ_pX_SetCoeff_fp(x, i, ziter);
        }
    }
}


// Converts an NTL ZZ_p to an arkworks field element.
pub fn NTL_ZZ_p_to_ark<F: ark_ff::PrimeField>(x: *const ZZ_p, bytesize: usize) -> F {
    unsafe{
        let x_cstr: *const u8 = ZZ_p_to_string(x);
        let x_slice = std::slice::from_raw_parts(x_cstr, bytesize);
        let p = F::from_le_bytes_mod_order(x_slice);        
        return p;
    }
}

// Converts an NTL ZZ_pX to an arkworks polynomial.
pub fn NTL_ZZ_pX_to_ark<F: ark_ff::PrimeField>(x: *const ZZ_pX, bytesize: usize) -> DensePolynomial<F> 
{
    unsafe {
        let deg = ZZ_pX_deg(x);
        let mut coeffs:Vec<F> = Vec::new();

        for i in 0..deg {
            coeffs[i as usize] = NTL_ZZ_p_to_ark(ZZ_pX_coeff(x, i), bytesize);
        }

        let poly: DensePolynomial<F> =  DensePolynomial::from_coefficients_vec(coeffs);
        return poly;
    }
}

pub fn main() { 
}