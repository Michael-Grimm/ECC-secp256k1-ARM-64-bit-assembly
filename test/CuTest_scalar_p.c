#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CuTest.h"
#include "../release/secp256k1.h"

#define scalarEq(exp, res, msg) CuAssertLongLongEquals_Msg(tc, msg, (exp)[0], (res)[0]);\
						   CuAssertLongLongEquals_Msg(tc, msg, (exp)[1], (res)[1]);\
						   CuAssertLongLongEquals_Msg(tc, msg, (exp)[2], (res)[2]);\
						   CuAssertLongLongEquals_Msg(tc, msg, (exp)[3], (res)[3])
 
/**
  Tests for functions mod p
*/

void TestSecp256k1_add_mod_p_1(CuTest *tc){
		
        Scalar a =   {0x5a1f8ffde8773176,0x40c247f073ce1f4c, 0xbc0e1455985c0c8e, 0xf089eaef57aba315};
        Scalar b =   {0x3d3cc4a3546ee4e8,0xc5a830101aabff78, 0xf1fe87385a4582e7, 0xf3b1b70975dec6dd};
        Scalar r;
        Scalar exp = {0x975c54a23ce61a2f,0x066a78008e7a1ec4, 0xae0c9b8df2a18f76, 0xe43ba1f8cd8a69f3};
        secp256k1_add_mod_p(a, b, r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_add_mod_p_2(CuTest *tc){
		
        Scalar a={0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b={0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;
        Scalar exp = {0x2000007a0,0,0,0};
        secp256k1_add_mod_p(a, b, r);
        scalarEq(exp, r, "r != exp");

}


void TestSecp256k1_add_mod_p_3(CuTest *tc){
		
        Scalar a = {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;
        Scalar exp = {0x1000003d0,0,0,0};
        secp256k1_add_mod_p(a, b, r);
        scalarEq(exp, r, "r != exp");

}

void TestSecp256k1_add_mod_p_4(CuTest *tc){
		
        Scalar a = {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b = {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;
        Scalar exp = {0,0,0,0};
        secp256k1_add_mod_p(a, b, r);
        scalarEq(exp, r, "r != exp");

}


void TestSecp256k1_add_mod_p_5(CuTest *tc){
		
        Scalar a = {0,0,0,0};
        Scalar b = {0,0,0,0};
        Scalar r;
        Scalar exp = {0,0,0,0};
        secp256k1_add_mod_p(a, b, r);
        scalarEq(exp, r, "r != exp");

}


void TestSecp256k1_add_mod_p_6(CuTest *tc){
		
        Scalar a ={1,0,0,0};
        Scalar b ={0xfffffffefffffc30, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;
        Scalar exp = {2,0, 0, 0};
        secp256k1_add_mod_p(a, b, r);
        scalarEq(exp, r, "r != exp");

}

void TestSecp256k1_add_mod_p_7(CuTest *tc){
		
        Scalar a = {1,0,0,0};
        Scalar b = {0xfffffffefffffc2e,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;
        Scalar exp = {0,0,0,0};
        secp256k1_add_mod_p(a, b, r);
        scalarEq(exp, r, "r != exp");

}


void TestSecp256k1_add_mod_p_8(CuTest *tc){
		
        Scalar a = {0xfffffffefffffc2e,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b = {0xfffffffefffffc2e,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;
        Scalar exp = {0xfffffffefffffc2d,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff}; 
        secp256k1_add_mod_p(a, b, r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_add_mod_p_9(CuTest *tc){
		
        Scalar a = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};
        Scalar b = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};
        Scalar r;
        Scalar exp = {0x7fa4bd1aa06c8653,0x755db9cd5e914077, 0xfffffffffffffffd, 0xffffffffffffffff};
        secp256k1_add_mod_p(a, b, r);
        scalarEq(exp, r, "r != exp");

}


void TestSecp256k1_add_mod_p_10(CuTest *tc){
		
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};
        Scalar r;
        Scalar exp = {0x6b8d0a487bf0f0cc, 0xb9addbe5ae479f3a, 0xdeaddeaddeaddeac, 0xcafecafecafecafe};
        secp256k1_add_mod_p(a, b, r);
        scalarEq(exp, r, "r != exp");


}

void TestSecp256k1_add_mod_p_11(CuTest *tc){
		
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar r;
        Scalar exp = {0x5775577657755b45, 0xfdfdfdfdfdfdfdfd, 0xbd5bbd5bbd5bbd5b, 0x95fd95fd95fd95fd};
        secp256k1_add_mod_p(a, b, r);
        scalarEq(exp, r, "r != exp");

}

void TestSecp256k1_double_mod_p_1(CuTest *tc){
		
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar r;
        Scalar exp = {0x5775577657755b45, 0xfdfdfdfdfdfdfdfd, 0xbd5bbd5bbd5bbd5b, 0x95fd95fd95fd95fd};
        secp256k1_double_mod_p(a, r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_double_mod_p_2(CuTest *tc){
		
        Scalar a = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};
        Scalar r;
       
        Scalar exp = {0x7fa4bd1aa06c8653,0x755db9cd5e914077, 0xfffffffffffffffd, 0xffffffffffffffff};
        secp256k1_double_mod_p(a, r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_double_mod_p_3(CuTest *tc){
		
        Scalar a = {0xfffffffefffffc2e,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;
        Scalar exp = {0xfffffffefffffc2d,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};        
        secp256k1_double_mod_p(a, r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_double_mod_p_4(CuTest *tc){
		
        Scalar a = {0,0,0,0};
        Scalar r;
        Scalar exp = {0,0,0,0};      
        secp256k1_double_mod_p(a, r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_double_mod_p_5(CuTest *tc){
		
        Scalar a={0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;
        Scalar exp = {0x2000007a0,0,0,0};   
        secp256k1_double_mod_p(a, r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_double_mod_p_6(CuTest *tc){
		
        Scalar a = {1,2,3,4};
        Scalar r;
        Scalar exp = {2,4,6,8};      
        secp256k1_double_mod_p(a, r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_triple_mod_p_1(CuTest *tc){
		
        Scalar a = {0,0,0,0};
        Scalar r;
        Scalar exp = {0,0,0,0};      
        secp256k1_triple_mod_p(a, r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_triple_mod_p_2(CuTest *tc){
		
        Scalar a = {0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff};
        Scalar r;
        Scalar exp = {0x300000b70,0,0,0};      
        secp256k1_triple_mod_p(a, r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_triple_mod_p_3(CuTest *tc){
		
        Scalar a = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};
        Scalar r;      
        Scalar exp = {0x3f771ba870a2cb65, 0x300c96b40dd9e0b3, 0xfffffffffffffffc, 0xffffffffffffffff};     
        secp256k1_triple_mod_p(a, r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_triple_mod_p_4(CuTest *tc){
		
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar r;   
        Scalar exp = {0x0330033203300ad0,0xfcfcfcfcfcfcfcfc,0x9c099c099c099c09,0x60fc60fc60fc60fc};      
        secp256k1_triple_mod_p(a, r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_triple_mod_p_5(CuTest *tc){
		
        Scalar a = {1,2,3,4};
        Scalar r;
        Scalar exp = {3,6,9,12};      
        secp256k1_triple_mod_p(a, r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_triple_mod_p_6(CuTest *tc){
		
        Scalar a = {0xfffffffefffffc2f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;
        Scalar exp = {0,0,0,0};      
        secp256k1_triple_mod_p(a, r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_triple_mod_p_7(CuTest *tc){
		
        Scalar a = {0xfffffffefffffc30,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;
        Scalar exp = {3,0,0,0};      
        secp256k1_triple_mod_p(a, r);
        scalarEq(exp, r, "r != exp");
}


void TestSecp256k1_triple_mod_p_8(CuTest *tc){
		
        Scalar a = {0,0,0,0};
        Scalar r;
        Scalar exp = {0,0,0,0};      
        secp256k1_triple_mod_p(a, r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_sub_mod_p_1(CuTest *tc){
        Scalar a =  {0x5a1f8ffde8773176,0x40c247f073ce1f4c, 0xbc0e1455985c0c8e, 0xf089eaef57aba315}; 
        Scalar b =  {0x3d3cc4a3546ee4e8,0xc5a830101aabff78, 0xf1fe87385a4582e7, 0xf3b1b70975dec6dd};
        Scalar r;
        Scalar exp =  {0x1ce2cb59940848bd,0x7b1a17e059221fd4, 0xca0f8d1d3e1689a6, 0xfcd833e5e1ccdc37};
        secp256k1_sub_mod_p(a, b, r);
        scalarEq(exp, r, "r != exp");

}

void TestSecp256k1_sub_mod_p_2(CuTest *tc){
        Scalar a = {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff}; 
        Scalar b = {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff}; 
        Scalar r;
        Scalar exp = {0,0,0,0}; 
        secp256k1_sub_mod_p(a, b, r);
        scalarEq(exp, r, "r != exp");

}

void TestSecp256k1_sub_mod_p_3(CuTest *tc){
        Scalar a = {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff}; 
        Scalar b =  {0xfffffffefffffc2f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff}; 
        Scalar r;
        Scalar exp = {0x1000003d0,0,0,0}; 
        secp256k1_sub_mod_p(a, b, r);
        scalarEq(exp, r, "r != exp");

}


void TestSecp256k1_sub_mod_p_4(CuTest *tc){
        Scalar a =  {0xfffffffefffffc2f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =  {0xfffffffefffffc2f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;
        Scalar exp = {0,0,0,0}; 
        secp256k1_sub_mod_p(a, b, r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_sub_mod_p_5(CuTest *tc){
        Scalar a =  {0,0,0,0};
        Scalar b =  {0,0,0,0};
        Scalar r;
        Scalar exp = {0,0,0,0}; 
        secp256k1_sub_mod_p(a, b, r);
        scalarEq(exp, r, "r != exp");

}

void TestSecp256k1_sub_mod_p_6(CuTest *tc){
        Scalar a =  {0xfffffffefffffc2f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =  {1,0,0,0};
        Scalar r;
        Scalar exp = {0xfffffffefffffc2e,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff}; 
        secp256k1_sub_mod_p(a, b, r);
        scalarEq(exp, r, "r != exp");

}

void TestSecp256k1_sub_mod_p_7(CuTest *tc){
        Scalar a = {1,0,0,0}; 
        Scalar b = {0xfffffffefffffc2f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff}; 
        Scalar r;
        Scalar exp =  {1,0,0,0};
        secp256k1_sub_mod_p(a, b, r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_sub_mod_p_8(CuTest *tc){
        Scalar a = {1,0,0,0}; 
        Scalar b = {5,0,0,0}; 
        Scalar r;
        Scalar exp =  {0xfffffffefffffc2b,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        secp256k1_sub_mod_p(a, b, r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_negate_mod_p_1(CuTest *tc){
        Scalar a = {1,0,0,0}; 
        Scalar r;
        Scalar exp =  {0xfffffffefffffc2e,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        secp256k1_negate_mod_p(a,r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_negate_mod_p_2(CuTest *tc){
        Scalar a = {0x63b82f6f04ef2777,0x02e84bb7597aabe6,0xa25b0403f1eef757,0xb7c52588d95c3b9a};
        Scalar exp = {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465};
        Scalar r;
        secp256k1_negate_mod_p(a,r);
        scalarEq(exp, r, "r != exp");
}


void TestSecp256k1_negate_mod_p_3(CuTest *tc){
        Scalar exp = {0x63b82f6f04ef2777,0x02e84bb7597aabe6,0xa25b0403f1eef757,0xb7c52588d95c3b9a};
        Scalar a = {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465};
        Scalar r;
        secp256k1_negate_mod_p(a,r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_negate_mod_p_4(CuTest *tc){
        Scalar exp = {0x5445544454455075, 0x0101010101010101, 0x2152215221522152, 0x3501350135013501};
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar r;
        secp256k1_negate_mod_p(a,r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_negate_mod_p_5(CuTest *tc){
        Scalar a = {0x5445544454455075, 0x0101010101010101, 0x2152215221522152, 0x3501350135013501};
        Scalar exp = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar r;
        secp256k1_negate_mod_p(a,r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_negate_mod_p_6(CuTest *tc){
        Scalar a =   {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF};
		Scalar exp = {0xfffffffdfffff85f, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF};
        Scalar r;
        secp256k1_negate_mod_p(a,r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_negate_mod_p_7(CuTest *tc){
        Scalar a =   {0x1000003d0, 0, 0, 0};
		Scalar exp = {0xfffffffdfffff85f, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF};
        Scalar r;
        secp256k1_negate_mod_p(a,r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_negate_mod_p_8(CuTest *tc){
        Scalar exp =   {0x1000003d0, 0, 0, 0};
		Scalar a = {0xfffffffdfffff85f, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF};
        Scalar r;
        secp256k1_negate_mod_p(a,r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_negate_mod_p_asign_1(CuTest *tc){
        Scalar exp = {0x63b82f6f04ef2777,0x02e84bb7597aabe6,0xa25b0403f1eef757,0xb7c52588d95c3b9a};
        Scalar a = {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465};
        secp256k1_negate_mod_p_asign(a);
        scalarEq(exp, a, "a != exp");
}

void TestSecp256k1_negate_mod_p_asign_2(CuTest *tc){
        Scalar exp = {0x5445544454455075, 0x0101010101010101, 0x2152215221522152, 0x3501350135013501};
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        secp256k1_negate_mod_p_asign(a);
        scalarEq(exp, a, "a != exp");
}

void TestSecp256k1_sub_mod_p_9(CuTest *tc){
        Scalar a =  {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b =  {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar r;
        Scalar exp = {0,0,0,0}; 
        secp256k1_sub_mod_p(a, b, r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_sub_mod_p_10(CuTest *tc){
        Scalar a = {0xfffffffefffffc2f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff}; 
        Scalar b = {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff}; 
        Scalar r;
        Scalar exp =  {0xfffffffdfffff85f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        secp256k1_sub_mod_p(a, b, r);
        scalarEq(exp, r, "r != exp");

}

void TestSecp256k1_sub_mod_p_11(CuTest *tc){
        Scalar a =  {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =  {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};
        Scalar r;
        Scalar exp = {0x402da1732fc9bebe,0x4551231950b75fc4,1,0}; 
        secp256k1_sub_mod_p(a, b, r);
        scalarEq(exp, r, "r != exp");
}

void TestSecp256k1_square_mod_p_1(CuTest *tc){

        Scalar val = {0,0,0,0};
        Scalar exp = {0,0,0,0};  
        Scalar res;
        secp256k1_square_mod_p(val,res);
        scalarEq(exp, res, "square 0 = 0");
}

void TestSecp256k1_square_mod_p_2(CuTest *tc){

		
        Scalar val = {1,0,0,0};
        Scalar exp = {1,0,0,0};  
        Scalar res;

        secp256k1_square_mod_p(val,res);
        scalarEq(exp, res, "square 1 = 1");
}


void TestSecp256k1_square_mod_p_3(CuTest *tc){

		
        Scalar val = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar exp = {0x165483cc248f15f1, 0x5896ce5cc50e63aa, 0x0a0bef2c090f8a19, 0x480ac6ad64873e1c};  
        Scalar res;

        secp256k1_square_mod_p(val,res);
        scalarEq(exp, res, "exp != val");
}


void TestSecp256k1_square_mod_p_4(CuTest *tc){

		
        Scalar val = {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p
        Scalar exp = {0,0,0,0};  
        Scalar res;

        secp256k1_square_mod_p(val,res);
        scalarEq(exp, res, "square p = 0");
}

void TestSecp256k1_square_mod_p_5(CuTest *tc){

		
        Scalar val = {0xfffffffefffffc30, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p+1
        Scalar exp = {1,0,0,0};  
        Scalar res;

        secp256k1_square_mod_p(val,res);
        scalarEq(exp, res, "square p+1 = 1");
}

void TestSecp256k1_square_mod_p_6(CuTest *tc){

		
        Scalar val = {0xfffffffefffffc2e, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p-1
        Scalar exp = {1,0,0,0};  
        Scalar res;

        secp256k1_square_mod_p(val,res);
        scalarEq(exp, res, "square p-1 = 1");
}


void TestSecp256k1_square_mod_p_7(CuTest *tc){

		
        Scalar val = {0xfffffffefffffc2d, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p-2
        Scalar exp = {4,0,0,0};  
        Scalar res;

        secp256k1_square_mod_p(val,res);
        scalarEq(exp, res, "square p-2");
}


void TestSecp256k1_square_mod_p_8(CuTest *tc){

		
        Scalar val = {0x63b82f6f04ef2777,0x02e84bb7597aabe6,0xa25b0403f1eef757,0xb7c52588d95c3b9a};//Gy-
        Scalar exp = {0x44e4e9b8118c26f2,0xf16f80a548e5e20a,0x6bcc57ccd3735da5,0x4866d6a5ab41ab2c};  
        Scalar res;

        secp256k1_square_mod_p(val,res);
        scalarEq(exp, res, "square Gy-");
}


void TestSecp256k1_square_mod_p_9(CuTest *tc){

        Scalar val = {0x9c47d08ffb10d4b8,0xfd17b448a6855419,0x5da4fbfc0e1108a8,0x483ada7726a3c465};//Gy+
        Scalar exp = {0x44e4e9b8118c26f2,0xf16f80a548e5e20a,0x6bcc57ccd3735da5,0x4866d6a5ab41ab2c};  
        Scalar res;
        secp256k1_square_mod_p(val,res);
        scalarEq(exp, res, "square Gy+");
}

void TestSecp256k1_square_mod_p_10(CuTest *tc){

		
        Scalar val = {0,0,0,0};
        Scalar exp = {0,0,0,0};  
        Scalar res;

        secp256k1_square_mod_p(val,res);
        scalarEq(exp, res, "square 0");
}


void TestSecp256k1_square_mod_p_11(CuTest *tc){
        Scalar val = {0xf99999999999999f, 0xf99999999999999f, 0xf99999999999999f, 0xf99999999999999f};
        Scalar exp = {0xd547b5da1ef1188b,0x0851ebe2d5201e3c,0x2eb852209785e9b1,0x551eb85e59ebb526};
        Scalar res;
        secp256k1_square_mod_p(val,res);
        scalarEq(exp, res, "square f999...999f");
}

void TestSecp256k1_square_mod_p_asign_1(CuTest *tc){

		
        Scalar val = {0x63b82f6f04ef2777,0x02e84bb7597aabe6,0xa25b0403f1eef757,0xb7c52588d95c3b9a};//Gy-
        Scalar exp = {0x44e4e9b8118c26f2,0xf16f80a548e5e20a,0x6bcc57ccd3735da5,0x4866d6a5ab41ab2c};  
        secp256k1_square_mod_p_asign(val);
        scalarEq(exp, val, "square Gy-");
}


void TestSecp256k1_square_mod_p_asign_2(CuTest *tc){

        Scalar val = {0x9c47d08ffb10d4b8,0xfd17b448a6855419,0x5da4fbfc0e1108a8,0x483ada7726a3c465};//Gy+
        Scalar exp = {0x44e4e9b8118c26f2,0xf16f80a548e5e20a,0x6bcc57ccd3735da5,0x4866d6a5ab41ab2c};  
        secp256k1_square_mod_p_asign(val);
        scalarEq(exp, val, "square Gy+");
}

void Testsecp256k1_invert_mod_p_1(CuTest *tc){

        Scalar val = {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p
        Scalar exp = {0,0,0,0}; 
        Scalar inv; 
		secp256k1_invert_mod_p(val,inv);
        scalarEq(exp, inv, "inv p = 0");
}



void Testsecp256k1_invert_mod_p_2(CuTest *tc){

        Scalar val = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};//n
        Scalar exp = {0x2ac462030e4af361, 0xd715ad82d3d2a398, 0xb43e759e099ce8f6, 0x5a8423ffb26c8d73};  
       	Scalar inv;
		secp256k1_invert_mod_p(val,inv);
        scalarEq(exp, inv, "inv n");
}

void Testsecp256k1_invert_mod_p_3(CuTest *tc){

        Scalar val ={1,0,0,0};
        Scalar exp = {1,0,0,0};  
       	Scalar inv;
		secp256k1_invert_mod_p(val,inv);
        scalarEq(exp, inv, "inv 1");
}



void Testsecp256k1_invert_mod_p_4(CuTest *tc){

        Scalar val ={2,0,0,0};
        Scalar exp = {0xffffffff7ffffe18,0xffffffffffffffff,0xffffffffffffffff,0x7fffffffffffffff};  
       	Scalar inv;
		secp256k1_invert_mod_p(val,inv);
        scalarEq(exp, inv, "inv 2");
}


void Testsecp256k1_invert_mod_p_5(CuTest *tc){

        Scalar val ={4,0,0,0};
        Scalar exp = {0xFFFFFFFFBFFFFF0C, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0x3FFFFFFFFFFFFFFF};        
       	Scalar inv;
		secp256k1_invert_mod_p(val,inv);
        scalarEq(exp, inv, "val != inv 4");
}



void Testsecp256k1_invert_mod_p_6(CuTest *tc){

        Scalar val ={0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar exp = {0x48ca344950b1f7e3, 0xa8b3af9250bd1dc5, 0x56a7b0c57a72960e, 0x46e99613447130f9};  
       	Scalar inv;
		secp256k1_invert_mod_p(val,inv);
        scalarEq(exp, inv, "inv abba...");
}


void Testsecp256k1_invert_mod_p_7(CuTest *tc){

        Scalar val ={0x5a1f8ffde8773176,0x40c247f073ce1f4c,0xbc0e1455985c0c8e,0xf089eaef57aba315};
        Scalar exp = {0x74dca51d4f93cc4f,0xa8f0367bad4f8152,0x16f85029e14932a1,0x1a70ccd07fc49412};  
       	Scalar inv;
		secp256k1_invert_mod_p(val,inv);
        scalarEq(exp, inv, "val != exp");
}

void Testsecp256k1_invert_mod_p_8(CuTest *tc){

        Scalar val ={1234567890,0,0,0};
		Scalar exp = {0xE672184570C31C74, 0xEE90FBAACEF8CD18, 0x942211B9475F5D34, 0x2B0CAA92097F8DA5};
     	Scalar inv;
    	secp256k1_invert_mod_p(val,inv);
        scalarEq(exp, inv, "inv 1234567890");
}


void Testsecp256k1_invert_mod_p_asign_1(CuTest *tc){

        Scalar val = {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p
        Scalar exp = {0,0,0,0};  
		secp256k1_invert_mod_p_asign(val);
        scalarEq(exp, val, "inv p = 0");
}



void Testsecp256k1_invert_mod_p_asign_2(CuTest *tc){

        Scalar val = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};//n
        Scalar exp = {0x2ac462030e4af361, 0xd715ad82d3d2a398, 0xb43e759e099ce8f6, 0x5a8423ffb26c8d73};  
		secp256k1_invert_mod_p_asign(val);
        scalarEq(exp, val, "inv n");
}

void Testsecp256k1_invert_mod_p_asign_3(CuTest *tc){

        Scalar val ={1,0,0,0};
        Scalar exp = {1,0,0,0};  
		secp256k1_invert_mod_p_asign(val);
        scalarEq(exp, val, "inv 1");
}



void Testsecp256k1_invert_mod_p_asign_4(CuTest *tc){

        Scalar val ={2,0,0,0};
        Scalar exp = {0xffffffff7ffffe18,0xffffffffffffffff,0xffffffffffffffff,0x7fffffffffffffff};  
		secp256k1_invert_mod_p_asign(val);
        scalarEq(exp, val, "inv 2");
}


void Testsecp256k1_invert_mod_p_asign_5(CuTest *tc){

        Scalar val ={4,0,0,0};
        Scalar exp = {0xFFFFFFFFBFFFFF0C, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0x3FFFFFFFFFFFFFFF};        
		secp256k1_invert_mod_p_asign(val);
        scalarEq(exp, val, "val != inv 4");
}



void Testsecp256k1_invert_mod_p_asign_6(CuTest *tc){

        Scalar val ={0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar exp = {0x48ca344950b1f7e3, 0xa8b3af9250bd1dc5, 0x56a7b0c57a72960e, 0x46e99613447130f9};  
		secp256k1_invert_mod_p_asign(val);
        scalarEq(exp, val, "inv abba...");
}


void Testsecp256k1_invert_mod_p_asign_7(CuTest *tc){

        Scalar val ={0x5a1f8ffde8773176,0x40c247f073ce1f4c,0xbc0e1455985c0c8e,0xf089eaef57aba315};
        Scalar exp = {0x74dca51d4f93cc4f,0xa8f0367bad4f8152,0x16f85029e14932a1,0x1a70ccd07fc49412};  
		secp256k1_invert_mod_p_asign(val);
        scalarEq(exp, val, "val != exp");
}

void Testsecp256k1_invert_mod_p_asign_8(CuTest *tc){

        Scalar val ={1234567890,0,0,0};
		Scalar exp = {0xE672184570C31C74, 0xEE90FBAACEF8CD18, 0x942211B9475F5D34, 0x2B0CAA92097F8DA5};
     	Scalar inv;
    	secp256k1_invert_mod_p_asign(val);
        scalarEq(exp, val, "inv 1234567890");
}


void Testsecp256k1_exponentiate_mod_p1(CuTest *tc){
        Scalar a ={2,0,0,0};
        Scalar e = {0xfffffffefffffc2d, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p-2
        Scalar exp = {0xffffffff7ffffe18,0xffffffffffffffff,0xffffffffffffffff,0x7fffffffffffffff};  
        Scalar res;
        secp256k1_exponentiate_mod_p(a,e,res);
        scalarEq(exp, res, "exp != res");
}


void Testsecp256k1_exponentiate_mod_p2(CuTest *tc){
        Scalar a ={0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar e = {0xfffffffefffffc2d, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p-2
        Scalar exp = {0x48ca344950b1f7e3, 0xa8b3af9250bd1dc5, 0x56a7b0c57a72960e, 0x46e99613447130f9};  
        Scalar res;
        secp256k1_exponentiate_mod_p(a,e,res);
        scalarEq(exp, res, "exp != res");
}

void Testsecp256k1_exponentiate_mod_p3(CuTest *tc){
        Scalar a ={2,0,0,0};
        Scalar e = {0xfffffffefffffc2d, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p-2
        Scalar exp = {0xffffffff7ffffe18,0xffffffffffffffff,0xffffffffffffffff,0x7fffffffffffffff};  
        Scalar res;
        secp256k1_exponentiate_mod_p(a,e,res);
        scalarEq(exp, res, "exp != res");
}


void Testsecp256k1_exponentiate_mod_p4(CuTest *tc){
        Scalar a ={0x5a1f8ffde8773176,0x40c247f073ce1f4c,0xbc0e1455985c0c8e,0xf089eaef57aba315};
        Scalar e = {0xfffffffefffffc2d, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p-2
        Scalar exp = {0x74dca51d4f93cc4f,0xa8f0367bad4f8152,0x16f85029e14932a1,0x1a70ccd07fc49412};  
        Scalar res;
        secp256k1_exponentiate_mod_p(a,e,res);
        scalarEq(exp, res, "exp != res");
}


void Testsecp256k1_exponentiate_mod_p5(CuTest *tc){
        Scalar a ={0x5a1f8ffde8773176,0x40c247f073ce1f4c,0xbc0e1455985c0c8e,0xf089eaef57aba315};
        Scalar e = {3,0,0,0};
        Scalar exp = {0x59ae4742bd581e7f,0x4e2b1534a0782299,0xea0dee34354adc7d,0x6f032fba18b1cad5};  
        Scalar res;
        secp256k1_exponentiate_mod_p(a,e,res);
        scalarEq(exp, res, "exp != res");
}

void Testsecp256k1_exponentiate_mod_p6(CuTest *tc){
        Scalar e = {3,0,0,0};
        Scalar a ={0x74dca51d4f93cc4f,0xa8f0367bad4f8152,0x16f85029e14932a1,0x1a70ccd07fc49412};
        Scalar exp = {0xB5043452B8F1EAE8, 0x3E2D784C1CC19CBB, 0x916B6F17F63D8FF6, 0xC00C8F8FB555C39A};        
        Scalar res;
        secp256k1_exponentiate_mod_p(a,e,res);
        scalarEq(exp, res, "exp != res");
}

void Testsecp256k1_exponentiate_mod_p7(CuTest *tc){
        Scalar a =   {0x74dca51d4f93cc4f,0xa8f0367bad4f8152,0x16f85029e14932a1,0x1a70ccd07fc49412};
        Scalar e =   {0xB5043452B8F1EAE8, 0x3E2D784C1CC19CBB, 0x916B6F17F63D8FF6, 0xC00C8F8FB555C39A};
		Scalar exp = {0xC831614B17E37244, 0xE8A0CD98ECB496DF, 0x1AEA2DD56D9B77E5, 0x1717A1B6EBAE18CE};
        Scalar res;
        secp256k1_exponentiate_mod_p(a,e,res);
        scalarEq(exp, res, "exp != res");
}


void Testsecp256k1_cube_mod_p_1(CuTest *tc){
        Scalar a ={0x5a1f8ffde8773176,0x40c247f073ce1f4c,0xbc0e1455985c0c8e,0xf089eaef57aba315};
        Scalar exp = {0x59ae4742bd581e7f,0x4e2b1534a0782299,0xea0dee34354adc7d,0x6f032fba18b1cad5}; 
        Scalar res;
        secp256k1_cube_mod_p(a, res);
        scalarEq(exp, res, "exp != res");
}

void Testsecp256k1_cube_mod_p_2(CuTest *tc){
        Scalar a ={0x74dca51d4f93cc4f,0xa8f0367bad4f8152,0x16f85029e14932a1,0x1a70ccd07fc49412};
        Scalar exp = {0xB5043452B8F1EAE8, 0x3E2D784C1CC19CBB, 0x916B6F17F63D8FF6, 0xC00C8F8FB555C39A};
        Scalar res;
        secp256k1_cube_mod_p(a, res);
        scalarEq(exp, res, "exp != res");
}

void Testsecp256k1_cube_mod_p_asign_1(CuTest *tc){
        Scalar a ={0x5a1f8ffde8773176,0x40c247f073ce1f4c,0xbc0e1455985c0c8e,0xf089eaef57aba315};
        Scalar exp = {0x59ae4742bd581e7f,0x4e2b1534a0782299,0xea0dee34354adc7d,0x6f032fba18b1cad5}; 
        secp256k1_cube_mod_p_asign(a);
        scalarEq(exp, a, "a != exp");
}

void Testsecp256k1_cube_mod_p_asign_2(CuTest *tc){
        Scalar a ={0x74dca51d4f93cc4f,0xa8f0367bad4f8152,0x16f85029e14932a1,0x1a70ccd07fc49412};
        Scalar exp = {0xB5043452B8F1EAE8, 0x3E2D784C1CC19CBB, 0x916B6F17F63D8FF6, 0xC00C8F8FB555C39A};
        secp256k1_cube_mod_p_asign(a);
        scalarEq(exp, a, "a != exp");
}

void Testsecp256k1_squareroot_mod_p_1(CuTest *tc){

        Scalar a = {25,0,0,0};
        Scalar exp = {0xFFFFFFFEFFFFFC2A, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF};
        Scalar root;
        secp256k1_squareroot_mod_p(a,root);
        scalarEq(exp, root, "root != exp");
}

void Testsecp256k1_squareroot_mod_p_2(CuTest *tc){

        Scalar a = {36,0,0,0};
        Scalar exp = {0xFFFFFFFEFFFFFC29, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF};
        Scalar root;
		secp256k1_squareroot_mod_p(a,root);
        scalarEq(exp, root, "root != exp");
}


void Testsecp256k1_squareroot_mod_p_3(CuTest *tc){

        Scalar a = {64,0,0,0};
        Scalar exp = {8,0,0,0};
        Scalar root;
	    secp256k1_squareroot_mod_p(a,root);
        scalarEq(exp, root, "root != exp");
}

void Testsecp256k1_squareroot_mod_p_4(CuTest *tc){

        Scalar a = {9,0,0,0};
        Scalar exp = {0xFFFFFFFEFFFFFC2C, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF};
        Scalar root;
		secp256k1_squareroot_mod_p(a,root);
        scalarEq(exp, root, "root != exp");
}

void Testsecp256k1_squareroot_mod_p_5(CuTest *tc){

        Scalar a = {16,0,0,0};
        Scalar exp = {4,0,0,0};
        Scalar root;
		secp256k1_squareroot_mod_p(a,root);
        scalarEq(exp, root, "root != exp");
}

void Testsecp256k1_squareroot_mod_p_6(CuTest *tc){
        Scalar exp = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar a = {0x165483cc248f15f1, 0x5896ce5cc50e63aa, 0x0a0bef2c090f8a19, 0x480ac6ad64873e1c};  
        Scalar root;
		secp256k1_squareroot_mod_p(a,root);
        scalarEq(exp, root, "root != exp");
}

void Testsecp256k1_squareroot_mod_p_7(CuTest *tc){

        Scalar exp = {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465};
        Scalar a = {0x44e4e9b8118c26f2,0xf16f80a548e5e20a,0x6bcc57ccd3735da5,0x4866d6a5ab41ab2c};  
        Scalar root;
		secp256k1_squareroot_mod_p(a,root);
        scalarEq(exp, root, "root != exp");
}


void Testsecp256k1_squareroot_mod_p_asign_1(CuTest *tc){
        Scalar exp = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar a = {0x165483cc248f15f1, 0x5896ce5cc50e63aa, 0x0a0bef2c090f8a19, 0x480ac6ad64873e1c};  
		secp256k1_squareroot_mod_p_asign(a);
        scalarEq(exp, a, "root != exp");
}

void Testsecp256k1_squareroot_mod_p_asign_2(CuTest *tc){

        Scalar exp = {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465};
        Scalar a = {0x44e4e9b8118c26f2,0xf16f80a548e5e20a,0x6bcc57ccd3735da5,0x4866d6a5ab41ab2c};  
		secp256k1_squareroot_mod_p_asign(a);
        scalarEq(exp, a, "root != exp");
}


void Testsecp256k1_has_squareroot_mod_p_1(CuTest *tc){
        Scalar a = {16,0,0,0};
        int exp = 1;
        int res = secp256k1_has_squareroot_mod_p(a);
        CuAssertIntEquals_Msg(tc, "should have squareroot",exp,res);
}

void Testsecp256k1_has_squareroot_mod_p_2(CuTest *tc){

        Scalar a = {7,0,0,0};
        int exp = 0xFFFFFC2E;       
        int res =  secp256k1_has_squareroot_mod_p(a);
        CuAssertIntEquals_Msg(tc, "should not have squareroot",exp,res);
}

void Testsecp256k1_has_squareroot_mod_p_3(CuTest *tc){

        Scalar a = {64,0,0,0};
        int exp = 1;
        int res =  secp256k1_has_squareroot_mod_p(a);
        CuAssertIntEquals_Msg(tc, "should have squareroot",exp,res);
}

void Testsecp256k1_has_squareroot_mod_p_4(CuTest *tc){

        Scalar a = {66,0,0,0};
		int exp = 0xFFFFFC2E; 
        int res =  secp256k1_has_squareroot_mod_p(a);
        CuAssertIntEquals_Msg(tc, "should not have squareroot",exp,res);
}

void Testsecp256k1_has_squareroot_mod_p_5(CuTest *tc){

        Scalar a = {16,0,0,0};
        int exp = 1;
        int res = secp256k1_has_squareroot_mod_p(a);
        CuAssertIntEquals_Msg(tc, "should have squareroot",exp,res);
}

void Testsecp256k1_has_squareroot_mod_p_6(CuTest *tc){

        Scalar a = {7,0,0,0};
        int exp = 0xFFFFFC2E;         
        int res = secp256k1_has_squareroot_mod_p(a);
        CuAssertIntEquals_Msg(tc, "should not have squareroot",exp,res);
}

void Testsecp256k1_has_squareroot_mod_p_7(CuTest *tc){

        Scalar a = {64,0,0,0};
        int exp = 1;
        int res = secp256k1_has_squareroot_mod_p(a);
        CuAssertIntEquals_Msg(tc, "should have squareroot",exp,res);

}

void Testsecp256k1_has_squareroot_mod_p_8(CuTest *tc){

        Scalar a = {66,0,0,0};
        int exp = 0xFFFFFC2E;        
        int res = secp256k1_has_squareroot_mod_p(a);
        CuAssertIntEquals_Msg(tc, "should not have squareroot",exp,res);

}

void Testsecp256k1_has_squareroot_mod_p_9(CuTest *tc){

        Scalar a = {0x165483cc248f15f1, 0x5896ce5cc50e63aa, 0x0a0bef2c090f8a19, 0x480ac6ad64873e1c};  
        int exp = 1;
        int res = secp256k1_has_squareroot_mod_p(a);
        CuAssertIntEquals_Msg(tc, "should have squareroot",exp,res);

}


void TestSecp256k1_mul_mod_p_1(CuTest *tc){

        Scalar a = {0xFFFFFFFFBFFFFF0C, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0x3FFFFFFFFFFFFFFF};
        Scalar b =   {0xfffffffefffffc30, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar exp = {0xFFFFFFFFBFFFFF0C, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0x3FFFFFFFFFFFFFFF}; //the exponent for the squareroot-algorithm       
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        scalarEq(exp, r, "(p+1)*inv 4");
}

void TestSecp256k1_mul_mod_p_2(CuTest *tc){

        Scalar a =   {0xffffffffffffffff, 0, 0,0};
        Scalar b =   {0xffffffffffffffff,0,0,0};
        Scalar exp = {1, 0xfffffffffffffffe, 0, 0};  
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        scalarEq(exp, r, "ff * ff");
}

void TestSecp256k1_mul_mod_p_3(CuTest *tc){

        Scalar a =   {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =   {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar exp = {0x7a0000e8900, 1,0, 0};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        scalarEq(exp, r, "fff... * fff...");
}

void TestSecp256k1_mul_mod_p_4(CuTest *tc){

        Scalar a =   {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =   {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar exp = {0x2e6834736e1ef264, 0x2b2b2b2ad7e6d6aa, 0xd58ed58ef5dff65b, 0xb664b664ca13ca5e};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        scalarEq(exp, r, "fff... * a");
}


void TestSecp256k1_mul_mod_p_5(CuTest *tc){

        Scalar a =   {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =   {0xfffffffefffffc30, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar exp = {0,0,0,0};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        scalarEq(exp, r, "p * (p+1) = 0");
}



void TestSecp256k1_mul_mod_p_6(CuTest *tc){

        Scalar a =   {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =   {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar exp = {0,0,0,0};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        scalarEq(exp, r, "p * p = 0");
}


void TestSecp256k1_mul_mod_p_7(CuTest *tc){

        Scalar a =   {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =   {0xfffffffefffffc2e, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar exp = {0,0,0,0};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        scalarEq(exp, r, "p * (p-1) = 0");
}


void TestSecp256k1_mul_mod_p_8(CuTest *tc){

        Scalar a =   {0xfffffffefffffc2e, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =   {0xfffffffefffffc2e, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar exp = {1,0,0,0};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        scalarEq(exp, r, "(p-1) * (p-1) = 1");
}


void TestSecp256k1_mul_mod_p_9(CuTest *tc){

        Scalar a =   {0xfffffffefffffc30, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =   {0xfffffffefffffc30, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar exp = {1,0,0,0};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        scalarEq(exp, r, "(p+1) * (p+1) = 1");
}

void TestSecp256k1_mul_mod_p_10(CuTest *tc){

        Scalar a =   {0xfffffffefffffc30, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =   {0xfffffffefffffc2e, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar exp = {0xfffffffefffffc2e, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        scalarEq(exp, r, "(p+1) * (p-1)");
}

void TestSecp256k1_mul_mod_p_11(CuTest *tc){

        Scalar a =   {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b =   {0x48ca344950b1f7e3, 0xa8b3af9250bd1dc5, 0x56a7b0c57a72960e, 0x46e99613447130f9};
        Scalar exp = {1,0,0,0};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        scalarEq(exp, r, "a * inv a = 1");
}


void TestSecp256k1_mul_mod_p_12(CuTest *tc){

        Scalar a =   {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =   {0xfffffffefffffc30, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar exp = {0x1000003d0,0, 0,0};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        scalarEq(exp, r, "ffff... * p+1");
}

void TestSecp256k1_mul_mod_p_13(CuTest *tc){

        Scalar a =   {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =   {0xfffffffefffffc2e, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar exp = {0xfffffffdfffff85f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        scalarEq(exp, r, "ffff... * p-1");
}


void TestSecp256k1_mul_mod_p_14(CuTest *tc){

        Scalar a =   {0x5a1f8ffde8773176,0x40c247f073ce1f4c, 0xbc0e1455985c0c8e, 0xf089eaef57aba315};
        Scalar b =   {0x3d3cc4a3546ee4e8,0xc5a830101aabff78, 0xf1fe87385a4582e7, 0xf3b1b70975dec6dd};
        Scalar exp = {0x86dbc498f66ee080, 0x429dfabfe818bcf4, 0x2ed219af5c7bb005, 0x885da4eae93c3d69};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        scalarEq(exp, r, "a*b");
}

