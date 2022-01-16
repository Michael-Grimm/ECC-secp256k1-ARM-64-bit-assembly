build: libsecp256k1.a

test: build
	gcc -o test.out  tests.c libsecp256k1.a
	./test.out	

libsecp256k1.a: scalar_n.o scalar_p.o point_p.o stringutils.o u256.o  secp256k1.h aliases commonmacros
	ar rcs libsecp256k1.a  scalar_n.o scalar_p.o point_p.o  stringutils.o u256.o 


point_p.o: point_p.sx
	gcc -c -o point_p.o point_p.sx    


stringutils.o: stringutils.sx
	gcc -c -o stringutils.o stringutils.sx    

scalar_n.o: scalar_n.sx
	gcc -c -o scalar_n.o scalar_n.sx    

scalar_p.o: scalar_p.sx
	gcc   -c -o scalar_p.o scalar_p.sx    

u256.o: u256.sx
	gcc  -c -o u256.o u256.sx 

 









	
