use cty::c_long;
use num::{BigInt, Num};
use wrapper_bindings::ZZ_p_zero;
use std::ffi::CString;

use ark_poly::{self, univariate::DensePolynomial};

use wrapper_bindings::ZZ_p;
use wrapper_bindings::ZZ_pX;
use wrapper_bindings::init_modulus;
use wrapper_bindings::ZZ_set_string;
use wrapper_bindings::ZZ_p_set_string;
use wrapper_bindings::ZZ_pX_SetCoeff_fp;


// Converts arkworks Field element to an NTL ZZ_p.
pub fn ark_to_NTL_ZZ_p<F: ark_ff::PrimeField>(p: F, x: *mut ZZ_p) {

    let p_cstr: CString =  CString::new(BigInt::from_str_radix(
                                           &p.into_repr()
                                               .to_string(), 16)
                                               .unwrap()
                                               .to_string())
                                               .unwrap();
    let p_str = p_cstr.as_ptr() as *const i8;

    let modulus_u64 = F::characteristic();    
    let mut modulus_str: String = "".to_owned();

    for i in 0..modulus_u64.len() {
        modulus_str.push_str(&modulus_u64[i].to_string().to_owned());
    }

    let modulus_cstr = CString::new(modulus_str).unwrap();

    unsafe {
        let modulus = ZZ_set_string(modulus_cstr.as_ptr() as *const i8);
        init_modulus(modulus);

        ZZ_p_set_string(p_str, x);
    }
}


// Converts an arkworks polynomial to an NTL ZZ_pX.
pub fn ark_to_NTL_ZZ_pX<F: ark_ff::PrimeField>(p: DensePolynomial<F>, x: *mut ZZ_pX) {

    let coeff_list: Vec<F> = p.coeffs;
    let length:c_long = coeff_list.len() as i64;

    unsafe {
        let modulus_u64 = F::characteristic();    
        let mut modulus_str: String = "".to_owned();

        for i in 0..modulus_u64.len() {
            modulus_str.push_str(&modulus_u64[i].to_string().to_owned());
        }

        let modulus_cstr = CString::new(modulus_str).unwrap();

        let modulus = ZZ_set_string(modulus_cstr.as_ptr() as *const i8);
        init_modulus(modulus);

        let ziter: *mut ZZ_p = ZZ_p_zero();
        
        for i in 0..length {
            ark_to_NTL_ZZ_p(coeff_list[i as usize], ziter);
            ZZ_pX_SetCoeff_fp(x, i, ziter);
        }
    }
}