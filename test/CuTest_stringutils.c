#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CuTest.h"
#include "../release/secp256k1.h"

#define scalarEq(exp, res, msg) CuAssertLongLongEquals_Msg(tc, msg, (exp)[0], (res)[0]);\
						   CuAssertLongLongEquals_Msg(tc, msg, (exp)[1], (res)[1]);\
						   CuAssertLongLongEquals_Msg(tc, msg, (exp)[2], (res)[2]);\
						   CuAssertLongLongEquals_Msg(tc, msg, (exp)[3], (res)[3])



//************************Tests for parsing scalars and points from strings********************************************************************************************

void TestSecp256k1_parse_point_1(CuTest *tc){

	char inp[] = "0474F1CE3C6EF778D672808056EE1E53F497D573E36ED4385F52B465135504E4FFA416475ADA0FD2563AA92456DCA573E07A8A2D551742BF50D127A2980B361248";
	Point exp = {{0x52B465135504E4FF, 0x97D573E36ED4385F, 0x72808056EE1E53F4, 0x74F1CE3C6EF778D6}, 
					{0xD127A2980B361248, 0x7A8A2D551742BF50, 0x3AA92456DCA573E0, 0xA416475ADA0FD256}};
    Point res;
    secp256k1_parse_point(inp, &res);
    scalarEq(exp.x, res.x, "exp.x != res.x");
    scalarEq(exp.y, res.y, "exp.y != res.y"); 
}

void TestSecp256k1_parse_point_2(CuTest *tc){

	char inp[] = "044F83A657A0CED2B1A02640EB88CB0CFD1DFA93A9285B2F4F002B28F4BF8944779E1C64324941D002FB5C05A28B88B0743E7BE1AB6AF1D6CACCAA9B5070C81633";
	Point exp = {{0x002B28F4BF894477, 0x1DFA93A9285B2F4F, 0xA02640EB88CB0CFD, 0x4F83A657A0CED2B1}, 
					{0xCCAA9B5070C81633, 0x3E7BE1AB6AF1D6CA, 0xFB5C05A28B88B074, 0x9E1C64324941D002}};
    Point res;
    secp256k1_parse_point(inp, &res);
    scalarEq(exp.x, res.x, "exp.x != res.x");
    scalarEq(exp.y, res.y, "exp.y != res.y");     
}
 
void TestSecp256k1_parse_point_3(CuTest *tc){

    
	char inp[] = "0274F1CE3C6EF778D672808056EE1E53F497D573E36ED4385F52B465135504E4FF";
	Point exp = {{0x52B465135504E4FF, 0x97D573E36ED4385F, 0x72808056EE1E53F4, 0x74F1CE3C6EF778D6}, 
					{0xD127A2980B361248, 0x7A8A2D551742BF50, 0x3AA92456DCA573E0, 0xA416475ADA0FD256}};
    Point res;
    secp256k1_parse_point(inp, &res);
    scalarEq(exp.x, res.x, "exp.x != res.x");
    scalarEq(exp.y, res.y, "exp.y != res.y"); 
}

void TestSecp256k1_parse_point_4(CuTest *tc){

    
    	char inp[] = "034F83A657A0CED2B1A02640EB88CB0CFD1DFA93A9285B2F4F002B28F4BF894477";
	Point exp = {{0x002B28F4BF894477, 0x1DFA93A9285B2F4F, 0xA02640EB88CB0CFD, 0x4F83A657A0CED2B1}, 
					{0xCCAA9B5070C81633, 0x3E7BE1AB6AF1D6CA, 0xFB5C05A28B88B074, 0x9E1C64324941D002}};
    Point res;
    secp256k1_parse_point(inp, &res);
    scalarEq(exp.x, res.x, "exp.x != res.x");
    scalarEq(exp.y, res.y, "exp.y != res.y");     
}

void TestSecp256k1_parse_point_5(CuTest *tc){

	char inp[] =     "0279BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798";
	Point exp = {{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC}, 
					{0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}};//Generator
    Point res;
    secp256k1_parse_point(inp, &res);
    scalarEq(exp.x, res.x, "exp.x != res.x");
    scalarEq(exp.y, res.y, "exp.y != res.y");     
}

void TestSecp256k1_parse_point_6(CuTest *tc){

	char inp[] =     "03D0E1494EE3B53B5C3463617DDD99C589B0F1560794B9D8FB94083A4167A396AA";
	                  //  0xD0E1494EE3B53B5C 0x3463617DDD99C589 0xB0F1560794B9D8FB 0x94083A4167A396AA
	                  //  0x1D085BB398547817 0x67B9BE0A3C9B46DD 0x4FF88CFD0E4DE55A 0x73FDC7871F71213D";
	Point exp = {{0x94083A4167A396AA,0xB0F1560794B9D8FB,0x3463617DDD99C589,0xD0E1494EE3B53B5C}, 
					{0x73FDC7871F71213D,0x4FF88CFD0E4DE55A,0x67B9BE0A3C9B46DD,0x1D085BB398547817}};
    Point res;
    secp256k1_parse_point(inp, &res);
    scalarEq(exp.x, res.x, "exp.x != res.x");
    scalarEq(exp.y, res.y, "exp.y != res.y");     
}

void TestSecp256k1_parse_point_7(CuTest *tc){

	char inp[] =     "04D0E1494EE3B53B5C3463617DDD99C589B0F1560794B9D8FB94083A4167A396AA1D085BB39854781767B9BE0A3C9B46DD4FF88CFD0E4DE55A73FDC7871F71213D";
	Point exp = {{0x94083A4167A396AA,0xB0F1560794B9D8FB,0x3463617DDD99C589,0xD0E1494EE3B53B5C}, 
					{0x73FDC7871F71213D,0x4FF88CFD0E4DE55A,0x67B9BE0A3C9B46DD,0x1D085BB398547817}};
    Point res;
    secp256k1_parse_point(inp, &res);
    scalarEq(exp.x, res.x, "exp.x != res.x");
    scalarEq(exp.y, res.y, "exp.y != res.y");     
} 

//04E0013E9240345F3B6D1381061FB6E3EEFAA2F4EE3ECD36EE40E1A99D5F6B4351 
 //  0x3C77676F28D9128D 0x268505B5B5C08E74 0x17D22360A93237D4 0xC2E9CE8472F3E72A

void TestSecp256k1_parse_point_8(CuTest *tc){

	char inp[] =     "04E0013E9240345F3B6D1381061FB6E3EEFAA2F4EE3ECD36EE40E1A99D5F6B43513C77676F28D9128D268505B5B5C08E7417D22360A93237D4C2E9CE8472F3E72A";
	Point exp = {{0x40E1A99D5F6B4351,0xFAA2F4EE3ECD36EE,0x6D1381061FB6E3EE,0xE0013E9240345F3B}, 
					{0xC2E9CE8472F3E72A,0x17D22360A93237D4,0x268505B5B5C08E74,0x3C77676F28D9128D}};
    Point res;
    secp256k1_parse_point(inp, &res);
    scalarEq(exp.x, res.x, "exp.x != res.x");
    scalarEq(exp.y, res.y, "exp.y != res.y");     
}

void TestSecp256k1_parse_point_9(CuTest *tc){

	char inp[] =     "02E0013E9240345F3B6D1381061FB6E3EEFAA2F4EE3ECD36EE40E1A99D5F6B4351";
	Point exp = {{0x40E1A99D5F6B4351,0xFAA2F4EE3ECD36EE,0x6D1381061FB6E3EE,0xE0013E9240345F3B}, 
					{0xC2E9CE8472F3E72A,0x17D22360A93237D4,0x268505B5B5C08E74,0x3C77676F28D9128D}};
    Point res;
    secp256k1_parse_point(inp, &res);
    scalarEq(exp.x, res.x, "exp.x != res.x");
    scalarEq(exp.y, res.y, "exp.y != res.y");     
}


void TestSecp256k1_parse_point_10(CuTest *tc){

	char inp[] =     "04AB5118410D6F90CD184972CFC940E85CADD730781636FCF01450B4A66F3011156BDE88A239EC2C1457145D1D88418513F51F75B79975C4239B722639A5FFC0A2";
	Point exp = {{0x1450B4A66F301115,0xADD730781636FCF0,0x184972CFC940E85C,0xAB5118410D6F90CD}, 
					{0x9B722639A5FFC0A2,0xF51F75B79975C423,0x57145D1D88418513,0x6BDE88A239EC2C14}};
    Point res;
    secp256k1_parse_point(inp, &res);
    scalarEq(exp.x, res.x, "exp.x != res.x");
    scalarEq(exp.y, res.y, "exp.y != res.y");     
}

void TestSecp256k1_parse_point_11(CuTest *tc){

	char inp[] =     "02AB5118410D6F90CD184972CFC940E85CADD730781636FCF01450B4A66F301115";
	Point exp = {{0x1450B4A66F301115,0xADD730781636FCF0,0x184972CFC940E85C,0xAB5118410D6F90CD}, 
					{0x9B722639A5FFC0A2,0xF51F75B79975C423,0x57145D1D88418513,0x6BDE88A239EC2C14}};
    Point res;
    secp256k1_parse_point(inp, &res);
    scalarEq(exp.x, res.x, "exp.x != res.x");
    scalarEq(exp.y, res.y, "exp.y != res.y");     
}


void TestSecp256k1_parse_point_12(CuTest *tc){

	char inp[] =     "04FC55EF482F9CD58292046433B8A1FFEED18889E6393195051052926A5778A309C16684DB73FCF87B1B3FA5218B0E58A3126A2C11305F3E7DA082F10231F68BE7";
	Point exp = {{0x1052926A5778A309,0xD18889E639319505,0x92046433B8A1FFEE,0xFC55EF482F9CD582}, 
					{0xA082F10231F68BE7,0x126A2C11305F3E7D,0x1B3FA5218B0E58A3,0xC16684DB73FCF87B}};
    Point res;
    secp256k1_parse_point(inp, &res);
    scalarEq(exp.x, res.x, "exp.x != res.x");
    scalarEq(exp.y, res.y, "exp.y != res.y");     
}

void TestSecp256k1_parse_point_13(CuTest *tc){

	char inp[] =     "03FC55EF482F9CD58292046433B8A1FFEED18889E6393195051052926A5778A309";
	Point exp = {{0x1052926A5778A309,0xD18889E639319505,0x92046433B8A1FFEE,0xFC55EF482F9CD582}, 
					{0xA082F10231F68BE7,0x126A2C11305F3E7D,0x1B3FA5218B0E58A3,0xC16684DB73FCF87B}};
    Point res;
    secp256k1_parse_point(inp, &res);
    scalarEq(exp.x, res.x, "exp.x != res.x");
    scalarEq(exp.y, res.y, "exp.y != res.y");     
}

void Testsecp256k1_parse_scalar_1(CuTest *tc){

		char inp[] = "cafecafecafecafedeaddeaddeaddeadfefefefefefefefeabbaabbaabbaabba";
        Scalar val;
        Scalar exp = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};  
        secp256k1_parse_scalar(inp, val);
        scalarEq(exp, val, "exp != val");
}


void Testsecp256k1_parse_scalar_2(CuTest *tc){

		char inp[] = "B68B69A717D220F744B9CC0DD5B7530A92880838C85D6AC0A6F0146894AE298F";
        Scalar val;
        Scalar exp = {0xA6F0146894AE298F, 0x92880838C85D6AC0, 0x44B9CC0DD5B7530A, 0xB68B69A717D220F7};
        secp256k1_parse_scalar(inp, val);
        scalarEq(exp, val, "exp != val");
}

void Testsecp256k1_parse_scalar_3(CuTest *tc){

		char inp[] = "b68b69a717D220f744b9cC0DD5B7530a92880838c85d6AC0a6F0146894Ae298f";
        Scalar val;
        Scalar exp = {0xA6F0146894AE298F, 0x92880838C85D6AC0, 0x44B9CC0DD5B7530A, 0xB68B69A717D220F7};
        secp256k1_parse_scalar(inp, val);
        scalarEq(exp, val, "exp != val");
}

void Testsecp256k1_parse_scalar_4(CuTest *tc){

		char inp[] = "B68B69A717D220F744B9CC0DD5B7530A92880838C85D6AC0A6F0146894AE298F\0\0";
        Scalar val;
        Scalar exp = {0xA6F0146894AE298F, 0x92880838C85D6AC0, 0x44B9CC0DD5B7530A, 0xB68B69A717D220F7};
        secp256k1_parse_scalar(inp, val);
        scalarEq(exp, val, "exp != val");
}

void Testsecp256k1_parse_u64_1(CuTest *tc){

		char inp[] = "Fedcba9876543210";
		unsigned long long exp = 0xfedcba9876543210;
		unsigned long long val = secp256k1_parse_u64(inp);
		CuAssertLongLongEquals_Msg(tc, "exp != val", (exp), (val));
}

void Testsecp256k1_parse_u64_2(CuTest *tc){

		char inp[] = "f000000000000001";
		unsigned long long exp = 0xf000000000000001;
		unsigned long long val = secp256k1_parse_u64(inp);
		CuAssertLongLongEquals_Msg(tc, "exp != val", (exp), (val));
}

void Testsecp256k1_parse_u64_3(CuTest *tc){

		char inp[] = "Ab7aB0efDe3dCa1e";
		unsigned long long exp = 0xab7ab0efde3dca1e;
		unsigned long long val = secp256k1_parse_u64(inp);
		CuAssertLongLongEquals_Msg(tc, "exp != val", (exp), (val));
}


//***************************Tests for converting a Scalar into an ASCII string*****************************+

void Test_secp256k1_scalar_to_string_1(CuTest *tc){
        Scalar s = {0x5218cb08e79cce78, 0x2bf92433d9919b9c,0xfb7152f85cee7eb5,0x0231c6f3d980a6b0};
        char exp_str[] = "0231c6f3d980a6b0fb7152f85cee7eb52bf92433d9919b9c5218cb08e79cce78\0";
        char str[65] = {0};
        secp256k1_scalar_to_string(s, str);
        CuAssertStrEquals_Msg(tc, "str != exp_str", exp_str, str);
}


void Test_secp256k1_scalar_to_string_2(CuTest *tc){
        Scalar s = {0xabba1970dead1982, 0xbabecafe13001224,0xfefe0830deadbeef,0xbaba1920dead2001};
        char exp_str[] = "baba1920dead2001fefe0830deadbeefbabecafe13001224abba1970dead1982\0";
        char str[65] = {0};
        secp256k1_scalar_to_string(s, str);
        CuAssertStrEquals_Msg(tc, "str != exp_str", exp_str, str);
}


//***************************Tests for helper functions************************************
void Test_secp256k1_u32_to_string_1(CuTest *tc){

        int val = 0x87654321;
        char str[] = "00000000";
        char exp_str[] = "87654321";
        secp256k1_u32_to_string(val, str);
        CuAssertStrEquals_Msg(tc, "str != exp_str", exp_str, str);
}

void Test_secp256k1_u32_to_string_1a(CuTest *tc){

        int val = 0x87654321;
        char str[9];
        str[8] = 0;
        char exp_str[] = "87654321";
        secp256k1_u32_to_string(val, str);
        CuAssertStrEquals_Msg(tc, "str != exp_str", exp_str, str);
}

void Test_secp256k1_u32_to_string_2(CuTest *tc){

        int val = 0xfedcba98;
        char str[] = "00000000\0";
        char exp_str[] = "fedcba98\0";
        secp256k1_u32_to_string(val, str);
        CuAssertStrEquals_Msg(tc, "str != exp_str", exp_str, str);
}

void Test_secp256k1_u32_to_string_2a(CuTest *tc){

        int val = 0xfedcba98;
        char str[9] = {0};
        char exp_str[] = "fedcba98\0";
        secp256k1_u32_to_string(val, str);
        CuAssertStrEquals_Msg(tc, "str != exp_str", exp_str, str);
}


void Test_secp256k1_u32_to_string_3(CuTest *tc){

        int val = 0x41424344;
        char str[] = "00000000";
        char exp_str[] = "41424344\0";
        secp256k1_u32_to_string(val, str);
        CuAssertStrEquals_Msg(tc, "str != exp_str", exp_str, str);
}

void Test_secp256k1_u64_to_string_1(CuTest *tc){

        long long val = 0xfedcba9876543210;
        char str[] = "0000000000000000\0";
        char exp_str[] = "fedcba9876543210\0";
        secp256k1_u64_to_string(val, str);
        CuAssertStrEquals_Msg(tc, "str != exp_str", exp_str, str);
}

void Test_secp256k1_u64_to_string_2(CuTest *tc){

        long long val = 0xabbadeadbabecafe;
        char str[17] = {0};
        char exp_str[] = "abbadeadbabecafe\0";
        secp256k1_u64_to_string(val, str);
        CuAssertStrEquals_Msg(tc, "str != exp_str", exp_str, str);
}











