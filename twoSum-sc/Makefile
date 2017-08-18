all:
	 gcc -c twoSum.c
	 gcc -c main.c
	 gcc -o main twoSum.o main.o

test_twoSum: clean
	 gcc -c twoSum.c
	 gcc -c test_twoSum.c
	 gcc -o test_twoSum.exe twoSum.o test_twoSum.o
	 ./test_twoSum.exe

test:	 test_twoSum

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c twoSum.c
	 gcc -c main.c
	 gcc -o main.exe twoSum.o main.o
	 ./main
