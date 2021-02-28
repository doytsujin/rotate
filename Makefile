c:
	gcc main.c -o a -Wall -Werror
c2:
	gcc main2.c -o a -Wall -Werror

run:
	./a
clean:
	-rm a
