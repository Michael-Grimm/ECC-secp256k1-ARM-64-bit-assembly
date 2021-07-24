/**
 * Finite field and ecc arithmetic and on the secp256k1-curve in AArch64-assembly.
 * Prime p is 2^256 - c,  with c = 0x1000003d1
 * (SEC 2, section 2.4.1: Recommended Elliptic Curve Domain Parameters,Certicom 
 * Research, 2010, Version 2.0).
 * 
 * A Scalar is an array of four 64-bit unsigned integers (unsigned long long) 
 * with the least significant integer at index 0, the most significant 
 * integer at index 3.
 * For example: the order n of the curve 
 * 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBAAEDCE6AF48A03BBFD25E8CD0364141
 * is represented as array:
 * Scalar n = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};
 * This is the same as unsigned long long n[4] = {0xBFD25.....}:
 * A valid input of a function is in the range of 0 to  2^256 - 1:
 * Scalar f = {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF};
 * is valid.
 * All finite field-functions expect addresses of such arrays.
 * A Scalar as result of a function modulo p is always < p.
 * A Scalar as result of a function modulo n is always < n.
 * Example: 
 * void secp256k1_add_mod_p(const Scalar a, const Scalar b, Scalar r)
 * calculates the sum of a and b modulo p and returns the result in r.
 *
 * A Point on the elliptic curve is represented by its x- and y-coordinates as
 * Scalars.
 * Example: 
 * The generator Point G of the secp256k1-curve
 * G.x = {0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC}; 
 * G.y = {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465};
 *
 * All functions expect valid inputs. There are no checks for the validity of inputs.
 * Invalid inputs cause undefined results or error messages for memory access violations etc.
 */

#ifndef SECP256K1_ARM_64_H
#define SECP256K1_ARM_64_H 

typedef unsigned long long Scalar[4];

typedef struct{
	Scalar x;  
	Scalar y;  
} Point;

typedef struct{
    Scalar r;
    Scalar s;
} Signature;

typedef struct{
    Scalar private_key;
    Point  public_key;
} KeyPair;




/**
 * Testing for equality
 * Returns 0, if a and b have same value, otherwise a value different from 0.
 */
int secp256k1_scalars_equal(Scalar a, Scalar b);

/**
 * Returns 0 if Scalar a is zero ({0,0,0,0}), otherwise 1
 */
int secp256k1_is_zero(Scalar a);


//*************************** Functions modulo p *******************************

/**
 * Reduction of a Scalar modulo p
 * a = a - p,  if a >= p
 * a = a,  if a < p
 */
void secp256k1_reduce_mod_p(Scalar a);
 
/**
 * Addition modulo p
 * r = (a+b) mod p
 */
void secp256k1_add_mod_p(const Scalar a, const Scalar b, Scalar r);

/**
 * Doubling modulo p
 * r = 2a mod p
 */
void secp256k1_double_mod_p(const Scalar a, Scalar r);

/**
 * Doubling modulo p
 * a = 2a mod p
 */
void secp256k1_double_mod_p_asign(const Scalar a);

/**
 * Tripling modulo p
 * r = 3a mod p
 */
void secp256k1_triple_mod_p(const Scalar a, Scalar r);

/**
 * Tripling modulo p
 * a = 3a mod p
 */
void secp256k1_triple_mod_p_asign(const Scalar a, Scalar r);

/**
 * Subtraction modulo p
 * r = (a-b) mod p
 */
void secp256k1_sub_mod_p(const Scalar a, const Scalar b, Scalar r);

/**
 * Negation modulo p
 * r = -a mod p
 */
void secp256k1_negate_mod_p(const Scalar a, Scalar r);

/**
 * Negation modulo p
 * a = -a mod p
 */
void secp256k1_negate_mod_p_asign(Scalar a);

/**
 * Multiplication modulo p
 *  r = (a*b) mod p
 */
void secp256k1_mul_mod_p(const Scalar a, const Scalar b, Scalar r);

/**
 * Squaring modulo p
 * r = a² mod p
 */
void secp256k1_square_mod_p(const Scalar a, Scalar r);

/**
 * Squaring modulo p
 * a = a² mod p
 */
void secp256k1_square_mod_p_asign(Scalar a);

/**
 * Cubing modulo p
 * r = a³ mod p
 */
void secp256k1_cube_mod_p(const Scalar a, Scalar r);

/**
 * Cubing modulo p
 * a = a³ mod p
 */
void secp256k1_cube_mod_p_asign(Scalar a);

/**
 * r = a⁻¹ mod p
 * (with a * r = 1)
 */
void secp256k1_invert_mod_p(const Scalar a, Scalar r);

/**
 * Inverting modulo p
 * a = a⁻¹ mod p
 */
void secp256k1_invert_mod_p_asign(const Scalar a);


/**
 * Taking square root modulo p
 * r = sqareroot(a) mod p
 * a = r² mod p  
 * If a has no squareroot, the result is undefined.
 */
void secp256k1_squareroot_mod_p(const Scalar a, Scalar r);

/**
 * Taking square root modulo p
 * a = sqareroot(a) mod p
 * If a has no squareroot, the result is undefined.
 */
void secp256k1_squareroot_mod_p_asign(Scalar a);


/**
 * Testing for the existence of a square root.
 * The result is 1, if a has a squareroot, otherwise p-1
 */
int secp256k1_has_squareroot_mod_p(const Scalar a);


/**
 * Exponentiation modulo p
 * r = a^e mod p
 */
void secp256k1_exponentiate_mod_p(const Scalar a, const Scalar e, Scalar r);



//***************** Functions for points on the elliptic curve *****************


/**
 * Function secp256k1_compare_points 
 * compares two points a and b.
 * The result is 0 if a == b, otherwise 1.
 */
int  secp256k1_compare_points(const Point *a, const Point *b);

/**
 * Doubling of a point (adding a point to itself)
 * r = a+a
 */
void secp256k1_double_point(const Point *a, Point *r);

/**
 * Doubling of a point (adding a point to itself)
 * a = a+a
 */
void secp256k1_double_point_asign(Point *a);

/**
 * Adding different points
 * r = a + b
 */
void secp256k1_add_different_points(const Point *a, const Point *b, const Point *r);

/**
 * Point multiplication
 * multiplies a point with a scalar k
 * The scalar must be less than the order n.
 * r = k*a
 */
void secp256k1_point_mul(const Point *a, const Scalar k, Point *r);

/**
 * Point multiplication
 * multiplies a point with a scalar k 
 * The scalar must be less than the order n.
 * a = k*a
 */
void secp256k1_point_mul_asign(Point *a, const Scalar k);

/**
 * Multiplication of the generator point G
 * multiplies the generator point G of the curve with a scalar.
 * The scalar must be less than the order n.
 * r = k*G
 */
void secp256k1_generator_mul(const Scalar k, Point *r);

/**
 * Calculation of a public key from a given private key 
 * KeyPair kp must contain a valid private key.
 */
void secp256k1_keypair_from_private_key(KeyPair *kp);


/**
 * Tests whether a point is on the curve
 * This is the case if y³ == x² + 7
 * Result:
 * 0 if point is on curve, otherwise 1.
 */
int secp256k1_is_point_on_curve(const Point *p);

/**
 * Calculation of the even and odd y-coordinates from the x-coordinate.
 * Input:
 * x-coordinate from a point on the curve.
 * Output:
 * even and odd y-coordinates
 */
void secp256k1_calculate_y_coordinates_from_x(const Scalar x, Scalar even_y, Scalar odd_y);


//********************** Functions modulo order n ******************************

/**
 * Reduction of a Scalar modulo n
 * a = a - n,  if a >= n
 * a = a,  if a < n
 */
void secp256k1_reduce_mod_n(Scalar a);


/**
 * Addition modulo n
 * r = (a+b) mod n
 */
void secp256k1_add_mod_n(const Scalar a, const Scalar b, Scalar r);

/**
 * Subtraction modulo n
 * r = (a-b) mod n
 */
void secp256k1_sub_mod_n(const Scalar a, const Scalar b, Scalar r);

/**
 * Multiplication modulo n
 * r = (a*b) mod n
 */
void secp256k1_mul_mod_n(const Scalar a, const Scalar b, Scalar r); 

/**
 * Squaring modulo n
 * r = a² mod n
 */
void secp256k1_square_mod_n(const Scalar a, Scalar r); 

/**
 * Squaring modulo n
 * a = a² mod n
 */
void secp256k1_square_mod_n_asign(const Scalar a); 

/**
 * Inversion modulo n
 * r = a⁻¹ mod n
 * (with a * r = 1)
 */
void secp256k1_invert_mod_n(const Scalar a, Scalar r);

/**
 * Inversion modulo n
 * a = a⁻¹ mod n
 */
void secp256k1_invert_mod_n_asign(const Scalar a);

//************************************* Signing and verifying ******************

/**
 * Signing a message.
 * prk:  the private key of the signer.
 * eph: an ephemeral key pair that must be used only once.  
 * msg: the message (or hash of a message) to be signed. 
 * sig: the resulting signature
 * Algorithm:
 * sig.r = eph.public_key.x
 * sig.s = eph.private_key⁻1 * (msg + eph.public_key.x*prk) mod n
 * sig.s is always in lower-S form: if s > n/2 --> s = n - s
 */
void secp256k1_sign(const Scalar prk, const KeyPair *eph, const Scalar msg, Signature *sig);

/**
 * Verifying a message
 * puk: the public key of the signer
 * msg: the message (or hash of a message) to be verified
 * sig: signature of the message
 * Result: 0 if the message can be verified, otherwise 1
 */
int secp256k1_verify(const Point *puk, const Scalar msg, const Signature *sig);



//********** Functions for parsing strings into Scalars or Points **************
/* 
 A valid string must contain ASCII-characters '0'...'9', 'A'...'F' or 'a'...'f'
 Upper and lower case can be mixed: AaBb ist valid.
 The string must not start with the prefix "0x".
 There is no error checking for valid string length or valid hex-characters
 The result of parsing an invalid string (e.g. 0xIO) is undefined or can cause 
 memory access violation errors if it is too short.
*/

/**
 * The function secp256k1_parse_u64
 * parses a String with a length of 16 chars into an unsigned long long integer.
 */
unsigned long long secp256k1_parse_u64(const char *str);

/**
 * The function secp256k1_parse_scalar
 * parses a String with length of 64 chars into a Scalar.
 */
void secp256k1_parse_scalar(const char *str, Scalar s);

/**
 * The function secp256k1_parse_point
 * parses a String str into a Point pt.
 * If str starts with the two characters "04", it contains both x and y 
 * coordinates and must have a total length of 66 chars.
 * A string starting with "03" or "02" contain only the x coordinate, with a 
 * total length of 34 chars.
 * The y coordinate is calculated from x. 
 * "03" signals the odd, "02" the even y coordinate
 */
void secp256k1_parse_point(const char *str, Point *pt);

/**
 * TODO
 * Parsing a String str into a Signature is not yet implemented.
 */
void secp256k1_parse_signature(const char *str, Signature *sig);


#endif

