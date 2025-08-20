CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99

BIN = main
MAIN = main.c
CVEC = cvec.h

$(BIN): $(MAIN) $(CVEC)
	$(CC) $(CFLAGS) $(MAIN) $(CVEC) -o $(BIN)

clean:
	rm -f $(BIN)

expand:
	$(CC) -E $(MAIN) -o main.i
