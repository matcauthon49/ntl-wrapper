use std::ffi::CString;
use wrapper_bindings::ZZ;
use wrapper_bindings::ZZ_pX_zero;
use wrapper_bindings::ZZ_pX_random;
use wrapper_bindings::ZZ_set_string;
use wrapper_bindings::ZZ_pX_mul;
use wrapper_bindings::ZZ_pX_div;
use wrapper_bindings::ZZ_pX_invmod;
use wrapper_bindings::init_modulus;

use std::time::Instant;

fn check_mul(degree: cty::c_long, p: *mut ZZ) {
    unsafe{
        init_modulus(p);
        let z = ZZ_pX_zero();
        let f = ZZ_pX_zero();
        let g = ZZ_pX_zero();

        ZZ_pX_random(f, degree);
        ZZ_pX_random(g, degree);

        let start_time = Instant::now();
            ZZ_pX_mul(z, f, g);
        let elapsed = start_time.elapsed();
        println!("Multiplication {}: {:.2?}", degree, elapsed);
    }
}

fn check_div(degree: cty::c_long, p: *mut ZZ, linear: bool) {
    unsafe{
        init_modulus(p);
        let z = ZZ_pX_zero();
        let f = ZZ_pX_zero();
        let g = ZZ_pX_zero();

        if linear {
            ZZ_pX_random(f, degree);
            ZZ_pX_random(g, 2);
        }
        else {
            ZZ_pX_random(f, 2*degree);
            ZZ_pX_random(g, degree);
        }

        let start_time = Instant::now();
            ZZ_pX_div(z, f, g);
        let elapsed = start_time.elapsed();
        println!("Division {}: {:.2?}", degree, elapsed);
    }
}

fn check_inv(degree: cty::c_long, p: *mut ZZ) {
    unsafe{
        init_modulus(p);
        let z = ZZ_pX_zero();
        let f = ZZ_pX_zero();
        let g = ZZ_pX_zero();

        ZZ_pX_random(f, degree);
        ZZ_pX_random(g, 2*degree);

        let start_time = Instant::now();
            ZZ_pX_invmod(z, f, g);
        let elapsed = start_time.elapsed();
        println!("Inversion {}: {:.2?}", degree, elapsed);
    }
}

fn main() {
    unsafe {
        let s1 = CString::new("57896044618658097711785492504343953926634992332820282019728792003956564819949".to_string()).unwrap();
        let s2 = CString::new("21888242871839275222246405745257275088548364400416034343698204186575808495617".to_string()).unwrap();
        
        let p = ZZ_set_string(s1.as_ptr() as *const i8);
        let q = ZZ_set_string(s2.as_ptr() as *const i8);

        let s3 = CString::new("10".to_string()).unwrap();
        let r = ZZ_set_string(s3.as_ptr() as *const i8);



    // FFT Unfriendly Arithmetic
   check_mul(10000,p);
   check_mul(100000,p);
   check_mul(1000000,p);

   check_div(10000,p,true);
   check_div(100000,p,true);
   check_div(1000000,p,true);

   check_inv(10000,p);
   check_inv(100000,p);
    //    check_inv(1000000,p);

   // FFT Friendly Arithmetic
   check_mul(10000,q);
   check_mul(100000,q);
   check_mul(1000000,q);

   check_div(10000,q,false);
   check_div(100000,q,false);
   check_div(1000000,q,false);

   check_inv(10000,q);
   check_inv(100000,q);
    //    check_inv(1000000,q);
    }
}