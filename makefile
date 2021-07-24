test: build
	make -C ./test utests

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
	
	 
	
clear: 	
	rm ./release/libsecp256k1.a
	rm ./release/secp256k1.h
	rm ./*.o
	make build
	make test








	
