CC=gcc
FLAGS=-Wall -Wconversion -Wextra -pedantic
LIBS=-lm

run: bin.c
	$(CC) $(FLAGS) $(LIBS) -o test bin.c
	./test

clean:
	rm ./test
