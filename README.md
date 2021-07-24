# Secp256k1-ARM-64-bit-assembly
## Implementation of finite field arithmetic and eliptic curve cryptography on the secp256k1 curve in ARM 64-bit assembly.

For better readability of the source code
* aliases are used for all registers -> see file 'aliases'.
* macros encapsulate frequently recurring commands and boilerplate for function declaration -> see files 'commonmacros' and 'u256macros'

All C functions for using finite field arithmetic and ecc are in secp256k1.h 

The project was developed on a Raspberry Pi 4, 8GB, with ubuntuMATE 20.4
