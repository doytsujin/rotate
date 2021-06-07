
CC = gcc-10
CFLAGS = -Wall 
CFLAGS += -Wextra 
CFLAGS += -Wpedantic
SRC = $(wildcard src/*.c)
SRC_C_H = $(SRC) $(wildcard src/include/*.h)
ANALYZE = -fanalyzer
STRICT  = -Werror 
CSTD = -std=gnu18
CSTD_LINT = --std=c11
DEBUG  = -g
BIN  = a


run: 
	$(CC) $(SRC) -o $(BIN) $(CFLAGS) $(CSTD) $(LIB)

test:
	python3 tester.py

strict:
	$(CC) $(SRC) -o $(BIN) $(CFLAGS) $(DEBUG) $(STRICT) $(CSTD) $(LIB)

afl:
	afl-clang $(SRC) -o $(BIN) $(CFLAGS) $(DEBUG) $(CSTD) $(LIB)  

debug:
	$(CC) $(SRC) -o $(BIN) $(CFLAGS) $(ANALYZE) $(DEBUG) $(CSTD) $(LIB)

clean:
	-rm ./$(BIN)

memcheck:
	valgrind --leak-check=full --track-origins=yes -s ./$(BIN)

lint:
	cppcheck  $(SRC_C_H) $(CSTD_LINT)

edit:
	vim ./src/
