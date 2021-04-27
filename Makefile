CC=gcc
CFLAGS=-g -Wall -Wextra -Wpedantic
STRICT=-Werror -fanalyzer
BIN=a


run: 
	$(CC) ./src/*.c -o $(BIN) $(CFLAGS)

strict:
	$(CC) ./src/*.c -o $(BIN) $(CFLAGS) $(STRICT)


clean:
	-rm ./$(BIN)

memcheck:
	valgrind ./$(BIN) --leak-check=full --track-origins=yes -s

lint:
	cppcheck ./src/ --std=c11
