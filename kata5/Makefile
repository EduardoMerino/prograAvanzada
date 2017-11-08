LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c fizz_buzz.c
	 gcc -c main.c
	 gcc -o fizz_buzz.exe fizz_buzz.o main.o $(LIB)

test_fizz_buzz: clean
	 gcc -c fizz_buzz.c
	 gcc -c test_fizz_buzz.c
	 gcc -o test_fizz_buzz.exe fizz_buzz.o test_fizz_buzz.o
	 ./test_fizz_buzz.exe

test:	 test_fizz_buzz

clean:
	 rm *.out *.o *.exe || exit 0

fizz_buzz: clean
	 gcc -c fizz_buzz.c
	 gcc -c main.c
	 gcc -o fizz_buzz.exe fizz_buzz.o main.o $(LIB)

run: fizz_buzz
	 ./fizz_buzz.exe

runtest: fizz_buzz
	 ./integrationtest.tcl ./fizz_buzz.exe

