c:
	gcc *.c -g -o a -Wall -Wextra -pedantic -std=c99
r:
	./a

clean:
	-rm a

memcheck:
	valgrind ./a --leak-check=full --track-origins=yes

lint:
	cppcheck . --std=c99
