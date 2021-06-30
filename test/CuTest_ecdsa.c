#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CuTest.h"
#include "../release/secp256k1.h"

#define scalarEq(exp, res, msg) CuAssertLongLongEquals_Msg(tc, msg, (exp)[0], (res)[0]);\
						   CuAssertLongLongEquals_Msg(tc, msg, (exp)[1], (res)[1]);\
						   CuAssertLongLongEquals_Msg(tc, msg, (exp)[2], (res)[2]);\
						   CuAssertLongLongEquals_Msg(tc, msg, (exp)[3], (res)[3])

void printScalar(char *msg, long long *s);

/**
Test cases for ECDSA signing and verification on the secp256k1 elliptic curve.
*/






//******************************************* Tests for signing **************************************************************************


void Test_secp256k1_sign_1(CuTest *tc){
                
        Scalar msg = {0x5218cb08e79cce78, 0x2bf92433d9919b9c,0xfb7152f85cee7eb5,0x0231c6f3d980a6b0};
        Scalar prk = {0xd212263a1d1e0f00, 0x38ff60eb3963b12c, 0x92ec9f589c303b10, 0x8b387de39861728c};
        KeyPair eph = {{1234567890,0,0,0},
        			   {{0x8B121697B782EF22, 0xE8838DD1FB752040, 0x7E63488AD48C23E8, 0x2B698A0F0A4041B7},
        			   {0x98D160C306A31BAC, 0x16AFE6AA152B87E3, 0x101C7E79B040E5CB, 0x2EE976351A7FE808}}
        			  };
        Signature sig;
        Scalar exp_r = {0x8B121697B782EF22, 0xE8838DD1FB752040, 0x7E63488AD48C23E8, 0x2B698A0F0A4041B7};
        Scalar exp_s = {0xD46F0A44D087B488, 0xD43B916C9F7B4789, 0xD1DA052CD7B994C9, 0x44EB19FD1061C078};
        secp256k1_sign(prk, &eph, msg, &sig);
        scalarEq(exp_r, sig.r, "r != exp.r");
        scalarEq(exp_s, sig.s, "s != exp.s");
}

void Test_secp256k1_sign_2(CuTest *tc){
                 
        Scalar  msg = {0x6e1936ae47060d48, 0x09c9f6aed9696501,0x795fd013fe88868d,0x969f6056aa26f7d2};
        KeyPair kp = {{12345,0,0,0},{
        {0x105CF385A023A80F, 0x65522BF85734008F, 0xD410404CB8690720, 0xF01D6B9018AB421D},
        {0x6DA4999CF3F6A295, 0xBEFCCD9F7FF01DD2, 0xD681984DC525982A, 0x0EBA29D0F0C5408E}
        }};
      
        
        KeyPair eph = {{1234567890,0,0,0},
        			   {{0x8B121697B782EF22, 0xE8838DD1FB752040, 0x7E63488AD48C23E8, 0x2B698A0F0A4041B7},
        			   {0x98D160C306A31BAC, 0x16AFE6AA152B87E3, 0x101C7E79B040E5CB, 0x2EE976351A7FE808}}
        			   };
        Signature sig;
        Scalar exp_r = {0x8B121697B782EF22, 0xE8838DD1FB752040, 0x7E63488AD48C23E8, 0x2B698A0F0A4041B7};
        Scalar exp_s = {0x6F316CFF2CB0BC1A, 0x7076D8B20990A0F2, 0x5E602A7B56416116, 0x1DBC63BFEF441670};
        secp256k1_sign(kp.private_key, &eph, msg, &sig);

        scalarEq(exp_r, sig.r, "r != exp.r");
        scalarEq(exp_s, sig.s, "s != exp.s");
}


void Test_secp256k1_sign_3(CuTest *tc){
        Scalar msg = {0x0471baa664531d1a,0x9c67ea1c3bf63f3e,0x41ddb16ff0a1842d,0x4b688df40bcedbe6};
        Scalar prk = {0x92de1a255cad3e0f,0xad8de9f5d7c90286,0x0a28ac82f6bdf97b,0xebb2c082fd772789};
        KeyPair eph = {0x42ecf322ba9ddd9a,0x06571c974b191efb,0x0d0721d72804befd,0x49a0d7b786ec9cde};
        secp256k1_keypair_from_private_key(&eph);
        
        Signature sig;
        Scalar exp_r = {0xf8b08505c9e2f795, 0x10efbb3b2676bbc0, 0x145c8961dbdf10c3, 0x241097efbf8b63bf};
        Scalar exp_s = {0xc7955dfb01f3ca0e, 0x661828131aef1ecb, 0x9e8b415a7f9acb1b, 0x021006b783860933};
        secp256k1_sign(prk, &eph, msg, &sig);
        scalarEq(exp_r, sig.r, "r != exp.r");
        scalarEq(exp_s, sig.s, "s != exp.s");
}

//******************************************* Tests for verification **************************************************************************


void Test_secp256k1_verify_1(CuTest *tc){
 
        Point puk = {{0x1795FFB3BE2F6C52, 0xDDF3B42740DF0D21, 0x11983F3E97C3FA0A, 0x028D003EAB2E428D},
        	         {0xB547526D8CD309E2, 0x6FB218D9E7594F02, 0xC78CB2A937ED8909, 0x0AE987B9EC6EA159}};
        Scalar msg = {0x5218cb08e79cce78, 0x2bf92433d9919b9c,0xfb7152f85cee7eb5,0x0231c6f3d980a6b0};
        Signature sig = {{0x8B121697B782EF22, 0xE8838DD1FB752040, 0x7E63488AD48C23E8, 0x2B698A0F0A4041B7},
        				 {0xeb635447ffae8cb9, 0xe6734b7a0fcd58b1, 0x2e25fad328466b34, 0xbb14e602ef9e3f87}};
        int exp = 0;
        int res = secp256k1_verify(&puk, msg, &sig);
        CuAssertIntEquals_Msg(tc, "verification should succeed",exp,res);
}

void Test_secp256k1_verify_1b(CuTest *tc){
        Point puk = {{0x1795FFB3BE2F6C52, 0xDDF3B42740DF0D21, 0x11983F3E97C3FA0A, 0x028D003EAB2E428D},
        	         {0xB547526D8CD309E2, 0x6FB218D9E7594F02, 0xC78CB2A937ED8909, 0x0AE987B9EC6EA159}};
        Scalar msg = {0x5218cb08e79cce78, 0x2bf92433d9919b9c,0xfb7152f85cee7eb5,0x0231c6f3d980a6b0};
        Signature sig = {{0x8B121697B782EF22, 0xE8838DD1FB752040, 0x7E63488AD48C23E8, 0x2B698A0F0A4041B7},
        				 {0xeb635447ffae8cb9, 0xe6734b7a0fcd58b1, 0x2e25fad328466b34, 0xbb14e602ef9e3f87}};
        Scalar inv_s;				 
        secp256k1_invert_mod_n(sig.s, inv_s);
  
        Scalar u;
        secp256k1_mul_mod_n(msg, inv_s,	u);
        
        Scalar v;
        secp256k1_mul_mod_n(sig.r, inv_s,	v);	 
        
        Point uG;
        secp256k1_generator_mul(u, &uG);
        
        Point vP;
        secp256k1_point_mul(&puk, v, &vP);
        
        Point W;
        secp256k1_add_different_points(&uG, &vP, &W);
        
        secp256k1_reduce_mod_n(W.x);
        
        Scalar diff;
        secp256k1_sub_mod_n(W.x, sig.r, diff);
        
        int res = secp256k1_is_zero(diff);
        int exp = 0;

        CuAssertIntEquals_Msg(tc, "verification should succeed",exp,res);
}

void Test_secp256k1_verify_2(CuTest *tc){
        Scalar  msg = {0x6e1936ae47060d48, 0x09c9f6aed9696501,0x795fd013fe88868d,0x969f6056aa26f7d2};
        KeyPair kp = {{0,0,0,0},{
        {0x105CF385A023A80F, 0x65522BF85734008F, 0xD410404CB8690720, 0xF01D6B9018AB421D},
        {0x6DA4999CF3F6A295, 0xBEFCCD9F7FF01DD2, 0xD681984DC525982A, 0x0EBA29D0F0C5408E}
        }};
        Signature sig = {{0x8B121697B782EF22, 0xE8838DD1FB752040, 0x7E63488AD48C23E8, 0x2B698A0F0A4041B7},
                         {0x6f316cff2cb0bc1a, 0x7076d8b20990a0f2, 0x5e602a7b56416116, 0x1dbc63bfef441670}};
        int exp = 0;
        int res = secp256k1_verify(&kp.public_key, msg, &sig);
        CuAssertIntEquals_Msg(tc, "verification should succeed",exp,res);
}

void Test_secp256k1_verify_2b(CuTest *tc){
        Point puk = {{0x105CF385A023A80F, 0x65522BF85734008F, 0xD410404CB8690720, 0xF01D6B9018AB421D},
        			 {0x6DA4999CF3F6A295, 0xBEFCCD9F7FF01DD2, 0xD681984DC525982A, 0x0EBA29D0F0C5408E}};
        Scalar  msg = {0x6e1936ae47060d48, 0x09c9f6aed9696501,0x795fd013fe88868d,0x969f6056aa26f7d2};
        Signature sig = {{0x8B121697B782EF22, 0xE8838DD1FB752040, 0x7E63488AD48C23E8, 0x2B698A0F0A4041B7},
                         {0x6f316cff2cb0bc1a, 0x7076d8b20990a0f2, 0x5e602a7b56416116, 0x1dbc63bfef441670}};
        Scalar inv_s;				 
        secp256k1_invert_mod_n(sig.s, inv_s);
  
        Scalar u;
        secp256k1_mul_mod_n(msg, inv_s,	u);
        
        Scalar v;
        secp256k1_mul_mod_n(sig.r, inv_s,	v);	 
        
        Point uG;
        secp256k1_generator_mul(u, &uG);
        
        Point vP;
        secp256k1_point_mul(&puk, v, &vP);
        
        Point W;
        secp256k1_add_different_points(&uG, &vP, &W);
        
        secp256k1_reduce_mod_n(W.x);
        
        Scalar diff;
        secp256k1_sub_mod_n(W.x, sig.r, diff);
        
        int res = secp256k1_is_zero(diff);
        int exp = 0;

        CuAssertIntEquals_Msg(tc, "verification should succeed",exp,res);
}

void Test_secp256k1_verify_3(CuTest *tc){
        Point puk = {{0x37A427BD5847DFCD, 0x28B790DC6B3B7D44, 0xD2CF6CB31D82D433, 0x779DD197A5DF977E},
        		     {0x75C9237B917D426F, 0xF5B1699D6EF41249, 0x7BB7607C3E3281DA, 0xE94B724A555B6D01}};
        Scalar msg = {0x0471baa664531d1a,0x9c67ea1c3bf63f3e,0x41ddb16ff0a1842d,0x4b688df40bcedbe6};
        Signature sig = {{0xf8b08505c9e2f795, 0x10efbb3b2676bbc0, 0x145c8961dbdf10c3, 0x241097efbf8b63bf},
        				 {0xc7955dfb01f3ca0e, 0x661828131aef1ecb, 0x9e8b415a7f9acb1b, 0x021006b783860933}};
        int exp = 0;
        int res = secp256k1_verify(&puk, msg, &sig);

        CuAssertIntEquals_Msg(tc, "verification should succeed",exp,res);
}

void Test_secp256k1_verify_3b(CuTest *tc){
        Point puk = {{0x37A427BD5847DFCD, 0x28B790DC6B3B7D44, 0xD2CF6CB31D82D433, 0x779DD197A5DF977E},
        		     {0x75C9237B917D426F, 0xF5B1699D6EF41249, 0x7BB7607C3E3281DA, 0xE94B724A555B6D01}};
        Scalar msg = {0x0471baa664531d1a,0x9c67ea1c3bf63f3e,0x41ddb16ff0a1842d,0x4b688df40bcedbe6};
        Signature sig = {{0xf8b08505c9e2f795, 0x10efbb3b2676bbc0, 0x145c8961dbdf10c3, 0x241097efbf8b63bf},
        				 {0xc7955dfb01f3ca0e, 0x661828131aef1ecb, 0x9e8b415a7f9acb1b, 0x021006b783860933}};
        Scalar inv_s;				 
        secp256k1_invert_mod_n(sig.s, inv_s);

        
        Scalar u;
        secp256k1_mul_mod_n(msg, inv_s,	u);

              
        Scalar v;
        secp256k1_mul_mod_n(sig.r, inv_s,	v);	 
                
        Point uG;
        secp256k1_generator_mul(u, &uG);
   
        Point vP;
        secp256k1_point_mul(&puk, v, &vP);
 
        Point W;
        secp256k1_add_different_points(&uG, &vP, &W);

      
        secp256k1_reduce_mod_n(W.x);
       
        Scalar diff;
        secp256k1_sub_mod_n(W.x, sig.r, diff);

        int res = secp256k1_is_zero(diff);
        int exp = 0;

        CuAssertIntEquals_Msg(tc, "verification should succeed",exp,res);
}



void Test_secp256k1_verify_4(CuTest *tc){
//Example from Jimmy Songs 'Programming Bitcoin', Exercise 6
		char p[] = "04887387e452b8eacc4acfde10d9aaf7f6d9a0f975aabb10d006e4da568744d06c61de6d95231cd89026e286df3b6ae4a894a3378e393e93a0f45b666329a0ae34";
    	Point puk;
    	secp256k1_parse_point(p, &puk);
    
    	char m[] = "ec208baa0fc1c19f708a9ca96fdeff3ac3f230bb4a7ba4aede4942ad003c0f60";
        Scalar msg;
        secp256k1_parse_scalar(m, msg);
        
        char r[] = "ac8d1c87e51d0d441be8b3dd5b05c8795b48875dffe00b7ffcfac23010d3a395";
        char s[] = "068342ceff8935ededd102dd876ffd6ba72d6a427a3edb13d26eb0781cb423c4";
        Signature sig;
        secp256k1_parse_scalar(r, sig.r);
        secp256k1_parse_scalar(s, sig.s);
        
        int exp = 0;
        int res = secp256k1_verify(&puk, msg, &sig);

        CuAssertIntEquals_Msg(tc, "verification should succeed",exp,res);
}

void Test_secp256k1_verify_4b(CuTest *tc){
//Example from Jimmy Songs 'Programming Bitcoin', Exercise 6
		char p[] = "04887387e452b8eacc4acfde10d9aaf7f6d9a0f975aabb10d006e4da568744d06c61de6d95231cd89026e286df3b6ae4a894a3378e393e93a0f45b666329a0ae34";
    	Point puk;
    	secp256k1_parse_point(p, &puk);
    
    	char m[] = "ec208baa0fc1c19f708a9ca96fdeff3ac3f230bb4a7ba4aede4942ad003c0f61";//ends with 1 instead of 0
        Scalar msg;
        secp256k1_parse_scalar(m, msg);
        
        char r[] = "ac8d1c87e51d0d441be8b3dd5b05c8795b48875dffe00b7ffcfac23010d3a395";
        char s[] = "068342ceff8935ededd102dd876ffd6ba72d6a427a3edb13d26eb0781cb423c4";
        Signature sig;
        secp256k1_parse_scalar(r, sig.r);
        secp256k1_parse_scalar(s, sig.s);
        
        int exp = 1;
        int res = secp256k1_verify(&puk, msg, &sig);

        CuAssertIntEquals_Msg(tc, "verification should succeed",exp,res);
}

void Test_secp256k1_verify_5(CuTest *tc){
//Example from Jimmy Songs 'Programming Bitcoin', Exercise 6
		char p[] = "04887387e452b8eacc4acfde10d9aaf7f6d9a0f975aabb10d006e4da568744d06c61de6d95231cd89026e286df3b6ae4a894a3378e393e93a0f45b666329a0ae34";
    	Point puk;
    	secp256k1_parse_point(p, &puk);
    
    	char m[] = "7c076ff316692a3d7eb3c3bb0f8b1488cf72e1afcd929e29307032997a838a3d";
        Scalar msg;
        secp256k1_parse_scalar(m, msg);
        
        char r[] = "00eff69ef2b1bd93a66ed5219add4fb51e11a840f404876325a1e8ffe0529a2c";
        char s[] = "c7207fee197d27c618aea621406f6bf5ef6fca38681d82b2f06fddbdce6feab6";
        Signature sig;
        secp256k1_parse_scalar(r, sig.r);
        secp256k1_parse_scalar(s, sig.s);
        
        int exp = 0;
        int res = secp256k1_verify(&puk, msg, &sig);

        CuAssertIntEquals_Msg(tc, "verification should succeed",exp,res);
}

void Test_secp256k1_verify_5b(CuTest *tc){
//Example from Jimmy Songs 'Programming Bitcoin', Exercise 6
		char p[] = "04887387e452b8eacc4acfde10d9aaf7f6d9a0f975aabb10d006e4da568744d06c61de6d95231cd89026e286df3b6ae4a894a3378e393e93a0f45b666329a0ae34";
    	Point puk;
    	secp256k1_parse_point(p, &puk);
    
    	char m[] = "7c076ff316692a3d7eb3c3bb0f8b1488cf72e1afcd929e29307032997a838a3e";//ends with e instead of d
        Scalar msg;
        secp256k1_parse_scalar(m, msg);
        
        char r[] = "00eff69ef2b1bd93a66ed5219add4fb51e11a840f404876325a1e8ffe0529a2c";
        char s[] = "c7207fee197d27c618aea621406f6bf5ef6fca38681d82b2f06fddbdce6feab6";
        Signature sig;
        secp256k1_parse_scalar(r, sig.r);
        secp256k1_parse_scalar(s, sig.s);
        
        int exp = 1;
        int res = secp256k1_verify(&puk, msg, &sig);

        CuAssertIntEquals_Msg(tc, "verification should succeed",exp,res);
}




void Test_secp256k1_sign_and_verify_1(CuTest *tc){
		//Signing
        Scalar msg = {0x5218cb08e79cce78, 0x2bf92433d9919b9c,0xfb7152f85cee7eb5,0x0231c6f3d980a6b0};
        KeyPair signer = {{0xd212263a1d1e0f00, 0x38ff60eb3963b12c, 0x92ec9f589c303b10, 0x8b387de39861728c}, 
                          {{0x1795FFB3BE2F6C52, 0xDDF3B42740DF0D21, 0x11983F3E97C3FA0A, 0x028D003EAB2E428D},
                           {0xB547526D8CD309E2, 0x6FB218D9E7594F02, 0xC78CB2A937ED8909, 0x0AE987B9EC6EA159}}
                         };
        
        KeyPair eph = {{1234567890,0,0,0},
        			   {{0x8B121697B782EF22, 0xE8838DD1FB752040, 0x7E63488AD48C23E8, 0x2B698A0F0A4041B7},
        			    {0x98D160C306A31BAC, 0x16AFE6AA152B87E3, 0x101C7E79B040E5CB, 0x2EE976351A7FE808}}
        			  };
        Signature sig;
        Scalar exp_r = {0x8B121697B782EF22, 0xE8838DD1FB752040, 0x7E63488AD48C23E8, 0x2B698A0F0A4041B7};
        Scalar exp_s = {0xD46F0A44D087B488, 0xD43B916C9F7B4789, 0xD1DA052CD7B994C9, 0x44EB19FD1061C078};
        secp256k1_sign(signer.private_key, &eph, msg, &sig);
        scalarEq(exp_r, sig.r, "r != exp.r");
        scalarEq(exp_s, sig.s, "s != exp.s");
        
        //Verifying
        int result = secp256k1_verify(&signer.public_key, msg, &sig);
        int exp = 0;
        CuAssertIntEquals_Msg(tc, "verification should succeed",exp,result);        

}

void Test_secp256k1_sign_and_verify_2(CuTest *tc){
        Scalar  msg = {0x6e1936ae47060d48, 0x09c9f6aed9696501,0x795fd013fe88868d,0x969f6056aa26f7d2};
        KeyPair signer = {{12345,0,0,0},{
        {0x105CF385A023A80F, 0x65522BF85734008F, 0xD410404CB8690720, 0xF01D6B9018AB421D},
        {0x6DA4999CF3F6A295, 0xBEFCCD9F7FF01DD2, 0xD681984DC525982A, 0x0EBA29D0F0C5408E}
        }};
      
        
        KeyPair eph = {{1234567890,0,0,0},
        			   {{0x8B121697B782EF22, 0xE8838DD1FB752040, 0x7E63488AD48C23E8, 0x2B698A0F0A4041B7},
        			   {0x98D160C306A31BAC, 0x16AFE6AA152B87E3, 0x101C7E79B040E5CB, 0x2EE976351A7FE808}}
        			   };
        Signature sig;
        Scalar exp_r = {0x8B121697B782EF22, 0xE8838DD1FB752040, 0x7E63488AD48C23E8, 0x2B698A0F0A4041B7};
        Scalar exp_s = {0x6F316CFF2CB0BC1A, 0x7076D8B20990A0F2, 0x5E602A7B56416116, 0x1DBC63BFEF441670};
        secp256k1_sign(signer.private_key, &eph, msg, &sig);
        scalarEq(exp_r, sig.r, "r != exp.r");
        scalarEq(exp_s, sig.s, "s != exp.s");
        
        //Verifying
        int result = secp256k1_verify(&signer.public_key, msg, &sig);
        int exp = 0;
        CuAssertIntEquals_Msg(tc, "verification should succeed",exp,result); 

}






//***************************** tests for normalization signature s **************************************

void secp256k1_normalize_s(Scalar s);

void Testsecp256k1_normalize_s_1(CuTest *tc){
     Scalar s =     {0xdfe92f46681b20a0, 0x5d576e7357a4501d, 0xffffffffffffffff, 0x7fffffffffffffff}; //s = n/2
     Scalar exp_s = {0xdfe92f46681b20a0, 0x5d576e7357a4501d, 0xffffffffffffffff, 0x7fffffffffffffff}; //s = n/2
     secp256k1_normalize_s(s);
     scalarEq(exp_s, s, "exp.s != s");
}

void Testsecp256k1_normalize_s_2(CuTest *tc){
     Scalar s = {0xdfe92f46681b20a1, 0x5d576e7357a4501d, 0xffffffffffffffff, 0x7fffffffffffffff}; //s = n/2 + 1
     Scalar exp_s =  {0xdfe92f46681b20a0, 0x5d576e7357a4501d, 0xffffffffffffffff, 0x7fffffffffffffff};// s = n - (n/2+1)
     secp256k1_normalize_s(s);
     scalarEq(exp_s, s, "exp.s != s");
}

void Testsecp256k1_normalize_s_3(CuTest *tc){
     Scalar s = {0xdfe92f46681b209f, 0x5d576e7357a4501d, 0xffffffffffffffff, 0x7fffffffffffffff}; //s = n/2 - 1
     Scalar exp_s = {0xdfe92f46681b209f, 0x5d576e7357a4501d, 0xffffffffffffffff, 0x7fffffffffffffff}; //s = n/2 -1
     secp256k1_normalize_s(s);
     scalarEq(exp_s, s, "exp.s != s");
}

void Testsecp256k1_normalize_s_4(CuTest *tc){
     Scalar s =  {0xBFD25E8CD0364140, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF}; //n-1
     Scalar exp_s = {1, 0, 0, 0}; //s = n - (n -1) = 1
     secp256k1_normalize_s(s);
     scalarEq(exp_s, s, "exp.s != s");
}


void Testsecp256k1_normalize_s_5(CuTest *tc){
     Scalar s =     {0xD46F0A44D087B488, 0xD43B916C9F7B4789, 0xD1DA052CD7B994C9, 0x44EB19FD1061C078}; //<n/2
     Scalar exp_s = {0xD46F0A44D087B488, 0xD43B916C9F7B4789, 0xD1DA052CD7B994C9, 0x44EB19FD1061C078};
     secp256k1_normalize_s(s);
     scalarEq(exp_s, s, "exp.s != s");

}

void Testsecp256k1_normalize_s_6(CuTest *tc){
     Scalar s =     {0, 0, 0, 0xF000000000000000}; //>n/2

     Scalar exp_s = {0xbfd25e8cd0364141, 0xbaaedce6af48a03b, 0xfffffffffffffffe, 0x0fffffffffffffff};
     secp256k1_normalize_s(s);
     scalarEq(exp_s, s, "exp.s != s");
    
}






















































