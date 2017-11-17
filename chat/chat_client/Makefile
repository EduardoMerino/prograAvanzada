LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c chat_client.c
	 gcc -c main.c
	 gcc -o chat_client.exe chat_client.o main.o $(LIB)

test_chat_client: clean
	 gcc -c chat_client.c
	 gcc -c test_chat_client.c
	 gcc -o test_chat_client.exe chat_client.o test_chat_client.o
	 ./test_chat_client.exe

test:	 test_chat_client

clean:
	 rm *.out *.o *.exe || exit 0

chat_client: clean
	 gcc -c chat_client.c
	 gcc -c main.c
	 gcc -o chat_client.exe chat_client.o main.o $(LIB)

run: chat_client
	 ./chat_client.exe

runtest: chat_client
	 ./integrationtest.tcl ./chat_client.exe

