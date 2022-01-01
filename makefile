clear_and_test: 
	make clear
	make build
	make -C ./test test_after_updating_test_suites

clear:
	rm -rf ./release/libsecp256k1.a
	rm -rf ./release/secp256k1.h
	rm -rf ./*.o
	

test_after_tests_changed: 
	make build
	make -C ./test test_after_updating_test_suites
	
test_after_code_changed: 
	make build
	make -C ./test test_without_updating_test_suites

build: ./release/libsecp256k1.a

./release/libsecp256k1.a: ./scalar_n.o ./scalar_p.o ./point_p.o ./stringutils.o ./u256.o  ./src/secp256k1.h ./src/aliases ./src/commonmacros
	ar rcs ./release/libsecp256k1.a  ./scalar_n.o ./scalar_p.o ./point_p.o  ./stringutils.o ./u256.o 
	cp ./src/secp256k1.h ./release/secp256k1.h


./point_p.o: ./src/point_p.sx
	gcc -I./src -c -o ./point_p.o ./src/point_p.sx    


./stringutils.o: ./src/stringutils.sx
	gcc -I./src -c -o ./stringutils.o ./src/stringutils.sx    

./scalar_n.o: ./src/scalar_n.sx
	gcc   -I./src -c -o ./scalar_n.o ./src/scalar_n.sx    

./scalar_p.o: ./src/scalar_p.sx
	gcc   -I./src -c -o ./scalar_p.o ./src/scalar_p.sx    

./u256.o: ./src/u256.sx
	gcc   -I./src -c -o ./u256.o ./src/u256.sx   
	










	
