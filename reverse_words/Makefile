all:
	 gcc -c reverse_words.c
	 gcc -c main.c
	 gcc -o main reverse_words.o main.o

test_reverse_words: clean
	 gcc -c reverse_words.c
	 gcc -c test_reverse_words.c
	 gcc -o test_reverse_words.exe reverse_words.o test_reverse_words.o
	 ./test_reverse_words.exe

test:	 test_reverse_words

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c reverse_words.c
	 gcc -c main.c
	 gcc -o main.exe reverse_words.o main.o
	 ./main
