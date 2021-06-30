#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CuTest.h"
#include "../release/secp256k1.h"
#include "../src/u256.h"

#define scalarEq(exp, res, msg) CuAssertLongLongEquals_Msg(tc, msg, (exp)[0], (res)[0]);\
						   CuAssertLongLongEquals_Msg(tc, msg, (exp)[1], (res)[1]);\
						   CuAssertLongLongEquals_Msg(tc, msg, (exp)[2], (res)[2]);\
						   CuAssertLongLongEquals_Msg(tc, msg, (exp)[3], (res)[3])


void printScalar(char *msg, long long *s);

/**
Test cases for u256-big integer multiplication and squareing
*/


/******* 512-bit big integer multiplication  ****************/
void Test_mul512_1(CuTest *tc){
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar hi;
        Scalar lo;    
        Scalar exp_hi = {0xd4de74191353b28d,0x15d61c2f228828e0,0xc9108f16551c1b22,0xa0c12a0db35a3ca6};
        Scalar exp_lo = {0xfad61c1b3d605ea6,0x87e5cfc817aa5f8c,0x953b1b53a16c2784,0x3991556b71458d1f};
        mul512(a,b,lo, hi);
        scalarEq(exp_lo, lo, "lo != expected lo");
        scalarEq(exp_hi, hi, "hi != expected hi");
}

void Test_mul512_2(CuTest *tc){
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0x31f7c7475c96f1e5,0x06b37149dbe04676,0x9418638e3304027a,0xa0f715f18aebffe6};
        Scalar exp_lo = {0x6626efd0797a0324,0xe9e32d067029b34d,0xa5f3fb01500ea51b,0x6e2407f3a1c33b92};
        mul512(a,b,lo, hi);
        scalarEq(exp_lo, lo, "lo != expected lo");
        scalarEq(exp_hi, hi, "hi != expected hi");
}

void Test_mul512_3(CuTest *tc){
        Scalar a = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar b = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0x60cb2addf4f0bf02,0xfbfbe2dac9b9b098,0x465be564846d2375,0xa08b5039ffe8af97};
        Scalar exp_lo = {0x37bc0632d4a9a321,0xadf604905b2ab1c5,0x7528cfaf2a3584bb,0x638de44d650ce5cc};
        mul512(a,b,lo, hi);
        scalarEq(exp_lo, lo, "lo != expected lo");
        scalarEq(exp_hi, hi, "hi != expected hi");
}

void Test_mul512_4(CuTest *tc){
        Scalar a = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar b = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0xbeefbeefbeefbeee,0xdeafdeafdeafdeaf,0xbaffbaffbaffbaff,0xcabacabacabacaba};
        Scalar exp_lo = {0x4110411041104111,0x2150215021502150,0x4500450045004500,0x3545354535453545};
        mul512(a,b,lo, hi);
        scalarEq(exp_lo, lo, "lo != expected lo");
        scalarEq(exp_hi, hi, "hi != expected hi");
}

void Test_mul512_5(CuTest *tc){
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0xabbaabbaabbaabb9,0xfefefefefefefefe,0xdeaddeaddeaddead,0xcafecafecafecafe};
        Scalar exp_lo = {0x5445544554455446,0x0101010101010101,0x2152215221522152,0x3501350135013501};
        mul512(a,b,lo, hi);
        scalarEq(exp_lo, lo, "lo != expected lo");
        scalarEq(exp_hi, hi, "hi != expected hi");
}

void Test_mul512_6(CuTest *tc){
        Scalar a = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0xfffffffffffffffe,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff};
        Scalar exp_lo = {1,0,0,0};
        mul512(a,b,lo, hi);
        scalarEq(exp_lo, lo, "lo != expected lo");
        scalarEq(exp_hi, hi, "hi != expected hi");
}

void Test_mul512_7(CuTest *tc){
        Scalar a = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar b = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0x60cb2addf4f0bf02,0xfbfbe2dac9b9b098,0x465be564846d2375,0xa08b5039ffe8af97};
        Scalar exp_lo = {0x37bc0632d4a9a321,0xadf604905b2ab1c5,0x7528cfaf2a3584bb,0x638de44d650ce5cc};
        mul512(a,b,lo, hi);
        scalarEq(exp_lo, lo, "lo != expected lo");
        scalarEq(exp_hi, hi, "hi != expected hi");
}

/*********512-bit big integer squareing **************************************/
void Test_square512_1(CuTest *tc){
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0x31f7c7475c96f1e5,0x06b37149dbe04676,0x9418638e3304027a,0xa0f715f18aebffe6};
        Scalar exp_lo = {0x6626efd0797a0324,0xe9e32d067029b34d,0xa5f3fb01500ea51b,0x6e2407f3a1c33b92};
        square512(a,lo, hi);
        scalarEq(exp_lo, lo, "lo != expected lo");
        scalarEq(exp_hi, hi, "hi != expected hi");
}

void Test_square512_2(CuTest *tc){
        Scalar a = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0x60cb2addf4f0bf02,0xfbfbe2dac9b9b098,0x465be564846d2375,0xa08b5039ffe8af97};
        Scalar exp_lo = {0x37bc0632d4a9a321,0xadf604905b2ab1c5,0x7528cfaf2a3584bb,0x638de44d650ce5cc};
        square512(a,lo, hi);
        scalarEq(exp_lo, lo, "lo != expected lo");
        scalarEq(exp_hi, hi, "hi != expected hi");
}

void Test_square512_3(CuTest *tc){
        Scalar a = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0xfffffffffffffffe,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff};
        Scalar exp_lo = {1,0,0,0};
        square512(a,lo, hi);
        scalarEq(exp_lo, lo, "lo != expected lo");
        scalarEq(exp_hi, hi, "hi != expected hi");
}

void Test_square512_4(CuTest *tc){
        Scalar a = {0xf99999999999999f, 0xf99999999999999f, 0xf99999999999999f, 0xf99999999999999f};
        Scalar hi;
        Scalar lo; 
        Scalar exp_hi = {0x45c28f5c28f5c313,0xd4f5c28f5c28f620,0x6428f5c28f5c292a,0xf35c28f5c28f5c35};
        Scalar exp_lo = {0x7d70a3d70a3d70c1,0xee3d70a3d70a3db5,0x5f0a3d70a3d70aaa,0xcfd70a3d70a3d7a0};
        square512(a,lo, hi);
        scalarEq(exp_lo, lo, "lo != expected lo");
        scalarEq(exp_hi, hi, "hi != expected hi");
}



void Test_square512_5(CuTest *tc){
        Scalar a = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0x60cb2addf4f0bf02,0xfbfbe2dac9b9b098,0x465be564846d2375,0xa08b5039ffe8af97};
        Scalar exp_lo = {0x37bc0632d4a9a321,0xadf604905b2ab1c5,0x7528cfaf2a3584bb,0x638de44d650ce5cc};
        square512(a,lo, hi);
        scalarEq(exp_lo, lo, "lo != expected lo");
        scalarEq(exp_hi, hi, "hi != expected hi");
}

void Test_square512_6(CuTest *tc){
        Scalar a = {0, 0, 0, 0};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0,0,0,0};
        Scalar exp_lo = {0,0,0,0};
        square512(a,lo, hi);
        scalarEq(exp_lo, lo, "lo != expected lo");
        scalarEq(exp_hi, hi, "hi != expected hi");
}

void Test_square512_7(CuTest *tc){
        Scalar a = {4, 3, 2, 1};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0xa,4,1,0};
        Scalar exp_lo = {0x10,0x18,0x19,0x14};
        square512(a,lo, hi);
        scalarEq(exp_lo, lo, "lo != expected lo");
        scalarEq(exp_hi, hi, "hi != expected hi");
}

