CC=gcc
CFLAGS=-I.
DEPS = twoSum.h
OBJ = twoSum.o twoSumMain.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

twoSum.exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o *.exe
