#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CuTest.h"
#include "../release/secp256k1.h"

#define scalarEq(exp, res, msg) CuAssertLongLongEquals_Msg(tc, msg, (exp)[0], (res)[0]);\
						   CuAssertLongLongEquals_Msg(tc, msg, (exp)[1], (res)[1]);\
						   CuAssertLongLongEquals_Msg(tc, msg, (exp)[2], (res)[2]);\
						   CuAssertLongLongEquals_Msg(tc, msg, (exp)[3], (res)[3])

//void printScalar(char *msg, long long *s);

/**
Test cases for functions modulo the order n on the secp256k1 elliptic curve.
*/






//******************************************* Tests for functions modulo order n **************************************************************************


void Testsecp256k1_secp256k1_reduce_mod_n_1(CuTest *tc){
        
        Scalar val = {0xffffffffffffffff, 0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff};
        Scalar exp = {0x402da1732fc9bebe,0x4551231950b75fc4, 1};
        secp256k1_reduce_mod_n(val);
        scalarEq(exp, val, "val != exp");
}

void Testsecp256k1_secp256k1_reduce_mod_n_2(CuTest *tc){
        
        Scalar val = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead,0xdadadadadadadada};
        Scalar exp = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead,0xdadadadadadadada};
        secp256k1_reduce_mod_n(val);
        scalarEq(exp, val, "val != exp");
}

void Testsecp256k1_secp256k1_reduce_mod_n_3(CuTest *tc){
        
        Scalar val = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead,0xdadadadadadadada};
        Scalar exp = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead,0xdadadadadadadada};
        secp256k1_reduce_mod_n(val);
        scalarEq(exp, val, "val != exp");
}

void Testsecp256k1_secp256k1_reduce_mod_n_4(CuTest *tc){
        
        Scalar val = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};
        Scalar exp = {0, 0, 0, 0};
        secp256k1_reduce_mod_n(val);
        scalarEq(exp, val, "val != exp");
}




void Testsecp256k1_add_mod_n_1(CuTest *tc){
        
        Scalar a = {0xdadadadadadadada, 0xdeaddeaddeaddead, 0xfefefefefefefefe, 0xabbaabbaabbaabba};
        Scalar b = {0xdadadadadadadada, 0xdeaddeaddeaddead, 0xfadefadefadefade, 0xfadefadefadefade};
        Scalar r;      
        Scalar exp = {0xf5e35728e57f7473,0x02ace0750e131d1f,0xf9ddf9ddf9ddf9df,0xa699a699a699a699};
        secp256k1_add_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}


void Testsecp256k1_add_mod_n_2(CuTest *tc){
        
        Scalar a;
        Scalar b;
        secp256k1_parse_scalar("abbaabbaabbaabbafefefefefefefefedeaddeaddeaddeaddadadadadadadada", a);
        secp256k1_parse_scalar("abbaabbaabbaabbafefefefefefefefedeaddeaddeaddeaddadadadadadadada", b);
        Scalar r;      
        Scalar exp;
        secp256k1_parse_scalar("5775577557755775fdfdfdfdfdfdfdff02ace0750e131d1ff5e35728e57f7473", exp);
        secp256k1_add_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}

void Testsecp256k1_add_mod_n_3(CuTest *tc){
        
        Scalar a;
        Scalar b;
        secp256k1_parse_scalar("abbaabbaabbaabbafefefefefefefefedeaddeaddeaddeaddadadadadadadada", a);
        secp256k1_parse_scalar("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", b);
        Scalar r;      
        Scalar exp;
        secp256k1_parse_scalar("abbaabbaabbaabbafefefefefefeff0023ff01c72f653e721b087c4e0aa49998", exp);
        secp256k1_add_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}

void Testsecp256k1_add_mod_n_4(CuTest *tc){
        
        Scalar a = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;           
        Scalar exp = {0x805b42e65f937d7c, 0x8aa24632a16ebf88, 2,0};
        secp256k1_add_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}

void Testsecp256k1_add_mod_n_5(CuTest *tc){
        
        Scalar a = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};
        Scalar b = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;                         
        Scalar exp = {0x402da1732fc9bebe, 0x4551231950b75fc4, 1,0};
        secp256k1_add_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}

void Testsecp256k1_mul_mod_n_1(CuTest *tc){
        
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0};
        Scalar b = {0xabbaabbaabbaabba, 0, 0, 0};
        Scalar r;  
        Scalar exp = {0x6626efd0797a0324, 0x2e8b0b47e804c4c1, 0xcdf5797d2504d08c, 0x9560837271845f95 };
        secp256k1_mul_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}

void Testsecp256k1_mul_mod_n_2(CuTest *tc){
        
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xabbaabbaabbaabba, 0, 0, 0};
        Scalar r;  
        Scalar exp = {0x4f8d127ac3048852,0x28fb69eac90e6cff, 0x7b00c3d55860da6b, 0xc813076d46c78622};
        secp256k1_mul_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}


void Testsecp256k1_mul_mod_n_3(CuTest *tc){
        
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xabbaabbaabbaabba, 0xdeafdeafdeafdeaf, 0, 0};
        Scalar r;  
        Scalar exp = {0xa2e8a718c8f4391a,0xa4fd92e15fd1a59d,0xa08a0a1a8131661c,0xc46bf510ca0af161};
        secp256k1_mul_mod_n(a, b, r);
       scalarEq(exp, r, "r != expected r");
}



void Testsecp256k1_mul_mod_n_4(CuTest *tc){
        
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xd00fd00fd00fd00f, 0xdeafdeafdeafdeaf, 0xbeefbeefbeefbeef, 0};
        Scalar r;   
        Scalar exp = {0xceca8f047e2a065d,0x892fe175e1492c8a,0x80ffa4c7b53e4040,0xe223f8f9d3aeac68};
        secp256k1_mul_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}
 
void Testsecp256k1_mul_mod_n_5(CuTest *tc){
        
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar r;       
        Scalar exp = {0x0bfa5f0b85eaeb70,0x80c12db9ee712832,0x294c58a8a8328d36,0x1cbdc38ef7120249};
        secp256k1_mul_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}

void Testsecp256k1_mul_mod_n_6(CuTest *tc){
        
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar r;      
        Scalar exp = {0xc4de3cb88fb027e1,0xcc0fde5133bbf131,0x3c1e69b67c8b999b,0x396e3143a2085c94};
        secp256k1_mul_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}

void Testsecp256k1_mul_mod_n_7(CuTest *tc){
        
        Scalar a = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar b = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar r;  
        Scalar exp = {0xbd67421d53d8494f,0x048c8fcce7f19951,0xba8169d64e59d4a0,0x6b6a04942ffeba55};
        secp256k1_mul_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}

void Testsecp256k1_mul_mod_n_8(CuTest *tc){
        
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;           
        Scalar exp = {0xc0e6f362e5557208,0x7f16734fccc1eb89,0xe38e21aaccc99097,0x6e524c9d903e2445};
        secp256k1_mul_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}

void Testsecp256k1_mul_mod_n_9(CuTest *tc){
        Scalar a = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar b = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;         
        Scalar exp = {0x0125f88877059a90,0xd3028865be5a31dc,0xf831f1f592b65040,0x98fa846fd876af4b};
        secp256k1_mul_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}

//******************square mod n

void Testsecp256k1_square_mod_n_1(CuTest *tc){
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar r;      
        Scalar exp = {0xc4de3cb88fb027e1,0xcc0fde5133bbf131,0x3c1e69b67c8b999b,0x396e3143a2085c94};
        secp256k1_square_mod_n(a, r);
        scalarEq(exp, r, "r != expected r");
}

void Testsecp256k1_square_mod_n_2(CuTest *tc){
        Scalar a = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar r;  
        Scalar exp = {0xbd67421d53d8494f,0x048c8fcce7f19951,0xba8169d64e59d4a0,0x6b6a04942ffeba55};
        secp256k1_square_mod_n(a,r);
        scalarEq(exp, r, "r != expected r");
}

void TestSecp256k1_square_mod_n_3(CuTest *tc){
        Scalar val = {0,0,0,0};
        Scalar exp = {0,0,0,0};  
        Scalar res;
        secp256k1_square_mod_n(val,res);
        scalarEq(exp, res, "square 0 = 0");
}

void TestSecp256k1_square_mod_n_4(CuTest *tc){
        Scalar val = {1,0,0,0};
        Scalar exp = {1,0,0,0};  
        Scalar res;
        secp256k1_square_mod_n(val,res);
        scalarEq(exp, res, "square 1 = 1");
}


void TestSecp256k1_square_mod_n_5(CuTest *tc){
        Scalar val = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar exp = {0xc4de3cb88fb027e1, 0xcc0fde5133bbf131, 0x3c1e69b67c8b999b, 0x396e3143a2085c94};  
        Scalar res;
        secp256k1_square_mod_n(val,res);
        scalarEq(exp, res, "exp != val");
}


void TestSecp256k1_square_mod_n_6(CuTest *tc){
        Scalar val = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};//n
        Scalar exp = {0,0,0,0};  
        Scalar res;
        secp256k1_square_mod_n(val,res);
        scalarEq(exp, res, "square n = 0");
}

void TestSecp256k1_square_mod_n_7(CuTest *tc){
        Scalar val = {0xBFD25E8CD0364142, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};;//n+1
        Scalar exp = {1,0,0,0};  
        Scalar res;
        secp256k1_square_mod_n(val,res);
        scalarEq(exp, res, "square n+1 = 1");
}

void TestSecp256k1_square_mod_n_8(CuTest *tc){
        Scalar val = {0xBFD25E8CD0364140, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};;//n-1
        Scalar exp = {1,0,0,0};  
        Scalar res;
        secp256k1_square_mod_n(val,res);
        scalarEq(exp, res, "square n-1 = 1");
}


void TestSecp256k1_square_mod_n_9(CuTest *tc){
        Scalar val = {0xBFD25E8CD036413f, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};//n-2
        Scalar exp = {4,0,0,0};  
        Scalar res;
        secp256k1_square_mod_n(val,res);
        scalarEq(exp, res, "square n-2");
}


void TestSecp256k1_square_mod_n_10(CuTest *tc){
        Scalar val = {0x63b82f6f04ef2777,0x02e84bb7597aabe6,0xa25b0403f1eef757,0xb7c52588d95c3b9a};//Gy-
        Scalar exp = {0x92257b42ad837086,0x459d96fc8984a0b6,0xc84d4ba8fa0fd1f8,0x89190981fdf298d4};  
        Scalar res;
        secp256k1_square_mod_n(val,res);
        scalarEq(exp, res, "square Gy-");
}


void TestSecp256k1_square_mod_n_11(CuTest *tc){

        Scalar val = {0x9c47d08ffb10d4b8,0xfd17b448a6855419,0x5da4fbfc0e1108a8,0x483ada7726a3c465};//Gy+
        Scalar exp = {0xd972e4448d6b5a58,0x471af7794639da50,0x316d2404dcc41ed6,0x308deb5bb5abd3d2};  
        Scalar res;

        secp256k1_square_mod_n(val,res);
        scalarEq(exp, res, "square Gy+");
}

void TestSecp256k1_square_mod_n_12(CuTest *tc){
        Scalar val = {0,0,0,0};
        Scalar exp = {0,0,0,0};  
        Scalar res;
        secp256k1_square_mod_n(val,res);
        scalarEq(exp, res, "square 0");
}


void TestSecp256k1_square_mod_n_13(CuTest *tc){
        Scalar val = {0xf99999999999999f, 0xf99999999999999f, 0xf99999999999999f, 0xf99999999999999f};
        Scalar exp = {0xb755d12813dea34d,0xfdb26a405ddba449,0x4daf61d992f3f07c,0x147786a3879965a8};
        Scalar res;
        secp256k1_square_mod_n(val,res);
        scalarEq(exp, res, "square f999...999f");
}

void TestSecp256k1_square_mod_n_asign_1(CuTest *tc){
        Scalar val = {0x63b82f6f04ef2777,0x02e84bb7597aabe6,0xa25b0403f1eef757,0xb7c52588d95c3b9a};//Gy-
        Scalar exp = {0x92257b42ad837086,0x459d96fc8984a0b6,0xc84d4ba8fa0fd1f8,0x89190981fdf298d4};  
        secp256k1_square_mod_n_asign(val);
        scalarEq(exp, val, "square Gy-");
}


void TestSecp256k1_square_mod_n_asign_2(CuTest *tc){
        Scalar val = {0x9c47d08ffb10d4b8,0xfd17b448a6855419,0x5da4fbfc0e1108a8,0x483ada7726a3c465};//Gy+
        Scalar exp = {0xd972e4448d6b5a58,0x471af7794639da50,0x316d2404dcc41ed6,0x308deb5bb5abd3d2};  
        secp256k1_square_mod_n_asign(val);
        scalarEq(exp, val, "square Gy+");
}


//****************** invert mod n
void Testsecp256k1_invert_mod_n_1(CuTest *tc){

        Scalar val = {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p
        Scalar exp = {0x8f3107a7a3e12be1,0x569fa14fe13edb7f,0x4bc18a61f6631708,0xa57bdc004d93728c}; 
        Scalar inv; 
		secp256k1_invert_mod_n(val,inv);
        scalarEq(exp, inv, "inv p = 0");
}



void Testsecp256k1_invert_mod_n_2(CuTest *tc){

        Scalar val = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};//n
        Scalar exp = {0,0,0,0};  
       	Scalar inv;
		secp256k1_invert_mod_n(val,inv);
        scalarEq(exp, inv, "inv n");
}

void Testsecp256k1_invert_mod_n_3(CuTest *tc){

        Scalar val ={1,0,0,0};
        Scalar exp = {1,0,0,0};  
       	Scalar inv;
		secp256k1_invert_mod_n(val,inv);
        scalarEq(exp, inv, "inv 1");
}



void Testsecp256k1_invert_mod_n_4(CuTest *tc){

        Scalar val ={2,0,0,0};
        Scalar exp = {0xdfe92f46681b20a1,0x5d576e7357a4501d,0xffffffffffffffff,0x7fffffffffffffff};  
       	Scalar inv;
		secp256k1_invert_mod_n(val,inv);
        scalarEq(exp, inv, "inv 2");
}


void Testsecp256k1_invert_mod_n_5(CuTest *tc){

        Scalar val ={4,0,0,0};
        Scalar exp = {0xcfddc6e99c28b0f1, 0x0c0325ad0376782c, 0xffffffffffffffff, 0xbfffffffffffffff};        
       	Scalar inv;
		secp256k1_invert_mod_n(val,inv);
        scalarEq(exp, inv, "val != inv 4");
}



void Testsecp256k1_invert_mod_n_6(CuTest *tc){

        Scalar val ={0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar exp = {0xa09cccd761df4fd8, 0x261fb885f90ae37e, 0x39d289d99a963637, 0x1ae4490de9f04989};  
       	Scalar inv;
		secp256k1_invert_mod_n(val,inv);
        scalarEq(exp, inv, "inv abba...");
}


void Testsecp256k1_invert_mod_n_7(CuTest *tc){

        Scalar val ={0x5a1f8ffde8773176,0x40c247f073ce1f4c,0xbc0e1455985c0c8e,0xf089eaef57aba315};
        Scalar exp = {0x4b6cb9993c67beaf,0x5f16f1eab3900559,0x4c2453286480f13a,0x670ba7fe0feea77a};  
       	Scalar inv;
		secp256k1_invert_mod_n(val,inv);
        scalarEq(exp, inv, "val != exp");
}

void Testsecp256k1_invert_mod_n_8(CuTest *tc){

        Scalar val ={1234567890,0,0,0};
		Scalar exp = {0xf4484e8dceb39d91, 0xa0c6ba7347f32b95, 0xf23bfbb091158daa, 0x6bd555ecd0e4e06d};
     	Scalar inv;
    	secp256k1_invert_mod_n(val,inv);
        scalarEq(exp, inv, "inv 1234567890");
}


void Testsecp256k1_invert_mod_n_asign_1(CuTest *tc){
        Scalar val ={0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar exp = {0xa09cccd761df4fd8, 0x261fb885f90ae37e, 0x39d289d99a963637, 0x1ae4490de9f04989};  
		secp256k1_invert_mod_n_asign(val);
        scalarEq(exp, val, "inv abba...");
}


void Testsecp256k1_invert_mod_n_asign_2(CuTest *tc){

        Scalar val ={0x5a1f8ffde8773176,0x40c247f073ce1f4c,0xbc0e1455985c0c8e,0xf089eaef57aba315};
        Scalar exp = {0x4b6cb9993c67beaf,0x5f16f1eab3900559,0x4c2453286480f13a,0x670ba7fe0feea77a};  
		secp256k1_invert_mod_n_asign(val);
        scalarEq(exp, val, "val != exp");
}


//******************sub mod n

void Testsecp256k1_sub_mod_n_1(CuTest *tc){
        
        Scalar a = {0xdadadadadadadada, 0xdeaddeaddeaddead, 0xfefefefefefefefe, 0xabbaabbaabbaabba};
        Scalar b = {0xdadadadadadadada, 0xdeaddeaddeaddead, 0xfadefadefadefade, 0xfadefadefadefade};
        Scalar r;     
        Scalar exp = {0xbfd25e8cd0364141, 0xbaaedce6af48a03b, 0x042004200420041e, 0xb0dbb0dbb0dbb0dc};
        secp256k1_sub_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}

void Testsecp256k1_sub_mod_n_2(CuTest *tc){
		

        Scalar a =   {0x5a1f8ffde8773176,0x40c247f073ce1f4c, 0xbc0e1455985c0c8e, 0xf089eaef57aba315};
        Scalar b =   {0x3d3cc4a3546ee4e8,0xc5a830101aabff78, 0xf1fe87385a4582e7, 0xf3b1b70975dec6dd};
        Scalar exp = {0xdcb529e7643e8dcf,0x35c8f4c7086ac00f, 0xca0f8d1d3e1689a5, 0xfcd833e5e1ccdc37};
        Scalar r;                  
        secp256k1_sub_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}

void Testsecp256k1_sub_mod_n_3(CuTest *tc){
		
        
        Scalar a = {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b = {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r; 
        Scalar exp =  {0,0,0,0};
        secp256k1_sub_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}

void Testsecp256k1_sub_mod_n_4(CuTest *tc){
		

        Scalar a = {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b = {0xfffffffefffffc2f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r; 
        Scalar exp =  {0x1000003d0,0,0,0};
        secp256k1_sub_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}


void Testsecp256k1_sub_mod_n_5(CuTest *tc){
		

        Scalar a = {0xfffffffefffffc2f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b = {0xfffffffefffffc2f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r; 
        Scalar exp =  {0,0,0,0};
        secp256k1_sub_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}

void Testsecp256k1_sub_mod_n_6(CuTest *tc){
		

        Scalar a = {0,0,0,0};
        Scalar b = {0,0,0,0};
        Scalar r; 
        Scalar exp =  {0,0,0,0};
        secp256k1_sub_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}

void Testsecp256k1_sub_mod_n_7(CuTest *tc){
		
        Scalar a = {0xfffffffefffffc2f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b = {1,0,0,0};
        Scalar r;                          
        Scalar exp =  {0x402da1722fc9baed,0x4551231950b75fc4, 1, 0};
        secp256k1_sub_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}

void Testsecp256k1_sub_mod_n_8(CuTest *tc){
		

        Scalar a = {1,0,0,0};
        Scalar b = {0xBFD25E8CD0364141,0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xffffffffffffffff};
        Scalar r; 
        Scalar exp =  {1,0,0,0};
        secp256k1_sub_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}

void Testsecp256k1_sub_mod_n_9(CuTest *tc){
		

        Scalar a = {1,0,0,0};
        Scalar b = {5,0,0,0};
        Scalar r;  
        Scalar exp =  {0xbfd25e8cd036413d,0xbaaedce6af48a03b, 0xfffffffffffffffe, 0xffffffffffffffff};
        secp256k1_sub_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}

void Testsecp256k1_sub_mod_n_10(CuTest *tc){
		

        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar r; 
        Scalar exp =  {0,0,0,0};
        secp256k1_sub_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}

void Testsecp256k1_sub_mod_n_11(CuTest *tc){
        Scalar a = {0xBFD25E8CD0364141,0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xffffffffffffffff};
        Scalar b = {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r; 
        Scalar exp =  {0x7fa4bd19a06c8283,0x755db9cd5e914077, 0xfffffffffffffffd, 0xffffffffffffffff};
        secp256k1_sub_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}

void Testsecp256k1_sub_mod_n_12(CuTest *tc){
		

        Scalar a = {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};
        Scalar r; 
        Scalar exp = {0x402da1732fc9bebe,0x4551231950b75fc4,1,0};
        secp256k1_sub_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}

void Testsecp256k1_sub_mod_n_13(CuTest *tc){
        Scalar a = {0xBFD25E8CD0364141,0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xffffffffffffffff};
        Scalar b = {1,0,0,0};
        Scalar r;                          
        Scalar exp = {0xBFD25E8CD0364140, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};
        secp256k1_sub_mod_n(a, b, r);
        scalarEq(exp, r, "r != expected r");
}


