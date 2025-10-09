CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

all: cvec strings

cvec: main.c cvec.h
	$(CC) $(CFLAGS) main.c cvec.h -o cvec

strings: strings.c
	$(CC) $(CFLAGS) strings.c -o strings

clean:
	rm -f cvec strings

expand:
	$(CC) -E main.c -o main.i
