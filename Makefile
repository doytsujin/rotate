# makefile

CC = gcc
CFLAGS = -Wall 
CFLAGS += -Wextra 
CFLAGS += -Wpedantic
ANALYZE = -Xanalyzer
STRICT  = -Werror 
DEBUG  = -g
BIN  = a


run: 
	$(CC) ./src/*.c -o $(BIN) $(CFLAGS) $(DEBUG)

strict:
	$(CC) ./src/*.c -o $(BIN) $(CFLAGS) $(DEBUG) $(STRICT)

debug:
	clang ./src/*.c -o $(BIN) $(CFLAGS) $(ANALYZE) $(STRICT) $(DEBUG)

clean:
	-rm ./$(BIN)

memcheck:
	valgrind --leak-check=full --track-origins=yes -s ./$(BIN)

lint:
	cppcheck ./src/* --std=c11
