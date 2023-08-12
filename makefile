connectn.out: main.o game.o board.o input_validation.o
	gcc -g -Wall -Werror -o connectn.out main.o game.o board.o input_validation.o
main.o: main.c game.h board.h
	gcc -g -Wall -Werror -c main.c
game.o: game.c game.h board.h input_validation.h
	gcc -g -Wall -Werror -c game.c
board.o: board.c board.h
	gcc -g -Wall -Werror -c board.c
input_validation.o: input_validation.c input_validation.h
	gcc -g -Wall -Werror -c input_validation.c
clean:
	rm -fr *.o*.out
