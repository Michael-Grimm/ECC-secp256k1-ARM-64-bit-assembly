utests:
	./make-tests.sh > tests.c
	gcc -o test.out CuTest.c  CuTest_u256.c CuTest_stringutils.c CuTest_scalar_n.c CuTest_scalar_p.c CuTest_point_p.c CuTest_ecdsa.c tests.c ../release/libsecp256k1.a
	./test.out


	
	
