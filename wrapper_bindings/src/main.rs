mod wrapper_tests;
mod ark_tests;

fn main() {
    wrapper_tests::run_wrapper_tests();
    ark_tests::run_ark_tests();
}