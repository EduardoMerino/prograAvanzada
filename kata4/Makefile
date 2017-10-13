LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c island.c
	 gcc -c main.c
	 gcc -o island.exe island.o main.o $(LIB)

test_island: clean
	 gcc -c island.c
	 gcc -c test_island.c
	 gcc -o test_island.exe island.o test_island.o
	 ./test_island.exe

test:	 test_island

clean:
	 rm *.out *.o *.exe || exit 0

island: clean
	 gcc -c island.c
	 gcc -c main.c
	 gcc -o island.exe island.o main.o $(LIB)

run: island
	 ./island.exe

runtest: island
	 ./integrationtest.tcl ./island.exe

