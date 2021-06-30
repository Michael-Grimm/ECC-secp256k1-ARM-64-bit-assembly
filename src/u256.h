/**
 * Big integer functions with 512-bit results.
 */


/**
  The function mul512
  multiplies two 256-bit scalars.
  The result is a 512-bit product split into two scalars
  lo and hi. 
  (lo, hi) = a*b
  This function is used for testing the macro u256mul.
*/ 
void mul512(const Scalar a, const Scalar b, Scalar lo, Scalar hi);





/**
  The function square512
  squares a 256-bit scalar.
  The result is a 512-bit product split into two scalars
  lo and hi. 
  (lo, hi) = a*a
  This function is used for testing the macro u256square.
*/ 
void square512(const Scalar a, Scalar lo, Scalar hi);    
















































