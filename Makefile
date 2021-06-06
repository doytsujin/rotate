
CC = gcc
CFLAGS = -Wall 
CFLAGS += -Wextra 
CFLAGS += -Wpedantic
SRC = $(wildcard src/*.c)
ANALYZE = -Xanalyzer
STRICT  = -Werror 
CSTD = -std=gnu18
DEBUG  = -g
BIN  = a


run: 
	$(CC) $(SRC) -o $(BIN) $(CFLAGS) $(CSTD) $(LIB)

strict:
	$(CC) ./src/*.c -o $(BIN) $(CFLAGS) $(DEBUG) $(STRICT) $(CSTD) $(LIB)

afl:
	afl-clang ./src/*.c -o $(BIN) $(CFLAGS) $(DEBUG) $(CSTD) $(LIB)  

debug:
	clang ./src/*.c -o $(BIN) $(CFLAGS) $(ANALYZE) $(STRICT) $(DEBUG) $(CSTD) $(LIB)

clean:
	-rm ./$(BIN)

memcheck:
	valgrind --leak-check=full --track-origins=yes -s ./$(BIN)

lint:
	cppcheck ./src/* --std=c11

edit:
	vim ./src/
