

/* This is auto-generated code. Edit at your own peril. */
#include <stdio.h>
#include <stdlib.h>

#include "CuTest.h"


extern void TestSecp256k1_points_add_3G_plus_4G_equals_7G(CuTest*);
extern void TestSecp256k1_points_add_G_plus_2G_equals_3G(CuTest*);
extern void TestSecp256k1_G_mul_big_scalar1(CuTest*);
extern void TestSecp256k1_G_mul_0x25(CuTest*);
extern void TestSecp256k1_G_mul_order_n_minus_1(CuTest*);
extern void TestSecp256k1_G_mul_order_plus_0x25(CuTest*);
extern void TestSecp256k1_G_mul_4_3_2_1(CuTest*);
extern void TestSecp256k1_G_mul_0xfff(CuTest*);
extern void TestSecp256k1_G_mul_0xfff_minus_order(CuTest*);
extern void TestSecp256k1_G_mul_prime_minus_order(CuTest*);
extern void TestSecp256k1_G_mul_prime(CuTest*);
extern void TestSecp256k1_G_mul_order_results_in_minus_g_with_negative_y(CuTest*);
extern void TestSecp256k1_G_mul_big_scalar2(CuTest*);
extern void TestSecp256k1_G_mul_big_scalar3(CuTest*);
extern void TestSecp256k1_G_mul_big_scalar3a(CuTest*);
extern void TestSecp256k1_G_mul_big_scalar3b(CuTest*);
extern void TestSecp256k1_G_mul_big_scalar3c(CuTest*);
extern void TestSecp256k1_point_mul_G_x_big_scalar4a(CuTest*);
extern void TestSecp256k1_point_mul_G_x_big_scalar4b(CuTest*);
extern void TestSecp256k1_point_mul_G_x_big_scalar4c(CuTest*);
extern void TestSecp256k1_points_add_4b_plus_4c_equals_4a(CuTest*);
extern void TestSecp256k1_point_mul_G_x_big_scalar4d(CuTest*);
extern void TestSecp256k1_point_mul_G_x_big_scalar4e(CuTest*);
extern void TestSecp256k1_points_add_4d_plus_4e_equals_4a(CuTest*);


void RunAllTests(void) 
{
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();


    SUITE_ADD_TEST(suite, TestSecp256k1_points_add_3G_plus_4G_equals_7G);
    SUITE_ADD_TEST(suite, TestSecp256k1_points_add_G_plus_2G_equals_3G);
    SUITE_ADD_TEST(suite, TestSecp256k1_G_mul_big_scalar1);
    SUITE_ADD_TEST(suite, TestSecp256k1_G_mul_0x25);
    SUITE_ADD_TEST(suite, TestSecp256k1_G_mul_order_n_minus_1);
    SUITE_ADD_TEST(suite, TestSecp256k1_G_mul_order_plus_0x25);
    SUITE_ADD_TEST(suite, TestSecp256k1_G_mul_4_3_2_1);
    SUITE_ADD_TEST(suite, TestSecp256k1_G_mul_0xfff);
    SUITE_ADD_TEST(suite, TestSecp256k1_G_mul_0xfff_minus_order);
    SUITE_ADD_TEST(suite, TestSecp256k1_G_mul_prime_minus_order);
    SUITE_ADD_TEST(suite, TestSecp256k1_G_mul_prime);
    SUITE_ADD_TEST(suite, TestSecp256k1_G_mul_order_results_in_minus_g_with_negative_y);
    SUITE_ADD_TEST(suite, TestSecp256k1_G_mul_big_scalar2);
    SUITE_ADD_TEST(suite, TestSecp256k1_G_mul_big_scalar3);
    SUITE_ADD_TEST(suite, TestSecp256k1_G_mul_big_scalar3a);
    SUITE_ADD_TEST(suite, TestSecp256k1_G_mul_big_scalar3b);
    SUITE_ADD_TEST(suite, TestSecp256k1_G_mul_big_scalar3c);
    SUITE_ADD_TEST(suite, TestSecp256k1_point_mul_G_x_big_scalar4a);
    SUITE_ADD_TEST(suite, TestSecp256k1_point_mul_G_x_big_scalar4b);
    SUITE_ADD_TEST(suite, TestSecp256k1_point_mul_G_x_big_scalar4c);
    SUITE_ADD_TEST(suite, TestSecp256k1_points_add_4b_plus_4c_equals_4a);
    SUITE_ADD_TEST(suite, TestSecp256k1_point_mul_G_x_big_scalar4d);
    SUITE_ADD_TEST(suite, TestSecp256k1_point_mul_G_x_big_scalar4e);
    SUITE_ADD_TEST(suite, TestSecp256k1_points_add_4d_plus_4e_equals_4a);

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
    CuStringDelete(output);
    CuSuiteDelete(suite);
}

int main(void)
{
    printf("\nTesting point multiplication on the secp256k1 elliptic curve.\n");
    RunAllTests();
}

