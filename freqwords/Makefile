all:
	gcc -Wall -Wextra -Werror -g -lm -c main.c -o main.o
	gcc -Wall -Wextra -Werror -g -lm -c word.c -o word.o
	gcc -Wall -Wextra -Werror -g -lm -c read_lib.c -o read_lib.o
	
	gcc -lm -g main.o word.o read_lib.o -o exec

clean:
	@rm -rf *.o exec

run:
	@./exec

valgrind: clean all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./exec

zip:
	@zip -r code.zip Makefile main.c *.c *.h