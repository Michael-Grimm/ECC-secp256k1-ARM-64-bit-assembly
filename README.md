# Secp256k1-ARM-64-bit-assembly
Implementation of finite field arithmetic and eliptic curve cryptography on the secp256k1 curve in ARM 64-bit assembly.

For better readability of the source code
-aliases are used for all registers -> see file 'aliases'.
-macros encapsulate frequently recurring commands and boilerplate for function declaration -> see files 'commonmacros' and 'u256macros'
C-functions for finite field arithmetic and ecc are in secp256k1.h, u256.h contains two big integer functions (multiplication and squaring) with 512-bit results.
