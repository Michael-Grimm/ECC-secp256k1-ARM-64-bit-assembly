test: build
	make -C ./test utests

build: ./release/libsecp256k1.a

./release/libsecp256k1.a: ./temp/scalar_n.o ./temp/scalar_p.o ./temp/point_p.o ./temp/stringutils.o ./temp/u256.o  ./src/secp256k1.h ./src/aliases ./src/commonmacros
	ar rcs ./release/libsecp256k1.a  ./temp/scalar_n.o ./temp/scalar_p.o ./temp/point_p.o  ./temp/stringutils.o ./temp/u256.o 
	cp ./src/secp256k1.h ./release/secp256k1.h


./temp/point_p.o: ./src/point_p.sx
	gcc -I./src -c -o ./temp/point_p.o ./src/point_p.sx    


./temp/stringutils.o: ./src/stringutils.sx
	gcc -I./src -c -o ./temp/stringutils.o ./src/stringutils.sx    

./temp/scalar_n.o: ./src/scalar_n.sx
	gcc   -I./src -c -o ./temp/scalar_n.o ./src/scalar_n.sx    

./temp/scalar_p.o: ./src/scalar_p.sx
	gcc   -I./src -c -o ./temp/scalar_p.o ./src/scalar_p.sx    

./temp/u256.o: ./src/u256.sx
	gcc   -I./src -c -o ./temp/u256.o ./src/u256.sx   
	
	 
	
clear: 	
	rm ./release/libsecp256k1.a
	rm ./release/secp256k1.h
	rm ./temp/*.o
	make build
	make test








	
