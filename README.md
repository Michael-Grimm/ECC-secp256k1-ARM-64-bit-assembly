# Secp256k1-ARM-64-bit-assembly
## Implementation of finite field arithmetic and elliptic curve cryptography on the secp256k1 curve in ARM 64-bit assembly.

For better readability of the source code
* aliases are used for all registers -> see file 'aliases'.
* macros encapsulate frequently recurring commands and boilerplate for function declaration -> see files 'commonmacros' and 'u256macros'

C-interface for all public assembly functions: secp256k1.h 

Developed on a RaspberryPi 4 (Broadcom BCM2711, Quad core Cortex-A72 (ARM v8) 64-bit SoC @ 1.5GHz) with ubuntuMATE 20.4
