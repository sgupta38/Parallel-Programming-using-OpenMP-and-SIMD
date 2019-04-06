CC=g++
CFLAGS=-I. -std=c++11 -mfma

all: simd

simd: simd.cpp 
	$(CC) -o simd simd.cpp $(CFLAGS)

clean:
	rm -f *.o simd 
