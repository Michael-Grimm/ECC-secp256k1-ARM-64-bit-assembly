#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "secp256k1.h"
#include "u256.h"

/**
 * Unit tests 
 */


/**
 * Prints all functions starting with 'void test' of the importing file. 
 * Can be used to update a function that calls all the test cases.
 */
#define PRINT_TEST_FUNCTIONS  \
     char command[] = "cat " __FILE__ " | grep '^void test' | sed -e 's/void//' -e 's/{/;/'"; \
     FILE *f = popen(command, "w"); \
     pclose(f); 

/**
 * Tests two strings for equality.
 */
#define TEST_STRING_EQUALS(expected, actual) \
	if(strcmp(expected, actual) != 0){ \
		printf("%s, line %d: Expected %s, but was %s\n", __FUNCTION__, __LINE__, expected, actual); \
		failed_tests += 1; \
	}else{ \
		passed_tests += 1; \
	}

/**
 * Tests two integers for equality.
 */
#define TEST_INT_EQUALS(expected, actual) \
	if(expected != actual){ \
		printf("%s, line %d: Expected %d, but was %d\n", __FUNCTION__, __LINE__, expected, actual); \
		failed_tests += 1; \
	}else{ \
		passed_tests += 1; \
	}

/**
 * Tests two long long integers for equality.
 */
#define TEST_LONGLONG_EQUALS(expected, actual) \
	if(expected != actual){ \
		printf("%s, line %d: Expected 0x%llx, but was 0x%llx\n", __FUNCTION__, __LINE__, expected, actual); \
		failed_tests += 1; \
	}else{ \
		passed_tests += 1; \
	}
	
/**
 *  Tests two Scalars for equality
 */	
#define TEST_SCALAR_EQUALS(expected, actual) \
	if(expected[0] != actual[0]){ \
		printf("%s, line %d, Scalar[0]: Expected 0x%llx, but was 0x%llx\n", __FUNCTION__, __LINE__, expected[0], actual[0]); \
		failed_tests += 1; \
	} \
	if(expected[1] != actual[1]){ \
		printf("%s, line %d, Scalar[1]: Expected 0x%llx, but was 0x%llx\n", __FUNCTION__, __LINE__, expected[1], actual[1]); \
		failed_tests += 1; \
	} \
	if(expected[2] != actual[2]){ \
		printf("%s, line %d, Scalar[2]: Expected 0x%llx, but was 0x%llx\n", __FUNCTION__, __LINE__, expected[2], actual[2]); \
		failed_tests += 1; \
	} \
	if(expected[3] != actual[3]){ \
		printf("%s, line %d, Scalar[3]: Expected 0x%llx, but was 0x%llx\n", __FUNCTION__, __LINE__, expected[3], actual[3]); \
		failed_tests += 1; \
	} \
		passed_tests += 1; 	
	

/**
 * Last command in the function that calls the test functions.
 * Prints the results.
 */
#define PRINT_TEST_RESULTS \
	printf("\nResults of testing %s: \nPassed tests: %lld\nFailed tests: %lld\n", __FILE__, passed_tests, failed_tests); \
    passed_tests = 0; \
    failed_tests = 0;
    

long long int passed_tests = 0; 
long long int failed_tests = 0;




 

/**
  Tests for functions mod p
*/

void test_secp256k1_add_mod_p_1(){
		
        Scalar a =   {0x5a1f8ffde8773176,0x40c247f073ce1f4c, 0xbc0e1455985c0c8e, 0xf089eaef57aba315};
        Scalar b =   {0x3d3cc4a3546ee4e8,0xc5a830101aabff78, 0xf1fe87385a4582e7, 0xf3b1b70975dec6dd};
        Scalar r;
        Scalar exp = {0x975c54a23ce61a2f,0x066a78008e7a1ec4, 0xae0c9b8df2a18f76, 0xe43ba1f8cd8a69f3};
        secp256k1_add_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_add_mod_p_2(){
		
        Scalar a={0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b={0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;
        Scalar exp = {0x2000007a0,0,0,0};
        secp256k1_add_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp, r)

}


void test_secp256k1_add_mod_p_3(){
		
        Scalar a = {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;
        Scalar exp = {0x1000003d0,0,0,0};
        secp256k1_add_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp, r)

}

void test_secp256k1_add_mod_p_4(){
		
        Scalar a = {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b = {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;
        Scalar exp = {0,0,0,0};
        secp256k1_add_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp, r)

}


void test_secp256k1_add_mod_p_5(){
		
        Scalar a = {0,0,0,0};
        Scalar b = {0,0,0,0};
        Scalar r;
        Scalar exp = {0,0,0,0};
        secp256k1_add_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp, r)

}


void test_secp256k1_add_mod_p_6(){
		
        Scalar a ={1,0,0,0};
        Scalar b ={0xfffffffefffffc30, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;
        Scalar exp = {2,0, 0, 0};
        secp256k1_add_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp, r)

}

void test_secp256k1_add_mod_p_7(){
		
        Scalar a = {1,0,0,0};
        Scalar b = {0xfffffffefffffc2e,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;
        Scalar exp = {0,0,0,0};
        secp256k1_add_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp, r)

}


void test_secp256k1_add_mod_p_8(){
		
        Scalar a = {0xfffffffefffffc2e,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b = {0xfffffffefffffc2e,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;
        Scalar exp = {0xfffffffefffffc2d,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff}; 
        secp256k1_add_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_add_mod_p_9(){
		
        Scalar a = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};
        Scalar b = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};
        Scalar r;
        Scalar exp = {0x7fa4bd1aa06c8653,0x755db9cd5e914077, 0xfffffffffffffffd, 0xffffffffffffffff};
        secp256k1_add_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp, r)

}


void test_secp256k1_add_mod_p_10(){
		
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};
        Scalar r;
        Scalar exp = {0x6b8d0a487bf0f0cc, 0xb9addbe5ae479f3a, 0xdeaddeaddeaddeac, 0xcafecafecafecafe};
        secp256k1_add_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp, r)


}

void test_secp256k1_add_mod_p_11(){
		
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar r;
        Scalar exp = {0x5775577657755b45, 0xfdfdfdfdfdfdfdfd, 0xbd5bbd5bbd5bbd5b, 0x95fd95fd95fd95fd};
        secp256k1_add_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp, r)

}

void test_secp256k1_double_mod_p_1(){
		
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar r;
        Scalar exp = {0x5775577657755b45, 0xfdfdfdfdfdfdfdfd, 0xbd5bbd5bbd5bbd5b, 0x95fd95fd95fd95fd};
        secp256k1_double_mod_p(a, r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_double_mod_p_2(){
		
        Scalar a = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};
        Scalar r;
       
        Scalar exp = {0x7fa4bd1aa06c8653,0x755db9cd5e914077, 0xfffffffffffffffd, 0xffffffffffffffff};
        secp256k1_double_mod_p(a, r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_double_mod_p_3(){
		
        Scalar a = {0xfffffffefffffc2e,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;
        Scalar exp = {0xfffffffefffffc2d,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};        
        secp256k1_double_mod_p(a, r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_double_mod_p_4(){
		
        Scalar a = {0,0,0,0};
        Scalar r;
        Scalar exp = {0,0,0,0};      
        secp256k1_double_mod_p(a, r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_double_mod_p_5(){
		
        Scalar a={0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;
        Scalar exp = {0x2000007a0,0,0,0};   
        secp256k1_double_mod_p(a, r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_double_mod_p_6(){
		
        Scalar a = {1,2,3,4};
        Scalar r;
        Scalar exp = {2,4,6,8};      
        secp256k1_double_mod_p(a, r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_triple_mod_p_1(){
		
        Scalar a = {0,0,0,0};
        Scalar r;
        Scalar exp = {0,0,0,0};      
        secp256k1_triple_mod_p(a, r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_triple_mod_p_2(){
		
        Scalar a = {0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff};
        Scalar r;
        Scalar exp = {0x300000b70,0,0,0};      
        secp256k1_triple_mod_p(a, r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_triple_mod_p_3(){
		
        Scalar a = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};
        Scalar r;      
        Scalar exp = {0x3f771ba870a2cb65, 0x300c96b40dd9e0b3, 0xfffffffffffffffc, 0xffffffffffffffff};     
        secp256k1_triple_mod_p(a, r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_triple_mod_p_4(){
		
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar r;   
        Scalar exp = {0x0330033203300ad0,0xfcfcfcfcfcfcfcfc,0x9c099c099c099c09,0x60fc60fc60fc60fc};      
        secp256k1_triple_mod_p(a, r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_triple_mod_p_5(){
		
        Scalar a = {1,2,3,4};
        Scalar r;
        Scalar exp = {3,6,9,12};      
        secp256k1_triple_mod_p(a, r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_triple_mod_p_6(){
		
        Scalar a = {0xfffffffefffffc2f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;
        Scalar exp = {0,0,0,0};      
        secp256k1_triple_mod_p(a, r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_triple_mod_p_7(){
		
        Scalar a = {0xfffffffefffffc30,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;
        Scalar exp = {3,0,0,0};      
        secp256k1_triple_mod_p(a, r);
        TEST_SCALAR_EQUALS(exp, r)
}


void test_secp256k1_triple_mod_p_8(){
		
        Scalar a = {0,0,0,0};
        Scalar r;
        Scalar exp = {0,0,0,0};      
        secp256k1_triple_mod_p(a, r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_sub_mod_p_1(){
        Scalar a =  {0x5a1f8ffde8773176,0x40c247f073ce1f4c, 0xbc0e1455985c0c8e, 0xf089eaef57aba315}; 
        Scalar b =  {0x3d3cc4a3546ee4e8,0xc5a830101aabff78, 0xf1fe87385a4582e7, 0xf3b1b70975dec6dd};
        Scalar r;
        Scalar exp =  {0x1ce2cb59940848bd,0x7b1a17e059221fd4, 0xca0f8d1d3e1689a6, 0xfcd833e5e1ccdc37};
        secp256k1_sub_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp, r)

}

void test_secp256k1_sub_mod_p_2(){
        Scalar a = {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff}; 
        Scalar b = {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff}; 
        Scalar r;
        Scalar exp = {0,0,0,0}; 
        secp256k1_sub_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp, r)

}

void test_secp256k1_sub_mod_p_3(){
        Scalar a = {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff}; 
        Scalar b =  {0xfffffffefffffc2f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff}; 
        Scalar r;
        Scalar exp = {0x1000003d0,0,0,0}; 
        secp256k1_sub_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp, r)

}


void test_secp256k1_sub_mod_p_4(){
        Scalar a =  {0xfffffffefffffc2f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =  {0xfffffffefffffc2f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;
        Scalar exp = {0,0,0,0}; 
        secp256k1_sub_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_sub_mod_p_5(){
        Scalar a =  {0,0,0,0};
        Scalar b =  {0,0,0,0};
        Scalar r;
        Scalar exp = {0,0,0,0}; 
        secp256k1_sub_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp, r)

}

void test_secp256k1_sub_mod_p_6(){
        Scalar a =  {0xfffffffefffffc2f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =  {1,0,0,0};
        Scalar r;
        Scalar exp = {0xfffffffefffffc2e,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff}; 
        secp256k1_sub_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp, r)

}

void test_secp256k1_sub_mod_p_7(){
        Scalar a = {1,0,0,0}; 
        Scalar b = {0xfffffffefffffc2f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff}; 
        Scalar r;
        Scalar exp =  {1,0,0,0};
        secp256k1_sub_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_sub_mod_p_8(){
        Scalar a = {1,0,0,0}; 
        Scalar b = {5,0,0,0}; 
        Scalar r;
        Scalar exp =  {0xfffffffefffffc2b,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        secp256k1_sub_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_negate_mod_p_1(){
        Scalar a = {1,0,0,0}; 
        Scalar r;
        Scalar exp =  {0xfffffffefffffc2e,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        secp256k1_negate_mod_p(a,r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_negate_mod_p_2(){
        Scalar a = {0x63b82f6f04ef2777,0x02e84bb7597aabe6,0xa25b0403f1eef757,0xb7c52588d95c3b9a};
        Scalar exp = {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465};
        Scalar r;
        secp256k1_negate_mod_p(a,r);
        TEST_SCALAR_EQUALS(exp, r)
}


void test_secp256k1_negate_mod_p_3(){
        Scalar exp = {0x63b82f6f04ef2777,0x02e84bb7597aabe6,0xa25b0403f1eef757,0xb7c52588d95c3b9a};
        Scalar a = {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465};
        Scalar r;
        secp256k1_negate_mod_p(a,r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_negate_mod_p_4(){
        Scalar exp = {0x5445544454455075, 0x0101010101010101, 0x2152215221522152, 0x3501350135013501};
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar r;
        secp256k1_negate_mod_p(a,r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_negate_mod_p_5(){
        Scalar a = {0x5445544454455075, 0x0101010101010101, 0x2152215221522152, 0x3501350135013501};
        Scalar exp = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar r;
        secp256k1_negate_mod_p(a,r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_negate_mod_p_6(){
        Scalar a =   {0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF};
		Scalar exp = {0xfffffffdfffff85f, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF};
        Scalar r;
        secp256k1_negate_mod_p(a,r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_negate_mod_p_7(){
        Scalar a =   {0x1000003d0, 0, 0, 0};
		Scalar exp = {0xfffffffdfffff85f, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF};
        Scalar r;
        secp256k1_negate_mod_p(a,r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_negate_mod_p_8(){
        Scalar exp =   {0x1000003d0, 0, 0, 0};
		Scalar a = {0xfffffffdfffff85f, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF};
        Scalar r;
        secp256k1_negate_mod_p(a,r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_negate_mod_p_asign_1(){
        Scalar exp = {0x63b82f6f04ef2777,0x02e84bb7597aabe6,0xa25b0403f1eef757,0xb7c52588d95c3b9a};
        Scalar a = {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465};
        secp256k1_negate_mod_p_asign(a);
        TEST_SCALAR_EQUALS(exp, a)
}

void test_secp256k1_negate_mod_p_asign_2(){
        Scalar exp = {0x5445544454455075, 0x0101010101010101, 0x2152215221522152, 0x3501350135013501};
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        secp256k1_negate_mod_p_asign(a);
        TEST_SCALAR_EQUALS(exp, a)
}

void test_secp256k1_sub_mod_p_9(){
        Scalar a =  {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b =  {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar r;
        Scalar exp = {0,0,0,0}; 
        secp256k1_sub_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_sub_mod_p_10(){
        Scalar a = {0xfffffffefffffc2f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff}; 
        Scalar b = {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff}; 
        Scalar r;
        Scalar exp =  {0xfffffffdfffff85f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        secp256k1_sub_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp, r)

}

void test_secp256k1_sub_mod_p_11(){
        Scalar a =  {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =  {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};
        Scalar r;
        Scalar exp = {0x402da1732fc9bebe,0x4551231950b75fc4,1,0}; 
        secp256k1_sub_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp, r)
}

void test_secp256k1_square_mod_p_1(){

        Scalar val = {0,0,0,0};
        Scalar exp = {0,0,0,0};  
        Scalar res;
        secp256k1_square_mod_p(val,res);
        TEST_SCALAR_EQUALS(exp, res)
}

void test_secp256k1_square_mod_p_2(){

		
        Scalar val = {1,0,0,0};
        Scalar exp = {1,0,0,0};  
        Scalar res;

        secp256k1_square_mod_p(val,res);
        TEST_SCALAR_EQUALS(exp, res)
}


void test_secp256k1_square_mod_p_3(){

		
        Scalar val = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar exp = {0x165483cc248f15f1, 0x5896ce5cc50e63aa, 0x0a0bef2c090f8a19, 0x480ac6ad64873e1c};  
        Scalar res;

        secp256k1_square_mod_p(val,res);
        TEST_SCALAR_EQUALS(exp, res)
}


void test_secp256k1_square_mod_p_4(){

		
        Scalar val = {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p
        Scalar exp = {0,0,0,0};  
        Scalar res;

        secp256k1_square_mod_p(val,res);
        TEST_SCALAR_EQUALS(exp, res)
}

void test_secp256k1_square_mod_p_5(){

		
        Scalar val = {0xfffffffefffffc30, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p+1
        Scalar exp = {1,0,0,0};  
        Scalar res;

        secp256k1_square_mod_p(val,res);
        TEST_SCALAR_EQUALS(exp, res)
}

void test_secp256k1_square_mod_p_6(){

		
        Scalar val = {0xfffffffefffffc2e, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p-1
        Scalar exp = {1,0,0,0};  
        Scalar res;

        secp256k1_square_mod_p(val,res);
        TEST_SCALAR_EQUALS(exp, res)
}


void test_secp256k1_square_mod_p_7(){

		
        Scalar val = {0xfffffffefffffc2d, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p-2
        Scalar exp = {4,0,0,0};  
        Scalar res;

        secp256k1_square_mod_p(val,res);
        TEST_SCALAR_EQUALS(exp, res)
}


void test_secp256k1_square_mod_p_8(){

		
        Scalar val = {0x63b82f6f04ef2777,0x02e84bb7597aabe6,0xa25b0403f1eef757,0xb7c52588d95c3b9a};//Gy-
        Scalar exp = {0x44e4e9b8118c26f2,0xf16f80a548e5e20a,0x6bcc57ccd3735da5,0x4866d6a5ab41ab2c};  
        Scalar res;

        secp256k1_square_mod_p(val,res);
        TEST_SCALAR_EQUALS(exp, res)
}


void test_secp256k1_square_mod_p_9(){

        Scalar val = {0x9c47d08ffb10d4b8,0xfd17b448a6855419,0x5da4fbfc0e1108a8,0x483ada7726a3c465};//Gy+
        Scalar exp = {0x44e4e9b8118c26f2,0xf16f80a548e5e20a,0x6bcc57ccd3735da5,0x4866d6a5ab41ab2c};  
        Scalar res;
        secp256k1_square_mod_p(val,res);
        TEST_SCALAR_EQUALS(exp, res)
}

void test_secp256k1_square_mod_p_10(){

		
        Scalar val = {0,0,0,0};
        Scalar exp = {0,0,0,0};  
        Scalar res;

        secp256k1_square_mod_p(val,res);
        TEST_SCALAR_EQUALS(exp, res)
}


void test_secp256k1_square_mod_p_11(){
        Scalar val = {0xf99999999999999f, 0xf99999999999999f, 0xf99999999999999f, 0xf99999999999999f};
        Scalar exp = {0xd547b5da1ef1188b,0x0851ebe2d5201e3c,0x2eb852209785e9b1,0x551eb85e59ebb526};
        Scalar res;
        secp256k1_square_mod_p(val,res);
        TEST_SCALAR_EQUALS(exp, res)
}

void test_secp256k1_square_mod_p_asign_1(){

		
        Scalar val = {0x63b82f6f04ef2777,0x02e84bb7597aabe6,0xa25b0403f1eef757,0xb7c52588d95c3b9a};//Gy-
        Scalar exp = {0x44e4e9b8118c26f2,0xf16f80a548e5e20a,0x6bcc57ccd3735da5,0x4866d6a5ab41ab2c};  
        secp256k1_square_mod_p_asign(val);
        TEST_SCALAR_EQUALS(exp, val)
}

void test_secp256k1_square_mod_p_asign_2(){

        Scalar val = {0x9c47d08ffb10d4b8,0xfd17b448a6855419,0x5da4fbfc0e1108a8,0x483ada7726a3c465};//Gy+
        Scalar exp = {0x44e4e9b8118c26f2,0xf16f80a548e5e20a,0x6bcc57ccd3735da5,0x4866d6a5ab41ab2c};  
        secp256k1_square_mod_p_asign(val);
        TEST_SCALAR_EQUALS(exp, val)
}

void test_secp256k1_invert_mod_p_1(){

        Scalar val = {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p
        Scalar exp = {0,0,0,0}; 
        Scalar inv; 
		secp256k1_invert_mod_p(val,inv);
        TEST_SCALAR_EQUALS(exp, inv)
}



void test_secp256k1_invert_mod_p_2(){

        Scalar val = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};//n
        Scalar exp = {0x2ac462030e4af361, 0xd715ad82d3d2a398, 0xb43e759e099ce8f6, 0x5a8423ffb26c8d73};  
       	Scalar inv;
		secp256k1_invert_mod_p(val,inv);
        TEST_SCALAR_EQUALS(exp, inv)
}

void test_secp256k1_invert_mod_p_3(){

        Scalar val ={1,0,0,0};
        Scalar exp = {1,0,0,0};  
       	Scalar inv;
		secp256k1_invert_mod_p(val,inv);
        TEST_SCALAR_EQUALS(exp, inv)
}



void test_secp256k1_invert_mod_p_4(){

        Scalar val ={2,0,0,0};
        Scalar exp = {0xffffffff7ffffe18,0xffffffffffffffff,0xffffffffffffffff,0x7fffffffffffffff};  
       	Scalar inv;
		secp256k1_invert_mod_p(val,inv);
        TEST_SCALAR_EQUALS(exp, inv)
}


void test_secp256k1_invert_mod_p_5(){

        Scalar val ={4,0,0,0};
        Scalar exp = {0xFFFFFFFFBFFFFF0C, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0x3FFFFFFFFFFFFFFF};        
       	Scalar inv;
		secp256k1_invert_mod_p(val,inv);
        TEST_SCALAR_EQUALS(exp, inv)
}



void test_secp256k1_invert_mod_p_6(){

        Scalar val ={0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar exp = {0x48ca344950b1f7e3, 0xa8b3af9250bd1dc5, 0x56a7b0c57a72960e, 0x46e99613447130f9};  
       	Scalar inv;
		secp256k1_invert_mod_p(val,inv);
        TEST_SCALAR_EQUALS(exp, inv)
}


void test_secp256k1_invert_mod_p_7(){

        Scalar val ={0x5a1f8ffde8773176,0x40c247f073ce1f4c,0xbc0e1455985c0c8e,0xf089eaef57aba315};
        Scalar exp = {0x74dca51d4f93cc4f,0xa8f0367bad4f8152,0x16f85029e14932a1,0x1a70ccd07fc49412};  
       	Scalar inv;
		secp256k1_invert_mod_p(val,inv);
        TEST_SCALAR_EQUALS(exp, inv)
}

void test_secp256k1_invert_mod_p_8(){

        Scalar val ={1234567890,0,0,0};
		Scalar exp = {0xE672184570C31C74, 0xEE90FBAACEF8CD18, 0x942211B9475F5D34, 0x2B0CAA92097F8DA5};
     	Scalar inv;
    	secp256k1_invert_mod_p(val,inv);
        TEST_SCALAR_EQUALS(exp, inv);
}


void test_secp256k1_invert_mod_p_asign_1(){

        Scalar val = {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p
        Scalar exp = {0,0,0,0};  
		secp256k1_invert_mod_p_asign(val);
        TEST_SCALAR_EQUALS(exp, val)
}



void test_secp256k1_invert_mod_p_asign_2(){

        Scalar val = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};//n
        Scalar exp = {0x2ac462030e4af361, 0xd715ad82d3d2a398, 0xb43e759e099ce8f6, 0x5a8423ffb26c8d73};  
		secp256k1_invert_mod_p_asign(val);
        TEST_SCALAR_EQUALS(exp, val)
}

void test_secp256k1_invert_mod_p_asign_3(){

        Scalar val ={1,0,0,0};
        Scalar exp = {1,0,0,0};  
		secp256k1_invert_mod_p_asign(val);
        TEST_SCALAR_EQUALS(exp, val)
}



void test_secp256k1_invert_mod_p_asign_4(){

        Scalar val ={2,0,0,0};
        Scalar exp = {0xffffffff7ffffe18,0xffffffffffffffff,0xffffffffffffffff,0x7fffffffffffffff};  
		secp256k1_invert_mod_p_asign(val);
        TEST_SCALAR_EQUALS(exp, val)
}


void test_secp256k1_invert_mod_p_asign_5(){

        Scalar val ={4,0,0,0};
        Scalar exp = {0xFFFFFFFFBFFFFF0C, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0x3FFFFFFFFFFFFFFF};        
		secp256k1_invert_mod_p_asign(val);
        TEST_SCALAR_EQUALS(exp, val)
}



void test_secp256k1_invert_mod_p_asign_6(){

        Scalar val ={0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar exp = {0x48ca344950b1f7e3, 0xa8b3af9250bd1dc5, 0x56a7b0c57a72960e, 0x46e99613447130f9};  
		secp256k1_invert_mod_p_asign(val);
        TEST_SCALAR_EQUALS(exp, val)
}


void test_secp256k1_invert_mod_p_asign_7(){

        Scalar val ={0x5a1f8ffde8773176,0x40c247f073ce1f4c,0xbc0e1455985c0c8e,0xf089eaef57aba315};
        Scalar exp = {0x74dca51d4f93cc4f,0xa8f0367bad4f8152,0x16f85029e14932a1,0x1a70ccd07fc49412};  
		secp256k1_invert_mod_p_asign(val);
        TEST_SCALAR_EQUALS(exp, val)
}

void test_secp256k1_invert_mod_p_asign_8(){

        Scalar val ={1234567890,0,0,0};
		Scalar exp = {0xE672184570C31C74, 0xEE90FBAACEF8CD18, 0x942211B9475F5D34, 0x2B0CAA92097F8DA5};
     	Scalar inv;
    	secp256k1_invert_mod_p_asign(val);
        TEST_SCALAR_EQUALS(exp, val)
}


void test_secp256k1_exponentiate_mod_p1(){
        Scalar a ={2,0,0,0};
        Scalar e = {0xfffffffefffffc2d, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p-2
        Scalar exp = {0xffffffff7ffffe18,0xffffffffffffffff,0xffffffffffffffff,0x7fffffffffffffff};  
        Scalar res;
        secp256k1_exponentiate_mod_p(a,e,res);
        TEST_SCALAR_EQUALS(exp, res)
}


void test_secp256k1_exponentiate_mod_p2(){
        Scalar a ={0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar e = {0xfffffffefffffc2d, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p-2
        Scalar exp = {0x48ca344950b1f7e3, 0xa8b3af9250bd1dc5, 0x56a7b0c57a72960e, 0x46e99613447130f9};  
        Scalar res;
        secp256k1_exponentiate_mod_p(a,e,res);
       TEST_SCALAR_EQUALS(exp, res)
}

void test_secp256k1_exponentiate_mod_p3(){
        Scalar a ={2,0,0,0};
        Scalar e = {0xfffffffefffffc2d, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p-2
        Scalar exp = {0xffffffff7ffffe18,0xffffffffffffffff,0xffffffffffffffff,0x7fffffffffffffff};  
        Scalar res;
        secp256k1_exponentiate_mod_p(a,e,res);
       TEST_SCALAR_EQUALS(exp, res)
}


void test_secp256k1_exponentiate_mod_p4(){
        Scalar a ={0x5a1f8ffde8773176,0x40c247f073ce1f4c,0xbc0e1455985c0c8e,0xf089eaef57aba315};
        Scalar e = {0xfffffffefffffc2d, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p-2
        Scalar exp = {0x74dca51d4f93cc4f,0xa8f0367bad4f8152,0x16f85029e14932a1,0x1a70ccd07fc49412};  
        Scalar res;
        secp256k1_exponentiate_mod_p(a,e,res);
       TEST_SCALAR_EQUALS(exp, res)
}


void test_secp256k1_exponentiate_mod_p5(){
        Scalar a ={0x5a1f8ffde8773176,0x40c247f073ce1f4c,0xbc0e1455985c0c8e,0xf089eaef57aba315};
        Scalar e = {3,0,0,0};
        Scalar exp = {0x59ae4742bd581e7f,0x4e2b1534a0782299,0xea0dee34354adc7d,0x6f032fba18b1cad5};  
        Scalar res;
        secp256k1_exponentiate_mod_p(a,e,res);
       TEST_SCALAR_EQUALS(exp, res)
}

void test_secp256k1_exponentiate_mod_p6(){
        Scalar e = {3,0,0,0};
        Scalar a ={0x74dca51d4f93cc4f,0xa8f0367bad4f8152,0x16f85029e14932a1,0x1a70ccd07fc49412};
        Scalar exp = {0xB5043452B8F1EAE8, 0x3E2D784C1CC19CBB, 0x916B6F17F63D8FF6, 0xC00C8F8FB555C39A};        
        Scalar res;
        secp256k1_exponentiate_mod_p(a,e,res);
       TEST_SCALAR_EQUALS(exp, res)
}

void test_secp256k1_exponentiate_mod_p7(){
        Scalar a =   {0x74dca51d4f93cc4f,0xa8f0367bad4f8152,0x16f85029e14932a1,0x1a70ccd07fc49412};
        Scalar e =   {0xB5043452B8F1EAE8, 0x3E2D784C1CC19CBB, 0x916B6F17F63D8FF6, 0xC00C8F8FB555C39A};
		Scalar exp = {0xC831614B17E37244, 0xE8A0CD98ECB496DF, 0x1AEA2DD56D9B77E5, 0x1717A1B6EBAE18CE};
        Scalar res;
        secp256k1_exponentiate_mod_p(a,e,res);
       TEST_SCALAR_EQUALS(exp, res)
}


void test_secp256k1_cube_mod_p_1(){
        Scalar a ={0x5a1f8ffde8773176,0x40c247f073ce1f4c,0xbc0e1455985c0c8e,0xf089eaef57aba315};
        Scalar exp = {0x59ae4742bd581e7f,0x4e2b1534a0782299,0xea0dee34354adc7d,0x6f032fba18b1cad5}; 
        Scalar res;
        secp256k1_cube_mod_p(a, res);
       TEST_SCALAR_EQUALS(exp, res)
}

void test_secp256k1_cube_mod_p_2(){
        Scalar a ={0x74dca51d4f93cc4f,0xa8f0367bad4f8152,0x16f85029e14932a1,0x1a70ccd07fc49412};
        Scalar exp = {0xB5043452B8F1EAE8, 0x3E2D784C1CC19CBB, 0x916B6F17F63D8FF6, 0xC00C8F8FB555C39A};
        Scalar res;
        secp256k1_cube_mod_p(a, res);
        TEST_SCALAR_EQUALS(exp, res)
}

void test_secp256k1_cube_mod_p_asign_1(){
        Scalar a ={0x5a1f8ffde8773176,0x40c247f073ce1f4c,0xbc0e1455985c0c8e,0xf089eaef57aba315};
        Scalar exp = {0x59ae4742bd581e7f,0x4e2b1534a0782299,0xea0dee34354adc7d,0x6f032fba18b1cad5}; 
        secp256k1_cube_mod_p_asign(a);
        TEST_SCALAR_EQUALS(exp, a)
}

void test_secp256k1_cube_mod_p_asign_2(){
        Scalar a ={0x74dca51d4f93cc4f,0xa8f0367bad4f8152,0x16f85029e14932a1,0x1a70ccd07fc49412};
        Scalar exp = {0xB5043452B8F1EAE8, 0x3E2D784C1CC19CBB, 0x916B6F17F63D8FF6, 0xC00C8F8FB555C39A};
        secp256k1_cube_mod_p_asign(a);
        TEST_SCALAR_EQUALS(exp, a)
}

void test_secp256k1_squareroot_mod_p_1(){

        Scalar a = {25,0,0,0};
        Scalar exp = {0xFFFFFFFEFFFFFC2A, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF};
        Scalar root;
        secp256k1_squareroot_mod_p(a,root);
        TEST_SCALAR_EQUALS(exp, root)
}

void test_secp256k1_squareroot_mod_p_2(){

        Scalar a = {36,0,0,0};
        Scalar exp = {0xFFFFFFFEFFFFFC29, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF};
        Scalar root;
		secp256k1_squareroot_mod_p(a,root);
        TEST_SCALAR_EQUALS(exp, root)
}


void test_secp256k1_squareroot_mod_p_3(){

        Scalar a = {64,0,0,0};
        Scalar exp = {8,0,0,0};
        Scalar root;
	    secp256k1_squareroot_mod_p(a,root);
        TEST_SCALAR_EQUALS(exp, root)
}

void test_secp256k1_squareroot_mod_p_4(){

        Scalar a = {9,0,0,0};
        Scalar exp = {0xFFFFFFFEFFFFFC2C, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF};
        Scalar root;
		secp256k1_squareroot_mod_p(a,root);
        TEST_SCALAR_EQUALS(exp, root)
}

void test_secp256k1_squareroot_mod_p_5(){

        Scalar a = {16,0,0,0};
        Scalar exp = {4,0,0,0};
        Scalar root;
		secp256k1_squareroot_mod_p(a,root);
        TEST_SCALAR_EQUALS(exp, root)
}

void test_secp256k1_squareroot_mod_p_6(){
        Scalar exp = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar a = {0x165483cc248f15f1, 0x5896ce5cc50e63aa, 0x0a0bef2c090f8a19, 0x480ac6ad64873e1c};  
        Scalar root;
		secp256k1_squareroot_mod_p(a,root);
        TEST_SCALAR_EQUALS(exp, root)
}

void test_secp256k1_squareroot_mod_p_7(){

        Scalar exp = {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465};
        Scalar a = {0x44e4e9b8118c26f2,0xf16f80a548e5e20a,0x6bcc57ccd3735da5,0x4866d6a5ab41ab2c};  
        Scalar root;
		secp256k1_squareroot_mod_p(a,root);
        TEST_SCALAR_EQUALS(exp, root)
}


void test_secp256k1_squareroot_mod_p_asign_1(){
        Scalar exp = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar a = {0x165483cc248f15f1, 0x5896ce5cc50e63aa, 0x0a0bef2c090f8a19, 0x480ac6ad64873e1c};  
		secp256k1_squareroot_mod_p_asign(a);
        TEST_SCALAR_EQUALS(exp, a)
}

void test_secp256k1_squareroot_mod_p_asign_2(){

        Scalar exp = {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465};
        Scalar a = {0x44e4e9b8118c26f2,0xf16f80a548e5e20a,0x6bcc57ccd3735da5,0x4866d6a5ab41ab2c};  
		secp256k1_squareroot_mod_p_asign(a);
        TEST_SCALAR_EQUALS(exp, a)
}


void test_secp256k1_has_squareroot_mod_p_1(){
        Scalar a = {16,0,0,0};
        int exp = 1;
        int res = secp256k1_has_squareroot_mod_p(a);
        TEST_INT_EQUALS(exp,res)
        
}

void test_secp256k1_has_squareroot_mod_p_2(){

        Scalar a = {7,0,0,0};
        int exp = 0xFFFFFC2E;       
        int res =  secp256k1_has_squareroot_mod_p(a);
        TEST_INT_EQUALS(exp,res)
}

void test_secp256k1_has_squareroot_mod_p_3(){

        Scalar a = {64,0,0,0};
        int exp = 1;
        int res =  secp256k1_has_squareroot_mod_p(a);
       TEST_INT_EQUALS(exp,res)
}

void test_secp256k1_has_squareroot_mod_p_4(){

        Scalar a = {66,0,0,0};
		int exp = 0xFFFFFC2E; 
        int res =  secp256k1_has_squareroot_mod_p(a);
        TEST_INT_EQUALS(exp,res)
}

void test_secp256k1_has_squareroot_mod_p_5(){

        Scalar a = {16,0,0,0};
        int exp = 1;
        int res = secp256k1_has_squareroot_mod_p(a);
        TEST_INT_EQUALS(exp,res)
}

void test_secp256k1_has_squareroot_mod_p_6(){

        Scalar a = {7,0,0,0};
        int exp = 0xFFFFFC2E;         
        int res = secp256k1_has_squareroot_mod_p(a);
        TEST_INT_EQUALS(exp,res)
}

void test_secp256k1_has_squareroot_mod_p_7(){

        Scalar a = {64,0,0,0};
        int exp = 1;
        int res = secp256k1_has_squareroot_mod_p(a);
        TEST_INT_EQUALS(exp,res)

}

void test_secp256k1_has_squareroot_mod_p_8(){

        Scalar a = {66,0,0,0};
        int exp = 0xFFFFFC2E;        
        int res = secp256k1_has_squareroot_mod_p(a);
        TEST_INT_EQUALS(exp,res)

}

void test_secp256k1_has_squareroot_mod_p_9(){

        Scalar a = {0x165483cc248f15f1, 0x5896ce5cc50e63aa, 0x0a0bef2c090f8a19, 0x480ac6ad64873e1c};  
        int exp = 1;
        int res = secp256k1_has_squareroot_mod_p(a);
        TEST_INT_EQUALS(exp,res)

}


void test_secp256k1_mul_mod_p_1(){

        Scalar a = {0xFFFFFFFFBFFFFF0C, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0x3FFFFFFFFFFFFFFF};
        Scalar b =   {0xfffffffefffffc30, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar exp = {0xFFFFFFFFBFFFFF0C, 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF, 0x3FFFFFFFFFFFFFFF}; //the exponent for the squareroot-algorithm       
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp,r)
}

void test_secp256k1_mul_mod_p_2(){

        Scalar a =   {0xffffffffffffffff, 0, 0,0};
        Scalar b =   {0xffffffffffffffff,0,0,0};
        Scalar exp = {1, 0xfffffffffffffffe, 0, 0};  
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp,r)
}

void test_secp256k1_mul_mod_p_3(){

        Scalar a =   {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =   {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar exp = {0x7a0000e8900, 1,0, 0};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp,r)
}

void test_secp256k1_mul_mod_p_4(){

        Scalar a =   {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =   {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar exp = {0x2e6834736e1ef264, 0x2b2b2b2ad7e6d6aa, 0xd58ed58ef5dff65b, 0xb664b664ca13ca5e};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp,r)
}


void test_secp256k1_mul_mod_p_5(){

        Scalar a =   {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =   {0xfffffffefffffc30, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar exp = {0,0,0,0};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp,r)
}



void test_secp256k1_mul_mod_p_6(){

        Scalar a =   {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =   {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar exp = {0,0,0,0};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp,r)
}


void test_secp256k1_mul_mod_p_7(){

        Scalar a =   {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =   {0xfffffffefffffc2e, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar exp = {0,0,0,0};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp,r)
}


void test_secp256k1_mul_mod_p_8(){

        Scalar a =   {0xfffffffefffffc2e, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =   {0xfffffffefffffc2e, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar exp = {1,0,0,0};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp,r)
}


void test_secp256k1_mul_mod_p_9(){

        Scalar a =   {0xfffffffefffffc30, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =   {0xfffffffefffffc30, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar exp = {1,0,0,0};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp,r)
}

void test_secp256k1_mul_mod_p_10(){

        Scalar a =   {0xfffffffefffffc30, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =   {0xfffffffefffffc2e, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar exp = {0xfffffffefffffc2e, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp,r)
}

void test_secp256k1_mul_mod_p_11(){

        Scalar a =   {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b =   {0x48ca344950b1f7e3, 0xa8b3af9250bd1dc5, 0x56a7b0c57a72960e, 0x46e99613447130f9};
        Scalar exp = {1,0,0,0};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp,r)
}


void test_secp256k1_mul_mod_p_12(){

        Scalar a =   {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =   {0xfffffffefffffc30, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar exp = {0x1000003d0,0, 0,0};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp,r)
}

void test_secp256k1_mul_mod_p_13(){

        Scalar a =   {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b =   {0xfffffffefffffc2e, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar exp = {0xfffffffdfffff85f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp,r)
}


void test_secp256k1_mul_mod_p_14(){

        Scalar a =   {0x5a1f8ffde8773176,0x40c247f073ce1f4c, 0xbc0e1455985c0c8e, 0xf089eaef57aba315};
        Scalar b =   {0x3d3cc4a3546ee4e8,0xc5a830101aabff78, 0xf1fe87385a4582e7, 0xf3b1b70975dec6dd};
        Scalar exp = {0x86dbc498f66ee080, 0x429dfabfe818bcf4, 0x2ed219af5c7bb005, 0x885da4eae93c3d69};
		Scalar r;
        secp256k1_mul_mod_p(a, b, r);
        TEST_SCALAR_EQUALS(exp,r)
}




//******************************************* tests for functions modulo order n **************************************************************************


void test_secp256k1_secp256k1_reduce_mod_n_1(){
        
        Scalar val = {0xffffffffffffffff, 0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff};
        Scalar exp = {0x402da1732fc9bebe,0x4551231950b75fc4, 1};
        secp256k1_reduce_mod_n(val);
        TEST_SCALAR_EQUALS(exp, val) 
}

void test_secp256k1_secp256k1_reduce_mod_n_2(){
        
        Scalar val = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead,0xdadadadadadadada};
        Scalar exp = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead,0xdadadadadadadada};
        secp256k1_reduce_mod_n(val);
        TEST_SCALAR_EQUALS(exp, val) 
}

void test_secp256k1_secp256k1_reduce_mod_n_3(){
        
        Scalar val = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead,0xdadadadadadadada};
        Scalar exp = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead,0xdadadadadadadada};
        secp256k1_reduce_mod_n(val);
        TEST_SCALAR_EQUALS(exp, val) 
}

void test_secp256k1_secp256k1_reduce_mod_n_4(){
        
        Scalar val = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};
        Scalar exp = {0, 0, 0, 0};
        secp256k1_reduce_mod_n(val);
        TEST_SCALAR_EQUALS(exp, val) 
}




void test_secp256k1_add_mod_n_1(){
        
        Scalar a = {0xdadadadadadadada, 0xdeaddeaddeaddead, 0xfefefefefefefefe, 0xabbaabbaabbaabba};
        Scalar b = {0xdadadadadadadada, 0xdeaddeaddeaddead, 0xfadefadefadefade, 0xfadefadefadefade};
        Scalar r;      
        Scalar exp = {0xf5e35728e57f7473,0x02ace0750e131d1f,0xf9ddf9ddf9ddf9df,0xa699a699a699a699};
        secp256k1_add_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}


void test_secp256k1_add_mod_n_2(){
        
        Scalar a;
        Scalar b;
        secp256k1_parse_scalar("abbaabbaabbaabbafefefefefefefefedeaddeaddeaddeaddadadadadadadada", a);
        secp256k1_parse_scalar("abbaabbaabbaabbafefefefefefefefedeaddeaddeaddeaddadadadadadadada", b);
        Scalar r;      
        Scalar exp;
        secp256k1_parse_scalar("5775577557755775fdfdfdfdfdfdfdff02ace0750e131d1ff5e35728e57f7473", exp);
        secp256k1_add_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}

void test_secp256k1_add_mod_n_3(){
        
        Scalar a;
        Scalar b;
        secp256k1_parse_scalar("abbaabbaabbaabbafefefefefefefefedeaddeaddeaddeaddadadadadadadada", a);
        secp256k1_parse_scalar("ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff", b);
        Scalar r;      
        Scalar exp;
        secp256k1_parse_scalar("abbaabbaabbaabbafefefefefefeff0023ff01c72f653e721b087c4e0aa49998", exp);
        secp256k1_add_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}

void test_secp256k1_add_mod_n_4(){
        
        Scalar a = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;           
        Scalar exp = {0x805b42e65f937d7c, 0x8aa24632a16ebf88, 2,0};
        secp256k1_add_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}

void test_secp256k1_add_mod_n_5(){
        
        Scalar a = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};
        Scalar b = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;                         
        Scalar exp = {0x402da1732fc9bebe, 0x4551231950b75fc4, 1,0};
        secp256k1_add_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}

void test_secp256k1_mul_mod_n_1(){
        
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0};
        Scalar b = {0xabbaabbaabbaabba, 0, 0, 0};
        Scalar r;  
        Scalar exp = {0x6626efd0797a0324, 0x2e8b0b47e804c4c1, 0xcdf5797d2504d08c, 0x9560837271845f95 };
        secp256k1_mul_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}

void test_secp256k1_mul_mod_n_2(){
        
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xabbaabbaabbaabba, 0, 0, 0};
        Scalar r;  
        Scalar exp = {0x4f8d127ac3048852,0x28fb69eac90e6cff, 0x7b00c3d55860da6b, 0xc813076d46c78622};
        secp256k1_mul_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}


void test_secp256k1_mul_mod_n_3(){
        
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xabbaabbaabbaabba, 0xdeafdeafdeafdeaf, 0, 0};
        Scalar r;  
        Scalar exp = {0xa2e8a718c8f4391a,0xa4fd92e15fd1a59d,0xa08a0a1a8131661c,0xc46bf510ca0af161};
        secp256k1_mul_mod_n(a, b, r);
       TEST_SCALAR_EQUALS(exp, r) 
}



void test_secp256k1_mul_mod_n_4(){
        
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xd00fd00fd00fd00f, 0xdeafdeafdeafdeaf, 0xbeefbeefbeefbeef, 0};
        Scalar r;   
        Scalar exp = {0xceca8f047e2a065d,0x892fe175e1492c8a,0x80ffa4c7b53e4040,0xe223f8f9d3aeac68};
        secp256k1_mul_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}
 
void test_secp256k1_mul_mod_n_5(){
        
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar r;       
        Scalar exp = {0x0bfa5f0b85eaeb70,0x80c12db9ee712832,0x294c58a8a8328d36,0x1cbdc38ef7120249};
        secp256k1_mul_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}

void test_secp256k1_mul_mod_n_6(){
        
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar r;      
        Scalar exp = {0xc4de3cb88fb027e1,0xcc0fde5133bbf131,0x3c1e69b67c8b999b,0x396e3143a2085c94};
        secp256k1_mul_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}

void test_secp256k1_mul_mod_n_7(){
        
        Scalar a = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar b = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar r;  
        Scalar exp = {0xbd67421d53d8494f,0x048c8fcce7f19951,0xba8169d64e59d4a0,0x6b6a04942ffeba55};
        secp256k1_mul_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}

void test_secp256k1_mul_mod_n_8(){
        
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;           
        Scalar exp = {0xc0e6f362e5557208,0x7f16734fccc1eb89,0xe38e21aaccc99097,0x6e524c9d903e2445};
        secp256k1_mul_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}

void test_secp256k1_mul_mod_n_9(){
        Scalar a = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar b = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r;         
        Scalar exp = {0x0125f88877059a90,0xd3028865be5a31dc,0xf831f1f592b65040,0x98fa846fd876af4b};
        secp256k1_mul_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}

//******************square mod n

void test_secp256k1_square_mod_n_1(){
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar r;      
        Scalar exp = {0xc4de3cb88fb027e1,0xcc0fde5133bbf131,0x3c1e69b67c8b999b,0x396e3143a2085c94};
        secp256k1_square_mod_n(a, r);
        TEST_SCALAR_EQUALS(exp, r) 
}

void test_secp256k1_square_mod_n_2(){
        Scalar a = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar r;  
        Scalar exp = {0xbd67421d53d8494f,0x048c8fcce7f19951,0xba8169d64e59d4a0,0x6b6a04942ffeba55};
        secp256k1_square_mod_n(a,r);
        TEST_SCALAR_EQUALS(exp, r) 
}

void test_secp256k1_square_mod_n_3(){
        Scalar val = {0,0,0,0};
        Scalar exp = {0,0,0,0};  
        Scalar res;
        secp256k1_square_mod_n(val,res);
        TEST_SCALAR_EQUALS(exp, res) 
}

void test_secp256k1_square_mod_n_4(){
        Scalar val = {1,0,0,0};
        Scalar exp = {1,0,0,0};  
        Scalar res;
        secp256k1_square_mod_n(val,res);
        TEST_SCALAR_EQUALS(exp, res) 
}


void test_secp256k1_square_mod_n_5(){
        Scalar val = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar exp = {0xc4de3cb88fb027e1, 0xcc0fde5133bbf131, 0x3c1e69b67c8b999b, 0x396e3143a2085c94};  
        Scalar res;
        secp256k1_square_mod_n(val,res);
        TEST_SCALAR_EQUALS(exp, res) 
}


void test_secp256k1_square_mod_n_6(){
        Scalar val = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};//n
        Scalar exp = {0,0,0,0};  
        Scalar res;
        secp256k1_square_mod_n(val,res);
        TEST_SCALAR_EQUALS(exp, res)  
}

void test_secp256k1_square_mod_n_7(){
        Scalar val = {0xBFD25E8CD0364142, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};;//n+1
        Scalar exp = {1,0,0,0};  
        Scalar res;
        secp256k1_square_mod_n(val,res);
        TEST_SCALAR_EQUALS(exp, res)  
}

void test_secp256k1_square_mod_n_8(){
        Scalar val = {0xBFD25E8CD0364140, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};;//n-1
        Scalar exp = {1,0,0,0};  
        Scalar res;
        secp256k1_square_mod_n(val,res);
        TEST_SCALAR_EQUALS(exp, res)  
}


void test_secp256k1_square_mod_n_9(){
        Scalar val = {0xBFD25E8CD036413f, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};//n-2
        Scalar exp = {4,0,0,0};  
        Scalar res;
        secp256k1_square_mod_n(val,res);
        TEST_SCALAR_EQUALS(exp, res)  
}


void test_secp256k1_square_mod_n_10(){
        Scalar val = {0x63b82f6f04ef2777,0x02e84bb7597aabe6,0xa25b0403f1eef757,0xb7c52588d95c3b9a};//Gy-
        Scalar exp = {0x92257b42ad837086,0x459d96fc8984a0b6,0xc84d4ba8fa0fd1f8,0x89190981fdf298d4};  
        Scalar res;
        secp256k1_square_mod_n(val,res);
        TEST_SCALAR_EQUALS(exp, res)  
}


void test_secp256k1_square_mod_n_11(){

        Scalar val = {0x9c47d08ffb10d4b8,0xfd17b448a6855419,0x5da4fbfc0e1108a8,0x483ada7726a3c465};//Gy+
        Scalar exp = {0xd972e4448d6b5a58,0x471af7794639da50,0x316d2404dcc41ed6,0x308deb5bb5abd3d2};  
        Scalar res;

        secp256k1_square_mod_n(val,res);
        TEST_SCALAR_EQUALS(exp, res)  
}

void test_secp256k1_square_mod_n_12(){
        Scalar val = {0,0,0,0};
        Scalar exp = {0,0,0,0};  
        Scalar res;
        secp256k1_square_mod_n(val,res);
        TEST_SCALAR_EQUALS(exp, res)  
}


void test_secp256k1_square_mod_n_13(){
        Scalar val = {0xf99999999999999f, 0xf99999999999999f, 0xf99999999999999f, 0xf99999999999999f};
        Scalar exp = {0xb755d12813dea34d,0xfdb26a405ddba449,0x4daf61d992f3f07c,0x147786a3879965a8};
        Scalar res;
        secp256k1_square_mod_n(val,res);
        TEST_SCALAR_EQUALS(exp, res) 
}

void test_secp256k1_square_mod_n_asign_1(){
        Scalar val = {0x63b82f6f04ef2777,0x02e84bb7597aabe6,0xa25b0403f1eef757,0xb7c52588d95c3b9a};//Gy-
        Scalar exp = {0x92257b42ad837086,0x459d96fc8984a0b6,0xc84d4ba8fa0fd1f8,0x89190981fdf298d4};  
        secp256k1_square_mod_n_asign(val);
        TEST_SCALAR_EQUALS(exp, val) 
}


void test_secp256k1_square_mod_n_asign_2(){
        Scalar val = {0x9c47d08ffb10d4b8,0xfd17b448a6855419,0x5da4fbfc0e1108a8,0x483ada7726a3c465};//Gy+
        Scalar exp = {0xd972e4448d6b5a58,0x471af7794639da50,0x316d2404dcc41ed6,0x308deb5bb5abd3d2};  
        secp256k1_square_mod_n_asign(val);
        TEST_SCALAR_EQUALS(exp, val) 
}


//****************** invert mod n
void test_secp256k1_invert_mod_n_1(){

        Scalar val = {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p
        Scalar exp = {0x8f3107a7a3e12be1,0x569fa14fe13edb7f,0x4bc18a61f6631708,0xa57bdc004d93728c}; 
        Scalar inv; 
		secp256k1_invert_mod_n(val,inv);
        TEST_SCALAR_EQUALS(exp, inv) 
}



void test_secp256k1_invert_mod_n_2(){

        Scalar val = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};//n
        Scalar exp = {0,0,0,0};  
       	Scalar inv;
		secp256k1_invert_mod_n(val,inv);
        TEST_SCALAR_EQUALS(exp, inv) 
}

void test_secp256k1_invert_mod_n_3(){

        Scalar val ={1,0,0,0};
        Scalar exp = {1,0,0,0};  
       	Scalar inv;
		secp256k1_invert_mod_n(val,inv);
        TEST_SCALAR_EQUALS(exp, inv) 
}



void test_secp256k1_invert_mod_n_4(){

        Scalar val ={2,0,0,0};
        Scalar exp = {0xdfe92f46681b20a1,0x5d576e7357a4501d,0xffffffffffffffff,0x7fffffffffffffff};  
       	Scalar inv;
		secp256k1_invert_mod_n(val,inv);
        TEST_SCALAR_EQUALS(exp, inv) // "inv 2");
}


void test_secp256k1_invert_mod_n_5(){

        Scalar val ={4,0,0,0};
        Scalar exp = {0xcfddc6e99c28b0f1, 0x0c0325ad0376782c, 0xffffffffffffffff, 0xbfffffffffffffff};        
       	Scalar inv;
		secp256k1_invert_mod_n(val,inv);
        TEST_SCALAR_EQUALS(exp, inv) 
}



void test_secp256k1_invert_mod_n_6(){

        Scalar val ={0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar exp = {0xa09cccd761df4fd8, 0x261fb885f90ae37e, 0x39d289d99a963637, 0x1ae4490de9f04989};  
       	Scalar inv;
		secp256k1_invert_mod_n(val,inv);
        TEST_SCALAR_EQUALS(exp, inv) 
}


void test_secp256k1_invert_mod_n_7(){

        Scalar val ={0x5a1f8ffde8773176,0x40c247f073ce1f4c,0xbc0e1455985c0c8e,0xf089eaef57aba315};
        Scalar exp = {0x4b6cb9993c67beaf,0x5f16f1eab3900559,0x4c2453286480f13a,0x670ba7fe0feea77a};  
       	Scalar inv;
		secp256k1_invert_mod_n(val,inv);
        TEST_SCALAR_EQUALS(exp, inv) 
}

void test_secp256k1_invert_mod_n_8(){

        Scalar val ={1234567890,0,0,0};
		Scalar exp = {0xf4484e8dceb39d91, 0xa0c6ba7347f32b95, 0xf23bfbb091158daa, 0x6bd555ecd0e4e06d};
     	Scalar inv;
    	secp256k1_invert_mod_n(val,inv);
        TEST_SCALAR_EQUALS(exp, inv) 
}


void test_secp256k1_invert_mod_n_asign_1(){
        Scalar val ={0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar exp = {0xa09cccd761df4fd8, 0x261fb885f90ae37e, 0x39d289d99a963637, 0x1ae4490de9f04989};  
		secp256k1_invert_mod_n_asign(val);
        TEST_SCALAR_EQUALS(exp, val) 
}


void test_secp256k1_invert_mod_n_asign_2(){

        Scalar val ={0x5a1f8ffde8773176,0x40c247f073ce1f4c,0xbc0e1455985c0c8e,0xf089eaef57aba315};
        Scalar exp = {0x4b6cb9993c67beaf,0x5f16f1eab3900559,0x4c2453286480f13a,0x670ba7fe0feea77a};  
		secp256k1_invert_mod_n_asign(val);
        TEST_SCALAR_EQUALS(exp, val) 
}


//******************sub mod n

void test_secp256k1_sub_mod_n_1(){
        
        Scalar a = {0xdadadadadadadada, 0xdeaddeaddeaddead, 0xfefefefefefefefe, 0xabbaabbaabbaabba};
        Scalar b = {0xdadadadadadadada, 0xdeaddeaddeaddead, 0xfadefadefadefade, 0xfadefadefadefade};
        Scalar r;     
        Scalar exp = {0xbfd25e8cd0364141, 0xbaaedce6af48a03b, 0x042004200420041e, 0xb0dbb0dbb0dbb0dc};
        secp256k1_sub_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}

void test_secp256k1_sub_mod_n_2(){
		

        Scalar a =   {0x5a1f8ffde8773176,0x40c247f073ce1f4c, 0xbc0e1455985c0c8e, 0xf089eaef57aba315};
        Scalar b =   {0x3d3cc4a3546ee4e8,0xc5a830101aabff78, 0xf1fe87385a4582e7, 0xf3b1b70975dec6dd};
        Scalar exp = {0xdcb529e7643e8dcf,0x35c8f4c7086ac00f, 0xca0f8d1d3e1689a5, 0xfcd833e5e1ccdc37};
        Scalar r;                  
        secp256k1_sub_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}

void test_secp256k1_sub_mod_n_3(){
		
        
        Scalar a = {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b = {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r; 
        Scalar exp =  {0,0,0,0};
        secp256k1_sub_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}

void test_secp256k1_sub_mod_n_4(){
		

        Scalar a = {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b = {0xfffffffefffffc2f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r; 
        Scalar exp =  {0x1000003d0,0,0,0};
        secp256k1_sub_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}


void test_secp256k1_sub_mod_n_5(){
		

        Scalar a = {0xfffffffefffffc2f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b = {0xfffffffefffffc2f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r; 
        Scalar exp =  {0,0,0,0};
        secp256k1_sub_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}

void test_secp256k1_sub_mod_n_6(){
		

        Scalar a = {0,0,0,0};
        Scalar b = {0,0,0,0};
        Scalar r; 
        Scalar exp =  {0,0,0,0};
        secp256k1_sub_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}

void test_secp256k1_sub_mod_n_7(){
		
        Scalar a = {0xfffffffefffffc2f,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b = {1,0,0,0};
        Scalar r;                          
        Scalar exp =  {0x402da1722fc9baed,0x4551231950b75fc4, 1, 0};
        secp256k1_sub_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}

void test_secp256k1_sub_mod_n_8(){
		

        Scalar a = {1,0,0,0};
        Scalar b = {0xBFD25E8CD0364141,0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xffffffffffffffff};
        Scalar r; 
        Scalar exp =  {1,0,0,0};
        secp256k1_sub_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}

void test_secp256k1_sub_mod_n_9(){
		

        Scalar a = {1,0,0,0};
        Scalar b = {5,0,0,0};
        Scalar r;  
        Scalar exp =  {0xbfd25e8cd036413d,0xbaaedce6af48a03b, 0xfffffffffffffffe, 0xffffffffffffffff};
        secp256k1_sub_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}

void test_secp256k1_sub_mod_n_10(){
		

        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar r; 
        Scalar exp =  {0,0,0,0};
        secp256k1_sub_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}

void test_secp256k1_sub_mod_n_11(){
        Scalar a = {0xBFD25E8CD0364141,0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xffffffffffffffff};
        Scalar b = {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar r; 
        Scalar exp =  {0x7fa4bd19a06c8283,0x755db9cd5e914077, 0xfffffffffffffffd, 0xffffffffffffffff};
        secp256k1_sub_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}

void test_secp256k1_sub_mod_n_12(){
		

        Scalar a = {0xffffffffffffffff,0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b = {0xBFD25E8CD0364141, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};
        Scalar r; 
        Scalar exp = {0x402da1732fc9bebe,0x4551231950b75fc4,1,0};
        secp256k1_sub_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}

void test_secp256k1_sub_mod_n_13(){
        Scalar a = {0xBFD25E8CD0364141,0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xffffffffffffffff};
        Scalar b = {1,0,0,0};
        Scalar r;                          
        Scalar exp = {0xBFD25E8CD0364140, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};
        secp256k1_sub_mod_n(a, b, r);
        TEST_SCALAR_EQUALS(exp, r) 
}



//******************************************* tests for Points on the secp255k1 curve **************************************************************************

void test_add_different_points_1(){

        Point exp = {{0xad8a04887e5b2352, 0xb53f53e486d8511d, 0x2fe83c1af1a8403c, 0x50863ad64a87ae8a }, 
        				{0xF2EE187E9C582BA6,0xBC11A1DF38855ED6,0xFA9E77237716103A,0x2CD470243453A299}}; 
        Point p1 = {{0x15B6102F43228506, 0x2E4EB529ED776E92, 0x10DAE4C62A4520DD, 0x4D696DF0B0F1C4C1},
        				{0x97A110D0A2682360, 0xDE221EA11AE3A483, 0x0769C4B534C00831, 0xD9C5BF1AC94B5C7F}};
        Point p2 = {{0x8808CA5FBEB8B1E2, 0x0262B204EA0DDA76, 0xB6FFFFFCDDEB356B, 0x52DE253AFBB83870}, 
        				{0x961F40C08F8D21EA, 0x89686278002F03ED, 0x0FF834D738E421EA, 0x3A270D6FD36FB8DB}};
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        TEST_SCALAR_EQUALS(exp.x, p3.x)
        TEST_SCALAR_EQUALS(exp.y, p3.y)
}


void test_add_different_points_2(){

        Point exp = {{0x98C13CA84DB6A392, 0xC832C50E9B1EEF8A, 0xDEF2B65EE8C8B17D, 0x6D0A80195FF48CC4 }, 
        				{0xA17A800BEE319F96,0xBBEAB4B55A15F295,0xEC17A721F0F0BAF8,0x6B47A61FD59BF8D0}}; 
        Point p1 = {{0xB26AF1F9B853983D, 0x299E84FCBF0B98AF, 0x9894B97A3990AAD5,0xE315F81399469D5A },
        			   {0xC5C81620CBA96983,0xEEBB7348E27E7918 ,0x1227B0B98A468469 ,0x86F325BB8701D0C2 }};
        Point p2 = {{0xABAC09B95C709EE5, 0x5C778E4B8CEF3CA7, 0x3045406E95C07CD8, 0xC6047F9441ED7D6D}, 
        				{0x236431A950CFE52A, 0xF7F632653266D0E1, 0xA3C58419466CEAEE, 0x1AE168FEA63DC339}};
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        TEST_SCALAR_EQUALS(exp.x, p3.x)
        TEST_SCALAR_EQUALS(exp.y, p3.y)
}

void test_add_different_points_3(){

		Point exp = {{0x7573D644A1C279B2, 0x778ED5CD442392AE, 0xBF405DA152F1B7DA, 0x60087A99DDA9CE3D },
						{0x4077C1C554A7D3FC, 0x3563D7A11690BCE0, 0xE2BA6984F86D1E0B, 0x922A1CCD38EA29FE}};
        Point p1 = {{0x57ee45bbceba551b,0x9327b8047643b458,0xf8b9038217d65ef0,0xc0880c2b124e1bc1},
                       {0x29f00f6a71b300ec,0xb8250d73398ebd19,0x8ca4995c0f2348f1,0x4a6e48d3fd76af13}};

        Point p2 = {{0xad8a04887e5b2352,0xb53f53e486d8511d,0x2fe83c1af1a8403c,0x50863ad64a87ae8a},
        			   {0xF2EE187E9C582BA6,0xBC11A1DF38855ED6,0xFA9E77237716103A,0x2CD470243453A299}};
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        TEST_SCALAR_EQUALS(exp.x, p3.x)
        TEST_SCALAR_EQUALS(exp.y, p3.y)
}

void test_add_different_points_4(){

        Point  exp = {{0xF5A1ADDCF2740D18, 0x586BE9D91E090D3B, 0xC0F1450D891FCE3A, 0xD6E069598E0C64D1},
                {0xABB54CC7E8EE63FF, 0x2F39929151D4823F, 0x41D64D857F9043E5, 0x9CED083529EADC99}};
        Point p1 = {{0x52b465135504e4ff, 0x97d573e36ed4385f, 0x72808056ee1e53f4, 0x74f1ce3c6ef778d6},
                       {0xd127a2980b361248, 0x7a8a2d551742bf50, 0x3aa92456dca573e0, 0xa416475ada0fd256}};
        Point p2 = {{0xc88923705f74ebe3, 0x0bc5ad357953ce83, 0x925ed15291736225, 0x34da6a5fe7e64ea7},
                       {0xe3597b1c29e91d01, 0xda517498d863708a, 0xd93a09e9ec7f98d0, 0xea775f9faa9a41e0}};
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        TEST_SCALAR_EQUALS(exp.x, p3.x)
        TEST_SCALAR_EQUALS(exp.y, p3.y)
}


void test_add_different_points_5(){

        Point exp = {{0xAF7CC5C9213E9DDD, 0xAB40F82D4E621D08, 0x29DC4C11603AC327, 0x28158CAAA9057D23},
                        {0x2625C5AB6BE6591E, 0x4946DB84DD4591B7, 0x5FD31AD41DF4D271, 0x4CB64D69F23E982D}};
        Point p1 = {{0x52b465135504e4ff, 0x97d573e36ed4385f, 0x72808056ee1e53f4, 0x74f1ce3c6ef778d6},
        			   {0xd127a2980b361248, 0x7a8a2d551742bf50, 0x3aa92456dca573e0, 0xa416475ada0fd256}};
        Point p2 = {{0x002b28f4bf894477, 0x1dfa93a9285b2f4f, 0xa02640eb88cb0cfd, 0x4f83a657a0ced2b1},
        			   {0xccaa9b5070c81633, 0x3e7be1ab6af1d6ca, 0xfb5c05a28b88b074, 0x9e1c64324941d002}};
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        TEST_SCALAR_EQUALS(exp.x, p3.x)
        TEST_SCALAR_EQUALS(exp.y, p3.y)
}

void test_add_different_points_6(){

        Point exp = {{0x1A1F2588CD8C7B99, 0x81749EA2B53B91ED, 0xEC180C0285E45304, 0x7BADB382A0797000},  
        				{0xC0FA98A3F7FCCEC2, 0x2CBA625E86C48F78, 0xEF4EBF083546CDFD, 0x1545DD745F9F38C9}};
        Point p1 = {{0x66631d7c87fa6b09, 0xea7fb259af59d80f, 0xa3b4f953c203dae6, 0x827bbf04097867c2},
                       {0x2e6693e32d6f7566, 0x89befd00d4990a7b, 0xefc0d777f026b087, 0x842a5d53da72e8d9}};
        Point p2 = {{0xC88923705F74EBE3, 0x0BC5AD357953CE83, 0x925ED15291736225, 0x34DA6A5FE7E64EA7},
                       {0xE3597B1C29E91D01, 0xDA517498D863708A, 0xD93A09E9EC7F98D0, 0xEA775F9FAA9A41E0}};
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        TEST_SCALAR_EQUALS(exp.x, p3.x)
        TEST_SCALAR_EQUALS(exp.y, p3.y)
}

void test_add_different_points_7(){

        Point exp = {{0xACB54C27F91ABE08, 0xC670890B1DD15B2E, 0x20B45E69A24D0BAF, 0xAAB2F658611D3D91},
						{0x472FF554140E8973, 0xD61AC4F6D3C8F019, 0x1FC3CF123E1FAE1B, 0x9994E302D89D67D7}};
        Point p1 = {{0xDFF8D267A3897561, 0x0733EF5B3F4CE687, 0x0E72E26F8ACFD6FA, 0x1A72C74ECF959A74},
                         {0xC5A446144AE742BD, 0x96D2F74DECE41AF7, 0x85575C3AB2990E69, 0xA206BAFD335B12CE}};
        Point p2 = {{0xB8ED1D28C6C0E474, 0xD65C19F210F45DE9, 0x6E7B7C5BBC85A579, 0x729ED24498A577A3},
                         {0x2B560859353A8E19, 0x7215799DDE7E7442, 0xEB1F919866D297FD, 0xA91DCE1C9336D628}};
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        TEST_SCALAR_EQUALS(exp.x, p3.x)
        TEST_SCALAR_EQUALS(exp.y, p3.y)
}

void test_add_different_points_8(){

        Point exp = { {0xE92BDDEDCAC4F9BC, 0x3D419B7E0330E39C, 0xA398F365F2EA7A0E, 0x5CBDF0646E5DB4EA},
                         {0xA5082628087264DA, 0xA813D0B813FDE7B5, 0xA3178D6D861A54DB, 0x6AEBCA40BA255960}};//7G
        Point p1 = { {0x8601F113BCE036F9, 0xB531C845836F99B0, 0x49344F85F89D5229, 0xF9308A019258C310},
                        {0x6CB9FD7584B8E672, 0x6500A99934C2231B, 0x0FE337E62A37F356, 0x388F7B0F632DE814}};//input: 3G
        Point p2 = {{0x74FA94ABE8C4CD13, 0xCC6C13900EE07584, 0x581E4904930B1404, 0xE493DBF1C10D80F3},
                       {0xCFE97BDC47739922, 0xD967AE33BFBDFE40, 0x5642E2098EA51448, 0x51ED993EA0D455B7}};//input: 4G
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        TEST_SCALAR_EQUALS(exp.x, p3.x)
        TEST_SCALAR_EQUALS(exp.y, p3.y)
}


void test_add_different_points_9(){

        Point exp = { {0x8601F113BCE036F9, 0xB531C845836F99B0, 0x49344F85F89D5229, 0xF9308A019258C310},
                         {0x6CB9FD7584B8E672, 0x6500A99934C2231B, 0x0FE337E62A37F356, 0x388F7B0F632DE814}};//3G
        Point p1 = {{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC},
                       {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}};//input: G
        Point p2 = { {0xABAC09B95C709EE5, 0x5C778E4B8CEF3CA7, 0x3045406E95C07CD8, 0xC6047F9441ED7D6D},
                        {0x236431A950CFE52A, 0xF7F632653266D0E1, 0xA3C58419466CEAEE, 0x1AE168FEA63DC339}};//input: 2G
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        TEST_SCALAR_EQUALS(exp.x, p3.x)
        TEST_SCALAR_EQUALS(exp.y, p3.y)
}


void test_add_different_points_10(){

        Point exp = {{0xA6F0146894AE298F,0x92880838C85D6AC0,0x44B9CC0DD5B7530A,0xB68B69A717D220F7},
                         {0x30731EBC29648EA0,0x96876FA217206006,0x86038570733AD6EA,0x863978F7A606A4DB}};
        Point p1 = {{0xFC2A15DF5570D417,0x5326EE294BB33D45,0x112C258B808B9BBF,0xE8AFB71910C1E2A0},
     	                 {0x0BDF710DFD3E1487,0x0877D5F8AED5F471,0x470ACD54EFBB5694,0x4F712F0FB74E7467}};
        Point p2 = {{0xE548DA3ADD7A673E,0x6E1ED105333CA92F,0x6FCB01B0963134ED,0xB1D8DABC9FF75A95},
                         {0x70F7C21D2DA3955A,0xC3387E96A0855167,0x6D1D5C598737AC50,0xA6503D7508A09DEA}};
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        TEST_SCALAR_EQUALS(exp.x, p3.x)
        TEST_SCALAR_EQUALS(exp.y, p3.y)
}

void test_add_different_points_11(){

        Point exp = {{0x2C0402C2BA51D4EE,0x8E46F1D66DF34FFF,0xC0DBCA779584BEBB,0xF9CDDDA817150CEB},
                         {0xE36EE91E4C9AA276,0x3300C29EF2E73BE9,0x4DD3481BDF98E16B,0xE68409628925B679}};
        Point p1 = {{0x3371D350150E96FE,0xB05892D6C6A46FBF,0x8BE659471C770FB5,0x0B00592A587731CA},                             
                        {0x36746F41DFFF09A0,0x43F2829888C191AA,0x1D536E704748CFFB,0x6BDC9456D4D089CD}};
        Point p2 = {{0x4DDE2837A3D3F5D5,0x24A57B5865FFE641,0x76C36C3E00CE0549,0x8A342ECD31232055},
                         {0x8DF92078D3E41E1B,0x6D9E52275389C032,0xA82D7CC580222E0A,0x1EF8189771D704AF}};
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        TEST_SCALAR_EQUALS(exp.x, p3.x)
        TEST_SCALAR_EQUALS(exp.y, p3.y)
}

void test_add_different_points_12(){

        Point exp ={{0x349A00A472818766, 0xDE6FC343A529DDC1, 0x5213373198D70837, 0xEC6BD14FA8E2FB5B},
                       {0xAD4C286ED3BBD982, 0x028ED2447305351B, 0xFAB0D54DA2DAEADD, 0x2A461C37BAF43625}};//{101,101,101,101}*G        
        Point p1 = {{0x8808CA5FBEB8B1E2, 0x0262B204EA0DDA76, 0xB6FFFFFCDDEB356B, 0x52DE253AFBB83870},
                         {0x961F40C08F8D21EA, 0x89686278002F03ED, 0x0FF834D738E421EA, 0x3A270D6FD36FB8DB}};//{1,1,1,1}*G
        Point p2 = {{0x7EFC785B6413FCDE, 0x835286041B32F6DB,0xB01F9F9EF1585B3D , 0xA243447B2453CD05},
                        {0x12E8F88A2EB8AFFA, 0x47DDFDA1012E2843, 0x10D38ECB5E1F58BA, 0x70091B837C926FFD}};//{100,100,100,100}*G
		Point p3;
		secp256k1_add_different_points(&p1,&p2,&p3);    
        TEST_SCALAR_EQUALS(exp.x, p3.x)
        TEST_SCALAR_EQUALS(exp.y, p3.y)
}

void test_add_different_points_13(){
        Point exp = {{0xED0669955270548A, 0x792C00A226005FC2,0x8449135B0C3D0C09 , 0x533210F4AFABD74E},
                        {0x7702D167DE9C09C3, 0xF3819AB954AB1E50, 0x234731C10D6768F6, 0xC7A955AABA76CBBF}};//{137,100,100,100}*G        
                       
        Point p1 = { {0xFE31C7E9D87FF33D, 0xDCB01C354959B10C, 0x7402FDC45A215E10, 0x62D14DAB4150BF49},
                        {0x35F5642483B25EAF, 0x01AA132967AB4722, 0x98088A1950EED0DB, 0x80FC06BD8CC5B010}};//{37,0,0,0}*G
        Point p2 = {{0x7EFC785B6413FCDE, 0x835286041B32F6DB,0xB01F9F9EF1585B3D , 0xA243447B2453CD05},
                        {0x12E8F88A2EB8AFFA, 0x47DDFDA1012E2843, 0x10D38ECB5E1F58BA, 0x70091B837C926FFD}};//{100,100,100,100}*G
		Point p3;		
		secp256k1_add_different_points(&p1,&p2,&p3);    
        TEST_SCALAR_EQUALS(exp.x, p3.x)
        TEST_SCALAR_EQUALS(exp.y, p3.y)
}

void test_add_asign_14(){
        //This test should fail because secp256k1_add_different_points adds only different points, but p1 == p2  
        Point exp ={{0x5D5F08989EA28C69, 0xF6F1EE9676AD413D, 0x1BADDE312DAFE40A, 0x5769B6AB9A471918},
					   {0x03033EFF68388768, 0x9570FF559C00BE05, 0x303618F7C87BC571, 0x0FB1CE68C891F32D}};//{2, 2,2,2}*G      
        Point p1 = {{0x8808CA5FBEB8B1E2, 0x0262B204EA0DDA76, 0xB6FFFFFCDDEB356B, 0x52DE253AFBB83870},
                         {0x961F40C08F8D21EA, 0x89686278002F03ED, 0x0FF834D738E421EA, 0x3A270D6FD36FB8DB}};//{1,1,1,1}*G
        Point p2 = {{0x8808CA5FBEB8B1E2, 0x0262B204EA0DDA76, 0xB6FFFFFCDDEB356B, 0x52DE253AFBB83870},
                         {0x961F40C08F8D21EA, 0x89686278002F03ED, 0x0FF834D738E421EA, 0x3A270D6FD36FB8DB}};//{1,1,1,1}*G
        Point p3;
        int exp_res = 1;             
		secp256k1_add_different_points(&p1,&p2,&p3);  
        int res =  secp256k1_compare_points(&p3,&exp);   //different points: 1, equal points: 0
		TEST_INT_EQUALS(exp_res,res)
}

//***************Point doubling*****************

void test_double_point_1(){
        Point a ={{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC}, 
                     {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}};//Generator Gx
        Point exp = {{0xABAC09B95C709EE5, 0x5C778E4B8CEF3CA7, 0x3045406E95C07CD8, 0xC6047F9441ED7D6D},
                     {0x236431A950CFE52A, 0xF7F632653266D0E1, 0xA3C58419466CEAEE, 0x1AE168FEA63DC339}};
        Point res;
        secp256k1_double_point(&a, &res);
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)
        
}

void test_double_point_2(){
        Point exp ={{0x5D5F08989EA28C69, 0xF6F1EE9676AD413D, 0x1BADDE312DAFE40A, 0x5769B6AB9A471918},
					   {0x03033EFF68388768, 0x9570FF559C00BE05, 0x303618F7C87BC571, 0x0FB1CE68C891F32D}};//{2, 2,2,2}*G
        Point a  = {{0x8808CA5FBEB8B1E2, 0x0262B204EA0DDA76, 0xB6FFFFFCDDEB356B, 0x52DE253AFBB83870},
                         {0x961F40C08F8D21EA, 0x89686278002F03ED, 0x0FF834D738E421EA, 0x3A270D6FD36FB8DB}};//{1,1,1,1}*G
        Point res;
        secp256k1_double_point(&a, &res);
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)
        
}

void test_double_point_3(){

        Point a ={{0xE92BDDEDCAC4F9BC, 0x3D419B7E0330E39C, 0xA398F365F2EA7A0E,0x5CBDF0646E5DB4EA},
					   {0xA5082628087264DA,0xA813D0B813FDE7B5,0xA3178D6D861A54DB,0x6AEBCA40BA255960}};//7*G
   
        Point exp  = {{0xE49B241A60E823E4,0x26AA7B63678949E6,0xFD64E67F07D38E32,0x499FDF9E895E719C },
                         {0xC65F40D403A13F5B,0x464279C27A3F95BC,0x90F044E4A7B3D464,0xCAC2F6C4B54E8551}};//14*G
        Point res;
        secp256k1_double_point(&a, &res);
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)
        
}

/** **********************************Compare points ********************/

void test_compare_1(){
        Point a = {{1,1,1,1},{1,1,1,1}};
        Point b = {{1,1,1,1},{1,1,1,1}};
        int exp = 0; 
        int res = secp256k1_compare_points(&a, &b);
        TEST_INT_EQUALS(exp,res)
}

void test_compare_2(){
        Point a = {{8,1,1,1},{1,1,1,1}};
        Point b = {{1,1,1,1},{1,1,1,1}};
        int exp = 1; 
        int res = secp256k1_compare_points(&a, &b);
        TEST_INT_EQUALS(exp,res)
}


void test_compare_3(){
        Point a = {{1,8,1,1},{1,1,1,1}};
        Point b = {{1,1,1,1},{1,1,1,1}};
        int exp = 1; 
        int res = secp256k1_compare_points(&a, &b);
        TEST_INT_EQUALS(exp,res)
}

void test_compare_4(){
        Point a = {{1,1,8,1},{1,1,1,1}};
        Point b = {{1,1,1,1},{1,1,1,1}};
        int exp = 1; 
        int res = secp256k1_compare_points(&a, &b);
        TEST_INT_EQUALS(exp,res)
}

void test_compare_5(){
        Point a = {{1,1,1,8},{1,1,1,1}};
        Point b = {{1,1,1,1},{1,1,1,1}};
        int exp = 1; 
        int res = secp256k1_compare_points(&a, &b);
        TEST_INT_EQUALS(exp,res)
}

void test_compare_6(){
        Point a = {{1,1,1,1},{8,1,1,1}};
        Point b = {{1,1,1,1},{1,1,1,1}};
        int exp = 1; 
        int res = secp256k1_compare_points(&a, &b);
        TEST_INT_EQUALS(exp,res)
}

void test_compare_7(){
        Point a = {{1,1,1,1},{1,8,1,1}};
        Point b = {{1,1,1,1},{1,1,1,1}};
        int exp = 1; 
        int res = secp256k1_compare_points(&a, &b);
        TEST_INT_EQUALS(exp,res)
}

void test_compare_8(){
        Point a = {{1,1,1,1},{1,1,8,1}};
        Point b = {{1,1,1,1},{1,1,1,1}};
        int exp = 1; 
        int res = secp256k1_compare_points(&a, &b);
        TEST_INT_EQUALS(exp,res)
}

void test_compare_9(){
        Point a = {{1,1,1,1},{1,1,1,8}};
        Point b = {{1,1,1,1},{1,1,1,1}};
        int exp = 1; 
        int res = secp256k1_compare_points(&a, &b);
        TEST_INT_EQUALS(exp,res)
}

/********************************* generator multiplication *****************************************************/

void test_generator_mul_1(){
        Scalar k = {  0x20653B12448E00FD, 0xCAE8E2EFD506619D, 0xA21CF70BA2B3A52F, 0xA302FDA67E896BA4};
        Point exp ={ {0x51205AF4CAA22825, 0xDA22AB7288CEC20A, 0x92D98A24047BB8B4, 0x2C3143909EC74F67},
						{0x9CF18D0C261F9F13, 0x7029736F1B7E8D65, 0xAE4CB2D7780770DA, 0x9F0C1DA1C1052260}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)
}


void test_generator_mul_2(){
        Scalar k = {37, 0,0,0}; 
        Point exp ={ {0xFE31C7E9D87FF33D, 0xDCB01C354959B10C, 0x7402FDC45A215E10, 0x62D14DAB4150BF49},
                        {0x35F5642483B25EAF, 0x01AA132967AB4722, 0x98088A1950EED0DB, 0x80FC06BD8CC5B010}};//{37,0,0,0}*G
        Point res;
		secp256k1_generator_mul(k, &res);    
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)

}

void test_generator_mul_3(){
        Scalar k = {2, 2,2,2}; 
        Point exp ={{0x5D5F08989EA28C69, 0xF6F1EE9676AD413D, 0x1BADDE312DAFE40A, 0x5769B6AB9A471918},
					   {0x03033EFF68388768, 0x9570FF559C00BE05, 0x303618F7C87BC571, 0x0FB1CE68C891F32D}};//{2, 2,2,2}*G
        Point res;
        
		secp256k1_generator_mul(k, &res);    
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)

}

void test_generator_mul_4(){
        Scalar k = {100, 100,100,100};
        Point exp ={ {0x7EFC785B6413FCDE, 0x835286041B32F6DB,0xB01F9F9EF1585B3D , 0xA243447B2453CD05},
                        {0x12E8F88A2EB8AFFA, 0x47DDFDA1012E2843, 0x10D38ECB5E1F58BA, 0x70091B837C926FFD}};//{100,100,100,100}*G
        Point res;
		secp256k1_generator_mul(k, &res);    
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)
}

void test_generator_mul_5(){
        Scalar k = {700, 700,700,700};
        Point exp ={{0x842749DC71E8544F, 0x514E3415C90E1005, 0x9A820F0875E01A13, 0x09234DAF59273438},
					   {0x5235E8340AFEFBB6, 0x208F1A8C91710890, 0x840B6F57A304EC53, 0x3A04FCF4CD72FDA6}};//{700, 700,700,700}*G
        Point res;
		secp256k1_generator_mul(k, &res);    
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)
}

void test_generator_mul_6(){
        Scalar k = {101, 101,101,101};
        Point exp ={{0x349A00A472818766, 0xDE6FC343A529DDC1, 0x5213373198D70837, 0xEC6BD14FA8E2FB5B},
                       {0xAD4C286ED3BBD982, 0x028ED2447305351B, 0xFAB0D54DA2DAEADD, 0x2A461C37BAF43625}};//{101,101,101,101}*G
        Point res;
		secp256k1_generator_mul(k, &res); 
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)
}


void test_generator_mul_7(){
        Scalar k = {137, 100,100,100};
        Point exp ={ {0xED0669955270548A, 0x792C00A226005FC2,0x8449135B0C3D0C09 , 0x533210F4AFABD74E},
                        {0x7702D167DE9C09C3, 0xF3819AB954AB1E50, 0x234731C10D6768F6, 0xC7A955AABA76CBBF}};//{137,100,100,100}*G
        Point res;
		secp256k1_generator_mul(k, &res); 
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)
}

void test_generator_mul_8(){
        Scalar k = {0xBFD25E8CD0364140, 0xBAAEDCE6AF48A03B, 0xfffffffffffffffe, 0xffffffffffffffff};// order n - 1
        Point exp ={ {0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC},
                        {0x63B82F6F04EF2777, 0x02E84BB7597AABE6, 0xA25B0403F1EEF757, 0xB7C52588D95C3B9A}};
        Point res;
		secp256k1_generator_mul(k, &res);    
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)
}


void test_generator_mul_9(){
        Scalar k = {0xBFD25E8CD0364166, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF}; //order n + 25
        Point exp ={ {0xFE31C7E9D87FF33D, 0xDCB01C354959B10C, 0x7402FDC45A215E10, 0x62D14DAB4150BF49},
                        {0x35F5642483B25EAF, 0x01AA132967AB4722, 0x98088A1950EED0DB, 0x80FC06BD8CC5B010} };
        Point res;
		secp256k1_generator_mul(k, &res);    
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)
}

void test_generator_mul_10(){
        Scalar k = {1, 2, 3, 4};
        Point exp ={ {0xA103B5E4937A62DD, 0xB1A1A19D87AC52F5, 0x7D29A027D305B1F9, 0xE75010603E253C46},
         				{0x629856CC38AA1D1A, 0x188FF68F4EFDD8D9, 0x317C39233F752C20, 0x63DAF0B554057290} };
        Point res;
		secp256k1_generator_mul(k, &res); 
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y) 
}

void test_generator_mul_11(){
        Scalar k = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Point exp ={ {0x15714AA4B56606AF, 0x6B4A22095F894F47, 0x5F9E3DF9F69D7F35, 0x9166C289B9F905E5},
         				{0x1099AF98499255E7, 0x94E214F06C93FD09, 0xCFF9E16B66D809BE, 0xF181EB966BE4ACB5}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y) 

}

void test_generator_mul_12(){
        Scalar k = {0x402da1732fc9bebe, 0x4551231950b75fc4, 1, 0 };//ffffffffffffffff - order n
        Point exp ={ {0x15714AA4B56606AF, 0x6B4A22095F894F47, 0x5F9E3DF9F69D7F35, 0x9166C289B9F905E5},
         				{0x1099AF98499255E7, 0x94E214F06C93FD09, 0xCFF9E16B66D809BE, 0xF181EB966BE4ACB5}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y) 

}

void test_generator_mul_13(){
        Scalar k = {0x402da1722fc9baee, 0x4551231950b75fc4, 1, 0}; //p -n
        Point exp ={ {0x65E902417E7AF914, 0xBC3B5224BCDD4B4B, 0x5C0B8B853B6939AA, 0xB42B34A974823871 },
         				{0x936138086AC129E9, 0x87404DCA2F648560, 0x7FA170896D939C3B, 0xC1064CE5DFB9E024}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y) 

}

void test_generator_mul_14(){
        Scalar k = {0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};//p
        Point exp ={ {0x65E902417E7AF914, 0xBC3B5224BCDD4B4B, 0x5C0B8B853B6939AA, 0xB42B34A974823871 },
         				{0x936138086AC129E9, 0x87404DCA2F648560, 0x7FA170896D939C3B, 0xC1064CE5DFB9E024}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y) 
}

void test_generator_mul_15(){
        Scalar k = {0xBFD25E8CD0364140, 0xBAAEDCE6AF48A03B, 0xfffffffffffffffe, 0xffffffffffffffff};//n-1
        Point exp ={ {0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC },
         				{0x63b82f6f04ef2777,0x02e84bb7597aabe6,0xa25b0403f1eef757,0xb7c52588d95c3b9a}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)         
}

void test_generator_mul_16(){
        Scalar k = {0x35db29a206321725, 0xe774e7f9a47e2c20, 0x6a94f8114701e7c8, 0x18e14a7b6a307f42};
        Point exp ={ {0xad8a04887e5b2352, 0xb53f53e486d8511d, 0x2fe83c1af1a8403c, 0x50863ad64a87ae8a },
         				{0xF2EE187E9C582BA6,0xBC11A1DF38855ED6,0xFA9E77237716103A,0x2CD470243453A299}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)         
}

void test_generator_mul_17(){
        Scalar k = {0x8F643232DD1B2F45, 0x06C76E9617C917DF, 0x8E8212A8D001FA2F, 0xBE958E7C2CF53555};
        Point exp ={ {0xDE6F16004425F630, 0x6B7C284F42777941, 0x4623A201C0BA8FCB, 0x485B7911BDDC1841 },
         				{0x743AFF5DF16FF4FE,0x42C52DBDC160DADD,0x50DDE4DA872FD9E8,0x00B3906863E416D1}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)         


}

void test_generator_mul_18(){
        Scalar k = {0x35db29a206321725, 0xe774e7f9a47e2c20, 0x6a94f8114701e7c8, 0x18e14a7b6a307f42};
        Point exp ={ {0xad8a04887e5b2352, 0xb53f53e486d8511d, 0x2fe83c1af1a8403c, 0x50863ad64a87ae8a },
                        {0xF2EE187E9C582BA6,0xBC11A1DF38855ED6,0xFA9E77237716103A,0x2CD470243453A299}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)         

}

void test_generator_mul_19(){
        Scalar k = {0x0, 0xe774e7f9a47e2c20, 0x6a94f8114701e7c8, 0x18e14a7b6a307f42};
        Point exp ={ {0x55BA44045BFC16A5, 0x87981736082C416C, 0x1BCBC6B505AD7AAF, 0xBF26E545FCD77D76},
                        {0x3BDE5E5940680D06, 0x1A716D33B129C664, 0xC5E29CB5A16DA775, 0x345DD848AC31807E}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)     

}

void test_generator_mul_20(){
        Scalar k = {0x35db29a206321725,0,0,0};
        Point exp ={ {0x432990D34DB0A38A, 0xEF7F847693AA51AE, 0xB802EEFF511EA530, 0x0D6E6A89A30CD122},
                        {0xBB3C60F0973B528C, 0x9B8D9D51156B63F8, 0x511498A93BEC1213, 0x8104A89209EBB999}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)     
}


void test_generator_mul_21(){ 
        Scalar k = {0xc2c2529eb3399b3c,0x377f8d82f883816f,0x358a73ec4cda12d9,0xf412548fa1f37eac};
        Point exp ={ {0x52b465135504e4ff, 0x97d573e36ed4385f, 0x72808056ee1e53f4, 0x74f1ce3c6ef778d6},
                        {0xd127a2980b361248, 0x7a8a2d551742bf50, 0x3aa92456dca573e0, 0xa416475ada0fd256}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)  

}


void test_generator_mul_22(){ 
        Scalar k = {0x2a26a877a58eabd5,0x0e3a8e80117f2dc3,0x9c0f6c9528ab8379,0x255bf055824c2907};
        Point exp ={ {0x002b28f4bf894477, 0x1dfa93a9285b2f4f, 0xa02640eb88cb0cfd, 0x4f83a657a0ced2b1},
                        {0xccaa9b5070c81633, 0x3e7be1ab6af1d6ca, 0xfb5c05a28b88b074, 0x9e1c64324941d002}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)  

}


void test_generator_mul_23(){  
        Scalar k = {0x98667f65db5f321a,0xb5584a8c2222519d,0x3b030056141d8837,0x4ec93408ab2fa6a9};
        Point exp ={ {0xc88923705f74ebe3, 0x0bc5ad357953ce83, 0x925ed15291736225, 0x34da6a5fe7e64ea7},
                        {0xe3597b1c29e91d01, 0xda517498d863708a, 0xd93a09e9ec7f98d0, 0xea775f9faa9a41e0}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)  

}


void test_generator_mul_24(){  
        Scalar k = {0xdf940462c4a9ed4e,0x5830f5d6dddb38c9,0xd0c1784e0b1347a2,0x05a44f99903ef13c};
        Point exp ={{0x66631d7c87fa6b09, 0xea7fb259af59d80f, 0xa3b4f953c203dae6, 0x827bbf04097867c2},
                       {0x2e6693e32d6f7566, 0x89befd00d4990a7b, 0xefc0d777f026b087, 0x842a5d53da72e8d9}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)  

}


void test_generator_mul_25(){   
        Scalar k = {0x20816400a4117723,0x8ed984970d08061e,0x9c4a64595f67c93d,0x90518c8f7e609450};
        Point exp ={{0x57ee45bbceba551b,0x9327b8047643b458,0xf8b9038217d65ef0,0xc0880c2b124e1bc1},
                       {0x29f00f6a71b300ec,0xb8250d73398ebd19,0x8ca4995c0f2348f1,0x4a6e48d3fd76af13}};
        Point res;
		secp256k1_generator_mul(k, &res); 
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)
}


void test_generator_mul_26(){
     Scalar k = {0xFFFFFFFFFFFFFFFF,0xFFFFFFFFFFFFFFFF,0xFFFFFFFFFFFFFFFF,0xFFFFFFFFFFFFFFFF};
     //s gets internally reduced to 0x14551231950b75fc4402da1732fc9bebe without affecting the original scalar
     Point  p;
     Point exp = {{0x15714AA4B56606AF,0x6B4A22095F894F47,0x5F9E3DF9F69D7F35,0x9166C289B9F905E5},
                     {0x1099AF98499255E7,0x94E214F06C93FD09,0xCFF9E16B66D809BE,0xF181EB966BE4ACB5}};
     secp256k1_generator_mul(k, &p);
     TEST_SCALAR_EQUALS(exp.x, p.x)
     TEST_SCALAR_EQUALS(exp.y, p.y)  
}

void test_generator_mul_27(){
     Scalar k = {0x402da1732fc9bebe, 0x4551231950b75fc4, 1};//0x14551231950b75fc4402da1732fc9bebe
     Point  p;
     Point exp = {{0x15714AA4B56606AF,0x6B4A22095F894F47,0x5F9E3DF9F69D7F35,0x9166C289B9F905E5},
                     {0x1099AF98499255E7,0x94E214F06C93FD09,0xCFF9E16B66D809BE,0xF181EB966BE4ACB5}};
     secp256k1_generator_mul(k, &p);
     TEST_SCALAR_EQUALS(exp.x, p.x)
     TEST_SCALAR_EQUALS(exp.y, p.y)  
}




void test_generator_mul_30(){
     Scalar k = {0xBFD25E8CD0364142, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF};//n+1
     Point  p;
     Point exp = {{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC}, 
                     {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}};//Generator Gx
     secp256k1_generator_mul(k, &p);
     TEST_SCALAR_EQUALS(exp.x, p.x)
     TEST_SCALAR_EQUALS(exp.y, p.y)      
}


void test_generator_mul_31(){
     Scalar k = {0,0,0,0x0FFFFFFFFFFFFFFF};
     Point  p;
     Point exp = {{0x4DDE2837A3D3F5D5,0x24A57B5865FFE641,0x76C36C3E00CE0549,0x8A342ECD31232055},
     				 {0x8DF92078D3E41E1B,0x6D9E52275389C032,0xA82D7CC580222E0A,0x1EF8189771D704AF}};
     secp256k1_generator_mul(k, &p);
     TEST_SCALAR_EQUALS(exp.x, p.x)
     TEST_SCALAR_EQUALS(exp.y, p.y) 
}


void test_generator_mul_32(){
		 Scalar k = {0,0,0xFFFFFFFFFFFFFFFF,0};
		 Point  p;
		 Point exp = {{0x3371D350150E96FE,0xB05892D6C6A46FBF,0x8BE659471C770FB5,0x0B00592A587731CA},                             
		  				 {0x36746F41DFFF09A0,0x43F2829888C191AA,0x1D536E704748CFFB,0x6BDC9456D4D089CD}};
		 secp256k1_generator_mul(k, &p);
		 TEST_SCALAR_EQUALS(exp.x, p.x)
		 TEST_SCALAR_EQUALS(exp.y, p.y) 
}

void test_generator_mul_33(){
     Scalar k = {0,0,0xFFFFFFFFFFFFFFFF,0x0FFFFFFFFFFFFFFF};
     Point  p;
     Point exp = {{0x2C0402C2BA51D4EE,0x8E46F1D66DF34FFF,0xC0DBCA779584BEBB,0xF9CDDDA817150CEB},
     				 {0xE36EE91E4C9AA276,0x3300C29EF2E73BE9,0x4DD3481BDF98E16B,0xE68409628925B679}};

     secp256k1_generator_mul(k, &p);
     TEST_SCALAR_EQUALS(exp.x, p.x)
     TEST_SCALAR_EQUALS(exp.y, p.y) 
}




void test_point_mul_1(){  
        Scalar k = {0x20816400a4117723,0x8ed984970d08061e,0x9c4a64595f67c93d,0x90518c8f7e609450};
        Point p ={{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC},
                             {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}}; //generator G
        Point exp ={ {0x57ee45bbceba551b,0x9327b8047643b458,0xf8b9038217d65ef0,0xc0880c2b124e1bc1},
                                   {0x29f00f6a71b300ec,0xb8250d73398ebd19,0x8ca4995c0f2348f1,0x4a6e48d3fd76af13}};
        Point res;
		secp256k1_point_mul(&p, k, &res);  ;    
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)

}




void test_point_mul_2(){

        Scalar k = {0x35db29a206321725, 0xe774e7f9a47e2c20, 0x6a94f8114701e7c8, 0x18e14a7b6a307f42};
        Point p ={{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC},
                             {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}}; //generator G
        Point exp ={ {0xad8a04887e5b2352, 0xb53f53e486d8511d, 0x2fe83c1af1a8403c, 0x50863ad64a87ae8a },
                                   {0xF2EE187E9C582BA6,0xBC11A1DF38855ED6,0xFA9E77237716103A,0x2CD470243453A299}};
        Point res;
		secp256k1_point_mul(&p, k, &res);    
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)
}

void test_point_mul_3(){
 
        Scalar k = {0x0, 0xe774e7f9a47e2c20, 0x6a94f8114701e7c8, 0x18e14a7b6a307f42};
        Point p ={{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC},
                             {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}}; //generator G

        Point exp ={ {0x55BA44045BFC16A5, 0x87981736082C416C, 0x1BCBC6B505AD7AAF, 0xBF26E545FCD77D76},
                        {0x3BDE5E5940680D06, 0x1A716D33B129C664, 0xC5E29CB5A16DA775, 0x345DD848AC31807E}};
        Point res;
		secp256k1_point_mul(&p, k, &res);    
        TEST_SCALAR_EQUALS(exp.x, res.x)
        TEST_SCALAR_EQUALS(exp.y, res.y)

}







void test_point_mul_asign_1(){
        Scalar k = {0x35db29a206321725, 0xe774e7f9a47e2c20, 0x6a94f8114701e7c8, 0x18e14a7b6a307f42}; 
        Point exp ={{0xad8a04887e5b2352, 0xb53f53e486d8511d, 0x2fe83c1af1a8403c, 0x50863ad64a87ae8a},
                       {0xF2EE187E9C582BA6, 0xBC11A1DF38855ED6, 0xFA9E77237716103A, 0x2CD470243453A299}};
        Point p ={{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC},
        			   {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}};//input: G
		secp256k1_point_mul_asign(&p,k);    
        TEST_SCALAR_EQUALS(exp.x, p.x)
        TEST_SCALAR_EQUALS(exp.y, p.y)
}

void test_point_mul_asign_2(){
        Scalar k = {0x0, 0xe774e7f9a47e2c20, 0x6a94f8114701e7c8, 0x18e14a7b6a307f42};
        Point p ={{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC},
                             {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}}; //generator G
        Point exp ={ {0x55BA44045BFC16A5, 0x87981736082C416C, 0x1BCBC6B505AD7AAF, 0xBF26E545FCD77D76},
                                   {0x3BDE5E5940680D06, 0x1A716D33B129C664, 0xC5E29CB5A16DA775, 0x345DD848AC31807E}};
		secp256k1_point_mul_asign(&p,k);    
        TEST_SCALAR_EQUALS(exp.x, p.x)
        TEST_SCALAR_EQUALS(exp.y, p.y)
}


void test_point_mul_asign_3(){
        Scalar k = {0x35db29a206321725,0,0,0};
        Point exp = {{0x432990D34DB0A38A, 0xEF7F847693AA51AE, 0xB802EEFF511EA530, 0x0D6E6A89A30CD122}, 
        				 {0xBB3C60F0973B528C, 0x9B8D9D51156B63F8, 0x511498A93BEC1213, 0x8104A89209EBB999}};
        Point p = {{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC},
                         {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}};// G
		secp256k1_point_mul_asign(&p,k); 
        TEST_SCALAR_EQUALS(exp.x, p.x)
        TEST_SCALAR_EQUALS(exp.y, p.y)
}


 

void test_point_mul_asign_4(){
        Scalar k = {0x35db29a206321724, 0xe774e7f9a47e2c1f, 0x6a94f8114701e7c7, 0x18e14a7b6a307f41};
        Point exp = {{0x15B6102F43228506, 0x2E4EB529ED776E92, 0x10DAE4C62A4520DD, 0x4D696DF0B0F1C4C1},
                         {0x97A110D0A2682360, 0xDE221EA11AE3A483, 0x0769C4B534C00831, 0xD9C5BF1AC94B5C7F}};
        Point p = {{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC},
                         {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}};//G
		secp256k1_point_mul_asign(&p,k); 
        TEST_SCALAR_EQUALS(exp.x, p.x)
        TEST_SCALAR_EQUALS(exp.y, p.y)        
}


void test_point_mul_asign_5(){
        Scalar k = {2, 0, 0 ,0};
        Point exp ={{0x5D5F08989EA28C69, 0xF6F1EE9676AD413D, 0x1BADDE312DAFE40A, 0x5769B6AB9A471918},
					   {0x03033EFF68388768, 0x9570FF559C00BE05, 0x303618F7C87BC571, 0x0FB1CE68C891F32D}};//{2, 2,2,2}*G
        Point p = {{0x8808CA5FBEB8B1E2, 0x0262B204EA0DDA76, 0xB6FFFFFCDDEB356B, 0x52DE253AFBB83870},
                         {0x961F40C08F8D21EA, 0x89686278002F03ED, 0x0FF834D738E421EA, 0x3A270D6FD36FB8DB}};//{1,1,1,1}*G
		secp256k1_point_mul_asign(&p,k); 
        TEST_SCALAR_EQUALS(exp.x, p.x)
        TEST_SCALAR_EQUALS(exp.y, p.y)        

}




void test_point_mul_asign_6(){
        Scalar k = {7, 0, 0 ,0};
		Point exp ={{0x842749DC71E8544F, 0x514E3415C90E1005, 0x9A820F0875E01A13, 0x09234DAF59273438},
					   {0x5235E8340AFEFBB6, 0x208F1A8C91710890, 0x840B6F57A304EC53, 0x3A04FCF4CD72FDA6}};//{700, 700,700,700}*G
		Point p ={ {0x7EFC785B6413FCDE, 0x835286041B32F6DB,0xB01F9F9EF1585B3D , 0xA243447B2453CD05},
                        {0x12E8F88A2EB8AFFA, 0x47DDFDA1012E2843, 0x10D38ECB5E1F58BA, 0x70091B837C926FFD}};//{100,100,100,100}*G
		secp256k1_point_mul_asign(&p,k); 
        TEST_SCALAR_EQUALS(exp.x, p.x)
        TEST_SCALAR_EQUALS(exp.y, p.y)        
}




void test_is_point_on_curve_1(){
        Point p = {{0x8808CA5FBEB8B1E2, 0x0262B204EA0DDA76, 0xB6FFFFFCDDEB356B, 0x52DE253AFBB83870},
                         {0x961F40C08F8D21EA, 0x89686278002F03ED, 0x0FF834D738E421EA, 0x3A270D6FD36FB8DB}};
        int exp = 0;
        int res = secp256k1_is_point_on_curve(&p);
        TEST_INT_EQUALS(exp,res) 
}
void test_is_point_on_curve_2(){
        Point p = {{0x9808CA5FBEB8B1E2, 0x0262B204EA0DDA76, 0xB6FFFFFCDDEB356B, 0x52DE253AFBB83870},
                         {0x961F40C08F8D21EA, 0x89686278002F03ED, 0x0FF834D738E421EA, 0x3A270D6FD36FB8DB}};
        int exp = 1;
        int res = secp256k1_is_point_on_curve(&p);
        TEST_INT_EQUALS(exp,res) 
}


void test_is_point_on_curve_3(){
        Point p ={ {0x7EFC785B6413FCDE, 0x835286041B32F6DB,0xB01F9F9EF1585B3D , 0xA243447B2453CD05},
                        {0x12E8F88A2EB8AFFA, 0x47DDFDA1012E2843, 0x10D38ECB5E1F58BA, 0x70091B837C926FFD}};
        int exp = 0;
        int res = secp256k1_is_point_on_curve(&p);
        TEST_INT_EQUALS(exp,res) 
}

void test_is_point_on_curve_4(){
        Point p ={ {0x7EFC785B6413FCDE, 0x835286041B32F6DB,0xB01F9F9EF1585B3D , 0xA243447B2453CD05},
                        {0xF2E8F88A2EB8AFFA, 0x47DDFDA1012E2843, 0x10D38ECB5E1F58BA, 0x70091B837C926FFD}};
        int exp = 1;
        int res = secp256k1_is_point_on_curve(&p);
        TEST_INT_EQUALS(exp,res) 
}

void test_is_point_on_curve_5(){
        Point p ={{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC}, 
                     {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}};//Generator Gx
        int exp = 0;
        int res = secp256k1_is_point_on_curve(&p);
        TEST_INT_EQUALS(exp,res); 
}

void test_is_point_on_curve_6(){
        Point p ={{0, 0, 0, 0}, 
                     {0xEECB4B6FBA9360DC, 0x38ED44E3932A7179, 0x0727CD69B4A7333D, 0x8F537EEFDFC1606A}}; 
        int exp = 1;
        int res = secp256k1_is_point_on_curve(&p);
        TEST_INT_EQUALS(exp,res); 
}


void test_is_point_on_curve_7(){
        Point p ={{0, 0, 0, 0}, 
                     {0x1134B48F456C9B53, 0xC712BB1C6CD58E86, 0xF8D832964B58CCC2, 0x70AC8110203E9F95}};
        int exp = 1;
        int res = secp256k1_is_point_on_curve(&p);
        TEST_INT_EQUALS(exp,res);  
}

void test_secp256k1_calculate_y_coordinates_from_x_1(){
        Scalar x = {0xFE31C7E9D87FF33D, 0xDCB01C354959B10C, 0x7402FDC45A215E10, 0x62D14DAB4150BF49};
        Scalar exp_y = {0x35F5642483B25EAF, 0x01AA132967AB4722, 0x98088A1950EED0DB, 0x80FC06BD8CC5B010};
        Scalar even;
        Scalar odd;
        secp256k1_calculate_y_coordinates_from_x(x, even, odd);
        TEST_SCALAR_EQUALS(exp_y, odd)
}

void test_secp256k1_calculate_y_coordinates_from_x_2(){
        Scalar x = {0x4DDE2837A3D3F5D5,0x24A57B5865FFE641,0x76C36C3E00CE0549,0x8A342ECD31232055};
        Scalar exp_y = {0x8DF92078D3E41E1B,0x6D9E52275389C032,0xA82D7CC580222E0A,0x1EF8189771D704AF};
        Scalar even;
        Scalar odd;
        secp256k1_calculate_y_coordinates_from_x(x, even, odd);
        TEST_SCALAR_EQUALS(exp_y, odd)
}

void test_secp256k1_calculate_y_coordinates_from_x_3(){
        Scalar x = {0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC};
        Scalar exp_y = {0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465};//G
        Scalar even;
        Scalar odd;
        secp256k1_calculate_y_coordinates_from_x(x, even, odd);
        TEST_SCALAR_EQUALS(exp_y, even)
}

void test_secp256k1_calculate_y_coordinates_from_x_4(){
        Scalar x = {0x842749DC71E8544F, 0x514E3415C90E1005, 0x9A820F0875E01A13, 0x09234DAF59273438};
		Scalar exp_y =  {0x5235E8340AFEFBB6, 0x208F1A8C91710890, 0x840B6F57A304EC53, 0x3A04FCF4CD72FDA6};
        Scalar even;
        Scalar odd;
        secp256k1_calculate_y_coordinates_from_x(x, even, odd);
        TEST_SCALAR_EQUALS(exp_y, even)
}

 
                     
void test_secp256k1_calculate_y_coordinates_from_x_5(){
        Scalar x = {0x15714AA4B56606AF,0x6B4A22095F894F47,0x5F9E3DF9F69D7F35,0x9166C289B9F905E5};
		Scalar exp_y =  {0x1099AF98499255E7,0x94E214F06C93FD09,0xCFF9E16B66D809BE,0xF181EB966BE4ACB5};
        Scalar even;
        Scalar odd;
        secp256k1_calculate_y_coordinates_from_x(x, even, odd);
        TEST_SCALAR_EQUALS(exp_y, odd)
}                     
  
 
        				                    
void test_secp256k1_calculate_y_coordinates_from_x_6(){
        Scalar x = {0x98C13CA84DB6A392, 0xC832C50E9B1EEF8A, 0xDEF2B65EE8C8B17D, 0x6D0A80195FF48CC4 };
		Scalar exp_y =  {0xA17A800BEE319F96,0xBBEAB4B55A15F295,0xEC17A721F0F0BAF8,0x6B47A61FD59BF8D0} ;
        Scalar even;
        Scalar odd;
        secp256k1_calculate_y_coordinates_from_x(x, even, odd);
        TEST_SCALAR_EQUALS(exp_y, even)
} 


void test_secp256k1_keypair_from_private_key_1(){ 
        Scalar exp_prk = {0x2a26a877a58eabd5,0x0e3a8e80117f2dc3,0x9c0f6c9528ab8379,0x255bf055824c2907};
        Point  exp_puk ={ {0x002b28f4bf894477, 0x1dfa93a9285b2f4f, 0xa02640eb88cb0cfd, 0x4f83a657a0ced2b1},
                        {0xccaa9b5070c81633, 0x3e7be1ab6af1d6ca, 0xfb5c05a28b88b074, 0x9e1c64324941d002}};
        KeyPair kp={0x2a26a877a58eabd5,0x0e3a8e80117f2dc3,0x9c0f6c9528ab8379,0x255bf055824c2907};
		secp256k1_keypair_from_private_key(&kp); 
		Point p = kp.public_key;
        TEST_SCALAR_EQUALS(exp_prk, kp.private_key)
        TEST_SCALAR_EQUALS(exp_puk.x, p.x)
        TEST_SCALAR_EQUALS(exp_puk.y, p.y) 

}


void test_secp256k1_keypair_from_private_key_2(){  
        Scalar exp_prk = {0x98667f65db5f321a,0xb5584a8c2222519d,0x3b030056141d8837,0x4ec93408ab2fa6a9};
        Point  exp_puk ={ {0xc88923705f74ebe3, 0x0bc5ad357953ce83, 0x925ed15291736225, 0x34da6a5fe7e64ea7},
                        {0xe3597b1c29e91d01, 0xda517498d863708a, 0xd93a09e9ec7f98d0, 0xea775f9faa9a41e0}};
        KeyPair kp; 
        kp.private_key[0] = 0x98667f65db5f321a;
        kp.private_key[1] = 0xb5584a8c2222519d;
        kp.private_key[2] = 0x3b030056141d8837;
        kp.private_key[3] = 0x4ec93408ab2fa6a9;
		secp256k1_keypair_from_private_key(&kp); 
        TEST_SCALAR_EQUALS(exp_prk, kp.private_key)
        TEST_SCALAR_EQUALS(exp_puk.x, kp.public_key.x)
        TEST_SCALAR_EQUALS(exp_puk.y, kp.public_key.y) 

}


void test_secp256k1_keypair_from_private_key_3(){  
        Scalar exp_prk = {0xdf940462c4a9ed4e,0x5830f5d6dddb38c9,0xd0c1784e0b1347a2,0x05a44f99903ef13c};
        Point  exp_puk ={{0x66631d7c87fa6b09, 0xea7fb259af59d80f, 0xa3b4f953c203dae6, 0x827bbf04097867c2},
                       {0x2e6693e32d6f7566, 0x89befd00d4990a7b, 0xefc0d777f026b087, 0x842a5d53da72e8d9}};
        KeyPair kp ={0xdf940462c4a9ed4e,0x5830f5d6dddb38c9,0xd0c1784e0b1347a2,0x05a44f99903ef13c,0,0,0,0,0,0,0,0};
		secp256k1_keypair_from_private_key(&kp); 
        TEST_SCALAR_EQUALS(exp_prk, kp.private_key)
        TEST_SCALAR_EQUALS(exp_puk.x, kp.public_key.x)
        TEST_SCALAR_EQUALS(exp_puk.y, kp.public_key.y) 

}


void test_secp256k1_keypair_from_private_key_4(){   
        Scalar exp_prk = {0x20816400a4117723,0x8ed984970d08061e,0x9c4a64595f67c93d,0x90518c8f7e609450};
        Point  exp_puk ={{0x57ee45bbceba551b,0x9327b8047643b458,0xf8b9038217d65ef0,0xc0880c2b124e1bc1},
                       {0x29f00f6a71b300ec,0xb8250d73398ebd19,0x8ca4995c0f2348f1,0x4a6e48d3fd76af13}};
        KeyPair kp = {{0x20816400a4117723,0x8ed984970d08061e,0x9c4a64595f67c93d,0x90518c8f7e609450},{{},{}}};

		secp256k1_keypair_from_private_key(&kp); 
        TEST_SCALAR_EQUALS(exp_prk, kp.private_key)
        TEST_SCALAR_EQUALS(exp_puk.x, kp.public_key.x)
        TEST_SCALAR_EQUALS(exp_puk.y, kp.public_key.y) 
}



/**
test cases for ECDSA signing and verification on the secp256k1 elliptic curve.
*/






//******************************************* tests for signing **************************************************************************


void test_secp256k1_sign_1(){
                
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
        TEST_SCALAR_EQUALS(exp_r, sig.r)
        TEST_SCALAR_EQUALS(exp_s, sig.s)
}

void test_secp256k1_sign_2(){
                 
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

        TEST_SCALAR_EQUALS(exp_r, sig.r)
        TEST_SCALAR_EQUALS(exp_s, sig.s)
}


void test_secp256k1_sign_3(){
        Scalar msg = {0x0471baa664531d1a,0x9c67ea1c3bf63f3e,0x41ddb16ff0a1842d,0x4b688df40bcedbe6};
        Scalar prk = {0x92de1a255cad3e0f,0xad8de9f5d7c90286,0x0a28ac82f6bdf97b,0xebb2c082fd772789};
        KeyPair eph = {0x42ecf322ba9ddd9a,0x06571c974b191efb,0x0d0721d72804befd,0x49a0d7b786ec9cde};
        secp256k1_keypair_from_private_key(&eph);
        
        Signature sig;
        Scalar exp_r = {0xf8b08505c9e2f795, 0x10efbb3b2676bbc0, 0x145c8961dbdf10c3, 0x241097efbf8b63bf};
        Scalar exp_s = {0xc7955dfb01f3ca0e, 0x661828131aef1ecb, 0x9e8b415a7f9acb1b, 0x021006b783860933};
        secp256k1_sign(prk, &eph, msg, &sig);
        TEST_SCALAR_EQUALS(exp_r, sig.r)
        TEST_SCALAR_EQUALS(exp_s, sig.s)
}

//******************************************* tests for verification **************************************************************************


void test_secp256k1_verify_1(){
 
        Point puk = {{0x1795FFB3BE2F6C52, 0xDDF3B42740DF0D21, 0x11983F3E97C3FA0A, 0x028D003EAB2E428D},
        	         {0xB547526D8CD309E2, 0x6FB218D9E7594F02, 0xC78CB2A937ED8909, 0x0AE987B9EC6EA159}};
        Scalar msg = {0x5218cb08e79cce78, 0x2bf92433d9919b9c,0xfb7152f85cee7eb5,0x0231c6f3d980a6b0};
        Signature sig = {{0x8B121697B782EF22, 0xE8838DD1FB752040, 0x7E63488AD48C23E8, 0x2B698A0F0A4041B7},
        				 {0xeb635447ffae8cb9, 0xe6734b7a0fcd58b1, 0x2e25fad328466b34, 0xbb14e602ef9e3f87}};
        int exp = 0;
        int res = secp256k1_verify(&puk, msg, &sig);
        TEST_INT_EQUALS(exp,res)
}

void test_secp256k1_verify_1b(){
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

        TEST_INT_EQUALS(exp,res)
}

void test_secp256k1_verify_2(){
        Scalar  msg = {0x6e1936ae47060d48, 0x09c9f6aed9696501,0x795fd013fe88868d,0x969f6056aa26f7d2};
        KeyPair kp = {{0,0,0,0},{
        {0x105CF385A023A80F, 0x65522BF85734008F, 0xD410404CB8690720, 0xF01D6B9018AB421D},
        {0x6DA4999CF3F6A295, 0xBEFCCD9F7FF01DD2, 0xD681984DC525982A, 0x0EBA29D0F0C5408E}
        }};
        Signature sig = {{0x8B121697B782EF22, 0xE8838DD1FB752040, 0x7E63488AD48C23E8, 0x2B698A0F0A4041B7},
                         {0x6f316cff2cb0bc1a, 0x7076d8b20990a0f2, 0x5e602a7b56416116, 0x1dbc63bfef441670}};
        int exp = 0;
        int res = secp256k1_verify(&kp.public_key, msg, &sig);
        TEST_INT_EQUALS(exp,res)
}

void test_secp256k1_verify_2b(){
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

        TEST_INT_EQUALS(exp,res)
}

void test_secp256k1_verify_3(){
        Point puk = {{0x37A427BD5847DFCD, 0x28B790DC6B3B7D44, 0xD2CF6CB31D82D433, 0x779DD197A5DF977E},
        		     {0x75C9237B917D426F, 0xF5B1699D6EF41249, 0x7BB7607C3E3281DA, 0xE94B724A555B6D01}};
        Scalar msg = {0x0471baa664531d1a,0x9c67ea1c3bf63f3e,0x41ddb16ff0a1842d,0x4b688df40bcedbe6};
        Signature sig = {{0xf8b08505c9e2f795, 0x10efbb3b2676bbc0, 0x145c8961dbdf10c3, 0x241097efbf8b63bf},
        				 {0xc7955dfb01f3ca0e, 0x661828131aef1ecb, 0x9e8b415a7f9acb1b, 0x021006b783860933}};
        int exp = 0;
        int res = secp256k1_verify(&puk, msg, &sig);

        TEST_INT_EQUALS(exp,res)
}

void test_secp256k1_verify_3b(){
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

        TEST_INT_EQUALS(exp,res)
}



void test_secp256k1_verify_4(){
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

        TEST_INT_EQUALS(exp,res)
}

void test_secp256k1_verify_4b(){
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

        TEST_INT_EQUALS(exp,res)
}

void test_secp256k1_verify_5(){
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

        TEST_INT_EQUALS(exp,res)
}

void test_secp256k1_verify_5b(){
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

        TEST_INT_EQUALS(exp,res)
}




void test_secp256k1_sign_and_verify_1(){
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
        TEST_SCALAR_EQUALS(exp_r, sig.r)
        TEST_SCALAR_EQUALS(exp_s, sig.s)
        
        //Verifying
        int res = secp256k1_verify(&signer.public_key, msg, &sig);
        int exp = 0;
        TEST_INT_EQUALS(exp,res)       

}

void test_secp256k1_sign_and_verify_2(){
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
        TEST_SCALAR_EQUALS(exp_r, sig.r)
        TEST_SCALAR_EQUALS(exp_s, sig.s)
        
        //Verifying
        int res = secp256k1_verify(&signer.public_key, msg, &sig);
        int exp = 0;
        TEST_INT_EQUALS(exp,res)

}






//***************************** tests for normalization signature s **************************************

void secp256k1_normalize_s(Scalar s);

void test_secp256k1_normalize_s_1(){
     Scalar s =     {0xdfe92f46681b20a0, 0x5d576e7357a4501d, 0xffffffffffffffff, 0x7fffffffffffffff}; //s = n/2
     Scalar exp_s = {0xdfe92f46681b20a0, 0x5d576e7357a4501d, 0xffffffffffffffff, 0x7fffffffffffffff}; //s = n/2
     secp256k1_normalize_s(s);
     TEST_SCALAR_EQUALS(exp_s, s)
}

void test_secp256k1_normalize_s_2(){
     Scalar s = {0xdfe92f46681b20a1, 0x5d576e7357a4501d, 0xffffffffffffffff, 0x7fffffffffffffff}; //s = n/2 + 1
     Scalar exp_s =  {0xdfe92f46681b20a0, 0x5d576e7357a4501d, 0xffffffffffffffff, 0x7fffffffffffffff};// s = n - (n/2+1)
     secp256k1_normalize_s(s);
     TEST_SCALAR_EQUALS(exp_s, s)
}

void test_secp256k1_normalize_s_3(){
     Scalar s = {0xdfe92f46681b209f, 0x5d576e7357a4501d, 0xffffffffffffffff, 0x7fffffffffffffff}; //s = n/2 - 1
     Scalar exp_s = {0xdfe92f46681b209f, 0x5d576e7357a4501d, 0xffffffffffffffff, 0x7fffffffffffffff}; //s = n/2 -1
     secp256k1_normalize_s(s);
     TEST_SCALAR_EQUALS(exp_s, s)
}

void test_secp256k1_normalize_s_4(){
     Scalar s =  {0xBFD25E8CD0364140, 0xBAAEDCE6AF48A03B, 0xFFFFFFFFFFFFFFFE, 0xFFFFFFFFFFFFFFFF}; //n-1
     Scalar exp_s = {1, 0, 0, 0}; //s = n - (n -1) = 1
     secp256k1_normalize_s(s);
     TEST_SCALAR_EQUALS(exp_s, s)
}


void test_secp256k1_normalize_s_5(){
     Scalar s =     {0xD46F0A44D087B488, 0xD43B916C9F7B4789, 0xD1DA052CD7B994C9, 0x44EB19FD1061C078}; //<n/2
     Scalar exp_s = {0xD46F0A44D087B488, 0xD43B916C9F7B4789, 0xD1DA052CD7B994C9, 0x44EB19FD1061C078};
     secp256k1_normalize_s(s);
     TEST_SCALAR_EQUALS(exp_s, s)

}

void test_secp256k1_normalize_s_6(){
     Scalar s =     {0, 0, 0, 0xF000000000000000}; //>n/2

     Scalar exp_s = {0xbfd25e8cd0364141, 0xbaaedce6af48a03b, 0xfffffffffffffffe, 0x0fffffffffffffff};
     secp256k1_normalize_s(s);
     TEST_SCALAR_EQUALS(exp_s, s)
    
}



/**
 * tests for u256 multiplication and squaring with u512 results
 */
void test_mul512_1(){
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar hi;
        Scalar lo;    
        Scalar exp_hi = {0xd4de74191353b28d,0x15d61c2f228828e0,0xc9108f16551c1b22,0xa0c12a0db35a3ca6};
        Scalar exp_lo = {0xfad61c1b3d605ea6,0x87e5cfc817aa5f8c,0x953b1b53a16c2784,0x3991556b71458d1f};
        mul512(a,b,lo, hi);
        TEST_SCALAR_EQUALS(exp_lo, lo)
        TEST_SCALAR_EQUALS(exp_hi, hi)
}

void test_mul512_2(){
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0x31f7c7475c96f1e5,0x06b37149dbe04676,0x9418638e3304027a,0xa0f715f18aebffe6};
        Scalar exp_lo = {0x6626efd0797a0324,0xe9e32d067029b34d,0xa5f3fb01500ea51b,0x6e2407f3a1c33b92};
        mul512(a,b,lo, hi);
        TEST_SCALAR_EQUALS(exp_lo, lo)
        TEST_SCALAR_EQUALS(exp_hi, hi)
}

void test_mul512_3(){
        Scalar a = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar b = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0x60cb2addf4f0bf02,0xfbfbe2dac9b9b098,0x465be564846d2375,0xa08b5039ffe8af97};
        Scalar exp_lo = {0x37bc0632d4a9a321,0xadf604905b2ab1c5,0x7528cfaf2a3584bb,0x638de44d650ce5cc};
        mul512(a,b,lo, hi);
        TEST_SCALAR_EQUALS(exp_lo, lo)
        TEST_SCALAR_EQUALS(exp_hi, hi)
}

void test_mul512_4(){
        Scalar a = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar b = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0xbeefbeefbeefbeee,0xdeafdeafdeafdeaf,0xbaffbaffbaffbaff,0xcabacabacabacaba};
        Scalar exp_lo = {0x4110411041104111,0x2150215021502150,0x4500450045004500,0x3545354535453545};
        mul512(a,b,lo, hi);
        TEST_SCALAR_EQUALS(exp_lo, lo)
        TEST_SCALAR_EQUALS(exp_hi, hi)
}

void test_mul512_5(){
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar b = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0xabbaabbaabbaabb9,0xfefefefefefefefe,0xdeaddeaddeaddead,0xcafecafecafecafe};
        Scalar exp_lo = {0x5445544554455446,0x0101010101010101,0x2152215221522152,0x3501350135013501};
        mul512(a,b,lo, hi);
        TEST_SCALAR_EQUALS(exp_lo, lo)
        TEST_SCALAR_EQUALS(exp_hi, hi)
}

void test_mul512_6(){
        Scalar a = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar b = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0xfffffffffffffffe,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff};
        Scalar exp_lo = {1,0,0,0};
        mul512(a,b,lo, hi);
        TEST_SCALAR_EQUALS(exp_lo, lo)
        TEST_SCALAR_EQUALS(exp_hi, hi)
}

void test_mul512_7(){
        Scalar a = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar b = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0x60cb2addf4f0bf02,0xfbfbe2dac9b9b098,0x465be564846d2375,0xa08b5039ffe8af97};
        Scalar exp_lo = {0x37bc0632d4a9a321,0xadf604905b2ab1c5,0x7528cfaf2a3584bb,0x638de44d650ce5cc};
        mul512(a,b,lo, hi);
        TEST_SCALAR_EQUALS(exp_lo, lo)
        TEST_SCALAR_EQUALS(exp_hi, hi)
}

/*********512-bit big integer squareing **************************************/
void test_square512_1(){
        Scalar a = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0x31f7c7475c96f1e5,0x06b37149dbe04676,0x9418638e3304027a,0xa0f715f18aebffe6};
        Scalar exp_lo = {0x6626efd0797a0324,0xe9e32d067029b34d,0xa5f3fb01500ea51b,0x6e2407f3a1c33b92};
        square512(a,lo, hi);
        TEST_SCALAR_EQUALS(exp_lo, lo)
        TEST_SCALAR_EQUALS(exp_hi, hi)
}

void test_square512_2(){
        Scalar a = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0x60cb2addf4f0bf02,0xfbfbe2dac9b9b098,0x465be564846d2375,0xa08b5039ffe8af97};
        Scalar exp_lo = {0x37bc0632d4a9a321,0xadf604905b2ab1c5,0x7528cfaf2a3584bb,0x638de44d650ce5cc};
        square512(a,lo, hi);
        TEST_SCALAR_EQUALS(exp_lo, lo)
        TEST_SCALAR_EQUALS(exp_hi, hi)
}

void test_square512_3(){
        Scalar a = {0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0xfffffffffffffffe,0xffffffffffffffff,0xffffffffffffffff,0xffffffffffffffff};
        Scalar exp_lo = {1,0,0,0};
        square512(a,lo, hi);
        TEST_SCALAR_EQUALS(exp_lo, lo)
        TEST_SCALAR_EQUALS(exp_hi, hi)
}

void test_square512_4(){
        Scalar a = {0xf99999999999999f, 0xf99999999999999f, 0xf99999999999999f, 0xf99999999999999f};
        Scalar hi;
        Scalar lo; 
        Scalar exp_hi = {0x45c28f5c28f5c313,0xd4f5c28f5c28f620,0x6428f5c28f5c292a,0xf35c28f5c28f5c35};
        Scalar exp_lo = {0x7d70a3d70a3d70c1,0xee3d70a3d70a3db5,0x5f0a3d70a3d70aaa,0xcfd70a3d70a3d7a0};
        square512(a,lo, hi);
        TEST_SCALAR_EQUALS(exp_lo, lo)
        TEST_SCALAR_EQUALS(exp_hi, hi)
}



void test_square512_5(){
        Scalar a = {0xbeefbeefbeefbeef, 0xdeafdeafdeafdeaf, 0xbaffbaffbaffbaff, 0xcabacabacabacaba};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0x60cb2addf4f0bf02,0xfbfbe2dac9b9b098,0x465be564846d2375,0xa08b5039ffe8af97};
        Scalar exp_lo = {0x37bc0632d4a9a321,0xadf604905b2ab1c5,0x7528cfaf2a3584bb,0x638de44d650ce5cc};
        square512(a,lo, hi);
        TEST_SCALAR_EQUALS(exp_lo, lo)
        TEST_SCALAR_EQUALS(exp_hi, hi)
}

void test_square512_6(){
        Scalar a = {0, 0, 0, 0};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0,0,0,0};
        Scalar exp_lo = {0,0,0,0};
        square512(a,lo, hi);
        TEST_SCALAR_EQUALS(exp_lo, lo)
        TEST_SCALAR_EQUALS(exp_hi, hi)
}

void test_square512_7(){
        Scalar a = {4, 3, 2, 1};
        Scalar hi;
        Scalar lo;  
        Scalar exp_hi = {0xa,4,1,0};
        Scalar exp_lo = {0x10,0x18,0x19,0x14};
        square512(a,lo, hi);
        TEST_SCALAR_EQUALS(exp_lo, lo)
        TEST_SCALAR_EQUALS(exp_hi, hi)
}



//*******tests for parsing scalars and points from strings*************************************************



void test_secp256k1_parse_point_1(){

	char inp[] = "0474F1CE3C6EF778D672808056EE1E53F497D573E36ED4385F52B465135504E4FFA416475ADA0FD2563AA92456DCA573E07A8A2D551742BF50D127A2980B361248";
	Point exp = {{0x52B465135504E4FF, 0x97D573E36ED4385F, 0x72808056EE1E53F4, 0x74F1CE3C6EF778D6}, 
					{0xD127A2980B361248, 0x7A8A2D551742BF50, 0x3AA92456DCA573E0, 0xA416475ADA0FD256}};
    Point res;
    secp256k1_parse_point(inp, &res);
    TEST_SCALAR_EQUALS(exp.x, res.x)
    TEST_SCALAR_EQUALS(exp.y, res.y) 
}

void test_secp256k1_parse_point_2(){

	char inp[] = "044F83A657A0CED2B1A02640EB88CB0CFD1DFA93A9285B2F4F002B28F4BF8944779E1C64324941D002FB5C05A28B88B0743E7BE1AB6AF1D6CACCAA9B5070C81633";
	Point exp = {{0x002B28F4BF894477, 0x1DFA93A9285B2F4F, 0xA02640EB88CB0CFD, 0x4F83A657A0CED2B1}, 
					{0xCCAA9B5070C81633, 0x3E7BE1AB6AF1D6CA, 0xFB5C05A28B88B074, 0x9E1C64324941D002}};
    Point res;
    secp256k1_parse_point(inp, &res);
    TEST_SCALAR_EQUALS(exp.x, res.x)
    TEST_SCALAR_EQUALS(exp.y, res.y)     
}
 
void test_secp256k1_parse_point_3(){

    
	char inp[] = "0274F1CE3C6EF778D672808056EE1E53F497D573E36ED4385F52B465135504E4FF";
	Point exp = {{0x52B465135504E4FF, 0x97D573E36ED4385F, 0x72808056EE1E53F4, 0x74F1CE3C6EF778D6}, 
					{0xD127A2980B361248, 0x7A8A2D551742BF50, 0x3AA92456DCA573E0, 0xA416475ADA0FD256}};
    Point res;
    secp256k1_parse_point(inp, &res);
    TEST_SCALAR_EQUALS(exp.x, res.x)
    TEST_SCALAR_EQUALS(exp.y, res.y) 
}

void test_secp256k1_parse_point_4(){

    
    	char inp[] = "034F83A657A0CED2B1A02640EB88CB0CFD1DFA93A9285B2F4F002B28F4BF894477";
	Point exp = {{0x002B28F4BF894477, 0x1DFA93A9285B2F4F, 0xA02640EB88CB0CFD, 0x4F83A657A0CED2B1}, 
					{0xCCAA9B5070C81633, 0x3E7BE1AB6AF1D6CA, 0xFB5C05A28B88B074, 0x9E1C64324941D002}};
    Point res;
    secp256k1_parse_point(inp, &res);
    TEST_SCALAR_EQUALS(exp.x, res.x)
    TEST_SCALAR_EQUALS(exp.y, res.y)     
}

void test_secp256k1_parse_point_5(){

	char inp[] =     "0279BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798";
	Point exp = {{0x59F2815B16F81798, 0x029BFCDB2DCE28D9, 0x55A06295CE870B07, 0x79BE667EF9DCBBAC}, 
					{0x9C47D08FFB10D4B8, 0xFD17B448A6855419, 0x5DA4FBFC0E1108A8, 0x483ADA7726A3C465}};//Generator
    Point res;
    secp256k1_parse_point(inp, &res);
    TEST_SCALAR_EQUALS(exp.x, res.x)
    TEST_SCALAR_EQUALS(exp.y, res.y)     
}

void test_secp256k1_parse_point_6(){

	char inp[] =     "03D0E1494EE3B53B5C3463617DDD99C589B0F1560794B9D8FB94083A4167A396AA";
	Point exp = {{0x94083A4167A396AA,0xB0F1560794B9D8FB,0x3463617DDD99C589,0xD0E1494EE3B53B5C}, 
					{0x73FDC7871F71213D,0x4FF88CFD0E4DE55A,0x67B9BE0A3C9B46DD,0x1D085BB398547817}};
    Point res;
    secp256k1_parse_point(inp, &res);
    TEST_SCALAR_EQUALS(exp.x, res.x)
    TEST_SCALAR_EQUALS(exp.y, res.y)     
}

void test_secp256k1_parse_point_7(){

	char inp[] =     "04D0E1494EE3B53B5C3463617DDD99C589B0F1560794B9D8FB94083A4167A396AA1D085BB39854781767B9BE0A3C9B46DD4FF88CFD0E4DE55A73FDC7871F71213D";
	Point exp = {{0x94083A4167A396AA,0xB0F1560794B9D8FB,0x3463617DDD99C589,0xD0E1494EE3B53B5C}, 
					{0x73FDC7871F71213D,0x4FF88CFD0E4DE55A,0x67B9BE0A3C9B46DD,0x1D085BB398547817}};
    Point res;
    secp256k1_parse_point(inp, &res);
    TEST_SCALAR_EQUALS(exp.x, res.x)
    TEST_SCALAR_EQUALS(exp.y, res.y)     
} 


void test_secp256k1_parse_point_8(){

	char inp[] =     "04E0013E9240345F3B6D1381061FB6E3EEFAA2F4EE3ECD36EE40E1A99D5F6B43513C77676F28D9128D268505B5B5C08E7417D22360A93237D4C2E9CE8472F3E72A";
	Point exp = {{0x40E1A99D5F6B4351,0xFAA2F4EE3ECD36EE,0x6D1381061FB6E3EE,0xE0013E9240345F3B}, 
					{0xC2E9CE8472F3E72A,0x17D22360A93237D4,0x268505B5B5C08E74,0x3C77676F28D9128D}};
    Point res;
    secp256k1_parse_point(inp, &res);
    TEST_SCALAR_EQUALS(exp.x, res.x)
    TEST_SCALAR_EQUALS(exp.y, res.y)     
}

void test_secp256k1_parse_point_9(){

	char inp[] =     "02E0013E9240345F3B6D1381061FB6E3EEFAA2F4EE3ECD36EE40E1A99D5F6B4351";
	Point exp = {{0x40E1A99D5F6B4351,0xFAA2F4EE3ECD36EE,0x6D1381061FB6E3EE,0xE0013E9240345F3B}, 
					{0xC2E9CE8472F3E72A,0x17D22360A93237D4,0x268505B5B5C08E74,0x3C77676F28D9128D}};
    Point res;
    secp256k1_parse_point(inp, &res);
    TEST_SCALAR_EQUALS(exp.x, res.x)
    TEST_SCALAR_EQUALS(exp.y, res.y)     
}


void test_secp256k1_parse_point_10(){

	char inp[] =     "04AB5118410D6F90CD184972CFC940E85CADD730781636FCF01450B4A66F3011156BDE88A239EC2C1457145D1D88418513F51F75B79975C4239B722639A5FFC0A2";
	Point exp = {{0x1450B4A66F301115,0xADD730781636FCF0,0x184972CFC940E85C,0xAB5118410D6F90CD}, 
					{0x9B722639A5FFC0A2,0xF51F75B79975C423,0x57145D1D88418513,0x6BDE88A239EC2C14}};
    Point res;
    secp256k1_parse_point(inp, &res);
    TEST_SCALAR_EQUALS(exp.x, res.x)
    TEST_SCALAR_EQUALS(exp.y, res.y)     
}

void test_secp256k1_parse_point_11(){

	char inp[] =     "02AB5118410D6F90CD184972CFC940E85CADD730781636FCF01450B4A66F301115";
	Point exp = {{0x1450B4A66F301115,0xADD730781636FCF0,0x184972CFC940E85C,0xAB5118410D6F90CD}, 
					{0x9B722639A5FFC0A2,0xF51F75B79975C423,0x57145D1D88418513,0x6BDE88A239EC2C14}};
    Point res;
    secp256k1_parse_point(inp, &res);
    TEST_SCALAR_EQUALS(exp.x, res.x)
    TEST_SCALAR_EQUALS(exp.y, res.y)     
}


void test_secp256k1_parse_point_12(){

	char inp[] =     "04FC55EF482F9CD58292046433B8A1FFEED18889E6393195051052926A5778A309C16684DB73FCF87B1B3FA5218B0E58A3126A2C11305F3E7DA082F10231F68BE7";
	Point exp = {{0x1052926A5778A309,0xD18889E639319505,0x92046433B8A1FFEE,0xFC55EF482F9CD582}, 
					{0xA082F10231F68BE7,0x126A2C11305F3E7D,0x1B3FA5218B0E58A3,0xC16684DB73FCF87B}};
    Point res;
    secp256k1_parse_point(inp, &res);
    TEST_SCALAR_EQUALS(exp.x, res.x)
    TEST_SCALAR_EQUALS(exp.y, res.y)     
}

void test_secp256k1_parse_point_13(){

	char inp[] =     "03FC55EF482F9CD58292046433B8A1FFEED18889E6393195051052926A5778A309";
	Point exp = {{0x1052926A5778A309,0xD18889E639319505,0x92046433B8A1FFEE,0xFC55EF482F9CD582}, 
					{0xA082F10231F68BE7,0x126A2C11305F3E7D,0x1B3FA5218B0E58A3,0xC16684DB73FCF87B}};
    Point res;
    secp256k1_parse_point(inp, &res);
    TEST_SCALAR_EQUALS(exp.x, res.x)
    TEST_SCALAR_EQUALS(exp.y, res.y)     
}

void test_secp256k1_parse_scalar_1(){

		char inp[] = "cafecafecafecafedeaddeaddeaddeadfefefefefefefefeabbaabbaabbaabba";
        Scalar val;
        Scalar exp = {0xabbaabbaabbaabba, 0xfefefefefefefefe, 0xdeaddeaddeaddead, 0xcafecafecafecafe};  
        secp256k1_parse_scalar(inp, val);
        TEST_SCALAR_EQUALS(exp, val)
}


void test_secp256k1_parse_scalar_2(){

		char inp[] = "B68B69A717D220F744B9CC0DD5B7530A92880838C85D6AC0A6F0146894AE298F";
        Scalar val;
        Scalar exp = {0xA6F0146894AE298F, 0x92880838C85D6AC0, 0x44B9CC0DD5B7530A, 0xB68B69A717D220F7};
        secp256k1_parse_scalar(inp, val);
        TEST_SCALAR_EQUALS(exp, val)
}

void test_secp256k1_parse_scalar_3(){

		char inp[] = "b68b69a717D220f744b9cC0DD5B7530a92880838c85d6AC0a6F0146894Ae298f";
        Scalar val;
        Scalar exp = {0xA6F0146894AE298F, 0x92880838C85D6AC0, 0x44B9CC0DD5B7530A, 0xB68B69A717D220F7};
        secp256k1_parse_scalar(inp, val);
        TEST_SCALAR_EQUALS(exp, val)
}

void test_secp256k1_parse_scalar_4(){

		char inp[] = "B68B69A717D220F744B9CC0DD5B7530A92880838C85D6AC0A6F0146894AE298F\0\0";
        Scalar val;
        Scalar exp = {0xA6F0146894AE298F, 0x92880838C85D6AC0, 0x44B9CC0DD5B7530A, 0xB68B69A717D220F7};
        secp256k1_parse_scalar(inp, val);
        TEST_SCALAR_EQUALS(exp, val)
}

void test_secp256k1_parse_u64_1(){

		char inp[] = "Fedcba9876543210";
		unsigned long long exp = 0xfedcba9876543210;
		unsigned long long val = secp256k1_parse_u64(inp);
		TEST_LONGLONG_EQUALS(exp,val)
}

void test_secp256k1_parse_u64_2(){

		char inp[] = "f000000000000001";
		unsigned long long exp = 0xf000000000000001;
		unsigned long long val = secp256k1_parse_u64(inp);
		TEST_LONGLONG_EQUALS(exp,val)
}

void test_secp256k1_parse_u64_3(){

		char inp[] = "Ab7aB0efDe3dCa1e";
		unsigned long long exp = 0xab7ab0efde3dca1e;
		unsigned long long val = secp256k1_parse_u64(inp);
		TEST_LONGLONG_EQUALS(exp,val)
}


//***************************tests for converting a Scalar into an ASCII string*****************************+

void test_secp256k1_scalar_to_string_1(){
        Scalar s = {0x5218cb08e79cce78, 0x2bf92433d9919b9c,0xfb7152f85cee7eb5,0x0231c6f3d980a6b0};
        char exp_str[] = "0231c6f3d980a6b0fb7152f85cee7eb52bf92433d9919b9c5218cb08e79cce78\0";
        char str[65] = {0};
        secp256k1_scalar_to_string(s, str);
        TEST_STRING_EQUALS(exp_str, str)
}


void test_secp256k1_scalar_to_string_2(){
        Scalar s = {0xabba1970dead1982, 0xbabecafe13001224,0xfefe0830deadbeef,0xbaba1920dead2001};
        char exp_str[] = "baba1920dead2001fefe0830deadbeefbabecafe13001224abba1970dead1982\0";
        char str[65] = {0};
        secp256k1_scalar_to_string(s, str);
        TEST_STRING_EQUALS(exp_str, str)
}


//***************************tests for helper functions************************************
void test_secp256k1_u32_to_string_1(){

        int val = 0x87654321;
        char str[] = "00000000";
        char exp_str[] = "87654321";
        secp256k1_u32_to_string(val, str);
        TEST_STRING_EQUALS(exp_str, str)
}

void test_secp256k1_u32_to_string_1a(){

        int val = 0x87654321;
        char str[9];
        str[8] = 0;
        char exp_str[] = "87654321";
        secp256k1_u32_to_string(val, str);
        TEST_STRING_EQUALS(exp_str, str)
}

void test_secp256k1_u32_to_string_2(){

        int val = 0xfedcba98;
        char str[] = "00000000\0";
        char exp_str[] = "fedcba98\0";
        secp256k1_u32_to_string(val, str);
        TEST_STRING_EQUALS(exp_str, str)
}

void test_secp256k1_u32_to_string_2a(){

        int val = 0xfedcba98;
        char str[9] = {0};
        char exp_str[] = "fedcba98\0";
        secp256k1_u32_to_string(val, str);
        TEST_STRING_EQUALS(exp_str, str)
}


void test_secp256k1_u32_to_string_3(){

        int val = 0x41424344;
        char str[] = "00000000";
        char exp_str[] = "41424344\0";
        secp256k1_u32_to_string(val, str);
        TEST_STRING_EQUALS(exp_str, str)
}

void test_secp256k1_u64_to_string_1(){

        long long val = 0xfedcba9876543210;
        char str[] = "0000000000000000\0";
        char exp_str[] = "fedcba9876543210\0";
        secp256k1_u64_to_string(val, str);
        TEST_STRING_EQUALS(exp_str, str)
}

void test_secp256k1_u64_to_string_2(){

        long long val = 0xabbadeadbabecafe;
        char str[17] = {0};
        char exp_str[] = "abbadeadbabecafe\0";
        secp256k1_u64_to_string(val, str);
        TEST_STRING_EQUALS(exp_str, str)
}



int asciiz_length(char *array);



void test_asciiz_length_1(){
       char arr[] = "abcde\0";
       int len = asciiz_length(arr);
       int exp_len = 5;
       TEST_INT_EQUALS(exp_len, len)

}

void test_asciiz_length_2(){
       char arr[20] = {0};
       int len = asciiz_length(arr);
       int exp_len = 0;
       TEST_INT_EQUALS(exp_len, len)

}
  
void test_asciiz_length_3(){
       char arr[20] = {97, 98, 99, 0};
       int len = asciiz_length(arr);
       int exp_len = 3;
       TEST_INT_EQUALS(exp_len, len)

}

void test_asciiz_length_4(){
       char arr[] = {97, 98, 99, 100, 101, 102, 103, 104, 0};
       int len = asciiz_length(arr);
       int exp_len = 8;
       TEST_INT_EQUALS(exp_len, len)

}


void test_asciiz_length_5(){
       char arr[] = "abcdefghijk\0lmnopqrstuvw\0";
       int len = asciiz_length(arr);
       int exp_len = 11;
       TEST_INT_EQUALS(exp_len, len)

}

void test_asciiz_length_6(){
       char arr[] = "a\0bcdefghijk\0lmnopqrstuvw\0";
       int len = asciiz_length(arr);
       int exp_len = 1;
       TEST_INT_EQUALS(exp_len, len)

}
void test_asciiz_length_7(){
       char arr[] = "abcdefghijk\0lmnopqrstuvw";
       arr[0] = 0;
       int len = asciiz_length(arr);
       int exp_len = 0;
       TEST_INT_EQUALS(exp_len, len)

}

void test_asciiz_length_8(){
       char arr[] = "abcdefghijk\0";
       arr[5] = 0;
       int len = asciiz_length(arr);
       int exp_len = 5;
       TEST_INT_EQUALS(exp_len, len)

}

void test_asciiz_length_9(){
       char arr[] = "abcdefghijk";
       int len = asciiz_length(arr);
       int exp_len = 11;
       TEST_INT_EQUALS(exp_len, len)

}

void test_asciiz_length_10(){
       int len = asciiz_length("abcdefghijk");
       int exp_len = 11;
       TEST_INT_EQUALS(exp_len, len)

}

int count_decimals(unsigned long long);

void test_count_decimals_1(){
	   long long val = 0xabbafefedeadcafe; // = dec 12374483296764939006 => 20 chars.
       int len = count_decimals(val);
       int exp_len = 20;
       TEST_INT_EQUALS(exp_len, len)

}

void test_count_decimals_2(){
	   long long val = 1237448390 ;
       int exp_len = 10;
        int len = count_decimals(val);
       TEST_INT_EQUALS(exp_len, len)

}

void test_count_decimals_3(){
	   long long val = 0xffffffffffffffff; //= dec 18446744073709551615 => 20 chars.
       int len = count_decimals(val);
       int exp_len = 20;
       TEST_INT_EQUALS(exp_len, len)

}

void test_count_decimals_4(){
	   long long val = 8446744073709551615; //=> 19 chars.
       int len = count_decimals(val);
       int exp_len = 19;
       TEST_INT_EQUALS(exp_len, len)

}

void test_count_decimals_5(){
	   long long val = 2000; //=> 4 chars.
       int len = count_decimals(val);
       int exp_len = 4;
       TEST_INT_EQUALS(exp_len, len)

}

void test_count_decimals_6(){
	   long long val = 123456789; //=> 9 chars.
       int len = count_decimals(val);
       int exp_len = 9;
       TEST_INT_EQUALS(exp_len, len)

}

void test_count_decimals_7(){
	   long long val = 0; //=> 1 chars.
       int len = count_decimals(val);
       int exp_len = 1;
       TEST_INT_EQUALS(exp_len, len)

}

void test_count_decimals_8(){
	   long long val = 123456789012345; //=> 15 chars.
       int len = count_decimals(val);
       int exp_len = 15;
       TEST_INT_EQUALS(exp_len, len)

}

int u64_to_decimal(long long value, char *buf);

void test_u64_to_decimal_1(){
	   long long val = 123456789012345; //=> 15 chars.
	   char exp_str[] = "123456789012345";
       char buf[21] = {0};
       int len = u64_to_decimal(val, buf);
       int exp_len =15;
       TEST_INT_EQUALS(exp_len, len)
       TEST_STRING_EQUALS(exp_str, buf)
}


void test_u64_to_decimal_2(){
	   long long val = 0xabbafefedeadcafe;  
	   char exp_str[] = "12374483296764939006";
       char buf[21] = {0};
       int len = u64_to_decimal(val, buf);
       int exp_len =20;
       TEST_INT_EQUALS(exp_len, len)
       TEST_STRING_EQUALS(exp_str, buf)
}

void test_u64_to_decimal_3(){
	   long long val = 0xffffffffffffffff;   
	   char exp_str[] = "18446744073709551615";
       char buf[21] = {0};
       int len = u64_to_decimal(val, buf);
       int exp_len =20;
       TEST_INT_EQUALS(exp_len, len)
       TEST_STRING_EQUALS(exp_str, buf)
}

void test_u64_to_decimal_4(){
	   long long val = 0x64;   
	   char exp_str[] = "100";
       char buf[21] = {0};
       int len = u64_to_decimal(val, buf);
       int exp_len =3;
       TEST_INT_EQUALS(exp_len, len)
       TEST_STRING_EQUALS(exp_str, buf)
}

void test_u64_to_decimal_5(){
	   long long val = 0;   
	   char exp_str[] = "0";
       char buf[21] = {0};
       int len = u64_to_decimal(val, buf);
       int exp_len =1;
       TEST_INT_EQUALS(exp_len, len)
       TEST_STRING_EQUALS(exp_str, buf)
}

void test_u64_to_decimal_6(){
	   long long val = 1;   
	   char exp_str[] = "1";
       char buf[21] = {0};
       int len = u64_to_decimal(val, buf);
       int exp_len =1;
       TEST_INT_EQUALS(exp_len, len)
       TEST_STRING_EQUALS(exp_str, buf)
}


int u64_to_ascii(long long value, int base, char *buf);


void test_u64_to_ascii_base16_1(){
	   long long val = 0xffffffffffffffff;   
	   char exp_str[] = "FFFFFFFFFFFFFFFF";
       char buf[17] = {0};
       int base = 16;
       int len = u64_to_ascii(val, base, buf);
       int exp_len =16;
       TEST_INT_EQUALS(exp_len, len)
       TEST_STRING_EQUALS(exp_str, buf)
}

void test_u64_to_ascii_base16_2(){
	   long long val = 0xabbadeadbabecafe;   
	   char exp_str[] = "ABBADEADBABECAFE";
       char buf[17] = {0};
       int base = 16;
       int len = u64_to_ascii(val, base, buf);
       int exp_len =16;
       TEST_INT_EQUALS(exp_len, len)
       TEST_STRING_EQUALS(exp_str, buf)
}

void test_u64_to_ascii_base10(){
	   long long val = 0xffffffffffffffff;   
	   char exp_str[] = "18446744073709551615";
       char buf[21] = {0};
       int base = 10;
       int len = u64_to_ascii(val, base, buf);
       int exp_len =20;
       TEST_INT_EQUALS(exp_len, len)
       TEST_STRING_EQUALS(exp_str, buf)
}


void test_u64_to_ascii_base8(){
	   long long val = 0xffffffffffffffff;   
	   char exp_str[] = "1777777777777777777777";
       char buf[23] = {0};
       int base = 8;
       int len = u64_to_ascii(val, base, buf);
       int exp_len =22;
       TEST_INT_EQUALS(exp_len, len)
       TEST_STRING_EQUALS(exp_str, buf)
}

void test_u64_to_ascii_base4(){
	   long long val = 0xffffffffffffffff;   
	   char exp_str[] = "33333333333333333333333333333333";
       char buf[33] = {0};
       int base = 4;
       int len = u64_to_ascii(val, base, buf);
       int exp_len =32;
       TEST_INT_EQUALS(exp_len, len)
       TEST_STRING_EQUALS(exp_str, buf)
}

void test_u64_to_ascii_base3(){
	   long long val = 0xffffffffffffffff;   
	   char exp_str[] = "11112220022122120101211020120210210211220";
       char buf[42] = {0};
       int base = 3;
       int len = u64_to_ascii(val, base, buf);
       int exp_len =41;
         TEST_INT_EQUALS(exp_len, len)
       TEST_STRING_EQUALS(exp_str, buf)
}

void test_u64_to_ascii_base2(){
	   long long val = 0xffffffffffffffff;   
	   char exp_str[] = "1111111111111111111111111111111111111111111111111111111111111111";
       char buf[65] = {0};
       int base = 2;
       int len = u64_to_ascii(val, base, buf);
       int exp_len =64;
         TEST_INT_EQUALS(exp_len, len)
       TEST_STRING_EQUALS(exp_str, buf)
}


void test_u64_to_ascii_base32_ext_hex_alphabet(){
	   long long val = 0xffffffffffffffff;   
	   char exp_str[] = "FVVVVVVVVVVVV";
       char buf[14] = {0};
       int base = 32;
       int len = u64_to_ascii(val, base, buf);
       int exp_len =13;
       TEST_INT_EQUALS(exp_len, len)
       TEST_STRING_EQUALS(exp_str, buf)
}


void test_u64_to_ascii_base32_ext_hex_alphabet_2(){
	   long long val = 0xabbadeadbabecafe;   
	   char exp_str[] = "ANEMULMTBTINU";
       char buf[14] = {0};
       int base = 32;
       int len = u64_to_ascii(val, base, buf);
       int exp_len = 13;
       TEST_INT_EQUALS(exp_len, len)
       TEST_STRING_EQUALS(exp_str, buf)
}

void test_u64_to_ascii_base85(){
	   long long val = 0xffffffffffffffff;   
	   char exp_str[] = "_sw2=@*|O0";
       char buf[11] = {0};
       int base = 85;
       int len = u64_to_ascii(val, base, buf);
       int exp_len = 10;
       TEST_INT_EQUALS(exp_len, len)
       TEST_STRING_EQUALS(exp_str, buf)
}



int main(void){
    printf("\nTesting finite field and elliptic curve functions on the secp256k1 curve.\n\n");
 test_secp256k1_add_mod_p_1();
 test_secp256k1_add_mod_p_2();
 test_secp256k1_add_mod_p_3();
 test_secp256k1_add_mod_p_4();
 test_secp256k1_add_mod_p_5();
 test_secp256k1_add_mod_p_6();
 test_secp256k1_add_mod_p_7();
 test_secp256k1_add_mod_p_8();
 test_secp256k1_add_mod_p_9();
 test_secp256k1_add_mod_p_10();
 test_secp256k1_add_mod_p_11();
 test_secp256k1_double_mod_p_1();
 test_secp256k1_double_mod_p_2();
 test_secp256k1_double_mod_p_3();
 test_secp256k1_double_mod_p_4();
 test_secp256k1_double_mod_p_5();
 test_secp256k1_double_mod_p_6();
 test_secp256k1_triple_mod_p_1();
 test_secp256k1_triple_mod_p_2();
 test_secp256k1_triple_mod_p_3();
 test_secp256k1_triple_mod_p_4();
 test_secp256k1_triple_mod_p_5();
 test_secp256k1_triple_mod_p_6();
 test_secp256k1_triple_mod_p_7();
 test_secp256k1_triple_mod_p_8();
 test_secp256k1_sub_mod_p_1();
 test_secp256k1_sub_mod_p_2();
 test_secp256k1_sub_mod_p_3();
 test_secp256k1_sub_mod_p_4();
 test_secp256k1_sub_mod_p_5();
 test_secp256k1_sub_mod_p_6();
 test_secp256k1_sub_mod_p_7();
 test_secp256k1_sub_mod_p_8();
 test_secp256k1_negate_mod_p_1();
 test_secp256k1_negate_mod_p_2();
 test_secp256k1_negate_mod_p_3();
 test_secp256k1_negate_mod_p_4();
 test_secp256k1_negate_mod_p_5();
 test_secp256k1_negate_mod_p_6();
 test_secp256k1_negate_mod_p_7();
 test_secp256k1_negate_mod_p_8();
 test_secp256k1_negate_mod_p_asign_1();
 test_secp256k1_negate_mod_p_asign_2();
 test_secp256k1_sub_mod_p_9();
 test_secp256k1_sub_mod_p_10();
 test_secp256k1_sub_mod_p_11();
 test_secp256k1_square_mod_p_1();
 test_secp256k1_square_mod_p_2();
 test_secp256k1_square_mod_p_3();
 test_secp256k1_square_mod_p_4();
 test_secp256k1_square_mod_p_5();
 test_secp256k1_square_mod_p_6();
 test_secp256k1_square_mod_p_7();
 test_secp256k1_square_mod_p_8();
 test_secp256k1_square_mod_p_9();
 test_secp256k1_square_mod_p_10();
 test_secp256k1_square_mod_p_11();
 test_secp256k1_square_mod_p_asign_1();
 test_secp256k1_square_mod_p_asign_2();
 test_secp256k1_invert_mod_p_1();
 test_secp256k1_invert_mod_p_2();
 test_secp256k1_invert_mod_p_3();
 test_secp256k1_invert_mod_p_4();
 test_secp256k1_invert_mod_p_5();
 test_secp256k1_invert_mod_p_6();
 test_secp256k1_invert_mod_p_7();
 test_secp256k1_invert_mod_p_8();
 test_secp256k1_invert_mod_p_asign_1();
 test_secp256k1_invert_mod_p_asign_2();
 test_secp256k1_invert_mod_p_asign_3();
 test_secp256k1_invert_mod_p_asign_4();
 test_secp256k1_invert_mod_p_asign_5();
 test_secp256k1_invert_mod_p_asign_6();
 test_secp256k1_invert_mod_p_asign_7();
 test_secp256k1_invert_mod_p_asign_8();
 test_secp256k1_exponentiate_mod_p1();
 test_secp256k1_exponentiate_mod_p2();
 test_secp256k1_exponentiate_mod_p3();
 test_secp256k1_exponentiate_mod_p4();
 test_secp256k1_exponentiate_mod_p5();
 test_secp256k1_exponentiate_mod_p6();
 test_secp256k1_exponentiate_mod_p7();
 test_secp256k1_cube_mod_p_1();
 test_secp256k1_cube_mod_p_2();
 test_secp256k1_cube_mod_p_asign_1();
 test_secp256k1_cube_mod_p_asign_2();
 test_secp256k1_squareroot_mod_p_1();
 test_secp256k1_squareroot_mod_p_2();
 test_secp256k1_squareroot_mod_p_3();
 test_secp256k1_squareroot_mod_p_4();
 test_secp256k1_squareroot_mod_p_5();
 test_secp256k1_squareroot_mod_p_6();
 test_secp256k1_squareroot_mod_p_7();
 test_secp256k1_squareroot_mod_p_asign_1();
 test_secp256k1_squareroot_mod_p_asign_2();
 test_secp256k1_has_squareroot_mod_p_1();
 test_secp256k1_has_squareroot_mod_p_2();
 test_secp256k1_has_squareroot_mod_p_3();
 test_secp256k1_has_squareroot_mod_p_4();
 test_secp256k1_has_squareroot_mod_p_5();
 test_secp256k1_has_squareroot_mod_p_6();
 test_secp256k1_has_squareroot_mod_p_7();
 test_secp256k1_has_squareroot_mod_p_8();
 test_secp256k1_has_squareroot_mod_p_9();
 test_secp256k1_mul_mod_p_1();
 test_secp256k1_mul_mod_p_2();
 test_secp256k1_mul_mod_p_3();
 test_secp256k1_mul_mod_p_4();
 test_secp256k1_mul_mod_p_5();
 test_secp256k1_mul_mod_p_6();
 test_secp256k1_mul_mod_p_7();
 test_secp256k1_mul_mod_p_8();
 test_secp256k1_mul_mod_p_9();
 test_secp256k1_mul_mod_p_10();
 test_secp256k1_mul_mod_p_11();
 test_secp256k1_mul_mod_p_12();
 test_secp256k1_mul_mod_p_13();
 test_secp256k1_mul_mod_p_14();
 test_secp256k1_secp256k1_reduce_mod_n_1();
 test_secp256k1_secp256k1_reduce_mod_n_2();
 test_secp256k1_secp256k1_reduce_mod_n_3();
 test_secp256k1_secp256k1_reduce_mod_n_4();
 test_secp256k1_add_mod_n_1();
 test_secp256k1_add_mod_n_2();
 test_secp256k1_add_mod_n_3();
 test_secp256k1_add_mod_n_4();
 test_secp256k1_add_mod_n_5();
 test_secp256k1_mul_mod_n_1();
 test_secp256k1_mul_mod_n_2();
 test_secp256k1_mul_mod_n_3();
 test_secp256k1_mul_mod_n_4();
 test_secp256k1_mul_mod_n_5();
 test_secp256k1_mul_mod_n_6();
 test_secp256k1_mul_mod_n_7();
 test_secp256k1_mul_mod_n_8();
 test_secp256k1_mul_mod_n_9();
 test_secp256k1_square_mod_n_1();
 test_secp256k1_square_mod_n_2();
 test_secp256k1_square_mod_n_3();
 test_secp256k1_square_mod_n_4();
 test_secp256k1_square_mod_n_5();
 test_secp256k1_square_mod_n_6();
 test_secp256k1_square_mod_n_7();
 test_secp256k1_square_mod_n_8();
 test_secp256k1_square_mod_n_9();
 test_secp256k1_square_mod_n_10();
 test_secp256k1_square_mod_n_11();
 test_secp256k1_square_mod_n_12();
 test_secp256k1_square_mod_n_13();
 test_secp256k1_square_mod_n_asign_1();
 test_secp256k1_square_mod_n_asign_2();
 test_secp256k1_invert_mod_n_1();
 test_secp256k1_invert_mod_n_2();
 test_secp256k1_invert_mod_n_3();
 test_secp256k1_invert_mod_n_4();
 test_secp256k1_invert_mod_n_5();
 test_secp256k1_invert_mod_n_6();
 test_secp256k1_invert_mod_n_7();
 test_secp256k1_invert_mod_n_8();
 test_secp256k1_invert_mod_n_asign_1();
 test_secp256k1_invert_mod_n_asign_2();
 test_secp256k1_sub_mod_n_1();
 test_secp256k1_sub_mod_n_2();
 test_secp256k1_sub_mod_n_3();
 test_secp256k1_sub_mod_n_4();
 test_secp256k1_sub_mod_n_5();
 test_secp256k1_sub_mod_n_6();
 test_secp256k1_sub_mod_n_7();
 test_secp256k1_sub_mod_n_8();
 test_secp256k1_sub_mod_n_9();
 test_secp256k1_sub_mod_n_10();
 test_secp256k1_sub_mod_n_11();
 test_secp256k1_sub_mod_n_12();
 test_secp256k1_sub_mod_n_13();
 test_add_different_points_1();
 test_add_different_points_2();
 test_add_different_points_3();
 test_add_different_points_4();
 test_add_different_points_5();
 test_add_different_points_6();
 test_add_different_points_7();
 test_add_different_points_8();
 test_add_different_points_9();
 test_add_different_points_10();
 test_add_different_points_11();
 test_add_different_points_12();
 test_add_different_points_13();
 test_add_asign_14();
 test_double_point_1();
 test_double_point_2();
 test_double_point_3();
 test_compare_1();
 test_compare_2();
 test_compare_3();
 test_compare_4();
 test_compare_5();
 test_compare_6();
 test_compare_7();
 test_compare_8();
 test_compare_9();
 test_generator_mul_1();
 test_generator_mul_2();
 test_generator_mul_3();
 test_generator_mul_4();
 test_generator_mul_5();
 test_generator_mul_6();
 test_generator_mul_7();
 test_generator_mul_8();
 test_generator_mul_9();
 test_generator_mul_10();
 test_generator_mul_11();
 test_generator_mul_12();
 test_generator_mul_13();
 test_generator_mul_14();
 test_generator_mul_15();
 test_generator_mul_16();
 test_generator_mul_17();
 test_generator_mul_18();
 test_generator_mul_19();
 test_generator_mul_20();
 test_generator_mul_21(); 
 test_generator_mul_22(); 
 test_generator_mul_23();  
 test_generator_mul_24();  
 test_generator_mul_25();   
 test_generator_mul_26();
 test_generator_mul_27();
 test_generator_mul_30();
 test_generator_mul_31();
 test_generator_mul_32();
 test_generator_mul_33();
 test_point_mul_1();  
 test_point_mul_2();
 test_point_mul_3();
 test_point_mul_asign_1();
 test_point_mul_asign_2();
 test_point_mul_asign_3();
 test_point_mul_asign_4();
 test_point_mul_asign_5();
 test_point_mul_asign_6();
 test_is_point_on_curve_1();
 test_is_point_on_curve_2();
 test_is_point_on_curve_3();
 test_is_point_on_curve_4();
 test_is_point_on_curve_5();
 test_is_point_on_curve_6();
 test_is_point_on_curve_7();
 test_secp256k1_calculate_y_coordinates_from_x_1();
 test_secp256k1_calculate_y_coordinates_from_x_2();
 test_secp256k1_calculate_y_coordinates_from_x_3();
 test_secp256k1_calculate_y_coordinates_from_x_4();
 test_secp256k1_calculate_y_coordinates_from_x_5();
 test_secp256k1_calculate_y_coordinates_from_x_6();
 test_secp256k1_keypair_from_private_key_1(); 
 test_secp256k1_keypair_from_private_key_2();  
 test_secp256k1_keypair_from_private_key_3();  
 test_secp256k1_keypair_from_private_key_4();   
 test_secp256k1_sign_1();
 test_secp256k1_sign_2();
 test_secp256k1_sign_3();
 test_secp256k1_verify_1();
 test_secp256k1_verify_1b();
 test_secp256k1_verify_2();
 test_secp256k1_verify_2b();
 test_secp256k1_verify_3();
 test_secp256k1_verify_3b();
 test_secp256k1_verify_4();
 test_secp256k1_verify_4b();
 test_secp256k1_verify_5();
 test_secp256k1_verify_5b();
 test_secp256k1_sign_and_verify_1();
 test_secp256k1_sign_and_verify_2();
 test_secp256k1_normalize_s_1();
 test_secp256k1_normalize_s_2();
 test_secp256k1_normalize_s_3();
 test_secp256k1_normalize_s_4();
 test_secp256k1_normalize_s_5();
 test_secp256k1_normalize_s_6();
 test_mul512_1();
 test_mul512_2();
 test_mul512_3();
 test_mul512_4();
 test_mul512_5();
 test_mul512_6();
 test_mul512_7();
 test_square512_1();
 test_square512_2();
 test_square512_3();
 test_square512_4();
 test_square512_5();
 test_square512_6();
 test_square512_7();
 test_secp256k1_parse_point_1();
 test_secp256k1_parse_point_2();
 test_secp256k1_parse_point_3();
 test_secp256k1_parse_point_4();
 test_secp256k1_parse_point_5();
 test_secp256k1_parse_point_6();
 test_secp256k1_parse_point_7();
 test_secp256k1_parse_point_8();
 test_secp256k1_parse_point_9();
 test_secp256k1_parse_point_10();
 test_secp256k1_parse_point_11();
 test_secp256k1_parse_point_12();
 test_secp256k1_parse_point_13();
 test_secp256k1_parse_scalar_1();
 test_secp256k1_parse_scalar_2();
 test_secp256k1_parse_scalar_3();
 test_secp256k1_parse_scalar_4();
 test_secp256k1_parse_u64_1();
 test_secp256k1_parse_u64_2();
 test_secp256k1_parse_u64_3();
 test_secp256k1_scalar_to_string_1();
 test_secp256k1_scalar_to_string_2();
 test_secp256k1_u32_to_string_1();
 test_secp256k1_u32_to_string_1a();
 test_secp256k1_u32_to_string_2();
 test_secp256k1_u32_to_string_2a();
 test_secp256k1_u32_to_string_3();
 test_secp256k1_u64_to_string_1();
 test_secp256k1_u64_to_string_2();
 test_asciiz_length_1();
 test_asciiz_length_2();
 test_asciiz_length_3();
 test_asciiz_length_4();
 test_asciiz_length_5();
 test_asciiz_length_6();
 test_asciiz_length_7();
 test_asciiz_length_8();
 test_asciiz_length_9();
 test_asciiz_length_10();
 test_count_decimals_1();
 test_count_decimals_2();
 test_count_decimals_3();
 test_count_decimals_4();
 test_count_decimals_5();
 test_count_decimals_6();
 test_count_decimals_7();
 test_count_decimals_8();
 test_u64_to_decimal_1();
 test_u64_to_decimal_2();
 test_u64_to_decimal_3();
 test_u64_to_decimal_4();
 test_u64_to_decimal_5();
 test_u64_to_decimal_6();
 test_u64_to_ascii_base16_1();
 test_u64_to_ascii_base16_2();
 test_u64_to_ascii_base10();
 test_u64_to_ascii_base8();
 test_u64_to_ascii_base4();
 test_u64_to_ascii_base3();
 test_u64_to_ascii_base2();
 test_u64_to_ascii_base32_ext_hex_alphabet();
 test_u64_to_ascii_base32_ext_hex_alphabet_2();
 test_u64_to_ascii_base85();    
   PRINT_TEST_RESULTS
}



