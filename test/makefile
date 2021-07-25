test_after_updating_test_suites:
	./make-tests.sh > tests.c #this script extracts all tests from *.c files and creates file 'tests.c'
	gcc -o test.out CuTest.c  CuTest_u256.c CuTest_stringutils.c CuTest_scalar_n.c CuTest_scalar_p.c CuTest_point_p.c CuTest_ecdsa.c tests.c ../release/libsecp256k1.a
	./test.out

test_without_updating_test_suites: 
	#uses a previously build 'tests.c' file. No search for new tests.
	gcc -o test.out CuTest.c  CuTest_u256.c CuTest_stringutils.c CuTest_scalar_n.c CuTest_scalar_p.c CuTest_point_p.c CuTest_ecdsa.c tests.c ../release/libsecp256k1.a
	./test.out	
	
