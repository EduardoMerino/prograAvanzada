LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c chat_server.c
	 gcc -c main.c
	 gcc -o chat_server.exe chat_server.o main.o $(LIB)

test_chat_server: clean
	 gcc -c chat_server.c
	 gcc -c test_chat_server.c
	 gcc -o test_chat_server.exe chat_server.o test_chat_server.o
	 ./test_chat_server.exe

test:	 test_chat_server

clean:
	 rm *.out *.o *.exe || exit 0

chat_server: clean
	 gcc -c chat_server.c
	 gcc -c main.c
	 gcc -o chat_server.exe chat_server.o main.o $(LIB)

run: chat_server
	 ./chat_server.exe

runtest: chat_server
	 ./integrationtest.tcl ./chat_server.exe

