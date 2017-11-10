LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c students.c
	 gcc -c main.c
	 gcc -o students.exe students.o main.o $(LIB)

test_students: clean
	 gcc -c students.c
	 gcc -c test_students.c
	 gcc -o test_students.exe students.o test_students.o
	 ./test_students.exe

test:	 test_students

clean:
	 rm *.out *.o *.exe || exit 0

students: clean
	 gcc -c students.c
	 gcc -c main.c
	 gcc -o students.exe students.o main.o $(LIB)

run: students
	 ./students.exe

runtest: students
	 ./integrationtest.tcl ./students.exe

