CC=gcc
CFLAGS=-g -Wall -Wextra -pedantic
STRICT=-Werror
BIN=a


run: 
	$(CC) ./src/*.c -o $(BIN) $(CFLAGS)

strict:
	$(CC) ./src/*.c -o $(BIN) $(CFLAGS) $(STRICT)


clean:
	-rm ./$(BIN)

memcheck:
	valgrind ./$(BIN) --leak-check=full --track-origins=yes

lint:
	cppcheck ./src/ --std=c11
