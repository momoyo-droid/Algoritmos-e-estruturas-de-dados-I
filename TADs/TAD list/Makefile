all:
	gcc -Wall -Wextra -Werror -g -lm -c main.c -o main.o
	gcc -Wall -Wextra -Werror -g -lm -c list.c -o list.o
	
	gcc -lm -g main.o list.o -o exec

clean:
	@rm -rf *.o exec

run:
	@./exec

valgrind: clean all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./exec

zip:
	@zip -r code.zip Makefile main.c *.c *.h