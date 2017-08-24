CC=gcc
CFLAGS=-I.
DEPS = lastWord.h
OBJ = lastWord.o lastWordMain.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

lastWord.exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o *.exe
