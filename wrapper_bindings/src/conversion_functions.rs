use cty::c_long;
use num::{BigInt, Num};
use std::ffi::CString;

use ark_poly::{self, univariate::DensePolynomial};
use ark_bls12_381::Fq as F;
use ark_std::{UniformRand};

use wrapper_bindings::ZZ_p;
use wrapper_bindings::ZZ_pX;
use wrapper_bindings::init_modulus;
use wrapper_bindings::ZZ_set_string;
use wrapper_bindings::ZZ_p_set_string;
use wrapper_bindings::ZZ_pX_zero;
use wrapper_bindings::ZZ_pX_SetCoeff_fp;


pub fn ark_to_NTL_ZZ_p<F: ark_ff::PrimeField>(p: F) -> *mut ZZ_p {

    let p_str: *const i8 =  CString::new(BigInt::from_str_radix(
                                           &p.into_repr()
                                               .to_string(), 16)
                                               .unwrap()
                                               .to_string())
                                               .unwrap()
                                               .as_ptr() as *const i8;

    let modulus_u64 = F::characteristic();    
    let mut modulus_str: String = "".to_owned();

    for i in 0..modulus_u64.len() {
        modulus_str.push_str(&modulus_u64[i].to_string().to_owned());
    }

    unsafe {
        let modulus = ZZ_set_string(CString::new(modulus_str).unwrap().as_ptr() as *const i8);
        init_modulus(modulus);

        return ZZ_p_set_string(p_str);
    }
}

pub fn ark_to_NTL_ZZ_pX<F: ark_ff::PrimeField>(p: DensePolynomial<F>) -> *mut ZZ_pX {

    let coeff_list: Vec<F> = p.coeffs;
    let length:c_long = coeff_list.len() as i64;

    unsafe {
        let modulus = F::characteristic();
        let pol: *mut ZZ_pX = ZZ_pX_zero();
        
        for i in 0..length {
            ZZ_pX_SetCoeff_fp(pol, i, ark_to_NTL_ZZ_p(coeff_list[i as usize]));
        }
        return pol;
    }
}


pub fn main() {

    
    let mut rng = ark_std::rand::thread_rng();
    
    let a = F::rand(&mut rng);
    let b = F::rand(&mut rng);

    println!("{}", a);
    ark_to_NTL_ZZ_p(a);

}