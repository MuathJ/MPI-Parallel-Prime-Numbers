CC=mpic++
CFLAGS=-I -O3 -Wall

DEPS=
OBJ = primenum.o .o mpiprim.o mpiprimecyclic.o

all: primenum mpiprim mpiprimecyclic

primenum: primenum.o
		g++ -o $@ $^
mpiprim: mpiprim.o
		$(CC) -o $@ $^
mpiprimecyclic: mpiprimecyclic.o
		$(CC) -o $@ $^
		
%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)
		
prime: primenum
		./primenum 100
		
mpiprime: mpiprim
		mpirun -np 4 ./mpiprim 100
		
mpicyc: mpiprimecyclic
		mpirun -np 4 ./mpiprimecyclic 100

clean:
		rm -f *.o *~ core
