use ark_poly::{self, univariate::DensePolynomial};
use cty::c_long;
use wrapper_bindings::ZZ_pX;
use wrapper_bindings::ZZ_p;
use wrapper_bindings::ZZ_pX_SetCoeff_fp;
use wrapper_bindings::ZZ_pX_zero;


pub fn ark_to_NTL_ZZ_p<F: ark_ff::PrimeField>(p: F) -> *mut ZZ_p {

    let p_str: String  =  p.into_repr().to_string();
    let modulus = F::characteristic();

    // convert modulus to string, then const char*
    // ZZ_set_string(modulus);
    // init_modulus(modulus);
    // convert p_str to a decimal string, and then to const char*
    // ZZ_p_set_string(p_str);
    // return

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

}