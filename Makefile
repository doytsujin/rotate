CC=gcc
CFLAGS=-g -Wall -Wextra -Wpedantic
ANALYZE=-fanalyzer
STRICT=-Werror 
BIN=a


run: 
	$(CC) ./src/*.c -o $(BIN) $(CFLAGS)


check:
	$(CC) ./src/*.c -o $(BIN) $(CFLAGS) $(ANALYZE)


strict:
	$(CC) ./src/*.c -o $(BIN) $(CFLAGS) $(STRICT) 


strictcheck:
	$(CC) ./src/*.c -o $(BIN) $(CFLAGS) $(ANALYZE) $(STRICT)


clean:
	-rm ./$(BIN)


memcheck:
	valgrind ./$(BIN) --leak-check=full --track-origins=yes -s


lint:
	cppcheck ./src/ --std=c11
