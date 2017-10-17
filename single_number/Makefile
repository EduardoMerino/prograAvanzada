LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c single_number.c
	 gcc -c main.c
	 gcc -o single_number.exe single_number.o main.o $(LIB)

test_single_number: clean
	 gcc -c single_number.c
	 gcc -c test_single_number.c
	 gcc -o test_single_number.exe single_number.o test_single_number.o
	 ./test_single_number.exe

test:	 test_single_number

clean:
	 rm *.out *.o *.exe || exit 0

single_number: clean
	 gcc -c single_number.c
	 gcc -c main.c
	 gcc -o single_number.exe single_number.o main.o $(LIB)

run: single_number
	 ./single_number.exe

runtest: single_number
	 ./integrationtest.tcl ./single_number.exe

