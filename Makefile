CC=g++
CFLAGS=-I. -std=c++11 -fopenmp -I/usr/include/python2.7 -lpython2.7

all: sequential_sphere parallel_sphere

sequential_sphere: serial_main.cpp Csequential.cpp
	$(CC) -O4 -o sequential_sphere serial_main.cpp Csequential.cpp $(CFLAGS)

parallel_sphere: parallel_main.cpp CParallel.cpp
	$(CC) -O4 -o parallel_sphere parallel_main.cpp CParallel.cpp $(CFLAGS)

clean:
	rm -rf *.o lcs sequential_sphere parallel_sphere graphs_parallel/ graphs_sequential/
