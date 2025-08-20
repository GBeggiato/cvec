CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99

BIN = cvec
MAIN = main.c

$(BIN): $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) cvec.h -o $(BIN)

clean:
	rm -f $(BIN)

expand:
	$(CC) -E $(MAIN) -o main.i
